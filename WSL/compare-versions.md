---
title: Comparing WSL Versions
description: WSL 2 provides the benefits of WSL 1, but uses an actual Linux kernel, rather than a translation layer like WSL 1, resulting in faster performance.
ms.date: 11/20/2023
ms.topic: conceptual
ms.custom: seo-windows-dev
---

# Comparing WSL Versions

Learn more about different WSL versions, including why WSL 2 is now the default and the specific scenarios or exceptions that may warrant switching your installed Linux distribution to the earlier WSL 1 architecture. 

## Comparing WSL 1 and WSL 2

This guide will compare WSL 1 and WSL 2, including [exceptions for using WSL 1 rather than WSL 2](#exceptions-for-using-wsl-1-rather-than-wsl-2). The primary differences between WSL 1 and WSL 2 are the use of an actual Linux kernel inside a managed VM, support for full system call compatibility, and performance across the Linux and Windows operating systems. WSL 2 is the current default version when installing a Linux distribution and uses the latest and greatest in virtualization technology to run a Linux kernel inside of a lightweight utility virtual machine (VM). WSL2 runs Linux distributions as isolated containers inside the managed VM. If your distribution is currently running WSL 1 and you want to update to WSL 2, see [update from WSL 1 to WSL 2](./install.md#upgrade-version-from-wsl-1-to-wsl-2).

### Comparing features

Feature | WSL 1 | WSL 2
--- | --- | ---
 Integration between Windows and Linux| ✅|✅
 Fast boot times| ✅ | ✅
 Small resource foot print compared to traditional Virtual Machines| ✅ |✅
 Runs with current versions of VMware and VirtualBox| ✅ | ❌
 Managed VM| ❌ | ✅
 Full Linux Kernel| ❌ |✅
 Full system call compatibility| ❌ | ✅
 Performance across OS file systems| ✅ | ❌
 systemd support| ❌ | ✅
 IPv6 support| ✅ | ✅

As you can tell from the comparison table above, the WSL 2 architecture outperforms WSL 1 in several ways, with the exception of performance across OS file systems, which can be addressed by storing your project files on the same operating system as the tools you are running to work on the project.

WSL 2 is only available in Windows 11 or Windows 10, Version 1903, Build 18362 or later. Check your Windows version by selecting the **Windows logo key + R**, type **winver**, select **OK**. (Or enter the `ver` command in Windows Command Prompt). You may need to [update to the latest Windows version](ms-settings:windowsupdate). For builds lower than 14393, WSL is not supported at all.

For more info on the latest WSL 2 updates, see the [Windows Command Line blog](https://devblogs.microsoft.com/commandline/), including [Systemd support is now available in WSL](https://devblogs.microsoft.com/commandline/systemd-support-is-now-available-in-wsl/) and [WSL September 2023 update](https://devblogs.microsoft.com/commandline/windows-subsystem-for-linux-september-2023-update/) for more info on IPv6 support.

> [!NOTE]
> WSL 2 will work with [VMware 15.5.5+](https://blogs.vmware.com/workstation/2020/05/vmware-workstation-now-supports-hyper-v-mode.html) and although [VirtualBox 6+](https://www.virtualbox.org/wiki/Changelog-6.0) states that there is WSL support, there are still significant challenges that make it unsupported. Learn more in our [FAQs.](./faq.yml#will-i-be-able-to-run-wsl-2-and-other-3rd-party-virtualization-tools-such-as-vmware--or-virtualbox-)

## What's new in WSL 2

WSL 2 is a major overhaul of the underlying architecture and uses virtualization technology and a Linux kernel to enable new features. The primary goals of this update are to increase file system performance and add full system call compatibility.

- [WSL 2 system requirements](./install-manual.md#step-2---check-requirements-for-running-wsl-2)
- [Set your Linux distribution version from WSL 1 to WSL 2](./basic-commands.md#set-wsl-version-to-1-or-2)
- [Frequently Asked Questions about WSL 2](./faq.yml)

### WSL 2 architecture

A traditional VM experience can be slow to boot up, is isolated, consumes a lot of resources, and requires your time to manage it. WSL 2 does not have these attributes.

WSL 2 provides the benefits of WSL 1, including seamless integration between Windows and Linux, fast boot times, a small resource footprint, and requires no VM configuration or management. While WSL 2 does use a VM, it is managed and run behind the scenes, leaving you with the same user experience as WSL 1.

### Full Linux kernel

The Linux kernel in WSL 2 is built by Microsoft from the latest stable branch, based on the source available at kernel.org. This kernel has been specially tuned for WSL 2, optimizing for size and performance to provide an amazing Linux experience on Windows. The kernel will be serviced by Windows updates, which means you will get the latest security fixes and kernel improvements without needing to manage it yourself.

The [WSL 2 Linux kernel is open source](https://github.com/microsoft/WSL2-Linux-Kernel). If you'd like to learn more, check out the blog post [Shipping a Linux Kernel with Windows](https://devblogs.microsoft.com/commandline/shipping-a-linux-kernel-with-windows/) written by the team that built it.

Learn more in the [Release Notes for Windows Subsystem for Linux kernel](./kernel-release-notes.md).

### Increased file IO performance

File intensive operations like git clone, npm install, apt update, apt upgrade, and more are all noticeably faster with WSL 2.

The actual speed increase will depend on which app you're running and how it is interacting with the file system. Initial versions of WSL 2 run up to 20x faster compared to WSL 1 when unpacking a zipped tarball, and around 2-5x faster when using git clone, npm install and cmake on various projects.

### Full system call compatibility

Linux binaries use system calls to perform functions such as accessing files, requesting memory, creating processes, and more. Whereas WSL 1 used a translation layer that was built by the WSL team, WSL 2 includes its own Linux kernel with full system call compatibility. Benefits include:

- A whole new set of apps that you can run inside of WSL, such as **[Docker](tutorials/wsl-containers.md)** and more.

- Any updates to the Linux kernel are immediately ready for use. (You don't have to wait for the WSL team to implement updates and add the changes).

## Exceptions for using WSL 1 rather than WSL 2

We recommend that you use WSL 2 as it offers faster performance and 100% system call compatibility. However, there are a few specific scenarios where you might prefer using WSL 1. Consider using WSL 1 if:

- Your project files must be stored in the Windows file system. WSL 1 offers faster access to files mounted from Windows.
  - If you will be using your WSL Linux distribution to access project files on the Windows file system, and these files cannot be stored on the Linux file system, you will achieve faster performance across the OS files systems by using WSL 1.
- A project which requires cross-compilation using both Windows and Linux tools on the same files.
  - File performance across the Windows and Linux operating systems is faster in WSL 1 than WSL 2, so if you are using Windows applications to access Linux files, you will currently achieve faster performance with WSL 1.
- Your project needs access to a serial port or USB device. *However,* USB device support is now available for WSL 2 via the USBIPD-WIN project. See [Connect USB devices](./connect-usb.md) for set up steps.
- WSL 2 does not include support for accessing serial ports. Learn more in the [FAQs](./faq.yml#can-i-access-the-gpu-in-wsl-2--are-there-plans-to-increase-hardware-support-) or in [WSL GitHub repo issue on serial support](https://github.com/microsoft/WSL/issues/4322).
- You have strict memory requirements
  - WSL 2's memory usage grows and shrinks as you use it. When a process frees memory this is automatically returned to Windows. However, as of right now WSL 2 does not yet release cached pages in memory back to Windows until the WSL instance is shut down. If you have long running WSL sessions, or access a very large amount of files, this cache can take up memory on Windows. We are tracking the work to improve this experience on [the WSL GitHub repository issue 4166](https://github.com/microsoft/WSL/issues/4166).
- For those using VirtualBox, be sure to use the latest version of both VirtualBox and WSL 2. See the [related FAQ](./faq.yml#will-i-be-able-to-run-wsl-2-and-other-3rd-party-virtualization-tools-such-as-vmware--or-virtualbox-). 
- If you rely on a Linux distribution to have an IP address in the same network as your host machine, you may need to set up a workaround in order to run WSL 2. WSL 2 is running as a hyper-v virtual machine. This is a change from the bridged network adapter used in WSL 1, meaning that WSL 2 uses a Network Address Translation (NAT) service for its virtual network, instead of making it bridged to the host Network Interface Card (NIC) resulting in a unique IP address that will change on restart. To learn more about the issue and workaround that forwards TCP ports of WSL 2 services to the host OS, see [WSL GitHub repository issue 4150, NIC Bridge mode (TCP Workaround)](https://github.com/microsoft/WSL/issues/4150).

> [!NOTE]
> Consider trying the VS Code [Remote WSL Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl) to enable you to store your project files on the Linux file system, using Linux command line tools, but also using VS Code on Windows to author, edit, debug, or run your project in an internet browser without any of the performance slow-downs associated with working across the Linux and Windows file systems. [Learn more](tutorials/wsl-vscode.md).

## WSL in the Microsoft Store

WSL has lifted the update functionality out of the Windows OS Image into a package that is available via the Microsoft Store. This means faster updates and servicing as soon as they're available, rather than needing to wait for an update of your Windows operating system.

WSL was originally included in the Windows operating system as an optional component that need to be enabled in order to install a Linux distribution. WSL in the Store has the same user experience, and is the same product, but receives updates and servicing as a store package, rather than as an entire OS update. Beginning in Windows version 19044 or higher, running the `wsl.exe --install` command will install the WSL servicing update from the Microsoft Store. ([See the blog post announcing this update](https://devblogs.microsoft.com/commandline/the-windows-subsystem-for-linux-in-the-microsoft-store-is-now-generally-available-on-windows-10-and-11/)). If you are already using WSL, you can update to ensure that you're receiving the latest WSL features and servicing from the store by running `wsl.exe --update`.
