---
title: Windows Subsystem for Linux Command Reference
description: List of commands that manage the Windows Subsystem for Linux
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu
author: scooley
ms.author: scooley
ms.date: 07/31/2017
ms.topic: article
ms.assetid: 82908295-a6bd-483c-a995-613674c2677e
ms.custom: seodec18
---

# Command Reference for Windows Subsystem for Linux

The best way to interact with the Windows Subsystem for Linux is to use the `wsl.exe` command. 

## `wsl.exe` 

Below is a list containing all options when using `wsl.exe` as of Windows Version 1903.

Using: `wsl [Argument] [Options...] [CommandLine]`

### Arguments for running Linux binaries

* **Without arguments**

  If no command line is provided, wsl.exe launches the default shell.
  
  Options:
  * **--distribution, -d \<Distro>**
  
    Run the specified distribution.

  * **--user, -u \<UserName>**
  
    Run as the specified user.

* **--exec, -e \<CommandLine>**
  
  Execute the specified command without using the default Linux shell.

* **--**
  
  Pass the remaining command line as is.



### Arguments for managing Windows Subsystem for Linux

* **--export \<Distro> \<FileName>**
  
  Exports the distribution to a tar file. The filename can be - for standard output.

* **--import \<Distro> \<InstallLocation> \<FileName> [Options]**
  
  Imports the specified tar file as a new distribution. The filename can be - for standard input.

  Options:
  * **--version \<Version>**
      
    Specifies the version to use for the new distribution.

* **--list, -l [Options]**
  
  Lists distributions.

  Options:
  * **--all**
      
    List all distributions, including distributions that are currently being installed or uninstalled.

  * **--running**
      
    List only distributions that are currently running.

* **--set-default, -s \<Distro>**
  
  Sets the distribution as the default.

* **--set-default-version \<Version>**
  
  Changes the default install version for new distributions.

* **--set-version \<Distro> \<Version>**
  
  Changes the version of the specified distribution.

* **--terminate, -t \<Distro>**
  
  Terminates the specified distribution.

* **--unregister \<Distro>**
  
  Unregisters the distribution.
   
* **--upgrade \<Distro>**
  
  Upgrades the distribution to the WslFs file system format.
          
  The upgrade command will make sure your distro is using a new file system WslFs when WSL is accessing your files in your drive. In general, this will improve WSL accessing files, is something that's in the back end (so your workflow won't be impacted by it), and if you've installed your distributions recently then they'll automatically be using WslFs. [Additional Information](https://github.com/MicrosoftDocs/WSL/issues/280#issuecomment-468425983).

* **--help**
  Display usage information.

## Additional Commands

There are also historic commands to interact with the Windows Subsystem for Linux. Their functionality is encompassed within `wsl.exe`, but they are still available for use. 

### `wslconfig.exe`

This command lets you configure your WSL distribution. Below is a list of its options.

Using: `wslconfig [Argument] [Options...]`

#### Arguments
* **/l, /list [Options]**
  
  Lists registered distributions.
  
  Options:
    * **/all**
    
      Optionally list all distributions, including distributions that are currently being installed or uninstalled.

    * **/running**
      
      List only distributions that are currently running.

* **/s, /setdefault \<DistributionName>**
  
  Sets the distribution as the default.

* **/t, /terminate \<DistributionName>**
  
  Terminates the distribution.

* **/u, /unregister \<DistributionName>**
  
  Unregisters the distribution.
   
* **/upgrade \<DistributionName>**
  
  Upgrades the distribution to the WslFs file system format. See the description of `wsl --upgrade <Distro>` for details.

### `bash.exe`

This command is used to start a bash shell. Below are the options you can use with this command.

Using: `bash [Options...]`

* **No Option given**
  
  Launches the Bash shell in the current directory. If the Bash shell is not installed automatically runs `lxrun /install`

* **~**
  
  `bash ~` launches the bash shell into the user's home directory.  Similar to running `cd ~`.

* **-c "\<command>"**
  
  Runs the command, prints the output and exits back to the Windows command prompt.
    
  Example:  `bash -c "ls"`.

## Deprecated Commands

The `lxrun.exe` was the first command used to install and manage the Windows Subsystem for Linux. It is deprecated as of Windows 10 1803 and later.

The command `lxrun.exe` can be used to interact with the [Windows Subsystem for Linux (WSL)](https://msdn.microsoft.com/en-us/commandline/wsl/faq#what-windows-subsystem-for-linux-wsl-) directly.  These commands are installed into the `\Windows\System32` directory and may be run within a Windows command prompt or in PowerShell.

| Command                     | Description                     |
|:----------------------------|:---------------------------|
| `lxrun`                     | The lxrun command is used to manage the WSL instance. |
| `lxrun /install`            | Starts the download and install process. <br/> **/y** may be added to bypass all prompts.  The confirmation prompt is automatically accepted and the default user is set to root.          |
| `lxrun /uninstall`          | Uninstalls and deletes the Ubuntu image.  By default this does not remove the user's Ubuntu home directory. <br/> **/y** may be added to automatically accept the confirmation prompt <br/>**/full** uninstalls and deletes the user's Ubuntu home directory         |
| `lxrun /setdefaultuser <userName>`     | Sets the default Bash on Ubuntu user. Will prompt for a password if the specified user does not exist.  For more information visit: https://aka.ms/wslusers. <br/> **/y** Bypasses promping for the password.  The user will be created without a password.|
| `lxrun /update`            | Updates the subsystem's package index          |
