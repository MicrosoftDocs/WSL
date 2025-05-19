---
title: Open Source WSL 
description: Windows Subsystem for Linux is now Open Source. Learn what this means and how to download WSL and build it from source code.
ms.date: 05/19/2025
ms.topic: article
---

# WSL and Open Source resources

Windows Subsystem for Linux (WSL) is now Open Source.

The code that powers WSL is available at [GitHub: microsoft/WSL Releases](https://github.com/microsoft/WSL/releases/).

Learn what this means, how to download WSL, build from source code, and overview of WSL components, and more.

## Component overview

WSL is made of a set of distribution components. Some run in Windows, and some run inside the WSL 2 virtual machine.

:::image type="content" source="./media/wsl-architecture.png" alt-text="Overview diagram of WSL architecture.":::

WSL’s code can be broken up into these main areas:

- Command line executables that are the entry points to interact with WSL: `wsl.exe`, `wslconfig.exe`, and `wslg.exe`. These are processes run from `C:\\Windows\System32\wsl.exe` > `CreateProcess()`.

- The WSL service that starts the WSL Virtual Machine (VM), starts the installed Linux distributions, mounts file access shares and more: `wslservice.exe`.

- Linux init and daemon processes, binaries that run in Linux to provide WSL functionality: `init` for start up, `gns` for networking, `localhost` for port forwarding, etc.

- File sharing Linux files to Windows with WSL’s plan9 server implementation: `plan9`.

Learn more about each component at the WSL Open Source docs site: [wsl.dev](https://wsl.dev).

The WSL source code is supported by these additional open sourced components:

- [microsoft/wslg: Enabling the Windows Subsystem for Linux to include support for Wayland and X server related scenarios](https://github.com/microsoft/wslg): The Graphical User Interface (GUI) to run Linus apps with a UI (not just in the command line).
- [microsoft/WSL2-Linux-Kernel: The source for the Linux kernel used in Windows Subsystem for Linux 2 (WSL2)](https://github.com/microsoft/WSL2-Linux-Kernel): The WSL2 Linux kernel.

The following components are still part of the Windows image and are not open sourced at this time:

- `Lxcore.sys`: the kernel side driver that powers WSL 1
- `P9rdr.sys` and `p9np.dll`: The components which run the `\\wsl.localhost` filesystem redirection (from Windows to Linux)

For more about the history and community behind open sourcing WSL, see the blog announcement from Microsoft Build 2025: [The Windows Subsystem for Linux is now open source by Pierre Boulay](https://blogs.windows.com/windowsdeveloper/2025/05/19/the-windows-subsystem-for-linux-is-now-open-source/)

Visit the WSL repo on GitHub to contribute: [github.com/WSL]](https://github.com/microsoft/WSL/).
