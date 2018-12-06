---
title: Windows Subsystem for Linux Command Reference
description: List of commands that manage the Windows Subsystem for Linux
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu
author: scooley
ms.author: scooley
ms.date: 07/31/2017
ms.topic: article
ms.service: windows-subsystem-for-linux
ms.assetid: 82908295-a6bd-483c-a995-613674c2677e
ms.custom: seodec18
---

# Command Reference for Windows Subsystem for Linux

> `lxrun.exe` is deprecated as of Windows 10 1803 and later.

The command `lxrun.exe` can be used to interact with the [Windows Subsystem for Linux (WSL)](https://msdn.microsoft.com/en-us/commandline/wsl/faq#what-windows-subsystem-for-linux-wsl-) directly.  These commands are installed into the `\Windows\System32` directory and may be run within a Windows command prompt or in PowerShell.

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
| `lxrun /setdefaultuser <userName>`     | Sets the default Bash on Ubuntu user. Will prompt for a password if the specified user does not exist.  For more information visit: https://aka.ms/wslusers. <br/> **/y** Bypasses promping for the password.  The user will be created without a password.|
| `lxrun /update`            | Updates the subsystem's package index          |
