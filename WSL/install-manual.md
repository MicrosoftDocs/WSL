---
title: Manually download Windows Subsystem for Linux (WSL) Distros
description: Instructions for how to manually download WSL distros
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, WSL, windowssubsystem, distro, ubuntu, openSUSE, SLES
author: taraj
ms.author: taraj
ms.date: 07/24/2018
ms.topic: article
ms.prod: windows-subsystem-for-linux
ms.service: windows-subsystem-for-linux
ms.assetid: 9281ffa2-4fa9-4078-bf6f-b51c967617e3
---
# Manually download WSL distro packages

There are several scenarios in which you may not be able (or want) to, install WSL Linux distros via the Windows Store. Specifically, you may be running a Windows Server or Long-Term Servicing (LTSB/LTSC) desktop OS SKU that doesn't support Windows Store, or your corporate network policies and/or admins to not permit Windows Store usage in your environment.

In these cases, while WSL itself is available, how do you download and install Linux distros in WSL if you can't access the store?

> Note: **Command-Line shell environments including Cmd, PowerShell, and Linux/WSL distros are not permitted to run on Windows 10 S Mode**. This restriction exists in order to ensure the integrity and safety goals that S Mode delivers: Read [this post](https://blogs.msdn.microsoft.com/commandline/2017/05/18/will-linux-distros-run-on-windows-10-s/) for more information.

# Downloading distros

If the Windows Store app is not available, you can download and manually install Linux distros by clicking these links:
* [Ubuntu 18.04](https://aka.ms/wsl-ubuntu-1804)
* [Ubuntu 18.04 ARM](https://aka.ms/wsl-ubuntu-1804-arm)
* [Ubuntu 16.04](https://aka.ms/wsl-ubuntu-1604)
* [Debian GNU/Linux](https://aka.ms/wsl-debian-gnulinux)
* [OpenSUSE](https://aka.ms/wsl-opensuse-42)
* [SLES](https://aka.ms/wsl-sles-12)

This will cause the `<distro>.appx` packages to download to a folder of your choosing. Follow the [installation instructions](#installing_your_distro) to install your downloaded distro(s).

## Downloading distros via the Command-Line
If you prefer, you can also download your preferred distro(s) via the Command-Line:

 ### Download using PowerShell
 To download distros using PowerShell, use the [Invoke-WebRequest](https://msdn.microsoft.com/powershell/reference/5.1/microsoft.powershell.utility/invoke-webrequest) cmdlet. Here's a sample instruction to download Ubuntu 16.04.

``` PowerShell
Invoke-WebRequest -Uri https://aka.ms/wsl-ubuntu-1604 -OutFile Ubuntu.appx -UseBasicParsing
```

> [!TIP]
> If the download is taking a long time, turn off the progress bar by setting `$ProgressPreference = 'SilentlyContinue'`

### Download using curl
Windows 10 Spring 2018 Update (or later) includes the popular [curl command-line utility](https://curl.haxx.se/) with which you can invoke web requests (i.e. HTTP GET, POST, PUT, etc. commands) from the command-line. You can use `curl.exe` to download the above distro's:

``` cmd
curl.exe -L -o ubuntu-1604.appx https://aka.ms/wsl-ubuntu-1604
```

In the above example, `curl.exe` is executed (not just `curl`) to ensure that, in PowerShell, the real curl executable is invoked, not the PowerShell curl alias for [Invoke-WebRequest](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.utility/invoke-webrequest?view=powershell-6)

> Note: Using `curl` might be preferable if you have to invoke/script download steps using Cmd shell and/or `.bat` / `.cmd` scripts.

# Installing your distro
For instructions on how to install your downloaded distro(s), please refer to the [Windows Desktop](install-win10.md) or [Windows Server](install-on-server.md) installation instructions.
