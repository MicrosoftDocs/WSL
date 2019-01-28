---
title: Install Windows Subsystem for Linux (WSL) on Windows 10
description: Installation instructions for the Windows Subsystem for Linux on Windows 10.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, debian, suse, windows 10, install
author: taraj
ms.author: taraj
ms.date: 07/23/2018
ms.topic: article
ms.assetid: 7afaeacf-435a-4e58-bff0-a9f0d75b8a51
ms.custom: seodec18
---

# Windows Subsystem for Linux Installation Guide for Windows 10

## Install the Windows Subsystem for Linux

Before installing any Linux distros for WSL, you must ensure that the "Windows Subsystem for Linux" optional feature is enabled:

1. Open PowerShell as Administrator and run:
    ```powershell
    Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
    ```

2. Restart your computer when prompted.

## Install your Linux Distribution of Choice
To download and install your preferred distro(s), you have three choices:
1. Download and install from the Windows Store (see below)
1. Download and install from the Command-Line/Script ([read the manual installation instructions](install-manual.md))
1. Download and manually unpack and install (for Windows Server - [instructions here](install-on-server.md))

### Windows 10 Fall Creators Update and later: Install from the Microsoft Store

> This section is for Windows build 16215 or later.  Follow these steps to [check your build](troubleshooting.md#check-your-build-number). 

1. Open the Microsoft Store and choose your favorite Linux distribution.

    ![View of Linux distros in the Windows store](media/store.png)

    The following links will open the Windows store page for each distribution:

    * [Ubuntu](https://www.microsoft.com/store/p/ubuntu/9nblggh4msv6)
    * [OpenSUSE](https://www.microsoft.com/store/apps/9njvjts82tjx)
    * [SLES](https://www.microsoft.com/store/apps/9p32mwbh6cns)
    * [Kali Linux](https://www.microsoft.com/store/apps/9PKR34TNCV07)
    * [Debian GNU/Linux](https://www.microsoft.com/store/apps/9MSVKQC78PK6)

1. From the distro's page, select "Get"

    ![View of Linux distros in the Windows store](media/UbuntuStore.png)

## Complete initialization of your distro
Now that your Linux distro is installed, you must [initialize your new distro instance](initialize-distro.md) once, before it can be used.

## Troubleshooting: 

Below are related errors and suggested fixes. Refer to the [WSL troubleshooting page](troubleshooting.md) for other common errors and their solutions.

* **Installation failed with error 0x80070003**
    * The Windows Subsystem for Linux only runs on your system drive (usually this is your `C:` drive). Make sure that distros are stored on your system drive:  
    * Open **Settings** -> **Storage** -> **More Storage Settings: Change where new content is saved**
    ![Picture of system settings to install apps on C: drive](media/AppStorage.png)
