---
title: About Windows Subsystem for Linux
description: Learn about the Windows Subsystem for Linux, the different versions and ways you can use them.
keywords: BashOnWindows, bash, wsl, windows, windowssubsystem, gnu, linux
ms.date: 05/12/2020
ms.topic: article
ms.assetid: 3cefe0db-7616-4848-a2b6-9296746a178b
ROBOTS: NOINDEX
---

# What is the Windows Subsystem for Linux?

The Windows Subsystem for Linux lets developers run a GNU/Linux environment -- including most command-line tools, utilities, and applications -- directly on Windows, unmodified, without the overhead of a traditional virtual machine or dualboot setup.

You can:

* Choose your favorite GNU/Linux distributions [from the Microsoft Store](https://aka.ms/wslstore).
* Run common command-line tools such as `grep`, `sed`, `awk`, or other ELF-64 binaries.
* Run Bash shell scripts and GNU/Linux command-line applications including:  
    * Tools: vim, emacs, tmux
    * Languages: [NodeJS](https://docs.microsoft.com/windows/nodejs/setup-on-wsl2), Javascript, [Python](https://docs.microsoft.com/windows/python/web-frameworks), Ruby, C/C++, C# & F#, Rust, Go, etc.
    * Services: SSHD, MySQL, Apache, lighttpd, [MongoDB](https://docs.microsoft.com/windows/nodejs/databases), [PostgreSQL](https://docs.microsoft.com/windows/python/databases).
* Install additional software using own GNU/Linux distribution package manager.
* Invoke Windows applications using a Unix-like command-line shell.
* Invoke GNU/Linux applications on Windows.

## What is WSL 2?

WSL 2 is a new version of the Windows Subsystem for Linux architecture that powers the Windows Subsystem for Linux to run ELF64 Linux binaries on Windows. Its primary goals are to **increase file system performance**, as well as adding **full system call compatibility**.

This new architecture changes how these Linux binaries interact with Windows and your computer's hardware, but still provides the same user experience as in WSL 1 (the current widely available version).

Individual Linux distributions can be run with either the WSL 1 or WSL 2 architecture. Each distribution can be upgraded or downgraded at any time and you can run WSL 1 and WSL 2 distributions side by side. WSL 2 uses an entirely new architecture that benefits from running a real Linux kernel.

## Next steps

* [Install WSL 1 and update to WSL 2](./install-win10.md)

* [Compare WSL 2 and WSL 1](./compare-versions.md)

* [Create a user account and password for your new Linux distribution](./user-support.md)

* [Read Frequently Asked Questions](./faq.md)

* [Read Frequently Asked Questions about WSL 2](./wsl2-faq.md)

* [Troubleshooting](./troubleshooting.md)

* [Run interoperability commands between Windows and Linux](./interop.md)

* [Run launch commands and configurations](./wsl-config.md)

* [Set up file permissions](./file-permissions.md)

* [Set up WSL for Enterprise](./enterprise.md)

* [Reference WSL commands](./reference.md)

* [Build a custom distributions](./build-custom-distro.md)

* [Read the WSL Release Notes](./release-notes.md)
