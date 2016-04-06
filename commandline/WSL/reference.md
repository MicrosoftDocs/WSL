---
author: jackchammons
---

#Command Reference

> **Important note**  
  This is the first release of this brand new technology and it is branded “beta” deliberately – it’s not yet complete! We know there are issues and incomplete features, you should expect some things to work and for many things to fail. But we appreciate you playing with this feature and helping us identify the issues we need to fix in order to deliver a great experience.

The commands `bash.exe` and `lxrun.exe` are used to interact with the Windows Subsystem for Linux (WSL).  These commands are installed into the \Windows\System32 directory and may be run within a Windows command prompt or in Powershell.

* `bash.exe` launches the Bash enviornment and invokes /bin/bash.
* `lxrun.exe` is used to manage WSL.  This command can be used to install or uninstall the Ubuntu image.



| Command                     | Description                     |
|:----------------------------|:---------------------------|
| `bash`                      | Launches the Bash shell in the current directory.  If the Bash shell is not installed automatically runs `lxrun /install` |
| `bash ~`                    | Launches the bash shell into the user's Ubuntu home directory.  Similar to running cd ~            |
| `bash -c "<command>"`       | Runs the command, prints the output and exits back to the Windows command prompt. <br/> <br/> Example:  **bash -c "ls"** |

<p>

| Command                     | Description                     |
|:----------------------------|:---------------------------|
| `lxrun`                      | The lxrun command is used to manage the WSL instance. |
| `lxrun /install`            | Starts the download and install process. <br/> **/y** may be added to automatically accept the confirmation prompt.                       |
| `lxrun /uninstall`                | Uninstalls and deletes the Ubuntu image.  By default this does not remove the user's Ubuntu home directory. <br/> **/y** may be added to automatically accept the confirmation prompt <br/>**/full** uninstalls and deletes the user's Ubuntu home directory               |
