---
title: Disk maintenance operations on WSL2 distributions
description: Learn the steps to repair or expand WSL2 virtual hard disks
keywords: BashOnWindows, bash, wsl, windows, windows subsystem, distro, full, readonly, expand, vhd, read, only
ms.date: 12/08/2022
ms.topic: article
---

# Disk maintenance operations on WSL2 distributions

WSL 2 uses a Virtual Hard Disk (VHD) to store your Linux files. In WSL 2, a VHD is represented on your Windows hard drive as a *.vhdx* file.
Inside the VHD, WSL 2 VHD uses the ext4 file system.

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

See below sections for instructions on how to increase the size of a VHD, or repair it.

## 1) Getting the path where the VHD is stored

To figure out where the disk is stored, run the following command in powershell (replace `<distribution-name>` with the actual distribution name):

```powershell
(Get-ChildItem -Path HKCU:\Software\Microsoft\Windows\CurrentVersion\Lxss | Where-Object { $_.GetValue("DistributionName") -eq '<distribution-name>' }).GetValue("BasePath") + "\ext4.vhdx"
```

This will display a path looking like:
```powershell
C:\Users\User\AppData\Local\Packages\TheDebianProject.DebianGNULinux_76v4gfsz19hv4\LocalState\ext4.vhdx
```

## 2) Inspecting the disk

To figure out if a disk is out of space, run the following command (replace `<distribution-name>` with the actual distribution name):

```powershell
$ wsl.exe --system -d <distribution-name> df -h /mnt/wslg/distro
```

And look at the `Use%` column. If you see `100%`, then the disk is full.

Sample output:

```bash
Filesystem      Size  Used Avail Use% Mounted on
/dev/sdc        251G   251G    0 100% /mnt/wslg/distro
```

If the disk is full, then follow ['Expand the size of your WSL 2 Virtual Hard Disk'](#expand-the-size-of-your-wsl-2-virtual-hard-disk) to expand it.
If the disk is not full, but failed to mount properly, then it needs to be repaired. The next section shows how to do that.

## Mounting the disk with wsl --mount to repair it

This step will repair the disk so it can be mounted properly again.

First run the following command to terminate all WSL distributions.

```powershell
wsl.exe --shutdown
```

Then use the following command to mount the disk in WSL2 (run in an elevated command prompt):

```powershell
wsl.exe --mount <path-to-ext4.vhdx> --vhd --bare
```

Once mounted, use **another WSL 2 distribution** to access the disk:

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

## Expand the size of your WSL 2 Virtual Hard Disk

This VHD automatically resizes to meet your storage needs and has an initial maximum size of 1TB. If the storage space required by your Linux files exceeds this size you may need to expand it. If your distribution grows in size to be greater than its initial size, you will see errors stating that you've run out of disk space. You can fix this error by expanding the VHD size.

Note:
> [!NOTE]
> Older versions of WSL had smaller initial maximum sizes (512GB or 256GB).
>

To expand your maximum VHD size beyond its initial limit:

1. Terminate all WSL instances using the command: `wsl --shutdown`

2. Resize your WSL 2 VHD by completing the following commands:
   - Open Windows Command Prompt with admin privileges and enter:

      ```cmd
      diskpart
      ```

      ```cmd
      DISKPART> Select vdisk file="<pathToVHD>"
      ```

      ```cmd
      DISKPART> detail vdisk
      ```

   - Examine the output of the **detail** command.  The output will include a value for **Virtual size**. This is the current maximum. Convert this value to megabytes. For example, if the **detail** output shows **Virtual size: 256 GB**, convert this to **256000**.
   - The new value you enter must be greater than this original value. As an example, to double the virtual size listed above, you could enter the value: **512000**. Once you have determined the number you would like to set for your new size (in megabytes), enter the following command in your Windows Command Prompt **diskpart** prompt:

      ```cmd
      DISKPART> expand vdisk maximum=<sizeInMegaBytes>
      ```

   - Exit **diskpart**

      ```cmd
      DISKPART> exit
      ```

3. Launch your WSL distribution (Ubuntu, for example) and make sure it is running in WSL 2 (WSL 1 is not supported). You can confirm this using the command: `wsl.exe -l -v`. 

4. Make WSL aware that it can expand its file system's size by running these commands from your WSL distribution command line.

   ```bash
      sudo mount -t devtmpfs none /dev
      mount | grep ext4
   ```

   - You may see this message in response to the first **mount** command: "/dev: none already mounted on /dev." This message can safely be ignored.
   - Copy the name of this entry, which will look like: `/dev/sdX` (with the X representing any other character).  In the following example the value of **X** is **b**:

   ```bash
      sudo resize2fs /dev/sdb <sizeInMegabytes>M
   ```

   - Using the example from above, we changed the vhd size to **512000**, so the command would be: `sudo resize2fs /dev/sdb 512000M`.

   > [!NOTE]
   > You may need to install **resize2fs**.  If so, you can use this command to install it:  `sudo apt install resize2fs`.

   The output will look similar to the following:

   ```bash
      resize2fs 1.44.1 (24-Mar-2021)
      Filesystem at /dev/sdb is mounted on /; on-line resizing required
      old_desc_blocks = 32, new_desc_blocks = 38
      The filesystem on /dev/sdb is now 78643200 (4k) blocks long.
      ```

> [!IMPORTANT]
> We recommend that you do not modify, move, or access the WSL related files located inside of your AppData folder using Windows tools or editors. Doing so could cause your Linux distribution to become corrupted. If you would like to access your Linux files from Windows, that is possible via the path `\\wsl$\<distroName>\`. Open your WSL distribution and enter `explorer.exe .` to view that folder. To learn more, see the blog post: [Accessing Linux files from Windows](https://devblogs.microsoft.com/commandline/whats-new-for-wsl-in-windows-10-version-1903/#accessing-linux-files-from-windows).
