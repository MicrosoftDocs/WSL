# Windows Subsystem for Linux (WinLX)

Ubuntu on Windows provides users familiar with Linux a functional Bash shell and allows for the end user to run native Ubuntu binaries on Windows.   Doing this allows users to open a Bash shell and use familiar commands such as `ls`, `grep`, `sed`, and `awk`.  Additionally, this allows users to run `apt-get` to pull down 3rd party binaries compatible with Ubuntu such as `apt-get install ruby` to install the Ubuntu build of Ruby.

Ubuntu on Windows is made up of two main parts, the Windows Subsystem for Linux and the Ubuntu Usermode binaries.

* The Windows Subsystem for Linux is a translation layer between Linux and Windows kernel system calls. This light weight yet performant Microsoft technology allows Windows 10 to run Linux open source core utilities natively in a bash environment.
* The Ubuntu Usermode binaries are provided directly by Canonical and are unmodified from the bits a Linux user would download.

Using these two systems together, a user is able to run Ubuntu within the Windows environment.  Running Ubuntu in this way is not the same as running Ubuntu as a VM.  By default, Ubuntu for Windows has access to the running Windows system such as the network stack or the machine's hard drives.

The engineering effort behind the Windows Subsystem for Linux is a continued initiative within Microsoft. With this beta release of the product we don't expect everything to work perfectly. However, we have done considerable work to ensure that certain scenarios are well covered. Web developers, students, data analysists and others who currently rely on work arounds to access Linux command line tools and apt-get packages will find this preview very useful. Users familiar with frameworks such as Ruby on Rails, node.js and .net will feel right at home. 

While WinLX may not be ready for an enterprise production environment today, your use of the product will help identify areas that we will focus our efforts on in the future. Your feedback will play a vital role in guiding how we focus our development efforts moving forward.