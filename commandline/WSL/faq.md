---
title: Bash on Ubuntu on Windows - Frequently Asked Questions (FAQ)
description: Frequently Asked Questions
keywords: BashOnWindows, bash, wsl, windows, windowssubsystem, ubuntu
author: jackchammons
ms.date: 9/6/2016
ms.topic: article
ms.prod: windows-subsystem-for-linux
ms.service: windows-subsystem-for-linux
ms.assetid: 129101ed-b88a-43c2-b6a2-cd2c4ff6fee1
---

# Frequently Asked Questions

> **Important note**  
  This is the first release of this brand new technology and it is branded “beta” deliberately – it’s not yet complete! We know there are issues and incomplete features, you should expect some things to work and for many things to fail. But we appreciate you playing with this feature and helping us identify the issues we need to fix in order to deliver a great experience.


### What is BASH?
[BASH](https://en.wikipedia.org/wiki/Bash_%28Unix_shell%29) is a popular text-based shell and command-language. It is the default shell included within Ubuntu and other Linux distros, and in OSX. Users type commands into a shell to execute scripts and/or run commands and tools to accomplish many tasks.

### What is Windows Subsystem for Linux (WSL)?
The Windows Subsystem for Linux (WSL) is a new Windows 10 feature that enables you to run native Linux command-line tools directly on Windows, alongside your traditional Windows desktop and modern store apps.

See the [about page](./about.md) for more details.

### What is “Ubuntu on Windows”
When WSL is enabled (it’s an optional feature), we download a genuine Ubuntu user-mode image, created by Canonical. Our Bash.exe application, when started, then loads and runs the native Bash shell and Linux command-line tools from the Ubuntu image.

### Who is this for?
This is primarily a tool for developers -- especially web developers and those who work on or with open source projects.  This allows those who want/need to use Bash, common Linux tools (`sed`, `awk`, etc.) and many Linux-first tools (Ruby, Python, etc.) to use their toolchain on Windows.


### What can I do with WSL?
WSL provides an application called Bash.exe that, when started, opens a Windows console running the Bash shell. Using Bash, you can run command-line Linux tools and apps. For example, type `lsb_release -a` and hit enter; you’ll see details of the Linux distro currently running:

![](media/distro.png)

You can also access your local machine’s filesystem from within the Linux Bash shell – you’ll find your local drives mounted under the `/mnt` folder. For example, your `C:` drive is mounted under `/mnt/c`:  

![](media/ls.png)

### What is your high priority feature set for the Windows 10 Anniversary Edition?

The goal is to focus on core utilities and functionality.  For the Anniversary Edition we are prioritizing:

1. A Bash environment for developers to run standard GNU command-line tools such as grep, sed, awk
2. Provide access to the local hard drives through /mnt
3. Symlink support within the WSL environment
4. Linux user support
5. Provide the ability to run apt / apt-get for updates and package testing
6. Provide basic functionality for some languages:
  * NodeJS / npm
  * Python
  * Perl
  * Git
7. Command line editors/tools
  * vi
  * emacs
  * ssh

Additional languages and features may work in the Anniversary Edition but bugs in those areas will be a lower priority than the list above.

### How does this work?
Check out our [blog](https://blogs.msdn.microsoft.com/wsl/) where we go into detail about the underlying technology.

### Why would I use WSL rather than Linux in a VM?
WSL requires fewer resources (CPU, memory, and storage) than a full virtualized machine. WSL also allows you to run Linux command-line tools and apps alongside your Windows command-line, desktop and store apps, and to access your Windows files from within Linux. This enables you to use Windows apps and Linux command-line tools on the same set of files if you wish.

### Why would I use, for example, Ruby on Linux instead of on Windows?
Some cross-platform tools were built assuming that the environment in which they run behaves like Linux. For example, some tools assume that they are able to access very long file paths or that specific files/folders exist. This often causes problems on Windows which often behaves differently from Linux.

Many languages like Ruby and node are often ported to, and run great, on Windows. However, not all of the Ruby Gem or node/NPM library owners port their libraries to support Windows, and many have Linux-specific dependencies. This can often result in systems built using such tools and libraries suffering from build and sometimes runtime errors or unwanted behaviors on Windows.

These are just some of issues that caused many people to ask Microsoft to improve Windows’ command-line tools and what drove us to partner with Canonical to enable native Bash and Linux command-line tools to run on Windows.

### What does this mean for PowerShell?
While working with OSS projects, there are numerous scenarios where it’s immensely useful to drop into BASH from a PowerShell prompt.  Bash support is complementary and strengthens the value of the command-line on Windows, allowing PowerShell and the PowerShell community to leverage other popular technologies.

Read more on the PowerShell team blog -- [Bash for Windows: Why it’s awesome and what it means for PowerShell](https://blogs.msdn.microsoft.com/powershell/2016/04/01/bash-for-windows-why-its-awesome-and-what-it-means-for-powershell/)

### Can I run ALL Linux apps in WSL?
No! WSL is a tool aimed at enabling users who need them to run Bash and core Linux command-line tools on Windows.  

WSL does **not** aim to support GUI desktops or applications (e.g. Gnome, KDE, etc.)  

Also, even though you will be able to run many popular server applications (e.g. Redis), we do not recommend WSL for server scenarios – Microsoft offers a variety of solutions for running production Ubuntu workloads in Azure, Hyper-V, and Docker. 

### Why is this a beta release?
This is the first release of a brand new technology. There will be gaps. We know some of them, and we’re certain you will find many more.
Again, this is a beta release – expect things to fail. Some tools will crash and/or not run. But please be sure to let us know when you run into issues – we’re working hard to fix problems and dramatically improve WSL over time.

### How do I update Bash on Ubuntu on Windows?

There are two components of Bash on Ubuntu on Windows that can require updating. 

1. The Windows Subsystem for Linux
  
  Upgrading this portion of Bash on Ubuntu on Windows will enable any new fixes outlines in the [release notes](https://msdn.microsoft.com/en-us/commandline/wsl/release_notes). Ensure that you are subscribed to the Windows Insider Program and that your build is up to date. For finer grain control including resetting your Ubuntu instance check out the [command reference page](https://msdn.microsoft.com/en-us/commandline/wsl/reference).

2. The Ubuntu user binaries 

  Upgrading this portion of Bash on Ubuntu on Windows will install any updates to the Ubuntu user binaries including applications that you have installed via apt-get. To update run the following commands in Bash:
  
  1. `apt-get update`
  2. `apt-get upgrade`


### Can I run other Linux distros than Ubuntu?
Not at this time: We’re currently focused on delivering a great Ubuntu experience. We are keen to explore supporting other Linux distros in the future.

### What Windows SKUs is WSL included in?
Windows Subsystem for Linux is available only on the desktop version of Windows for the Anniversary and Creators update.

Beginning in the Fall Creators update WSL will be available on both the desktop and server SKUs of Windows.

### What processors do we support?
We only support x64 CPUs.

### How do I access my C drive?
Mount points for hard drives on the local machine are automatically created and provide easy access to the Windows filesystem. 
 
**/mnt/\<drive letter>/**
 
Example usage would be `cd /mnt/c` to access c:\

### How do I use a Windows file with a Linux app?

One of the benefits of WSL is being able to use the same file with both Windows and Linux apps or tools.

One of the main limitations of using WSL is that changing Linux files with a Windows app or tool is not allowed. See: [Do not change Linux files using Windows apps and tools](https://blogs.msdn.microsoft.com/commandline/2016/11/17/do-not-change-linux-files-using-windows-apps-and-tools/)

However changing Windows files with a Linux app or tools is allowed.

One way to use a Windows file with a Linux app is to use an absolute path, e.g. `/mnt/c/Users/<Windows User>/Documents/Projectes/<filename>`.

However not all Linux apps or tools can access a file using `/mnt`.

A solution is to create a [symbolic link](http://manpages.ubuntu.com/manpages/precise/man7/symlink.7.html).

Windows directory: `C:\Users\<Windows User>\Documents\Projects`    Note: This directory exist.

Linux directory:   `/home/<Linux User>/Projects`                   Note: This directory does not exist.

`ln -s "/mnt/c/Users/<Windows User>/Documents/Projects" /home/<Linux User>/Projects`

Now in WSL you can access the Windows directory as `/home/<Linux User>/Projects` or a specific file as `/home/<Linux User>/Projects/<filename>`, and if in WSL the current directory is `~` then `Projects/<filename>`.

###Is there any distinction between files in the Linux drive and the mounted Windows drives?
1. Files under the Linux root (i.e. “/”) are controlled by the subsystem.  This allows for Linux specific behavior including but is not limited to:
  * Files which contain invalid Windows filename characters
  * Symlinks created for non-admin users
  * Changing file attributes through chmod and chown
  * Support case sensitivity
2. Files in mounted drives are controlled by Windows and have the following behaviors:
  * Support case sensitivity
  * All permissions are set to best reflect the Windows permissions

### Why are there so many errors when I run apt-get upgrade?
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


### How do I fully uninstall WSL?
In Command Prompt:
  ``` CMD
  lxrun /uninstall /full
  ```

### Why does the ping command require Bash to be started with admin privileges?
This is a known issue that has to due with differences between the way the Linux and the Windows kernel handle the ICMP request that makes ping possible. We plan to address this in future releases.

### How do I run an OpenSSH server?
Similar to the previous question, WSL needs to be launched with admin privileges.

### Why do I get "Error: 0x80040306" when I try to install?
This has to do with the fact that we do not support legacy console.
To turn off legacy console:

1. Open cmd.exe
1. Right click title bar -> Properties -> Uncheck Use legacy console
1. Click OK

### Why do I get "Error: 0x80040154" when I run bash.exe after upgrading Windows?
The Windows Subsystem for Linux feature may be disabled during a Windows update. If this happens the Windows feature must be re-enabled. Instructions for enabling the Windows Subsystem for Linux can be found in the [Installation Guide](https://msdn.microsoft.com/en-us/commandline/wsl/install_guide#enable-the-windows-subsystem-for-linux-feature-guihttps://msdn.microsoft.com/en-us/commandline/wsl/install_guide#enable-the-windows-subsystem-for-linux-feature-gui).

### How do I change the display language of WSL?
WSL install will try to automatically change the Ubuntu locale to match the locale of your Windows install.  If you do not want this behavior you can run this command to change the Ubuntu locale after install completes.  You will have to relaunch bash.exe for this change to take effect.

The below example changes to locale to en-US:
``` BASH
sudo update-locale LANG=en_US.UTF8
```

### Why do I get a Permission Denied error when using ping?
Administrator privileges in Windows are required to run ping in WSL.  To run ping, run Bash on Ubuntu on Windows as an administrator, or run bash.exe from a CMD/PowerShell prompt with administrator privileges.

### Why do I not have internet access from WSL?
Some users have reported issues with specific firewall applications blocking internet access in WSL.  The firewalls reported are:

1. Kaspersky
1. AVG
1. Avast

In some cases turning off the firewall allows for access.  In some cases simply having the firewall installed looks to block access.

### Where can I provide feedback?

You can share feedback and ask questions through multiple channels:
Feedback and questions should be directed to:
* Our [GitHub issue tracker](https://github.com/Microsoft/BashOnWindows/issues)
* Our [command-line UserVoice portal](https://wpdev.uservoice.com/forums/266908-command-prompt/filters/top)
* Our [command-line team blog](https://blogs.msdn.microsoft.com/commandline/)
* Via Twitter. Please follow [@richturn_ms](https://twitter.com/richturn_MS) on Twitter to learn of news, updates, etc.
