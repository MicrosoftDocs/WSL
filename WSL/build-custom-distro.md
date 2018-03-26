---
title: Build a Custom Linux Distro for WSL
description: Learn how to create a custom Linux distribution for WSL.
keywords: BashOnWindows, bash, wsl, windows, windowssubsystem, distro, custom
author: taraj
ms.author: taraj
ms.date: 3/27/2018
ms.topic: article
ms.prod: windows-subsystem-for-linux
ms.service: windows-subsystem-for-linux
ms.assetid: 
---

# Creating a Custom Linux Distro for WSL

Use our open source WSL sample to build WSL distro packages for the Microsoft Store and/or to create custom Linux distro packages for sideloading. You can find the [distro launcher repo](https://github.com/Microsoft/WSL-DistroLauncher) on GitHub.

This project enables:
* Linux distribution maintainers to package and submit a Linux distribution as an appx that runs on WSL
* Developers to create custom Linux distributions that can be sideloaded onto their dev machine

## Background
We distribute Linux distros for WSL as UWP applications through the Microsoft Store. You can install those applications that will then run on WSL - the subsystem that sits in the Windows kernel. This delivery mechanism has many benefits as discussed in an earlier blog post.

## Sideloading a Custom Linux Distro Package
You can create a custom Linux distro package as an application to sideload on your personal machine. Please note that your custom package would not be distributed through the Microsoft Store unless you submit as a distribution maintainer.
To set up your machine to sideload apps, you will need to enable this in the system settings under “For Developers”.  Be sure to either have developer mode, or sideload apps selected

## For Linux Distro Maintainers
To submit to the Store, you will need to work with us to receive publishing approval. If you are a Linux distribution owner interested in adding your distribution to the Microsoft Store, please contact wslpartners@microsoft.com.

## Getting Started
Follow the instructions on the [Distro Launcher GitHub repo](https://github.com/Microsoft/WSL-DistroLauncher) to create a custom Linux distro package.

 
## Team Blogs
*  [Open Sourcing a WSL Sample for Linux Distribution Maintainers and Sideloading Custom Linux Distributions](https://blogs.msdn.microsoft.com/commandline/2018/03/26/wsl-distro-launcher/)
* [Command-Line blog](https://blogs.msdn.microsoft.com/commandline/)

## Provide Feedback
* [Distro Launcher Gitub repo](https://github.com/Microsoft/WSL-DistroLauncher)
* [GitHub issue tracker for WSL](https://github.com/Microsoft/BashOnWindows/issues)
* [Command-line UserVoice portal](https://wpdev.uservoice.com/forums/266908-command-prompt-console-bash-on-ubuntu-on-windo/category/161892-bash)