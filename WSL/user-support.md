---
title: Create and update user accounts for Linux distributions
description: Reference for user accounts and permission management with the Windows Subsystem for Linux.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, user accounts
ms.date: 05/12/2020
ms.topic: article
ms.localizationpriority: high
---

# Create a user account and password for your new Linux distribution

Once you have [enabled WSL and installed a Linux distribution from the Microsoft Store](./install-win10.md), the first step you will be asked to complete when opening your newly installed Linux distribution is to create an account, including a **User Name** and **Password**.

- This **User Name** and **Password** are specific to your Linux distribution and have no bearing on your Windows user name.

- Once you create this **User Name** and **Password**, the account will be your default user for the distribution and automatically sign-in on launch.

- This account will be considered the Linux administrator, with the ability to run `sudo` (Super User Do) administrative commands.

- Each Linux distribution running on the Windows Subsystem for Linux has its own Linux user accounts and passwords.  You will have to configure a Linux user account every time you add a distribution, reinstall, or reset.

![Ubuntu unpacking in the Windows console](media/UbuntuInstall.png)

## Update and upgrade packages

Most distributions ship with an empty or minimal package catalog. We strongly recommend regularly updating your package catalog and upgrading your installed packages using your distribution's preferred package manager. For Debian/Ubuntu, use apt:

```bash
sudo apt update && sudo apt upgrade
```

Windows does not automatically update or upgrade your Linux distribution(s). This is a task that most Linux users prefer to control themselves.

## Reset your Linux password

To change your password, open your Linux distribution (Ubuntu for example) and enter the command: `passwd`

You will be asked to enter your current password, then asked to enter your new password, and then to confirm your new password.

## Forgot your password

If you forgot the password for your Linux distribution:

1. Open PowerShell and enter the root of your default WSL distribution using the command: `wsl -u root`

    > If you need to update the forgotten password on a distribution that is not your default, use the command: `wsl -d Debian -u root`, replacing `Debian` with the name of your targeted distribution.

2. Once your WSL distribution has been opened at the root level inside PowerShell, you can use this command to update your password: `passwd`

3. You will be prompted to enter a new UNIX password and then confirm that password. Once you're told that the password has updated successfully, close WSL inside of PowerShell using the command: `exit`

> [!NOTE]
> If you are running an early version of Windows operating system, like 1703 (Creators Update) or 1709 (Fall Creators Update), see the [archived version of this user account update doc](./user-support-archived.md).
