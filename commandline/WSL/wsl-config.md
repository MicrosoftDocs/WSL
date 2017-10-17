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

While WSL config is helpful for settings that span or coordinate distributions, each distribution independently manages it's own configurations.  To see distribution-specific commands, run `[distroname] /?`.  For example `ubuntu /?`.

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

`wslconfig /setdefault <DistributionName>`  


## Unregister distribution

`wslconfig /unregister <DistributionName>`  
