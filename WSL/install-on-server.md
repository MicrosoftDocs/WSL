---
title: Install the Linux Subsystem on Windows Server
description: Installation instructions for the Linux Subsystem on Windows Server.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, windows server
author: scooley
ms.author: scooley
ms.date: 05/22/2018
ms.topic: article
ms.assetid: 9281ffa2-4fa9-4078-bf6f-b51c967617e3
ms.custom: seodec18
---

# Windows Server Installation Guide

> Applies to Windows Server 2019 and later

At //Build2017, Microsoft announced that Windows Subsystem for Linux will be [available on Windows Server](https://blogs.technet.microsoft.com/hybridcloud/2017/05/10/windows-server-for-developers-news-from-microsoft-build-2017/).  These instructions walk through running the Windows Subsystem for Linux on Windows Server 1709 and later.

## Enable the Windows Subsystem for Linux (WSL)

Before you can run Linux distros on Windows, you must enable the "Windows Subsystem for Linux" optional feature and reboot.

1. Open PowerShell as Administrator and run:
    ```powershell
    Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
    ```

2. Restart your computer when prompted. **This reboot is required** in order to ensure that WSL can initiate a trusted execution environment.

## Download a Linux distro

Follow [these instructions](install-manual.md) to download your favorite Linux distribution.

## Extract and install a Linux distro
Now that you've downloaded a distro, extract its contents and manually install the distro:

1. Extract the `<distro>.appx` package's contents, e.g. using PowerShell:

    ```powershell
    Rename-Item ~/Ubuntu.appx ~/Ubuntu.zip
    Expand-Archive ~/Ubuntu.zip ~/Ubuntu
    ```

    > Make sure your target directory (`~/Ubuntu` in this example) is on your system drive. Usually this is your `C:` drive. For example: `C:\Distros\Ubuntu`

2. Run the distro launcher
    To complete installation, run the distro launcher application in the target folder, named `<distro>.exe`. For example: `ubuntu.exe`, etc.

    ![Expanded Ubuntu distro on Windows Server](media/server-appx-expand.png)

    > **Troubleshooting**
    > * **Installation failed with error 0x8007007e**: This error occurs when your system doesn't support WSL. Make sure that:
    >   * You're running Windows build 16215 or later. [Check your build](troubleshooting.md#check-your-build-number).
    >   * The Windows Subsystem for Linux optional component is enabled and the computer has restarted.  [Make sure WSL is enabled](troubleshooting.md#confirm-wsl-is-enabled).
    
3. Add your distro path to the Windows environment PATH (`C:\Distros\Ubuntu` in this example), e.g. using Powershell:
        
    ```powershell
    $userenv = [System.Environment]::GetEnvironmentVariable("Path", "User")
    [System.Environment]::SetEnvironmentVariable("PATH", $userenv.TrimEnd(';') + ";C:\Distros\Ubuntu", "User")
    ```
    You can now launch your distro from any path by typing `<distro>.exe`. For example: `ubuntu.exe`

Now that your Linux distro is installed, you must [initialize your new distro instance](initialize-distro.md) before using your distro.
