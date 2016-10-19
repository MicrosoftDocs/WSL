#Windows Interoperability

> **Important note**  
	This is the first release of Bash on Windows and it is branded "beta" deliberately - it's not yet complete! You should expect many things to work and for some things to fail! We greatly appreciate you using Bash on Windows and helping us identify the issues we need to fix in order to deliver a great experience.

The Windows Subsystem for Linux can invoke native Windows binaries and be invoked from a Windows command line. This feature is available to Windows 10 users running Anniversary Update [build 14951](https://msdn.microsoft.com/en-us/commandline/wsl/release_notes#build-14951).  This new interoperability functionality delivers a seamless experience between Windows and WSL.  Technical details on how this interoperability works can be found on the [WSL blog](https://blogs.msdn.microsoft.com/wsl/2016/10/19/windows-and-ubuntu-interoperability/). 

##Invoking WSL from the Windows Command Line
Linux binaries can be invoked from the Windows Command Prompt or from PowerShell.  Binaries invoked in this way have the following properties:

1. Use the same working directory as the CMD or PowerShell prompt
2. Are run under as the WSL default user
3. Have the same Windows administrative rights as the calling process and terminal

Example:

```
C:\temp>bash -c "ls -la"
total 916
drwxrwxrwx 2 root root      0 Sep 28 08:45 .
drwxrwxrwx 2 root root      0 Sep 27 07:33 ..
-rwxrwxrwx 1 root root     14 Sep 27 14:26 foo.bat
```

Linux commands called in this way are handled like any other Windows application.  Things such as input, piping, and file redirection work as expected.  Examples:

```
C:\temp>bash -c "sudo apt-get update"
[sudo] password for username:
Hit:1 http://archive.ubuntu.com/ubuntu xenial InRelease
Get:2 http://security.ubuntu.com/ubuntu xenial-security InRelease [94.5 kB]

…

C:\temp>bash -c "ls -la" | findstr foo
-rwxrwxrwx 1 root root     14 Sep 27 14:26 foo.bat
C:\temp>dir | bash -c "grep foo"
09/27/2016  02:26 PM                14 foo.bat
C:\temp>bash -c "ls -la" > out.txt
```

The WSL commands passed into bash -c are forwarded to the WSL process without modification.  File paths must be specified in the WSL format and care must be taken to escape relevant characters. Example:

```
C:\temp>bash -c "ls -la /proc/cpuinfo"
-r--r--r-- 1 root root 0 Sep 28 11:28 /proc/cpuinfo

C:\temp>bash -c "ls -la \"/mnt/c/Program Files\"”
<- contents of C:\Program Files ->
```

##Invoking Windows binaries from WSL
The Windows Subsystem for Linux can invoke Windows binaries directly from the WSL command line.  Applications run this way have the following properties:

1. Retain the working directory as the WSL command prompt except in the scenario explained below 
2. Have the same permission rights as the bash.exe process 
3. Run as the active Windows user
4. Appear in the Windows Task Manager as if directly executed from the CMD prompt  

Example:

```
$/mnt/c/Windows/System32/notepad.exe
```

In WSL, these executables are handled similar to native Linux executables.  This means adding directories to the Linux path and piping between commands works as expected.  Examples:

```
$ export PATH=$PATH:/mnt/c/Windows/System32

$ notepad.exe

$ ipconfig.exe | grep IPv4 | cut -d: -f2

$ ls -la | findstr.exe foo.txt

$ cmd.exe /c dir
```

The Windows binary must include the file extension, match the file case, and be executable.  Non-executables including batch scripts and command like `dir` can be run with `/mnt/c/Windows/System32/cmd.exe /C` command. Examples:

```
$ /mnt/c/Windows/System32/cmd.exe /C dir

$/mnt/c/Windows/System32/PING.EXE www.microsoft.com
```
Parameters are passed to the Windows binary unmodified.  As an example, the following commands will open `C:\temp\foo.txt` in `notepad.exe`:

```
$notepad.exe “C:\temp\foo.txt”

$notepad.exe C:\\temp\\foo.txt
```

Modifying files located on VolFs (files not under `/mnt/<x>`) with a Windows application is not supported.  By default, WSL attempts to keep the working directory of the Windows binary as the current WSL directory, but will fall back on the instance creation directory if the working directory is on VolFs.

As an example; bash.exe is initially launched from C:\temp and the current WSL directory is changed to the user’s home.  When notepad.exe is called from the user’s home directory, WSL automatically reverts to C:\temp as the notepad.exe working directory:

```
C:\temp>bash
/mnt/c/temp/$ cd ~
~$ notepad.exe foo.txt
~$ ls | grep foo.txt
~$ exit
exit
C:\temp>dir | findstr foo.txt
09/27/2016  02:15 PM                14 foo.txt
```

Users may disable the ability to run Windows binaries for a single WLS session by running the following command as root:
```
$ echo 0 > /proc/sys/fs/binfmt_misc/WSLInterop
```

To reenable Windows binaries either exit all WSL sessions and re-run bash.exe or run the following command as root:

```
$ echo 1 > /proc/sys/fs/binfmt_misc/WSLInterop
```

Note that disabling interop will not persist between WSL sessions.
