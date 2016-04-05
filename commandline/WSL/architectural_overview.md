This scenario is comprised of two main components:

1. Ubuntu on Windows
Genuine Ubuntu user-mode binaries provided by Canonical. 

1. Window Subsystem for Linux (WSL)
This infrastructure supports unmodified Ubuntu binaries by exposing Linux-compatible kernel interfaces.  It includes Microsoft components that are responsible for handling Linux system call requests in coordination with the Windows NT kernel. This subsystem was developed by Microsoft and contains no Linux code.

![](media/architecture.png)
