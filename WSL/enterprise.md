---
title: Set up Windows Subsystem for Linux for your company
description: Resources and instructions on how to best use the Windows Subsystem for Linux in an Enterprise environment.
ms.date: 09/27/2021
ms.topic: article
---

# Enterprise environment: Set up Windows Subsystem for Linux for your company

As an administrator or manager, you may require all developers to use the same approved software. This consistency helps to create a well-defined work environment. The Windows Subsystem for Linux aids in this consistency by allowing you to import and export custom WSL images from one machine to the next. Read the guide below to learn more about:

* [Creating a custom WSL image](#creating-a-custom-wsl-image)
* [Distributing a WSL image](#distributing-your-wsl-image)
* [Update and patch Linux distributions and packages](#update-and-patch-linux-distributions-and-packages)
* [Enterprise security and control options](#enterprise-security-and-control-options)

## Creating a custom WSL image

What is commonly referred to as an "image", is simply a snapshot of your software and its components saved to a file. In the case of the Windows Subsystem for Linux, your image would consist of the subsystem, its distributions, and whatever software and packages are installed on the distribution.

To begin creating your WSL image, first [install the Windows Subsystem for Linux](./install.md).

Once installed, use The Microsoft Store for Business to download and install the Linux distribution that’s right for you. Create an account with the [Microsoft Store for Business](https://businessstore.microsoft.com/).

### Exporting your WSL image

Export your custom WSL image by running wsl --export `<Distro> <FileName>`, which will wrap your image in a tar file and make it ready for distribution on to other machines.

## Distributing your WSL image

Distribute the WSL image from a share or storage device by running wsl --import `<Distro> <InstallLocation> <FileName>`, which will import the specified tar file as a new distribution.

## Update and patch Linux distributions and packages

Using Linux configuration manager tools is strongly recommended for monitoring and managing Linux user space. There are a host of Linux configuration managers to choose from. Check out this [blog post](http://www.craigloewen.com/blog/2019/12/04/running-puppet-quickly-in-wsl2/) on how to install Puppet in WSL 2.

## Enterprise security and control options

Currently, WSL offers limited control mechanisms in regard to modifying the user experience in an Enterprise scenario. Enterprise features continue in development however, below are the areas of supported and unsupported features. To request a new feature not covered in this list, file an issue in our [GitHub repo](https://github.com/microsoft/WSL/issues?q=is%3Aissue+is%3Aopen+enterprise).

### Supported

* Sharing an approved image internally using `wsl --import` and `wsl --export`
* Creating your own WSL distro for your Enterprise using the [WSL Distro Launcher repo](https://github.com/microsoft/WSL-DistroLauncher)

Here's a list of features for which we don't yet have support for, but are investigating.

### Currently unsupported

Below is a list of commonly asked features that are currently unsupported within WSL. These requests are on our backlog and we are investigating ways to add them. 

* Synchronizing the user inside WSL with the Windows user on the host machine
* Managing updates and patching of the Linux distributions and packages using Windows tools
* Having Windows update also update WSL distro contents
* Controlling which distributions users in your Enterprise can access
* Running mandatory services (logging or monitoring) inside of WSL
* Monitoring Linux instances using Windows configuration manager tools such as SCCM or Intune
* McAfee support
