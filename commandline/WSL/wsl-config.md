---
title: Manage Linux Distributions
description: List of commands that manage the Windows Subsystem for Linux
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu
author: scooley
ms.date: 10/13/2017
ms.topic: article
ms.prod: windows-subsystem-for-linux
ms.service: windows-subsystem-for-linux
ms.assetid: 7ca59bd7-d9d3-4f6d-8b92-b8faa9bcf250
---

# Manage multiple Linux Distributions in WSL

> This article only applies to Windows 10 Fall Creators Update and later

WSL Config is a command line tool for managing Linux distributions running on the Windows Subsystem for Linux (WSL).

wslconfig.exe
Performs administrative operations on Windows Subsystem for Linux

Usage:
    /l, /list [/all] - Lists registered distributions.
        /all - Optionally list all distributions, including distributions that
               are currently being installed or uninstalled.
    /s, /setdefault <DistributionName> - Sets the specified distribution as the default.
    /u, /unregister <DistributionName> - Unregisters a distribution.