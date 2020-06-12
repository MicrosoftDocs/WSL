---
title: Manually download Windows Subsystem for Linux (WSL) Distros
description: Instructions for how to manually download Windows Subsystem for Linux distributions.
keywords: wsl, windows subsystem for linux, manual install, manually install, microsoft store, windows 10s, curl, Add-AppxPackage, Long-Term Servicing, LTSC
ms.date: 05/28/2020
ms.topic: article
ms.localizationpriority: medium
---

# Manually download Windows Subsystem for Linux distro packages

There are several scenarios in which you may not be able (or want) to, install WSL Linux distros via the Microsoft Store. Specifically, you may be running a Windows Server or Long-Term Servicing (LTSC) desktop OS SKU that doesn't support Microsoft Store, or your corporate network policies and/or admins to not permit Microsoft Store usage in your environment.

In these cases, while WSL itself is available, how do you download and install Linux distros in WSL if you can't access the store?

> Note: **Command-line shell environments including Cmd, PowerShell, and Linux/WSL distros are not permitted to run on Windows 10 S Mode**. This restriction exists in order to ensure the integrity and safety goals that S Mode delivers: Read [this post](https://blogs.msdn.microsoft.com/commandline/2017/05/18/will-linux-distros-run-on-windows-10-s/) for more information.

## Downloading distros

If the Microsoft Store app is not available, you can download and manually install Linux distros by clicking these links:
* [Ubuntu 20.04](https://aka.ms/wslubuntu2004)
* [Ubuntu 20.04 ARM](https://aka.ms/wslubuntu2004arm)
* [Ubuntu 18.04](https://aka.ms/wsl-ubuntu-1804)
* [Ubuntu 18.04 ARM](https://aka.ms/wsl-ubuntu-1804-arm)
* [Ubuntu 16.04](https://aka.ms/wsl-ubuntu-1604)
* [Debian GNU/Linux](https://aka.ms/wsl-debian-gnulinux)
* [Kali Linux](https://aka.ms/wsl-kali-linux-new)
* [OpenSUSE Leap 42](https://aka.ms/wsl-opensuse-42)
* [SUSE Linux Enterprise Server 12](https://aka.ms/wsl-sles-12)
* [Fedora Remix for WSL](https://github.com/WhitewaterFoundry/WSLFedoraRemix/releases/)

This will cause the `<distro>.appx` packages to download to a folder of your choosing. Follow the [installation instructions](#installing-your-distro) to install your downloaded distro(s).

## Downloading distros via the command line
If you prefer, you can also download your preferred distro(s) via the command line:

 ### Download using PowerShell
 To download distros using PowerShell, use the [Invoke-WebRequest](https://docs.microsoft.com/powershell/module/microsoft.powershell.utility/invoke-webrequest?view=powershell-5.1) cmdlet. Here's a sample instruction to download Ubuntu 16.04.

```powershell
Invoke-WebRequest -Uri https://aka.ms/wsl-ubuntu-1604 -OutFile Ubuntu.appx -UseBasicParsing
```

> [!TIP]
> If the download is taking a long time, turn off the progress bar by setting `$ProgressPreference = 'SilentlyContinue'`

### Download using curl
Windows 10 Spring 2018 Update (or later) includes the popular [curl command-line utility](https://curl.haxx.se/) with which you can invoke web requests (i.e. HTTP GET, POST, PUT, etc. commands) from the command line. You can use `curl.exe` to download the above distros:

```console
curl.exe -L -o ubuntu-1604.appx https://aka.ms/wsl-ubuntu-1604
```

In the above example, `curl.exe` is executed (not just `curl`) to ensure that, in PowerShell, the real curl executable is invoked, not the PowerShell curl alias for [Invoke-WebRequest](https://docs.microsoft.com/powershell/module/microsoft.powershell.utility/invoke-webrequest?view=powershell-6)

> Note: Using `curl` might be preferable if you have to invoke/script download steps using Cmd shell and/or `.bat` / `.cmd` scripts.

## Installing your distro
If you're using Windows 10 you can install your distro with PowerShell. Simply navigate to folder containing the distro downloaded from above, and in that directory run the following command where `app_name` is the name of your distro .appx file.  
```Powershell
Add-AppxPackage .\app_name.appx
```

If you are using Windows server you can find the install instructions on the [Windows Server](install-on-server.md) documentation page.

Once your distribution is installed, follow the normal instructions to [update to WSL 2](./install-win10.md#update-to-wsl-2) or [create a new user account and password](./user-support.md).
