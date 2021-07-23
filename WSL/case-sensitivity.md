---
title: Adjust the case sensitivity of directories with WSL
description: Learn how case sensitive file names are handled between Windows and Linux file systems, how to adjust these settings by directory with WSL, and how to troubleshoot issues.
keywords: case sensitivity, wsl, windows, linux, ntfs
ms.date: 07/21/2021
ms.topic: article
ms.localizationpriority: medium
---

# Adjust the case sensitivity of directories with WSL

Case sensitivity determines whether uppercase (FOO.txt) and lowercase (foo.txt) letters are handled as distinct (case-sensitive) or equivalent (case-insensitive) in a file name or directory.

- Case-sensitive: FOO.txt = foo.txt = Foo.txt
- Case-insenstive: FOO.text ≠ foo.txt ≠ Foo.txt

Windows Subsystem for Linux (WSL) enables you to make adjustments to how case sensitivity is handled by the file system per directory.

## Differences between Windows and Linux case sensitivity

Standard default behavior:

- Windows file system treats file and directory names as case-insensitive. FOO.txt and foo.txt will be treated as equivalent files.
- Linux file system treats file and directory names as case-sensitive. FOO.txt and foo.txt will be treated as distinct files.

Windows Subsystem for Linux (WSL 2) is running a real Linux kernel and, thus, follows the standard Linux behavior of treating files and directories (folders) as case-sensitive.

> [!NOTE]
> In the past, if you had files whose name differed only by case, these files could not be accessed by Windows, because Windows applications treat the file system as case insensitive and cannot distinguish between files whose names only differ in case. While Windows File Explorer will show both files, only one will open regardless of which you select.

> [!WARNING]
> Some Windows applications, using the assumption that the file system is case insensitive, don’t use the correct case to refer to files. For example, it’s not uncommon for applications to transform filenames to use all upper or lower case. In directories marked as case sensitive, this means that these applications can no longer access the files. Additionally, if Windows applications create new directories in a directory tree where you are using case sensitive files, these directories are not case sensitive. This makes it difficult to work with Windows tools in case sensitive directories.

## Per-directory case sensitivity

While Linux distributions run with WSL are case-sensitive by default, WSL enables you to flag specific directories as case-sensitive or case-insensitive.

> ![NOTE]
> Support for per-directory case sensitivity began in Windows 10, build 17107. In Windows 10, build 17692, support was updated to include inspecting and modifying the case sensitivity flag for a directory from inside WSL. Case sensitivity is exposed using an extended attribute named `system.wsl_case_sensitive`. The value of this attribute will be 0 for case insensitive directories, and 1 for case sensitive directories.

### Inspect and modify case sensitivity

To check if a directory is case sensitive in the Windows filesystem, run the command:

```powershell
fsutil.exe file queryCaseSensitiveInfo <path>
```

Replace `<path>` with your file path. For a directory in the Windows (NTFS) file system, the `<path>` will look like: `C:\Users\mattwojo\case-test` or if you are already in the `mattwojo` directory, you could just run: `fsutil.exe file setCaseSensitiveInfo case-test`

Changing the case-sensitivity of a directory requires that you run elevated permissions. Changing the case-sensitivity flag also requires “Write attributes”, “Create files”, “Create folders” and “Delete subfolders and files” permissions on the directory.
<!-- Should we cover how to check whether you have these permissions on a directory? Or trust that it's easy enough to find how to do this elsewhere? -->

To mark a directory as case-sensitive, run PowerShell as Administrator and use the command:

```powershell
fsutil.exe file setCaseSensitiveInfo <path> enable
```

To mark a directory as case-insensitive, run PowerShell as Administrator and use the command:

```powershell
fsutil.exe file setCaseSensitiveInfo <path> disable
```

To check whether a directory is case sensitive inside the WSL filesystem, run the command:

```bash

```

> ![NOTE]
> If you change the case sensitive flag on an existing directory while WSL is running, ensure WSL has no references to that directory or else the change will not be effective. This means the directory must not be open by any WSL processes, including using the directory (or its descendants) as the current working directory.

## Case sensitivity inheritance

<!-- When creating new directories, those directories will inherit the case sensitivity from it's parent directory. -->
The per-directory case sensitivity flag is not inherited; directories created in a case sensitive directory are not automatically case sensitive themselves. You must explicitly mark each directory as case sensitive.

## Automount options to force case for WSL

Case sensitivity can also be managed as an automount option within the WSL config file. Each Linux distribution that you have installed will have it's own WSL config file, called `/etc/wsl.conf`.

<!-- Does anyone have a wsl.conf file by default? Our docs imply that they will be can also create one. From what I can tell, they will always have to create this file themselves... true? -->

### WSL configuration file

To access the WSL config file for your distribution (ie. Ubuntu), open the distribution, change directories up until you see the `etc` folder (this may require you to `cd ..` up from the `home` directory). List the files in the `etc` directory to see if a `wsl.conf` file exists (use the `ls` command, or `explorer.exe .` to view the directory with Windows File Explorer). If the `wsl.conf` file does not already exist, you can create it using: `sudo touch wsl.conf`.

<!-- This statement thoroughly confused me: "To mount DrvFs with a specific case sensitivity setting, use /etc/wsl.conf to set the default mount options for all drives, or /etc/fstab to specify options for a specific drive. Not all file systems support per-directory case sensitivity; currently, it only works on local NTFS drives. To make sure your drive was successfully mounted with the desired case sensitivity option, use the mount command and see if the option was applied." -->

### Configure case sensitivity with the automount option

The following options are available for configuring case sensitivity in WSL file system directories:

- `case=dir`: This is the default setting. New directories created from a WSL command line on the Windows filesystem will be case-sensitive.
- `case=off`: New directories created from a WSL command line on the Windows filesystem will be case-insensitive.
- `case=force`: ?
<!-- Still unclear on how this setting works... and does it still require setting a registry key?? -->

<!-- Re-write this so that there is more clarity regarding what having "the case sensitivity flag set" means. -->
Directories with the case sensitivity flag set are always treated as case sensitive. Directories without the flag set are treated as case insensitive, unless you’re using case=force.

To configure the automount options for WSL case sensitivity, open the WSL config file (`/etc/wsl.conf`).

For new WSL directories to be case-sensitive, enter:

```bash
[automount]
options=case=dir
```

For new WSL directories to be case-insensitive, enter:

```bash
[automount]
options=case=off
```

For new WSL directories to be case-insensitive, enter:

```bash
[automount]
options=case=off
```

<!-- What does this mean in a practical sense? > "Not all file systems support per-directory case sensitivity; currently, it only works on local NTFS drives." ...What are some examples of drives a user may try to mount where case sensitivity won't be supported? -->

For more WSL configuration options, see [Configure per distro launch settings with wslconf](./wsl-config.md#configure-per-distro-launch-settings-with-wslconf).


You will need to restart WSL after making any changes to the `wsl.conf` file in order for those changes to take effect. You can restart WSL using the command: `wsl --shutdown`

> ![NOTE]
> You can check what your mount options are by sharing the output of the mount command.
<!-- Should we include instructions on how to do this? -->

<!-- Does any of this need to be included? If so, try to rewrite with more clarity:
DrvFs’s default behavior is now equivalent to using “case=dir”. This means that any directories you created with WSL before build 17093 will not be treated as case sensitive anymore. To fix this, use fsutil.exe to mark your existing directories as case sensitive.

If you require the old behavior, you can still mount DrvFs using “case=force”, though we strongly recommend using per-directory case sensitivity going forward. As of build 17110, using “case=force” requires setting a registry key, which you can do by running the following command from an elevated command prompt:

```powershell
reg.exe add HKLM\SYSTEM\CurrentControlSet\Services\lxss /v DrvFsAllowForceCaseSensitivity /t REG_DWORD /d 1
```
-->

<!-- Do we need to refer to DrvFs? Is it helpful to know the term "DrvFs" and for WSL users to understand what this is?

> ![NOTE]
> DrvFs is a filesystem plugin to WSL that was designed to support interop between WSL and the Windows filesystem. DrvFs enables WSL to mount drives with supported file systems under /mnt, such as /mnt/c, /mnt/d, etc.
 -->

## Troubleshooting

### Error: A local NTFS volume is required for this operation

<!-- Needs a resolution -->

### Error: The directory is not empty

<!-- Needs a resolution... Is this enough? "A directory must be empty in order to change the case-sensitivity." -->

### Error: Access denied

Check to be sure that you have the “Write attributes”, “Create files”, “Create folders” and “Delete subfolders and files” permissions on the directory required for changing case-sensitivity.

<!-- What other errors should be included? -->

## Additional resources

- [DevBlog: Per-directory case sensitivity and WSL](https://devblogs.microsoft.com/commandline/per-directory-case-sensitivity-and-wsl/)
- [DevBlog: Improved per-directory case sensitivity support in WSL](https://devblogs.microsoft.com/commandline/improved-per-directory-case-sensitivity-support-in-wsl/)

<!-- Notes from issue:

https://github.com/microsoft/WSL/issues/7211

how are you mounting your windows drives? Are you setting the case=dir mount option?
You can do this by adding this line to /etc/wsl.conf (and restarting wsl via wsl --shutdown).
[automount]
options=case=dir
You can check what your mount options are by sharing the output of the mount command.

 I didn’t have a default /etc/wsl.conf so I created one “sudo vi /etc/wsl.conf” and put the text that you suggested. I then ran wsl --shutdown in PowerShell. It did not seem to have an impact on the case sensitivity.


* the getfattr / setfattr commands will only work for WSL1
You should be able to use fsutil.exe to accomplish this:
fsutil.exe file setCaseSensitiveInfo dum enable
fsutil.exe file setCaseSensitiveInfo dum disable
**Update this blog: https://devblogs.microsoft.com/commandline/improved-per-directory-case-sensitivity-support-in-wsl/

I see case=dir in our mount output. Did you also try to use fsutil.exe to set the per-directory case sensitivity?

1) I added the option: [automount] options=case=dir to /etc/wsl.conf, which I had to create because it didn’t exist initially.
2) then went to the directory where dum is located on /mnt/d/, which is a mount that I created and may not be configured properly, because I don’t know what I am doing.
3) I tried: fsutil.exe file setCaseSensitiveInfo dum enable
and get the result: Error:  The directory is not empty. ...It does contain the file: DUMMY_FILE.

>> As the error implies, you can only change the sensitivity of empty directories.

I have a directory full of files with file names with mixed case. Is there a way to change the state of directory with content or do I have to create a directory, enable it and then move the files over?

>> generally what I will do is create the directory I want case-sensitive, mark as case sensitive, then git clone or untar into that location. If you already have the files somewhere case-insensitive (and there were conflicts) you probably ended up overwriting some files, if that makes sense.

Thank you! I’m good to go. I now have the ability to rename files with the same name but different cases. I think we can close this thread.

 -->
