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

Creating your Linux user is the first step in setting up a new Linux distribution on WSL.  The first user account you create is automatically configured with a few special attributes:

1. It is your default user -- it signs-in automatically on launch.
1. It is Linux administrator (a member of the sudo group) by default.

Each Linux distribution running on the Windows Subsystem for Linux has its own Linux user accounts and passwords.  You will have to configure a Linux user account any time you add a distribution, reinstall, or reset.  Linux user accounts are not only independent per distribution, they are also independent from your Windows user account.

## Resetting your Linux password

If you have access to your Linux user account and know your current password, change it using Linux password reset tools that distribution -- most likely `passwd`.

If that's not an option, depending on the distribution, you may be able to reset your password by resetting the default user.

WSL offers a default user tag to identify which user account automatically logs in when you start a WSL.  Since many distributions include commands to set the default user to root and also a root user with no password set, changing the default user to root is a handy tool for things like password reset.

To see what commands are available for a particular distribution, run `[distro.exe] /?`.
    
For example, running `ubuntu.exe /?` yields:

``` 
> ubuntu.exe /?

Launches or configures a linux distribution.

Usage:
    <no args>
      - Launches the distro's default behavior. By default, this launches your default shell.

    run <command line>
      - Run the given command line in that distro, using the default configuration.
      - Everything after `run ` is passed to the linux LaunchProcess cal

    config [setting [value]]
      - Configure certain settings for this distro.
      - Settings are any of the following (by default)
        - `--default-user <username>`: Set the default user for this distro to <username>

    clean
      - Uninstalls the distro. The appx remains on your machine. This can be
        useful for "factory resetting" your instance. This removes the linux
        filesystem from the disk, but not the app from your PC, so you don't
        need to redownload the entire tar.gz again.

    help
      - Print this usage message.
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


### For Creators Update and earlier

If you're running Windows 10 Creators update or earlier, you can change the default Bash user by running:

``` CMD
lxrun /setdefaultuser root
```

## Permissions

There are two important concepts to keep in mind when it comes to permissions in WSL:

1. The Windows permission model, i.e. administrator
2. The Linux permission model, i.e. root access, sudoers

When running Linux on WSL, Linux will have the same permissions as the console it is running in.  This means if you run WSL (or any distribution in WSL) from a normal CMD or PowerShell prompt, it is given the same permissions as the logged-in Windows user.  Running WSL from an "elevated" or "Administrator" command prompt runs with elevated permissions.

This is independent of the signed-in Linux user account.  Root privileges on the Linux side only impact the user’s rights within the Linux environment & filesystem; they have no impact on the Windows privileges granted.

**Example:**    
A Bash session with Windows admin privileges may `cd /mnt/c/Users/Administrator` while a Bash session without admin privileges would see Permission Denied.  
Typing `sudo cd /mnt/c/Users/Administrator` will not grant access to the Administrator’s directory since the permissions are restricted by Windows.

The Linux permission model is important when inside the Ubuntu environment where the user has permissions based on the current Linux user.

**Example:**  
A user in the sudo group may run `sudo apt update`.
