---
title: Build a Custom Linux Distro for WSL - Windows
description: Learn how to create a custom Linux distribution for Windows Subsystem for Linux.
ms.date: 02/05/2025
ms.topic: article
---

# Build a Custom Linux Distribution for WSL

This guide will walk through the steps to create and distribute a WSL distribution, which is a `.wsl` file.

WSL distributions have two parts:

1) A root filesystem (distributed as a tar file)
2) A manifest entry (which contains the distribution metadata)

This guide only applies to [WSL release 2.4.4]( https://github.com/microsoft/WSL/releases) and higher.

> [!NOTE]
> See [this repository](https://github.com/microsoft/WSL-DistroLauncher) for the previous appx based distribution packaging instructions.

## What are WSL root filesystem tar files?

WSL distributions are defined by a tar file with a `.wsl` file extension on Windows.

A TAR file (short for Tape Archive) is a type of archive file used to store multiple files together in a single file for easier distribution or backup. The TAR file contains the root file system of a Linux distribution (all the distribution files), as well as the WSL configuration files. WSL configuration files tell the WIndows operating system how to install and launch the distribution.

Once you have a Linux system that you'd like to make into a WSL distribution, follow the steps below to get started.

## Create WSL configuration files

There are two configuration files that the distribution should include:

1. `/etc/wsl-distribution.conf`: A file created by the distribution maintainer responsible for controlling how the Linux distribution should be configured when first launched with WSL.
2. `/etc/wsl.conf`: A file containing global system settings that are specific to the user and control how the distribution is launched. [Learn more about WSL configuration files.](./wsl-config.md).

### Add the WSL distribution configuration file

The distribution configuration file, `/etc/wsl-distribution.conf`, defines how the Linux distribution should be configured when first launched by the user. This file can be used to interactively create a user account, show a license agreement, etc.

Here is a sample `/etc/wsl-distribution.conf` file:

```bash
# /etc/wsl-distribution.conf

[oobe]
command = /etc/oobe.sh
defaultUid = 1000
defaultName = my-distro

[shortcut]
enabled = true
icon = /usr/lib/wsl/my-icon.ico

[windowsterminal]
enabled = true
ProfileTemplate = /usr/lib/wsl/terminal-profile.json
```

WSL distribution file configuration options:

| key | value | default | notes |
|:---|:---|:---|:---|
| `oobe.command` | string | None | OOBE stands for out of box experience. This command runs the first time the user opens an interactive shell in the distribution. If that command returns non zero, it is considered unsuccessful, and the user won't be able to open a shell.   |
| `oobe.defaultUid` | integer | None | The default UID that the distribution starts with. This is useful when the `oobe.command` script creates a new user. |
| `oobe.defaultName`| string | None | The default name that the distribution is registered under. This default name can be replaced with the command: `wsl.exe --install <distro> --name <name>` |
| `shortcut.icon` | string | The default WSL icon | The icon in the start menu shortcut for the distribution. Must be in `.ico` format with a maximum size of `10MB` |
| `shortcut.enabled` | boolean | true | Whether a start menu shortcut should be created when the distribution is installed. |
| `windowsterminal.profileTemplate` | string | None | The JSON template to generate a Windows Terminal profile for this distribution. |
| `windowsterminal.enabled` | boolean | true | Whether a terminal profile should be created when the distribution is installed. If `profileTemplate` is not set, a default profile will be generated. |
| `windowsterminal.profileTemplate` | string | Path to a terminal template file | The JSON template to generate a Windows Terminal profile for this distribution. |

You need to create an out of box experience (OOBE) first run experience for the distribution. Below is a sample bash script that you can use. This script assumes that `oobe.defaultUid` is set to `1000`:

```bash
#!/bin/bash

set -ue

DEFAULT_GROUPS='adm,cdrom,sudo,dip,plugdev'
DEFAULT_UID='1000'

echo 'Please create a default UNIX user account. The username does not need to match your Windows username.'
echo 'For more information visit: https://aka.ms/wslusers'

if getent passwd "$DEFAULT_UID" > /dev/null ; then
  echo 'User account already exists, skipping creation'
  exit 0
fi

while true; do

  # Prompt from the username
  read -p 'Enter new UNIX username: ' username

  # Create the user
  if /usr/sbin/adduser --uid "$DEFAULT_UID" --quiet --gecos ''  "$username"; then

    if /usr/sbin/usermod "$username" -aG "$DEFAULT_GROUPS"; then
      break
    else
      /usr/sbin/deluser "$username"
    fi
  fi
done
```

## Generate a Windows Terminal profile

WSL automatically generates a Windows Terminal profile when a distribution is installed. Distribution maintainers can customize the generated profile generated by setting `windowsterminal.profileTemplate` in the WSL configuration file, `/etc/wsl-distribution.conf`.

The json file follows [the terminal profile json format](/windows/terminal/json-fragment-extensions#structure-of-the-json-files).  Here’s an example profile:

```json
{
  "profiles": [
    {
      "antialiasingMode": "aliased",
      "fontWeight": "bold",
      "colorScheme": "Postmodern Tango Light"
    }
  ],
  "schemes": [
    {
      "name": "Postmodern Tango Light",
      "black": "#0C0C0C",
      "red": "#C50F1F",
      "green": "#13A10E",
      "yellow": "#C19C00",
      "blue": "#0037DA",
      "purple": "#881798",
      "cyan": "#3A96DD",
      "white": "#CCCCCC",
      "brightBlack": "#767676",
      "brightRed": "#E74856",
      "brightGreen": "#16C60C",
      "brightYellow": "#F9F1A5",
      "brightBlue": "#3B78FF",
      "brightPurple": "#B4009E",
      "brightCyan": "#61D6D6",
      "brightWhite": "#F2F2F2"
    }
  ]
}
```

This file doesn’t need to specify the profile `name`, or `commandLine`. Those are automatically added by WSL when generating the terminal profile.

### Add a WSL configuration for local settings on a per-distribution basis

In the context of a distribution root filesystem, we recommend that you configure systemd settings, including whether systemd starts by default, in the `/etc/wsl.conf` local settings on a per-distribution basis.  See the example below.

```bash
# /etc/wsl.conf

[boot]
systemd=true|false
```

The distribution author determines whether systemd is enabled by default by setting the `boot.systemd` value to `true` (enabled) or `false` (not enabled).

See the [Systemd recommendations](#systemd-recommendations) if you chose to enable systemd by default.

See [Advanced settings configuration in WSL](./wsl-config.md) for all supported settings in `/etc/wsl.conf`.

### Create the tar file

Once the distribution and configuration files are in place, the root filesystem can be captured in the tar file.

The recommended way of creating the tar file:

```bash
cd /path/to/rootfs
tar --numeric-owner --absolute-names -c  * | gzip --best > ../install.tar.gz
```

The root of the tar should be the root of the filesystem (not a directory containing the root filesystem).

The recommended compression format is gzip. Other compression formats run the risk of breaking compatibility with older WSL versions.

See the [Configuration file recommendations](#configuration-file-recommendations) for a list of files that should and shouldn't be included in the configuration.

To obtain a tar file of an existing Linux distribution, find guidance on how to export a docker container in [Import any Linux distribution to use with WSL](./use-custom-distro.md).

Once the tar file archive is ready, see [Test the distribution locally](#test-the-distribution-locally) to try it out locally.

## Create a .wsl file extension

The final step, once you have create a tar file to represent your custom Linux distribution, is to change the `.tar` file extension to a `.wsl` file extension by renaming it. Renaming this file extension will mark it as a WSL distribution. Once the tar has be renamed from `.tar` to `.wsl`, the file will install correctly on Windows when opened (double-clicked) in File Explorer. A `oobe.defaultName` entry is required in the `/etc/wsl-distribution.conf` file for this double-click experience to function properly.

## Distribute your WSL distribution

WSL users can view available distributions by running `wsl --list --online` and can install them directly with `wsl --install <distroName>` (replacing `<distroName>` with the actual name of the Linux distribution. This process is controlled by a distribution manifest file. You can add this manifest file to your customer Linux distribution for it to be included in the `wsl --install` command options.

The custom Linux distribution tar that you’ve created and renamed with a `.wsl` file extension can be distributed however you please. Once downloaded a user can install it directly from the command line with `wsl --install --from-file <fileLocation>` (replacing `<fileLocation>` with the actual location of the file). Alternatively, the `.wsl` file for your custom WSL distribution can be opened by double-clicking it.

## Distribution manifest details

The [distribution manifest](https://github.com/microsoft/WSL/blob/master/distributions/DistributionInfo.json) contains metadata about the distributions that are available for installation via `wsl --install <distribution>`.

Linux distributions that are tar-based are listed under `ModernDistribution`, with the below format:

```json
{
    "ModernDistributions": {
        "<flavor>": [
            {
                "Name": "<version name>",
                "FriendlyName": "<friendly name>",
                "Default": true | false,
                "Amd64Url": {
                    "Url": "<tar url>",
                    "Sha256": "<tar sha256 hash>"
                },
                "Arm64Url": {
                    "Url": "<tar url>",
                    "Sha256": "<tar sha256 hash>"
                }
            },
            {
                ...
            }
        ],
        "<flavor>": [
            ...
        ]
    }
}
```

Each `flavor` entry contains a list of installable distributions. Distributions can be installed either via the flavor name (in which case the default entry is installed), or the version name.

See how `wsl --install` commands work with the below manifest:

```json
{
    "ModernDistributions": {
        "my-distro": [
            {
                "Name": "my-distro-v3",
                "Default": true,
                "FriendlyName": "My distribution version 3 (latest)"
                [...]
            },
            {
                "Name": "my-distro-v2",
                "Default": false,
                "FriendlyName": "My distribution version 2"
                [...]
            }
        ]
    }
}
```

Sample install commands:

```powershell
wsl --install my-distro # Installs 'my-distro-v3' since it's the default for 'my-distro' flavor
wsl --install my-distro-v3 # Installs 'my-distro-v3' explicitly
wsl --install my-distro-v2 # Installs 'my-distro-v2' explicitly
```

## Adding your distribution to `wsl --install` for all WSL users

To make your WSL distribution available to all users, open a pull request on the [WSL GitHub repository](https://github.com/microsoft/WSL) that modifies the [DistributionInfo.json](https://github.com/microsoft/WSL/blob/master/distributions/DistributionInfo.json) file to include your distribution information.

This pull request will be reviewed by the WSL team.

## Adding your distribution to `wsl --install` for your enterprise or business group

You can also make your distribution available in `wsl --install` only to a select group by editing registry keys on the chosen Windows devices.

The WSL distribution manifest can be overridden by creating registry values in `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Lxss`.

- `DistributionListUrl`: Overrides the distribution manifest URL
- `DistributionListUrlAppend`: Add distributions from that manifest URL to the list of installable distributions

Both registry values are strings (REG_SZ) and are expected to be in URL format.

Starting with WSL release 2.4.4, the `file://` protocol is supported to make local testing easier. The expected format is: `file:///C:/path/to/file`.

### Test the distribution locally

To test a distribution tar, you can use the following sample powershell script to override the distribution manifest with the new distribution. First save the script below as `override-manifest.ps1`:

```powershell
#Requires -RunAsAdministrator

[cmdletbinding(PositionalBinding = $false)]
param (
    [Parameter(Mandatory = $true)][string]$TarPath,
    [string]$Flavor = "test-distro",
    [string]$Version = "test-distro-v1",
    [string]$FriendlyName = "Test distribution version 1")

Set-StrictMode -Version latest

$TarPath = Resolve-Path $TarPath
$hash = (Get-Filehash $TarPath -Algorithm SHA256).Hash


$manifest= @{
    ModernDistributions=@{
        "$Flavor" = @(
            @{
                "Name" = "$Version"
                Default = $true
                FriendlyName = "$FriendlyName"
                Amd64Url = @{
                    Url = "file://$TarPath"
                    Sha256 = "0x$hash"
                }
            })
        }
    }

$manifestFile = "$PSScriptRoot/manifest.json"
$manifest | ConvertTo-Json -Depth 5 | Out-File -encoding ascii $manifestFile


Set-ItemProperty -Path "HKLM:SOFTWARE\Microsoft\Windows\CurrentVersion\Lxss" -Name DistributionListUrl -Value "file://$manifestFile" -Type String -Force
```

Then configure the local manifest by running the following command in an elevated Powershell:

```powershell
.\override-manifest.ps1 -TarPath /path/to/tar
```

Once completed, you should see the following output from `wsl.exe --list --online`:

```powershell
$ wsl --list --online
The following is a list of valid distributions that can be installed.
Install using 'wsl.exe --install <Distro>'.

NAME              FRIENDLY NAME
test-distro-v1    Test distribution version 1
```

You can then run `wsl.exe --install test-distro-v1` to try the installation of the new distribution.

When you're done, you can delete `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Lxss\DistributionListUrl` to revert to the official manifest.

## WSL custom Linux distribution recommendations

### Configuration file recommendations

- Ensure that your custom distribution includes both the `/etc/wsl.conf` and `/etc/wsl-distribution.conf` configuration files. Both files should be owned by `root:root` and their permissions should be `0644`.
- If the `oobe.command` setting is used to create a new user, both `uid` and `oobe.defaultUid` should be set to `1000`.
- Ensure that you set both `oobe.defaultName` and `shortcut.icon` in the distribution configuration file: `/etc/wsl-distribution.conf`
- Do not include the file `/etc/resolv.conf` in the root filesystem.
- Do include a root user in `/etc/passwd`. The `uid` for this root user should be `0`.
- There should be no password hashes in `/etc/shadow`.
- The archive should not contain a kernel or an initramfs.

### Systemd recommendations

If systemd is enabled, units that can cause issues with WSL should be disabled or masked.
The below units are known to cause issues in WSL distributions (applies to both system and user units):

- systemd-resolved.service
- systemd-networkd.service
- NetworkManager.service
- systemd-tmpfiles-setup.service
- systemd-tmpfiles-clean.service
- systemd-tmpfiles-clean.timer
- systemd-tmpfiles-setup-dev-early.service
- systemd-tmpfiles-setup-dev.service
- tmp.mount
