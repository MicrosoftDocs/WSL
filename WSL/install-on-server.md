---
title: Install the Linux Subsystem on Windows Server
description: Installation instructions for the Linux Subsystem on Windows Server.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, windows server
ms.date: 05/12/2020
ms.topic: article
ms.localizationpriority: high
---

# Windows Server Installation Guide

The Windows Subsystem for Linux is available for installation on Windows Server 2019 (version 1709) and later. This guide will walk through the steps of enabling WSL on your machine.

## Enable the Windows Subsystem for Linux

Before you can run Linux distros on Windows, you must enable the "Windows Subsystem for Linux" optional feature and reboot.

Open PowerShell as Administrator and run:

```powershell
    Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux

```

## Download a Linux distribution

Follow [these instructions](install-manual.md) to download your favorite Linux distribution.

## Extract and install a Linux distribution

Now that you've downloaded a Linux distribution, in order to extract its contents and manually install, follow these steps:

1. Extract the `<distro>.appx` package's contents, using PowerShell:

    ```powershell
    Rename-Item .\Ubuntu.appx .\Ubuntu.zip
    Expand-Archive .\Ubuntu.zip .\Ubuntu
    ```

2. Run the distribution launcher application in the target folder. The launcher is typically named `<distro>.exe` (for example, `ubuntu.exe`).

    ![Expanded Ubuntu distro on Windows Server](media/server-appx-expand.png)

> [!CAUTION]
> **Installation failed with error 0x8007007e**: If you receive this error, then your system doesn't support WSL. Ensure that you're running Windows build 16215 or later. [Check your build](troubleshooting.md#check-your-build-number). Also check to [confirm that WSL is enabled](troubleshooting.md#confirm-wsl-is-enabled) and your computer was restarted after the feature was enabled.  

3.Add your distro path to the Windows environment PATH (`C:\Users\Administrator\Ubuntu` in this example), using PowerShell:

```powershell
$userenv = [System.Environment]::GetEnvironmentVariable("Path", "User")
[System.Environment]::SetEnvironmentVariable("PATH", $userenv + ";C:\Users\Administrator\Ubuntu", "User")
```

You can now launch your distribution from any path by typing `<distro>.exe`. For example: `ubuntu.exe`.

Now that it is installed, you must [initialize your new distribution instance](initialize-distro.md) before using it.
