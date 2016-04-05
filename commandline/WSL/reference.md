#Commands
This environment uses the following command line commands.


| Command                     | Action                     |
|:----------------------------|:---------------------------|
| `bash`                      | If the Ubuntu image is installed, this command puts the user into the bash shell in the current directory. <br/> <br/> If the Ubuntu image is not installed, this command will start the install process. |
| `bash ~`                    | Launches the bash shell into the user's Ubuntu home directory.  Similar to running cd ~            |
| `bash -c "<command>"`       | Runs the command, prints the output and exits back to the Windows command prompt. <br/> <br/> Example:  **bash -c "ls"** |
| `lxrun /install`            | Starts the download and install process.                      |
| `lxrun /install /y`         | Starts the install process without prompting the user for confirmation.            |
| `lxrun /uninstall`          | Uninstalls and deletes the Ubuntu image.  Uninstalling does not remove the user's Ubuntu home directory.  Additionally, /y may be added to skip confirmation.                  |
| `lxrun /uninstall /full`    | Uninstalls and deletes the Ubuntu image along with the user's home directory.  Additionally, /y may be added to skip confirmation.               |
