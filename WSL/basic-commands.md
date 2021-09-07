---
title: Basic commands for WSL
description: Reference for the basic commands included with Windows Subsystem for Linux (WSL).
keywords: wsl, install, BashOnWindows, bash, windows subsystem for linux, install ubuntu on windows, enable WSL2, linux on windows
ms.date: 08/25/2021
ms.topic: article
ms.localizationpriority: high
---

# Command reference for WSL

The basic WSL commands below are listed in a format supported by PowerShell or Windows Command Prompt. To run these commands from a Bash / Linux distribution command line, you must replace `wsl` with `wsl.exe`.

## Basic commands

The following basic commands are supported after [installing WSL](./install-command.md).

### Install

```powershell
wsl --install
```

Install WSL and the Ubuntu distribution of Linux. [Learn more](./install-command.md).

### Install a specific Linux distribution

```powershell
wsl --install --distribution <Distribution Name>
```

Designate a distribution of Linux for installation besides the default (Ubuntu) by replacing `<Distribution Name>` with the name of the distribution. This command can also be entered as: `wsl -d <Distribution Name>`.

### List available Linux distributions

```powershell
wsl --list --online
```

See a list of the Linux distributions available through the online store. This command can also be entered as: `wsl -l -o`.

### List install Linux distributions

```powershell
wsl --list --verbose
```

See a list of the Linux distributions installed on your Windows machine, including the state (whether the distribution is running or stopped) and the version of WSL running the distribution (WSL 1 or WSL 2). [Comparing WSL 1 and WSL 2](./compare-versions.md). This command can also be entered as: `wsl -l -v`. Additional options that can be used with the list command include: `--all` to list all distributions, `--running` to list only distributions that are currently running, or `--quite` to only show distribution names.

### Set WSL version to 1 or 2

```powershell
wsl --set-version <distribution name> <versionNumber>
```

To designate the version of WSL (1 or 2) that a Linux distribution is running on, replace `<distribution name>` with the name of the distribution and replace `<versionNumber>` with 1 or 2. [Comparing WSL 1 and WSL 2](./compare-versions.md).

### Set default WSL version

```powershell
wsl --set-default-version <Version>
```

To set a default version of WSL 1 or WSL 2, replacing `<Version>` with either the number 1 or 2 to represent which version of WSL you would like the installation to default on for new Linux distribution installations. For example, `wsl --set-default-version 2`. [Comparing WSL 1 and WSL 2](./compare-versions.md).

### Set default Linux distribution

```powershell
wsl --set-default <Distribution Name>
```

To set the default Linux distribution that WSL commands will use to run, replace `<Distribution Name>` with the name of your preferred Linux distribution.

### Run a specific Linux distribution from PowerShell or CMD

```powershell
wsl --distribution <Distribution Name> --user <User Name>
```

To run a specific Linux distribution with a specific user, replace `<Distribution Name>` with the name of your preferred Linux distribution (ie. Debian) and `<User Name>` with the name of an existing user (ie. root). If the user doesn't exist in the WSL distribution, you will receive an error. To print the current user name, use the command `whoami`.

### Update WSL

```powershell
wsl --update
```

Manually update the version of your WSL Linux kernel. You can also use the command: `wsl --update rollback` to rollback to a previous version of the WSL Linux kernel.

## Check WSL status

```powershell
wsl --status
```

See general information about your WSL configuration, such as default distribution type, default distribution, and kernel version.

```powershell
wsl --help
```

See a list of options and commands available with WSL.

```powershell
wsl --shutdown
```

Immediately terminates all running distributions and the WSL 2 lightweight utility virtual machine. This command may be necessary in instances that require you to restart the WSL 2 virtual machine environment, such as [changing memory usage limits](./vhd-size.md) or making a change to your [.wslconfig file](./manage.md#).

### Terminate a WSL distribution

```powershell
wsl --terminate <Distribution Name>
```

To terminate the specified distribution, or stop it from running, replace `<Distribution Name>` with the name of the targeted distribution.

### Export a distribution to a TAR file

```powershell
wsl --export <Distribution Name> <FileName>
```

Exports the distribution to a tar file. The filename can be - for standard output.

### Import a new distribution

```powershell
wsl --import <Distribution Name> <InstallLocation> <FileName>
```

Imports the specified tar file as a new distribution. The filename can be - for standard input. The `--version` option can also be used with this command to designate whether the imported distribution will run on WSL 1 or WSL 2.

### Unregister or uninstall a Linux distribution

```powershell
wsl --unregister <Distribution Name>
```

Unregister or uninstall the specific distribution by replacing `<Distribution Name>` with the name of the targeted distribution. This will remove the distribution from WSL and delete all of the associated data. You can also uninstall the Linux distribution app on your Windows machine just like any other store application.

### Mount a disk or device

```powershell
wsl --mount <DiskPath>
```

Attach and mount a physical disk in all WSL2 distributions by replacing `<DiskPath>` with the directory\file path where the disk is located. See [Mount a Linux disk in WSL 2](./wsl2-mount-disk.md). Options include:

- `wsl --mount --bare`: Attach the disk to WSL2, but don't mount it.
- `wsl --mount --type <Filesystem>`:  Filesystem type to use when mounting a disk, if not specified defaults to ext4. This command can also be entered as: `wsl --mount -t <Filesystem>`.You can detect the filesystem type using the command: `blkid <BlockDevice>`, for example: `blkid <dev/sdb1>`.
- `wsl --mount --partition <Partition Number>`: Index number of the partition to mount, if not specified defaults to the whole disk.
- `wsl --mount --options <MountOptions>`: There are some filesystem-specific options that can be included when mounting a disk. For example, [ext4 mount options](https://www.kernel.org/doc/Documentation/filesystems/ext4.txt) like: `wsl --mount -o "data-ordered"` or `wsl --mount -o "data=writeback`. However, only filesystem-specific options are supported at this time. Generic options, such as `ro`, `rw`, or `noatime`, are not supported.
- `wsl --unmount <DiskPath>`: Unmount and detach the disk from all WSL 2 distributions. If the `<DiskPath>` is not included, this command will unmount and detach ALL mounted disks.

> [!NOTE]
> If you're running a 32-bit process in order to access wsl.exe (a 64-bit tool), you may need to run the command in the following manner: `C:\Windows\Sysnative\wsl.exe --command`.

## Deprecated WSL commands

```powershell
wslconfig.exe [Argument] [Options]
```

```powershell
bash [Options]
```

```powershell
lxrun /[Argument]
```

These commands were the original wsl syntax for configuring Linux distributions installed with WSL, but have been replaced with the `wsl` or `wsl.exe` command syntax.
