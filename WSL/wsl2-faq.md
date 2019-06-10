---
title: WSL 2 Frequently Asked Questions
description: Frequently Asked Questions about the Windows Subsystem for Linux 2
keywords: BashOnWindows, bash, wsl, wsl2, windows, windows subsystem for linux, windowssubsystem, ubuntu, debian, suse, windows 10, install
author: crloewen
ms.author: crloewen
ms.date: 05/30/2019
ms.topic: article
ms.assetid: 7afaeacf-435a-4e58-bff0-a9f0d75b8a51
ms.custom: seodec18
---

# Does WSL 2 use Hyper-V? Will it be available on Windows 10 Home?

WSL 2 will be available on all SKUs where WSL is currently available, including Windows 10 Home.

The newest version of WSL uses Hyper-V architecture to enable its virtualization. This architecture will be available in an optional component that is a subset of the Hyper-V feature. This optional component will be available on all SKUs. You can expect to see more details about this experience soon as we get closer to the WSL 2 release.

# What will happen to WSL 1? Will it be abandoned?

We currently have no plans to deprecate WSL 1. You can run WSL 1 and WSL 2 distros side by side, and can upgrade and downgrade any distro at any time. Adding WSL 2 as a new architecture presents a better platform for the WSL team to deliver features that make WSL an amazing way to run a Linux environment in Windows.

# Will I be able to run WSL 2 and other 3rd party virtualization tools such as VMware, or Virtual Box?

Some 3rd party applications cannot work when Hyper-V is in use, which means they will not be able to run when WSL 2 is enabled. Unfortunately, this does include VMware, and versions of Virtual Box before Virtual Box 6 (Virtual Box 6.0.0 released in December 2018 [now supports Hyper-V as a fallback execution core on a Windows host][1]!)

We are investigating ways to help resolve this issue. For example, we expose a set of APIs called [Hypervisor Platform][2] that third-party virtualization providers can use to make their software compatible with Hyper-V’s. This lets applications use the Hyper-V architecture for their emulation such as [the Google Android Emulator][3], and Virtual Box 6 and above which are both now compatible with Hyper-V.

# Can I access the GPU in WSL 2? Are there plans to increase hardware support?

In initial releases of WSL 2 hardware access support will be limited, e.g: you will be unable to access the GPU, serial or USBs . However, adding better device support is high on our backlog, as this opens many more use cases for developers that wish to interact with these devices. In the meantime, you can always use WSL 1 which has serial port and USB access. Please stay tuned to this blog and WSL team members on Twitter to stay informed about the latest features coming to insider builds and reach out to give us feedback on what devices you’d like to interact with!

# Will WSL 2 be able to use networking applications?

Yes, in general networking applications will be faster and work better since we have full system call compatibility. However, the new architecture uses virtualized networking components. This means that in initial preview builds WSL 2 will behave more similarly to a virtual machine, e.g: WSL 2 will have a different IP address than the host machine. We are committed to making WSL 2 feel the same as WSL 1, and that includes improving our networking story. We expect to add improvements as quickly as we are able to, such as accessing all networking apps from Linux or Windows using localhost. We will be posting more details about our networking story and improvements as we approach the release of WSL 2.

# Can I run WSL 2 in a virtual machine?

Yes! You need to make sure that the virtual machine has nested virtualization enabled. This can be enabled in Hyper-V by running the following command in a PowerShell window with Administrator privileges:

`Set-VMProcessor -VMName <VMName> -ExposeVirtualizationExtensions $true`

Make sure to replace '<VMName>' with the name of your virtual machine.

 [1]: https://www.virtualbox.org/wiki/Changelog-6.0
 [2]: https://docs.microsoft.com/en-us/virtualization/api/
 [3]: https://devblogs.microsoft.com/visualstudio/hyper-v-android-emulator-support/