---
title: Bash on Ubuntu on Windows - Architectural Overview
description: Architectural overview of Bash on Ubuntu on Windows Subsystem for Linux
keywords: BashOnWindows, bash, wsl, windows, windowssubsystem, ubuntu, windows subsystem for linux
author: jackchammons
ms.date: 9/4/2016
ms.topic: article
ms.prod: windows-subsystem-for-linux
ms.service: windows-subsystem-for-linux
ms.assetid: 3cefe0db-7616-4848-a2b6-9296746a178b
---

There are three major components of WSL that allows Windows 10 to provide a bash shell. 

### 1. Ubuntu / Linux Binary 
Genuine unmodified Ubuntu user-mode binaries provided by Canonical and/or downloaded 
and installed manually or via apt-get 

### 2. Window Subsystem for Linux (WSL) 
WSL provides several important components and/or services that enable unmodified Linux binaries to run directly on Windows:

* Linux PicoProcesses: lightweight processes into which Linux binaries, and their dependencies are loaded, bound, and then executed
* Syscalls: Windows kernel infrastructure that exposes a set of syscalls that are compatible with the Linux kernel Application Binary Interface (ABI).  The WSL kernel infrastructure was developed by Microsoft and contains no Linux code.
* User-mode tools: Tools including bash.exe and lxrun.exe which are used to launch, and install/uninstall/configure the Ubuntu instance.

![](media/architecture.png)
