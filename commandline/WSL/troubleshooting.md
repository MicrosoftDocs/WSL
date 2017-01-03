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


### Collecting logs on for WSL
1. Download these two .txt files and rename them .cmd
  https://github.com/Microsoft/BashOnWindows/files/288621/start_lxcore_trace.txt <br/>
  https://github.com/Microsoft/BashOnWindows/files/288622/stop_lxcore_trace.txt
2. Run start_lxcore_trace.cmd from an admin command prompt
3. Launch bash.exe (repro the scenario).
4. Run stop_lxcore_trace.cmd from an admin command prompt
6. You should now see three .etl files in the directory you ran the script from.
7. Post the files with your GitHub post to our [issue page](https://github.com/Microsoft/BashOnWindows/issues). 
