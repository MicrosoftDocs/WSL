---
title: Install WSL
description: Install Windows Subsystem for Linux with the command, wsl --install. Use a Bash terminal on your Windows machine run by your preferred Linux distribution - Ubuntu, Debian, SUSE, Kali, Fedora, Pengwin, Alpine, and more are available.
keywords: wsl, install, BashOnWindows, bash, windows subsystem for linux, install ubuntu on windows, enable WSL2, linux on windows
ms.date: 09/10/2021
ms.topic: article
ms.localizationpriority: high
---

# Install WSL

You can now install everything you need to run Windows Subsystem for Linux (WSL) by entering this command in PowerShell or Windows Command Prompt and then restarting your machine.

```powershell
wsl --install
```

> [!IMPORTANT]
> The `wsl --install` command is only supported on Windows 10 version 2004 and higher (Build 19041 and higher) or Windows 11. If you're running an older build, or just prefer not to use the install command and would like step-by-step directions, see **[WSL manual installation steps for older versions](./install-manual.md)**.
>
> To check your Windows version and build number, select **Windows logo key + R**, type **winver**, select **OK**. You can [update to the latest Windows version](ms-settings:windowsupdate) in the Settings menu or using the [Windows Update Assistant](https://www.microsoft.com/software-download/windows10).


## Understanding the install command

The `wsl --install` command performs the following actions:

- Enables WSL and Virtual Machine Platform components
- Downloads and installs the latest Linux kernel
- Sets WSL 2 as the default
- Downloads and installs a Linux distribution *(Ubuntu by default, see below to change this)*

The install command does not automatically restart your machine, but may prompt you to do so.

The first time you launch a newly installed Linux distribution, a console window will open and you'll be asked to wait for files to de-compress and be stored on your PC. All future launches should take less than a second.

**CONGRATULATIONS! You've successfully installed and set up a Linux distribution that is completely integrated with your Windows operating system!**

## Change the default Linux distribution installed

By default, the installed Linux distribution will be Ubuntu. This can be changed using the `-d` flag.

- To change the distribution installed, enter: `wsl --install -d <Distribution Name>`. Replace `<Distribution Name>` with the name of the distribution you would like to install.
- To see a list of available Linux distributions available for download through the online store, enter: `wsl --list --online` or `wsl -l -o`.
- To install additional Linux distributions after the initial install, you may also use the command: `wsl --install -d <Distribution Name>`.

> [!TIP]
> If you want to install additional distributions from inside a Linux/Bash command line (rather than from PowerShell or Command Prompt), you must use .exe in the command: `wsl.exe --install -d <Distribution Name>` or to list available distributions: `wsl.exe -l -o`.

If you run into an issue during the install process, check the [installation section of the troubleshooting guide](./troubleshooting.md#installation-issues).

## Create a user account and password for your new Linux distribution

Once you have installed WSL, the first step you will be asked to complete when opening your newly installed Linux distribution is to create an account, including a **User Name** and **Password**.

- This **User Name** and **Password** is specific to each separate Linux distribution that you install and has no bearing on your Windows user name.

- Once you create a **User Name** and **Password**, the account will be your default user for the distribution and automatically sign-in on launch.

- This account will be considered the Linux administrator, with the ability to run `sudo` (Super User Do) administrative commands.

- Each Linux distribution running on WSL has its own Linux user accounts and passwords.  You will have to configure a Linux user account every time you add a distribution, reinstall, or reset.

![Ubuntu unpacking in the Windows console](media/UbuntuInstall.png)

> [!NOTE]
> Linux distributions installed with WSL are a per-user installation and can't be shared with other Windows user accounts.

## Update and upgrade packages

Most Linux distributions ship with an empty or minimal package catalog. We strongly recommend regularly updating your package catalog and upgrading your installed packages using the preferred package manager for the distribution. For Ubuntu or Debian, use apt:

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

2. Once your WSL distribution has been opened at the root level inside PowerShell, you can use this command to update your password: `passwd <WSLUsername>` where `<WSLUsername>` is the username of the account in the DISTRO whose password you've forgotten.

3. You will be prompted to enter a new UNIX password and then confirm that password. Once you're told that the password has updated successfully, close WSL inside of PowerShell using the command: `exit`

> [!NOTE]
> If you are running an early version of Windows operating system, like 1703 (Creators Update) or 1709 (Fall Creators Update), see the [Using older version of Windows and WSL](./troubleshooting.md#using-older-versions-of-windows-and-wsl) in the Troubleshooting guide.

## Want to try the latest WSL preview features?

Try the most recent features or updates to WSL by joining the [Windows Insiders Program](https://insider.windows.com/getting-started). Once you have joined Windows Insiders, you can choose the channel you would like to receive preview builds from inside the Windows settings menu to automatically receive any WSL updates or preview features associated with that build. You can choose from:

- Dev channel: Most recent updates, but low stability.
- Beta channel: Ideal for early adopters, more reliable builds than the Dev channel.
- Release Preview channel: Preview fixes and key features on the next version of Windows just before its available to the general public.

## Install Windows Terminal (optional)

Using Windows Terminal enables you to open multiple tabs or window panes to display and quickly switch between multiple Linux distributions or other command lines (PowerShell, Command Prompt, PowerShell, Azure CLI, etc). You can fully customize your terminal with unique color schemes, font styles, sizes, background images, and custom keyboard shortcuts. [Learn more.](/windows/terminal)

[Install Windows Terminal](/windows/terminal/get-started).

![Windows Terminal](media/terminal.png)

## Additional resources

- [Windows Command Line Blog: Install WSL with a single command now available in Windows 10 version 2004 and higher](https://devblogs.microsoft.com/commandline/install-wsl-with-a-single-command-now-available-in-windows-10-version-2004-and-higher/)
