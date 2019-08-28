---
title: Linux User Account and Permissions
description: Reference for user accounts and permission management with the Windows Subsystem for Linux.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, user accounts
author: scooley
ms.author: scooley
ms.date: 09/11/2017
ms.topic: article
ms.assetid: f70e685f-24c6-4908-9546-bf4f0291d8fd
ms.custom: seodec18
ms.localizationpriority: high
---

# User Accounts and Permissions for Windows Subsystem for Linux

Creating your Linux user is the first step in setting up a new Linux distribution on WSL.  The first user account you create is automatically configured with a few special attributes:

1. It is your default user -- it signs-in automatically on launch.
1. It is Linux administrator (a member of the sudo group) by default.

Each Linux distribution running on the Windows Subsystem for Linux has its own Linux user accounts and passwords.  You will have to configure a Linux user account any time you add a distribution, reinstall, or reset.  Linux user accounts are not only independent per distribution, they are also independent from your Windows user account.

## Resetting your Linux password

If you have access to your Linux user account and know your current password, change it using Linux password reset tools of that distribution -- most likely `passwd`.

If that's not an option, depending on the distribution, you may be able to reset your password by resetting the default user.

WSL offers a default user tag to identify which user account automatically logs in when you start a WSL.  Since many distributions include commands to set the default user to root and also a root user with no password set, changing the default user to root is a handy tool for things like password reset.

### For Creators Update and earlier
If you're running Windows 10 Creators update or earlier, you can change the default Bash user by running the following commands:

1. Change the default user to `root`:

    ```console
    C:\> lxrun /setdefaultuser root
    ```

1. Run `bash.exe` to now login as `root`:

    ```console
    C:\> bash.exe
    ```

1. Reset your password using the distribution's password command, and close the Linux Console:

    ```BASH
    $ passwd username
    $ exit
    ```

1. From Windows CMD, reset your default user back to your normal Linux user account:

    ```console
    C:\> lxrun.exe /setdefaultuser username
    ```

### For Fall Creators Update and later
To see what commands are available for a particular distribution, run `[distro.exe] /?`.
    
For example, with Ubuntu installed:

```console
C:\> ubuntu.exe /?

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

1. Open CMD
1. Set the default Linux user to `root`:

    ```console
    C:\> ubuntu config --default-user root
    ```    

1. Launch your Linux distribution (`ubuntu`).  You will automatically login as `root`:

1. Reset your password using the `passwd` command:

    ```BASH
    $ passwd username
    ```

1. From Windows CMD, reset your default user back to your normal Linux user account.

    ```console
    C:\> ubuntu config --default-user username
    ```

## Permissions

There are two important concepts to keep in mind when it comes to permissions in WSL:

1. The Windows permission model governs a process' rights to Windows resources
2. The Linux permission model controls a process' rights to Linux resources

When running Linux on WSL, Linux will have the same Windows permissions as the process that launches it. Linux can be launched in one of two permission levels:

* Normal (non-elevated): Linux runs with the permissions of the logged-in user
* Elevated/admin: Linux runs with elevated/admin Windows permissions

> Because elevated processes can access/modify (and therefore damage) system-wide settings and system-wide/protected data, **AVOID** launching elevated processes unless you absolutely have to - whether they're Windows or Linux applications/tools/shells!

The above Windows permissions are independent of the permissions within a Linux instance: Linux "Root privileges" only impact the user’s rights within the Linux environment & filesystem; they have no impact on the Windows privileges granted. Thus, running a Linux process as root (e.g. via `sudo`) only grants that process admin rights within the Linux environment.

**Example:**    
A Bash session with Windows admin privileges may access `cd /mnt/c/Users/Administrator` while a Bash session without admin privileges would see a "Permission Denied" error.

In Linux, typing `sudo cd /mnt/c/Users/Administrator` will not grant access to the Administrator’s directory since permissions within Windows are managed by Windows.

The Linux permission model is important when inside the Linux environment where the user has permissions based on the current Linux user.

**Example:**  
A user in the sudo group may run `sudo apt update`.
