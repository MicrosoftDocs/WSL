---
title: Install Linux Subsystem on Windows 10
description: Installation Guide
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu
author: jackchammons
ms.date: 9/6/2016
ms.topic: article
ms.prod: windows-subsystem-for-linux
ms.service: windows-subsystem-for-linux
ms.assetid: 7afaeacf-435a-4e58-bff0-a9f0d75b8a51
---

# Installation Guide

> **Important note**:
> Bash on Windows and the Windows Subsystem for Linux are “beta” features. We know that there are issues and gaps in 
> compatibility. You should expect many things to work and for some things to fail. We appreciate 
> any and all constructive feedback you can share from your experiences in using Bash/WSL. 
> Your [bug reports](https://github.com/microsoft/bashonwindows) help us diagnose issues we 
> need to fix in order to deliver a great experience.

## Prerequisites
1. Your PC must be running (at a minimum) a 64-bit version of Windows 10 Anniversary Update. **Creators Update is recommended.**

> To find your PC's CPU architecture and Windows version/build number, open 
> **Settings**>**System**>**About**. 
> Look for the **OS Build** and **System Type** fields.  

![](media/system.png) 

If your build is below 14393, [try checking for updates.](https://support.microsoft.com/en-us/instantanswers/c4a6d3df-d0d4-42b6-0018-ca48577f9909/update-windows-10)


## Installation
In order to run Bash on Windows, you will need to manually:

### 1. Turn on Developer Mode
1. Open Settings -> Update and Security -> For developers
2. Select the Developer Mode radio button  
	![](media/updateAndSecurity.png)

### 2. Enable the Windows Subsystem for Linux feature (GUI)
1. From Start, search for "Turn Windows features on or off" (type 'turn')
2. Select **Windows Subsystem for Linux (beta)**  
3. Click OK
	![](media/windowsFeatures.png)
  


#### Enable the Windows Subsystem for Linux feature (command-line)

Open a PowerShell prompt as administrator and run:

```PowerShell
Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```

### 3. Restart your Computer

> Portions of the Windows Subsystem for Linux can only be activated during the boot up sequence. Installation cannot proceed until this restart is completed.

### 4. Accept the License and Expand the Image
1. Open a command prompt
1. Run `bash` 
  
  ![](media/bashShellInstall.png)
  
After you have accepted the License, the Ubuntu user-mode image will be downloaded and extracted. A "Bash on Ubuntu on Windows" shortcut will be added to your start menu.

To launch Bash on Windows, either run `bash` at a cmd/PowerShell command-prompt, or use the start menu shortcut.

After installation your Linux distribution will be located at: `%localappdata%\lxss\`.

> **Avoid creating and/or modifying files in %localappdata%\lxss\ using Windows tools 
> and apps!** If you do, it is likely that your Linux files will be corrupted and data loss may occur. Avoid this issue by using a directory located under /mnt/.
> Please read this [blog post](https://blogs.msdn.microsoft.com/commandline/2016/11/17/do-not-change-linux-files-using-windows-apps-and-tools/) 
> for more information.

### 5. Create a UNIX user
The first time you install Bash on Windows, you will be prompted to create a UNIX username and password.

![](media/new-user.png)
  
This UNIX username and password can be different from, and has no relationship to your Windows username 
and password. [Learn more about your UNIX account.](https://msdn.microsoft.com/en-us/commandline/wsl/user_support).
