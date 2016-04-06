---
author: jackchammons
---

# Installation Guide

> **Important note**  
  This is the first release of this brand new technology and it is branded “beta” deliberately – it’s not yet complete! We know there are issues and incomplete features, you should expect some things to work and for many things to fail. But we appreciate you playing with this feature and helping us identify the issues we need to fix in order to deliver a great experience.

##Prerequisites
  1. Windows 10 Anniversay Edition - Build 14316  
      Available as of 4/6/2016 through the [Insider Fast Ring](http://insider.windows.com/)
2. x64-based processor

You can find the system architecture and build number by opening:  
Settings -> System -> About

Look for the **OS Build** and **System Type** fields.  

![](media/system.png) 

If your build is below 14316, try checking for updates.  In the "Advanced Options" menu, make sure you are running Fast Track insider preview builds.


## Installation

### Turn on Developer Mode
1. Open Settings -> Update and Security -> For developers
2. Select the Developer Mode radio button  
  ![](media/updateAndSecurity.png)

### Turn on Developer Mode

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

### Run “bash” at a command prompt
1. Open a command prompt
1. Run `bash` 
  
  ![](media/bashShellInstall.png)
  
  This will download the Ubuntu user-mode image and create a Bash on Ubuntu on Windows shortcut.  To launch, either run bash at a command line or use the shortcut.

