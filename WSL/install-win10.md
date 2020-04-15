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

# Install Windows Subsystem for Linux

The following guide will walk through the steps required to install the Windows Subsystem for Linux (WSL) on a computer running Windows 10. 

## Enable the Windows Subsystem for Linux optional feature

Before installing a Linux distribution, you must enable the "Windows Subsystem for Linux" optional feature on Windows 10:

1. Open PowerShell as Administrator and enter this script:
    ```powershell
    Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
    ```

2. Restart your computer when prompted.


## Install a Linux distribution

There are three ways to download and install your preferred Linux distribution(s):

- Download and install from the Microsoft Store (see below)
- [Download and manually install from command line](install-manual.md)
- [Install on Windows Server]](install-on-server.md)

### Install from the Microsoft Store

Linux distributions can be installed from the Microsoft Store on Windows 10 (Build 16215+). 

> [!NOTE]
> Follow these steps to [check your Windows 10 build number](troubleshooting.md#check-your-build-number). 

1. Open the Microsoft Store and choose your favorite Linux distribution.

    ![View of Linux distros in the Microsoft Store](media/store.png)

    The following links will open the Microsoft store page for each distribution:

    * [Ubuntu 16.04 LTS](https://www.microsoft.com/store/apps/9pjn388hp8c9)
    * [Ubuntu 18.04 LTS](https://www.microsoft.com/store/apps/9N9TNGVNDL3Q)
    * [OpenSUSE Leap 15](https://www.microsoft.com/store/apps/9n1tb6fpvj8c)
    * [OpenSUSE Leap 42](https://www.microsoft.com/store/apps/9njvjts82tjx)
    * [SUSE Linux Enterprise Server 12](https://www.microsoft.com/store/apps/9p32mwbh6cns)
    * [SUSE Linux Enterprise Server 15](https://www.microsoft.com/store/apps/9pmw35d7fnlx)
    * [Kali Linux](https://www.microsoft.com/store/apps/9PKR34TNCV07)
    * [Debian GNU/Linux](https://www.microsoft.com/store/apps/9MSVKQC78PK6)
    * [Fedora Remix for WSL](https://www.microsoft.com/store/apps/9n6gdm4k2hnc)
    * [Pengwin](https://www.microsoft.com/store/apps/9NV1GV1PXZ6P)
    * [Pengwin Enterprise](https://www.microsoft.com/store/apps/9N8LP0X93VCP)
    * [Alpine WSL](https://www.microsoft.com/store/apps/9p804crf0395)

1. Select "Get" and once the distribution has finished downloading, select "Launch". 

    ![View of Linux distros in the Microsoft store](media/UbuntuStore.png)

## Complete initialization of your distro

After launching your Linux distribution, follow the onscreen instructions to initialize your distro.

> [!NOTE]
> For Windows Server, launch your distribution using the executable, `<distro>.exe`, in the installation folder.

The first time a newly installed distribution runs, a console window will open and you'll be asked to wait for a minute or two for the installation to complete. During this final stage of installation, the distro's files are de-compressed and stored on your PC, ready for use. This may take around a minute or more depending on the performance of your PC's storage devices. This initial installation phase is only required when a distro is clean-installed - all future launches should take less than a second.

## Set up a new Linux user account

Once installation is complete, you will be prompted to create a new user account (and its password). 

![Ubuntu unpacking in the Windows console](media/UbuntuInstall.png)

This user account is for the normal non-admin user that you'll be logged-in as by default when launching a distribution. You can choose any username and password you wish - they have no bearing on your Windows username. 

When you open a new distro instance, you won't be prompted for your password, but **if you elevate a process using `sudo`, you will need to enter your password**, so make sure you choose a password you can easily remember! See the [User Support](user-support.md) page for more info.

## Update & upgrade packages

Most distributions ship with an empty or minimal package catalog. We strongly recommend regularly updating your package catalog and upgrading your installed packages using your distro's preferred package manager. For Debian/Ubuntu, use apt:

```bash
sudo apt update && sudo apt upgrade
```

Windows does not automatically update or upgrade your Linux distro(s). This is a task that the most Linux users prefer to control themselves.

Enjoy using your new Linux distro on WSL! 

## Troubleshooting

Below are related installation errors and suggested fixes. Refer to the [WSL troubleshooting page](troubleshooting.md) for other common errors and their solutions.

### Installation failed with error 0x8007007e

This error occurs when your system doesn't support Linux from the store.  Make sure that:
- You're running Windows build 16215 or later. [Check your build](troubleshooting.md#check-your-build-number).
- The Windows Subsystem for Linux optional component is enabled and the computer has restarted.  [Make sure WSL is enabled](troubleshooting.md#confirm-wsl-is-enabled).

### Installation failed with error 0x80070003

The Windows Subsystem for Linux only runs on your system drive (usually this is your `C:` drive). Make sure that distros are stored on your system drive: 

- Open **Settings** -> **Storage** -> **More Storage Settings: Change where new content is saved**
    
    ![Picture of system settings to install apps on C: drive](media/AppStorage.png)

### WslRegisterDistribution failed with error 0x8007019e

The Windows Subsystem for Linux optional component is not enabled: 

- Open **Control Panel** -> **Programs and Features** -> **Turn Windows Feature on or off** -> Check **Windows Subsystem for Linux** or using the PowerShell cmdlet mentioned at the begining of this article.
                                                                                                