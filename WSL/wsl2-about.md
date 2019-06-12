---
title: About WSL 2
description: About WSL 2 the new architecture for the Windows Subsystem for Linux
keywords: BashOnWindows, bash, wsl, wsl2, windows, windows subsystem for linux, windowssubsystem, ubuntu, debian, suse, windows 10, install
author: mscraigloewen
ms.author: mscraigloewen
ms.date: 05/30/2019
ms.topic: article
ms.assetid: 7afaeacf-435a-4e58-bff0-a9f0d75b8a51
ms.custom: seodec18
---

WSL 2 is a new version of the architecture that powers the Windows Subsystem for Linux to run ELF64 Linux binaries on Windows. Its primary goals are to increase file system performance, as well as adding full system call compatibility. This new architecture changes how these Linux binaries interact with Windows and your computer’s hardware, but still provides the same user experience as in WSL 1 (the current widely available version). Individual Linux distros can be run either as a WSL 1 distro, or as a WSL 2 distro, can be upgraded or downgraded at any time, and you can run WSL 1 and WSL 2 distros side by side. WSL 2 uses an entirely new architecture that uses a real Linux kernel.

# Linux kernel in WSL 2

The Linux kernel in WSL 2 is built in house from the latest stable branch, based on the source available at kernel.org. This kernel has been specially tuned for WSL 2. It has been optimized for size and performance to give an amazing Linux experience on Windows and will be serviced through Windows updates, which means you will get the latest security fixes and kernel improvements without needing to manage it yourself.

Additionally this kernel will be open source. You can find the full source code for the Linux kernel [here](https://thirdpartysource.microsoft.com/download/Windows%20Subsystem%20for%20Linux%20v2/May%202019/WSLv2-Linux-Kernel-master.zip). If you’d like to read more about this kernel you can check out [this blog post](https://devblogs.microsoft.com/commandline/shipping-a-linux-kernel-with-windows/) written by the team that built it.

# Brief overview of the WSL 2 architecture

WSL 2 uses the latest and greatest in virtualization technology to run its Linux kernel inside of a lightweight utility virtual machine (VM). However, WSL 2 will NOT be a traditional VM experience. A traditional VM experience can be slow to boot up, is isolated, consumes lots of resources, and requires your time to manage it. WSL 2 does not have these attributes. It will still give the remarkable benefits of WSL 1: High levels of integration between Windows and Linux, extremely fast boot times, small resource footprint, and best of all will require no VM configuration or management. While WSL 2 does use a VM, it will be managed and run behind the scenes leaving you with the same user experience as WSL 1.

# Increased file IO performance

File intensive operations like git clone, npm install, apt update, apt upgrade, and more will all be noticeably faster. The actual speed increase will depend on which app you’re running and how it is interacting with the file system. Initial versions of WSL 2 run up to 20x faster compared to WSL 1 when unpacking a zipped tarball, and around 2-5x faster when using git clone, npm install and cmake on various projects.

# Full System Call Compatibility

Linux binaries use system calls to perform many functions such as accessing files, requesting memory, creating processes, and more. Whereas WSL 1 used a translation layer that was built by the WSL team, WSL 2 includes its own Linux kernel with full system call compatibility. This introduces a whole new set of apps that you can run inside of WSL, such as Docker and more. Additionally, any updates to the Linux kernel can be immediately ready to be added to your computer, rather than waiting for the WSL team to implement the changes and then have them added.