---
title: Windows Subsystem for Linux Documentation
description: Overview of the Windows Subsystem for Linux documentation.
ms.topic: overview
ms.date: 09/09/2026
---

# Windows Subsystem for Linux Documentation

Windows Subsystem for Linux (WSL) lets developers run a GNU/Linux environment -- including most command-line tools, utilities, and applications -- directly on Windows, unmodified, without the overhead of a traditional virtual machine or dual-boot setup.

> [!div class="nextstepaction"]
> [Install WSL](install.md)

## Learn more

* [What is the Windows Subsystem for Linux (WSL)?](about.md)
* [Windows Subsystem for Linux is now open source](https://blogs.windows.com/windowsdeveloper/2025/05/19/the-windows-subsystem-for-linux-is-now-open-source/)
* [What's new with WSL 2?](compare-versions.md#whats-new-in-wsl-2)
* [Comparing WSL 1 and WSL 2](compare-versions.md)
* [Frequently Asked Questions](faq.yml)

:::image type="content" source="./media/wsl-opensource.png" alt-text="Screenshot of Satya introducing WSL going Open Source at the 2025 Build conference.":::

## Get started

* [Install WSL](install.md)
* [Install Linux on Windows Server](install-on-server.md)
* [Manual install steps](install-manual.md)
* [Best practices for setting up a WSL development environment](./setup/environment.md)

## WSL containers (preview)

Build and run Linux containers on Windows with the built-in `wslc.exe` command-line tool, or integrate Linux containers into Windows applications with the WSL container API. WSL containers are currently available in public preview. See the [WSL container prerequisites](wsl-container.md) before you begin.

| Your goal | Start here |
| --- | --- |
| Explore the feature and choose a workflow | [WSL container overview](wsl-container.md) |
| Build and run containers from the command line | [Run your first WSL container](tutorials/wsl-containers.md) |
| Use Linux containers as part of a Windows app | [WSL container API guide](wsl-container.md#wsl-container-api) |
| Find API details and runnable examples | [API reference](https://wsl.dev/api-reference/) and [samples](https://aka.ms/wslc-samples) |

## Try WSL preview features

WSL prereleases and Windows Insider builds are separate update channels. To try WSL containers, follow the [container installation instructions](tutorials/wsl-containers.md#install-and-verify-wslc), which use `wsl --update --pre-release`. Installing a WSL prerelease does not itself require enrollment in the Windows Insider Program.

Some features depend on a particular Windows build as well as a WSL version. Check each feature's prerequisites. If it requires a Windows preview build, see the [Windows Insider Program](https://insider.windows.com/getting-started) for enrollment and channel information.

## Team blogs

* [Overview post with a collection of videos and blogs](https://blogs.msdn.microsoft.com/commandline/learn-about-windows-console-and-windows-subsystem-for-linux-wsl/)
* [Command-Line blog](https://blogs.msdn.microsoft.com/commandline/) (Active)
* [Windows Subsystem for Linux Blog](/archive/blogs/wsl/) (Historical)

## Provide feedback

* [GitHub issue tracker: WSL](https://github.com/microsoft/WSL/issues)
* [GitHub issue tracker: WSL documentation](https://github.com/MicrosoftDocs/WSL/issues)

## Related videos

### WSL BASICS

1. [What is the Windows Subsystem for Linux (WSL)?](https://www.youtube.com/watch?v=NYGMY9c90Oo) | One Dev Question (0:40)
1. [I'm a Windows developer. Why should I use WSL? |](https://www.youtube.com/watch?v=sqdHy1rC2t4) One Dev Question (0:58)
1. [I'm a Linux developer. Why should I use WSL?](https://www.youtube.com/watch?v=75JBKfAqH3I) | One Dev Question (1:04)
1. [What is Linux?](https://www.youtube.com/watch?v=jx5I-8_arqM) | One Dev Question (1:31)
1. [What is a Linux distro?](https://www.youtube.com/watch?v=WnzKfwL3Iy0) | One Dev Question (1:04)
1. [How is WSL different than a virtual machine or dual booting?](https://www.youtube.com/watch?v=UMQ5GQix0rs) | One Dev Question
1. [Why was the Windows Subsystem for Linux created?](https://www.youtube.com/watch?v=b9I7NZHni5c) | One Dev Question (1:14)
1. [How do I access files on my computer in WSL?](https://www.youtube.com/watch?v=uUaFNRRS9yo&t=2s) | One Dev Question (1:41)
1. [How is WSL integrated with Windows?](https://www.youtube.com/watch?v=JuJ_Nx_bFEM) | One Dev Question (1:34)
1. [How do I configure a WSL distro to launch in the home directory in Terminal?](https://www.youtube.com/watch?v=n1YSFT5VK-Y) | One Dev Question (0:47)
1. [Can I use WSL for scripting?](https://www.youtube.com/watch?v=teI6WA48_Rg) | One Dev Question (1:04)
1. [Why would I want to use Linux tools on Windows?](https://www.youtube.com/watch?v=OeomwrHLAR4) | One Dev Question (1:20)
1. [In WSL, can I use distros other than the ones in the Microsoft Store?](https://www.youtube.com/watch?v=AfhDwVASD2c) | One Dev Question (1:03)

### WSL DEMOS

1. [WSL2: Code faster on the Windows Subsystem for Linux!](https://www.youtube.com/watch?v=MrZolfGm8Zk&t=3s) | Tabs vs Spaces (13:42)
1. [WSL: Run Linux GUI Apps](https://www.youtube.com/watch?v=kC3eWRPzeWw) | Tabs vs Spaces (17:16)
1. [WSL 2: Connect USB devices](https://www.youtube.com/watch?v=I2jOuLU4o8E) | Tabs vs Spaces (10:08)
1. [GPU Accelerated Machine Learning with WSL 2](https://www.youtube.com/watch?v=PdxXlZJiuxA) | Tabs vs Spaces (16:28)
1. [Visual Studio Code: Remote Dev with SSH, VMs, and WSL](https://www.youtube.com/watch?v=XkLjxr9iQ-8&t=1s) | Tabs vs Spaces (29:33)
1. [Windows Dev Tool Updates: WSL, Terminal, Package Manager, and more](https://www.youtube.com/watch?v=m5tt9mDRPSw) | Tabs vs Spaces (20:46)
1. [Build Node.JS apps with WSL](https://www.youtube.com/watch?v=lOXatmtBb88) | Highlight (3:15)
1. [New memory reclaim feature in WSL 2](https://www.youtube.com/watch?v=K9GPOHrZgr4) | Demo (6:01)
1. [Web development on Windows (in 2019)](https://www.youtube.com/watch?v=UxWN1BBr1bM) | Demo (10:39)

### WSL DEEP DIVES

1. [WSL on Windows 11 - Demos with Craig Loewen and Scott Hanselman](https://www.youtube.com/watch?v=pNwatyeXplY)| Windows Wednesday (35:48)
1. [WSL and Linux Distributions – Hayden Barnes and Kayla Cinnamon](https://www.youtube.com/watch?v=kCB3gO32SPs) | Windows Wednesday (37:00)
1. [Customize your terminal with Oh My Posh and WSL Linux distros](https://www.youtube.com/watch?v=uO_F5W2LbSk) | Windows Wednesday (33:14)
1. [Web dev Sarah Tamsin and Craig Loewen chat about web development, content creation, and WSL](https://www.youtube.com/watch?v=ySS8Re6LDTQ) | Dev Perspectives (12:22)
1. [How WSL accesses Linux files from Windows](https://www.youtube.com/watch?v=63wVlI9B3Ac&t=45s) | Deep dive (24:59)
1. [Windows subsystem for Linux architecture: a deep dive](https://www.youtube.com/watch?v=lwhMThePdIo) | Build 2019 (58:10)
