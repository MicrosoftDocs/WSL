---
title: Locate VHD file and disk path for your Linux distribution
description: How to locate VHD file for your WSL 2 Linux distribution.
ms.date: 12/14/2022
ms.topic: article
---

# Locate VHD file and disk path for your Linux distribution

WSL 2 uses a Virtual Hard Disk (VHD) to store your Linux files. In WSL 2, a VHD is represented on your Windows hard drive as a *.vhdx* file. To locate this *.vhdx* file, go to the directory path `%LocalAppData%\Packages\`. Each Linux distribution that you have installed includes a subfolder specific to that distribution.

For the default Ubuntu distribution, this directory will look something like `CanonicalGroupLimited.UbuntuonWindows_79rhkp1fndgsc`. Inside that directory will be a `LocalState` folder with the `ext4.vhdx` file that stores your data.

The VHD used by WSL 2 utilizes a ext4 format for the file system, not NTFS, so Windows will not natively read this format outside of the WSL environment. (Tools like Disk Manager or diskpart installed on Windows NTFS file system will not work.)

If you are having trouble locating the disk path where the *.vhdx* file is stored for a particular Linux distribution, you can use PowerShell to help you find it. Replace `<distribution-name>` with the actual distribution name and run the following command:

```powershell
(Get-ChildItem -Path HKCU:\Software\Microsoft\Windows\CurrentVersion\Lxss | Where-Object { $_.GetValue("DistributionName") -eq '<distribution-name>' }).GetValue("BasePath") + "\ext4.vhdx"
```

The result will display a path looking something like:

```powershell
C:\Users\User\AppData\Local\Packages\TheDebianProject.DebianGNULinux_76v4gfsz19hv4\LocalState\ext4.vhdx
```
