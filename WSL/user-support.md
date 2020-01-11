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

- This account will be considered the Linux administrator, with the ability to run `sudu` (Super User Do) administrative commands.

- Each Linux distribution running on the Windows Subsystem for Linux has its own Linux user accounts and passwords.  You will have to configure a Linux user account every time you add a distribution, reinstall, or reset.

## Reset your Linux password

To change your password, open your Linux distribution (Ubuntu for example) and enter the command: `passwd`

You will be asked to enter your current password, then asked to enter your new password, and then to confirm your new password.

### Forgot your password

If you forgot the password for your Linux distribution, try this: 

For Ubuntu:
1. Open PowerShell and use it to change the default user name of your Ubuntu distribution to root with: `ubuntu config --default-user root`

2. Open your distribution (Ubuntu) and you should see that the prompt now lists `root@computername` rather than the user name you entered. Enter the command: `passwd <username>` (replacing the username you created for your account and forgot the password for).

3. You will be prompted to enter a new UNIX password and then confirm that password. Once you're told that the password has updated successfully, close the Linux distribution (Ubuntu).

4. Open PowerShell and use it to change the default user name of your Ubuntu distribution back to your username with: `ubuntu config --default-user <your username>`

5. Now re-open your Ubuntu distribution and you should see your username displayed as the prompt, rather than `root`. Now you can confirm that your password was correctly updated.

For other Linux distributions, follow the same instructions, but in Powershell, change the command to align with the correct distribution name:

- openSUSE Leap 42: `openSUSE-42 config --default-user root`
- SUSE Linux: `SLES-12 config --default-user root`
- Debian: `debian config --default-user root`
- Kali Linux: `kali config --default-user root`

> [!NOTE]
> If you are running an early version of Windows operating system, like 1703 (Creators Update) or 1709 (Fall Creators Update), see the [archived version of this user account update doc](../user-support-archived.md).
