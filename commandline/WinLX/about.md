# Overview of WinLX

Ubuntu on Windows provides users familiar with Linux a functional Bash shell and allows for the end user to run native Ubuntu binaries on Windows.   Doing this allows users to open a Bash shell and use familiar commands such as `ls`, `grep`, `sed`, and `awk`.  Additionally, this allows users to run `apt-get` to pull down 3rd party binaries compatible with Ubuntu such as `apt-get install ruby` to install the Ubuntu build of Ruby.

Ubuntu on Windows is made up of two main parts, the Windows Subsystem for Linux and the Ubuntu Usermode binaries.

* The Windows Subsystem for Linux is a translation layer between Linux and Windows kernel system calls. This light weight yet performant Microsoft technology allows Windows 10 to run Linux open source core utilities natively in a bash environment.
* The Ubuntu Usermode binaries are provided directly by Canonical and are unmodified from the bits a Linux user would download.

Using these two systems together, a user is able to run Ubuntu within the Windows environment.  Running Ubuntu in this way is not the same as running Ubuntu as a VM.  By default, Ubuntu for Windows has access to the running Windows system such as the network stack or the machine's hard drives.
