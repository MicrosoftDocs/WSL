---
title: Recover a distribution with a corrupted or full disk
description: Learn the steps to recover a WSL distribution with a full or read-only disk.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem, distro, full, readonly
ms.date: 12/07/2022
ms.topic: article
---

If a WSL distribution encouters an error while mounting its disk, it can be mounted as read-only as a fallback.
If that happens, the distribution can display the following error during startup:

```powershell
$ wsl
An error occurred mounting the distribution disk, it was mounted read-only as a fallback.
See recovery instructions on: https://aka.ms/wsldiskmountrecovery
```

When a distribution is started as read-only, any attemps to write the filesystem will fail with an error looking like:

```bash
$ touch file
touch: cannot touch 'file': Read-only file system
```

Note:
> [!NOTE]
> You can run: `sudo mount -o remount,rw /` to make the distribution writable, but all changes will be in-memory (**and so will be lost when the distribution is restarted**).
>


# 1) Getting the distribution disk path

To figure out where the disk is stored, run the following command in powershell (replace <distribution-name> with the actual distribution name):

```powershell
(Get-ChildItem -Path HKCU:\Software\Microsoft\Windows\CurrentVersion\Lxss | Where-Object { $_.GetValue("DistributionName") -eq '<distribution-name>' }).GetValue("BasePath") + "\ext4.vhdx"
```

This will display a path looking like:
```powershell
C:\Users\User\AppData\Local\Packages\TheDebianProject.DebianGNULinux_76v4gfsz19hv4\LocalState\ext4.vhdx
```

# 2) Recovering the disk

The first step to recover the distribution is to find out why the disk failed to mount normally. The two most common causes are:

- The disk needs to be repaired (can happen if WSL was terminated improperly)
- The disk is full

To decide between those, run the following command (replace <distribution-name> with the actual distribution name):

```powershell
$ wsl.exe --system -d <distribution-name> df -h /mnt/wslg/distro
```

And look at the `Use%` column. If you see `100%`, then the disk is full.

Sample output:

```bash
Filesystem      Size  Used Avail Use% Mounted on
/dev/sdc        251G   251G    0 100% /mnt/wslg/distro
```

If the disk is full, then follow [this tutorial](vhd-size.md) to expand it.

# 3) Mounting the disk with wsl --mount to repair it

This step will repair the disk so it can be mounted properly again.

First run the following command to terminate all WSL distributions.

```powershell
wsl.exe --shutdown
```

Then use the following command to mount the disk in WSL2 (run in an elevated command prompt):

```powershell
wsl.exe --mount <path-to-ext4.vhdx> --vhd --bare
```

Once mounted, use **another WSL2 distribution** to access the disk:

```bash
# First use lsblk to get the block device name:

$ lsblk
NAME MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
sda    8:0    0 363.1M  1 disk
sdb    8:16   0     8G  0 disk [SWAP]
sdc    8:32   0   1.5T  0 disk
sdd    8:48   0     1T  0 disk /mnt/wslg/distro

# Here the block device is 'sdc'. Tips to find the block device:
# - It cannot be sda (that's always the system distribution)
# - It cannot be marked as [SWAP]
# - It cannot have a mountpoint

# Once the block device is known, run the following command to repair the disk (replace <device> with the correct block device)
$ sudo e2fsck -f /dev/<device>
```

Once done, run the following command to detach the disk:

```powershell
wsl.exe --unmount
```

The distribution disk is now repaired.