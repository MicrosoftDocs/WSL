---
title: Basic commands for WSL
description: Reference for the basic commands included with Windows Subsystem for Linux (WSL).
ms.date: 12/01/2025
ms.topic: article
---

# Basic commands for WSL

The WSL commands below are listed in a format supported by PowerShell or Windows Command Prompt. To run these commands from a Bash / Linux distribution command line, you must replace `wsl` with `wsl.exe`. For a full list of commands, run `wsl --help`. If you have not yet done so, we recommend [updating to the version of WSL installed from Microsoft Store](https://apps.microsoft.com/detail/9P9TQF7MRM4R) in order to receive WSL updates as soon as they are available. ([Learn more about installing WSL via Microsoft Store.](https://devblogs.microsoft.com/commandline/the-windows-subsystem-for-linux-in-the-microsoft-store-is-now-generally-available-on-windows-10-and-11/)).

## Install

```powershell
wsl --install
```

Install WSL and the default Ubuntu distribution of Linux. [Learn more](./install.md). You can also use this command to install additional Linux distributions by running `wsl --install <Distribution Name>`. For a valid list of distribution names, run `wsl --list --online`.

Options include:

- `--distribution`: Specify the Linux distribution to install. You can find available distributions by running `wsl --list --online`.
- `--no-launch`: Install the Linux distribution but do not launch it automatically.
- `--web-download`: Install from an online source rather than using the Microsoft Store.
- `--location`: Specify which folder you would like to install the WSL distribution to.

When WSL is not installed options include:

- `--inbox`: Installs WSL using the Windows component instead of using the Microsoft Store. *(WSL updates will be received via Windows updates, rather than pushed out as-available via the store).*
- `--enable-wsl1`: Enables WSL 1 during the install of the Microsoft Store version of WSL by also enabling the "Windows Subsystem for Linux" optional component.
- `--no-distribution`: Do not install a distribution when installing WSL.

> [!NOTE]
> If you run WSL on Windows 10 or an older version, you may need to include the `-d` flag with the `--install` command to specify a distribution: `wsl --install -d <distribution name>`.

## List available Linux distributions

```powershell
wsl --list --online
```

See a list of the Linux distributions available through the online store. This command can also be entered as: `wsl -l -o`.

## List installed Linux distributions

```powershell
wsl --list --verbose
```

See a list of the Linux distributions installed on your Windows machine, including the state (whether the distribution is running or stopped) and the version of WSL running the distribution (WSL 1 or WSL 2). [Comparing WSL 1 and WSL 2](./compare-versions.md). This command can also be entered as: `wsl -l -v`. Additional options that can be used with the list command include: `--all` to list all distributions, `--running` to list only distributions that are currently running, or `--quiet` to only show distribution names.

## Set WSL version to 1 or 2

```powershell
wsl --set-version <distribution name> <versionNumber>
```

To designate the version of WSL (1 or 2) that a Linux distribution is running on, replace `<distribution name>` with the name of the distribution and replace `<versionNumber>` with 1 or 2. [Comparing WSL 1 and WSL 2](./compare-versions.md). WSL 2 is only available in Windows 11 or Windows 10, Version 1903, Build 18362 or later.

> [!WARNING]
> Switching between WSL 1 and WSL 2 can be time-consuming and result in failures due to the differences between the two architectures. For distributions with large projects, we recommend backing up files before attempting a conversion.

## Set default WSL version

```powershell
wsl --set-default-version <Version>
```

To set a default version of WSL 1 or WSL 2, replace `<Version>` with either the number 1 or 2. For example, `wsl --set-default-version 2`. The number represents the version of WSL to default to for new Linux distribution installations. [Comparing WSL 1 and WSL 2](./compare-versions.md). WSL 2 is only available in Windows 11 or Windows 10, Version 1903, Build 18362 or later.

## Set default Linux distribution

```powershell
wsl --set-default <Distribution Name>
```

To set the default Linux distribution that WSL commands will use to run, replace `<Distribution Name>` with the name of your preferred Linux distribution.

## Start WSL in user home directory

```powershell
wsl ~
```

The `~` can be used with wsl to start in the user's home directory. To jump from any directory back to home from within a WSL command prompt, you can use the command: `cd ~`.

## Run a specific Linux distribution from PowerShell or CMD

```powershell
wsl --distribution <Distribution Name> --user <User Name>
```

To run a specific Linux distribution with a specific user, replace `<Distribution Name>` with the name of your preferred Linux distribution (ie. Debian) and `<User Name>` with the name of an existing user (ie. root). If the user doesn't exist in the WSL distribution, you will receive an error. To print the current user name, use the command `whoami`.

## Update WSL

```powershell
wsl --update
```

Update your WSL version to the latest version. Options include:

- `--web-download`: Download the latest update from the GitHub rather than the Microsoft Store.

## Check WSL status

```powershell
wsl --status
```

See general information about your WSL configuration, such as default distribution type, default distribution, and kernel version.

## Check WSL version

```powershell
wsl --version
```

Check the version information about WSL and its components.

## Help command

```powershell
wsl --help
```

See a list of options and commands available with WSL.

## Run as a specific user

```powershell
wsl --user <Username>
```

To run WSL as a specified user, replace `<Username>` with the name of a user that exists in the WSL distribution.

## Change the default user for a distribution

```powershell
<DistributionName> config --default-user <Username>
```

Change the default user for your distribution log-in. The user has to already exist inside the distribution in order to become the default user.

For example:
`ubuntu config --default-user johndoe` would change the default user for the Ubuntu distribution to the "johndoe" user.

> [!NOTE]
> If you are having trouble figuring out the name of your distribution, use the command `wsl -l`.

> [!WARNING]
> This command will not work for imported distributions, because these distributions do not have an executable launcher. You can instead change the default user for imported distributions using the `/etc/wsl.conf` file. See the Automount options in the [Advanced Settings Configuration](./wsl-config.md#user-settings) doc.

## Shutdown

```powershell
wsl --shutdown
```

Immediately terminates all running distributions and the WSL 2 lightweight utility virtual machine. This command may be necessary in instances that require you to restart the WSL 2 virtual machine environment, such as [changing memory usage limits](./disk-space.md) or making a change to your [.wslconfig file](./manage.md).

## Terminate

```powershell
wsl --terminate <Distribution Name>
```

To terminate the specified distribution, or stop it from running, replace `<Distribution Name>` with the name of the targeted distribution.

## Identify IP address

- `wsl hostname -I`: Returns the IP address of your Linux distribution installed via WSL 2 (the WSL 2 VM address)
- `ip route show | grep -i default | awk '{ print $3}'`: Returns the IP address of the Windows machine as seen from WSL 2 (the WSL 2 VM)

For a more detailed explanation, see [Accessing network applications with WSL: Identify IP Address](./networking.md#identify-ip-address).

## Export a distribution

```powershell
wsl --export <Distribution Name> <FileName>
```

Exports a snapshot of the specified distribution as a new distribution file. Defaults to tar format. The filename can be `-` for standard input. Options include:

- `--vhd`: Specifies the export distribution should be a .vhdx file instead of a tar file (this is only supported using WSL 2)

## Import a distribution

```powershell
wsl --import <Distribution Name> <InstallLocation> <FileName>
```

Imports the specified tar file as a new distribution. The filename can be `-` for standard input. Options include:

- `--vhd`: Specifies the import distribution should be a .vhdx file instead of a tar file (this is only supported using WSL 2)
- `--version <1/2>`: Specifies whether to import the distribution as a WSL 1 or WSL 2 distribution

## Import a distribution in place

```powershell
wsl --import-in-place <Distribution Name> <FileName>
```

Imports the specified .vhdx file as a new distribution. The virtual hard disk must be formatted in the ext4 filesystem type.

## Unregister or uninstall a Linux distribution

To unregister and uninstall a WSL distribution:

```powershell
wsl --unregister <DistributionName>
```

Replacing `<DistributionName>` with the name of your targeted Linux distribution will unregister that distribution from WSL so it can be reinstalled or cleaned up. **Caution:** Once unregistered, all data, settings, and software associated with that distribution will be permanently lost.  Reinstalling from the store will install a clean copy of the distribution. For example, `wsl --unregister Ubuntu` would remove Ubuntu from the distributions available in WSL.  Running `wsl --list` will reveal that it is no longer listed.

You can also uninstall the Linux distribution app on your Windows machine just like any other store application. To reinstall, find the distribution in the Microsoft Store and select "Launch".

## Mount a disk or device

```powershell
wsl --mount <DiskPath>
```

Attach and mount a physical disk in all WSL2 distributions by replacing `<DiskPath>` with the directory\file path where the disk is located. See [Mount a Linux disk in WSL 2](./wsl2-mount-disk.md). Options include:

- `--vhd`: Specifies that `<Disk>` refers to a virtual hard disk.
- `--name`: Mount the disk using a custom name for the mountpoint
- `--bare`: Attach the disk to WSL2, but don't mount it.
- `--type <Filesystem>`:  Filesystem type to use when mounting a disk, if not specified defaults to ext4. This command can also be entered as: `wsl --mount -t <Filesystem>`.You can detect the filesystem type using the command: `blkid <BlockDevice>`, for example: `blkid <dev/sdb1>`.
- `--partition <Partition Number>`: Index number of the partition to mount, if not specified defaults to the whole disk.
- `--options <MountOptions>`: There are some filesystem-specific options that can be included when mounting a disk. For example, [ext4 mount options](https://www.kernel.org/doc/Documentation/filesystems/ext4.txt) like: `wsl --mount -o "data-ordered"` or `wsl --mount -o "data=writeback`. However, only filesystem-specific options are supported at this time. Generic options, such as `ro`, `rw`, or `noatime`, are not supported.

> [!NOTE]
> If you're running a 32-bit process in order to access wsl.exe (a 64-bit tool), you may need to run the command in the following manner: `C:\Windows\Sysnative\wsl.exe --command`.

## Unmount disks

```powershell
wsl --unmount <DiskPath>
```

Unmount a disk given at the disk path, if no disk path is given then this command will unmount and detach ALL mounted disks.

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
