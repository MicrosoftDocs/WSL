---
title: Get started mounting a linux disk in WSL 2 (Preview)
description: Learn how to set up a disk mount in WSL 2 and how to access it.
keywords: wsl, windows, windowssubsystem, gnu, linux, bash, disk, ext4, filesystem, mount
ms.date: 06/08/2020
ms.topic: article
ms.localizationpriority: medium
---

# Get started mounting a linux disk in WSL 2 (Preview)

If you're dual booting to Linux, or simply want to access a linux disk format that isn't supported by Windows, WSL 2 can mount your disk and let you access its content.

This tutorial will outline the steps to identify the disk and partition to attach to WSL2, how mount them, and how to access them.


## Identify the disk

To list the available disks in Windows, run:

```powershell
wmic diskdrive list brief
```

The disks paths are available under the 'DeviceID' columns. Usually under the `\\.\PHYSICALDRIVE*` format.

## List and select the partitions to mount in WSL 2

Once the disk is identified, run:

```powershell
wsl --mount <DiskPath> --bare
```

This will make the disk available in WSL 2.

Once attached, the partition can be listed by running the following command inside WSL 2:

```powershell
lsblk
```

This will display the available block devices and their partitions.
Inside linux, a block device is identified as  `/dev/<Device><Partition>`. For example, /dev/sdb3, is the partition number 3 of disk `sdb`.

Example output:

```powershell
NAME   MAJ:MIN RM  SIZE RO TYPE MOUNTPOINT
sdb      8:16   0    1G  0 disk
├─sdb2   8:18   0   50M  0 part
├─sdb3   8:19   0  873M  0 part
└─sdb1   8:17   0  100M  0 part
sdc      8:32   0  256G  0 disk /
sda      8:0    0  256G  0 disk
```

## Identifying the filesystem type

If you don't know the type of filesystem of a disk or partition, you can use.

```powershell
blkid <BlockDevice>
```

Which will output the detected filesystem type (under the `TYPE="<Filesystem>"` format).

## Mount the selected partitions

Once you know which partitions you want to mount, run: 

```powershell
wsl --mount <DiskPath> --partition <PartitionNumber> --type <Filesystem>
```

On each partition.

> [!NOTE]
> If you wish to mount the whole disk as a single volume (i.e. if the disk isn't partitioned), `--partition` can be omitted

> [!NOTE]
> If omitted, the default filesystem type is "ext4"

## Access the disk content

Once mounted, the disk can be accessed under the path pointed to by the config value `automount.root`. The default value is `/mnt/wsl`.

From Windows, the disk can be accessed from the Explorer by navigating to `\\wsl$\\<Distro>\\<Mountpoint>` (pick any linux distribution).

## Unmount the disk

If you want to unmount and detach the disk from WSL 2, run:
```powershell
wsl --unmount <DiskPath>
```

## Going further

For more advanced use cases, check out [Mounting a disk using WSL 2](../wsl2-mount-disk.md)
