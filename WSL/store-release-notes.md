---
title: Release Notes for WSL in the Microsoft Store
description: Release notes for the Windows Subsystem for Linux
keywords: release notes, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, kernel
ms.date: 09/27/2021
ms.topic: article
ms.localizationpriority: high
---

# Release Notes for Windows Subsystem for Linux in the Microsoft Store

These release notes are for WSL inside of the Microsoft Store, which can be accessed [via this link](https://aka.ms/wslstorepage).

## 0.47.1.0 

* WSLg is now bundled as part of the WSL app! 
    * Update Microsoft.WSLg to version 1.0.29 
    * Switch to msrdc.exe for WSLg 
    * Enable virtio for ARM64to enabled WSLg shared memory. 
    * Allow environment variables used by WSLG to be overridden by WSLENV 
* New `wsl.exe –mount` features! 
    * Add mount `--vhd` to make mounting VHD files easier. 
    * Implement filesystem detection for `wsl.exe --mount`. This change implements filesystem type detection if no `--type` is specified when using wsl.exe --mount. 
    * Add --name feature to `wsl.exe --mount`. This change adds support for optionally naming a mountpoint when mounting a disk through WSL. 
* Update Linux kernel to 5.10.60.1 
    * Enable additional USB kernel configuration options for interacting with an Arduino over USB 
    * Update to upstream stable kernel release 5.10.60 
    * Enable virtio-pmem with support for PCI BAR-relative addresses 
    * Enable vPCI support under Hyper-V for ARM64 
    * Enable io_uring support 
    * Enable USB over IP support 
    * Enable paravirtualized spinlock support for x86_64 
    * Refresh dxgkrnl driver to pick up bug fixes and code cleanups 
    * Enable NFS client support for NFSv4.1* Improve the error message when 9p or fstab mounts fail 
* Fix \\wsl$\ and \\wsl.localhost\ issues on ARM64. 
* Switch to mkfs.ext4 instead of pre-formatted ext4 VHD. 
* Switch to using mkswap and swapon instead of custom swap file logic. [GH 5476] 
* Add logic to dynamically update the MTU of the NAT network 
* Fix for /etc/wsl.conf generateResolvConf not working as expected [GH 6977] 
* Added progress indicator helper function used to show a Please Wait message with animated dots on the conversion process to show users that WSL is still running. 
* Switch wslhost.exe to a win32 app. 
* Switch `wsl.exe --install` to not require the --distribution argument. This change switches `wsl.exe --install` to not require the `--distribution` argument but maintains support to avoid breaking existing scripts. 
* Add `wsl.exe --version` command 
* Add Windows version to `wsl.exe --status` and `wsl.exe --version` 
* Cleanup wsl.exe invalid argument handling to make syntax errors easier to self-diagnose. 
* If the app is launched via the tile, prompt the user for input before closing the console window. 
* Add error message dialog for wslg.exe 
* Simplify print for unsupported command line arguments. 
* Print a better error message if the user runs wsl.exe --install when WSL is already installed 
* Add special error codes for custom kernel not present, and custom kernel not supported (ARM64) 
* Update `wsl.exe --update` to work with the lifted package - this launches the store page. 
* Improved stability and performance of localhost relay. 
* Additional performance and stability improvements. 

 