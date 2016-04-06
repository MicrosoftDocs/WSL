---
author: jackchammons
---

# Installation Guide

## Requirements

1. Part of the Windows Insiders Program -- [learn more](https://insider.windows.com/)  
2. x64-based processor
3. Windows build 14316+

You can find the system architecture and build number by opening:  
Settings -> System -> About

Look for the **OS Build** and **System Type** fields.  

![](media/system.png) 

If your build is below 14316, try checking for updates.  In the "Advanced Options" menu, make sure you are running Fast Track insider preview builds.


## Installation

### Turn on Developer Mode
1. Open Settings
  1. Open Update and Security
  1. Select For developers
  1. Select the Developer Mode radio button

  ![](media/updateAndSecurity.png)

### Enable the Windows Subsystem for Linux feature
  1. Search for "Turn Windows features on or off"
  1. Select **Windows Subsystem for Linux (beta)**
  1. Click OK (This will require a reboot)

  ![](media/windowsFeatures.png)

### Run “bash” at a command prompt
  1. Open a command prompt
  1. Type bash
  
  ![](media/bashShellInstall.png)
  
  This will download the Ubuntu user-mode image and create a Bash on Ubuntu on Windows shortcut.  To launch, either run bash at a command line or use the shortcut.

