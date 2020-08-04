---
title: Mount disks in WSL2
description: Usage instructions to mount and attach physical disks in WSL2.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, windows 10, install, WSL2, version 2, disk, mount
ms.date: 08/03/2020
ms.topic: article
ms.localizationpriority: high
---

# Mounting a disk using WSL 2

WSL 2 is capable of mounting disk formats and filesystems that aren't natively supported by Windows.

## Attaching a disk
To mount a disk, run:

```powershell
wsl --mount <DiskPath>
```

Once attached to WSL 2, the disk appears 'offline' in Windows, and is accessible as a block device in WSL 2.

To list the available disks in Windows, run:

```powershell
wmic diskdrive list brief
```

The disks paths are available under the 'DeviceID' columns. Usually under the `\\.\\\.\PHYSICALDRIVE*` format.

Once mounted, the disk can be accessed under the path pointed to by the config value `automount.root`. The default value is `/mnt/wsl`.

## Mouting a specific filesystem

By default, WSL 2 will attempt to mount the device as ext4. To specify another filesystem, run:

```powershell
wsl --mount <DiskPath> -t <FileSystem>
```

For example, to mount a disk as fat, run:
```
wsl --mount <Diskpath> -t vfat
```

> [!NOTE]
> To list the available filesystems in WSL2, run `cat /proc/filesystems`

## Mouting a specific partition

By default, WSL 2 attempts to mount the whole disk, to mount a specific partition, run:

```
wsl --mount <Diskpath> -p <PartitionIndex>
```

> [!NOTE]
> This only works if the disk is either GPT or MBR.

## Specifying mount options

To specify mount options, run:

```powershell
wsl --mount <DiskPath> -o <MountOptions>
```

Example:

```powershell
wsl --mount <DiskPath> -o "data=ordered"
```

> [!NOTE]
> Only filesystem specific options are supported at this time. Generic options such as `ro, rw, noatime, ...` are not supported.

## Attaching the disk without mounting it

If the disk scheme isn't supported by any of the above options, you can attach the disk to WSL 2 without mounting it by running:

```powershell
wsl --mount <DiskPath> --bare
```

This will make the block device available inside WSL 2 so it can be mounted manually from there. Use `lsblk` to list the available block devices inside WSL 2.

## Detaching a disk

To detach a disk from WSL 2, run:
```powershell
wsl --unmount [DiskPath]
```

If `Diskpath` Is omitted, all attached disks disks are unmounted and detached.

> [!NOTE]
> If one disk fails to unmount, WSL 2 can be forced to exit by running `wsl --shutdown`, which will detach the disk`.


## Limitations

- At this time, only whole disks can be attached to WSL 2 meaning that it's not possible to attach only a partition. Concretely this means that it's not possible to use `wsl --mount` to read a partition on the boot device, because that device can't be detached from Windows.

- Only filesystems that are natively supported in the kernel can be mounted by `wsl --mount`. This means that it's not possible to use installed filesystem drivers (such as ntfs-3g for example) by calling `wsl --mount`.
