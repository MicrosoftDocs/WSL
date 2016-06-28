---
author: jackchammons
---

# Installation Guide

> **Important note**  
> This is the first release of Bash on Windows and it is branded "beta" deliberately - it's not yet complete! 
> You should expect many things to work and for some things to fail! 
> We greatly appreciate you using Bash on Windows and helping us identify the issues we need to fix in order to deliver a great experience.

##Prerequisites
In order to run Bash on Windows, please be sure to check the following prerequisites:

1. Your PC must have an AMD/Intel x64 compatible CPU
2. You must be a member of the (free) [Windows Insider Program](http://insider.windows.com/) (Preferably Fast-Ring)
3. Your PC must be running a 64-bit version of **Windows 10 Anniversary Update version 16xx / build 14316 or later**
    
> You can find your PC's CPU architecture and Windows version/build number by opening 
> Settings -> System -> About. 
> Look for the **OS Build** and **System Type** fields.  

![](media/system.png) 

If your build is below 14316, try checking for updates.  In the "Advanced Options" menu, make sure you are running Fast Ring insider preview builds.

## Installation

### Turn on Developer Mode
1. Open Settings -> Update and Security -> For developers
2. Select the Developer Mode radio button  
  ![](media/updateAndSecurity.png)

### Enable the Windows Subsystem for Linux feature
1. Search for "Turn Windows features on or off"  
1. Select **Windows Subsystem for Linux (beta)**  
  ![](media/windowsFeatures.png)
  
1. Click OK
1. Reboot

Alternately:

Open a PowerShell prompt as administrator and run:

``` PowerShell
Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```

### Run Bash on Windows
1. Open a command prompt
1. Run `bash` 
  
  ![](media/bashShellInstall.png)
  
  After you have accepted the License prompt, This will download the Ubuntu user-mode image and create a Bash on Ubuntu on Windows shortcut.  To launch, either run bash at a command line or use the shortcut.

