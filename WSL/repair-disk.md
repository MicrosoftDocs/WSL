---
title: Repair, reset, or uninstall a Linux distribution with WSL 2
description: How to repair a disk mount error, reset and unregister, or completely uninstall a Linux distribution with WSL 2.
ms.date: 12/14/2022
ms.topic: article
---

# Repair, reset, or uninstall a Linux distribution with WSL 2

WSL 2 uses a virtualization platform to install Linux distributions alongside the host Windows operating system. If there is a problem with an installed distribution, it is possible to repair, reset, or uninstall and reinstall the distribution. This how-to guide will cover the steps for each.

## Recover and repair a Linux distribution after a disk mount error

When WSL 2 installs a Linux distribution on your Windows machine, it is mounting the distribution as a Virtual Hard Disk (VHD) with it's own file system. Linux refers to these hard drives as "block devices" and you can view information about them by using the `lsblk` command.

To see what block devices are currently being used by WSL 2, open your distribution and enter the command: `lsblk`. (Or open PowerShell and enter the command: `wsl.exe lsblk`.) The result will look something like:

```bash
NAME MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
sda    8:0    0 363.1M  1 disk
sdb    8:16   0     8G  0 disk [SWAP]
sdc    8:32   0   1.5T  0 disk
sdd    8:48   0     1T  0 disk /mnt/wslg/distro
```

Information about the block device includes: NAME of the device (sd[a-z] refers to SCSI disk, with a letter designation for each disk being used). `sda` is always the system distribution. MAJ:MIN representing numbers used by the Linux kernel to internally identify the devices with the first number representing the device type (8 is used for Small Computer System Interface/SCSI disks, an alternative to USB). RM let's us know if the device is removable (1) or not (0). SIZE lets us know how much space the device is using. RO let's us know if the device is read-only (1) or not (0). TYPE refers to the device type (disk in this case, could also be something like lvm for a logical volume device). MOUNTPOINTS refers to the current directory on the files system where the block device is located (SWAP is for preconfigured inactive memory so no mountpoint).

If a WSL encounters an error while installing (mounting) a Linux distribution, it may mount the distribution as read-only (RO = 1) as a fallback. If that happens, the distribution may display the following error during startup:

```powershell
An error occurred mounting the distribution disk, it was mounted read-only as a fallback.
```

When a distribution is started as read-only, any attempts to write to the filesystem will fail with an error like this:

```bash
$ touch file
touch: cannot touch 'file': Read-only file system
```

To repair a disk mount error in WSL, and restore it back to a usable / writeable state again, you can use the `wsl --mount` command to re-mount the disk with the following steps:

1. Shutdown all WSL distributions by opening PowerShell and entering the command:

    ```powershell
    wsl.exe --shutdown
    ```

2. Open PowerShell as administrator (in an elevated command prompt) and enter the mount command, replacing `<path-to-ext4.vhdx>` with the path to the distribution's .vhdx file. For help locating this file, see [Locate VHD file and disk path for your Linux distribution](vhd-path.md).

    ```powershell
    wsl.exe --mount <path-to-ext4.vhdx> --vhd --bare
    ```

3. Use the `wsl.exe lsblk` command from PowerShell to identify the block device name for the distribution (sd[a-z]) and then enter the following command to repair the disk (replacing `<device>` with the correct block device name, like "sdc"). The `e2fsck` command checks ext4 file systems (the type used by distributions installed with WSL) for errors and repairs them accordingly.

    ```powershell
    wsl.exe sudo e2fsck -f /dev/<device>
    ```

4. Once the repair is complete, unmount the disk in PowerShell by entering:

    ```powershell
    wsl.exe --unmount
    ```

> [!WARNING]
> You can use the command: `sudo mount -o remount,rw /` to return a read-only distribution to a usable/writable state, but all changes will be in-memory and so will be lost when the distribution is restarted. We recommend using the steps listed above to mount and repair the disk instead.

**QUESTION (to-do)**: Should we mention using the Settings app "Repair" button found in: Settings > Apps > Installed apps > Ubuntu, under the **Reset** heading is a "Repair" button that says: "If this app isn't working right, we can try to repair it. The app's data won't be affected."

## Reset, unregister, or uninstall a Linux distribution

There are two ways to reset / unregister / uninstall a Linux distribution installed with WSL:

1. Use the Settings menu in Windows by going to: Settings > Apps (or Apps & features on W10). Select the name of the Linux distribution from your Installed Apps and go to the menu `...` to select "Advanced options". Scroll down to find the **Reset** button. Once reset, all data, settings, and software stored in the Linux distribution's file system will be lost.

2. Use the PowerShell command line to unregister a Linux distribution and reset it's defaults. Once unregistered, all data, settings, and software stored in the Linux distribution's file system will be lost. You can then reinstall the distribution in a completely reset, default state. To unregister a distribution, enter the following command, replacing `<DistributionName>` with the same of the distribution you want to unregister.

    ```powershell
    wsl --unregister <DistributionName>
    ```

Confirm what Linux distributions are currently installed by opening PowerShell and entering the command: `wsl.exe -l`
