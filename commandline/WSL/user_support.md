---
title: Linux User Account and Permissions
description: Reference for user accounts and permission management with the Windows Subsystem for Linux.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, user accounts
author: scooley
ms.date: 9/11/2017
ms.topic: article
ms.prod: windows-subsystem-for-linux
ms.service: windows-subsystem-for-linux
ms.assetid: f70e685f-24c6-4908-9546-bf4f0291d8fd
---

# User Accounts and Permissions

When you install a Linux distribution on the Windows Subsystem for Linux, you probably created a Linux user account and password when Linux launched.  Here are some things you should know about your Linux user account(s) and how WSL handles users and permissions.

## Your first Linux user account
Each Linux distribution writes their own app installer so, while the experience may vary between distributions, all of them will ask you for a Linux username and password.

This initial Linux user account is:

1. Independent from your Windows user account.
1. Linux admin (sudo) by default.
1. Signed-in automatically for every WSL instance.
1. Unique to the WSL environment for your current Windows user.

## Resetting your Linux password
The best option is to reset your password from your Linux user account using the distribution's particular command (`passwd`, for example).

If that's not an option, however, you can recover your Linux account from Windows.

1. Open CMD.
1. Set the default Linux user to `root` using `lxrun /setdefaultuser`.  Run:  
    
    ``` CMD
    lxrun /setdefaultuser root
    ```
    
    Setting the default user to root does not require a password.

1. Run your Linux distribution.  You should automatically login as `root`.
1. Reset your password using the distribution's password management commands.  In Ubuntu, this would be:

    ``` BASH
    passwd username
    ```

1. Set your default user back to your normal Linux user.
    ``` CMD
    lxrun /setdefaultuser username
    ```

The default user `root` is valid for users who would like to run directly as root, or require root access for troubleshooting.  

## Permissions
There are two important concepts to keep in mind when it comes to permissions:

1. The Windows permission model, i.e. administrator
2. The Linux permission model, i.e. root access, sudoers

When Bash runs, it has the same permissions as the console.  This means if typing `bash` from a normal CMD or PowerShell prompt, it is given the same permissions as the logged-in Windows user.  Running `bash` from an “elevated” or “Administrator” command prompt then runs Bash with elevated permissions.

This is independent of the signed-in Linux user account.  Root privileges on the Linux side only impact the user’s rights within the Linux environment & filesystem; they have no impact on the Windows privileges granted.

**Example:**  
> A Bash session with Windows admin privileges may `cd /mnt/c/Users/Administrator` while a Bash session without admin privileges would see Permission Denied.
> Typing `sudo cd /mnt/c/Users/Administrator` will not grant access to the Administrator’s directory since the permissions are restricted by Windows.

The Linux permission model is important when inside the Ubuntu environment where the user has permissions based on the current Linux user.

**Example:**
> A user in the sudo group may run `sudo apt update`
