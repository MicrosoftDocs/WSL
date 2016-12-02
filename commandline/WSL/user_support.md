---
title: Bash on Ubuntu on Windows - Linux User Account and Permissions
description: Linux User Account and Permissions
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu
author: jackchammons
ms.date: 9/6/2016
ms.topic: article
ms.prod: windows-subsystem-for-linux
ms.service: windows-subsystem-for-linux
ms.assetid: f70e685f-24c6-4908-9546-bf4f0291d8fd
---

# Linux User Account and Permissions

Bash on Ubuntu on Windows will prompt to create a default Linux user on first run.  This user:

1. Does not need to have the same username as the Windows signed in user and is treated as a distinct entity from the Windows user account
2. Will be prompted for a new password
    * Password will be used for Linux commands such as `sudo` and not used by any system outside of WSL
3. Will be automatically added to the sudo group
4. Will be signed-in automatically for every Bash instance
5. Will not require a password when launching WSL

Each Windows user has a unique WSL instance.  This means all changes made within the WSL environment are unique to that Windows user.  This includes Bash users created with the `adduser` command.

Users may change their default Bash user with the `lxrun /setdefaultuser` command. Users who have a previous build may use lxrun to set their default user without having to uninstall.  The default user ‘root’ is valid for users who would like to run directly as root, or require root access for troubleshooting.  Setting the default user to ‘root’ does not require a password.

## Permissions
There are two important concepts to keep in mind when it comes to permissions:

1. The Windows permission model, i.e. administrator
2. The Linux permission model, i.e. root access

When Bash runs, it has the same permissions as the console.  This means if typing `bash` from a normal CMD or PowerShell prompt, it is given the same permissions as the logged-in Windows user.  Running `bash` from an “elevated” or “Administrator” command prompt then runs Bash with elevated permissions.

This is independent of the signed-in Linux user account.  Root privileges on the Linux side only impact the user’s rights within the Linux environment & filesystem; they have no impact on the Windows privileges granted.

**Example:**  
> A Bash session with Windows admin privileges may `cd /mnt/c/Users/Administrator` while a Bash session without admin privileges would see Permission Denied.
> Typing `sudo cd /mnt/c/Users/Administrator` will not grant access to the Administrator’s directory since the permissions are restricted by Windows.

The Linux permission model is important when inside the Ubuntu environment where the user has permissions based on the current Linux user.

**Example:**
> A user in the sudo group may run `sudo apt update`
