---
title: Install Linux Subsystem on Windows Server
description: Learn how to install the Linux Subsystem on Windows Server. WSL is available for installation on Windows Server 2019 (version 1709) and later.
ms.date: 06/14/2022
ms.topic: install-set-up-deploy
---

# Windows Server Installation Guide

The Windows Subsystem for Linux (WSL) is available for installation on Windows Server 2019 (version 1709) and later. This guide will walk through the steps of enabling WSL on your machine.

## Install WSL on Windows Server 2022 and 2025 Desktop Experience

[Windows Server 2022](/windows-server/get-started/whats-new-in-windows-server-2022) now supports a simple WSL installation using the command:

```powershell
wsl.exe --install
```

You can now install everything you need to run WSL on Windows Server 2022 by entering this command in an **administrator** PowerShell and then restarting your machine.

This command will enable the required optional components, download the latest Linux kernel, set WSL 2 as your default, and install a Linux distribution for you *(Ubuntu by default)*.

See the standard WSL docs for more information on how to:

- [Change the default Linux distribution installed](install.md#change-the-default-linux-distribution-installed).
- [Set up your Linux username and password](./setup/environment.md#set-up-your-linux-username-and-password).
- [Check which version of WSL you are running](./install.md#check-which-version-of-wsl-you-are-running)
- [Update and upgrade packages](./setup/environment.md#update-and-upgrade-packages).
- [Add additional distributions](./setup/environment.md#add-additional-distributions).
- [Use Git with WSL](./tutorials/wsl-git.md).

## Install WSL on previous versions of Windows Server and Server Core

To install WSL on Windows Server 2019 (version 1709+), as well as Server Core for 2019 and later you can follow the manual install steps below.

### Enable the Windows Subsystem for Linux

Before you can run Linux distributions on Windows, you must enable the "Windows Subsystem for Linux" optional feature and reboot.

Open PowerShell **as Administrator** and run:

```powershell
Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux, VirtualMachinePlatform
```

### Install the WSL Kernel update for WSL 2

This is not necessary for server core 2025.

```powershell
Invoke-WebRequest -Uri "https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi" -OutFile ".\wsl_update_x64.msi"
Start-Process "msiexec.exe" -ArgumentList "/i .\wsl_update_x64.msi /quiet" -NoNewWindow -Wait
```

### Download a Linux distribution

See the [Downloading distributions](./install-manual.md#downloading-distributions) section of the manual installation page for instructions and links to download your preferred Linux distribution.

### Extract and install a Linux distribution

Now that you've downloaded a Linux distribution, in order to extract its contents and manually install, follow these steps. Note that you will be downloading an appx file that contains several appx files. In this example we will use debian.

1. List the contents of the appx using tar.exe:

    ```cmd
    > tar -xf .\debian.appx
    DistroLauncher-Appx_1.12.2.0_ARM64.appx
    DistroLauncher-Appx_1.12.2.0_scale-100.appx
    DistroLauncher-Appx_1.12.2.0_scale-125.appx
    DistroLauncher-Appx_1.12.2.0_scale-150.appx
    DistroLauncher-Appx_1.12.2.0_scale-400.appx
    DistroLauncher-Appx_1.12.2.0_x64.appx
    ```

    In our example we have a x64 bit server so we want to install `DistroLauncher-Appx_1.12.2.0_x64.appx`.

1. Unzip the contents to a new folder called `\%USERPROFILE%\AppData\Local\DebianWSL\`.

    ```powershell
    $debianWSLPath = Join-Path -Path $env:LocalAppData -ChildPath DebianWSL
    New-Item -Path $debianWSLPath -ItemType Directory | Out-Null
    tar -xf .\DistroLauncher-Appx_1.12.2.0_x64.appx -C "$env:USERPROFILE\AppData\Local\DebianWSL"
    ```

1. Add your Linux distribution path to the Windows environment PATH (`C:\Users\Administrator\Ubuntu` in this example), using PowerShell:

    ```powershell
    $userenv = [System.Environment]::GetEnvironmentVariable("Path", "User")
    [System.Environment]::SetEnvironmentVariable("PATH", $userenv + ";$env:USERPROFILE\AppData\Local\DebianWSL", "User")
    ```

You can now launch your distribution from any path by typing `<DistributionName>.exe`. For example: `ubuntu.exe`. Note that you will need to launch a new powershell instance from the start menu or log off and log on again in the case of Server core to refresh your path

Once installation is complete, you can [create a user account and password for your new Linux distribution](./setup/environment.md#set-up-your-linux-username-and-password).
