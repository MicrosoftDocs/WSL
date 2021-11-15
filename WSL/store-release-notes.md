---
title: Release Notes for WSL in the Microsoft Store
description: Release notes for the Windows Subsystem for Linux
keywords: release notes, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, kernel
ms.date: 10/11/2021
ms.topic: article
ms.localizationpriority: high
---

# Release Notes for Windows Subsystem for Linux in the Microsoft Store

These release notes are for [WSL inside of the Microsoft Store](https://aka.ms/wslstorepage).

## Known Issues:
* Launching Windows Subsystem from Linux from session zero does not currently work (for example from an ssh connection).
* The Linux icon in Windows Explorer will only appear if you have the Windows Subsystem for Linux Optional Component installed.

## 0.50.2.0

* Added new logo for Windows Subsystem for Linux
* Enable hardware performance counters if the hardware supports them [GH 4678]
    A `%USERPROFILE%\.wslconfig` option has been added to opt-out:
    ```
    [wsl2]
    hardwarePerformanceCounters=false
    ```
* Fix issue when printing system error messages that contain inserts
* Update the user tile to launch in the user's home directory instead of C:\WINDOWS\System32
* Restore default signal dispositions for /etc/wsl.conf boot.command process to prevent zombie processes [GH 7575]
* Switch to using a static CRT for Windows binaries
* Use store API to download distributions via `wsl.exe --install`
* Add `--no-launch` option to `wsl.exe --install`
* Many updates to localized strings
* Update to the official 22000 sdk
* Strip Linux symbols for release builds
* Update Linux kernel to 5.10.74.3
 * Update to upstream stable kernel release 5.10.74
 * Enable BPF Type Format (CONFIG_DEBUG_INFO_BTF) for use by eBPF tools [GH 7437]
 * Changed Dxgkrnl version to 2110
  * Implemented D3DKMTShareObjectWithHost
  * Fixed QueryStatistics VM bus alignment issue for the result
  * Implemented D3DKMTCreateSyncFile
  * Address upstream submission feedback
  * Moved d3dkmthk to include/uapi/misc
  * Replaces u32 by __u32 and u64 by __u64
  * Added "_" in front of the enumerator values to support including both WDK and Linux headers
  * Removed holes in the user mode visible structures to be compatible with 32 bit apps
  * Replaces pointer in the user mode visible structures with a define to be u64 for user mode apps
  * Fix build failure with GCC versions older than 8.1 [GH 7558]
 * Enable the Buffer Sharing and Sync File Frameworks (CONFIG_DMA_SHARED_BUFFER, CONFIG_SYNC_FILE) for Dxgkrnl usage

## 0.48.2.0

* Fix issue preventing Windows binaries from launching from inside the Linux filesystem [GH 7521].
* Fix error handling condition for `wsl --mount --bare`.
* Add localized strings for the following locales: `cs-CZ;da-DK;de-DE;en-GB;en-US;es-ES;fi-FI;fr-FR;hu-HU;it-IT;ja-JP;ko-KR;nb-NO;nl-NL;pl-PL;pt-BR;pt-PT;ru-RU;sv-SE;tr-TR;zh-CN;zh-TW`. We are investigating an issue where some strings are not being properly localized.
* Fix for /etc/fstab mounts so they are present in both elevated and non-elevated mount namespaces.
* Added a 5 second retry timeout to `wsl.exe --mount` operations.
* Simplify vm idle termination logic
* Update `wsl.exe --mount` to support passing options before the disk name for example: `wsl.exe --mount --vhd foo.vhdx`
* Allow individual distros to opt-out of GUI applications via a new /etc/wsl.conf setting:
  ```
  [general]
  guiApplications=false
  ```
* Ensure requested amount of swap size is available to Linux (previously was a page smaller than requested due to mkswap overhead).

## 0.47.1.0

* WSLg is now bundled as part of the WSL app!
  * Update Microsoft.WSLg to version 1.0.29
  * Switch to msrdc.exe for WSLg
  * Enable virtio for ARM64 to enable WSLg shared memory.
  * Allow environment variables used by WSLG to be overridden by WSLENV
* New `wsl.exe –mount` features!
  * Add mount `--vhd` to make mounting VHD files easier.
  * Implement filesystem detection for `wsl.exe --mount`. This change implements filesystem type detection if no `--type` is specified when using `wsl.exe --mount`.
  * Add `--name` feature to `wsl.exe --mount`. This change adds support for optionally naming a mountpoint when mounting a disk through WSL.
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
* Fix \\\\wsl$\\ and \\\\wsl.localhost\\ issues on ARM64.
* Switch to mkfs.ext4 instead of pre-formatted ext4 VHD.
* Switch to using mkswap and swapon instead of custom swap file logic. [GH 5476]
* Add logic to dynamically update the MTU of the NAT network
* Fix for /etc/wsl.conf generateResolvConf not working as expected [GH 6977]
* Added progress indicator helper function used to show a Please Wait message with animated dots on the conversion process to show users that WSL is still running.
* Switch wslhost.exe to a win32 app.
* Switch `wsl.exe --install` to not require the `--distribution` argument. This change switches `wsl.exe --install` to not require the `--distribution` argument but maintains support to avoid breaking existing scripts.
* Add `wsl.exe --version` command
* Add Windows version to `wsl.exe --status` and `wsl.exe --version`
* Cleanup wsl.exe invalid argument handling to make syntax errors easier to self-diagnose.
* If the app is launched via the tile, prompt the user for input before closing the console window.
* Add error message dialog for wslg.exe
* Simplify print for unsupported command line arguments.
* Print a better error message if the user runs `wsl.exe --install` when WSL is already installed
* Add special error codes for custom kernel not present, and custom kernel not supported (ARM64)
* Update `wsl.exe --update` to launch the store page.
* Improved stability and performance of localhost relay.
* Additional performance and stability improvements.
