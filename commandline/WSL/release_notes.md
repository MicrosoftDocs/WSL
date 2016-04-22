---
author: jackchammons
---

# Release Notes

## Build 14328
### New
* Now support Linux users.  Installing Bash on Ubuntu on Windows will prompt for creation of a Linux user.  For more information, visit http://aka.ms/wslusers
* Hostname is now set to the Windows computer name, no more @localhost
* For more information on build 14328, visit: http://aka.ms/wip14328

### Fixed
* Symlink improvements for non /mnt/<drive> files
    * tar now works with symbolic links
    * npm install now works
    * jdk / jre now installable using instructions found here.
    * known issue: symlinks do not work for Windows mounts.  Functionality will be available in a later build
* top and htop now display
* Additional error messages for some install failures
* Syscall improvements and bugfixes.  Supported syscall list below.
* Additional improvements bugfixes and improvements

### Syscall Support
Below is a list of syscalls that have some implementation in WSL.  Syscalls on this list are supported in at least one scenario, but may not have all parameters supported at this time.

`ACCEPT`
`ACCEPT4`
`ACCESS`
`ALARM` 
`ARCH_PRCTL` 
`BIND` 
`BRK` 
`CAPGET` 
`CAPSET` 
`CHDIR` 
`CHMOD` 
`CHOWN` 
`CLOCK_GETRES` 
`CLOCK_GETTIME` 
`CLOCK_NANOSLEEP` 
`CLONE` 
`CLOSE` 
`CONNECT` 
`CREAT` 
`DUP` 
`DUP2` 
`DUP3` 
`EPOLL_CREATE` 
`EPOLL_CREATE1` 
`EPOLL_CTL` 
`EPOLL_WAIT` 
`EVENTFD` 
`EVENTFD2` 
`EXECVE` 
`EXIT` 
`EXIT_GROUP` 
`FACCESSAT` 
`FADVISE64` 
`FCHDIR` 
`FCHMOD` 
`FCHMODAT` 
`FCHOWN` 
`FCHOWNAT` 
`FCNTL64` 
`FDATASYNC` 
`FLOCK` 
`FORK` 
`FSETXATTR` 
`FSTAT64` 
`FSTATAT64` 
`FSTATFS64` 
`FSYNC` 
`FTRUNCATE` 
`FTRUNCATE64` 
`FUTEX` 
`GETCPU` 
`GETCWD` 
`GETDENTS` 
`GETDENTS64` 
`GETEGID` 
`GETEGID16` 
`GETEUID` 
`GETEUID16` 
`GETGID` 
`GETGID16` 
`GETGROUPS` 
`GETPEERNAME` 
`GETPGID` 
`GETPGRP` 
`GETPID` 
`GETPPID` 
`GETPRIORITY` 
`GETRESGID` 
`GETRESGID16` 
`GETRESUID` 
`GETRESUID16` 
`GETRLIMIT` 
`GETRUSAGE` 
`GETSID` 
`GETSOCKNAME` 
`GETSOCKOPT` 
`GETTID` 
`GETTIMEOFDAY` 
`GETUID` 
`GETUID16` 
`GETXATTR` 
`GET_ROBUST_LIST` 
`GET_THREAD_AREA` 
`INOTIFY_ADD_WATCH` 
`INOTIFY_INIT` 
`INOTIFY_RM_WATCH` 
`IOCTL` 
`IOPRIO_GET` 
`IOPRIO_SET` 
`KEYCTL` 
`KILL` 
`LCHOWN` 
`LINK` 
`LINKAT` 
`LISTEN` 
`LLSEEK` 
`LSEEK` 
`LSTAT64` 
`MADVISE` 
`MKDIR` 
`MKDIRAT` 
`MKNOD` 
`MLOCK` 
`MMAP` 
`MMAP2` 
`MOUNT` 
`MPROTECT` 
`MREMAP` 
`MSYNC` 
`MUNLOCK` 
`MUNMAP` 
`NANOSLEEP` 
`NEWUNAME` 
`OPEN` 
`OPENAT` 
`PAUSE` 
`PERF_EVENT_OPEN` 
`PERSONALITY` 
`PIPE` 
`PIPE2` 
`POLL` 
`PPOLL` 
`PRCTL` 
`PREAD64` 
`PROCESS_VM_READV` 
`PROCESS_VM_WRITEV` 
`PSELECT6` 
`PTRACE` 
`PWRITE64` 
`READ` 
`READLINK` 
`READV` 
`REBOOT` 
`RECV` 
`RECVFROM` 
`RECVMSG` 
`RENAME` 
`RMDIR` 
`RT_SIGACTION` 
`RT_SIGPENDING` 
`RT_SIGPROCMASK` 
`RT_SIGRETURN` 
`RT_SIGSUSPEND` 
`RT_SIGTIMEDWAIT` 
`SCHED_GETAFFINITY` 
`SCHED_GETPARAM` 
`SCHED_GETSCHEDULER` 
`SCHED_GET_PRIORITY_MAX` 
`SCHED_GET_PRIORITY_MIN` 
`SCHED_SETAFFINITY` 
`SCHED_SETPARAM` 
`SCHED_SETSCHEDULER` 
`SCHED_YIELD` 
`SELECT` 
`SEND` 
`SENDMMSG` 
`SENDMSG` 
`SENDTO` 
`SETDOMAINNAME` 
`SETGID` 
`SETGROUPS` 
`SETHOSTNAME` 
`SETITIMER` 
`SETPGID` 
`SETPRIORITY` 
`SETREGID` 
`SETRESGID` 
`SETRESUID` 
`SETREUID` 
`SETRLIMIT` 
`SETSID` 
`SETSOCKOPT` 
`SETTIMEOFDAY` 
`SETUID` 
`SETXATTR` 
`SET_ROBUST_LIST` 
`SET_THREAD_AREA` 
`SET_TID_ADDRESS` 
`SHUTDOWN` 
`SIGACTION` 
`SIGALTSTACK` 
`SIGPENDING` 
`SIGPROCMASK` 
`SIGRETURN` 
`SIGSUSPEND` 
`SOCKET` 
`SOCKETCALL` 
`SOCKETPAIR` 
`SPLICE` 
`STAT64` 
`STATFS64` 
`SYMLINK` 
`SYMLINKAT` 
`SYNC` 
`SYSINFO` 
`TEE` 
`TGKILL` 
`TIME` 
`TIMERFD_CREATE` 
`TIMERFD_GETTIME` 
`TIMERFD_SETTIME` 
`TIMES` 
`TKILL` 
`TRUNCATE` 
`TRUNCATE64` 
`UMASK` 
`UMOUNT` 
`UMOUNT2` 
`UNLINK` 
`UNLINKAT` 
`UNSHARE` 
`UTIME` 
`UTIMENSAT` 
`UTIMES` 
`VFORK` 
`WAIT4` 
`WAITPID` 
`WRITE` 
`WRITEV` 
