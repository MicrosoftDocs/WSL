---
title: What is Windows Subsystem for Linux 
description: Learn about the Windows Subsystem for Linux, including the different versions and ways you can use them. Microsoft Loves Linux.
ms.date: 11/20/2023
ms.topic: article
---

# What is the Windows Subsystem for Linux?

Windows Subsystem for Linux (WSL) is a feature of Windows that allows you to run a Linux environment on your Windows machine, without the need for a separate virtual machine or dual booting.  WSL is designed to provide a seamless and productive experience for developers who want to use both Windows and Linux at the same time.

- Use WSL to install and run various Linux distributions, such as Ubuntu, Debian, Kali, and more. [Install Linux distributions](./install.md) and receive automatic updates from the [Microsoft Store](./compare-versions.md#wsl-in-the-microsoft-store), [import Linux distributions not available in the Microsoft Store](./use-custom-distro.md), or [build your own custom Linux distribution](./build-custom-distro.md).
- Store files in an isolated Linux file system, specific to the installed distribution.
- Run command-line tools, such as BASH.
- Run common BASH command-line tools such as `grep`, `sed`, `awk`, or other ELF-64 binaries.
- Run Bash scripts and GNU/Linux command-line applications including:  
  - Tools: vim, emacs, tmux
  - Languages: [NodeJS](/windows/nodejs/setup-on-wsl2), JavaScript, [Python](/windows/python/web-frameworks), Ruby, C/C++, C# & F#, Rust, Go, etc.
  - Services: SSHD, [MySQL](./tutorials/wsl-database.md), Apache, lighttpd, [MongoDB](./tutorials/wsl-database.md), [PostgreSQL](./tutorials/wsl-database.md).
- Install additional software using your own GNU/Linux distribution package manager.
- Invoke Windows applications using a Unix-like command-line shell.
- Invoke GNU/Linux applications on Windows.
- [Run GNU/Linux graphical applications](./tutorials/gui-apps.md) integrated directly to your Windows desktop
- Use your device [GPU to accelerate Machine Learning workloads running on Linux.](./tutorials/gpu-compute.md)

> [!div class="nextstepaction"]
> [Install WSL](install.md)

<br>

> [!VIDEO https://www.youtube.com/embed/48k317kOxqg]

## What is WSL 2?

WSL 2 is the default distro type when installing a Linux distribution. WSL 2 uses virtualization technology to run a Linux kernel inside of a lightweight utility virtual machine (VM). Linux distributions run as isolated containers inside of the WSL 2 managed VM. Linux distributions running via WSL 2 will share the same network namespace, device tree (other than `/dev/pts`), CPU/Kernel/Memory/Swap, `/init` binary, but have their own PID namespace, Mount namespace, User namespace, Cgroup namespace, and `init` process. 

WSL 2 **increases file system performance** and adds **full system call compatibility** in comparison to the WSL 1 architecture. Learn more about how [WSL 1 and WSL 2 compare](./compare-versions.md). 

Individual Linux distributions can be run with either the WSL 1 or WSL 2 architecture. Each distribution can be upgraded or downgraded at any time and you can run WSL 1 and WSL 2 distributions side by side. See the [Set WSL version command](/windows/wsl/basic-commands#set-default-wsl-version).

> [!VIDEO https://www.youtube.com/embed/MrZolfGm8Zk]

## Microsoft Loves Linux

Learn more about [Linux resources at Microsoft](/linux), including Microsoft tools that run on Linux, Linux training courses, Cloud Solution Architecture for Linux, and Microsoft + Linux news, events, and partnerships. **Microsoft Loves Linux!**
