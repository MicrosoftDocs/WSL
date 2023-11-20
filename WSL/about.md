---
title: What is Windows Subsystem for Linux 
description: Learn about the Windows Subsystem for Linux, including the different versions and ways you can use them.
ms.date: 11/20/2023
ms.topic: article
---

# What is the Windows Subsystem for Linux?

The Windows Subsystem for Linux lets developers run a GNU/Linux environment -- including most command-line tools, utilities, and applications -- directly on Windows, unmodified, without the overhead of a traditional virtual machine or dualboot setup. 

You can:

- Choose your favorite GNU/Linux distributions [from the Microsoft Store](https://aka.ms/wslstore).
- Run common command-line tools such as `grep`, `sed`, `awk`, or other ELF-64 binaries.
- Run Bash scripts and GNU/Linux command-line applications including:  
  - Tools: vim, emacs, tmux
  - Languages: [NodeJS](/windows/nodejs/setup-on-wsl2), JavaScript, [Python](/windows/python/web-frameworks), Ruby, C/C++, C# & F#, Rust, Go, etc.
  - Services: SSHD, [MySQL](./tutorials/wsl-database.md), Apache, lighttpd, [MongoDB](./tutorials/wsl-database.md), [PostgreSQL](./tutorials/wsl-database.md).
- Install additional software using your own GNU/Linux distribution package manager.
- Invoke Windows applications using a Unix-like command-line shell.
- Invoke GNU/Linux applications on Windows.
- [Run GNU/Linux graphical applications](./tutorials/gui-apps.md) integrated directly to your Windows desktop
- [Use GPU acceleration](./tutorials/gpu-compute.md) for machine learning, data science scenarios and more

> [!div class="nextstepaction"]
> [Install WSL](install.md)

<br>

> [!VIDEO https://www.youtube.com/embed/48k317kOxqg]

## What is WSL 2?

WSL 2 is the updated version of the Windows Subsystem for Linux architecture that powers the Windows Subsystem for Linux to run ELF64 Linux binaries on Windows. It's primary goals are to **increase file system performance**, as well as adding **full system call compatibility**.

WSL 2 architecture changes how Linux binaries interact with Windows and your computer's hardware [compared to WSL 1](./compare-versions.md). WSL 2 is the default version when installing a Linux distribution and uses virtualization technology to run a Linux kernel inside of a lightweight utility virtual machine (VM).

Linux distributions run as isolated containers inside of the WSL 2 managed VM. Linux distributions running via WSL 2 will share the same network namespace, device tree (other than `/dev/pts`), CPU/Kernel/Memory/Swap, `/init` binary, but have their own PID namespace, Mount namespace, User namespace, Cgroup namespace, and `init` process. 

Individual Linux distributions can be run with either the WSL 1 or WSL 2 architecture. Each distribution can be upgraded or downgraded at any time and you can run WSL 1 and WSL 2 distributions side by side. See the [Set WSL version command](/windows/wsl/basic-commands#set-default-wsl-version).

> [!VIDEO https://www.youtube.com/embed/MrZolfGm8Zk]
