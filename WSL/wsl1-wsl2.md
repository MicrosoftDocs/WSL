---
title: An overview on the the Windows Subsystem for Linux
description: Learn about the Windows Subsystem for Linux, the different versions and ways you can use them.
keywords: BashOnWindows, bash, wsl, windows, windowssubsystem, gnu, linux
ms.date: 03/23/2020
ms.topic: article
---

# Comparing WSL 2 and WSL 1


WSL 2 uses the latest and greatest in virtualization technology to run its Linux kernel inside of a lightweight utility virtual machine (VM). However, WSL 2 will NOT be a traditional VM experience. 

## Benefits and best practices 

Feature | WSL1 | WSL2
--- | --- | ---
 Integration between Windows and Linux| ✅|✅
 Fast boot times| ✅ | ✅
 Small resource foot print| ✅ |✅
 Managed VM| ❌ | ✅
 Full Linux Kernel| ❌ |✅
 Full system call compatibility| ❌ | ✅
 Runs with VM Ware and VirtualBox| ✅ |❌
 Fastest cross OS file performance| ✅ | ❌




With full system call compatibility and lightning fast speeds, WSL2 can be used for all of your typical Windows and Linux operations. However, its best to use WSL1 for the following cases.
### Consider using WSL1 for

* A project which has to be stored in the Windows file system
  + If the files cannot be stored in the Linux file system, use WSL1 and store them in the Windows file system
* A project which requires cross compilation using both Windows and Linux tools on the same files 
  + Cross-os file performance is faster in WSL1 than WSL2
 


## New in WSL2
### Architecture overview
A traditional VM experience can be slow to boot up, is isolated, consumes lots of resources, and requires your time to manage it. WSL 2 does not have these attributes. It will still give the remarkable benefits of WSL 1: High levels of integration between Windows and Linux, extremely fast boot times, small resource footprint, and best of all will require no VM configuration or management. While WSL 2 does use a VM, it will be managed and run behind the scenes leaving you with the same user experience as WSL 1.

### Full Linux kernel
The Linux kernel in WSL 2 is built in house from the latest stable branch, based on the source available at kernel.org. This kernel has been specially tuned for WSL 2. It has been optimized for size and performance to give an amazing Linux experience on Windows and will be serviced through Windows updates, which means you will get the latest security fixes and kernel improvements without needing to manage it yourself.
Additionally this kernel will be open source. You can find the full source code for the Linux kernel here. If you'd like to read more about this kernel you can check out this blog post written by the team that built it.

### Increased file IO performance
File intensive operations like git clone, npm install, apt update, apt upgrade, and more will all be noticeably faster. The actual speed increase will depend on which app you're running and how it is interacting with the file system. Initial versions of WSL 2 run up to 20x faster compared to WSL 1 when unpacking a zipped tarball, and around 2-5x faster when using git clone, npm install and cmake on various projects.

### Full system call compatibility
Linux binaries use system calls to perform many functions such as accessing files, requesting memory, creating processes, and more. Whereas WSL 1 used a translation layer that was built by the WSL team, WSL 2 includes its own Linux kernel with full system call compatibility. This introduces a whole new set of apps that you can run inside of WSL, such as Docker and more. Additionally, any updates to the Linux kernel can be immediately ready to be added to your computer, rather than waiting for the WSL team to implement the changes and then have them added.
                                                