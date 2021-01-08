---
title: Install or remove Windows 10 Anniversary Update
description: Installation and un-installation instructions for the legacy, beta distro on Windows 10 Anniversary Update or Creators Update
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, debian, suse, windows 10, legacy, beta, install, remove, uninstall, un-install, delete, deprecated
ms.date: 07/24/2018
ms.topic: article
ms.assetid: 7afaeacf-435a-4e58-bff0-a9f0d75b8a51
ms.custom: seodec18
---

# Guide to install or uninstall Windows Subsystem for Linux on Windows 10 Anniversary Update and Creators Update 

If you're running Windows 10 Creators Update or later, please [follow the Windows 10 installation instructions](install-win10.md).

<strong><em><span style="color: #f28014">The following instructions are for users running Windows 10 Anniversary Update or Windows 10 Creators Update</span></em></strong>

Prior to Windows 10 Fall Creators Update (version 1709), WSL was released as a beta feature and installed a single Ubuntu instance when "Bash on Ubuntu on Windows" (or Bash.exe) was first run.

> While you CAN use WSL on earlier Windows 10 releases, this beta "legacy distro" is now considered obsolete. We strongly encourage you to run the most recent version of Windows 10 available. Each new Windows 10 release includes many hundreds of fixes and improvements in WSL alone, allowing ever more Linux tools and apps to run correctly on WSL.

If you cannot upgrade to Fall Creators Update or later, follow the steps below to enable and use WSL:

1. Turn on Developer Mode
    To run WSL on Windows 10 Anniversary Update or Creators Update, you must enable Developer Mode:

    Open **Settings** -> **Update and Security** -> **For developers**

    Select the Developer Mode radio button  
    ![Enable developer mode](media/updateAndSecurity.png)

    > The requirement to enable Developer Mode was [removed in Windows 10 Fall Creators Update](https://blogs.msdn.microsoft.com/commandline/2017/06/08/developer-mode-no-longer-required-for-windows-subsystem-for-linux/)

1. Open a command prompt.  Type `bash` and hit enter

    The first time you run Bash on Ubuntu on Windows, you'll be prompted to accept Canonical's license. Once accepted, WSL will download and install the Ubuntu instance onto your machine, and a "Bash on Ubuntu on Windows" shortcut will be added to your start menu.

    ![Prompt to install Ubuntu](media/bashShellInstall.png)

    The first time you run Bash on Ubuntu on Windows, you will be prompted to create a UNIX username and password. Follow the [new distro instance instructions](initialize-distro.md) to complete your installation

1. Launch a new Ubuntu shell by either:
    * Running `bash` from a command-prompt
    * Clicking the start menu "Bash on Ubuntu on Windows" shortcut

    
## Uninstalling/Removing the legacy distro
If you upgrade to Windows 10 Fall Creators Update from an earlier Windows 10 release upon which you installed WSL, your existing distro will remain intact. However, we STRONGLY encourage you to install a new Store-delivered distro ASAP, and migrate any necessary files, data, etc. from your legacy distro to your new distro.

To remove the legacy distro from your machine, run the following from a Command Line or PowerShell instance:

```console
wsl --unregister Legacy
```

If you are not using Windows Version 1903 or higher, you may need to run `wslconfig /u Legacy` or `lxrun /uninstall /full` instead. 

### Manually deleting the legacy distro
If you wish, you can manually delete your legacy instance. This may be required if you encounter issues uninstalling the legacy distro using `lxrun.exe`, or are running Windows 10 Spring 2018 Update (or later) which do not ship with `lxrun.exe`.

To forcefully delete your legacy WSL distro, delete the `%localappdata%\lxss\` folder (and all it's sub-contents) using Windows' File Explorer, or the command-line:

Using PowerShell
```powershell
rm -Recurse $env:localappdata/lxss/
```

Using Cmd:
```console
DEL /S %localappdata%\lxss\
```
