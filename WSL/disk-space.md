---
title: How to manage WSL disk space
description: Learn how to check the amount of disk space available, expand the size of the Virtual Hard Disk (VHD), repair a VHD mounting or read-only error, and locate the .vhdx file and disk path for Linux distributions installed with WSL 2.
ms.date: 11/10/2023
ms.topic: article
---

# How to manage WSL disk space

This guide covers how to manage the disk space used by Linux distributions installed using WSL 2, including:

- [How to check the amount of disk space available in the VHD](#how-to-check-your-available-disk-space)
- [How to expand the size of the VHD](#how-to-expand-the-size-of-your-wsl-2-virtual-hard-disk)
- [How to repair the VHD if an error occurs](#how-to-repair-a-vhd-mounting-error)
- [How to locate the .vhdx file and disk path for any installed Linux distributions](#how-to-locate-the-vhdx-file-and-disk-path-for-your-linux-distribution)

Windows Subsystem for Linux (WSL 2) uses a virtualization platform to install Linux distributions alongside the host Windows operating system, creating a Virtual Hard Disk (VHD) to store files for each of the Linux distributions that you install. These VHDs use the [ext4 file system type](https://opensource.com/article/17/5/introduction-ext4-filesystem) and are represented on your Windows hard drive as an *ext4.vhdx* file.

WSL 2 automatically resizes these VHD files to meet storage needs. By default each VHD file used by WSL 2 is initially allocated a 1TB maximum amount of disk space (prior to [WSL release 0.58.0](https://github.com/microsoft/WSL/releases/tag/0.58.0) this default was set to a 512GB max and 256GB max prior to that).

If the storage space required by your Linux files exceeds this maximum size, you will see errors stating that you've run out of disk space. To fix this error, follow the guidance below on [How to expand the size of your WSL 2 Virtual Hard Disk](#how-to-expand-the-size-of-your-wsl-2-virtual-hard-disk).

## How to check your available disk space

Check the amount of disk space available in the VHD for a Linux distribution installed with WSL 2 by using the Linux `Df` command.

To check available disk space, open a PowerShell command line and enter this command (replacing `<distribution-name>` with the actual distribution name):

```powershell
wsl.exe --system -d <distribution-name> df -h /mnt/wslg/distro
```

If this command does not work for you please upgrade to the Store version of WSL using the `wsl --update` command, or try `wsl df -h /`.

The output will include:

- **Filesystem**: Identifier for the VHD file system
- **Size**: Total size of the disk (the maximum amount of space allocated to the VHD)
- **Used**: Amount of space currently being used in the VHD
- **Avail**: Amount of space left in the VHD (Allocated size minus amount used)
- **Use%**: Percentage of disk space remaining (Used / Allocated size)
- **Mounted on**: Directory path where the disk is mounted

If you see that you are near to reaching the available amount of disk space allocated to your VHD, or have already received an error due to no disk space remaining, see the next section for steps on how to expand the maximum amount of disk space allocated to the VHD associated with your Linux distribution. The amount of disk space allocated to your VHD by WSL will always show the default maximum amount (1TB in the most recent version of WSL), even if the amount of disk space on your actual Windows device is less than that. WSL mounts a VHD that will expand in size as you use it, so your Linux distribution sees that it can grow to the allocated maximum size of 1TB. 

## How to expand the size of your WSL 2 Virtual Hard Disk

To expand the VHD size for a Linux distribution beyond the **default 1TB maximum** amount of allocated disk space, follow the steps below. *(For earlier WSL releases that have not yet been updated, this max default may be set to 512GB or 256GB).*

1. Terminate all WSL instances using the command: `wsl.exe --shutdown`

2. Copy the directory path to the *ext4.vhdx* file associated with the Linux distribution installed on your machine. For help, see [How to locate the vhdx file and disk path for your Linux distribution](#how-to-locate-the-vhdx-file-and-disk-path-for-your-linux-distribution).

3. Open Windows Command Prompt with admin privileges and then open the [diskpart](/windows-server/administration/windows-commands/diskpart) command interpreter by entering:

      ```cmd
      diskpart
      ```

4. You will now have a `DISKPART>` prompt. Enter the following command, replacing `<pathToVHD>` with the directory path to the `ext4.vhdx` file associated with the Linux distribution (copied in step #2).

      ```cmd
      Select vdisk file="<pathToVHD>"
      ```

5. Display the details associated with this virtual disk, including the **Virtual size**, representing the current maximum size the VHD is allocated:

      ```cmd
      detail vdisk
      ```

6. You will need to convert the **Virtual size** to megabytes. For example, if **Virtual size: 512 GB**, this is equal to **512000 MB**. The new value you enter must be greater than this original value. To double the virtual size of 512 GB to 1024 GB, you would enter the value in MB as: **1024000**. Be careful not to enter a value higher than you actually want as the process of reducing a virtual disk size is much more complicated.

7. Enter the value for the new maximum size you want to allocate to this Linux distribution using the Windows Command Prompt `DISKPART>` prompt:

      ```cmd
      expand vdisk maximum=<sizeInMegaBytes>
      ```

8. Exit the `DISKPART>` prompt:

      ```cmd
      exit
      ```

9. Launch this Linux distribution. *(Ensure it is running in WSL 2. You can confirm this using the command: `wsl.exe -l -v`. WSL 1 is not supported).*

10. Make WSL aware that it can expand the file system size for this distribution by running these commands from your WSL distribution command line. You may see this message in response to the first **mount** command: "/dev: none already mounted on /dev." This message can safely be ignored.

    ```bash
    sudo mount -t devtmpfs none /dev
    mount | grep ext4
    ```

11. Copy the name of this entry, which will look like: `/dev/sdX` (with the X representing any other character).  In the following example the value of **X** is **b**:

   ```bash
      sudo resize2fs /dev/sdb <sizeInMegabytes>M
   ```

   Using the example from above, we changed the vhd size to **2048000**, so the command would be: `sudo resize2fs /dev/sdb 2048000M`.

   > [!NOTE]
   > You may need to install **resize2fs**.  If so, you can use this command to install it:  `sudo apt install resize2fs`.

The output will look similar to the following:

```bash
resize2fs 1.44.1 (24-Mar-2021)
Filesystem at /dev/sdb is mounted on /; on-line resizing required
old_desc_blocks = 32, new_desc_blocks = 38
The filesystem on /dev/sdb is now 78643200 (4k) blocks long.
```

The virtual drive (ext4.vhdx) for this Linux distribution has now successfully been expanded to the new size.  

> [!IMPORTANT]
> We recommend that you do not modify, move, or access the WSL related files located inside of your `AppData` folder using Windows tools or editors. Doing so could cause your Linux distribution to become corrupted. If you would like to access your Linux files from Windows, that is possible via the path `\\wsl$\<distribution-name>\`. Open your WSL distribution and enter `explorer.exe .` to view that folder. To learn more, see the blog post: [Accessing Linux files from Windows](https://devblogs.microsoft.com/commandline/whats-new-for-wsl-in-windows-10-version-1903/#accessing-linux-files-from-windows).

## How to repair a VHD mounting error

If you encounter an error related to "mounting the distribution disk", this could be due to a sudden shutdown or power outage and may result in the Linux distribution VHD being switched to *read-only* to avoid data loss. You can repair and restore the distribution using the `e2fsck` Linux command by following the steps below.

### Use the lsblk command to identify the block device name

When WSL 2 installs a Linux distribution, it is mounting the distribution as a Virtual Hard Disk (VHD) with it's own file system. Linux refers to these hard drives as "block devices" and you can view information about them by using the `lsblk` command.

To find the names of the block devices currently being used by WSL 2, open your distribution and enter the command: `lsblk`. (Or open PowerShell and enter the command: `wsl.exe lsblk`.) The output will look something like this:

```bash
NAME MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
sda    8:0    0 363.1M  1 disk
sdb    8:16   0     8G  0 disk [SWAP]
sdc    8:32   0   1.5T  0 disk
sdd    8:48   0     1T  0 disk /mnt/wslg/distro
```

Information about the block device includes:

- **NAME**: The name assigned to the device will be sd[a-z], referring to the SCSI Disk with a letter designation for each disk being used. `sda` is always the system distribution.
- **MAJ:MIN**: Represents numbers used by the Linux kernel to internally identify the devices with the first number representing the device type (8 is used for Small Computer System Interface/SCSI disks).
- **RM**: Let's us know if the device is removable (1) or not (0).
- **SIZE**: Total size of the volume.
- **RO**: Let's us know if the device is read-only (1) or not (0).
- **TYPE**: Refers to the device type (disk in this case).
- **MOUNTPOINTS**: Refers to the current directory on the files system where the block device is located (SWAP is for preconfigured inactive memory so no mountpoint).

### Read-only fallback error

If WSL encounters a "mounting error" when opening a Linux distribution, the distribution may be set as read-only as a fallback. If that happens, the distribution may display the following error during startup:

```powershell
An error occurred mounting the distribution disk, it was mounted read-only as a fallback.
```

When a distribution is started as read-only, any attempts to write to the filesystem will fail with an error like this:

```bash
$ touch file
touch: cannot touch 'file': Read-only file system
```

To repair a disk mount error in WSL, and restore it back to a usable / writeable state again, you can use the `wsl.exe --mount` command to re-mount the disk with the following steps:

1. Shutdown all WSL distributions by opening PowerShell and entering the command:

    ```powershell
    wsl.exe --shutdown
    ```

2. Open PowerShell as administrator (in an elevated command prompt) and enter the mount command, replacing `<path-to-ext4.vhdx>` with the path to the distribution's .vhdx file. For help locating this file, see [How to locate the VHD file and disk path for your Linux distribution](#how-to-locate-the-vhdx-file-and-disk-path-for-your-linux-distribution).

    ```powershell
    wsl.exe --mount <path-to-ext4.vhdx> --vhd --bare
    ```

3. Use the `wsl.exe lsblk` command from PowerShell to identify the block device name for the distribution (sd[a-z]) and then enter the following command to repair the disk (replacing `<device>` with the correct block device name, like "sdc"). The `e2fsck` command checks ext4 file systems (the type used by distributions installed with WSL) for errors and repairs them accordingly.

    ```powershell
    wsl.exe sudo e2fsck -f /dev/<device>
    ```

> [!NOTE]
> If you only have a single Linux distribution installed, you may encounter an "ext file in use" error and will need to [install](./basic-commands.md#install) an additional distribution in order to run `wsl.exe lsblk`. You can [uninstall](./basic-commands.md#unregister-or-uninstall-a-linux-distribution) the distribution once the repair is complete.

4. Once the repair is complete, unmount the disk in PowerShell by entering:

    ```powershell
    wsl.exe --unmount
    ```

> [!WARNING]
> You can use the command: `sudo mount -o remount,rw /` to return a read-only distribution to a usable/writable state, but all changes will be in-memory and so will be lost when the distribution is restarted. We recommend using the steps listed above to mount and repair the disk instead.

## How to locate the .vhdx file and disk path for your Linux distribution

To locate the *.vhdx* file and directory path for a Linux distribution, open PowerShell and use the following script, replacing `<distribution-name>` with the actual distribution name:

```powershell
(Get-ChildItem -Path HKCU:\Software\Microsoft\Windows\CurrentVersion\Lxss | Where-Object { $_.GetValue("DistributionName") -eq '<distribution-name>' }).GetValue("BasePath") + "\ext4.vhdx"
```

The result will display a path looking something like `%LOCALAPPDATA%\Packages\<PackageFamilyName>\LocalState\<disk>.vhdx`. For example:

```powershell
C:\Users\User\AppData\Local\Packages\CanonicalGroupLimited.UbuntuonWindows_79rhkp1fndgsc\LocalState\ext4.vhdx
```

This is the path to the `ext4.vhdx` file associated with the Linux distribution that you listed.
