---
title: An overview on the the Windows Subsystem for Linux
description: Learn about the Windows Subsystem for Linux, the different versions and ways you can use them.
keywords: BashOnWindows, bash, wsl, windows, windowssubsystem, gnu, linux
ms.date: 03/23/2020
ms.topic: article
ms.assetid: 3cefe0db-7616-4848-a2b6-9296746a178b
ms.custom: seodec18
ms.localizationpriority: high;
---
# Overview of the Windows Subsytem for Linux

## Windows Subsystem for Linux

The Windows Subsystem for Linux lets developers run a GNU/Linux environment -- including most command-line tools, utilities, and applications -- directly on Windows, unmodified, without the overhead of a virtual machine.

You can:

* Choose your favorite GNU/Linux distributions [from the Microsoft Store](https://aka.ms/wslstore).
* Run common command-line tools such as `grep`, `sed`, `awk`, or other ELF-64 binaries.
* Run Bash shell scripts and GNU/Linux command-line applications including:  
    *Tools: vim, emacs, tmux
    *Languages: Javascript, Ruby, Python, C/C++, C# & F#, Rust, Go, etc.
    *Services: SSHD, MySQL, Apache, lighttpd
* Install additional software using own GNU/Linux distribution package manager.
* Invoke Windows applications using a Unix-like command-line shell.
* Invoke GNU/Linux applications on Windows.

## Windows Subsystem for Linux 2

WSL 2 is a new version of the architecture that powers the Windows Subsystem for Linux to run ELF64 Linux binaries on Windows. Its primary goals are to increase file system performance, as well as adding full system call compatibility. This new architecture changes how these Linux binaries interact with Windows and your computer's hardware, but still provides the same user experience as in WSL 1 (the current widely available version). Individual Linux distros can be run either as a WSL 1 distro, or as a WSL 2 distro, can be upgraded or downgraded at any time, and you can run WSL 1 and WSL 2 distros side by side. WSL 2 uses an entirely new architecture that uses a real Linux kernel.
