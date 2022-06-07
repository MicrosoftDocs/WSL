---
title: Advanced settings configuration in WSL
description: A guide to the wsl.conf and .wslconfig files used for configuring settings when running multiple Linux distributions on Windows Subsystem for Linux.
ms.date: 12/02/2021
ms.topic: article
ms.custom: seo-windows-dev
adobe-target: true
---

# Advanced settings configuration in WSL

The [wsl.conf](#wslconf) and [.wslconfig](#wslconfig) files are used to configure advanced settings options, on a per-distribution basis (`wsl.conf`) and globally across all WSL 2 distributions (`.wslconfig`). This guide will cover each of the settings options, when to use each file type, where to store the file, sample settings files and tips.

## What is the difference between wsl.conf and .wslconfig?

You can configure the settings for your installed Linux distributions that will automatically be applied every time you launch WSL in two ways, by using:

- **[.wslconfig](#wslconfig)** to configure settings **globally** across all installed distributions running on WSL 2.
- **[wsl.conf](#wslconf)**  to configure settings **per-distribution** for Linux distros running on WSL 1 or WSL 2.

Both file types are used for configuring WSL settings, but the location where the file is stored, the scope of the configuration, and the version of WSL running your distribution all impact which file type to choose.

The version of WSL that you are running will impact the configuration settings. WSL 2 runs as a lightweight virtual machine (VM), so uses virtualization settings that allow you to control the amount of memory or processors used (which may be familiar if you use Hyper-V or VirtualBox).

## wsl.conf

- Stored in the `/etc` directory of the distribution as a unix file.
- Used to configure settings on a per-distribution basis. Settings configured in this file will only be applied to the specific Linux distribution that contains the directory where this file is stored.
- Can be used for distributions run by either version, WSL 1 or WSL 2.
- To get to the `/etc` directory for an installed distribution, use the distribution's command line with `cd /` to access the root directory, then `ls` to list files or `explorer.exe .` to view in Windows File Explorer. The directory path should look something like: `/etc/wsl.conf`.

## .wslconfig

- Stored in your `%UserProfile%` directory.
- Used to configure settings globally across all installed Linux distributions running as the WSL 2 version.
- Can be used **only for distributions run by WSL 2**. Distributions running as WSL 1 will not be affected by this configuration as they are not running as a virtual machine.
- To get to your `%UserProfile%` directory, in PowerShell, use `cd ~` to access your home directory (which is typically your user profile, `C:\Users\<UserName>`) or you can open Windows File Explorer and enter `%UserProfile%` in the address bar. The directory path should look something like: `C:\Users\<UserName>\.wslconfig`.

WSL will detect the existence of these files, read the contents, and automatically apply the configuration settings every time you launch WSL. If the file is missing or malformed (improper markup formatting), WSL will continue to launch as normal without the configuration settings applied.

[Check which version of WSL you are running.](./install.md#check-which-version-of-wsl-you-are-running)

> [!NOTE]
> Adjusting per-distribution settings with the wsl.conf file is only available in Windows Build 17093 and later.

### The 8 second rule

You must wait until the subsystem running your Linux distribution completely stops running and restarts for configuration setting updates to appear. This typically takes about 8 seconds after closing ALL instances of the distribution shell.

If you launch a distribution (ie. Ubuntu), modify the configuration file, close the distribution, and then re-launch it. You might assume that your configuration changes have immediately gone into effect. This is not currently the case as the subsystem could still be running. You must wait for the subsystem to stop before relaunching in order to give enough time for your changes to be picked up. You can check to see whether your Linux distribution (shell) is still running after closing it by using PowerShell with the command: `wsl --list --running`. If no distributions are running, you will receive the response: "There are no running distributions." You can now restart the distribution to see your configuration updates applied.

The command `wsl --shutdown` is a fast path to restarting WSL 2 distributions, but it will shut down all running distributions, so use wisely.

## Configuration settings for wsl.conf

The wsl.conf file configures settings on a per-distribution basis. *(For global configuration of WSL 2 distributions see [.wslconfig](#wslconfig)).*

The wsl.conf file supports four sections: `automount`, `network`, `interop`, and `user`. *(Modeled after .ini file conventions, keys are declared under a section, like .gitconfig files.)* See [wsl.conf](#wslconf) for info on where to store the wsl.conf file.

### Automount settings

Section label: `[automount]`

| key | value | default | notes |
|:-----------|:---------|:--------|:------|
| enabled | boolean | true | `true` causes fixed drives (i.e `C:/` or `D:/`) to be automatically mounted with DrvFs under `/mnt`.  `false` means drives won't be mounted automatically, but you could still mount them manually or via `fstab`.                                                                                                             |
| mountFsTab | boolean | true | `true` sets `/etc/fstab` to be processed on WSL start. /etc/fstab is a file where you can declare other filesystems, like an SMB share. Thus, you can mount these filesystems automatically in WSL on start up.                                                                                                                |
| root| string | `/mnt/` | Sets the directory where fixed drives will be automatically mounted. By default this is set to `/mnt/`, so your Windows file system C-drive is mounted to `/mnt/c/`. If you change `/mnt/` to `/windir/`, you should expect to see your fixed C-drive mounted to `/windir/c`.|
| options | comma-separated list of values, such as uid, gid, etc, see automount options below | empty string | The automount option values are listed below and are appended to the default DrvFs mount options string. **Only DrvFs-specific options can be specified.**|

The automount options are applied as the mount options for all automatically mounted drives. To change the options for a specific drive only, use the `/etc/fstab` file instead. Options that the mount binary would normally parse into a flag are not supported. If you want to explicitly specify those options, you must include every drive for which you want to do so in `/etc/fstab`.

#### Automount options

Setting different mount options for Windows drives (DrvFs) can control how file permissions are calculated for Windows files. The following options are available:

| Key | Description | Default |
|:----|:----|:----|
|uid| The User ID used for the owner of all files | The default User ID of your WSL distro (on first installation this defaults to 1000)
|gid| The Group ID used for the owner of all files | The default group ID of your WSL distro (on first installation this defaults to 1000)
|umask | An octal mask of permissions to exclude for all files and directories | 000
|fmask | An octal mask of permissions to exclude for all files | 000
|dmask | An octal mask of permissions to exclude for all directories | 000
|metadata | Whether metadata is added to Windows files to support Linux system permissions | disabled
|case | Determines directories treated as case sensitive and whether new directories created with WSL will have the flag set. See [case sensitivity](./case-sensitivity.md) for a detailed explanation of the options. Options include `off`, `dir`, or `force`. | `off`

By default, WSL sets the uid and gid to the value of the default user. For example, in Ubuntu, the default user is uid=1000, gid=1000. If this value is used to specify a different gid or uid option, the default user value will be overwritten. Otherwise, the default value will always be appended.

User file-creation mode mask (umask) sets permission for newly created files. The default is 022, only you can write data but anyone can read data. Values can be changed to reflect different permission settings. For example, `umask=077` changes permission to be completely private, no other user can read or write data. To further specify permission, fmask (files) and dmask (directories) can also be used.

> [!NOTE]
> The permission masks are put through a logical OR operation before being applied to files or directories.

#### What is DrvFs?

DrvFs is a filesystem plugin to WSL that was designed to support interop between WSL and the Windows filesystem. DrvFs enables WSL to mount drives with supported file systems under /mnt, such as /mnt/c, /mnt/d, etc. For more information about specifying the default case sensitivity behavior when mounting Windows or Linux drives or directories, see the [case sensitivity](./case-sensitivity.md) page.

### Network settings

Section label: `[network]`

| key | value | default | notes|
|:----|:----|:----|:----|
| generateHosts | boolean | `true` | `true` sets WSL to generate `/etc/hosts`. The `hosts` file contains a static map of hostnames corresponding IP address. |
| generateResolvConf | boolean | `true` | `true` set WSL to generate `/etc/resolv.conf`. The `resolv.conf` contains a DNS list that are capable of resolving a given hostname to its IP address. |
| hostname | string | Windows hostname | Sets hostname to be used for WSL distribution. |

### Interop settings

Section label: `[interop]`

These options are available in Insider Build 17713 and later.

| key | value | default | notes|
|:----|:----|:----|:----|
| enabled | boolean | `true` | Setting this key will determine whether WSL will support launching Windows processes. |
| appendWindowsPath | boolean | `true` | Setting this key will determine whether WSL will add Windows path elements to the $PATH environment variable. |

### User settings

Section label: `[user]`

These options are available in Build 18980 and later.

| key | value | default | notes|
|:----|:----|:----|:----|
| default | string | The initial username created on first run | Setting this key specifies which user to run as when first starting a WSL session. |

### Boot settings

The Boot setting is only available on Windows 11.

Section label: `[boot]`

| key | value | default | notes|
|:----|:----|:----|:----|
| command | string | "" | A string of the command that you would like to run when the WSL instance starts. This command is run as the root user. e.g: `service docker start` Only available for Windows 11.|

<!-- ## Preview configuration options for wsl.conf

These options are only available in the latest preview builds if you are on the latest builds of the [Windows Insiders program](https://insider.windows.com/getting-started). -->

### Example wsl.conf file

The `wsl.conf` sample file below demonstrates some of the configuration options available. In this example, the distribution is Ubuntu-20.04 and the file path is `\\wsl.localhost\Ubuntu-20.04\etc\wsl.conf`.

```bash
# Automatically mount Windows drive when the distribution is launched
[automount]

# Set to true will automount fixed drives (C:/ or D:/) with DrvFs under the root directory set above. Set to false means drives won't be mounted automatically, but need to be mounted manually or with fstab.
enabled = true

# Sets the directory where fixed drives will be automatically mounted. This example changes the mount location, so your C-drive would be /c, rather than the default /mnt/c. 
root = /

# DrvFs-specific options can be specified.  
options = "metadata,uid=1003,gid=1003,umask=077,fmask=11,case=off"

# Sets the `/etc/fstab` file to be processed when a WSL distribution is launched.
mountFsTab = true

# Network host settings that enable the DNS server used by WSL 2. This example changes the hostname, sets generateHosts to false, preventing WSL from the default behavior of auto-generating /etc/hosts, and sets generateResolvConf to false, preventing WSL from auto-generating /etc/resolv.conf, so that you can create your own (ie. nameserver 1.1.1.1).
[network]
hostname = DemoHost
generateHosts = false
generateResolvConf = false

# Set whether WSL supports interop process like launching Windows apps and adding path variables. Setting these to false will block the launch of Windows processes and block adding $PATH environment variables.
[interop]
enabled = false
appendWindowsPath = false

# Set the user when launching a distribution with WSL.
[user]
default = DemoUser

# Set a command to run when a new WSL instance launches. This example starts the Docker container service.
[boot]
command = service docker start
```

## Configuration setting for .wslconfig

The .wslconfig file configures settings globally for all Linux distributions running with WSL 2. *(For per-distribution configuration see [wsl.conf](#wslconf)).*

See [.wslconfig](#wslconfig) for info on where to store the .wslconfig file.

> [!NOTE]
> Global configuration options with `.wslconfig` is only available for distributions running as WSL 2 in Windows Build 19041 and later. Keep in mind you may need to run `wsl --shutdown` to shut down the WSL 2 VM and then restart your WSL instance for these changes to take affect.

This file can contain the following options that affect the VM that powers any WSL 2 distribution:

Section label: `[wsl2]`

| key | value | default | notes|
|:----|:----|:----|:----|
| kernel | string | The Microsoft built kernel provided inbox | An absolute Windows path to a custom Linux kernel. |
| memory | size | 50% of total memory on Windows or 8GB, whichever is less; on builds before 20175: 80% of your total memory on Windows | How much memory to assign to the WSL 2 VM. |
| processors | number | The same number of processors on Windows | How many processors to assign to the WSL 2 VM. |
| localhostForwarding | boolean | `true` | Boolean specifying if ports bound to wildcard or localhost in the WSL 2 VM should be connectable from the host via `localhost:port`. |
| kernelCommandLine | string | Blank | Additional kernel command line arguments. |
| swap | size | 25% of memory size on Windows rounded up to the nearest GB | How much swap space to add to the WSL 2 VM, 0 for no swap file. Swap storage is disk-based RAM used when memory demand exceeds limit on hardware device. |
| swapFile | string | `%USERPROFILE%\AppData\Local\Temp\swap.vhdx` | An absolute Windows path to the swap virtual hard disk. |
| pageReporting | boolean | `true` | Default `true` setting enables Windows to reclaim unused memory allocated to WSL 2 virtual machine. |
| guiApplications | boolean* | `true` | Boolean to turn on or off support for GUI applications ([WSLg](https://github.com/microsoft/wslg)) in WSL. Only available for Windows 11.|
| debugConsole | boolean* | `false` | Boolean to turn on an output console Window that shows the contents of `dmesg` upon start of a WSL 2 distro instance. Only available for Windows 11.|
| nestedVirtualization | boolean* | `true` | Boolean to turn on or off nested virtualization, enabling other nested VMs to run inside WSL 2. Only available for Windows 11.|
| vmIdleTimeout | number* | `60000` | The number of milliseconds that a VM is idle, before it is shut down. Only available for Windows 11.|

Entries with the `path` value must be Windows paths with escaped backslashes, e.g: `C:\\Temp\\myCustomKernel`

Entries with the `size` value must be a size followed by a unit, for example `8GB` or `512MB`.

Entries with an * after the value type are only available on Windows 11.

<!-- ## Preview configuration options for .wslconfig

These options are only available in the latest preview builds if you are on the latest builds of the [Windows Insiders program](https://insider.windows.com/getting-started).

| key | value | default | notes|
|:----|:----|:----|:----| -->

## Example .wslconfig file

The `.wslconfig` sample file below demonstrates some of the configuration options available. In this example, the file path is `C:\Users\<UserName>\.wslconfig`.

```bash
# Settings apply across all Linux distros running on WSL 2
[wsl2]

# Limits VM memory to use no more than 4 GB, this can be set as whole numbers using GB or MB
memory=4GB 

# Sets the VM to use two virtual processors
processors=2

# Specify a custom Linux kernel to use with your installed distros. The default kernel used can be found at https://github.com/microsoft/WSL2-Linux-Kernel
kernel=C:\\temp\\myCustomKernel

# Sets additional kernel parameters, in this case enabling older Linux base images such as Centos 6
kernelCommandLine = vsyscall=emulate

# Sets amount of swap storage space to 8GB, default is 25% of available RAM
swap=8GB

# Sets swapfile path location, default is %USERPROFILE%\AppData\Local\Temp\swap.vhdx
swapfile=C:\\temp\\wsl-swap.vhdx

# Disable page reporting so WSL retains all allocated memory claimed from Windows and releases none back when free
pageReporting=false

# Turn off default connection to bind WSL 2 localhost to Windows localhost
localhostforwarding=true

# Disables nested virtualization
nestedVirtualization=false

# Turns on output console showing contents of dmesg when opening a WSL 2 distro for debugging
debugConsole=true
```

## Additional resources

- [Windows Command Line Blog: Automatically Configuring WSL](https://devblogs.microsoft.com/commandline/automatically-configuring-wsl/)
- [Windows Command Line Blog: Chmod/Chown, DrvFs, file metadata](https://devblogs.microsoft.com/commandline/chmod-chown-wsl-improvements/)
