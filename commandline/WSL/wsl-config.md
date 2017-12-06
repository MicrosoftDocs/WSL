---
title: Manage Linux Distributions
description: Reference listing and configuring multiple Linux distributions running on the Windows Subsystem for Linux.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu
author: scooley
ms.author: scooley
ms.date: 10/13/2017
ms.topic: article
ms.prod: windows-subsystem-for-linux
ms.service: windows-subsystem-for-linux
ms.assetid: 7ca59bd7-d9d3-4f6d-8b92-b8faa9bcf250
---

# Manage multiple Linux Distributions in WSL

> Applies to Windows 10 Fall Creators Update and later.  See our updated [installation guide](./install_guide.md) to start running multiple Linux distros from the Windows Store.

WSL Config (`wslconfig.exe`) is a command line tool for managing Linux distributions running on the Windows Subsystem for Linux (WSL).  It lets you list available distributions, set a default distribution, and uninstall distributions.

While WSL Config is helpful for settings that span or coordinate distributions, each Linux distribution independently manages its own configurations.  To see distribution-specific commands, run `[distribution.exe] /?`.  For example `ubuntu /?`.

To see all available options for wslconfig, run:  `wslconfig /?`

```  txt
wslconfig.exe
Performs administrative operations on Windows Subsystem for Linux

Usage:
    /l, /list [/all] - Lists registered distributions.
        /all - Optionally list all distributions, including distributions that
               are currently being installed or uninstalled.
    /s, /setdefault <DistributionName> - Sets the specified distribution as the default.
    /u, /unregister <DistributionName> - Unregisters a distribution.
```

## List distributions

`wslconfig /list`  
Lists available Linux distributions available to WSL.  If a distribution is listed, it's installed and ready to use.

`wslconfig /list /all`  
Lists all distributions, including ones that aren't currently usable.  They may be in the process of installing, uninstalling, or are in a broken state.  

## Set a default distribution

There are three ways to launch and run WSL:

1. `wsl.exe` or `bash.exe`
1. `wsl [command]` or `bash -c [command]`
1. `[distro]` ie `ubuntu` -- this is the same as launching the installed app from the Windows menu.

In the first two cases, WSL must pick a distribution to run - a default distribution.  If you don't explicitly set a default, it will be the first one installed. Please note that when appending a command and invoking via 'wsl', you don't append a '-c' for the command.

`wslconfig /setdefault <DistributionName>`  
Sets the default distribution to `<DistributionName>`.

For example:
`wslconfig /setdefault Ubuntu` would set my default distribution to Ubuntu.  Now when I run `wsl -c npm init` it will run in Ubuntu.  If I run `wsl` it will open an Ubuntu session.

## Unregister and reinstall a distribution

While Linux distributions can be installed through the Windows store, they can't be uninstalled through the store.  WSL Config allows distributions to be unregistered/uninstalled.

Unregistering also allows distributions to be reinstalled.

> **Caution:** Once unregistered, all data, settings, and software associated with that distribution will be permanently lost.  Reinstalling from the store will install a clean copy of the distribution.

`wslconfig /unregister <DistributionName>`  
Unregisters the distribution from WSL so it can be reinstalled or cleaned up.

For example:
`wslconfig /unregister Ubuntu` would remove Ubuntu from the distributions available in WSL.  When I run `wsl /list` it will not be listed.

To reinstall, find the distribution in the Windows Store and select "Launch".
