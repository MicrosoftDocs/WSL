---
title: Bash on Ubuntu on Windows - Command Reference
description: Command Reference
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu
author: jackchammons
ms.date: 9/6/2016
ms.topic: article
ms.prod: windows-subsystem-for-linux
ms.service: windows-subsystem-for-linux
ms.assetid: 82908295-a6bd-483c-a995-613674c2677e
---

# Command Reference

The commands `bash.exe` and `lxrun.exe` are used to interact with the [Windows Subsystem for Linux (WSL)](https://msdn.microsoft.com/en-us/commandline/wsl/faq#what-windows-subsystem-for-linux-wsl-).  These commands are installed into the \Windows\System32 directory and may be run within a Windows command prompt or in PowerShell.

* `bash.exe` launches the Bash environment and invokes /bin/bash.
* `lxrun.exe` is used to manage WSL.  This command can be used to install or uninstall the Ubuntu image.



| Command                     | Description                     |
|:----------------------------|:---------------------------|
| `bash`                      | Launches the Bash shell in the current directory.  If the Bash shell is not installed automatically runs `lxrun /install` |
| `bash ~`                    | Launches the bash shell into the user's Ubuntu home directory.  Similar to running cd ~            |
| `bash -c "<command>"`       | Runs the command, prints the output and exits back to the Windows command prompt. <br/> <br/> Example:  **bash -c "ls"** |

<p>

| Command                     | Description                     |
|:----------------------------|:---------------------------|
| `lxrun`                     | The lxrun command is used to manage the WSL instance. |
| `lxrun /install`            | Starts the download and install process. <br/> **/y** may be added to bypass all prompts.  The confirmation prompt is automatically accepted and the default user is set to root.          |
| `lxrun /uninstall`          | Uninstalls and deletes the Ubuntu image.  By default this does not remove the user's Ubuntu home directory. <br/> **/y** may be added to automatically accept the confirmation prompt <br/>**/full** uninstalls and deletes the user's Ubuntu home directory         |
| `lxrun /setdefaultuser <userName>`     | Sets the default Bash on Ubuntu user. Will prompt for a password if the specified user does not exist.  For more information visit: http://aka.ms/wslusers. <br/> **/y** Bypasses promping for the password.  The user will be created without a password.|
| `lxrun /update`            | Updates the subsystem's package index          |
