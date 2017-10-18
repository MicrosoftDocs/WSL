---
title: Release Notes
description: Release notes for the Windows Subsystem for Linux.  Updated weekly.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu
author: benhillis
ms.date: 7/31/2017
ms.topic: article
ms.prod: windows-subsystem-for-linux
ms.service: windows-subsystem-for-linux
ms.assetid: 36ea641e-4d49-4881-84eb-a9ca85b1cdf4
---

# Release Notes

## Build 17017

For general Windows information on build 17017 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/10/13/announcing-windows-10-insider-preview-build-17017-pc).<br/>
 

### Fixed
#### WSL
- Ignore empty ELF program headers [GH 330].
- Allow LxssManager to create WSL instances for non-interactive users (ssh and scheduled task support) [GH 777, 1602].
- Support WSL->Win32->WSL ("inception") scenarios [GH 1228].
- Limited support for termination of console apps invoked via interop [GH 1614].
- Support mount options for devpts [GH 1948].
- Ptrace blocking child startup [GH 2333].
- EPOLLET missing some events [GH 2462].
- Return more data for PTRACE_GETSIGINFO.
- Getdents with lseek gives incorrect results.
- Fix some Win32 interop app hangs, waiting for input on a pipe that has no more data.
- O_ASYNC support for tty/pty files.
- Additional improvements and bug fixes

#### Console
- No Console related changes in this release.

### LTP Results:
Testing in progress.

# Fall Creators Update

## Build 16288

For general Windows information on build 16288 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/09/12/announcing-windows-10-insider-preview-build-16288-pc-build-15250-mobile/#7pLWQbj23JisfzV5.97/).<br/>
 

### Fixed
#### WSL
- Correctly initialize and report uid, gid, and mode for socket file descriptors [GH 2490]
- Additional improvements and bug fixes

#### Console
- No Console related changes in this release.

### LTP Results:
No change since 16273

## Build 16278

For general Windows information on build 162738 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/08/29/announcing-windows-10-insider-preview-build-16278-pc/#HMz6Xq7Su68WKi0t.97/).<br/>
 

### Fixed
#### WSL
- Explicitly unmap mapped views of file backed sections when tearing down LX MM state [GH 2415]
- Additional improvements and bug fixes

#### Console
- No Console related changes in this release.

### LTP Results:
No change since 16273

## Build 16275

For general Windows information on build 162735 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/08/25/announcing-windows-10-insider-preview-build-16275-pc-build-15245-mobile/#8QkxWqQbY37yZslV.97/).<br/>
 

### Fixed
#### WSL
- No WSL related changes in this release.

#### Console
- No Console related changes in this release.

### LTP Results:
No change since 16273

## Build 16273

For general Windows information on build 16273 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/08/23/announcing-windows-10-insider-preview-build-16273-pc/).<br/>
 

### Fixed
#### WSL
- Fixed an issue where DrvFs sometimes reported the wrong file type for directories [GH 2392]
- Allow creation of NETLINK_KOBJECT_UEVENT sockets to unblock programs that use uevent [GH 1121, 2293, 2242, 2295, 2235, 648, 637]
- Add support for non-blocking connect [GH 903, 1391, 1584, 1585, 1829, 2290, 2314]
- Implement CLONE_FS clone system call flag [GH 2242]
- Fix issues around not handling tabs or quotes correctly in NT interop [GH 1625, 2164]
- Resolve access denied error when trying to re-launch WSL instances [GH 651, 2095]
- Implement futex FUTEX_REQUEUE and FUTEX_CMP_REQUEUE operations [GH 2242]
- Fix permissions for various SysFs files [GH 2214]
- Fix Haskell stack hang during setup [GH 2290]
- Implement binfmt_misc 'C' 'O' and 'P' flags [GH 2103]
- Add /proc/sys/kernel /shmmax /shmmni & /threads-max [GH 1753]
- Add partial support for ioprio_set system call [GH 498]
- Stub SO_REUSEPORT & adding support for SO_PASSCRED for netlink sockets [GH 69]
- Return different error codes from RegisterDistribuiton if a distribution is currently being installed or uninstalled.
- Allow unregistration of partially installed WSL distributions via wslconfig.exe
- Fix python socket test hang from udp::msg_peek
- Additional improvements and bug fixes

#### Console
- No Console related changes in this release.

### LTP Results:
Total Tests: 1904<br/>
Total Skipped Tests: 209<br/>
Total Failures: 229<br/>
[LTP Test Run Logs](https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/16273)<br/>

## Build 16257

For general Windows information on build 16257 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/08/02/announcing-windows-10-insider-preview-build-16257-pc-build-15237-mobile/).<br/>
 

### Fixed
#### WSL
- Implement prlimit64 system call
- Add support for ulimit -n (setrlimit RLIMIT_NOFILE) [GH 1688]
- Stub MSG_MORE for TCP sockets [GH 2351]
- Fix invalid AT_EXECFN auxiliary vector behavior [GH 2133]
- Fix copy/paste behavior for console/tty, and add better full buffer handling [GH 2204, 2131]
- Set AT_SECURE in auxiliary vector for set-user-ID and set-group-ID programs [GH 2031]
- Psuedo-terminal master endpoint not handling TIOCPGRP [GH 1063]
- Fix lseek does to rewind directories in LxFs [GH 2310]
- /dev/ptmx locks up after heavy usage [GH 1882]
- Additional improvements and bug fixes

#### Console
- Fix for horizontal Lines/Underscores Everywhere [GH 2168]
- Fix for process order changed making NPM harder to close [GH 2170]
- Added our new color scheme: https://blogs.msdn.microsoft.com/commandline/2017/08/02/updating-the-windows-console-colors/ 

### LTP Results:
No change since 16251

### Syscall Support
Below are a list of new or enhanced syscalls that have some implementation in WSL. The syscalls on this list are supported in at least one scenario, but may not have all parameters supported at this time.

`prlimit64`<br/>

### Known Issues
#### [GitHub Issue 2392: Windows Folders not recognized by WSL ...](https://github.com/Microsoft/BashOnWindows/issues/2392)
In build 16257, WSL has issues when enumerating Windows files/folders via `/mnt/c/...`. 
This issue has been fixed and should be released in Insiders build during week commencing 8/14/2017.

<br/>

## Build 16251

For general Windows information on build 16251 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/07/26/announcing-windows-10-insider-preview-build-16251-pc-build-15235-mobile/).<br/>
 

### Fixed
#### WSL
- Remove beta tag from WSL optional component, see [blog post](https://blogs.msdn.microsoft.com/commandline/2017/07/28/windows-subsystem-for-linux-out-of-beta/) for details.
- Correctly initialize saved-set uid and gid for set-user-ID and set-group-ID binaries on exec [GH 962, 1415, 2072]
- Added support for ptrace PTRACE_O_TRACEEXIT [GH 555]
- Added support for ptrace PTRACE_GETFPREGS and PTRACE_GETREGSET with NT_FPREGSET [GH 555]
- Fixed ptrace to stop on ignored signals
- Additional improvements and bug fixes

#### Console
- No Console related changes in this release.

### LTP Results:
Number of Passing Tests: 768</br>
Number of Failing Tests: 244</br>
Number of Skipped Tests: 96</br>
[LTP Test Run Logs](https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/16251)<br/>

</br>

## Build 16241

For general Windows information on build 16241 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/07/13/announcing-windows-10-insider-preview-build-16241-pc-build-15230-mobile/).<br/>
 

### Fixed
#### WSL
- No WSL related changes in this release.

#### Console
- Fix for outputting the wrong character for the crossing-lines DEC, originally reported [here](https://www.reddit.com/r/Windows10/comments/6in82t/i_believe_ive_found_the_most_obscure_bug_ever/)
- Fix for no output text being displayed in codepage 65001 (utf8)
- Do not transfer changes made to one color's RGB values to other parts of the palette on selection change. This will make the console properties sheet a lot easier to use.
- Ctrl+S doesn't appear to work correctly
- Un-Bold/-Dim completely absent from ANSI escape codes [GH 2174]
- Console doesn't correctly support Vim color themes [GH 1706]
- Cannot paste particular characters [GH 2149]
- Reflow resize interacts strangely with resizing a bash window when stuff is on the edit/command line [GH ConEmu 1123]
- Ctrl-L leaves the screen dirty [GH 1978]
- Console rendering bug when displaying VT on HDPI [GH 1907]
- Japansese characters look strange with Unicode Character U+30FB [GH 2146]
- Additional improvements and bug fixes

</br>

## Build 16237

For general Windows information on build 16237 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/07/07/announcing-windows-10-insider-preview-build-16237-pc/).<br/>
 

### Fixed 
- Use default attributes for files without EAs in lxfs (root, root, 0000)
- Added support for distributions that use extended attributes
- Fix padding for entries returned by getdents and getdents64
- Fix permissions check for the shmctl SHM_STAT system call [GH 2068]
- Fixed incorrect initial epoll state for ttys [GH 2231]
- Fix DrvFs readdir not returning all entries [GH 2077]
- Fix LxFs readdir when files are unlinked [GH 2077]
- Allow unlinked drvfs files to be reopened through procfs
- Added global registry key override for disabling WSL features (interop / drive mounting)
- Fix incorrect block count in "stat" for DrvFs (and LxFs) [GH 1894]
- Additional improvements and bug fixes

</br>

## Build 16232

For general Windows information on build 16232 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/06/28/announcing-windows-10-insider-preview-build-16232-pc-build-15228-mobile/).<br/>
 

### Fixed 
- No WSL related changes in this release.

</br>

## Build 16226

For general Windows information on build 16226 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/06/21/announcing-windows-10-insider-preview-build-16226-pc/).<br/>
 

### Fixed 
- xattr related syscalls support (getxattr, setxattr, listxattr, removexattr).
- security.capablity xattr support.
- Improved compatibility with certain file systems and filters, including non-MS SMB servers. [GH #1952]
- Improved support for OneDrive placeholders, GVFS placeholders, and Compact OS compressed files.
- Additional improvements and bug fixes

</br>

## Build 16215

For general Windows information on build 16215 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/06/08/announcing-windows-10-insider-preview-build-16215-pc-build-15222-mobile/).<br/>
 

### Fixed 
- WSL no longer requires developer mode.
- Support directory junctions in drvfs.
- Handle uninstalling of WSL distribution appx packages.
- Update procfs to show private and shared mappings.
- Add ability for wslconfig.exe to clean up distributions that are partially installed or uninstalled.
- Added support for IP_MTU_DISCOVER for TCP sockets. [GH 1639, 2115, 2205]
- Infer protocol family for routes to AF_INADDR.
- Serial device improvements [GH 1929].

</br>

## Build 16199

For general Windows information on build 16199 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/05/17/announcing-windows-10-insider-preview-build-16199-pc-build-15215-mobile/).<br/>
 

### Fixed 
- No WSL related changes in these releases.

</br>

## Build 16193

For general Windows information on build 16193 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/05/11/announcing-windows-10-insider-preview-build-16193-pc-build-15213-mobile/).<br/>
 

### Fixed 
- Race condition between sending SIGCONT and a threadgroup terminating [GH 1973]
- change tty and pty devices to report FILE_DEVICE_NAMED_PIPE instead of FILE_DEVICE_CONSOLE [GH 1840]
- SSH fix for IP_OPTIONS
- Moved DrvFs mounting to init daemon [GH 1862, 1968, 1767, 1933]
- Added support in DrvFs for following NT symlinks. 

</br>

## Build 16184

For general Windows information on build 16184 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/04/28/announcing-windows-10-insider-preview-build-16184-pc-build-15208-mobile/).<br/>
 

### Fixed 
- Removed apt package maintenance task (lxrun.exe /update)
- Fixed output not showing up in from Windows processes in node.js [GH 1840] 
- Relax alignment requirements in lxcore [GH 1794] 
- Fixed handling of the AT_EMPTY_PATH flag in a numer of system calls.
- Fixed issue where deleting DrvFs files with open handles will cause the file to exhibit undefined behavior [GH 544,966,1357,1535,1615] 
- /etc/hosts will now inherit entries from the Windows hosts file (%windir%\system32\drivers\etc\hosts) [GH 1495] 

</br>

## Build 16179

For general Windows information on build 16179 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/04/19/announcing-windows-10-insider-preview-build-16179-pc-build-15205-mobile/).<br/>
 

### Fixed 
- No WSL changes this week.

</br>

## Build 16176

For general Windows information on build 16176 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/04/14/announcing-windows-10-insider-preview-build-16176-pc-build-15204-mobile/).<br/>
 

### Fixed

- [Enabled serial support](https://blogs.msdn.microsoft.com/wsl/2017/04/14/serial-support-on-the-windows-subsystem-for-linux/)
- Added IP socket option IP_OPTIONS [GH 1116]
- Implemented pwritev function (while uploading file to nginx/PHP-FPM) [GH 1506]
- Added IP socket options IP_MULTICAST_IF & IPV6_MULTICAST_IF [GH 990]
- Support for socket option IP_MULTICAST_LOOP & IPV6_MULTICAST_LOOP [GH 1678]
- Added IP(V6)_MTU socket option for apps node, traceroute, dig, nslookup, host
- Added IP socket option IPV6_UNICAST_HOPS
- [Filesystem Improvements](https://blogs.msdn.microsoft.com/wsl/2017/04/18/file-system-improvements-to-the-windows-subsystem-for-linux/)
	* Allow mounting of UNC paths
	* Enable CDFS support in drvfs
	* Correctly handle permissions for network file systems in drvfs
	* Add support for remote drives to drvfs
	* Enable FAT support in drvfs
- Additional fixes and Improvements

### LTP Results
No changes since 15042

</br>

## Build 16170

For general Windows information on build 16170 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/04/07/announcing-windows-10-insider-preview-build-16170-pc/).<br/>
 
We released a new [blog post](https://blogs.msdn.microsoft.com/wsl/2017/04/11/testing-the-windows-subsystem-for-linux/) discussing our efforts to test WSL.

### Fixed

- Support socket option IP_ADD_MEMBERSHIP & IPV6_ADD_MEMBERSHIP [GH 1678]
- Add support for PTRACE_OLDSETOPTIONS. [GH 1692] 
- Additional fixes and improvements 

### LTP Results
No changes since 15042

</br>

## Build 15046 to Windows 10 Creators Update
There are no more WSL fixes or features planned for inclusion in the Creators Update to Windows 10. Release notes for WSL will resume in the coming weeks for additions targeting the next major Windows Update. For general Windows information on build 15046 and future Insider releases visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/02/28/announcing-windows-10-insider-preview-build-15046-pc/). <br/><br/>
 <br/>

## Build 15042

For general Windows information on build 15042 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/02/24/announcing-windows-10-insider-preview-build-15042-pc-build-15043-mobile/).<br/>
 

### Fixed

- Fix for a deadlock when removing a path ending in ".."
- Fixed an issue where FIONBIO not returning 0 on success [GH 1683]
- Fixed issue with zero-length reads of inet datagram sockets
- Fix possible deadlock due to race condition in drvfs inode lookup [GH 1675]
- Extended support for unix socket ancillary data; SCM_CREDENTIALS and SCM_RIGHTS [GH 514, 613, 1326]
- Additional fixes and improvements 

### LTP Results:
Number of Passing Test: 737</br>
Number of non-Passing (failing, skipped, etc…): 255 

</br>

## Build 15031

For general Windows information on build 15031 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/02/08/announcing-windows-10-insider-preview-build-15031-pc/).<br/>
 

### Fixed

- Fixed a bug where time(2) would sporadically misbehave.
- Fixed and issue where *SIGPROCMASK syscalls could corrupt signal mask.
- Now return full command line length in WSL process creation notification. [GH 1632]
- WSL now reports thread exit through ptrace for GDB hangs. [GH 1196]
- Fixed bug where ptys would hang after heavy tmux IO. [GH 1358]
- Fixed timeout validation in many system calls (futex, semtimedop, ppoll, sigtimedwait, itimer, timer_create)
- Added eventfd EFD_SEMAPHORE support [GH 452]
- Additional fixes and improvements 

### LTP Results:
Number of Passing Test: 737</br>
Number of non-Passing (failing, skipped, etc…): 255 </br>
[LTP Test Run Logs] (https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/15031)<br/>

<br/>

## Build 15025

For general Windows information on build 15025 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/02/01/announcing-windows-10-insider-preview-build-15025-pc/).<br/>
 

### Fixed

- Fix for bug that broke grep 2.27 [GH 1578]
- Implemented EFD_SEMAPHORE flag for eventfd2 syscall [GH 452]
- Implemented /proc/[pid]/net/ipv6_route [GH 1608]
- Signal driven IO support for unix stream sockets [GH 393, 68]
- Support F_GETPIPE_SZ and F_SETPIPE_SZ [GH 1012]
- Implement recvmmsg() syscall [GH 1531]
- Fixed bug where epoll_wait() wasn't waiting [GH 1609]
- Implement /proc/version_signature
- Tee syscall now returns failure if both file descriptors refer to the same pipe
- Implemented correct behavior for SO_PEERCRED for Unix sockets
- Fixed tkill syscall invalid parameter handling
- Changes to increase the preformace of drvfs
- Minor fix for Ruby IO blocking
- Fixed recvmsg() returning EINVAL for the MSG_DONTWAIT flag for inet sockets [GH 1296]
- Additional fixes and improvements 

### LTP Results:
Number of Passing Test: 732</br>
Number of non-Passing (failing, skipped, etc…): 255 </br>
[LTP Test Run Logs] (https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/15025)<br/>

<br/>

## Build 15019

For general Windows information on build 15019 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/01/27/announcing-windows-10-insider-preview-build-15019-pc/).<br/>
 

### Fixed

- Fixed bug that incorrectly reported CPU usage in procfs for tools like htop (GH 823, 945, 971)
- When calling open() with O_TRUNC on an existing file inotify now generates IN_MODIFY before IN_OPEN
- Fixes to unix socket getsockopt SO_ERROR to enable postgress [GH 61, 1354]
- Implement /proc/sys/net/core/somaxconn for the GO language
- Apt-get package update background task now runs hidden from view
- Clear scope for ipv6 localhost (Spring-Framework(Java) failure).
- Additional fixes and improvements

### LTP Results:
Number of Passing Test: 714 </br>
Number of non-Passing (failing, skipped, etc…): 249 </br>
[LTP Test Run Logs] (https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/15019)<br/>

<br/>

## Build 15014
 
For general Windows information on build 15014 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/01/19/announcing-windows-10-insider-preview-build-15014-for-pc-and-mobile-hello-windows-insiders-today-we-are-excited-to-be-releasing-windows-10-insider-preview-build-15014-for-pc-and-mobile).<br/>
 
 
### Fixed
 
- Ctrl+C now works as intended
- htop and ps auxw now show correct resource utilization (GH #516)
- Basic translation of NT exceptions to signals. (GH #513)
- fallocate now fails with ENOSPC  when running out of space instead of EINVAL (GH #1571)
- Added /proc/sys/kernel/sem.
- Implemented semop and semtimedop system calls
- Fixed nslookup errors with IP_RECVTOS & IPV6_RECVTCLASS socket option (GH 69)
- Support for socket options IP_RECVTTL and IPV6_RECVHOPLIMIT 
- Additional fixes and improvements
 
### LTP Results:
Number of Passing Test: 709 </br>
Number of non-Passing (failing, skipped, etc…): 255 </br>
[LTP Test Run Logs](https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/15014)<br/>

### Syscall Summary
Total Syscalls: 384 </br>
Total Implemented: 235 </br>
Total Stubbed: 22 </br>
Total Unimplemented: 127 </br>
[Detailed Breakdown](https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/15014/Syscalls.txt)<br/>

<br/>

## Build 15007
 
For general Windows information on build 15007 visit the [Windows Blog]( https://blogs.windows.com/windowsexperience/2017/01/12/announcing-windows-10-insider-preview-build-15007-pc-mobile).<br/>
 
 
### Known Issue
 
- There is a known bug where the console does not recognize some Ctrl + <key> input.  This includes the ctrl-c command which will act as a normal ‘c’ keypress. 
 
  - Workaround: Map an alternate key to Ctrl+C. For example, to map Ctrl+K to Ctrl+C do:
`stty intr \^k`.  This mapping is per terminal and will have to be done *every* time bash is launched. Users can explore the option to include this in their `.bashrc`
 
### Fixed
 
- Corrected the issue where running WSL would consume 100% of a CPU core
- Socket option IP_PKTINFO, IPV6_RECVPKTINFO now supported. (GH #851, 987)
- Truncate network interface physical address to 16 bytes in lxcore (GH #1452, 1414, 1343, 468, 308)
- Additional fixes and improvements
 
### LTP Results:
Number of Passing Test: 709 </br>
Number of non-Passing (failing, skipped, etc…): 255 </br>
[LTP Test Run Logs] (https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/15007)<br/>

<br/>

## Build 15002

For general Windows information on build 15002 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/01/09/announcing-windows-10-insider-preview-build-15002-pc/).<br/>
 

### Known Issue

Two known issues:
- There is a known bug where the console does not recognize some Ctrl + <key> input.  This includes the ctrl-c command which will act as a normal ‘c’ keypress. 

  - Workaround: Map an alternate key to Ctrl+C. For example, to map Ctrl+K to Ctrl+C do:
`stty intr \^k`.  This mapping is per terminal and will have to be done *every* time bash is launched. Users can explore the option to include this in their `.bashrc`

- While WSL is running a system thread will consume 100% of a CPU core.  The root cause has been addressed and fixed internally. 

### Fixed
 
- All bash sessions must now be created at the same permission level.  Attempting to start a session at a different level will be blocked.  This means admin and non-admin consoles cannot run at the same time. (GH #626)
<br/>
- Implemented the following NETLINK_ROUTE messages (requires Windows admin)
     - RTM_NEWADDR (supports `ip addr add`)
     - RTM_NEWROUTE (supports `ip route add`)
     - RTM_DELADDR (supports `ip addr del`)
     - RTM_DELROUTE (supports `ip route del`)
- Scheduled task checking for packages to update will no longer run on a metered connection (GH #1371)
- Fixed error where piping gets stuck i.e. bash -c "ls -alR /" | bash -c "cat" (GH #1214)
- Implemented TCP_KEEPCNT socket option (GH #843)
- Implemented IP_MTU_DISCOVER INET socket option (GH #720, 717, 170, 69)
- Removed legacy functionality to run NT binaries from init with NT path lookup. (GH #1325)
- Fix mode of /dev/kmsg to allow group / other read access (0644) (GH #1321)
- Implemented /proc/sys/kernel/random/uuid  (GH #1092)
- Corrected error where process start time was showing as year 2432 (GH #974)
- Switched default TERM environment variable to xterm-256color (GH #1446)
- Modified the way that process commit is calculated during process fork. (GH #1286)
- Implemented /proc/sys/vm/overcommit_memory. (GH #1286)
- Implemented /proc/net/route file (GH #69)
- Fixed error where shortcut name was incorrectly localized (GH #696)
- Fixed elf parsing logic that is incorrectly validating the program headers must be less than (or equal to) PATH_MAX. (GH #1048)
- Implemented statfs callback for procfs, sysfs, cgroupfs, and binfmtfs (GH #1378)
- Fixed AptPackageIndexUpdate windows that won’t close (GH #1184, also discussed in GH #1193)
- Added ASLR personality  ADDR_NO_RANDOMIZE support. (GH #1148, 1128)
- Improved PTRACE_GETSIGINFO, SIGSEGV, for proper gdb stack traces during AV (GH #875)
- Elf parsing no longer fails for patchelf binaries. (GH #471)
- VPN DNS propagated to /etc/resolv.conf (GH #416, 1350)
- Improvements to TCP close for more reliable data transfer. (GH #610, 616, 1025, 1335)
- Now return correct error code when too many files are opened (EMFILE). (GH #1126, 2090)
- Windows Audit log now reports the image name in process create audit.
- Now gracefully fail when launching bash.exe from within a bash window
- Added error message when interop is unable to access a working directory under LxFs (i.e. notepad.exe .bashrc)
- Fixed issue where Windows path was truncated in WSL
- Additional fixes and improvements

### LTP Results:
Number of Passing Test: 690 </br>
Number of non-Passing (failing, skipped, etc…): 274 </br>
[LTP Test Run Logs] (https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/15002)<br/>

<br/>

### Syscall Support
Below are a list of new or enhanced syscalls that have some implementation in WSL. The syscalls on this list are supported in at least one scenario, but may not have all parameters supported at this time.

`shmctl`<br/>
`shmget`<br/>
`shmdt`<br/>
`shmat`<br/>
<br/>

## Build 14986

For general Windows information on build 14986 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/12/07/announcing-windows-10-insider-preview-build-14986-pc/).<br/>
 

### Fixed

- Fixed bugchecks with Netlink and Pty IOCTLs
- Kernel version now reports 4.4.0-43 for consistency with Xenial
- Bash.exe now launches when input directed to 'nul:' (GH #1259)
- Thread IDs now reported correctly in procfs (GH #967)
- IN_UNMOUNT | IN_Q_OVERFLOW | IN_IGNORED | IN_ISDIR flags now supported in inotify_add_watch() (GH #1280)
- Implement timer_create and related system calls.  This enables GHC support (GH #307)
- Fixed issue where ping returned a time of 0.000ms (GH #1296)
- Return correct error code when too many files are opened.
- Fixed issue in WSL where Netlink request for network interface data would fail with EINVAL if the interface's hardware address is 32-bytes (such as the Teredo interface)
   - Note that the Linux "ip" utility contains a bug where it will crash if WSL reports a 32-byte hardware address. This is a bug in "ip", not WSL. The “ip” utility hard-codes the length of the string buffer used to print the hardware address, and that buffer is too small to print a 32-byte hardware address.
- Additional fixes and improvements

### LTP Results:
Number of Passing Test: 669 </br>
Number of non-Passing (failing, skipped, etc…): 258 </br>
[LTP Test Run Logs] (https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/14986)<br/>

<br/>

### Syscall Support
Below are a list of new or enhanced syscalls that have some implementation in WSL. The syscalls on this list are supported in at least one scenario, but may not have all parameters supported at this time.

`timer_create`<br/>
`timer_delete`<br/>
`timer_gettime`<br/>
`timer_settime`<br/>
<br/>

## Build 14971

For general Windows information on build 14971 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/11/17/announcing-windows-10-insider-preview-build-14971-for-pc/).<br/>
 

### Fixed

 - Due to circumstances beyond our control there are no updates in this build for the Windows Subsystem for Linux.  Regularly scheduled updates will resume on the next release.

### LTP Results:
Unchanged from 14965 </br>
Number of Passing Test: 664 </br>
Number of non-Passing (failing, skipped, etc…): 263 </br>
[LTP Test Run Logs] (https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/14965)<br/>

<br/>

## Build 14965

For general Windows information on build 14965 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/11/09/announcing-windows-10-insider-preview-build-14965-for-mobile-and-pc/).<br/>
 

### Fixed

- Support for Netlink sockets NETLINK_ROUTE protocol's RTM_GETLINK and RTM_GETADDR (GH #468)
  - Enables ifconfig and ip commands for network enumeration
  - More information can be found in our [WSL Networking blog post] (https://blogs.msdn.microsoft.com/wsl/2016/11/08/225/).
- /sbin is now in the user's path by default
- NT user path now appended to the WSL path by default (i.e. you can now type notepad.exe without adding System32 to the Linux path)
- Added support for /proc/sys/kernel/cap_last_cap
- NT Binaries can now be launched from WSL when the current working directory contains non-ansi characters (GH #1254)
- Allow shutdown on disconnected unix stream socket.
- Added support for PR_GET_PDEATHSIG.
- Added support for CLONE_PARENT
- Fixed error where piping gets stuck i.e. bash -c "ls -alR /" | bash -c "cat" (GH #1214)
- Handle requests to connect to the current terminal.
- Mark /proc/<pid>/oom_score_adj as writable.
- Add /sys/fs/cgroup folder.
- sched_setaffinity should return number of affinity bits mask
- Fix ELF validation logic which incorrectly assumes interpreter paths must be less than 64 characters long. (GH #743)
- Open file descriptors can keep console window open (GH #1187)
- Fixeed error where rename() failed with trailing slash on target name (GH #1008)
- Implement /proc/net/dev file
- Fixed 0.000ms pings due to timer resolution.
- Implemented /proc/self/environ (GH #730)
- Additional bugfixes and improvements

### LTP Results:
Number of Passing Test: 664 </br>
Number of non-Passing (failing, skipped, etc…): 263 </br>
[LTP Test Run Logs] (https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/14965)<br/>

<br/>

## Build 14959

For general Windows information on build 14959 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/11/03/announcing-windows-10-insider-preview-build-14959-for-mobile-and-pc/#iI82GufJxMF3POU1.97).<br/>
 

### Fixed

- Improved Pico Process notification for Windows.  Additional information found on the [WSL Blog](https://blogs.msdn.microsoft.com/wsl/2016/11/01/wsl-antivirus-and-firewall-compatibility/).
- Improved stability with Windows interoperability 
- Fixed error 0x80070057 when launching bash.exe when Enterprise Data Protection (EDP) is enabled
- Additional bugfixes and improvements

### LTP Results:
Number of Passing Test: 665 </br>
Number of non-Passing (failing, skipped, etc…): 263 </br>
[LTP Test Run Logs] (https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/14959)<br/>

<br/>

## Build 14955

For general Windows information on build 14955 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/10/25/announcing-windows-10-insider-preview-build-14955-for-mobile-and-pc/#guGXQzKVFrZIDUYR.97).<br/>
 

### Fixed

 - Due to circumstances beyond our control there are no updates in this build for the Windows Subsystem for Linux.  Regularly scheduled updates will resume on the next release.

### LTP Results:
Number of Passing Test: 665 </br>
Number of non-Passing (failing, skipped, etc…): 263 </br>
[LTP Test Run Logs] (https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/14955)<br/>

<br/>

## Build 14951

For general Windows information on build 14951 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/10/19/announcing-windows-10-insider-preview-build-14951-for-mobile-and-pc/).<br/>
 

### New Feature: Windows / Ubuntu Interoperability
Windows binaries can now be invoked directly from the WSL command line.  This gives users the ability to interact with their Windows environment and system in a way that has not been possible.  As a quick example, it is now possible for users to run the following commands:
	
	```
	$ export PATH=$PATH:/mnt/c/Windows/System32
	$ notepad.exe
	$ ipconfig.exe | grep IPv4 | cut -d: -f2
	$ ls -la | findstr.exe foo.txt
	$ cmd.exe /c dir
	```
	
More information can be found at:

- [WSL Team Blog for Interop](https://blogs.msdn.microsoft.com/wsl/2016/10/19/windows-and-ubuntu-interoperability/)<br/>
- [MSDN Interop Documentation](https://msdn.microsoft.com/en-us/commandline/wsl/interop)<br/>

### Fixed

- Ubuntu 16.04 (Xenial) is now installed for all new WSL instances.  Users with existing 14.04 (Trusty) instances will not be automatically upgraded.
- Locale set during install is now displayed
- Terminal improvements including bug where redirecting a WSL process to a file does not always work
- Console lifetime should be tied to bash.exe lifetime
- Console window size should use visible size, not buffer size
- Additional bugfixes and improvements

### LTP Results:
Number of Passing Test: 665 </br>
Number of non-Passing (failing, skipped, etc…): 263 </br>
[LTP Test Run Logs] (https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/14951)<br/>

<br/>

## Build 14946

For general Windows information on build 14946 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/10/13/announcing-windows-10-insider-preview-build-14946-for-pc-and-mobile/#xj8GdVooEqo4H7H7.97).<br/>
 

### Fixed

- Fixed an issue that prevented creating WSL user accounts for users with NT usernames that contain spaces or quotes. 
- Change VolFs and DrvFs to return 0 for directory's link count in stat
- Support IPV6_MULTICAST_HOPS socket option.
- Limit to a single console I/O loop per tty. Example: the following command is possible:
    -  bash -c "echo data" | bash -c "ssh user@example.com 'cat > foo.txt'"
- replace spaces with tabs in /proc/cpuinfo (GH #1115)
- DrvFs now appears in mountinfo with a name that matches mounted Windows volume
- /home and /root now appear in mountinfo with correct names
- Additional bugfixes and improvements

### LTP Results:
Number of Passing Test: 665 </br>
Number of non-Passing (failing, skipped, etc…): 263 </br>
[LTP Test Run Logs] (https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/14946)<br/>

<br/>

## Build 14942

For general Windows information on build 14942 visit the [Windows Blog](https://aka.ms/onefourninefourtwoooooo).<br/>
 

### Fixed

- A number of bugchecks addressed, including the “ATTEMPTED EXECUTE OF NOEXECUTE MEMORY” networking crash which was blocking SSH
- inotifiy support for notifications generated from Windows applications on DrvFs is now in
- Implement TCP_KEEPIDLE and TCP_KEEPINTVL for mongod. (GH #695)
- Implement the pivot_root system call
- Implement socket option for SO_DONTROUTE
- Additional bugfixes and improvements


### LTP Results:
Number of Passing Test: 665 </br>
Number of non-Passing (failing, skipped, etc…): 263 </br>
[LTP Test Run Logs] (https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/14942)<br/>

### Syscall Support
Below are a list of new or enhanced syscalls that have some implementation in WSL. The syscalls on this list are supported in at least one scenario, but may not have all parameters supported at this time.

`pivot_root`<br/>
<br/>

## Build 14936

For general Windows information on build 14936 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/09/28/announcing-windows-10-insider-preview-build-14936-for-pc/).<br/>
 

Note: WSL will install Ubuntu version 16.04 (Xenial) instead of Ubuntu 14.04 (Trusty) in an upcoming release.  This change will apply to Insiders installing new instances (lxrun.exe /install or first run of bash.exe).  Existing instances with Trusty will not be upgraded automatically. Users can upgrade their Trusty image to Xenial using the do-release-upgrade command.

### Known Issue
WSL is experiencing an issue with some socket implementations.  The bugcheck manifests itself as a crash with the error “ATTEMPTED EXECUTE OF NOEXECUTE MEMORY”.  The most common manifestation of this issue is a crash when using ssh.  The root cause is fixed on internal builds and will be pushed to Insiders at the earliest opportunity.

### Fixed

- Implemented the chroot system call
- Improvements in inotify ~~including support for notifications generated from Windows applications on DrvFs~~
  - Correction: Inotify support for changes originating from Windows applications not available at this time.
- Socket binding to IPV6::<port n> now supports IPV6_V6ONLY  (GH #68, #157, #393, #460, #674, #740, #982, #996)
- WNOWAIT behavior for waitid systemcall implemented (GH #638)
- Support for IP socket options IP_HDRINCL and IP_TTL
- Zero-length read() should return immediately (GH #975)
- Correctly handle filenames and filename prefixes that don't include a NULL terminator in a .tar file.
- epoll support for /dev/null
- Fix /dev/alarm time source
- Bash -c now able to redirect to a file
- Additional bugfixes and improvements

### LTP Results:
Number of Passing Test: 664 </br>
Number of non-Passing (failing, skipped, etc…): 264 </br>
[LTP Test Run Logs] (https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/14936)<br/>

### Syscall Support
Below are a list of new or enhanced syscalls that have some implementation in WSL. The syscalls on this list are supported in at least one scenario, but may not have all parameters supported at this time.

`chroot`<br/>
<br/>

## Build 14931

For general Windows information on build 14931 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/09/21/announcing-windows-10-insider-preview-build-14931-for-pc/).<br/>
 

### Fixed

 - Due to circumstances beyond our control there are no updates in this build for the Windows Subsystem for Linux.  Regularly scheduled updates will resume in the next release.

<br/>

## Build 14926

For general Windows information on build 14926 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/09/14/announcing-windows-10-insider-preview-build-14926-for-pc-and-mobile/).<br/>
 

### Fixed

- Ping now works in consoles which do not have administrator privileges
- Ping6 now supported, also without administrator privileges
- Inotify support for files modified through WSL. (GH #216)  
  - Flags supported:
    - inotify_init1: LX_O_CLOEXEC, LX_O_NONBLOCK
    - inotify_add_watch events: LX_IN_ACCESS, LX_IN_MODIFY, LX_IN_ATTRIB, LX_IN_CLOSE_WRITE, LX_IN_CLOSE_NOWRITE, LX_IN_OPEN, LX_IN_MOVED_FROM, LX_IN_MOVED_TO, LX_IN_CREATE, LX_IN_DELETE, LX_IN_DELETE_SELF, LX_IN_MOVE_SELF
    - inotify_add_watch attributes: LX_IN_DONT_FOLLOW, LX_IN_EXCL_UNLINK, LX_IN_MASK_ADD, LX_IN_ONESHOT, LX_IN_ONLYDIR
    - read output: LX_IN_ISDIR, LX_IN_IGNORED
  - Known issue: Modifying files from Windows applications does not generate any events
- Unix socket now supports SCM_CREDENTIALS 

### LTP Results:
Number of Passing Test: 651 </br>
Number of non-Passing (failing, skipped, etc…): 258 </br>
[LTP Test Run Logs] (https://github.com/Microsoft/CommandLine-Documentation/tree/live/LTP_Results/14926)<br/>

<br/>

## Build 14915

For general Windows information on build 14915 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/08/31/announcing-windows-10-insider-preview-build-14915-for-pc-and-mobile).<br/>
 

### Fixed
-  Socketpair for unix datagram sockets (GH #262)
- Unix socket support for SO_REUSEADDR
- UNIX socket support for SO_BROADCAST (GH #568)
- Unix socket support for SOCK_SEQPACKET (GH #758, #546)
- Adding support for unix datagram socket send, recv and shutdown
- Fix bugcheck due to invalid mmap parameter validation for non-fixed addresses. (GH #847)
- Support for suspend / resume of terminal states
- Support for TIOCPKT ioctl to unblock the Screen utility (GH #774) 
	- Known issue: Function keys not operational
- Corrected a race in TimerFd that could cause a freed member 'ReaderReady' to be accessed by LxpTimerFdWorkerRoutine (GH #814)		 
- Enable restartable system call support for futex, poll, and clock_nanosleep
- Added bind mount support
- unshare for mount namespace support
	- Known issue: When creating a new mount namespace with `unshare(CLONE_NEWNS)` the current working directory will continue to point to the old namespace
- Additional improvements and bug fixes

<br/>

## Build 14905

For general Windows information on build 14905 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/08/17/announcing-windows-10-insider-preview-build-14905-for-pc-mobile/).<br/>
 

### Fixed
- Restartable system calls are now supported (GH #349, GH #520)
- Symlinks to directories ending in / now operational (GH #650)
- Implemented RNDGETENTCNT ioctl for /dev/random
- Implemented the /proc/[pid]/mounts, /proc/[pid]/mountinfo and /proc/[pid]/mountstats files
- Additional bugfixes and improvements

</br>

## Build 14901
First Insider build for the post Windows 10 Anniversary Update release.

For general Windows information on build 14901 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/08/11/announcing-windows-10-insider-preview-build-14901-for-pc/).<br/>
 

### Fixed
- Fixed trailing slash issue
    - Commands such as `$ mv a/c/ a/b/` now work
- Installing now prompts if Ubuntu locale should be set to Windows locale
- Procfs support for ns folder
- Added mount and unmount for tmpfs, procfs and sysfs file systems
- Fix mknod[at] 32-bit ABI signature
- Unix sockets moved to dispatch model
- INET socket recv buffer size set using the setsockopt should be honored
- Implement MSG_CMSG_CLOEXEC unix socket receive message flag
- Linux process stdin/stdout pipe redirection (GH #2)
	- Allows for piping of bash -c commands in CMD.  Example:  >dir | bash -c "grep foo"
- Bash can now be installed on systems with multiple pagefiles (GH #538, #358) 
- Default INET Socket buffer size should match that of default Ubuntu setup
- Align xattr syscalls to listxattr
- Only return interfaces with a valid IPv4 address from SIOCGIFCONF
- Fix signal default action when injected by ptrace
- implement /proc/sys/vm/min_free_kbytes
- Use machine context register values when restoring context in sigreturn
	- This resolves the issue where java and javac were hanging for some users
- Implement /proc/sys/kernel/hostname
 
### Syscall Support
Below are a list of new or enhanced syscalls that have some implementation in WSL. The syscalls on this list are supported in at least one scenario, but may not have all parameters supported at this time.

`waitid`<br/>
`epoll_pwait`<br/>

<br/>

## Build 14388 to Windows 10 Anniversary Update
For general Windows information on build 14388 visit the [Windows Blog](https://aka.ms/14388wip). <br/>
 
### Fixed
- Fixes to prepare for the Windows 10 Anniversary Update on 8/2
  - More information about WSL in the Anniversary Update can be found on our [blog](https://blogs.msdn.microsoft.com/wsl/)

<br/>

## Build 14376
For general Windows information on build 14376 visit the [Windows Blog] (https://blogs.windows.com/windowsexperience/2016/06/28/announcing-windows-10-insider-preview-build-14376-for-pc-and-mobile/). <br/>
 
### Fixed
- Removed some instances where apt-get hangs (GH #493)
- Fixed an issue where empty mounts were not handled correctly
- Fixed an issue where ramdisks were not mounted correctly
- Change unix socket accept to support flags (partial GH #451)
- Fixed common network related bluescreen
- Fixed bluescreen when accessing /proc/[pid]/task (GH #523)
- Fixed high CPU utilization for some pty scenarios (GH #488, #504)
- Additional bugfixes and improvements

<br/>

## Build 14371
For general Windows information on build 14371 visit the [Windows Blog] (https://blogs.windows.com/windowsexperience/2016/06/22/announcing-windows-10-insider-preview-build-14371-for-pc/). <br/>
 
### Fixed
- Corrected timing race with SIGCHLD and wait() when using ptrace
- Corrected some behavior when paths have a trailing /  (GH #432)
- Fixed issue with rename/unlink failing due to open handles to children
- Additional bugfixes and improvements

<br/>

## Build 14366
For general Windows information on build 14366 visit the [Windows Blog] (https://blogs.windows.com/windowsexperience/2016/06/14/announcing-windows-10-insider-preview-build-14366-mobile-build-14364/). <br/>
 
###Fixed
- Fix in file creation through symlinks
-	Added listxattr for Python (GH 385)
-	Additional bugfixes and improvements

###Syscall Support
-	Below are a list of new or enhanced syscalls that have some implementation in WSL. The syscalls on this list are supported in at least one scenario, but may not have all parameters supported at this time.

`listxattr`<br/>
<br/>

## Build 14361
For general Windows information on build 14361 visit the [Windows Blog](http://aka.ms/wip14361). <br/>
 
### Fixed
- DrvFs is now case sensitive when running in Bash on Ubuntu on Windows.
  - Users may case.txt and CASE.TXT on their /mnt/c drives
  - Case sensitivity is only supported within Bash on Ubuntu on Windows. When outside of Bash NTFS will report the files correctly, but unexpected behavior may occur interacting with the files from Windows.
  - The root of each volume (i.e. /mnt/c) is not case sensitive
  - More information on handling these files in Windows can be found [here](https://support.microsoft.com/en-us/kb/100625).
- Greatly enhanced pty / tty support.  Applications like TMUX now supported (GH #40)
- Fixed install issue where user accounts not always created
- Optimized command line arg structure allowing for extremely long argument list. (GH #153)
- Now able to delete and chmod read_only files from DrvFs
- Fixed some instances where the terminal hangs on disconnect (GH #43)
- chmod and chown now work on tty devices
- Allow connection to 0.0.0.0 and :: as localhost (GH #388)
- Sendmsg/recvmsg now handle an IO vector length of >1 (partial GH #376)
- Users can now opt-out of auto-generated hosts file (GH #398)
- Automatically match Linux locale to the NT locale during install (GH #11)
- Added the /proc/sys/vm/swappiness file (GH #306)
- strace now exits correctly
- Allow pipes to be reopened through /proc/self/fd (GH #222)
- Hide directories under %LOCALAPPDATA%\lxss from DrvFs (GH #270)
- Better handling of bash.exe ~.  Commands like “bash ~ -c ls” now supported (GH #467)
- Sockets now notify epoll read available during shutdown (GH #271)
- lxrun /uninstall does a better job of deleting the files and folders
- Corrected ps -f (GH #246)
- Improved support for x11 apps such as xEmacs (GH #481)
- Updated initial thread stack size to match default Ubuntu setting and reporting the size correctly to the get_rlimit syscall (GH #172, #258)
- Improved reporting of pico process image names (e.g., for auditing)
- Implemented /proc/mountinfo for df command
- Fixed symlink error code for child name . and ..
- Additional improvements bugfixes and improvements

### Syscall Support
Below are a list of new or enhanced syscalls that have some implementation in WSL. The syscalls on this list are supported in at least one scenario, but may not have all parameters supported at this time.

`GETTIMER`<br/>
`MKNODAT`<br/>
`RENAMEAT`<br/>
`SENDFILE`<br/>
`SENDFILE64`<br/>
`SYNC_FILE_RANGE`<br/>
<br/>

## Build 14352
For general Windows information on build 14352 visit the [Windows Blog](http://aka.ms/wip14352).<br/>
 

### Fixed
- Fixed issue where large files were not downloaded / created correctly.  This should unblock npm and other scenarios (GH #3, GH #313)
- Removed some instances where sockets hang
- Corrected some ptrace errors
- Fixed issue with WSL allowing filenames longer than 255 characters
- Improved support for non-English characters
- Add current Windows timezone data and set as default
- Unique device id’s for each mount point (jre fix – GH #49)
- Correct issue with paths containing “.” and “..”
- Added Fifo support (GH #71)
- Updated format of resolv.conf to match native Ubuntu format
- Some procfs cleanup
- Enabled ping for Administrator consoles (GH #18)
 
### Syscall Support
Below are a list of new or enhanced syscalls that have some implementation in WSL. The syscalls on this list are supported in at least one scenario, but may not have all parameters supported at this time.

`FALLOCATE`<br/>
`EXECVE`<br/>
`LGETXATTR`<br/>
`FGETXATTR`<br/>
<br/>

## Build 14342
For general Windows information on build 14342 the [Windows Blog](http://aka.ms/wip14342). <br/>
 
Information on VolFs and DriveFs can be found on the [WSL Blog](https://blogs.msdn.microsoft.com/wsl). <br/>

### Fixed
- Fixed install issue when the Windows user had Unicode characters in the username
- The apt-get update udev workaround in the FAQ is now provided by default on first run
- Enabled symlinks in DriveFs (/mnt/<drive>) directories
- Symlinks now work between DriveFs and VolFs
- Addressed top level path parsing issue: ls .// will now work as expected
- npm install on DriveFs and the -g options are now working
- Fixed issue preventing PHP server from launching
- Updated default environment values, such as $PATH to closer match native Ubuntu
- Added a weekly maintenance task in Windows to update the apt package cache
- Fixed issue with ELF header validation, WSL now supports all Melkor options
- Zsh shell is functional
- Precompiled Go binaries are now supported
- Prompting on Bash.exe first run is now localized correctly
- /proc/meminfo now returns correct information
- Sockets now supported in VFS
- /dev now mounted as tempfs
- Fifo now supported
- Multi-core systems now showing correctly in /proc/cpuinfo
- Additional improvements and error messages downloading during first run
- Syscall improvements and bugfixes. Supported syscall list below.
- Additional bugfixes and improvements

### Known Issues
- Not resolving ‘..’ correctly on DriveFs in some cases

### Syscall Support
Below are a list of new or enhanced syscalls that have some implementation in WSL. The syscalls on this list are supported in at least one scenario, but may not have all parameters supported at this time.

`FCHOWNAT`<br/>
`GETEUID`<br/>
`GETGID`<br/>
`GETRESUID`<br/>
`GETXATTR`<br/>
`PTRACE`<br/>
`SETGID`<br/>
`SETGROUPS`<br/>
`SETHOSTNAME`<br/>
`SETXATTR`<br/>
<br/>

## Build 14332

For general Windows information on build 14332 visit the [Windows Blog](http://aka.ms/wip14332). <br/>
 

### Fixed
- Better resolv.conf generation including prioritizing DNS entries
- Issue with moving files and directories between /mnt and non-/mnt drives 
- Tar files can now be created with symlinks
- Added default /run/lock directory on instance creation
- Update /dev/null to return proper stat info
- Additional errors when downloading during first run
- Syscall improvements and bugfixes. Supported syscall list below.
- Additional improvements bugfixes and improvements

### Syscall Support
Below is the new syscall that has some implementation in WSL. The syscall on this list is supported in at least one scenario, but may not have all parameters supported at this time.

`READLINKAT`<br/>
<br/>

## Build 14328

For general Windows information on build 14332 visit the [Windows Blog](http://aka.ms/wip14328). <br/>
 

### New Features
* Now support Linux users.  Installing Bash on Ubuntu on Windows will prompt for creation of a Linux user.  For more information, visit http://aka.ms/wslusers
* Hostname is now set to the Windows computer name, no more @localhost
* For more information on build 14328, visit: http://aka.ms/wip14328

### Fixed
* Symlink improvements for non /mnt/<drive> files
    * npm install now works
    * jdk / jre now installable using instructions found [here](http://xubuntugeek.blogspot.com/2012/09/how-to-install-oracle-jdk-7-manually-in.html).
    * known issue: symlinks do not work for Windows mounts.  Functionality will be available in a later build
* top and htop now display
* Additional error messages for some install failures
* Syscall improvements and bugfixes.  Supported syscall list below.
* Additional improvements bugfixes and improvements

### Syscall Support
Below is a list of syscalls that have some implementation in WSL.  Syscalls on this list are supported in at least one scenario, but may not have all parameters supported at this time.

`ACCEPT`<br/>
`ACCEPT4`<br/>
`ACCESS`<br/>
`ALARM`<br/>
`ARCH_PRCTL`<br/>
`BIND`<br/>
`BRK`<br/>
`CAPGET`<br/>
`CAPSET`<br/>
`CHDIR`<br/>
`CHMOD`<br/>
`CHOWN`<br/>
`CLOCK_GETRES`<br/>
`CLOCK_GETTIME`<br/>
`CLOCK_NANOSLEEP`<br/>
`CLONE`<br/>
`CLOSE`<br/>
`CONNECT`<br/>
`CREAT`<br/>
`DUP`<br/>
`DUP2`<br/>
`DUP3`<br/>
`EPOLL_CREATE`<br/>
`EPOLL_CREATE1`<br/>
`EPOLL_CTL`<br/>
`EPOLL_WAIT`<br/>
`EVENTFD`<br/>
`EVENTFD2`<br/>
`EXECVE`<br/>
`EXIT`<br/>
`EXIT_GROUP`<br/>
`FACCESSAT`<br/>
`FADVISE64`<br/>
`FCHDIR`<br/>
`FCHMOD`<br/>
`FCHMODAT`<br/>
`FCHOWN`<br/>
`FCHOWNAT`<br/>
`FCNTL64`<br/>
`FDATASYNC`<br/>
`FLOCK`<br/>
`FORK`<br/>
`FSETXATTR`<br/>
`FSTAT64`<br/>
`FSTATAT64`<br/>
`FSTATFS64`<br/>
`FSYNC`<br/>
`FTRUNCATE`<br/>
`FTRUNCATE64`<br/>
`FUTEX`<br/>
`GETCPU`<br/>
`GETCWD`<br/>
`GETDENTS`<br/>
`GETDENTS64`<br/>
`GETEGID`<br/>
`GETEGID16`<br/>
`GETEUID`<br/>
`GETEUID16`<br/>
`GETGID`<br/>
`GETGID16`<br/>
`GETGROUPS`<br/>
`GETPEERNAME`<br/>
`GETPGID`<br/>
`GETPGRP`<br/>
`GETPID`<br/>
`GETPPID`<br/>
`GETPRIORITY`<br/>
`GETRESGID`<br/>
`GETRESGID16`<br/>
`GETRESUID`<br/>
`GETRESUID16`<br/>
`GETRLIMIT`<br/>
`GETRUSAGE`<br/>
`GETSID`<br/>
`GETSOCKNAME`<br/>
`GETSOCKOPT`<br/>
`GETTID`<br/>
`GETTIMEOFDAY`<br/>
`GETUID`<br/>
`GETUID16`<br/>
`GETXATTR`<br/>
`GET_ROBUST_LIST`<br/>
`GET_THREAD_AREA`<br/>
`INOTIFY_ADD_WATCH`<br/>
`INOTIFY_INIT`<br/>
`INOTIFY_RM_WATCH`<br/>
`IOCTL`<br/>
`IOPRIO_GET`<br/>
`IOPRIO_SET`<br/>
`KEYCTL`<br/>
`KILL`<br/>
`LCHOWN`<br/>
`LINK`<br/>
`LINKAT`<br/>
`LISTEN`<br/>
`LLSEEK`<br/>
`LSEEK`<br/>
`LSTAT64`<br/>
`MADVISE`<br/>
`MKDIR`<br/>
`MKDIRAT`<br/>
`MKNOD`<br/>
`MLOCK`<br/>
`MMAP`<br/>
`MMAP2`<br/>
`MOUNT`<br/>
`MPROTECT`<br/>
`MREMAP`<br/>
`MSYNC`<br/>
`MUNLOCK`<br/>
`MUNMAP`<br/>
`NANOSLEEP`<br/>
`NEWUNAME`<br/>
`OPEN`<br/>
`OPENAT`<br/>
`PAUSE`<br/>
`PERF_EVENT_OPEN`<br/>
`PERSONALITY`<br/>
`PIPE`<br/>
`PIPE2`<br/>
`POLL`<br/>
`PPOLL`<br/>
`PRCTL`<br/>
`PREAD64`<br/>
`PROCESS_VM_READV`<br/>
`PROCESS_VM_WRITEV`<br/>
`PSELECT6`<br/>
`PTRACE`<br/>
`PWRITE64`<br/>
`READ`<br/>
`READLINK`<br/>
`READV`<br/>
`REBOOT`<br/>
`RECV`<br/>
`RECVFROM`<br/>
`RECVMSG`<br/>
`RENAME`<br/>
`RMDIR`<br/>
`RT_SIGACTION`<br/>
`RT_SIGPENDING`<br/>
`RT_SIGPROCMASK`<br/>
`RT_SIGRETURN`<br/>
`RT_SIGSUSPEND`<br/>
`RT_SIGTIMEDWAIT`<br/>
`SCHED_GETAFFINITY`<br/>
`SCHED_GETPARAM`<br/>
`SCHED_GETSCHEDULER`<br/>
`SCHED_GET_PRIORITY_MAX`<br/>
`SCHED_GET_PRIORITY_MIN`<br/>
`SCHED_SETAFFINITY`<br/>
`SCHED_SETPARAM`<br/>
`SCHED_SETSCHEDULER`<br/>
`SCHED_YIELD`<br/>
`SELECT`<br/>
`SEND`<br/>
`SENDMMSG`<br/>
`SENDMSG`<br/>
`SENDTO`<br/>
`SETDOMAINNAME`<br/>
`SETGID`<br/>
`SETGROUPS`<br/>
`SETHOSTNAME`<br/>
`SETITIMER`<br/>
`SETPGID`<br/>
`SETPRIORITY`<br/>
`SETREGID`<br/>
`SETRESGID`<br/>
`SETRESUID`<br/>
`SETREUID`<br/>
`SETRLIMIT`<br/>
`SETSID`<br/>
`SETSOCKOPT`<br/>
`SETTIMEOFDAY`<br/>
`SETUID`<br/>
`SETXATTR`<br/>
`SET_ROBUST_LIST`<br/>
`SET_THREAD_AREA`<br/>
`SET_TID_ADDRESS`<br/>
`SHUTDOWN`<br/>
`SIGACTION`<br/>
`SIGALTSTACK`<br/>
`SIGPENDING`<br/>
`SIGPROCMASK`<br/>
`SIGRETURN`<br/>
`SIGSUSPEND`<br/>
`SOCKET`<br/>
`SOCKETCALL`<br/>
`SOCKETPAIR`<br/>
`SPLICE`<br/>
`STAT64`<br/>
`STATFS64`<br/>
`SYMLINK`<br/>
`SYMLINKAT`<br/>
`SYNC`<br/>
`SYSINFO`<br/>
`TEE`<br/>
`TGKILL`<br/>
`TIME`<br/>
`TIMERFD_CREATE`<br/>
`TIMERFD_GETTIME`<br/>
`TIMERFD_SETTIME`<br/>
`TIMES`<br/>
`TKILL`<br/>
`TRUNCATE`<br/>
`TRUNCATE64`<br/>
`UMASK`<br/>
`UMOUNT`<br/>
`UMOUNT2`<br/>
`UNLINK`<br/>
`UNLINKAT`<br/>
`UNSHARE`<br/>
`UTIME`<br/>
`UTIMENSAT`<br/>
`UTIMES`<br/>
`VFORK`<br/>
`WAIT4`<br/>
`WAITPID`<br/>
`WRITE`<br/>
`WRITEV`<br/>
