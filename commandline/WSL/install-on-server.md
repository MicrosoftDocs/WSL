---
title: Install the Linux Subsystem on Windows Server
description: Installation instructions for the Linux Subsystem on Windows Server.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, windows 2016
author: scooley
ms.date: 7/11/2017
ms.topic: article
ms.prod: windows-subsystem-for-linux
ms.service: windows-subsystem-for-linux
ms.assetid: 9281ffa2-4fa9-4078-bf6f-b51c967617e3
---

# Windows Server 2016 Installation Guide

At //Build2017, Microsoft announced that Windows Subsystem for Linux will be [available on Windows Server](https://blogs.technet.microsoft.com/hybridcloud/2017/05/10/windows-server-for-developers-news-from-microsoft-build-2017/)!

## Prerequisites
Windows Server 2016 (build 16215+).  Right now, that means a Windows Insider's build.

To find your Windows Server build number, run the following in PowerShell:  
``` PowerShell
systeminfo | findstr /B /C:"OS Name" /C:"OS Version"
```

You can also confirm that your build has the Windows subsystem for Linux by running the following in PowerShell:  
``` PowerShell
Get-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```

## Install the Windows Subsystem for Linux
Enable the "Windows Subsystem for Linux" optional feature and reboot.

1. Open PowerShell as Administrator and run:
    ``` PowerShell
    Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
    ```

2. Restart your computer when prompted.

## For Windows Insiders: Install Linux distribution of choice

1. Download the appx for your favorite Linux distribution.  
Note: This requires us to set up     
    Here are links directly to the store installers:
    * [Ubuntu](https://www.microsoft.com/store/p/ubuntu/9nblggh4msv6)
    * comming soon -- [OpenSUSE](https://www.microsoft.com/store/apps/9njvjts82tjx)
    * comming soon --[SLES](https://www.microsoft.com/store/apps/9p32mwbh6cns)

2.	Place the appx in the directory the user wants to install the distro in.
  > The Windows Subsystem for Linux only runs on your system drive (usually this is your C: drive).

    Example: c:\Distros\Ubuntu

3. Rename the .appx to a .zip  
Note: This step may not be required. I was going to test this but never did. See if the unzip command can unzip .appx natively
[sunilmut] – Step (5) is necessary if we use the command from step (6) as per above. We should see if there is a command that can directly extract from an .appx. Renaming it to .zip looks very silly.

4. Unzip the file into the install directory
Additionally, I do not know if users will need to install compression on their machine or if it is in naturally.  I tested with the following commands but there is probably an easier way:
[System.Reflection.Assembly]::LoadWithPartialName("System.IO.Compression.FileSystem") | Out-Null
Expand-Archive $pathToZip $targetDir

5. Run the .exe.  This would be ubuntu.exe, fedora.exe, etc…
 
5. Create your UNIX username and password.  This user account can be different from, and has no relationship to, your Windows username and password. [Read more](https://msdn.microsoft.com/en-us/commandline/wsl/user_support).

You're done!  Now you can use your Linux environment.

## Install default Linux environment using lxrun
lxrun installs Ubuntu user-mode by default on top of the Windows subsystem for Linux.  

> Since moving to the store, we have stopped keeping this user-mode image up to date.  When you're done, run apt-get update.

1. Turn on Developer Mode  

    Open **Settings** -> **Update and Security** -> **For developers**

    Select the Developer Mode radio button  
    ![](media/updateAndSecurity.png)

2. Open a command prompt.  Run `bash`  
    ![](media/bashShellInstall.png)

    After you have accepted the License, the Ubuntu user-mode image will be downloaded and extracted. A "Bash on Ubuntu on Windows" shortcut will be added to your start menu.

3. Launch a new Ubuntu shell by either:
    * Running `bash` from a command-prompt
    * Clicking the start menu shortcut

4. Create a UNIX user
    
    The first time you install the Windows subsystem for Linux, you will be prompted to create a UNIX username and password.  
    ![](media/new-user.png)
    
    This UNIX username and password can be different from, and has no relationship to, your Windows username and password. [Learn more about your UNIX account.](https://msdn.microsoft.com/en-us/commandline/wsl/user_support).

After installation your Linux distribution will be located at: `%localappdata%\lxss\`.

**Avoid creating and/or modifying files in %localappdata%\lxss\ using Windows tools and apps!** If you do, it is likely that your Linux files will be corrupted and data loss may occur. Avoid this issue by using a directory located under /mnt/.  
Read this [blog post](https://blogs.msdn.microsoft.com/commandline/2016/11/17/do-not-change-linux-files-using-windows-apps-and-tools/) for more information.

You're done!  Go use your new Linux environment!