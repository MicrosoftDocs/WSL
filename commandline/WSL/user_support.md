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

Creating your Linux user is the first step in setting up a new Linux distribution on WSL.  The user account you create is automatically configured with a few special attributes:

1. It is your default user -- it signs-in automatically on launch.
1. It is a Linux superuser (sudo) by default.

Each Linux distribution running on the Windows Subsystem for Linux has its own Linux user accounts and passwords.  You will have to configure a Linux user account any time you add a distribution, reinstall, or reset.  Linux user accounts are not only independent per distribution, they are also independent from your Windows user account.

## Resetting your Linux password

If you have access to your Linux user account, know your password but want to change it, use the password reset command for that distribution -- most likely `passwd`.

If that's not an option, many distributions include commands for setting the default user to root.  Setting the default user to root does not require a password.  Once connected as root, you can reset your password.

To see what commands are available for a particular distribution, run `[distro.exe] /?`.
    
For example:

``` BASH
ubuntu /?
```

Step by step instructions using Ubuntu:

1. Open CMD.
1. Set the default Linux user to `root`.

    ``` CMD
    ubuntu config --default-user root
    ```    

1. Launch your Linux distribution (`ubuntu`).  You will automatically login as `root`.

1. Reset your password using the distribution's password command.

    ``` BASH
    passwd username
    ```

1. From Windows CMD, reset your default user back to your normal Linux user account.

    ``` CMD
    ubuntu config --default-user username
    ```

Setting the default user `root` can be useful.  It's great for users who would like to run directly as root or require root access for troubleshooting.

## Permissions

There are two important concepts to keep in mind when it comes to permissions in WSL:

1. The Windows permission model, i.e. administrator
2. The Linux permission model, i.e. root access, sudoers

When running Linux on WSL, Linux will have the same permissions as the console it is running in.  This means if you run WSL (or any distribution in WSL) from a normal CMD or PowerShell prompt, it is given the same permissions as the logged-in Windows user.  Running WSL from an "elevated" or "Administrator" command prompt runs with elevated permissions.

This is independent of the signed-in Linux user account.  Root privileges on the Linux side only impact the user’s rights within the Linux environment & filesystem; they have no impact on the Windows privileges granted.

**Example:**  
> A Bash session with Windows admin privileges may `cd /mnt/c/Users/Administrator` while a Bash session without admin privileges would see Permission Denied.
> Typing `sudo cd /mnt/c/Users/Administrator` will not grant access to the Administrator’s directory since the permissions are restricted by Windows.

The Linux permission model is important when inside the Ubuntu environment where the user has permissions based on the current Linux user.

**Example:**
> A user in the sudo group may run `sudo apt update`

## Resetting your password -- Creators Update and earlier

If you're running Windows 10 Creators update or earlier, you can change the default Bash user by running:

``` CMD
lxrun /setdefaultuser root
```