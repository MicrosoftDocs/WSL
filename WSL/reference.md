---
title: Windows Subsystem for Linux Command Reference
description: See a list of commands that manage the Windows Subsystem for Linux, such as arguments for running Linux commands.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu
ms.date: 09/15/2020
ms.topic: article
ms.localizationpriority: high
---


# Command Reference for Windows Subsystem for Linux

The best way to interact with the Windows Subsystem for Linux is to use the `wsl.exe` command.

## Set WSL 2 as your default version

Run the following command in Powershell to set WSL 2 as the default version when installing a new Linux distribution:

```powershell
wsl --set-default-version 2
```

## Set your distribution version to WSL 1 or WSL 2

You can check the WSL version assigned to each of the Linux distributions you have installed by opening the PowerShell command line and entering the command (only available in [Windows Build 19041 or higher](ms-settings:windowsupdate)): `wsl -l -v`

```bash
wsl --list --verbose
```

To set a distribution to be backed by either version of WSL please run:

```bash
wsl --set-version <distribution name> <versionNumber>
```

Make sure to replace `<distribution name>` with the actual name of your distribution and `<versionNumber>` with the number '1' or '2'. You can change back to WSL 1 at anytime by running the same command as above but replacing the '2' with a '1'.

Additionally, if you want to make WSL 2 your default architecture you can do so with this command:

```bash
wsl --set-default-version 2
```

This will set the version of any new distribution installed to WSL 2.

## `wsl.exe`

Below is a list containing all options when using `wsl.exe` as of Windows Version 1903.

Using: `wsl [Argument] [Options...] [CommandLine]`

### Arguments for running Linux commands

* **Without arguments**

  If no command line is provided, wsl.exe launches the default shell.

* **--exec, -e \<CommandLine>**
  
  Execute the specified command without using the default Linux shell.

* **--**
  
  Pass the remaining command line as is.

The above commands also accept the following options:

* **--distribution, -d \<Distro>**

  Run the specified distribution.

* **--user, -u \<UserName>**

  Run as the specified user.

### Arguments for managing Windows Subsystem for Linux

* **--export \<Distro> \<FileName>**
  
  Exports the distribution to a tar file. The filename can be - for standard output.

* **--import \<Distro> \<InstallLocation> \<FileName>**
  
  Imports the specified tar file as a new distribution. The filename can be - for standard input.

* **--list, -l [Options]**
  
  Lists distributions.

  Options:
  * **--all**

    List all distributions, including distributions that are currently being installed or uninstalled.

  * **--running**

    List only distributions that are currently running.

* **--set-default, -s \<Distro>**
  
  Sets the distribution as the default.

* **--terminate, -t \<Distro>**
  
  Terminates the specified distribution.

* **--unregister \<Distro>**
  
  Un-register the distribution.

* **--help**
  Display usage information.

## Additional Commands

There are also historic commands to interact with the Windows Subsystem for Linux. Their functionality is encompassed within `wsl.exe`, but they are still available for use.

### `wslconfig.exe`

This command lets you configure your WSL distribution. Below is a list of its options.

Using: `wslconfig [Argument] [Options...]`

#### Arguments

* **/l, /list [Options]**
  
  Lists registered distributions.
  
Options:

* **/all**
      Optionally list all distributions, including distributions that are currently being installed or uninstalled.

* **/running**
      List only distributions that are currently running.

* **/s, /setdefault \<Distro>** 
  Sets the distribution as the default.

* **/t, /terminate \<Distro>** 
  Terminates the distribution.

* **/u, /unregister \<Distro>**
  Un-registers the distribution.

* **/upgrade \<Distro>**
  Upgrades the distribution to the WslFs file system format.

### `bash.exe`

This command is used to start a bash shell. Below are the options you can use with this command.

Using: `bash [Options...]`

* **No Option given**
  
  Launches the Bash shell in the current directory. If the Bash shell is not installed automatically runs `lxrun /install`

* **~**
  
  `bash ~` launches the bash shell into the user's home directory.  Similar to running `cd ~`.

* **-c "\<command>"**
  
  Runs the command, prints the output and exits back to the Windows command prompt.

  Example:  `bash -c "ls"`.

## Deprecated Commands

The `lxrun.exe` was the first command used to install and manage the Windows Subsystem for Linux. It is deprecated as of Windows 10 1803 and later.

The command `lxrun.exe` can be used to interact with the Windows Subsystem for Linux (WSL) directly.  These commands are installed into the `\Windows\System32` directory and may be run within a Windows command prompt or in PowerShell.

| Command                     | Description                     |
|:----------------------------|:---------------------------|
| `lxrun`                     | The lxrun command is used to manage the WSL instance. |
| `lxrun /install`            | Starts the download and install process. <br/> **/y** may be added to bypass all prompts.  The confirmation prompt is automatically accepted and the default user is set to root.          |
| `lxrun /uninstall`          | Uninstalls and deletes the Ubuntu image.  By default this does not remove the user's Ubuntu home directory. <br/> **/y** may be added to automatically accept the confirmation prompt <br/>**/full** uninstalls and deletes the user's Ubuntu home directory         |
| `lxrun /setdefaultuser <userName>`     | Sets the default Bash on Ubuntu user. Will prompt for a password if the specified user does not exist.  For more information visit: https://aka.ms/wslusers. <br/> **/y** Bypasses promping for the password.  The user will be created without a password.|
| `lxrun /update`            | Updates the subsystem's package index          |
