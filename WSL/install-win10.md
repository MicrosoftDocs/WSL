---
title: Install Windows Subsystem for Linux (WSL) on Windows 10
description: Installation instructions for the Windows Subsystem for Linux on Windows 10.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, debian, suse, windows 10, install
ms.date: 07/23/2018
ms.topic: article
ms.assetid: 7afaeacf-435a-4e58-bff0-a9f0d75b8a51
ms.custom: seodec18
ms.localizationpriority: high
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
* Download and install from the Microsoft Store (see below)
* Download and install from the Command-Line/Script ([read the manual installation instructions](install-manual.md))
* Download and manually unpack and install (for Windows Server - [instructions here](install-on-server.md))

### Windows 10 Fall Creators Update and later: Install from the Microsoft Store

> This section is for Windows build 16215 or later.  Follow these steps to [check your build](troubleshooting.md#check-your-build-number). 

1. Open the Microsoft Store and choose your favorite Linux distribution.

    ![View of Linux distros in the Microsoft Store](media/store.png)

    The following links will open the Microsoft store page for each distribution:

    * [Ubuntu 16.04 LTS](https://www.microsoft.com/store/apps/9pjn388hp8c9)
    * [Ubuntu 18.04 LTS](https://www.microsoft.com/store/apps/9N9TNGVNDL3Q)
    * [openSUSE Leap 15.1](https://www.microsoft.com/store/apps/9NJFZK00FGKV)
    * [SUSE Linux Enterprise Server 12 SP5](https://www.microsoft.com/store/apps/9MZ3D1TRP8T1)
    * [SUSE Linux Enterprise Server 15 SP1](https://www.microsoft.com/store/apps/9PN498VPMF3Z)
    * [Kali Linux](https://www.microsoft.com/store/apps/9PKR34TNCV07)
    * [Debian GNU/Linux](https://www.microsoft.com/store/apps/9MSVKQC78PK6)
    * [Fedora Remix for WSL](https://www.microsoft.com/store/apps/9n6gdm4k2hnc)
    * [Pengwin](https://www.microsoft.com/store/apps/9NV1GV1PXZ6P)
    * [Pengwin Enterprise](https://www.microsoft.com/store/apps/9N8LP0X93VCP)
    * [Alpine WSL](https://www.microsoft.com/store/apps/9p804crf0395)

1. From the distro's page, select "Get"

    ![View of Linux distros in the Microsoft store](media/UbuntuStore.png)

## Complete initialization of your distro
Now that your Linux distro is installed, you must [initialize your new distro instance](initialize-distro.md) once, before it can be used.

## Troubleshooting: 

Below are related errors and suggested fixes. Refer to the [WSL troubleshooting page](troubleshooting.md) for other common errors and their solutions.

* **Installation failed with error 0x80070003**
    * The Windows Subsystem for Linux only runs on your system drive (usually this is your `C:` drive). Make sure that distros are stored on your system drive:  
    * Open **Settings** -> **Storage** -> **More Storage Settings: Change where new content is saved**
    ![Picture of system settings to install apps on C: drive](media/AppStorage.png)
    
    
 * **WslRegisterDistribution failed with error 0x8007019e**   
  * The Windows Subsystem for Linux optional component is not enabled: 
   * Open **Control Panel** -> **Programs and Features** -> **Turn Windows Feature on or off** -> Check **Windows Subsystem for Linux** or using the PowerShell cmdlet mentioned at the begining of this article.
