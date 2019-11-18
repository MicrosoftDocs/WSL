---
title: Install WSL 2
description: Installation instructions for WSL 2
keywords: BashOnWindows, bash, wsl, wsl2, windows, windows subsystem for linux, windowssubsystem, ubuntu, debian, suse, windows 10, install
ms.date: 05/30/2019
ms.topic: article
ms.assetid: 7afaeacf-435a-4e58-bff0-a9f0d75b8a51
ms.custom: seodec18
---

# Installation Instructions for WSL 2

To install and start using WSL 2 complete the following steps:

> WSL 2 is only available in Windows 10 builds 18917 or higher

- Ensure that you have WSL installed (you can find instructions to do so [here](./install-win10.md)) and that you are running Windows 10 **build 18917** or higher
   - To make sure you are using build 18917 or higher please join [the Windows Insider Program](https://insider.windows.com/en-us/) and select the 'Fast' ring. 
   - You can check your Windows version by opening Command Prompt and running the `ver` command.
- Enable the 'Virtual Machine Platform' optional component
- Set a distro to be backed by WSL 2 using the command line
- Verify what versions of WSL your distros are using

## Enable the 'Virtual Machine Platform' optional component and make sure WSL is enabled

To enable the 'Virtual Machine Platform' component open PowerShell as an administrator and run the command below. If you are installing WSL for the first time then select 'No' when prompted for a restart, as you will need to restart your machine anyway after installing the 'Windows Subsystem for Linux' optional component.

```powershell
Enable-WindowsOptionalFeature -Online -FeatureName VirtualMachinePlatform
```

You will also need to make sure that the Windows Subsystem for Linux optional component is enabled. You can do this by running the following command from a PowerShell window with administrator privileges: 

```powershell
Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```

Please restart your machine to finish installing both components.


## Set a distro to be backed by WSL 2 using the command line

If you do not have a Linux distro installed, please refer to the [Install on Windows 10](./install-win10.md#install-your-linux-distribution-of-choice) docs page for instructions on installing one. 

In PowerShell run:

`wsl --set-version <Distro> 2`

and make sure to replace `<Distro>` with the actual name of your distro. (You can find these with the command: `wsl -l`). You can change back to WSL 1 at anytime by running the same command as above but replacing the '2' with a '1'.

Additionally, if you want to make WSL 2 your default architecture you can do so with this command:

`wsl --set-default-version 2`

This will make any new distro that you install be initialized as a WSL 2 distro.

## Finish with verifying what versions of WSL your distro are using

To verify what versions of WSL each distro is using use the following command (only available in Windows Build 18917 or higher):

`wsl --list --verbose` or `wsl -l -v`

The distro that you've chosen above should now display a '2' under the 'version' column. Now that you're finished feel free to start using your WSL 2 distro! 

## Troubleshooting: 

Below are related errors and suggested fixes when installing WSL 2. Please refer to the [WSL troubleshooting page](troubleshooting.md) for other general WSL errors and their solutions.

* **Installation failed with error 0x80070003 or error 0x80370102**
    * Please make sure that virtualization is enabled inside of your computer's BIOS. The instructions on how to do this will vary from computer to computer, and will most likely be under CPU related options.
   
* **Error when trying to upgrade: `Invalid command line option: wsl --set-version Ubuntu 2`**
    * Please make sure that you have the Windows Subsystem for Linux enabled, and that you're using Windows Build version 18917 or higher. To enable WSL run this command in a Powershell prompt with admin privileges: `Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux`. You can find the full WSL install instructions [here](./install-win10.md).

* **The requested operation could not be completed due to a virtual disk system limitation. Virtual hard disk files must be uncompressed and unencrypted and must not be sparse.**
    * Please check [WSL Github thread #4103](https://github.com/microsoft/WSL/issues/4103) where this issue is being tracked for updated information.