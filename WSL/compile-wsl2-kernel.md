---
title: Compile a specific Linux kernel version for WSL2
description: Learn how to compile a specific Linux kernel version for WSL2.
keywords: wsl, Linux, Windows, kernel
ms.date: 10/04/2023
ms.topic: article
---

# Compile a specific Linux kernel version for WSL2

In some specific scenarios, you may need to compile the kernel for WSL2 yourself. This article will discuss in detail how to compile a Linux kernel suitable for use in WSL2.

## Preparation

1. Open the command line (Bash) for a Ubuntu 20.04 LTS (Focal Fossa) Linux distribution that you've already installed from the Microsoft Store.

2. Some tools need to be installed, such as bc jq cmake clang llvm lldb ninja build-essential wget dwarves kmod

```bash
sudo apt-get update -y && sudo apt-get install bc jq cmake clang llvm lldb ninja build-essential wget dwarves kmod -y
```

3. Download the kernel source code from the releases page of the wsl2 kernel repository https://github.com/microsoft/WSL2-Linux-Kernel/releases (use i.j.k.l to represent the version number) and extract it:

```bash
wget https://github.com/microsoft/WSL2-Linux-Kernel/archive/refs/tags/linux-msft-wsl-i.j.k.l.tar.gz

tar -xzf linux-msft-wsl-i.j.k.l.tar.gz
```


## Compilation

1. Enter the compilation working directory

```bash
cd WSL2-Linux-Kernel-linux-msft-wsl-i.j.k.l/
```

2. Customize the compilation configuration file config-wsl and merge custom kernel patches (Optional)

3. Compile the kernel source code

```bash
make KCONFIG_CONFIG=arch/x86/configs/config-wsl -j$(nproc)
```

   If processor architecture is arm64

```bash
make KCONFIG_CONFIG=arch/arm64/configs/config-wsl-arm64 -j$(nproc)
```

   You can add custom compiler parameter options like CFLAGS, CXXFLAGS, LTOFLAGS or RUSTFLAGS (Experimental)

```bash
make KCONFIG_CONFIG=arch/x86/configs/config-wsl -j$(nproc) CFLAGS="-march=x86-64-v3 -mtune=native -O3 -pipe -fno-plt -fexceptions -Wp,-D_FORTIFY_SOURCE=2 -Wformat -Werror=format-security -fstack-clash-protection -fcf-protection -mcx16 -mpopcnt -msse4.1 -msse4.2 -mssse3 -mavx -mavx2 -mbmi -mbmi2 -mf16c -mfma -mmovbe -mxsave" CXXFLAGS="$CFLAGS -Wp,-D_GLIBCXX_ASSERTIONS" LTOFLAGS="-flto=thin -falign-functions=32" RUSTFLAGS="-Copt-level=3 -Ctarget-cpu=x86-64-v3" GOAMD64="v3"

```


## Packaging

1. linux-kernel

Through the compilation stage you will get the linux kernel, where vmlinux is a statically linked executable format for the Linux kernel. It is uncompressed kernel code that is typically used to develop, debug, and analyze the kernel. Of course, you can also boot a system with the VMlinux kernel by adding further boot and decompression capabilities.

For WSL2, you should use the bzImage file as the kernel (if your processor architecture is arm64, what you get should be a file named Image). bzImage(Image) is a compressed bootable Linux kernel image file that boots the Linux operating system. It is compressed from the vmlinux file.

Please see the documentation on the [.wslconfig configuration file][install-inst] for information on using a custom built kernel.


2. linux-headers (Optional)

In some specific cases you may need the header files, Kconfig and Makefile in the current kernel source code, but the Linux distribution does not have a separately distributed package for WSL2. You need to further package from the compilation stage working directory

 - Generate the modules directory

```bash
mkdir -p ../wsl-i.j.k.l
make modules_install INSTALL_MOD_PATH=../wsl-i.j.k.l 

```

Or you can install directly into the current operating system

```bash
make modules_install INSTALL_MOD_PATH=/usr

```

 - Extract the files 

```bash
rm -rf ../wsl-i.j.k.l/lib/modules/i.j.k.l-microsoft-standard-WSL2/build
mkdir -p ../wsl-i.j.k.l/lib/modules/i.j.k.l-microsoft-standard-WSL2/build
local builddir=../wsl-i.j.k.l/lib/modules/i.j.k.l-microsoft-standard-WSL2/build
install -Dt "$builddir" -m644 Makefile Module.symvers System.map vmlinux
install -Dt "$builddir/kernel" -m644 kernel/Makefile
install -Dt "$builddir/arch/x86" -m644 arch/x86/Makefile
cp -t "$builddir" -a scripts
install -Dt "$builddir/tools/objtool" tools/objtool/objtool
install -Dt "$builddir/tools/bpf/resolve_btfids" tools/bpf/resolve_btfids/resolve_btfids
cp -t "$builddir" -a include
cp -t "$builddir/arch/x86" -a arch/x86/include
install -Dt "$builddir/arch/x86/kernel" -m644 arch/x86/kernel/asm-offsets.s
install -Dt "$builddir/drivers/md" -m644 drivers/md/*.h
install -Dt "$builddir/net/mac80211" -m644 net/mac80211/*.h
install -Dt "$builddir/drivers/media/i2c" -m644 drivers/media/i2c/msp3400-driver.h
install -Dt "$builddir/drivers/media/usb/dvb-usb" -m644 drivers/media/usb/dvb-usb/*.h
install -Dt "$builddir/drivers/media/dvb-frontends" -m644 drivers/media/dvb-frontends/*.h
install -Dt "$builddir/drivers/media/tuners" -m644 drivers/media/tuners/*.h
install -Dt "$builddir/drivers/iio/common/hid-sensors" -m644 drivers/iio/common/hid-sensors/*.h
find . -name 'Kconfig*' -exec install -Dm644 {} "$builddir/{}" \;
local arch
for arch in "$builddir"/arch/*/; do
  [[ $arch = */x86/ ]] && continue
  echo "Removing $(basename "$arch")"
  rm -r "$arch"
done
find -L "$builddir" -type l -printf 'Removing %P\n' -delete
find "$builddir" -type f -name '*.o' -printf 'Removing %P\n' -delete
local file
while read -rd '' file; do
  case "$(file -Sib "$file")" in
   application/x-sharedlib\;*)
    strip -v $STRIP_SHARED "$file" ;;
   application/x-archive\;*)
    strip -v $STRIP_STATIC "$file" ;;
   application/x-executable\;*)
    strip -v $STRIP_BINARIES "$file" ;;
   application/x-pie-executable\;*)
    strip -v $STRIP_SHARED "$file" ;;
  esac
done < <(find "$builddir" -type f -perm -u+x ! -name vmlinux -print0)
strip -v $STRIP_STATIC "$builddir/vmlinux"
mkdir -p "../wsl-i.j.k.l/src"
ln -sr "$builddir" "../wsl-i.j.k.l/src/i.j.k.l-microsoft-standard-WSL2"

```

If you installed directly to /usr you need to replace ../wsl-i.j.k.l with /usr

If you modified the CONFIG_LOCALVERSION field in the config-wsl configuration file during the compilation stage, the above code should be changed accordingly

3. linux-docs (Optional) 

When you need to refer to the kernel documentation for a long time, you can also package the Documentation directory together with linux-headers from the compilation stage working directory

```bash
rm -rf ../wsl-i.j.k.l/lib/modules/i.j.k.l-microsoft-standard-WSL2/build/Documentation
cp -r Documentation ../wsl-i.j.k.l/lib/modules/i.j.k.l-microsoft-standard-WSL2/build/Documentation
```

4. Compress the installation directory for archiving


```bash

sudo apt-get update -y && sudo apt-get install zstd -y
tar -c --zstd -f wsl-i.j.k.l.tar.zst ../wsl-i.j.k.l/

```



[install-inst]: https://github.com/MicrosoftDocs/WSL/blob/main/WSL/wsl-config.md
