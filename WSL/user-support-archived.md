---
title: WSL User Account updates on Previous Windows Versions 
description: Reference for Previous Windows Versions to update Linux user accounts with the Windows Subsystem for Linux.
ms.date: 01/20/2020
ms.topic: article
ROBOTS: NOINDEX
---

# WSL User Account updates on Previous Windows Versions

This content is archived for users of earlier versions of Windows operating system that support the subsystem for Linux and need support with updating Linux user accounts.

For current documentation, see [User Accounts for Windows Subsystem for Linux](../user-support.md).

### For Creators Update version of Windows and earlier

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
