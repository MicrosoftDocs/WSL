---
title: Bash on Ubuntu on Windows - About
description: About Bash on Ubuntu on Windows
keywords: BashOnWindows, bash, wsl, windows, windowssubsystem, ubuntu
author: jackchammons
ms.date: 9/6/2016
ms.topic: article
ms.prod: windows-subsystem-for-linux
ms.service: windows-subsystem-for-linux
ms.assetid: 3cefe0db-7616-4848-a2b6-9296746a178b
---

# <img src="media/bash_logo.png" width="600">

> **Important note**:
> Bash/WSL is deliberately branded as a “beta” feature: We know there are issues and incomplete 
> features. You should expect many things to work and for some things to fail. We appreciate 
> any and all constructive feedback you can share from your experiences in using Bash/WSL. 
> Your [bug reports](https://github.com/microsoft/bashonwindows) help us diagnose issues we 
> need to fix in order to deliver a great experience.

## Overview
Bash on Windows provides developers with a familiar Bash shell and Linux environment in which 
you can run most Linux command-line tools, directly on Windows, **UNMODIFIED**, without needing 
an entire Linux virtual machine!

Bash/WSL allows you to:

1. Run common command-line utilities such as `grep`, `sed`, `awk`, etc. delivered by any Unix-like environment. 
1. Use the Linux-compatible filesystem & heirarchy and access fixed Windows storage 
mounted under `/mnt/...`.
1. Run Bash shell scripts and Linux command-line apps, including:
    * Tools: vim, emacs, tmux.
    * Languages: Javascript/node.js, Ruby, Python, C/C++, C# & F#, Rust, Go, etc.
    * Services: sshd, MySQL, Apache, lighttpd. 
1. Install additional Linux tools using `apt`.
1. Invoke Windows applications from within Bash.
1. Invoke Linux applications from within Windows!

Bash on Windows runs Ubuntu user-mode binaries provided by Canonical.  This means the 
command-line utilities are the same as those that run within a native Ubuntu environment.  

## Getting started
* [Installation guide](https://msdn.microsoft.com/en-us/commandline/wsl/install_guide)
* [Command reference](https://msdn.microsoft.com/en-us/commandline/wsl/reference)
* [User accounts](https://msdn.microsoft.com/en-us/commandline/wsl/user_support)
* [Frequently asked questions](https://msdn.microsoft.com/en-us/commandline/wsl/faq)
* [Release notes](https://msdn.microsoft.com/en-us/commandline/wsl/release_notes)

## Learn About Bash on Windows Subsystem for Linux
To learn all about Bash and the Windows Subsystem for Linux (WSL), we've [collected several 
videos and blog posts][1] demonstrating Bash/WSL and detailing its inner workings!
<br/>
<a href="https://blogs.msdn.microsoft.com/commandline/learn-about-bash-on-windows-subsystem-for-linux/">
  <img title="Learn more about Bash on WSL image" 
    src="https://msdnshared.blob.core.windows.net/media/2016/06/LearnBash.jpg" 
    width="90%" />
</a>

## Team Blogs
* [Command-Line blog](https://blogs.msdn.microsoft.com/commandline/)
* [WSL Blog](https://blogs.msdn.microsoft.com/wsl/)

## Posts & Articles
* [Run Bash on Ubuntu on Windows](https://blogs.windows.com/buildingapps/2016/03/30/run-bash-on-ubuntu-on-windows/)
* [Developers Can Run Bash And Usermode Ubuntu Linux Binaries On Windows 10](http://www.hanselman.com/blog/DevelopersCanRunBashShellAndUsermodeUbuntuLinuxBinariesOnWindows10.aspx)
* [Ubuntu on Windows – The Ubuntu Userspace for Windows Developers](http://insights.ubuntu.com/2016/03/30/ubuntu-on-windows-the-ubuntu-userspace-for-windows-developers/) 

## Feedback
* [GitHub issue tracker](https://github.com/Microsoft/BashOnWindows/issues)
* [Command-line UserVoice portal](https://wpdev.uservoice.com/forums/266908-command-prompt-console-bash-on-ubuntu-on-windo/category/161892-bash)

[1]: https://blogs.msdn.microsoft.com/commandline/learn-about-bash-on-windows-subsystem-for-linux/
