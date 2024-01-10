---
title: Install Linux Subsystem on Windows Server
description: Learn how to install the Linux Subsystem on Windows Server. WSL is available for installation on Windows Server 2019 (version 1709) and later.
ms.date: 06/14/2022
ms.topic: article
---

# Windows Server Installation Guide

The Windows Subsystem for Linux (WSL) is available for installation on Windows Server 2019 (version 1709) and later. This guide will walk through the steps of enabling WSL on your machine.

## Install WSL on Windows Server 2022

[Windows Server 2022](/windows-server/get-started/whats-new-in-windows-server-2022) now supports a simple WSL installation using the command:

```bash
wsl --install
```

You can now install everything you need to run WSL on Windows Server 2022 by entering this command in an **administrator** PowerShell or Windows Command Prompt and then restarting your machine.

This command will enable the required optional components, download the latest Linux kernel, set WSL 2 as your default, and install a Linux distribution for you *(Ubuntu by default)*.

See the standard WSL docs for more information on how to:

- [Change the default Linux distribution installed](install.md#change-the-default-linux-distribution-installed).
- [Set up your Linux username and password](./setup/environment.md#set-up-your-linux-username-and-password).
- [Check which version of WSL you are running](./install.md#check-which-version-of-wsl-you-are-running)
- [Update and upgrade packages](./setup/environment.md#update-and-upgrade-packages).
- [Add additional distributions](./setup/environment.md#add-additional-distributions).
- [Use Git with WSL](./tutorials/wsl-git.md).

## Install WSL on previous versions of Windows Server

To install WSL on Windows Server 2019 (version 1709+), you can follow the manual install steps below.

### Enable the Windows Subsystem for Linux

Before you can run Linux distributions on Windows, you must enable the "Windows Subsystem for Linux" optional feature and reboot.

Open PowerShell **as Administrator** and run:

```powershell
Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```

### Download a Linux distribution

See the [Downloading distributions](install-manual.md#downloading-distributions) section of the manual installation page for instructions and links to download your preferred Linux distribution.

### Extract and install a Linux distribution

Now that you've downloaded a Linux distribution, in order to extract its contents and manually install, follow these steps:

1. Extract the `<DistributionName>.appx` package's contents, using PowerShell:

    ```powershell
    Rename-Item .\Ubuntu.appx .\Ubuntu.zip
    Expand-Archive .\Ubuntu.zip .\Ubuntu
    ```

2. Once the distribution has been downloaded, navigate to the folder containing the download and run the following command in that directory, where `app-name` is the name of the Linux distribution .appx file.

    ```Powershell
    Add-AppxPackage .\app_name.appx
    ```

    > [!CAUTION]
    > **Installation failed with error 0x8007007e**: If you receive this error, then your system doesn't support WSL. Ensure that you're running Windows build 16215 or later. [Check your build](troubleshooting.md#check-your-build-number). Also check to [confirm that WSL is enabled](troubleshooting.md#confirm-wsl-is-enabled) and your computer was restarted after the feature was enabled.  

3. Add your Linux distribution path to the Windows environment PATH (`C:\Users\Administrator\Ubuntu` in this example), using PowerShell:

    ```powershell
    $userenv = [System.Environment]::GetEnvironmentVariable("Path", "User")
    [System.Environment]::SetEnvironmentVariable("PATH", $userenv + ";C:\Users\Administrator\Ubuntu", "User")
    ```

You can now launch your distribution from any path by typing `<DistributionName>.exe`. For example: `ubuntu.exe`.

Once installation is complete, you can [create a user account and password for your new Linux distribution](./setup/environment.md#set-up-your-linux-username-and-password).
