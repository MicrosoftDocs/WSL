---
title: File Permissions for WSL
description: Understanding how WSL determines file permissions in Windows
keywords: File permissions, bash, wsl, wsl2, windows, windows subsystem for linux, windows subsystem, ubuntu, debian, suse, windows 10
ms.date: 09/27/2021
ms.topic: article
---

# File Permissions for WSL

This page details how Linux file permissions are interpreted across the Windows Subsystem for Linux, especially when accessing resources inside of Windows on the NT file system. This documentation assumes a basic understanding of the [Linux file system permissions structure](https://wiki.archlinux.org/title/File_permissions_and_attributes) and the [umask command](https://en.wikipedia.org/wiki/Umask).

When accessing Windows files from WSL the file permissions are either calculated from Windows permissions, or are read from metadata that has been added to the file by WSL. This metadata is not enabled by default.

## WSL metadata on Windows files

When metadata is enabled as a mount option in WSL, extended attributes on Windows NT files can be added and interpreted to supply Linux file system permissions.

WSL can add four NTFS extended attributes:

| Attribute Name | Description |
| --- | --- |
| $LXUID | User Owner ID |
| $LXGID | Group Owner ID |
| $LXMOD | File mode (File systems permission octals and type, e.g: 0777) |
| $LXDEV | Device, if it is a device file |

Additionally, any file that is not a regular file or directory (e.g: symlinks, FIFOs, block devices, unix sockets, and character devices) also have an NTFS [reparse point](/windows/win32/fileio/reparse-points). This makes it much faster to determine the kind of file in a given directory without having to query its extended attributes.

## File Access Scenarios

Below is a description of how permissions are determined when accessing files in different ways using the Windows Subsystem for Linux.

### Accessing Files in the Windows drive file system (DrvFS) from Linux

These scenarios occur when you are accessing your Windows files from WSL, most likely via `/mnt/c`.

#### Reading file permissions from an existing Windows file

The result depends on if the file already has existing metadata.

##### DrvFS file does not have metadata (default)

If the file has no metadata associated with it then we translate the effective permissions of the Windows user to read/write/execute bits and set them to the this as the same value for user, group, and other. For example, if your Windows user account has read and execute access but not write access to the file then this will be shown as `r-x` for user, group and other. If the file has the 'Read Only' attribute set in Windows then we do not grant write access in Linux.

##### The file has metadata

If the file has metadata present, we simply use those metadata values instead of translating effective permissions of the Windows user.

#### Changing file permissions on an existing Windows file using chmod

The result depends on if the file already has existing metadata.

##### chmod file does not have metadata (default)

Chmod will only have one effect, if you remove all the write attributes of a file then the 'read only' attribute on the Windows file will be set, since this is the same behaviour as CIFS (Common Internet File System) which is the SMB (Server Message Block) client in Linux.

##### chmod file has metadata

Chmod will change or add metadata depending on the file's already existing metadata. 

Please keep in mind that you cannot give yourself more access than what you have on Windows, even if the metadata says that is the case. For example, you could set the metadata to display that you have write permissions to a file using `chmod 777`, but if you tried to access that file you would still not be able to write to it. This is thanks to interoperability, as any read or write commands to Windows files are routed through your Windows user permissions.

#### Creating a file in DriveFS

The result depends on if metadata is enabled.

##### Metadata is not enabled (default)

The Windows permissions of the newly created file will be the same as if you created the file in Windows without a specific security descriptor, it will inherit the parent's permissions.

##### Metadata is enabled

The file's permission bits are set to follow the Linux umask, and the file will be saved with metadata.

#### Which Linux user and Linux group owns the file? 

The result depends on if the file already has existing metadata.

##### User file does not have metadata (default)

In the default scenario, when automounting Windows drives, we specify that the user ID (UID) for any file is set to the user ID of your WSL user and the group ID (GID) is set to the principal group ID of your WSL user.

##### User file has metadata

The UID and GID specified in the metadata is applied as the user owner and group owner of the file.

### Accessing Linux files from Windows using `\\wsl$`

Accessing Linux files via `\\wsl$` will use the default user of your WSL distribution. Therefore any Windows app accessing Linux files will have the same permissions as the default user.

#### Creating a new file

The default umask is applied when creating a new file inside of a WSL distribution from Windows. The default umask is `022`, or in other words it allows all permissions except write permissions to groups and others. 

### Accessing files in the Linux root file system from Linux

Any files created, modified, or accessed in the Linux root file system follow standard Linux conventions, such as applying the umask to a newly created file.

## Configuring file permissions

You can configure your file permissions inside of your Windows drives using the mount options in wsl.conf. The mount options allow you to set `umask`, `dmask` and `fmask` permissions masks. The `umask` is applied to all files, the `dmask` is applied just to directories and the `fmask` is applied just to files. These permission masks are then put through a logical OR operation when being applied to files, e.g: If you have a `umask` value of `023` and an `fmask` value of `022` then the resulting permissions mask for files will be `023`.

Learn more: [Per distribution configuration options with wsl.conf](/windows/wsl/wsl-config#per-distribution-configuration-options-with-wslconf).
