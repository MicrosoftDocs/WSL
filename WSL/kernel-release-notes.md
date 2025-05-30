---
title: Release Notes for WSL kernel 
description: Release notes for the Windows Subsystem for Linux.  Updated monthly.
keywords: release notes, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, kernel
ms.date: 09/27/2021
ms.topic: article
---

# Release Notes for Windows Subsystem for Linux kernel

We've added support for WSL 2 distributions, [which use a full Linux kernel](https://devblogs.microsoft.com/commandline/shipping-a-linux-kernel-with-windows/). This Linux kernel is open source, with its source code available at the [WSL2-Linux-Kernel](https://github.com/microsoft/WSL2-Linux-Kernel) repository. This Linux kernel is delivered to your machine via Microsoft Update, and follows a separate release schedule to the Windows Subsystem for Linux which is delivered as part of the Windows image.

## 5.15.57.1 

*Release Date*: Prerelease 2022/08/02

[Official GitHub release link](https://github.com/microsoft/WSL2-Linux-Kernel/releases/tag/linux-msft-wsl-5.15.57.1)

- Initial release of the WSL2 kernel based on the v5.15 kernel series
- Release rolling-lts/wsl/5.15.57.1
- Update to stable kernel version v5.15.57
- Enable Retbleed mitigations in x86_64 builds
- Enable nftables and traffic control
- Enable VGEM driver
- Fix 9p filesystem regressions since the last v5.10 WSL2 kernel
- Enable support for the Precision Time Protocol (PTP) clock device
- Enable the Landlock Linux Security Module (LSM)
  - https://landlock.io/
- Enable the Miscellaneous Control Group (CGroup)
  - https://www.kernel.org/doc/html/v5.15/admin-guide/cgroup-v2.html#misc
- Disable support for the Ceph Distributed File System

## 5.10.102.1

*Release Date*: Prerelease 2022/05/09

[Official Github release link](https://github.com/microsoft/WSL2-Linux-Kernel/releases/tag/linux-msft-wsl-5.10.102.1)

- Release rolling-lts/wsl/5.10.102.1
- Update to upstream stable kernel release 5.10.102
- Disable unprivileged BPF by default
- It can be re-enabled by setting the kernel.unprivileged_bpf_disabled sysctl to 0
- Update Dxgkrnl Version to 2216
- Fix out of bounds array access for ioctls[]
- Implement wait for sync VM bus messages as “killable” to allow killing a process waiting for a synchronous call to the host
- Flush device for termination when process is destroyed to avoid a deadlock when the guest process is killed

## 5.10.93.2

*Release Date*: Prerelease 2022/02/08

[Official Github release link](https://github.com/microsoft/WSL2-Linux-Kernel/releases/tag/linux-msft-wsl-5.10.93.2)

- Release rolling-lts/wsl/5.10.93.2
- Update to upstream stable kernel release 5.10.93
- Enable CH341 and CP210X USB Serial drivers
- Fix README.md build instructions to include dwarves dependency for pahole
- Switched Dxgkrnl Version to 2111
- Removed the limit of existing and total sysmem allocations
- Properly flush the device for termination during process cleanup
- Fixed SPDX-License-Identifier for d3dkmthk.h

## 5.10.81.1

*Release Date*: Prerelease 2022/02/01

[Official Github release link](https://github.com/microsoft/WSL2-Linux-Kernel/releases/tag/linux-msft-wsl-5.10.81.1)

- Release rolling-lts/wsl/5.10.81.1 
- Update to upstream stable kernel release 5.10.81
- Unify the kernel configurations by enabling missing options on arm64
- Enable non-arch specific ACPI options
- Enable options related to device-mapper RAID
- Enable Btrfs
- Enable LZO and ZSTD compression

## 5.10.74.3

*Release Date*: Prerelease 2021/11/10

[Official Github release link](https://github.com/microsoft/WSL2-Linux-Kernel/releases/tag/linux-msft-wsl-5.10.74.3)

- Release rolling-lts/wsl/5.10.74.3
- Update to upstream stable kernel release 5.10.74
- Enable BPF Type Format (CONFIG_DEBUG_INFO_BTF) for use by eBPF tools (microsoft/WSL#7437)
- Updated Dxgkrnl version to 2110
- Enable the Buffer Sharing and Sync File Frameworks (CONFIG_DMA_SHARED_BUFFER, CONFIG_SYNC_FILE) for Dxgkrnl usage
- Fix Dxgkrnl build failure with GCC versions older than 8.1 (microsoft/WSL#7558)

## 5.10.60.1

*Release Date*: 2021/11/02 ( Prerelease 2021/10/05 )

[Official Github release link](https://github.com/microsoft/WSL2-Linux-Kernel/releases/tag/linux-msft-wsl-5.10.60.1)

- Release rolling-lts/wsl/5.10.60.1
- Update to upstream stable kernel release 5.10.60
- Enable virtio-pmem with support for PCI BAR-relative addresses
- Enable vPCI support under Hyper-V for arm64
- Enable io_uring support
- Enable USB over IP support
- Enable paravirtualized spinlock support for x86_64
- Refresh dxgkrnl driver to pick up bug fixes and code cleanups
- Enable NFS client support for NFSv4.1
- Enable USB kernel configuration options for interacting with an Arduino over USB
- Provide a WSL2-specific README.md

## 5.10.43.3

*Release Date*: Prerelease 2021/07/12

[Official Github release link](https://github.com/microsoft/WSL2-Linux-Kernel/releases/tag/linux-msft-wsl-5.10.43.3)

- Version rolling-lts/wsl/5.10.43.3
- Update to upstream stable kernel release 5.10.43
- Improved dxgkrnl driver
- New revision of arm64 Linux on Hyper-V series (v9)
- Always use the Hyper-V hypercall interface on arm64 guests to support running on all versions of Windows

## 5.10.16.3

*Release Date*: 2021/07/20 ( Prerelease 2021/04/16 )

[Official Github release link](https://github.com/microsoft/WSL2-Linux-Kernel/releases/tag/linux-msft-wsl-5.10.16.3)

- Fixes [GH 5324](https://github.com/microsoft/WSL/issues/5324)
- Adds support for LUKS encrypted disks using wsl --mount

## 5.4.91

*Release Date*: Prerelease 2021/02/22

[Official Github release link](https://github.com/microsoft/WSL2-Linux-Kernel/releases/tag/linux-msft-5.4.91)

## 5.4.72
*Release Date*: 2021/01/21

[Official Github release link](https://github.com/microsoft/WSL2-Linux-Kernel/releases/tag/linux-msft-5.4.72)

- Fix config for 5.4.72

## 5.4.51-microsoft-standard

*Release Date*: Prerelease - 2020/10/22

[Official Github release link](https://github.com/microsoft/WSL2-Linux-Kernel/releases/tag/linux-msft-5.4.51).

- Stable release of 5.4.51

## 4.19.128-microsoft-standard

*Release Date*: 2020/09/15

[Official Github release link](https://github.com/microsoft/WSL2-Linux-Kernel/releases/tag/4.19.128-microsoft-standard).

- This is a stable release of 4.19.128
- Fix dxgkrnl driver IOCTL memory corruption

## 4.19.121-microsoft-standard

*Release Date*: Prerelease

[Official Github release link](https://github.com/microsoft/WSL2-Linux-Kernel/releases/tag/4.19.121-microsoft-standard).

- Drivers: hv: vmbus: hook up dxgkrnl
- Added support for GPU Compute

## 4.19.104-microsoft-standard

*Release Date*: 2020/06/09

[Official Github release link](https://github.com/microsoft/WSL2-Linux-Kernel/releases/tag/4.19.104-microsoft-standard).

- Update WSL config for 4.19.104

## 4.19.84-microsoft-standard

*Release Date*: 2019/12/11

[Official Github release link](https://github.com/microsoft/WSL2-Linux-Kernel/releases/tag/4.19.84-microsoft-standard).

- This is the 4.19.84 stable release
