---
title: What is Windows Subsystem for Linux 
description: Learn about the Windows Subsystem for Linux, including the different versions and ways you can use them.
keywords: BashOnWindows, bash, wsl, windows, windowssubsystem, gnu, linux
ms.date: 09/27/2021
ms.topic: article
ms.assetid: 3cefe0db-7616-4848-a2b6-9296746a178b
---

# What is the Windows Subsystem for Linux?

The Windows Subsystem for Linux lets developers run a GNU/Linux environment -- including most command-line tools, utilities, and applications -- directly on Windows, unmodified, without the overhead of a traditional virtual machine or dualboot setup.

You can:

- Choose your favorite GNU/Linux distributions [from the Microsoft Store](https://aka.ms/wslstore).
- Run common command-line tools such as `grep`, `sed`, `awk`, or other ELF-64 binaries.
- Run Bash shell scripts and GNU/Linux command-line applications including:  
  - Tools: vim, emacs, tmux
  - Languages: [NodeJS](/windows/nodejs/setup-on-wsl2), Javascript, [Python](/windows/python/web-frameworks), Ruby, C/C++, C# & F#, Rust, Go, etc.
  - Services: SSHD, [MySQL](./tutorials/wsl-database.md), Apache, lighttpd, [MongoDB](./tutorials/wsl-database.md), [PostgreSQL](./tutorials/wsl-database.md).
- Install additional software using your own GNU/Linux distribution package manager.
- Invoke Windows applications using a Unix-like command-line shell.
- Invoke GNU/Linux applications on Windows.

> [!div class="nextstepaction"]
> [Install WSL](install.md)

<br>

> [!VIDEO https://www.youtube.com/embed/48k317kOxqg]

## What is WSL 2?

WSL 2 is a new version of the Windows Subsystem for Linux architecture that powers the Windows Subsystem for Linux to run ELF64 Linux binaries on Windows. Its primary goals are to **increase file system performance**, as well as adding **full system call compatibility**.

This new architecture changes how these Linux binaries interact with Windows and your computer's hardware, but still provides the same user experience as in WSL 1 (the current widely available version).

Individual Linux distributions can be run with either the WSL 1 or WSL 2 architecture. Each distribution can be upgraded or downgraded at any time and you can run WSL 1 and WSL 2 distributions side by side. WSL 2 uses an entirely new architecture that benefits from running a real Linux kernel.

<br>

> [!VIDEO https://www.youtube.com/embed/MrZolfGm8Zk]
