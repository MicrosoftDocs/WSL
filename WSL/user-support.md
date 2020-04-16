---
title: Create and update user accounts for WSL distributions
description: Reference for user accounts and permission management with the Windows Subsystem for Linux.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, user accounts
ms.date: 01/20/2020
ms.topic: article
ms.assetid: f70e685f-24c6-4908-9546-bf4f0291d8fd
ms.custom: seodec18
ms.localizationpriority: high
---

# Create and update user accounts for WSL distributions

Once you have enabled WSL and installed a Linux distribution from the Microsoft Store, the first step you will be asked to complete when opening your newly installed Linux distribution is to create an account, including a **User Name** and **Password**.

- This **User Name** and **Password** is specific to your Linux distribution and has no bearing on your Windows user name.

- Once you create this **User Name** and **Password**, the account will be your default user for the distribution and automatically sign-in on launch.

- This account will be considered the Linux administrator, with the ability to run `sudo` (Super User Do) administrative commands.

- Each Linux distribution running on the Windows Subsystem for Linux has its own Linux user accounts and passwords.  You will have to configure a Linux user account every time you add a distribution, reinstall, or reset.

## Reset your Linux password

To change your password, open your Linux distribution (Ubuntu for example) and enter the command: `passwd`

You will be asked to enter your current password, then asked to enter your new password, and then to confirm your new password.

### Forgot your password

If you forgot the password for your Linux distribution:

<!-- This is a test of tab selectors. -->

# [PowerShell](#tab/powershell)

Open PowerShell and enter the root of your default WSL distribution using the command: `wsl -u root`

# [Linux distro](#tab/linux)

Open Ubuntu (or any WSL distro) and enter the command: `cd ~`

# [Win Command Prompt](#tab/windows)

Open the Windows Command Prompt and enter the command: `cd \`

---

<!-- Remove this tab selector section after testing.  -->

1. Open PowerShell and enter the root of your default WSL distribution using the command: `wsl -u root`

> If you need to update the forgotten password on a distribution that is not your default, use the command: `wsl -d Debian -u root`, replacing `Debian` with the name of your targeted distribution.

2. Once your WSL distribution has been opened at the root level inside PowerShell, you can use this command to update your password: `passwd`

3. You will be prompted to enter a new UNIX password and then confirm that password. Once you're told that the password has updated successfully, close WSL inside of PowerShell using the command: `exit`

> [!NOTE]
> If you are running an early version of Windows operating system, like 1703 (Creators Update) or 1709 (Fall Creators Update), see the [archived version of this user account update doc](./user-support-archived.md).
