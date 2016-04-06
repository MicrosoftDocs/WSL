There are three major components of WSL that allows Windows 10 to provide a bash shell. 

### 1. Ubuntu Binary 
Genuine unmodified Ubuntu user-mode binaries provided by Canonical. 

### 2. Window Subsystem for Linux (WSL) 
This infrastructure supports unmodified Ubuntu binaries by exposing Linux-compatible kernel interfaces.  It includes Microsoft components that are responsible for handling Linux system call requests in coordination with the Windows NT kernel. This subsystem was developed by Microsoft and contains no Linux code.

![](media/architecture.png)
