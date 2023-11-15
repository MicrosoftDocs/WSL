---
title: Release Notes for WSL 
description: Read release notes for the Windows Subsystem for Linux. These release notes include fixed issues and are updated weekly.
keywords: release notes, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu
author: benhillis
ms.date: 09/27/2021
ms.topic: article
---

# Release Notes for Windows Subsystem for Linux

## Build 21364

For general Windows information on build 21364 visit the [Windows blog](https://blogs.windows.com/windows-insider/2021/04/21/announcing-windows-10-insider-preview-build-21364/).

- GUI apps are now available! For more information see [this blog post](https://devblogs.microsoft.com/commandline/the-initial-preview-of-gui-app-support-is-now-available-for-the-windows-subsystem-for-linux-2/).
- Resolve error when accessing files via \\\\wsl.localhost\\.
- Fix potential deadlock in LxssManager service.

## Build 21354

For general Windows information on build 21354 visit the [Windows blog](https://blogs.windows.com/windows-insider/2021/04/07/announcing-windows-10-insider-preview-build-21354/).

- Switch the \\wsl prefix to \\wsl.localhost to avoid issues when there is a machine on the network named "wsl". \\wsl$ will continue to work.
- Enable Linux quick access icon for wow processes.
- Update issue where version 2 was always being passed via wslapi RegisterDistribution.
- Change the fmask of the /usr/lib/wsl/lib directory to 222 so files are marked as executable [GH 3847]
- Fix wsl service crash if Virtual Machine Platform is not enabled.

## Build 21286

For general Windows information on build 21286 visit the [Windows blog](https://blogs.windows.com/windows-insider/2021/01/06/announcing-windows-10-insider-preview-build-21286/).

- Introduce wsl.exe --cd command to set current working directory of a command.
- Improve mapping of NTSTATUS to Linux error codes. [GH 6063]
- Improve wsl.exe --mount error reporting.
- Added an option to /etc/wsl.conf to enable start up commands:

```console
[boot]
command=<string>
```

## Build 20226

For general Windows information on build 20226 visit the [Windows blog](https://blogs.windows.com/windows-insider/2020/09/30/announcing-windows-10-insider-preview-build-20226/).

- Fix crash in LxssManager service. [GH 5902]

## Build 20211

For general Windows information on build 20211 visit the [Windows blog](https://blogs.windows.com/windows-insider/2020/09/10/announcing-windows-10-insider-preview-build-20211/).

- Introduce `wsl.exe --mount` for mounting physical or virtual disks. For more information see [Access Linux filesystems in Windows and WSL 2](https://devblogs.microsoft.com/commandline/access-linux-filesystems-in-windows-and-wsl-2/).
- Fix crash in LxssManager service when checking if the VM is idle. [GH 5768]
- Support for compressed VHD files. [GH 4103]
- Ensure that Linux user mode libs installed to c:\windows\system32\lxss\lib are preserved across OS upgrade. [GH 5848]
- Added the ability to list available distributions that can be installed with `wsl --install --list-distributions`.
- WSL instances are now terminated when the user logs off.

## Build 20190

For general Windows information on build 20190 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2020/08/12/announcing-windows-10-insider-preview-build-20190/).

- Fix bug preventing WSL1 instances from launching. [GH 5633]
- Fix hang when redirecting Windows process output. [GH 5648]
- Add %userprofile%\\.wslconfig option to control the VM idle timeout (wsl2.vmIdleTimeout=<time_in_ms>).
- Support launching app execution aliases from WSL.
- Added support for installing the WSL2 kernel and distributions to wsl.exe --install.

## Build 20175

For general Windows information on build 20175 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2020/07/22/announcing-windows-10-insider-preview-build-20175/).

- Adjust default memory assignment of WSL2 VM to be 50% of host memory or 8GB, whichever is less [GH 4166].
- Change \\\\wsl$ prefix to \\\\wsl to support URI parsing. The old \\\\wsl$ path is still supported.
- Enable nested virtualization for WSL2 by default on amd64. You can disable this via %userprofile%\\.wslconfig ([wsl2] nestedVirtualization=false).
- Make wsl.exe --update demand start Microsoft Update.
- Support renaming over a read-only file in DrvFs.
- Ensure error messages are always printed in the correct codepage.

## Build 20150

For general Windows information on build 20150 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2020/06/17/announcing-windows-10-insider-preview-build-20150/).

- WSL2 GPU compute see [Windows blog](https://blogs.windows.com/windowsexperience/2020/06/17/announcing-windows-10-insider-preview-build-20150/) for more information.
- Introduce wsl.exe --install command line option to easily set up WSL.
- Introduce wsl.exe --update command line option to manage updates to the WSL2 kernel. 
- Set WSL2 as the default.
- Increase WSL2 vm graceful shutdown timeout.
- Fix virtio-9p race condition when mapping device memory.
- Don't run an elevated 9p server if UAC is disabled.

## Build 19640

For general Windows information on build 19640 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2020/06/03/announcing-windows-10-insider-preview-build-19640/).

- [WSL2] Stability improvements for virtio-9p (drvfs).

## Build 19555

For general Windows information on build 19555 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2020/01/30/announcing-windows-10-insider-preview-build-19555/).

- [WSL2] Use a memory cgroup to limit the amount of memory used by install and conversion operations [GH 4669]
- Make wsl.exe present when the Windows Subsystem for Linux optional component is not enabled to improve feature discoverability.
- Change wsl.exe to print help text if the WSL optional component is not installed
- Fix race condition when creating instances
- Create wslclient.dll that contains all command line functionality
- Prevent crash during LxssManagerUser service stop
- Fix wslapi.dll fast fail when distroName parameter is NULL

## Build 19041

For general Windows information on build 19041 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2019/12/10/announcing-windows-10-insider-preview-build-19041/).

- [WSL2] Clear the signal mask before launching the processes
- [WSL2] Update Linux kernel to 4.19.84
- Handle creation of /etc/resolv.conf symlink when the symlink is non-relative

## Build 19028

For general Windows information on build 19028 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2019/11/19/announcing-windows-10-insider-preview-build-19028/).

- [WSL2] Update Linux kernel to 4.19.81
- [WSL2] Change the default permission of /dev/net/tun to 0666 [GH 4629]
- [WSL2] Tweak default amount of memory assigned to Linux VM to be 80% of host memory
- [WSL2] fix interop server to handle requests with a timeout so bad callers cannot hang the server

## Build 19018

For general Windows information on build 19018 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2019/11/05/announcing-windows-10-insider-preview-build-19018/).

- [WSL2] Use cache=mmap as the default for 9p mounts to fix dotnet apps
- [WSL2] Fixes for localhost relay [GH 4340]
- [WSL2] Introduce a cross-distro shared tmpfs mount for sharing state between distros
- Fix restoring persistent network drive for \\\\wsl$

## Build 19013

For general Windows information on build 19013 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2019/10/29/announcing-windows-10-insider-preview-build-19013/).

- [WSL2] Improve memory performance of WSL utility VM. Memory that is no longer in use will be freed back to the host.
- [WSL2] Update kernel version to 4.19.79. (add CONFIG_HIGH_RES_TIMERS, CONFIG_TASK_XACCT, CONFIG_TASK_IO_ACCOUNTING, CONFIG_SCHED_HRTICK, and CONFIG_BRIDGE_VLAN_FILTERING).
- [WSL2] Fix input relay to handle cases where stdin is a pipe handle that is not closed [GH 4424]
- Make the check for \\\\wsl$ case-insensitive.

```console
[wsl2]
pageReporting = <bool>    # Enable or disable the free memory page reporting feature (default true).
idleThreshold = <integer> # Set the idle threshold for memory compaction, 0 disables the feature (default 1).
```

## Build 19002
For general Windows information on build 19002 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2019/10/17/announcing-windows-10-insider-preview-build-19002/).

* [WSL] Fix issue with handling of some Unicode characters: https://github.com/microsoft/terminal/issues/2770
* [WSL] Fix rare cases where distros could be unregistered if launched immediately after a build-to-build upgrade.
* [WSL] Fix minor issue with wsl.exe --shutdown where instance idle timers were not cancelled.

## Build 18995
For general Windows information on build 18995 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2019/10/03/announcing-windows-10-insider-preview-build-18995/).

* [WSL2] Fix an issue where DrvFs mounts stopped working after an operation was interrupted (e.g. ctrl-c) [GH 4377]
* [WSL2] Fix handling of very large hvsocket messages [GH 4105]
* [WSL2] Fix issue with interop when stdin is a file [GH 4475]
* [WSL2] Fix service crash when unexpected network state is encountered [GH 4474]
* [WSL2] Query the distro name from the interop server if the current process does not have the environment variable
* [WSL2] Fix issue with interop whe stdin is a file
* [WSL2] Update Linux kernel version to 4.19.72
* [WSL2] Add ability to specify additional kernel command line parameters via .wslconfig
```
[wsl2]
kernelCommandLine = <string> # Additional kernel command line arguments
```

## Build 18990
For general Windows information on build 18990 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2019/09/24/announcing-windows-10-insider-preview-build-18990/).

* Improve the performance for directory listings in \\\\wsl$
* [WSL2] Inject additional boot entropy [GH 4416]
* [WSL2] Fix for Windows interop when using su / sudo [GH 4465]

## Build 18980
For general Windows information on build 18980 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2019/09/11/announcing-windows-10-insider-preview-build-18980/).

* Fix reading symlinks that deny FILE_READ_DATA. This includes all the symlinks Windows creates for backwards compatibility such as "C:\Document and Settings" and a bunch of symlinks in the user profile directory
* Make unexpected filesystem state non-fatal [GH 4334, 4305]
* [WSL2] Add support for arm64 if your CPU / firmware supports virtualization
* [WSL2] Allow unprivileged users to view kernel log
* [WSL2] Fix output relay when stdout / stderr sockets have been closed [GH 4375]
* [WSL2] Support battery and AC adapter passthrough
* [WSL2] Update Linux kernel to 4.19.67
* Add the ability to set default username in /etc/wsl.conf:
```
[user]
default=<string>
```

## Build 18975
For general Windows information on build 18975 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2019/09/06/announcing-windows-10-insider-preview-build-18975/).

* [WSL2] Fixed a number of localhost reliability issues [GH 4340]

## Build 18970
For general Windows information on build 18970 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2019/08/29/announcing-windows-10-insider-preview-build-18970/).

* [WSL2] Sync time with host time when system resumes from sleep state [GH 4245]
* [WSL2] Create NT symlinks on the Windows volumes when possible.
* [WSL2] Create distros in UTS, IPC, PID, and Mount namespaces.
* [WSL2] Fix localhost port relay when server binds to localhost directly [GH 4353]
* [WSL2] Fix interop when output is redirected [GH 4337]
* [WSL2] Support translating absolute NT symlinks.
* [WSL2] Update kernel to 4.19.59
* [WSL2] Properly set subnet mask for eth0.
* [WSL2] Change logic to break out of console worker loop when exit event is signaled.
* [WSL2] Eject distribution vhd when the distro is not running.
* [WSL2] Fix config parsing library to correctly handle empty values.
* [WSL2] Support Docker Desktop by creating cross distro mounts. A distro can opt-in to this behavior by adding the following line to the /etc/wsl.conf file:
```
[automount]
crossDistro = true
```

## Build 18945
For general Windows information on build 18945 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2019/07/26/announcing-windows-10-insider-preview-build-18945/).

### WSL
* [WSL2] Allow listening tcp sockets in WSL2 to be accessible from the host by using localhost:port
* [WSL2] Fixes for install / conversion failures and additional diagnostics to track down future issues [GH 4105] 
* [WSL2] Improve diagnosability of WSL2 network issues
* [WSL2] Update kernel version to 4.19.55
* [WSL2] Update kernel with config options required for docker [GH 4165]
* [WSL2] Increase the number of CPUs assigned to the lightweight utility VM to be the same as the host (was previously capped at 8 by CONFIG_NR_CPUS in the kernel config) [GH 4137]
* [WSL2] Create a swap file for the WSL2 lightweight VM
* [WSL2] Allow user mounts to be visible via \\\\wsl$\\distro (for example sshfs) [GH 4172]
* [WSL2] Improve 9p filesystem performance
* [WSL2] Ensure vhd ACL does not grow unbounded [GH 4126]
* [WSL2] Update kernel config to support squashfs and xt_conntrack [GH 4107, 4123]
* [WSL2] Fix for interop.enabled /etc/wsl.conf option [GH 4140]
* [WSL2] Return ENOTSUP if the file system does not support EAs
* [WSL2] Fix CopyFile hang with \\\\wsl$
* Switch default umask to 0022 and add filesystem.umask setting to /etc/wsl.conf
* Fix wslpath to properly resolve symlinks, this was regressed in 19h1 [GH 4078]
* Introduce %UserProfile%\\.wslconfig file for tweaking WSL2 settings
```
[wsl2]
kernel=<path>              # An absolute Windows path to a custom Linux kernel.
memory=<size>              # How much memory to assign to the WSL2 VM.
processors=<number>        # How many processors to assign to the WSL2 VM.
swap=<size>                # How much swap space to add to the WSL2 VM. 0 for no swap file.
swapFile=<path>            # An absolute Windows path to the swap vhd.
localhostForwarding=<bool> # Boolean specifying if ports bound to wildcard or localhost in the WSL2 VM should be connectable from the host via localhost:port (default true).

# <path> entries must be absolute Windows paths with escaped backslashes, for example C:\\Users\\Ben\\kernel
# <size> entries must be size followed by unit, for example 8GB or 512MB
```

## Build 18917
For general Windows information on build 18917 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2019/06/12/announcing-windows-10-insider-preview-build-18917/).

### WSL
* WSL 2 is now available! Please see [blog](https://devblogs.microsoft.com/commandline/wsl-2-is-now-available-in-windows-insiders/) for more details.
* Fix a regression where launching Windows processes via symlinks did not work correctly [GH 3999]
* Add wsl.exe --list --verbose, wsl.exe --list --quiet, and wsl.exe --import --version options to wsl.exe
* Add wsl.exe --shutdown option
* Plan 9: Allow opening a directory for write to succeed

## Build 18890
For general Windows information on build 18890 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2019/05/01/announcing-windows-10-insider-preview-build-18890/).

### WSL
* Non-blocking socket leak [GH 2913]
* EOF input to terminal can block subsequent reads [GH 3421]
* Update resolv.conf header to refer to wsl.conf [discussed in GH 3928]
* Deadlock in epoll delete code [GH 3922]
* Handle spaces in arguments to --import and –export [GH 3932]
* Extending mmap'd files does not work properly [GH 3939]
* Fix issue with ARM64 \\\\wsl$ access not working properly
* Add better default icon for wsl.exe

## Build 18342
For general Windows information on build 18342 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2019/02/20/announcing-windows-10-insider-preview-build-18342/).

### WSL
* We've added the ability for users to access Linux files in a WSL distro from Windows. These files can be accessed through the command line, and also Windows apps, like file explorer, VSCode, etc. can interact with these files. Access your files by navigating to \\\\wsl$\\<distro_name>, or see a list of running distributions by navigating to \\\\wsl$
* Add additional CPU info tags and fix Cpus_allowed[_list] values [GH 2234]
* Support exec from non-leader thread [GH 3800]
* Treat configuration update failures as non-fatal [GH 3785]
* Update binfmt to properly handle offsets [GH 3768]
* Enable mapping network drives for Plan 9 [GH 3854]
* Support Windows -> Linux and Linux -> Windows path translation for bind mounts
* Create read-only sections for mappings on files opened read-only

## Build 18334
For general Windows information on build 18334 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2019/02/08/announcing-windows-10-insider-preview-build-18334/).

### WSL
* Redesign the way that Windows time zone is mapped to a  Linux time zone [GH 3747]
* Fix memory leaks and add new string translation functions [GH 3746]
* SIGCONT on a threadgroup with no threads is a no-op [GH 3741] 
* Correctly display socket and epoll file descriptors in /proc/self/fd

## Build 18305
For general Windows information on build 18305 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2018/12/19/announcing-windows-10-insider-preview-build-18305/).

### WSL
* pthreads lose access to files when the primary thread exits [GH 3589]
* TIOCSCTTY should ignore the "force" parameter unless it is required [GH 3652]
* wsl.exe command line improvements and addition of import / export functionality.
```
Usage: wsl.exe [Argument] [Options...] [CommandLine]

Arguments to run Linux binaries:

    If no command line is provided, wsl.exe launches the default shell.

    --exec, -e <CommandLine>
        Execute the specified command without using the default Linux shell.

    --
        Pass the remaining command line as is.

Options:
    --distribution, -d <DistributionName>
        Run the specified distribution.

    --user, -u <UserName>
        Run as the specified user.

Arguments to manage Windows Subsystem for Linux:

    --export <DistributionName> <FileName>
        Exports the distribution to a tar file.
        The filename can be - for standard output.

    --import <DistributionName> <InstallLocation> <FileName>
        Imports the specified tar file as a new distribution.
        The filename can be - for standard input.

    --list, -l [Options]
        Lists distributions.

        Options:
            --all
                List all distributions, including distributions that are currently
                being installed or uninstalled.

            --running
                List only distributions that are currently running.

    -setdefault, -s <DistributionName>
        Sets the distribution as the default.

    --terminate, -t <DistributionName>
        Terminates the distribution.

    --unregister <DistributionName>
        Unregisters the distribution.

    --upgrade <DistributionName>
        Upgrades the distribution to the WslFs file system format.

    --help
        Display usage information.
```

## Build 18277
For general Windows information on build 18277 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2018/11/07/announcing-windows-10-insider-preview-build-18277/).

### WSL
* Fix "no such interface supported" error introduced in build 18272 [GH 3645]
* Ignore the MNT_FORCE flag for umount syscall [GH 3605]
* Switch WSL interop to use the official CreatePseudoConsole API
* Maintain no timeout value when FUTEX_WAIT restarts

## Build 18272
For general Windows information on build 18272 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2018/10/31/announcing-windows-10-insider-preview-build-18272/).

### WSL
* **WARNING:** There is an issue in this build that makes WSL inoperable. When trying to launch your distribution you will see a "No such interface supported" error. The issue has been fixed and will be in next week's Insider Fast build. If you've installed this build you can roll back to the previous Windows build using "Go back to the previous version of Windows 10" in Settings->Update & Security->Recovery.

## Build 18267
For general Windows information on build 18267 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2018/10/24/announcing-windows-10-insider-preview-build-18267/).

### WSL
* Fix issue where zombie process may not be reaped and remain indefinitely.
* WslRegisterDistribution hangs if error message exceeds max length [GH 3592]
* Allow fsync to succeed for read-only files on DrvFs [GH 3556]
* Ensure that /bin and /sbin directories exist before creating symlinks inside [GH 3584]
* Added an instance termination timeout mechanism for WSL instances. The timeout is currently set to 15 seconds, meaning the instance will terminate 15 seconds after the last WSL process exits. To terminate a distribution immediately, use:
```
wslconfig.exe /terminate <DistributionName>
```

## Build 17763 (1809)
For general Windows information on build 17763 visit the [Windows blog](https://blogs.windows.com/windowsexperience/2018/10/02/how-to-get-the-windows-10-october-2018-update/).

### WSL
* Setpriority syscall permission check too strict for changing same thread priority [GH 1838]
* Ensure that unbiased interrupt time is used for boot time to avoid returning negative values for clock_gettime(CLOCK_BOOTTIME) [GH 3434]
* Handle symlinks in the WSL binfmt interpreter [GH 3424]
* Better handling of threadgroup leader file descriptor cleanup.
* Switch WSL to use KeQueryInterruptTimePrecise instead of KeQueryPerformanceCounter to avoid overflow [GH 3252]
* Ptrace attach may cause bad return value from system calls [GH 1731]
* Fix several AF_UNIX related issues [GH 3371]
* Fix issue that could cause WSL interop to fail if the current working directory is less than 5 characters long [GH 3379]
* Avoid one second delay failing loopback connections to non-existent ports [GH 3286]
* Add /proc/sys/fs/file-max stub file [GH 2893]
* More accurate IPV6 scope information.
* PR_SET_PTRACER support [GH 3053]
* Pipe filesystem inadvertently clearing edge-triggered epoll event [GH 3276]
* Win32 executable launched via NTFS symlink doesn't respect symlink name [GH 2909]
* Improved zombie support [GH 1353]
* Add wsl.conf entries for controlling Windows interop behavior [GH 1493]
  ```
    [interop]

    enabled=false # enable launch of Windows binaries; default is true

    appendWindowsPath=false # append Windows path to $PATH variable; default is true
  ```
* Fix for getsockname not always returning UNIX socket family type [GH 1774]
* Add support for TIOCSTI [GH 1863]
* Non-blocking sockets in the process of connecting should return EAGAIN for write attempts [GH 2846]
* Support interop on mounted VHDs [GH 3246, 3291]
* Fix permission checking issue on root folder [GH 3304]
* Limited support for TTY keyboard ioctls KDGKBTYPE, KDGKBMODE and KDSKBMODE.
* Windows UI apps should execute even when launched in the background.
* Add wsl -u or --user option [GH 1203]
* Fix WSL launch issues when fast startup is enabled [GH 2576]
* Unix sockets need to retain disconnected peer credentials [GH 3183]
* Non-blocking Unix sockets failing indefinitely with EAGAIN [GH 3191]
* case=off is the new default drvfs mount type [GH 2937, 3212, 3328]
    * See [blog](https://blogs.msdn.microsoft.com/commandline/2018/06/14/improved-per-directory-case-sensitivity-support-in-wsl/) for more information.
* Add wslconfig /terminate to stop running distributions.
* Fix issue with the WSL shell context menu entries that do not correctly handle paths with spaces.
* Expose per-directory case sensitivity as an extended attribute
* ARM64: Emulate cache maintenance operations. Resolve [dotnet issue](https://github.com/dotnet/core/issues/1561).
* DrvFs: only unescape characters in the private range that correspond to an escaped character.
* Fix off-by-one error in ELF parser interpreter length validation [GH 3154]
* WSL absolute timers with a time in the past do not fire [GH 3091]
* Ensure newly created reparse points are listed as such in the parent directory.
* Atomically create case sensitive directories in DrvFs.
* Fixed an additional issue where multithreaded operations could return ENOENT even though the file exists. [GH 2712]
* Fixed WSL launch failure when UMCI is enabled. [GH 3020]
* Add explorer context menu to launch WSL [GH 437, 603, 1836]. To use, hold shift and right-click when in an explorer window.
* Fix Unix socket non-blocking behavior [GH 2822, 3100]
* Fix hanging NETLINK command as reported in GH 2026.
* Add support for mount propagation flags [GH 2911].
* Fix issue with truncate not causing inotify events [GH 2978].
* Add --exec option for wsl.exe to invoke a single binary without a shell.
* Add --distribution option for wsl.exe to select a specific distro.
* Limited support for dmesg. Applications can now log to dmesg. WSL driver logs limited information to dmesg. In future, this can be extended to carry other information/diagnostics from the driver.
    * Note: dmesg is currently supported through the `/dev/kmsg` device interface. `syslog` syscall interface is not yet supported. And, so, some of the `dmesg` command line options such as `-S`, `-C` don't work.
* Change default gid and mode of serial devices to match native [GH 3042]
* DrvFs now supports extended attributes.
    * Note: DrvFs has some limitations on the name of extended attributes. Some characters (like '/', ':' and '\*') are not allowed, and extended attribute names are not case sensitive on DrvFs

## Build 18252 (Skip Ahead)
For general Windows information on build 18252 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/10/03/announcing-windows-10-insider-preview-build-18252/).

### WSL
* Move init and bsdtar binaries out of lxssmanager dll and into a separate tools folder
* Fix race around closing file descriptor when using CLONE_FILES
* Handle optional fields in /proc/pid/mountinfo when translating DrvFs paths
* Allow DrvFs mknod to succeed without metadata support for S_IFREG
* Readonly files created on DrvFs should have the readonly attribute set [GH 3411]
* Add /sbin/mount.drvfs helper to handle DrvFs mounting
* Use POSIX rename in DrvFs.
* Allow path translation on volumes without a volume GUID.

## Build 17738 (Fast)
For general Windows information on build 17738 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/08/14/announcing-windows-10-insider-preview-build-17738/).

### WSL
* Setpriority syscall permission check too strict for changing same thread priority [GH 1838]
* Ensure that unbiased interrupt time is used for boot time to avoid returning negative values for clock_gettime(CLOCK_BOOTTIME) [GH 3434]
* Handle symlinks in the WSL binfmt interpreter [GH 3424]
* Better handling of threadgroup leader file descriptor cleanup.

## Build 17728 (Fast)
For general Windows information on build 17728 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/07/31/announcing-windows-10-insider-preview-build-17728/).

### WSL
* Switch WSL to use KeQueryInterruptTimePrecise instead of KeQueryPerformanceCounter to avoid overflow [GH 3252]
* Ptrace attach may cause bad return value from system calls [GH 1731]
* Fix a number of AF_UNIX related issues [GH 3371]
* Fix issue that could cause WSL interop to fail if the current working directory is less than 5 characters long [GH 3379]

## Build 18204 (Skip Ahead)
For general Windows information on build 18204 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/07/25/announcing-windows-10-insider-preview-build-17723-and-build-18204/).

### WSL
* Pipe filesystem inadvertently clearing edge-triggered epoll event [GH 3276]
* Win32 executable launched via NTFS symlink doesn't respect symlink name [GH 2909]

## Build 17723 (Fast)
For general Windows information on build 17723 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/07/25/announcing-windows-10-insider-preview-build-17723-and-build-18204/).

### WSL
* Avoid one second delay failing loopback connections to non-existent ports [GH 3286]
* Add /proc/sys/fs/file-max stub file [GH 2893]
* More accurate IPV6 scope information.
* PR_SET_PTRACER support [GH 3053]
* Pipe filesystem inadvertently clearing edge-triggered epoll event [GH 3276]
* Win32 executable launched via NTFS symlink doesn't respect symlink name [GH 2909]

## Build 17713
For general Windows information on build 17713 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/07/11/announcing-windows-10-insider-preview-build-17713/).

### WSL
* Improved zombie support [GH 1353]
* Add wsl.conf entries for controlling Windows interop behavior [GH 1493]
  ```
    [interop]

    enabled=false # enable launch of Windows binaries; default is true

    appendWindowsPath=false # append Windows path to $PATH variable; default is true
  ```
* Fix for getsockname not always returning UNIX socket family type [GH 1774]
* Add support for TIOCSTI [GH 1863]
* Non-blocking sockets in the process of connecting should return EAGAIN for write attempts [GH 2846]
* Support interop on mounted VHDs [GH 3246, 3291]
* Fix permission checking issue on root folder [GH 3304]
* Limited support for TTY keyboard ioctls KDGKBTYPE, KDGKBMODE and KDSKBMODE.
* Windows UI apps should execute even when launched in the background.

## Build 17704
For general Windows information on build 17704 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/06/27/announcing-windows-10-insider-preview-build-17704/).

### WSL
* Add wsl -u or --user option [GH 1203]
* Fix WSL launch issues when fast startup is enabled [GH 2576]
* Unix sockets need to retain disconnected peer credentials [GH 3183]
* Non-blocking Unix sockets failing indefinitely with EAGAIN [GH 3191]
* case=off is the new default drvfs mount type [GH 2937, 3212, 3328]
    * See [blog](https://blogs.msdn.microsoft.com/commandline/2018/06/14/improved-per-directory-case-sensitivity-support-in-wsl/) for more information.
* Add wslconfig /terminate to stop running distributions.

## Build 17692
For general Windows information on build 17692 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/06/14/announcing-windows-10-insider-preview-build-17692).

### WSL
* Fix issue with the WSL shell context menu entries that do not correctly handle paths with spaces.
* Expose per-directory case sensitivity as an extended attribute
* ARM64: Emulate cache maintenance operations. Resolve [dotnet issue](https://github.com/dotnet/core/issues/1561).
* DrvFs: only unescape characters in the private range that correspond to an escaped character.

## Build 17686
For general Windows information on build 17686 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/06/06/announcing-windows-10-insider-preview-build-17686).

### WSL
* Fix off-by-one error in ELF parser interpreter length validation [GH 3154]
* WSL absolute timers with a time in the past do not fire [GH 3091]
* Ensure newly created reparse points are listed as such in the parent directory.
* Atomically create case sensitive directories in DrvFs.

## Build 17677
For general Windows information on build 17677 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/05/24/announcing-windows-10-insider-preview-build-17677/).

### WSL
* Fixed an additional issue where multithreaded operations could return ENOENT even though the file exists. [GH 2712]
* Fixed WSL launch failure when UMCI is enabled. [GH 3020]

## Build 17666
For general Windows information on build 17666 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/05/09/announcing-windows-10-insider-preview-build-17666/).

### WSL
#### WARNING: There is an issue preventing WSL from running on some AMD chipsets [GH 3134]. A fix is ready and making its way to the Insider Build branch.
* Add explorer context menu to launch WSL [GH 437, 603, 1836]. To use hold shift and right-click when in an explorer window.
* Fix unix socket non-blocking behavior [GH 2822, 3100]
* Fix hanging NETLINK command as reported in GH 2026.
* Add support for mount propagation flags [GH 2911].
* Fix issue with truncate not causing inotify events [GH 2978].
* Add --exec option for wsl.exe to invoke a single binary without a shell.
* Add --distribution option for wsl.exe to select a specific distro.

## Build 17655 (Skip Ahead)
For general Windows information on build 17655 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/04/25/announcing-windows-10-insider-preview-build-17655-for-skip-ahead/).

### WSL
* Limited support for dmesg. Applications can now log to dmesg. WSL driver logs limited information to dmesg. In future, this can be extended to carry other information/diagnostics from the driver.
    * Note: dmesg is currently supported through the `/dev/kmsg` device interface. `syslog` sycall interface is not yet supported. And, so, some of the `dmesg` command line options such as `-S`, `-C` don't work.
* Fixed an issue where multithreaded operations could return ENOENT even though the file exists. [GH 2712]

## Build 17639 (Skip Ahead)
For general Windows information on build 17639 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/04/04/announcing-windows-10-insider-preview-build-17639-for-skip-ahead/).

### WSL
* Change default gid and mode of serial devices to match native [GH 3042]
* DrvFs now supports extended attributes.
    * Note: DrvFs has some limitations on the name of extended attributes. In particular, some characters (like '/', ':' and '\*') are not allowed, and extended attribute names are not case sensitive on DrvFs

## Build 17133 (Fast)
For general Windows information on build 17133 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/03/27/announcing-windows-10-insider-preview-build-17133-for-fast/).

### WSL
* Fix for hang in WSL. [GH 3039, 3034]

## Build 17128 (Fast)
For general Windows information on build 17128 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/03/23/announcing-windows-10-insider-preview-build-17128-for-fast/).

### WSL
* None

## Build 17627 (Skip Ahead)
For general Windows information on build 17627 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/03/21/announcing-windows-10-insider-preview-build-17627-for-skip-ahead/).

### WSL
* Add support for the futex pi-aware operations. [GH 1006]
    * Note that priorities are not currently a supported WSL feature so there are limitations, but standard usage should be unblocked.
* Windows firewall support for WSL processes. [GH 1852]
    * For example, to allow the WSL python process to listen on any port, use the elevated Windows cmd:
```netsh.exe advfirewall firewall add rule name=wsl_python dir=in action=allow program="C:\users\<username>\appdata\local\packages\canonicalgrouplimited.ubuntuonwindows_79rhkp1fndgsc\localstate\rootfs\usr\bin\python2.7" enable=yes```
    * For additional details on how to add firewall rules, see [link](https://support.microsoft.com/help/947709/how-to-use-the-netsh-advfirewall-firewall-context-instead-of-the-netsh)
* Respect user's default shell when using wsl.exe. [GH 2372]
* Report all network interfaces as ethernet. [GH 2996]
* Better handling of corrupt /etc/passwd file. [GH 3001]

### Console
* No fixes.

### LTP Results:
Testing in progress.

## Build 17618 (Skip Ahead)
For general Windows information on build 17618 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/03/07/announcing-windows-10-insider-preview-build-17618-skip-ahead/).

### WSL
* Introduce pseudoconsole functionality for NT interop [GH 988, 1366, 1433, 1542, 2370, 2406].
* The legacy install mechanism (lxrun.exe) has been deprecated. The supported mechanism for installing distributions is through the Microsoft Store.

### Console
* No fixes.

### LTP Results:
Testing in progress.

## Build 17110
For general Windows information on build 17110 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/02/27/announcing-windows-10-insider-preview-build-17110-fast/).

### WSL
* Allow /init to be terminated from Windows [GH 2928].
* DrvFs now uses per-directory case sensitivity by default (equivalent to the "case=dir" mount option).
    * Using "case=force" (the old behavior) requires setting a registry key. Run the following command to enable "case=force" if you need to use it: reg add HKLM\SYSTEM\CurrentControlSet\Services\lxss /v DrvFsAllowForceCaseSensitivity /t REG_DWORD /d 1
    * If you have existing directories created with WSL in older version of Windows which need to be case sensitive, use fsutil.exe to mark them as case sensitive: fsutil.exe file setcasesensitiveinfo `<path>` enable
* NULL terminate strings returned from the uname syscall.

### Console
* No fixes.

### LTP Results:
Testing in progress.

## Build 17107
For general Windows information on build 17107 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/02/23/announcing-windows-10-insider-preview-build-17107-fast-ring/).

### WSL
* Support TCSETSF and TCSETSW on master pty endpoints [GH 2552].
* Starting simultaneous interop processes can result in EINVAL [GH 2813].
* Fix PTRACE_ATTACH to show proper tracing status in /proc/pid/status.
* Fix race where short-lived processes cloned with both the CLEARTID and SETTID flags could exit without clearing the TID address.
* Display a message when upgrading the Linux file system directories
when moving from a pre-17093 build. For more details on the 17093 file system changes, see the release notes for [17093](https://github.com/MicrosoftDocs/WSL/blob/live/WSL/release-notes.md#build-17093).

### Console
* No fixes.

### LTP Results:
Testing in progress.

## Build 17101
For general Windows information on build 17101 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/02/14/announcing-windows-10-insider-preview-build-17101-fast-build-17604-skip-ahead/).

### WSL
* Support for signalfd. [GH 129]
* Support file-names containing illegal NTFS characters by encoding them as private Unicode characters. [GH 1514]
* Auto mount will fallback to read-only when write is not supported. [GH 2603]
* Allow pasting of Unicode surrogate pairs (like emoji characters). [GH 2765]
* Pseudo-files in /proc and /sys should return read and write ready from select, poll, epoll, et al. [GH 2838]
* Fix issue that could cause service to go into infinite loop when the registry has been tampered with or is corrupt.
* Fix netlink messages to work with newer (upstream 4.14) version of iproute2.

### Console
* No fixes.

### LTP Results:
Testing in progress.

## Build 17093
For general Windows information on build 17093 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/02/07/announcing-windows-10-insider-preview-build-17093-pc/).

#### Important:
When starting WSL for the first time after upgrading to this build, it needs to perform some work upgrading the Linux file system directories. This may take up to several minutes, so WSL may appear to start slowly. This should only happen once for each distribution you have installed from the store.
* Improved case sensitivity support in DrvFs.
    * DrvFs now supports per-directory case sensitivity. This is a new flag that can be set on directories to indicate all operations in those directories should be treated as case sensitive, which allows even Windows applications to correctly open files that differ only by case.
    * DrvFs has new mount options controlling case sensitivity on a per-directory basis
        * case=force: all directories are treated as case sensitive (except for the drive root). New directories created with WSL are marked as case sensitive. This is the legacy behavior except for marking new directories case sensitive.
        * case=dir: only directories with the per-directory case sensitivity flag are treated as case sensitive; other directories are case insensitive. New directories created with WSL are marked as case sensitive.
        * case=off: only directories with the per-directory case sensitivity flag are treated as case sensitive; other directories are case insensitive. New directories created with WSL are marked as case insensitive.
    * Note: directories created by WSL in previous releases do not have this flag set, so will not be treated as case sensitive if you use the "case=dir" option. A way to set this flag on existing directories is coming soon.
    * Example of mounting with these options (for existing drives, you must first unmount before you can mount with different options): sudo mount -t drvfs C: /mnt/c -o case=dir
    * For now, case=force is still the default option. This will be changed to case=dir in the future.
* You can now use forward slashes in Windows paths when mounting DrvFs, e.g.: sudo mount -t drvfs //server/share /mnt/share
* WSL now processes the /etc/fstab file during instance start [GH 2636].
    * This is done prior to automatically mounting DrvFs drives; any drives that were already mounted by fstab will not be remounted automatically, allowing you to change the mount point for specific drives.
    * This behavior can be turned off using wsl.conf.
* The mount, mountinfo and mountstats files in /proc properly escape special characters like backslashes and spaces [GH 2799]
* Special files created with DrvFs such as WSL symbolic links, or fifos and sockets when metadata is enabled, can now be copied and moved from Windows.

#### WSL is more configurable with wsl.conf
We added a method for you to automatically configure certain functionality in WSL that will be applied every time you launch the subsystem. This includes automount options and network configuration. Learn more about it in our blog post at: https://aka.ms/wslconf

#### AF_UNIX allows socket connections between Linux processes on WSL and Windows native processes
WSL and Windows applications can now communicate with each other over Unix sockets. Imagine you want to run a service in Windows and make it available to both Windows and WSL apps. Now, that's possible with Unix sockets. Read more in our blog post at https://aka.ms/afunixinterop

### WSL
* Support mmap() with MAP_NORESERVE [GH 121, 2784]
* Support CLONE_PTRACE and CLONE_UNTRACED [GH 121, 2781]
* Handle non-SIGCHLD termination signal in clone [GH 121, 2781]
* Stub /proc/sys/fs/inotify/max_user_instances and /proc/sys/fs/inotify/max_user_watches [GH 1705]
* Error loading ELF binaries that contain load headers with non-zero offsets [GH 1884]
* Zero out trailing page bytes when loading images.
* Reduce cases where execve silently terminates process

### Console
* No fixes.

### LTP Results:
Testing in progress.

## Build 17083
For general Windows information on build 17083 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/01/24/announcing-windows-10-insider-preview-build-17083-for-pc/).

### WSL
* Fixed bugcheck related to epoll [GH 2798, 2801, 2857]
* Fixed hangs when turning off ASLR [GH 1185, 2870]
* Ensure mmap operations appear atomic [GH 2732]

### Console
* No fixes.

### LTP Results:
Testing in progress.

## Build 17074
For general Windows information on build 17074 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2018/01/11/announcing-windows-10-insider-preview-build-17074-pc/).

### WSL
* Fixed storage format of DrvFs metadata [GH 2777] </br>
**Important:** DrvFs metadata created before this build will show up incorrectly or not at all. To fix affected files, use chmod and chown to re-apply the metadata.
* Fixed issue with multiple signals and restartable syscalls.

### Console
* No fixes.

### LTP Results:
Testing in progress.

## Build 17063
For general Windows information on build 17063 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/12/19/announcing-windows-10-insider-preview-build-17063-pc/).

### WSL
* DrvFs supports additional Linux metadata. This allows setting the owner and mode of files using chmod/chown, and also the creation of special files such as fifos, unix sockets and device files. This is disabled by default for now since it's still experimental.
**Note:**  We fixed a bug in the metadata format used by DrvFs. While metadata works on this build for experimentation, future builds will not correctly read metadata created by this build.  You might need to manually update owner for modified files and devices with a custom device ID will have to be recreated.

  To enable, mount DrvFs with the metadata option (to enable it on an existing mount, you must first unmount it):

  ```bash
  mount -t drvfs C: /mnt/c -o metadata
  ```

  Linux permissions are added as additional metadata to the file; they do not affect the Windows permissions.  Remember, editing a file using a Windows editor may remove the metadata. In this case, the file will revert to its default permissions.

* Added mount options to DrvFs to control files without metadata.
  * uid: the user ID used for the owner of all files.
  * gid: the group ID used for the owner of all files.
  * umask: an octal mask of permissions to exclude for all files and directories.
  * fmask: an octal mask of permissions to exclude for all regular files.
  * dmask: an octal mask of permissions to exclude for all directories.

  For example:
  ```
  mount -t drvfs C: /mnt/c -o uid=1000,gid=1000,umask=22,fmask=111
  ```

  Combine with the metadata option to specify default permissions for files without metadata.

* Introduced a new environment variable, `WSLENV`, to configure how environment variables flow between WSL and Win32.

  For example:

  ``` bash
  WSLENV=GOPATH/l:USERPROFILE/pu:DISPLAY
  ```

  `WSLENV` is a colon-delimited list of environment variables that can be included when launching WSL processes from Win32 or Win32 processes from WSL.  Each variable can be suffixed with a slash followed by flags to specify how it is translated.
  * p: The value is a path that should be translated between WSL paths and Win32 paths.
  * l: The value is a list of paths. In WSL, it is a colon-delimited list. In Win32, it is a semicolon-delimited list.
  * u: The value should only be included when invoking WSL from Win32
  * w: The value should only be included when invoking Win32 from WSL

  You can set `WSLENV` in .bashrc or in the custom Windows environment for your user.

* drvfs mounts correctly preserves timestamps from tar, cp -p (GH 1939)
* drvfs symlinks report the correct size (GH 2641)
* read/write works for very large IO sizes (GH 2653)
* waitpid works with process group IDs (GH 2534)
* significantly improved mmap performance for large reserve regions; improves ghc performance (GH 1671)
* personality supports for READ_IMPLIES_EXEC; fixes maxima and clisp (GH 1185)
* mprotect supports PROT_GROWSDOWN; fixes clisp (GH 1128)
* page fault fixes in overcommit mode; fixes sbcl (GH 1128)
* clone supports more flags combinations
* Support select/epoll of epoll files (previously a no-op).
* Notify ptrace of unimplemented syscalls.
* Ignore interfaces that are not up when generating resolv.conf nameservers [GH 2694]
* Enumerate network interfaces with no physical address. [GH 2685]
* Additional bug fixes and improvements.

### Linux tools available to developers on Windows

* Windows Command line Toolchain includes bsdtar (tar) and curl.
  Read [this blog](https://aka.ms/tarcurlwindows) to learn more about the addition of these two new tools and see how they're shaping the developer experience on Windows.

*   `AF_UNIX` is available in the Windows Insider SDK (17061+).
  Read [this blog](https://blogs.msdn.microsoft.com/commandline/2017/12/19/af_unix-comes-to-windows/) to learn more about `AF_UNIX` and how developers on Windows can use it.

### Console
* No fixes.

### LTP Results:
Testing in progress.


## Build 17046

For general Windows information on build 17046 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/11/22/announcing-windows-10-insider-preview-build-17046-pc).

### Fixed
#### WSL
- Allow processes to run without an active terminal. [GH 709, 1007, 1511, 2252, 2391, et al.]
- Better support of CLONE_VFORK and CLONE_VM. [GH 1878, 2615]
- Skip TDI filter drivers for WSL networking operations. [GH 1554]
- DrvFs creates NT symlinks when certain conditions are met. [GH 353, 1475, 2602]
    - The link target must be relative, must not cross any mount points or symlinks, and must exist.
    - The user must have SE_CREATE_SYMBOLIC_LINK_PRIVILEGE (this normally requires you to launch wsl.exe elevated), unless Developer Mode is turned on.
    - In all other situations, DrvFs still creates WSL symlinks.
- Allow running elevated and non-elevated WSL instances simultaneously.
- Support /proc/sys/kernel/yama/ptrace_scope
- Add wslpath to do WSL<->Windows path conversions. [GH 522, 1243, 1834, 2327, et al.]
  ```
    wslpath usage:
      -a    force result to absolute path format
      -u    translate from a Windows path to a WSL path (default)
      -w    translate from a WSL path to a Windows path
      -m    translate from a WSL path to a Windows path, with '/' instead of '\\'

      EX: wslpath 'c:\users'
  ```
  #### Console
- No fixes.

### LTP Results:
Testing in progress.


## Build 17040

For general Windows information on build 17040 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/11/16/announcing-windows-10-insider-preview-build-17040-pc).<br/>


### Fixed
#### WSL
- No fixes since 17035.

#### Console
- No fixes since 17035.

### LTP Results:
Testing in progress.

## Build 17035

For general Windows information on build 17035 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/11/08/announcing-windows-10-insider-preview-build-17035-pc).<br/>


### Fixed
#### WSL
- Accessing files on DrvFs could occasionally fail with EINVAL. [GH 2448]

#### Console
- Some color loss when inserting/deleting lines in VT mode.

### LTP Results:
Testing in progress.

## Build 17025

For general Windows information on build 17025 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/10/25/announcing-windows-10-insider-preview-build-17025-pc).<br/>


### Fixed
#### WSL
- Start initial processes in a new foreground process group [GH 1653, 2510].
- SIGHUP delivery fixes [GH 2496].
- Generate default virtual bridge name if none provided [GH 2497].
- Implement /proc/sys/kernel/random/boot_id [GH 2518].
- More interop stdout/stderr pipe fixes.
- Stub syncfs system call.

#### Console
- Fix input VT translation for third party consoles [GH 111]

### LTP Results:
Testing in progress.

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

## Fall Creators Update

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
- Return different error codes from RegisterDistribution if a distribution is currently being installed or uninstalled.
- Allow unregistration of partially installed WSL distributions via wslconfig.exe
- Fix python socket test hang from udp::msg_peek
- Additional improvements and bug fixes

#### Console
- No Console related changes in this release.

### LTP Results:
Total Tests: 1904<br/>
Total Skipped Tests: 209<br/>
Total Failures: 229<br/>


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
- Pseudo-terminal master endpoint not handling TIOCPGRP [GH 1063]
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
- Japanese characters look strange with Unicode Character U+30FB [GH 2146]
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
- security.capability xattr support.
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

- [Enabled serial support](/archive/blogs/wsl/serial-support-on-the-windows-subsystem-for-linux)
- Added IP socket option IP_OPTIONS [GH 1116]
- Implemented pwritev function (while uploading file to nginx/PHP-FPM) [GH 1506]
- Added IP socket options IP_MULTICAST_IF & IPV6_MULTICAST_IF [GH 990]
- Support for socket option IP_MULTICAST_LOOP & IPV6_MULTICAST_LOOP [GH 1678]
- Added IP(V6)_MTU socket option for apps node, traceroute, dig, nslookup, host
- Added IP socket option IPV6_UNICAST_HOPS
- [Filesystem Improvements](/archive/blogs/wsl/file-system-improvements-to-the-windows-subsystem-for-linux)
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

We released a new [blog post](/archive/blogs/wsl/testing-the-windows-subsystem-for-linux) discussing our efforts to test WSL.

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
- Changes to increase the performance of drvfs
- Minor fix for Ruby IO blocking
- Fixed recvmsg() returning EINVAL for the MSG_DONTWAIT flag for inet sockets [GH 1296]
- Additional fixes and improvements

### LTP Results:
Number of Passing Test: 732</br>
Number of non-Passing (failing, skipped, etc…): 255 </br>

<br/>

## Build 15019

For general Windows information on build 15019 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/01/27/announcing-windows-10-insider-preview-build-15019-pc/).<br/>


### Fixed

- Fixed bug that incorrectly reported CPU usage in procfs for tools like htop (GH 823, 945, 971)
- When calling open() with O_TRUNC on an existing file inotify now generates IN_MODIFY before IN_OPEN
- Fixes to unix socket getsockopt SO_ERROR to enable postgres [GH 61, 1354]
- Implement /proc/sys/net/core/somaxconn for the GO language
- Apt-get package update background task now runs hidden from view
- Clear scope for ipv6 localhost (Spring-Framework(Java) failure).
- Additional fixes and improvements

### LTP Results:
Number of Passing Test: 714 </br>
Number of non-Passing (failing, skipped, etc…): 249 </br>


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

### Syscall Summary
Total Syscalls: 384 </br>
Total Implemented: 235 </br>
Total Stubbed: 22 </br>
Total Unimplemented: 127 </br>


<br/>

## Build 15007

For general Windows information on build 15007 visit the [Windows Blog]( https://blogs.windows.com/windowsexperience/2017/01/12/announcing-windows-10-insider-preview-build-15007-pc-mobile).<br/>


### Known Issue

- There is a known bug where the console does not recognize some Ctrl + `<key>` input.  This includes the ctrl-c command which will act as a normal 'c' keypress.

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

<br/>

## Build 15002

For general Windows information on build 15002 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2017/01/09/announcing-windows-10-insider-preview-build-15002-pc/).<br/>


### Known Issue

Two known issues:
- There is a known bug where the console does not recognize some Ctrl + `<key>` input.  This includes the ctrl-c command which will act as a normal 'c' keypress.

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
- Fixed AptPackageIndexUpdate windows that won't close (GH #1184, also discussed in GH #1193)
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
   - Note that the Linux "ip" utility contains a bug where it will crash if WSL reports a 32-byte hardware address. This is a bug in "ip", not WSL. The "ip" utility hard-codes the length of the string buffer used to print the hardware address, and that buffer is too small to print a 32-byte hardware address.
- Additional fixes and improvements

### LTP Results:
Number of Passing Test: 669 </br>
Number of non-Passing (failing, skipped, etc…): 258 </br>

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

<br/>

## Build 14965

For general Windows information on build 14965 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/11/09/announcing-windows-10-insider-preview-build-14965-for-mobile-and-pc/).<br/>


### Fixed

- Support for Netlink sockets NETLINK_ROUTE protocol's RTM_GETLINK and RTM_GETADDR (GH #468)
  - Enables ifconfig and ip commands for network enumeration

- /sbin is now in the user's path by default
- NT user path now appended to the WSL path by default (i.e. you can now type notepad.exe without adding System32 to the Linux path)
- Added support for /proc/sys/kernel/cap_last_cap
- NT Binaries can now be launched from WSL when the current working directory contains non-ansi characters (GH #1254)
- Allow shutdown on disconnected unix stream socket.
- Added support for PR_GET_PDEATHSIG.
- Added support for CLONE_PARENT
- Fixed error where piping gets stuck i.e. bash -c "ls -alR /" | bash -c "cat" (GH #1214)
- Handle requests to connect to the current terminal.
- Mark `/proc/<pid>/oom_score_adj` as writable.
- Add /sys/fs/cgroup folder.
- sched_setaffinity should return number of affinity bits mask
- Fix ELF validation logic which incorrectly assumes interpreter paths must be less than 64 characters long. (GH #743)
- Open file descriptors can keep console window open (GH #1187)
- Fixed error where rename() failed with trailing slash on target name (GH #1008)
- Implement /proc/net/dev file
- Fixed 0.000ms pings due to timer resolution.
- Implemented /proc/self/environ (GH #730)
- Additional bugfixes and improvements

### LTP Results:
Number of Passing Test: 664 </br>
Number of non-Passing (failing, skipped, etc…): 263 </br>

<br/>

## Build 14959

For general Windows information on build 14959 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/11/03/announcing-windows-10-insider-preview-build-14959-for-mobile-and-pc/#iI82GufJxMF3POU1.97).<br/>


### Fixed

- Improved Pico Process notification for Windows.  Additional information found on the [WSL Blog](/archive/blogs/wsl/wsl-antivirus-and-firewall-compatibility).
- Improved stability with Windows interoperability
- Fixed error 0x80070057 when launching bash.exe when Enterprise Data Protection (EDP) is enabled
- Additional bugfixes and improvements

### LTP Results:
Number of Passing Test: 665 </br>
Number of non-Passing (failing, skipped, etc…): 263 </br>

<br/>

## Build 14955

For general Windows information on build 14955 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/10/25/announcing-windows-10-insider-preview-build-14955-for-mobile-and-pc/#guGXQzKVFrZIDUYR.97).<br/>


### Fixed

 - Due to circumstances beyond our control there are no updates in this build for the Windows Subsystem for Linux.  Regularly scheduled updates will resume on the next release.

### LTP Results:
Number of Passing Test: 665 </br>
Number of non-Passing (failing, skipped, etc…): 263 </br>

<br/>

## Build 14951

For general Windows information on build 14951 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/10/19/announcing-windows-10-insider-preview-build-14951-for-mobile-and-pc/).<br/>


### New Feature: Windows / Ubuntu Interoperability
Windows binaries can now be invoked directly from the WSL command line.  This gives users the ability to interact with their Windows environment and system in a way that has not been possible.  As a quick example, it is now possible for users to run the following commands:

```bash
$ export PATH=$PATH:/mnt/c/Windows/System32
$ notepad.exe
$ ipconfig.exe | grep IPv4 | cut -d: -f2
$ ls -la | findstr.exe foo.txt
$ cmd.exe /c dir
```

More information can be found at:

- [WSL Team Blog for Interop](/archive/blogs/wsl/windows-and-ubuntu-interoperability)<br/>
- [WSL File Systems Documentation](./filesystems.md)<br/>

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

<br/>

## Build 14946

For general Windows information on build 14946 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/10/13/announcing-windows-10-insider-preview-build-14946-for-pc-and-mobile/#xj8GdVooEqo4H7H7.97).<br/>


### Fixed

- Fixed an issue that prevented creating WSL user accounts for users with NT usernames that contain spaces or quotes. 
- Change VolFs and DrvFs to return 0 for directory's link count in stat
- Support IPV6_MULTICAST_HOPS socket option.
- Limit to a single console I/O loop per tty. Example: the following command is possible:
  - bash -c "echo data" | bash -c "ssh user@example.com 'cat > foo.txt'"

- replace spaces with tabs in /proc/cpuinfo (GH #1115)
- DrvFs now appears in mountinfo with a name that matches mounted Windows volume
- /home and /root now appear in mountinfo with correct names
- Additional bugfixes and improvements

### LTP Results:
Number of Passing Test: 665 </br>
Number of non-Passing (failing, skipped, etc…): 263 </br>

<br/>

## Build 14942

For general Windows information on build 14942 visit the [Windows Blog](https://aka.ms/onefourninefourtwoooooo).<br/>


### Fixed

- A number of bugchecks addressed, including the "ATTEMPTED EXECUTE OF NOEXECUTE MEMORY" networking crash which was blocking SSH
- inotify support for notifications generated from Windows applications on DrvFs is now in
- Implement TCP_KEEPIDLE and TCP_KEEPINTVL for mongod. (GH #695)
- Implement the pivot_root system call
- Implement socket option for SO_DONTROUTE
- Additional bugfixes and improvements


### LTP Results:
Number of Passing Test: 665 </br>
Number of non-Passing (failing, skipped, etc…): 263 </br>

### Syscall Support
Below are a list of new or enhanced syscalls that have some implementation in WSL. The syscalls on this list are supported in at least one scenario, but may not have all parameters supported at this time.

`pivot_root`<br/>
<br/>

## Build 14936

For general Windows information on build 14936 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/09/28/announcing-windows-10-insider-preview-build-14936-for-pc/).<br/>


Note: WSL will install Ubuntu version 16.04 (Xenial) instead of Ubuntu 14.04 (Trusty) in an upcoming release.  This change will apply to Insiders installing new instances (lxrun.exe /install or first run of bash.exe).  Existing instances with Trusty will not be upgraded automatically. Users can upgrade their Trusty image to Xenial using the do-release-upgrade command.

### Known Issue
WSL is experiencing an issue with some socket implementations.  The bugcheck manifests itself as a crash with the error "ATTEMPTED EXECUTE OF NOEXECUTE MEMORY".  The most common manifestation of this issue is a crash when using ssh.  The root cause is fixed on internal builds and will be pushed to Insiders at the earliest opportunity.

### Fixed

- Implemented the chroot system call
- Improvements in inotify ~~including support for notifications generated from Windows applications on DrvFs~~
  - Correction: Inotify support for changes originating from Windows applications not available at this time.
- Socket binding to `IPV6::<port n>` now supports `IPV6_V6ONLY`  (GH #68, #157, #393, #460, #674, #740, #982, #996)
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
  - More information about WSL in the Anniversary Update can be found on our [blog](/archive/blogs/wsl/)

<br/>

## Build 14376
For general Windows information on build 14376 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/06/28/announcing-windows-10-insider-preview-build-14376-for-pc-and-mobile/). <br/>

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
For general Windows information on build 14371 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/06/22/announcing-windows-10-insider-preview-build-14371-for-pc/). <br/>

### Fixed
- Corrected timing race with SIGCHLD and wait() when using ptrace
- Corrected some behavior when paths have a trailing /  (GH #432)
- Fixed issue with rename/unlink failing due to open handles to children
- Additional bugfixes and improvements

<br/>

## Build 14366
For general Windows information on build 14366 visit the [Windows Blog](https://blogs.windows.com/windowsexperience/2016/06/14/announcing-windows-10-insider-preview-build-14366-mobile-build-14364/). <br/>

### Fixed
- Fix in file creation through symlinks
-   Added listxattr for Python (GH 385)
-   Additional bugfixes and improvements

### Syscall Support
-   Below are a list of new or enhanced syscalls that have some implementation in WSL. The syscalls on this list are supported in at least one scenario, but may not have all parameters supported at this time.

`listxattr`<br/>
<br/>

## Build 14361
For general Windows information on build 14361 visit the [Windows Blog](https://aka.ms/wip14361). <br/>

### Fixed
- DrvFs is now case sensitive when running in Bash on Ubuntu on Windows.
  - Users may case.txt and CASE.TXT on their /mnt/c drives
  - Case sensitivity is only supported within Bash on Ubuntu on Windows. When outside of Bash NTFS will report the files correctly, but unexpected behavior may occur interacting with the files from Windows.
  - The root of each volume (i.e. /mnt/c) is not case sensitive
  - More information on handling these files in Windows can be found [here](./case-sensitivity.md).
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
- Better handling of bash.exe ~.  Commands like "bash ~ -c ls" now supported (GH #467)
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
For general Windows information on build 14352 visit the [Windows Blog](https://aka.ms/wip14352).<br/>


### Fixed
- Fixed issue where large files were not downloaded / created correctly.  This should unblock npm and other scenarios (GH #3, GH #313)
- Removed some instances where sockets hang
- Corrected some ptrace errors
- Fixed issue with WSL allowing filenames longer than 255 characters
- Improved support for non-English characters
- Add current Windows timezone data and set as default
- Unique device id's for each mount point (jre fix – GH #49)
- Correct issue with paths containing "." and ".."
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
For general Windows information on build 14342 the [Windows Blog](https://aka.ms/wip14342). <br/>

Information on VolFs and DriveFs can be found on the [WSL Blog](/archive/blogs/wsl/). <br/>

### Fixed
- Fixed install issue when the Windows user had Unicode characters in the username
- The apt-get update udev workaround in the FAQ is now provided by default on first run
- Enabled symlinks in DriveFs (`/mnt/<drive>`) directories
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
- Not resolving '..' correctly on DriveFs in some cases

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

For general Windows information on build 14332 visit the [Windows Blog](https://aka.ms/wip14332). <br/>


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

For general Windows information on build 14332 visit the [Windows Blog](https://aka.ms/wip14328). <br/>


### New Features
* Now support Linux users.  Installing Bash on Ubuntu on Windows will prompt for creation of a Linux user.  For more information, visit https://aka.ms/wslusers
* Hostname is now set to the Windows computer name, no more @localhost
* For more information on build 14328, visit: https://aka.ms/wip14328

### Fixed
* Symlink improvements for non `/mnt/<drive>` files
    * npm install now works
    * jdk / jre now installable using instructions found [here](https://xubuntugeek.blogspot.com/2012/09/how-to-install-oracle-jdk-7-manually-in.html).
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
