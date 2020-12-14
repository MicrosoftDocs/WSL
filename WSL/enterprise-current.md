---
title: WSL for Enterprise
description: Resources and instructions on how to best use the WSL in an Enterprise environment.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, debian, suse, windows 10, enterprise, deployment, offline, packaging, store, distribution, installation, install
ms.date: 09/04/2018
ms.topic: article
ms.assetid: 7afaeacf-435a-4e58-bff0-a9f0d75b8a51
ms.custom: seodec18
---

# Windows Subsystem for Linux for Enterprise

## Creating your WSL image

Once WSL is installed on your machine, you should [choose a Linux distribution](https://docs.microsoft.com/windows/wsl/install-win10#step-6---install-your-linux-distribution-of-choice) to run from the Windows store.

## Exporting your custom WSL image

Export your custom WSL image by running wsl --export `<Distro> <FileName>`, which will wrap your image in a tar file and make it ready for distribution on to other machines.

## Distributing your WSL image

Distribute the WSL image from a share or storage device by running wsl --import `<Distro> <InstallLocation> <FileName>`, which will import the specified tar file as a new distribution.

## Frequently asked questions

### Are there other methods to control different aspects of WSL for users in my Enterprise?

As of right now WSL does not offer some control mechanisms to modify a user's experience in an Enterprise scenario. However, we are looking into adding some of these Enterprise features in the future. Here's a list of commonly asked features that we currently support.

Supported:

* Sharing an approved image internally using `wsl --import` and `wsl --export`
* Creating your own WSL distro for your Enterprise using the WSL Distro Launcher repo

Here's a list of features for which we don't yet have support for, but are investigating adding.

Currently Unsupported:

* Synchronizing the user inside WSL with the Windows user on the host machine
* Managing updates and patching of the Linux distributions and packages using Windows tools
* Having Windows update also update WSL distro contents
* Controlling which distributions users in your Enterprise can access
* Running mandatory services (logging or monitoring) inside of WSL
* Monitoring Linux instances using Windows configuration manager tools such as SCCM or Intune
* McAfee support

### How should I manage updating and patching the Linux distributions and packages?

Using Linux configuration manager tools is strongly recommended for monitoring and managing Linux user space. There are a host of Linux configuration managers to choose from. Check out this [blog post](http://www.craigloewen.com/blog/2019/12/04/running-puppet-quickly-in-wsl2/) on how to install Puppet in WSL 2.
