---
title: Windows interoperability with Linux
description: Describes Windows interoperability with Linux distributions running on the Windows Subsystem for Linux. 
author: scooley
ms.author: scooley
ms.date: 12/20/2017
ms.topic: article
ms.assetid: 3cefe0db-7616-4848-a2b6-9296746a178b
---

# WSL interoperability with Windows

> **Updated for Fall Creators Update.**  
If you're running Creators Update or Anniversary Update, jump to the [Creators/Anniversary Update section](interop.md#creators-update-and-anniversary-update).

The Windows Subsystem for Linux (WSL) is continuously improving integration between Windows and Linux.  You can:

1. Invoke Windows binaries from the Linux console.
1. Invoke Linux binaries from a Windows console.
1. **Windows Insiders Builds 17063+** Share environment variables between Linux and Windows.

This delivers a seamless experience between Windows and WSL.  Technical details are on the [WSL blog](https://blogs.msdn.microsoft.com/wsl/2016/10/19/windows-and-ubuntu-interoperability/).

## Run Linux tools from a Windows command line

Run Linux binaries from the Windows Command Prompt (CMD or PowerShell) using `wsl.exe <command>`.

Binaries invoked in this way:

1. Use the same working directory as the current CMD or PowerShell prompt.
1. Run as the WSL default user.
1. Have the same Windows administrative rights as the calling process and terminal.

For example:

``` CMD
C:\temp> wsl ls -la
<- contents of C:\temp ->
```

The Linux command following `wsl.exe` is handled like any command run in WSL.  Things such as sudo, piping, and file redirection work.

Example using sudo:

``` CMD
C:\temp> wsl sudo apt-get update
[sudo] password for username:
Hit:1 http://archive.ubuntu.com/ubuntu xenial InRelease
Get:2 http://security.ubuntu.com/ubuntu xenial-security InRelease [94.5 kB]
```

Examples mixing WSL and Windows commands:

``` CMD
C:\temp> wsl ls -la | findstr "foo"
-rwxrwxrwx 1 root root     14 Sep 27 14:26 foo.bat

C:\temp> dir | wsl grep foo
09/27/2016  02:26 PM                14 foo.bat

C:\temp> wsl ls -la > out.txt
```

The commands passed into `wsl.exe` are forwarded to the WSL process without modification.  File paths must be specified in the WSL format.

Example with paths:

``` CMD
C:\temp> wsl ls -la /proc/cpuinfo
-r--r--r-- 1 root root 0 Sep 28 11:28 /proc/cpuinfo

C:\temp> wsl ls -la "/mnt/c/Program Files"
<- contents of C:\Program Files ->
```

## Run Windows tools from WSL

WSL can invoke Windows binaries directly from the WSL command line using `[binary name].exe`.  For example, `notepad.exe`.  To make Windows executables easier to run, Windows path is included in the Linux `$PATH` in Fall Creators Update.

Applications run this way have the following properties:

1. Retain the working directory as the WSL command prompt (for the most part -- exceptions are explained below).
1. Have the same permission rights as the WSL process.
1. Run as the active Windows user.
1. Appear in the Windows Task Manager as if directly executed from the CMD prompt.

Example:

``` BASH
$ notepad.exe
```

Windows executables run in WSL are handled similarly to native Linux executables -- piping, redirects, and even backgrounding work as expected.

Examples using pipes:

``` BASH
$ ipconfig.exe | grep IPv4 | cut -d: -f2
172.21.240.1
10.159.21.24
```

Example using mixed Windows and WSL commands:

``` BASH
$ ls -la | findstr.exe foo.txt

$ cmd.exe /c dir
<- contents of C:\ ->
```

Windows binaries must include the file extension, match the file case, and be executable.  Non-executables including batch scripts.  CMD native commands like `dir` can be run with `cmd.exe /C` command.

Examples:

``` BASH
$ cmd.exe /C dir
<- contents of C:\ ->

$ PING.EXE www.microsoft.com
Pinging e1863.dspb.akamaiedge.net [2600:1409:a:5a2::747] with 32 bytes of data:
Reply from 2600:1409:a:5a2::747: time=2ms
```

Parameters are passed to the Windows binary unmodified.

As an example, the following commands will open `C:\temp\foo.txt` in `notepad.exe`:

``` BASH
$ notepad.exe "C:\temp\foo.txt"
$ notepad.exe C:\\temp\\foo.txt
```

Modifying files located on VolFs (files not under `/mnt/<x>`) with a Windows application in WSL is not supported.

By default, WSL tries to keep the working directory of the Windows binary as the current WSL directory, but will fall back on the instance creation directory if the working directory is on VolFs.

As an example; `wsl.exe` is initially launched from `C:\temp` and the current WSL directory is changed to the user’s home.  When `notepad.exe` is called from the user’s home directory, WSL automatically reverts to `C:\temp` as the notepad.exe working directory:

``` BASH
C:\temp> wsl
/mnt/c/temp/$ cd ~
~$ notepad.exe foo.txt
~$ ls | grep foo.txt
~$ exit

exit
C:\temp>dir | findstr foo.txt
09/27/2016  02:15 PM                14 foo.txt
```

## Share environment variables between Windows and WSL

> Available in Windows Insider builds 17063 and later.

Prior to 17063, only Windows environment variable that WSL could access was `PATH` (so you could launch Win32 executables from under WSL).

Starting in 17063, WSL and Windows share `WSLENV`, a special environment variable created to bridge Windows and Linux distros running on WSL.

Properties of `WSLENV`:

* It is shared; it exists in both Windows and WSL environments.
* It is a list of environment variables to share between Windows and WSL.
* It can format environment variables to work well in Windows and WSL.

There are four flags available in `WSLENV` to influence how that environment variable is translated.

`WSLENV` flags:

* `/p` - translates the path between WSL/Linux style paths and Win32 paths.
* `/l` - indicates the environment variable is a list of paths.
* `/u` - indicates that this environment variable should only be included when running WSL from Win32.
* `/w` - indicates that this environment variable should only be included when running Win32 from WSL.

Flags can be combined as needed.

## Disable Interop

Users may disable the ability to run Windows binaries for a single WSL session by running the following command as root:

``` BASH
$ echo 0 > /proc/sys/fs/binfmt_misc/WSLInterop
```

To reenable Windows binaries either exit all WSL sessions and re-run bash.exe or run the following command as root:

``` BASH
$ echo 1 > /proc/sys/fs/binfmt_misc/WSLInterop
```

Disabling interop will not persist between WSL sessions -- interop will be enabled again when a new session is launched.

## Creators Update and Anniversary Update

While the interop experience pre-Fall Creators Update is similar to more recent interop experiences, there are a handfull of major differences.

To summarize:

* `bash.exe` has been deprecated and replaced with `wsl.exe`.
* `-c` option for running a single command isn't needed with `wsl.exe`.
* Windows path is included in the WSL `$PATH`

The process for disabling interop is unchanged.

### Invoking WSL from the Windows Command Line

Linux binaries can be invoked from the Windows Command Prompt or from PowerShell.  Binaries invoked in this way have the following properties:

1. Use the same working directory as the CMD or PowerShell prompt.
1. Run as the WSL default user.
1. Have the same Windows administrative rights as the calling process and terminal.

Example:

``` CMD
C:\temp> bash -c "ls -la"
```

Linux commands called in this way are handled like any other Windows application.  Things such as input, piping, and file redirection work as expected.

Examples:

``` CMD
C:\temp>bash -c "sudo apt-get update"
[sudo] password for username:
Hit:1 http://archive.ubuntu.com/ubuntu xenial InRelease
Get:2 http://security.ubuntu.com/ubuntu xenial-security InRelease [94.5 kB]
```

``` CMD
C:\temp> bash -c "ls -la" | findstr foo
C:\temp> dir | bash -c "grep foo"
C:\temp> bash -c "ls -la" > out.txt
```

The WSL commands passed into `bash -c` are forwarded to the WSL process without modification.  File paths must be specified in the WSL format and care must be taken to escape relevant characters. Example:

``` CMD
C:\temp> bash -c "ls -la /proc/cpuinfo"
-r--r--r-- 1 root root 0 Sep 28 11:28 /proc/cpuinfo

C:\temp> bash -c "ls -la \"/mnt/c/Program Files\""
<- contents of C:\Program Files ->
```

### Invoking Windows binaries from WSL

The Windows Subsystem for Linux can invoke Windows binaries directly from the WSL command line.  Applications run this way have the following properties:

1. Retain the working directory as the WSL command prompt except in the scenario explained below.
1. Have the same permission rights as the `bash.exe` process. 
1. Run as the active Windows user.
1. Appear in the Windows Task Manager as if directly executed from the CMD prompt.

Example:

``` BASH
$ /mnt/c/Windows/System32/notepad.exe
```

In WSL, these executables are handled similar to native Linux executables.  This means adding directories to the Linux path and piping between commands works as expected.  Examples:

``` BASH
$ export PATH=$PATH:/mnt/c/Windows/System32
$ notepad.exe
$ ipconfig.exe | grep IPv4 | cut -d: -f2
$ ls -la | findstr.exe foo.txt
$ cmd.exe /c dir
```

The Windows binary must include the file extension, match the file case, and be executable.  Non-executables including batch scripts and command like `dir` can be run with `/mnt/c/Windows/System32/cmd.exe /C` command.

Examples:

``` BASH
$ /mnt/c/Windows/System32/cmd.exe /C dir
$ /mnt/c/Windows/System32/PING.EXE www.microsoft.com
```

Parameters are passed to the Windows binary unmodified.  

As an example, the following commands will open `C:\temp\foo.txt` in `notepad.exe`:

``` BASH
$ notepad.exe "C:\temp\foo.txt"
$ notepad.exe C:\\temp\\foo.txt
```

Modifying files located on VolFs (files not under `/mnt/<x>`) with a Windows application is not supported.  By default, WSL attempts to keep the working directory of the Windows binary as the current WSL directory, but will fall back on the instance creation directory if the working directory is on VolFs.

As an example; `bash.exe` is initially launched from `C:\temp` and the current WSL directory is changed to the user’s home.  When `notepad.exe` is called from the user’s home directory, WSL automatically reverts to `C:\temp` as the notepad.exe working directory:

``` BASH
C:\temp> bash
/mnt/c/temp/$ cd ~
~$ notepad.exe foo.txt
~$ ls | grep foo.txt
~$ exit
exit

C:\temp> dir | findstr foo.txt
09/27/2016  02:15 PM                14 foo.txt
```
