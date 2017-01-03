---
title: Bash on Ubuntu on Windows - Troubleshooting
description: Troubleshooting Bash on Ubuntu on Windows
keywords: BashOnWindows, bash, wsl, windows, windowssubsystem, ubuntu
author: jackchammons
ms.date: 1/2/2017
ms.topic: article
ms.prod: windows-subsystem-for-linux
ms.service: windows-subsystem-for-linux
ms.assetid: 6753f1b2-200e-49cc-93a5-4323e1117246
---

# Troubleshooting

> **Important note**  
  This is the first release of this brand new technology and it is branded “beta” deliberately – it’s not yet complete! We know there are issues and incomplete features, you should expect some things to work and for many things to fail. But we appreciate you playing with this feature and helping us identify the issues we need to fix in order to deliver a great experience.


### Collecting logs for WSL
1. Download these two .txt files and rename them .cmd
  https://github.com/Microsoft/BashOnWindows/files/288621/start_lxcore_trace.txt <br/>
  https://github.com/Microsoft/BashOnWindows/files/288622/stop_lxcore_trace.txt
2. Run start_lxcore_trace.cmd from an admin command prompt
3. Launch bash.exe (repro the scenario).
4. Run stop_lxcore_trace.cmd from an admin command prompt
6. You should now see three .etl files in the directory you ran the script from.
7. Post the files with your GitHub post to our [issue page](https://github.com/Microsoft/BashOnWindows/issues). 

### Updating Bash on Ubuntu on Windows

There are two components of Bash on Ubuntu on Windows that can require updating. 

1. The Windows Subsystem for Linux
  
  Upgrading this portion of Bash on Ubuntu on Windows will enable any new fixes outlines in the [release notes](https://msdn.microsoft.com/en-us/commandline/wsl/release_notes). Ensure that you are subscribed to the Windows Insider Program and that your build is up to date. For finer grain control including resetting your Ubuntu instance check out the [command reference page](https://msdn.microsoft.com/en-us/commandline/wsl/reference).

2. The Ubuntu user binaries 

  Upgrading this portion of Bash on Ubuntu on Windows will install any updates to the Ubuntu user binaries including applications that you have installed via apt-get. To update run the following commands in Bash:
  
  1. `apt-get update`
  2. `apt-get upgrade`
  
### Apt-get upgrade errors
Some packages use features that we haven't implemented yet. `udev`, for example, isn't supported yet and causes several `apt-get upgrade` errors.

To fix issues related to `udev`, follow the following steps:

1. Write the following to `/usr/sbin/policy-rc.d` and save your changes.
  
  ``` BASH
  #!/bin/sh
  exit 101
  ```
  
2. Add execute permissions to `/usr/sbin/policy-rc.d`
  ``` BASH
  chmod +x /usr/sbin/policy-rc.d
  ```
  
2. Run the following commands
  ``` BASH
  dpkg-divert --local --rename --add /sbin/initctl
  ln -s /bin/true /sbin/initctl
  ```
  
### "Error: 0x80040306" on installation
This has to do with the fact that we do not support legacy console.
To turn off legacy console:

1. Open cmd.exe
1. Right click title bar -> Properties -> Uncheck Use legacy console
1. Click OK

### "Error: 0x80040154" after Windows update
The Windows Subsystem for Linux feature may be disabled during a Windows update. If this happens the Windows feature must be re-enabled. Instructions for enabling the Windows Subsystem for Linux can be found in the [Installation Guide](https://msdn.microsoft.com/en-us/commandline/wsl/install_guide#enable-the-windows-subsystem-for-linux-feature-guihttps://msdn.microsoft.com/en-us/commandline/wsl/install_guide#enable-the-windows-subsystem-for-linux-feature-gui).

### Changing the display language
WSL install will try to automatically change the Ubuntu locale to match the locale of your Windows install.  If you do not want this behavior you can run this command to change the Ubuntu locale after install completes.  You will have to relaunch bash.exe for this change to take effect.

The below example changes to locale to en-US:
``` BASH
sudo update-locale LANG=en_US.UTF8
```

### No internet access in WSL
Some users have reported issues with specific firewall applications blocking internet access in WSL.  The firewalls reported are:

1. Kaspersky
1. AVG
1. Avast

In some cases turning off the firewall allows for access.  In some cases simply having the firewall installed looks to block access.

### Permission Denied error when using ping
In the Anniversary Update administrator privileges in Windows are required to run ping in WSL.  To run ping, run Bash on Ubuntu on Windows as an administrator, or run bash.exe from a CMD/PowerShell prompt with administrator privileges.
