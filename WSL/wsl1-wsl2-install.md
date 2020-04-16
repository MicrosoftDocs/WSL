---
title: Install Windows Subsystem for Linux (WSL) on Windows 10
description: Installation instructions for the Windows Subsystem for Linux on Windows 10.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, debian, suse, windows 10, install
ms.date: 03/30/2020
ms.topic: article
---

# Windows Subsystem for Linux Installation Guide for Windows 10

## Install the Windows Subsystem for Linux

Before installing any Linux distros for WSL, you must ensure that the "Windows Subsystem for Linux" optional feature is enabled:

Open PowerShell as Administrator and run:

```powershell
    Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```

**If you're looking for 100% system call compatibility and faster IO performance, read below to install WSL 2!**
> WSL 2 is only available in Windows 10 builds 18917 or higher

**If continuing with WSL 1, restart your machine when prompted and continue with installation [here](./wsl1-wsl2-install.md##install-your-linux-distribution-of-choice)**

## Install the Windows Subsystem for Linux 2

To install and start using WSL 2 complete the following steps:

1. Ensure that you are running Windows 10 **build 18917** or higher
   - To make sure you are using build 18917 or higher please join [the Windows Insider Program](https://insider.windows.com/) and select the 'Fast' ring or the 'Slow' ring.
   - You can check your Windows version by opening Command Prompt and running the `ver` command.
2. Enable the 'Virtual Machine Platform' optional component
3. Install a Linux distribution of your choice
4. Set a distro to be backed by WSL1 or WSL2 using the command line
5. Verify what versions of WSL your distros are using

## Enable the 'Virtual Machine Platform' optional component

For WSL 2, you will also need to make sure that you have the Virtual Machine Platform optional component installed. You can do that by running the following command in PowerShell:

```powershell
dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
```

Please restart your machine to finish installing both components.

## Install your Linux Distribution of Choice

To download and install your preferred distro(s), you have three choices:

- Download and install from the Microsoft Store (see below)
- Download and install from the Command-Line/Script ([read the manual installation instructions](install-manual.md))
- Download and manually unpack and install (for Windows Server - [instructions here](install-on-server.md))

### Windows 10 Fall Creators Update and later: Install from the Microsoft Store

> This section is for Windows build 16215 or later.  Follow these steps to [check your build](troubleshooting.md#check-your-build-number).

1. Open the Microsoft Store and choose your favorite Linux distribution.

    ![View of Linux distros in the Microsoft Store](media/store.png)

    The following links will open the Microsoft store page for each distribution:

    - [Ubuntu 16.04 LTS](https://www.microsoft.com/store/apps/9pjn388hp8c9)
    - [Ubuntu 18.04 LTS](https://www.microsoft.com/store/apps/9N9TNGVNDL3Q)
    - [OpenSUSE Leap 15](https://www.microsoft.com/store/apps/9n1tb6fpvj8c)
    - [OpenSUSE Leap 42](https://www.microsoft.com/store/apps/9njvjts82tjx)
    - [SUSE Linux Enterprise Server 12](https://www.microsoft.com/store/apps/9p32mwbh6cns)
    - [SUSE Linux Enterprise Server 15](https://www.microsoft.com/store/apps/9pmw35d7fnlx)
    - [Kali Linux](https://www.microsoft.com/store/apps/9PKR34TNCV07)
    - [Debian GNU/Linux](https://www.microsoft.com/store/apps/9MSVKQC78PK6)
    - [Fedora Remix for WSL](https://www.microsoft.com/store/apps/9n6gdm4k2hnc)
    - [Pengwin](https://www.microsoft.com/store/apps/9NV1GV1PXZ6P)
    - [Pengwin Enterprise](https://www.microsoft.com/store/apps/9N8LP0X93VCP)
    - [Alpine WSL](https://www.microsoft.com/store/apps/9p804crf0395)

1. From the distro's page, select "Get"

    ![View of Linux distros in the Microsoft store](media/UbuntuStore.png)

## Complete initialization of your distro

After launching your Linux distribution, follow the onscreen instructions to initialize your distro.

> [!NOTE]
> For Windows Server, launch your distribution using the executable, `<distro>.exe`, in the installation folder.

The first time a newly installed distribution runs, a console window will open and you'll be asked to wait for a minute or two for the installation to complete. During this final stage of installation, the distro's files are de-compressed and stored on your PC, ready for use. This may take around a minute or more depending on the performance of your PC's storage devices. This initial installation phase is only required when a distro is clean-installed - all future launches should take less than a second.

### Set up a new Linux user account

Once installation is complete, you will be prompted to create a new user account (and its password).

![Ubuntu unpacking in the Windows console](media/UbuntuInstall.png)

This user account is for the normal non-admin user that you'll be logged-in as by default when launching a distribution. You can choose any username and password you wish - they have no bearing on your Windows username.

When you open a new distro instance, you won't be prompted for your password, but **if you elevate a process using `sudo`, you will need to enter your password**, so make sure you choose a password you can easily remember! See the [User Support](user-support.md) page for more info.

### Update & upgrade packages

Most distributions ship with an empty or minimal package catalog. We strongly recommend regularly updating your package catalog and upgrading your installed packages using your distro's preferred package manager. For Debian/Ubuntu, use apt:

```bash
sudo apt update && sudo apt upgrade
```

Windows does not automatically update or upgrade your Linux distro(s). This is a task that the most Linux users prefer to control themselves.

## Set a distro to be backed by WSL1 or WSL2 using the command line

To set a distro to be backed by either version of WSL please run:

```bash
wsl --set-version <Distro> <versionNumber>
```

Make sure to replace `<Distro>` with the actual name of your distro and `<versionNumber>` with the number '1' or '2'. (You can find these with the command: `wsl -l`). You can change back to WSL 1 at anytime by running the same command as above but replacing the '2' with a '1'.

Additionally, if you want to make WSL 2 your default architecture you can do so with this command:

```bash
wsl --set-default-version 2
```

This will make any new distro that you install be initialized as a WSL 2 distro.

## Finish with verifying what versions of WSL your distro are using

To verify what versions of WSL each distro is using use the following command (only available in Windows Build 18917 or higher):

`wsl --list --verbose` or `wsl -l -v`

The distro that you've chosen above should now display either a '1' or '2' under the 'version' column. Now that you're finished feel free to start using any WSL distro!

## Troubleshooting

Below are related errors and suggested fixes. Refer to the [WSL troubleshooting page](troubleshooting.md) for other common errors and their solutions.

- **Installation failed with error 0x80070003**
  - The Windows Subsystem for Linux only runs on your system drive (usually this is your `C:` drive). Make sure that distros are stored on your system drive:  
  - Open **Settings** -> **Storage** -> **More Storage Settings: Change where new content is saved**
    ![Picture of system settings to install apps on C: drive](media/AppStorage.png)

- **WslRegisterDistribution failed with error 0x8007019e**
  - The Windows Subsystem for Linux optional component is not enabled:
  - Open **Control Panel** -> **Programs and Features** -> **Turn Windows Feature on or off** -> Check **Windows Subsystem for Linux** or using the PowerShell cmdlet mentioned at the begining of this article.

- **Installation failed with error 0x80070003 or error 0x80370102**
  - Please make sure that virtualization is enabled inside of your computer's BIOS. The instructions on how to do this will vary from computer to computer, and will most likely be under CPU related options.

- **Error when trying to upgrade: `Invalid command line option: wsl --set-version Ubuntu 2`**
  - Please make sure that you have the Windows Subsystem for Linux enabled, and that you're using Windows Build version 18917 or higher. To enable WSL run this command in a Powershell prompt with admin privileges: `Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux`. You can find the full WSL install instructions [here](./install-win10.md).

- **The requested operation could not be completed due to a virtual disk system limitation. Virtual hard disk files must be uncompressed and unencrypted and must not be sparse.**
  - Please check [WSL Github thread #4103](https://github.com/microsoft/WSL/issues/4103) where this issue is being tracked for updated information.

- **The term 'wsl' is not recognized as the name of a cmdlet, function, script file, or operable program.**
  - Ensure that the [Windows Subsystem for Linux Optional Component is installed](./wsl2-install.md#enable-the-virtual-machine-platform-optional-component). Additionally, if you are using an Arm64 device and running this command from PowerShell, you will receive this error. Instead run `wsl.exe` from [PowerShell Core](https://docs.microsoft.com/powershell/scripting/install/installing-powershell-core-on-windows?view=powershell-6), or Command Prompt.
