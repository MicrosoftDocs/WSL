---
title: Manual installation steps for older versions of WSL
description: Step by step instructions to manually install WSL on older versions of Windows, rather than using the wsl install command.
keywords: wsl, install, BashOnWindows, bash, windows subsystem for linux, install ubuntu on windows, enable WSL2, linux on windows
ms.date: 02/07/2025
ms.topic: article
adobe-target: true
---

# Manual installation steps for older versions of WSL

For simplicity, we generally recommend using the [`wsl --install`](./install.md) to install Windows Subsystem for Linux, but if you're running an older build of Windows, that may not be supported. We have included the manual installation steps below. If you run into an issue during the install process, check the [installation section of the troubleshooting guide](./troubleshooting.md#installation-issues).

## Step 1 - Enable the Windows Subsystem for Linux

You must first enable the "Windows Subsystem for Linux" optional feature before installing any Linux distributions on Windows.

Open PowerShell **as Administrator (Start menu > PowerShell > right-click > Run as Administrator)** and enter this command:

```powershell
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
```

We recommend now moving on to [Step 2 - Check requirements for running WSL 2](#step-2---check-requirements-for-running-wsl-2), updating to WSL 2, but if you wish to only install WSL 1, you can now **restart** your machine and move on to [Step 6 - Install your Linux distribution of choice](#step-6---install-your-linux-distribution-of-choice). To update to WSL 2, **wait to restart** your machine and move on to the next step.

## Step 2 - Check requirements for running WSL 2

To update to WSL 2, you must be running Windows 10...

- For x64 systems: **Version 1903** or later, with **Build 18362.1049** or later.
- For ARM64 systems: **Version 2004** or later, with **Build 19041** or later.

or Windows 11.
> [!NOTE]
> Builds lower than 18362 do not support WSL 2. Use the [Windows Update Assistant](https://www.microsoft.com/software-download/windows10) to update your version of Windows. The Windows version 1903 support is also only for x64 systems. If you are using an Arm64 version of Windows, you will need to upgrade to Windows 10 version 2004 or later for full access to WSL 2. For more info, see [WSL 2 support coming to Windows 10 Versions 1903 and 1909](https://devblogs.microsoft.com/commandline/wsl-2-support-is-coming-to-windows-10-versions-1903-and-1909).

To check your version and build number, select **Windows logo key + R**, type **winver**, select **OK**. [Update to the latest Windows version](ms-settings:windowsupdate) in the Settings menu.

> [!NOTE]
> If you are running Windows 10 version 1903 or 1909, open "Settings" from your Windows menu, navigate to "Update & Security" and select "Check for Updates". Your Build number must be 18362.1049+ or 18363.1049+, with the minor build # over .1049. Read more: [WSL 2 Support is coming to Windows 10 Versions 1903 and 1909](https://devblogs.microsoft.com/commandline/wsl-2-support-is-coming-to-windows-10-versions-1903-and-1909/).

## Step 3 - Enable Virtual Machine feature

Before installing WSL 2, you must enable the **Virtual Machine Platform** optional feature. Your machine will require [virtualization capabilities](./troubleshooting.md#error-0x80370102-the-virtual-machine-could-not-be-started-because-a-required-feature-is-not-installed) to use this feature.

Open PowerShell as Administrator and run:

```powershell
dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
```

**Restart** your machine to complete the WSL install and update to WSL 2.

## Step 4 - Download the Linux kernel update package

The Linux kernel update package installs the most recent version of the [WSL 2 Linux kernel](https://github.com/microsoft/WSL2-Linux-Kernel) for running WSL inside the Windows operating system image. (To run [WSL from the Microsoft Store](./compare-versions.md#wsl-in-the-microsoft-store), with more frequently pushed updates, use `wsl.exe --install` or `wsl.exe --update`.).

1. Download the latest package:
    - [WSL2 Linux kernel update package for x64 machines](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi)
    - [WSL2 Linux kernel update package for ARM64 machines](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_arm64.msi)

    > [!NOTE]
    > If you don't know your system architecture, press the :::no-loc text="Win + X"::: keys, find System in the menu, or press the :::no-loc text="Y"::: key to open the "About System" settings (or Control Panel) interface, and find the architecture of your current system.

2. Run the update package downloaded in the previous step. (Double-click to run - you will be prompted for elevated permissions, select ‘yes’ to approve this installation.)

Once the installation is complete, move on to the next step - setting WSL 2 as your default version when installing new Linux distributions. (Skip this step if you want your new Linux installs to be set to WSL 1).

> [!NOTE]
> For more information, read the article [changes to updating the WSL2 Linux kernel](https://devblogs.microsoft.com/commandline/wsl2-will-be-generally-available-in-windows-10-version-2004), available on the [Windows Command Line Blog](https://aka.ms/cliblog).

## Step 5 - Set WSL 2 as your default version

Open PowerShell and run this command to set WSL 2 as the default version when installing a new Linux distribution:

```powershell
wsl --set-default-version 2
```

## Step 6 - Install your Linux distribution of choice

1. Open the [Microsoft Store](ms-windows-store://collection?CollectionId=LinuxDistros) and select your favorite Linux distribution.

    ![View of Linux distributions in the Microsoft Store](media/store.png)

    The following links will open the Microsoft store page for each distribution:

    - Ubuntu:
        - [Ubuntu](https://apps.microsoft.com/detail/9PDXGNCFSCZV)
        - [Ubuntu 24.04.1 LTS](https://apps.microsoft.com/detail/9NZ3KLHXDJP5)
        - [Ubuntu 22.04.5 LTS](https://apps.microsoft.com/detail/9PN20MSR04DW)
        - [Ubuntu 20.04.6 LTS](https://apps.microsoft.com/detail/9MTTCL66CPXJ)
        - [Ubuntu 20.04 LTS](https://apps.microsoft.com/detail/9N6SVWS3RX71)
        - [Ubuntu 18.04.6 LTS](https://apps.microsoft.com/detail/9PNKSF5ZN4SW)
        - [Ubuntu 18.04 LTS](https://apps.microsoft.com/detail/9N9TNGVNDL3Q)
        - [Ubuntu (Preview)](https://apps.microsoft.com/detail/9P7BDVKVNXZ6)
    - Debian:
        - [Debian](https://apps.microsoft.com/detail/9MSVKQC78PK6)
    - Arch Linux:
        - [Arch WSL](https://apps.microsoft.com/detail/9MZNMNKSM73X)
    - Fedora:
        - [Fedora WSL](https://apps.microsoft.com/detail/9NPCP8DRCHSN)
    - deepin:
        - [deepin WSL](https://apps.microsoft.com/detail/9P6HT7L0QGRH)
    - Alpine Linux:
        - [Alpine WSL](https://apps.microsoft.com/detail/9P804CRF0395)
    - openEuler:
        - [openEuler 24.09](https://apps.microsoft.com/detail/9P6NZFGV79KJ)
        - [openEuler 24.03](https://apps.microsoft.com/detail/9PKZ8GN18L5C)
        - [openEuler 23.09](https://apps.microsoft.com/detail/9N8XNFG3J1HT)
        - [openEuler 23.03](https://apps.microsoft.com/detail/9NW527WWDBCZ)
        - [openEuler 22.09](https://apps.microsoft.com/detail/9MWVQSNTMS7G)
        - [openEuler 22.03](https://apps.microsoft.com/detail/9P9RSPJDKX9G)
        - [openEuler 20.03](https://apps.microsoft.com/detail/9NWB78L1MPS2)
    - SUSE:
        - openSUSE:
            - [openSUSE Tumbleweed](https://apps.microsoft.com/detail/9MSSK2ZXXN11)
            - [openSUSE Leap 15.6](https://apps.microsoft.com/detail/9NJGLDP5G04B)
            - [openSUSE Leap 15.5](https://apps.microsoft.com/detail/9NJGLDP5G04B)
            - [openSUSE-Leap-15-1](https://apps.microsoft.com/detail/9NJFZK00FGKV)
        - SUSE Linux:
            - [SUSE Linux Enterprise 15 SP6](https://apps.microsoft.com/detail/9N738KZGNB91)
            - [SUSE Linux Enterprise 15 SP5](https://apps.microsoft.com/detail/9N648JDGXK2D)
            - [SUSE Linux Enterprise Server 15 SP1](https://apps.microsoft.com/detail/9PN498VPMF3Z)
            - [SUSE Linux Enterprise Server 12 SP5](https://apps.microsoft.com/detail/9MZ3D1TRP8T1)
    - Pistachio Linux:
        - [Pistachio Linux](https://apps.microsoft.com/detail/9P41G2MV9CQ3)
    - Kali Linux:
        - [Kali Linux](https://apps.microsoft.com/detail/9PKR34TNCV07)
    - Oracle Linux:
        - [Oracle Linux 9.4](https://apps.microsoft.com/detail/9PMC1FJR3JF3)
        - [Oracle Linux 9.3](https://apps.microsoft.com/detail/9N5MGJ01CVXC)
        - [Oracle Linux 9.2](https://apps.microsoft.com/detail/9P068SN43NBQ)
        - [Oracle Linux 9.1](https://apps.microsoft.com/detail/9N6CN5STZRX6)
        - [Oracle Linux 9](https://apps.microsoft.com/detail/9MXQ65HLMC27)
        - [Oracle Linux 8.10](https://apps.microsoft.com/detail/9MVFWTCT78ZN)
        - [Oracle Linux 8.9](https://apps.microsoft.com/detail/9PP4JL775K1G)
        - [Oracle Linux 8.8](https://apps.microsoft.com/detail/9NPBTNKMPVVV)
        - [Oracle Linux 8.7](https://apps.microsoft.com/detail/9NGGZVB0BKD9)
        - [Oracle Linux 8.6](https://apps.microsoft.com/detail/9PGKJC9GPP2S)
        - [Oracle Linux 8.5](https://apps.microsoft.com/detail/9P06H18WXBVP)
        - [Oracle Linux 7.9](https://apps.microsoft.com/detail/9P7L0QWBSLTK)
    - AlmaLinux OS:
        - [AlmaLinux OS 9](https://apps.microsoft.com/detail/9P5RWLM70SN9)
        - [AlmaLinux OS 8](https://apps.microsoft.com/detail/9NMD96XJJ19F)
    - AOSC OS:
        - [AOSC OS on WSL](https://apps.microsoft.com/detail/9NMDF21NV65Z)
    - Athena OS
        - [Athena OS](https://apps.microsoft.com/detail/9N1M7Q4F1KQF)
    - Slackware:
        - [WSLackware](https://apps.microsoft.com/detail/9N8WPJWZ4JX7) (Unofficial)
    - Fedora Remix:
        - [Fedora Remix for WSL](https://apps.microsoft.com/detail/9N6GDM4K2HNC) (Paid)
    - Pengwin:
        - [Pengwin](https://apps.microsoft.com/detail/9NV1GV1PXZ6P) (Paid)
        - [Pengwin Enterprise 9](https://apps.microsoft.com/detail/9P70GX2HQNHN) (Paid)
        - [Pengwin Enterprise 8](https://apps.microsoft.com/detail/9N2XZFWMRRQW) (Paid)
        - [Pengwin Enterprise 7](https://apps.microsoft.com/detail/9N8LP0X93VCP)
    - Rocky Linux:
        - [RLU 9](https://apps.microsoft.com/detail/9NQ0DQKJG91N) (Unofficial, Paid)
        - [Rocky 8 RC Unofficial](https://apps.microsoft.com/detail/9N6P6053RS25) (Unofficial, Paid)
    - Azure Linux:
        - [Swabbie](https://apps.microsoft.com/detail/9PLZ9KQTM5FN) (Unofficial, Paid)
        - [Swabbie2](https://apps.microsoft.com/detail/9NX9DX5B8QKN) (Unofficial, Paid)

    *Paid only indicates that it is paid in the Microsoft Store, but it does not mean that it has no other free download channels.

2. From the distribution's page, select "Get".

    ![Linux distributions in the Microsoft store](media/UbuntuStore.png)

The first time you launch a newly installed Linux distribution, a console window will open and you'll be asked to wait for a minute or two for files to de-compress and be stored on your PC. All future launches should take less than a second.

You will then need to [create a user account and password for your new Linux distribution](./setup/environment.md#set-up-your-linux-username-and-password).

![Ubuntu unpacking in the Windows console](media/UbuntuInstall.png)

**CONGRATULATIONS! You've successfully installed and set up a Linux distribution that is completely integrated with your Windows operating system!**

## Troubleshooting installation

If you run into an issue during the install process, check the [installation section of the troubleshooting guide](./troubleshooting.md#installation-issues).

## Downloading distributions

There are some scenarios in which you may not be able (or want) to, install WSL Linux distributions using the Microsoft Store. You may be running a Windows Server or Long-Term Servicing (LTSC) desktop OS SKU that doesn't support Microsoft Store, or your corporate network policies and/or admins do not permit Microsoft Store usage in your environment. In these cases, while WSL itself is available, you may need to download Linux distributions directly.

If the Microsoft Store app is not available, you can download and manually install Linux distributions using these links:

- Ubuntu:
  - [Ubuntu](https://aka.ms/wslubuntu) (x64, arm64)
  - [Ubuntu 24.04 LTS](https://wslstorestorage.blob.core.windows.net/wslblob/Ubuntu2404-240425.AppxBundle) (x64, arm64)
  - [Ubuntu 22.04 LTS](https://aka.ms/wslubuntu2204) (x64, arm64)
  - [Ubuntu 20.04 LTS](https://aka.ms/wslubuntu2004) (x64, arm64)
  - [Ubuntu 18.04 LTS](https://aka.ms/wsl-ubuntu-1804) (x64)
  - [Ubuntu 18.04 LTS ARM](https://aka.ms/wsl-ubuntu-1804-arm) (arm64)
  - [Ubuntu 16.04](https://aka.ms/wsl-ubuntu-1604) (x64)
- Debian:
  - [Debian GNU/Linux](https://aka.ms/wsl-debian-gnulinux) (x64, arm64)
- Kali Linux:
  - [Kali Linux Rolling](https://aka.ms/wsl-kali-linux-new)
- OracleLinux:
  - [Oracle Linux 9.1](https://publicwsldistros.blob.core.windows.net/wsldistrostorage/OracleLinux_9.1-230428.Appx) (x64)
  - [Oracle Linux 8.7](https://publicwsldistros.blob.core.windows.net/wsldistrostorage/OracleLinux_8.7-230428.Appx) (x64)
  - [Oracle Linux 8.5](https://aka.ms/wsl-oraclelinux-8-5) (x64)
  - [Oracle Linux 7.9](https://aka.ms/wsl-oraclelinux-7-9) (x64)
  - SUSE:
    - openSUSE:
      - [openSUSE Tumbleweed](https://aka.ms/wsl-opensuse-tumbleweed) (x64)
      - [openSUSE Leap 15.6](https://publicwsldistros.blob.core.windows.net/wsldistrostorage/SUSELeap15p6-240801_x64.Appx) (x64)
      - [openSUSE Leap 15.3](https://aka.ms/wsl-opensuseleap15-3) (x64)
      - [openSUSE Leap 15.2](https://aka.ms/wsl-opensuseleap15-2) (x64)
    - SUSE Linux:
      - [SUSE Linux Enterprise Server 15 SP6](https://publicwsldistros.blob.core.windows.net/wsldistrostorage/SUSELinuxEnterprise15SP6-241001_x64.Appx) (x64)
      - [SUSE Linux Enterprise Server 15 SP5](https://publicwsldistros.blob.core.windows.net/wsldistrostorage/SUSELinuxEnterprise15_SP5-240801.Appx) (x64)
      - [SUSE Linux Enterprise Server 15 SP3](https://aka.ms/wsl-SUSELinuxEnterpriseServer15SP3) (x64)
      - [SUSE Linux Enterprise Server 15 SP2](https://aka.ms/wsl-SUSELinuxEnterpriseServer15SP2) (x64)
      - [SUSE Linux Enterprise Server 12](https://aka.ms/wsl-sles-12) (x64)
- Fedora Remix:
  - [Fedora Remix for WSL](https://github.com/WhitewaterFoundry/Fedora-Remix-for-WSL/releases) (x64, arm64)

This will cause the `<distro>.appx` packages to download to a folder of your choosing.

If you prefer, you can also download your preferred distribution(s) via the command line, you can use PowerShell with the [Invoke-WebRequest](/powershell/module/microsoft.powershell.utility/invoke-webrequest) cmdlet. For example, to download Ubuntu 20.04:

```powershell
Invoke-WebRequest -Uri https://aka.ms/wslubuntu2004 -OutFile Ubuntu.appx -UseBasicParsing
```

> [!TIP]
> If the download is taking a long time, turn off the progress bar by setting `$ProgressPreference = 'SilentlyContinue'`

You also have the option to use the [curl command-line utility](https://curl.se/) for downloading. To download Ubuntu 20.04 with curl:

```powershell
curl.exe -LR -o ubuntu-2004.Appx https://aka.ms/wslubuntu2204
```

In this example, `curl.exe` is executed (not just `curl`) to ensure that, in PowerShell, the real curl executable is invoked, not the PowerShell curl alias for [Invoke-WebRequest](/powershell/module/microsoft.powershell.utility/invoke-webrequest).

Once the distribution has been downloaded, navigate to the folder containing the download and run the following command in that directory, where `app-name` is the name of the Linux distribution .Appx file.

```powershell
Add-AppxPackage .\app_name.Appx
```

Once the Appx package has finished downloading, you can start running the new distribution by double-clicking the appx file. (The command `wsl -l` will not show that the distribution is installed until this step is complete).

If you are using Windows server, or run into problems running the command above you can find the alternate install instructions on the [Windows Server](install-on-server.md) documentation page to install the `.Appx` file by changing it to a zip file.

Once your distribution is installed, follow the instructions to [create a user account and password for your new Linux distribution](./setup/environment.md#set-up-your-linux-username-and-password).

## Install Windows Terminal (optional)

Using Windows Terminal enables you to open multiple tabs or window panes to display and quickly switch between multiple Linux distributions or other command lines (PowerShell, Command Prompt, Azure CLI, etc). You can fully customize your terminal with unique color schemes, font styles, sizes, background images, and custom keyboard shortcuts. [Learn more.](/windows/terminal)

> [!div class="nextstepaction"]
> [Install Windows Terminal](/windows/terminal/install)

![Windows Terminal](media/terminal.png)
