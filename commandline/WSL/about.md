# BASH Running in Ubuntu on Windows

## Overview
Windows provides developers with a familiar Bash environment. This environment will allow users to:

1.	Run common command line utilities such as `grep`, `sed`, and `awk`
2.	Navigate the file system using these commands
3.	Run bash shell scripts which rely on supported command line utilities

Windows is running Ubuntu user-mode binaries provided by Canonical.  This means the command line utilities are the same as those that run within a native Ubuntu environment.  

This is provided as beta software.  While many of the coreutil commands provided by Ubuntu will work, there are some that will not.  We welcome feedback and will prioritize accordingly.  

This video from Build 2016 gives you more infromation and a demo of Ubuntu on Windows:  
<iframe src="https://channel9.msdn.com/Events/Build/2016/P488/player" width="800" height="450"  allowFullScreen="true" frameBorder="0" scrolling="no"></iframe>

Feedback and questions should be directed to:
* Our [GitHub issue tracker](https://github.com/Microsoft/CommandLine-Documentation/issues)
* Our [command-line UserVoice portal](https://wpdev.uservoice.com/forums/266908-command-prompt/filters/top)
* Our [command-line team blog](https://blogs.msdn.microsoft.com/commandline/)


## Architecture

This scenario is comprised of two main components:

1.	**Ubuntu on Windows**  
  Genuine Ubuntu user-mode binaries provided by Canonical. 

2.	**Window Subsystem for Linux (WSL)**  
  This infrastructure supports unmodified Ubuntu binaries by exposing Linux-compatible kernel interfaces.  It includes Microsoft components that are responsible for handling Linux system call requests in coordination with the Windows NT kernel.  
  This subsystem was developed by Microsoft and contains no Linux code.

![](media/architecture.png)

## Announcements

**Blogs**
* Mike Harsh's Blog -- [Run Bash on Ubuntu on Windows](https://blogs.windows.com/buildingapps/2016/03/30/run-bash-on-ubuntu-on-windows/)
* Scott Hanselman's Blog -- [Developers Can Run Bash And Usermode Ubuntu Linux Binaries On Windows 10](http://www.hanselman.com/blog/DevelopersCanRunBashShellAndUsermodeUbuntuLinuxBinariesOnWindows10.aspx)
* Ubuntu News -- [Ubuntu on Windows – The Ubuntu Userspace for Windows Developers](http://insights.ubuntu.com/2016/03/30/ubuntu-on-windows-the-ubuntu-userspace-for-windows-developers/)

**Build 2016**
* [Day 1 Keynote](https://channel9.msdn.com/events/Build/2016/KEY01)
* Interview with Ben Hillis, Dustin Kirkland, Russ Alexander, and Scott Hanselman -- [Linux Command Line on Windows](https://channel9.msdn.com/Events/Build/2016/C906?ocid=player)
* Video walkthrough -- [Running Bash on Ubuntu on Windows!](https://channel9.msdn.com/events/Build/2016/P488)

## Feedback

[GitHub issue tracker](https://github.com/Microsoft/CommandLine-Documentation/issues)
[command-line UserVoice portal](https://wpdev.uservoice.com/forums/266908-command-prompt/filters/top)
[command-line team blog](https://blogs.msdn.microsoft.com/commandline/)