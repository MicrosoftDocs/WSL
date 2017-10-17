---
title: Manage Linux Distributions
description: Reference listing and configuring multiple Linux distributions running on the Windows Subsystem for Linux.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu
author: scooley
ms.date: 10/13/2017
ms.topic: article
ms.prod: windows-subsystem-for-linux
ms.service: windows-subsystem-for-linux
ms.assetid: 7ca59bd7-d9d3-4f6d-8b92-b8faa9bcf250
---

# Manage multiple Linux Distributions in WSL

> Applies to Windows 10 Fall Creators Update and later.

WSL Config (`wslconfig.exe`) is a command line tool for managing Linux distributions running on the Windows Subsystem for Linux (WSL).  It lets you list available distributions, set a default distribution, and uninstall distributions.

While WSL config is helpful for settings that span or coordinate distributions, each Linux distribution independently manages it's own configurations.  To see distribution-specific commands, run `[distribution.exe] /?`.  For example `ubuntu /?`.

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
Lists availabls Linux distributions available to WSL.  If a distribution is listed, it's installed and ready to use.

`wslconfig /list /all`  
Lists all distributions, including ones that aren't currelty usable.  They may be in the process of installing, uninstalling, or are in a broken state.  

## Set a default distribution

There are three ways to launch and run WSL:

1. `wsl.exe` or `bash.exe`
1. `wsl -c [command]` or `bash -c [command]`
1. `[distro]` ie `ubuntu` -- this is the same as launching the installed app from the windows menu.

In the first two cases, WSL has to pick a distribution to run - a default distribution.  If you don't explicitly set a default, it will be the first one installed.

`wslconfig /setdefault <DistributionName>`  
Sets the default distribution to `<DistributionName>`.

For example:
`wslconfig /setdefault Ubuntu` would set my default distribution to Ubuntu.  Now when I run `wsl -c npm init` it will run in Ubuntu.  If I run `wsl` it will open an Ubuntu session.


## Unregister distribution


`wslconfig /unregister <DistributionName>`  

