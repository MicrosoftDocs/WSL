---
title: Set up Windows Subsystem for Linux for your company
description: Resources and instructions on how to best use the Windows Subsystem for Linux in an Enterprise environment.
ms.date: 08/16/2024
ms.topic: article
---

# Enterprise environment: Set up Windows Subsystem for Linux for your company

This guidance is intended for IT Administrators or Security Analysts responsible for setting up enterprise work environments with the goal of distributing software across multiple machines and maintaining a consistent level of security settings across those work machines. 

Many companies use [Microsoft Intune](/mem/intune/) and [Microsoft Defender](/microsoft-365/security/defender/) to manage these security settings. However, setting up WSL and accessing Linux distributions in this context requires some specific setup. This guidance provides what you need to know to enable the secure use of Linux with WSL in an enterprise environment.

## Recommended Enterprise set up with Microsoft Defender for Endpoint, Intune, and Advanced Networking Controls

There are a variety of ways to set up a secure enterprise environment, but we recommend the following for setting up a secure environment that utilizes WSL.

### Pre-requisites

To get started ensure that all enterprise devices have the following minimum versions installed:

* Windows 10 22H2 or higher, or Windows 11 22H2 or higher
    * Advanced networking features are only available on Windows 11 22H2 or higher.
* [WSL version 2.0.9](https://github.com/microsoft/WSL/releases) or higher
    - You can check the WSL version by running `wsl --version`.

### Enable Microsoft Defender for Endpoint (MDE) integration

[Microsoft Defender for Endpoint](/microsoft-365/security/defender-endpoint/microsoft-defender-endpoint) is an enterprise endpoint security platform designed to help enterprise networks prevent, detect, investigate, and respond to advanced threats. MDE now integrates with WSL as a [WSL plugin](./wsl-plugins.md), which allows security teams to see and continuously monitor for security events in all running WSL distributions with Defender for Endpoint while minimally impacting performance on developer workloads. 

See [Microsoft Defender for Endpoint plug-in for WSL](/microsoft-365/security/defender-endpoint/mde-plugin-wsl) to learn more about how to get started.

### Configure recommended settings with Intune

[Microsoft Intune](/mem/intune/fundamentals/what-is-intune) is a cloud-based endpoint management solution. It manages user access to organizational resources and simplifies app and device management across your many devices, including mobile devices, desktop computers, and virtual endpoints. You can use Microsoft Intune to manage devices inside of your organization, which now also includes managing access to WSL and its key security settings. 

See [Intune settings for WSL](./intune.md) for guidance on using InTune to manage WSL as a Windows component and the recommended settings. 

### Use advanced networking features and controls

Starting from Windows 11 22H2 and WSL 2.0.9 or later, Windows firewall rules will automatically apply to WSL. This ensures that the firewall rules set on the Windows host will automatically apply to all WSL distributions by default. For guidance on customizing the firewall settings for WSL, visit [Configure Hyper-V firewall](/windows/security/operating-system-security/network-security/windows-firewall/hyper-v-firewall).

Additionally, we recommend configuring [settings under `[wsl2]` in the `.wslconfig` file](/windows/wsl/wsl-config#configuration-setting-for-wslconfig) to suit your specific Enterprise scenario.

#### Mirrored mode networking

`networkingMode=mirrored` enables mirrored mode networking. This new networking mode improves compatibility with complex networking environments, especially VPNs and more, as well as adding support for new networking features unavailable in the default NAT mode like IPv6.

#### DNS Tunneling

`dnsTunneling=true` changes how WSL obtains DNS information. This setting improves compatibility in different networking environments, and makes use of virtualization features to obtain DNS information rather than a networking packet. It's recommended to turn this on if experiencing any connectivity issues, and can be especially helpful when using VPNs, advanced firewall settings, and more. 

#### Auto proxy

`autoProxy=true` enforces WSL to use Windows' HTTP proxy information. We recommend turning this setting on when using a proxy on Windows, as it will make that proxy automatically apply to your WSL distributions.

## Creating a custom WSL image

What is commonly referred to as an "image", is simply a snapshot of your software and its components saved to a file. In the case of the Windows Subsystem for Linux, your image would consist of the subsystem, its distributions, and whatever software and packages are installed on the distribution.

To begin creating your WSL image, first [install the Windows Subsystem for Linux](./install.md).

Once installed, use the [Microsoft Store](https://apps.microsoft.com/search?query=wsl&hl) to download and install the Linux distribution that’s right for you.

### Exporting your WSL image

Export your custom WSL image by running wsl --export `<Distro> <FileName>`, which will wrap your image in a tar file and make it ready for distribution on to other machines. You can [create custom distributions including CentOS, RedHat and more using the custom distro guide](./use-custom-distro.md).

## Distributing your WSL image

Distribute the WSL image from a share or storage device by running wsl --import `<Distro> <InstallLocation> <FileName>`, which will import the specified tar file as a new distribution.

## Update and patch Linux distributions and packages

Using Linux configuration manager tools is strongly recommended for monitoring and managing Linux user space. There are a host of Linux configuration managers to choose from. See this blog post on [Running Puppet quickly in WSL 2](http://www.craigloewen.com/blog/2019/12/04/running-puppet-quickly-in-wsl2/).

## Windows file system access

When a Linux binary inside of WSL accesses a Windows file, it does so with the user permissions of the Windows user that ran `wsl.exe`. So even though a Linux user has root access inside of WSL, they cannot do Windows administrator level operations on Windows if the Windows user does not have those permission. With regards to Windows file and Windows executable access from WSL, running a shell like `bash` has the same security level permissions as running `powershell` from Windows as that user. 

### Supported

* Sharing an approved image internally using `wsl --import` and `wsl --export`
* Creating your own WSL distro for your Enterprise using the [WSL Distro Launcher repo](https://github.com/microsoft/WSL-DistroLauncher)
* Monitor security events inside of WSL distros using Microsoft Defender for Endpoint (MDE)
* Use firewall settings to control networking in WSL (Includes syncing Windows firewall settings to WSL)
* Control access to WSL and its key security settings with Intune or group policy

Here's a list of features for which we don't yet have support for, but are investigating.

### Currently unsupported

Below is a list of commonly asked features that are currently unsupported within WSL. These requests are on our backlog and we are investigating ways to add them. 

* Managing updates and patching of the Linux distributions and packages using Windows tools
* Having Windows update also update WSL distro contents
* Controlling which distributions users in your Enterprise can access
* Controlling root access for users
