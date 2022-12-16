---
title: Display available disk space
description: How to display the amount of disk space used by and available for Linux distributions installed with WSL 2.
ms.date: 12/14/2022
ms.topic: article
---

# Display disk space for Linux distributions installed with WSL 2

There are a couple of ways to assess disk space in WSL that include:

1. **Total usage**: This represents the space being used by a Linux distribution installed via WSL and the total size of the `LocalApps` directory where the distribution is stored. The "Total usage" size can be viewed by opening Settings on your Windows device. Go to **Settings > Apps > Installed apps** and search the list of installed apps by entering the name of the Linux distribution you want to view, for example "Ubuntu" or "Debian". By selecting `...`, you can choose **Advanced options** to view the total disk space used, amount of data stored, and version number of your installed distribution. You can also **Uninstall** the distribution.

2. **Amount of disk space on the Linux distribution's file system**: WSL 2 uses a Virtual Hard Disk (VHD) to store your Linux files (represented on your Windows drive as a *.vhdx* file). This VHD automatically resizes to meet your storage needs, with an initial maximum size of 256GB. If your distribution grows in size to be greater than 256GB, you will see errors stating that you've run out of disk space. To check the amount of space currently available in your distribution, you can use the Linux `Df` command. Open the PowerShell command line and run the following command (replace `<distribution-name>` with the actual distribution name):

```powershell
wsl.exe --system -d <distribution-name> df -h /mnt/wslg/distro
```

Output will include:

- **Filesystem**: Identifier for the file system
- **Size**: Total size of the disk (the maximum amount of space allocated to the VHD)
- **Used**: Amount of space currently being used in the VHD
- **Avail**: Amount of space left in the VHD (Allocated size minus amount used)
- **Use%**: Percentage of disk space remaining (Used / Allocated size)
- **Mounted on**: Directory path where the disk is mounted

You can expand the amount of space available in the VHD for your installed Linux distribution by following the guidance on how to [Expand the size of your WSL 2 Virtual Hard Disk](./vhd-size.md).
