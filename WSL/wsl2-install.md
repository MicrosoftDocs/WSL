---
title: Install WSL 2
description: Installation instructions for WSL 2
keywords: BashOnWindows, bash, wsl, wsl2, windows, windows subsystem for linux, windowssubsystem, ubuntu, debian, suse, windows 10, install
ms.date: 05/30/2019
ms.topic: article
ms.assetid: 7afaeacf-435a-4e58-bff0-a9f0d75b8a51
ms.custom: seodec18
ms.localizationpriority: high
---

# Installation Instructions for WSL 2

To install and start using WSL 2 complete the following steps:

- Ensure that you have WSL installed (you can find instructions to do so [here](./install-win10.md)) and that you are running Windows 10 **build 18917** or higher. You can check your Windows version by opening Command Prompt and running the `ver` command.
- [Enable the optional Virtual Machine Platform feature](#enable-the-virtual-machine-platform-optional-component)
- [Set the distribution to version 2](#set-the-distribution-to-version-2)
- [Verify your WSL distribution version](#verify-your-wsl-distribution-version)

## Enable the Virtual Machine Platform optional component

You will need to make sure that you have both the Windows Subsystem for Linux and the Virtual Machine Platform optional components installed. You can do that by running the following command in PowerShell:

```powershell
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
```

Please restart your machine to finish installing both components.

## Set the distribution to version 2

If you do not have a Linux distribution installed, please refer to the [Install on Windows 10](./install-win10.md#install-a-linux-distribution) docs page for instructions on installing one.

To set a distribution to WSL 2, use the command:

```powershell
wsl --set-version <Distro> 2
```

Be sure to replace `<Distro>` with the actual name of your distribution. (You can find these with the command: `wsl -l`). You can change back to WSL 1 at anytime by running the same command as above but replacing the '2' with a '1'.

Additionally, if you want to make WSL 2 your default architecture you can do so with this command:

```powershell
wsl --set-default-version 2
```

This will default any new distribution that you install to be initialized as WSL 2.

## Verify your WSL distribution version

To verify what versions of WSL each distro is using use the following command (only available in Windows Build 18917 or higher):

`wsl --list --verbose` or `wsl -l -v`

The distribution that you've chosen above should now display a '2' under the 'version' column. Now that you're finished feel free to start using your WSL 2 distribution!

## Troubleshooting

Below are related errors and suggested fixes when installing WSL 2. Please refer to the [WSL troubleshooting page](troubleshooting.md) for other general WSL errors and their solutions.

### Installation failed with error 0x80070003 or error 0x80370102

Please make sure that virtualization is enabled inside of your computer's BIOS. The instructions on how to do this will vary from computer to computer, and will most likely be under CPU related options.

### Error when trying to upgrade

`Invalid command line option: wsl --set-version Ubuntu 2`

Please make sure that you have the Windows Subsystem for Linux enabled, and that you're using Windows Build version 18917 or higher. To enable WSL run this command in a Powershell prompt with admin privileges: `Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux`. Visit the full [WSL install instructions](./install-win10.md).

### The requested operation could not be completed due to a virtual disk system limitation

Virtual hard disk files must be uncompressed and unencrypted and must not be sparse. Please check [WSL Github thread #4103](https://github.com/microsoft/WSL/issues/4103) where this issue is being tracked for updated information.

### The term 'wsl' is not recognized as the name of a cmdlet, function, script file, or operable program

Ensure that the [Windows Subsystem for Linux Optional Component is installed](./wsl2-install.md#enable-the-optional-virtual-machine-platform-feature).

Additionally, if you are using an Arm64 device and running this command from PowerShell, you will receive this error. Instead run `wsl.exe` from [PowerShell Core](https://docs.microsoft.com/powershell/scripting/install/installing-powershell-core-on-windows?view=powershell-6), or Command Prompt.

Ensure that the [Windows Subsystem for Linux Optional Component is installed](./wsl2-install.md#enable-the-optional-virtual-machine-platform-feature).

Additionally, if you are using an Arm64 device and running this command from PowerShell, you will receive this error. Instead run `wsl.exe` from [PowerShell Core](https://docs.microsoft.com/powershell/scripting/install/installing-powershell-core-on-windows?view=powershell-6), or Command Prompt.
