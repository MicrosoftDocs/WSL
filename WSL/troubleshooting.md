---
title: Troubleshooting the Windows Subsystem for Linux
description: Provides detailed information about common errors and issues people run into while running Linux on the Windows Subsystem for Linux. 
keywords: BashOnWindows, bash, wsl, windows, windowssubsystem, ubuntu
ms.date: 09/28/2020
ms.topic: article
ms.localizationpriority: high
---

# Troubleshooting Windows Subsystem for Linux

For support with issues related to WSL, please see our [WSL product repo on GitHub](https://github.com/Microsoft/wsl/issues).

## Search for any existing issues related to your problem

For technical issues, use the [product repo](https://github.com/Microsoft/wsl/issues).

For issues related to the contents of this documentation, use the [docs repo](https://github.com/MicrosoftDocs/wsl/issues).

## Submit a bug report

For bugs related to WSL functions or features, file an issue in the product repo: https://github.com/Microsoft/wsl/issues

## Submit a feature request

To request a new feature related to WSL functionality or compatibility, [file an issue in the product repo](https://github.com/Microsoft/wsl/issues).

## Contribute to the docs

To contribute to the WSL documentation, submit a pull request in the docs repo: https://github.com/MicrosoftDocs/wsl/issues

## Terminal or Command Line

Lastly, if your issue is related to the Windows Terminal, Windows Console, or the command-line UI, use the Windows terminal repo: https://github.com/microsoft/terminal

## Common issues

### I'm on Windows 10 version 1903 and I still do not see options for WSL 2

This is likely because your machine has not yet taken the backport for WSL 2. The simplest way to resolve this is by going to Windows Settings and clicking 'Check for Updates' to install the latest updates on your system. See [the full instructions on taking the backport](https://devblogs.microsoft.com/commandline/wsl-2-support-is-coming-to-windows-10-versions-1903-and-1909/#how-do-i-get-it).

If you hit 'Check for Updates' and still do not receive the update you can [install KB KB4566116 manually](https://www.catalog.update.microsoft.com/Search.aspx?q=KB4566116).  

### Error: 0x1bc when `wsl --set-default-version 2`

This may happen when 'Display Language' or 'System Locale' setting is not English.

```powershell
wsl --set-default-version 2
Error: 0x1bc
For information on key differences with WSL 2 please visit https://aka.ms/wsl2
```

THe actual error for `0x1bc` is:

```powershell
WSL 2 requires an update to its kernel component. For information please visit https://aka.ms/wsl2kernel
```

For more information, please refer to issue [5749](https://github.com/microsoft/WSL/issues/5749)

### Cannot access WSL files from Windows

A 9p protocol file server provides the service on the Linux side to allow Windows to access the Linux file system. If you cannot access WSL using `\\wsl$` on Windows, it could be because 9P did not start correctly.

To check this, you can check the start up logs using: `dmesg |grep 9p`, and this will show you any errors. A successfull output looks like the following:

```bash
[    0.363323] 9p: Installing v9fs 9p2000 file system support
[    0.363336] FS-Cache: Netfs '9p' registered for caching
[    0.398989] 9pnet: Installing 9P2000 support
```

Please see [this Github thread](https://github.com/microsoft/wsl/issues/5307) for further discussion on this issue.

### Can't start WSL 2 distribution and only see 'WSL 2' in output

If your display language is not English, then it is possible you are seeing a truncated version of an error text.

```powershell
C:\Users\me>wsl
WSL 2
```

To resolve this issue, please visit `https://aka.ms/wsl2kernel` and install the kernel manually by following the directions on that doc page. 

### `command not found` when executing windows .exe in linux

Users can run Windows executables like notepad.exe directly from Linux. Sometimes, you may hit "command not found" like below: 

```Bash
$ notepad.exe
-bash: notepad.exe: command not found
```

If there are no win32 paths in your $PATH, interop isn't going to find the .exe.
You can verify it by running `echo $PATH` in Linux. It's expected that you will see a win32 path (for example, /mnt/c/Windows) in the output.
If you can't see any Windows paths then most likely your PATH is being overwritten by your Linux shell. 

Here is a an example that /etc/profile on Debian contributed to the problem:

```Bash
if [ "`id -u`" -eq 0 ]; then
  PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
else
  PATH="/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games"
fi
```

The correct way on Debian is to remove above lines.
You may also append $PATH during the assignment like below, but this lead to some [other problems](https://salsa.debian.org/debian/WSL/-/commit/7611edba482fd0b3f67143aa0fc1e2cc1d4100a6) with WSL and VSCode..

For more information, see issue [5296](https://github.com/microsoft/WSL/issues/5296) and issue [5779](https://github.com/microsoft/WSL/issues/5779).

### Please enable the Virtual Machine Platform Windows feature and ensure virtualization is enabled in the BIOS

Please enable the Virtual Machine Platform Windows feature and ensure virtualization is enabled in the BIOS.

1. Check the [Hyper-V system requirements](/windows-server/virtualization/hyper-v/system-requirements-for-hyper-v-on-windows#:~:text=on%20Windows%20Server.-,General%20requirements,the%20processor%20must%20have%20SLAT.)

2. If your machine is a VM, please enable [nested virtualization](./wsl2-faq.md#can-i-run-wsl-2-in-a-virtual-machine) manually. Launch powershell with admin, and run:

    ```powershell
    Set-VMProcessor -VMName <VMName> -ExposeVirtualizationExtensions $true
    ```

3. Please follow guidelines from your PC's manufacturer on how to enable virtualization. In general, this can involve using the system BIOS to ensure that these features are enabled on your CPU. Instructions for this process can vary from machine to machine, please see [this article](https://www.bleepingcomputer.com/tutorials/how-to-enable-cpu-virtualization-in-your-computer-bios/) from Bleeping Computer for an example.

4. Restart your machine after enabling the `Virtual Machine Platform` optional component.

### Bash loses network connectivity once connected to a VPN

If after connecting to a VPN on Windows, bash loses network connectivity, try this workaround from within bash. This workaround will allow you to manually override the DNS resolution through `/etc/resolv.conf`.

1. Take a note of the DNS server of the VPN from doing `ipconfig.exe /all`
2. Make a copy of the existing resolv.conf
   `sudo cp /etc/resolv.conf /etc/resolv.conf.new`
3. Unlink the current resolv.conf
   `sudo unlink /etc/resolv.conf`
4. `sudo mv /etc/resolv.conf.new /etc/resolv.conf`
5. Open `/etc/resolv.conf` and <br/>
   a. Delete the first line from the file, which says "\# This file was automatically generated by WSL. To stop automatic generation of this file, remove this line.". <br/>
   b. Add the DNS entry from (1) above as the very first entry in the list of DNS servers. <br/>
   c. Close the file. <br/>

Once you have disconnected the VPN, you will have to revert the changes to `/etc/resolv.conf`. To do this, do:

1. `cd /etc`
2. `sudo mv resolv.conf resolv.conf.new`
3. `sudo ln -s ../run/resolvconf/resolv.conf resolv.conf`

### Starting WSL or installing a distribution returns an error code

Follow [these instructions](https://github.com/Microsoft/WSL/blob/master/CONTRIBUTING.md#8-detailed-logs) to collect detailed logs and file an issue on our GitHub.

### Updating Bash on Ubuntu on Windows

There are two components of Bash on Ubuntu on Windows that can require updating.

1. The Windows Subsystem for Linux
  
   Upgrading this portion of Bash on Ubuntu on Windows will enable any new fixes outlines in the [release notes](./release-notes.md). Ensure that you are subscribed to the Windows Insider Program and that your build is up to date. For finer grain control including resetting your Ubuntu instance check out the [command reference page](./reference.md).

2. The Ubuntu user binaries

   Upgrading this portion of Bash on Ubuntu on Windows will install any updates to the Ubuntu user binaries including applications that you have installed via apt-get. To update run the following commands in Bash:
  
   1. `apt-get update`
   2. `apt-get upgrade`
  
### Apt-get upgrade errors

Some packages use features that we haven't implemented yet. `udev`, for example, isn't supported yet and causes several `apt-get upgrade` errors.

To fix issues related to `udev`, follow the following steps:

1. Write the following to `/usr/sbin/policy-rc.d` and save your changes.
  
   ```bash
   #!/bin/sh
   exit 101
   ```
  
2. Add execute permissions to `/usr/sbin/policy-rc.d`:

   ```bash
   chmod +x /usr/sbin/policy-rc.d
   ```
  
3. Run the following commands:

   ```bash
   dpkg-divert --local --rename --add /sbin/initctl
   ln -s /bin/true /sbin/initctl
   ```
  
### "Error: 0x80040306" on installation

This has to do with the fact that we do not support legacy console.
To turn off legacy console:

1. Open cmd.exe
1. Right click title bar -> Properties -> Uncheck Use legacy console
1. Click OK

### "Error: 0x80040154" after Windows update

The Windows Subsystem for Linux feature may be disabled during a Windows update. If this happens the Windows feature must be re-enabled. Instructions for enabling the Windows Subsystem for Linux can be found in the [Installation Guide](./install-win10.md).

### Changing the display language

WSL install will try to automatically change the Ubuntu locale to match the locale of your Windows install.  If you do not want this behavior you can run this command to change the Ubuntu locale after install completes.  You will have to relaunch bash.exe for this change to take effect.

The below example changes to locale to en-US:

```bash
sudo update-locale LANG=en_US.UTF8
```

### Installation issues after Windows system restore

1. Delete the `%windir%\System32\Tasks\Microsoft\Windows\Windows Subsystem for Linux` folder. <br/>
  **Note: Do not do this if your optional feature is fully installed and working.**
2. Enable the WSL optional feature (if not already)
3. Reboot
4. lxrun /uninstall /full
5. Install bash

### No internet access in WSL

Some users have reported issues with specific firewall applications blocking internet access in WSL.  The firewalls reported are:

1. Kaspersky
2. AVG
3. Avast

In some cases turning off the firewall allows for access.  In some cases simply having the firewall installed looks to block access.

### Permission Denied error when using ping

For [Windows Anniversary Update, version 1607](./release-notes.md#build-14388-to-windows-10-anniversary-update),
**administrator privileges** in Windows are required to run ping in WSL.  To run ping, run Bash on Ubuntu on Windows as an administrator, or run bash.exe from a CMD/PowerShell prompt with administrator privileges.

For later versions of Windows, [Build 14926+](./release-notes.md#build-14926), administrator privileges are no longer required.

### Bash is hung

If while working with bash, you find that bash is hung (or deadlocked) and not responding to inputs, help us diagnose the issue by collecting and reporting a memory dump. Note that these steps will crash your system. Do not do this if you are not comfortable with that or save your work prior to doing this.

To collect a memory dump

1. Change the memory dump type to "complete memory dump". While changing the dump type, take a note of your current type.

2. Use the [steps](https://techcommunity.microsoft.com/t5/Core-Infrastructure-and-Security/How-to-Force-a-Diagnostic-Memory-Dump-When-a-Computer-Hangs/ba-p/257809) to configure crash using keyboard control.

3. Repro the hang or deadlock.

4. Crash the system using the key sequence from (2).

5. The system will crash and collect the memory dump.

6. Once the system reboots, report the memory.dmp to secure@microsoft.com. The default location of the dump file is %SystemRoot%\memory.dmp or C:\Windows\memory.dmp if C: is the system drive. In the email, note that the dump is for the WSL or Bash on Windows team.

7. Restore the memory dump type to the original setting.

### Check your build number

To find your PC's architecture and Windows build number, open  
**Settings** > **System** > **About**

Look for the **OS Build** and **System Type** fields.  
    ![Screenshot of Build and System Type fields](media/system.png)

To find your Windows Server build number, run the following in PowerShell:  

``` PowerShell
systeminfo | Select-String "^OS Name","^OS Version"
```

### Confirm WSL is enabled

You can confirm that the Windows Subsystem for Linux is enabled by running the following in PowerShell:  

``` PowerShell
Get-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```

### OpenSSH-Server connection issues

Trying to connect your SSH server is failed with the following error: "Connection closed by 127.0.0.1 port 22".

1. Make sure your OpenSSH Server is running:

   ```bash
   sudo service ssh status
   ```

   and you've followed this tutorial:
   https://help.ubuntu.com/lts/serverguide/openssh-server.html.en

2. Stop the sshd service and start sshd in debug mode:

   ```bash
   sudo service ssh stop
   sudo /usr/sbin/sshd -d
   ```

3. Check the startup logs and make sure HostKeys are available and you don't see log messages such as:

   ```BASH
   debug1: sshd version OpenSSH_7.2, OpenSSL 1.0.2g  1 Mar 2016
   debug1: key_load_private: incorrect passphrase supplied to decrypt private key
   debug1: key_load_public: No such file or directory
   Could not load host key: /etc/ssh/ssh_host_rsa_key
   debug1: key_load_private: No such file or directory
   debug1: key_load_public: No such file or directory
   Could not load host key: /etc/ssh/ssh_host_dsa_key
   debug1: key_load_private: No such file or directory
   debug1: key_load_public: No such file or directory
   Could not load host key: /etc/ssh/ssh_host_ecdsa_key
   debug1: key_load_private: No such file or directory
   debug1: key_load_public: No such file or directory
   Could not load host key: /etc/ssh/ssh_host_ed25519_key
   ```

If you do see such messages and the keys are missing under `/etc/ssh/`, you will have to regenerate the keys or just purge&install openssh-server:

```BASH
sudo apt-get purge openssh-server
sudo apt-get install openssh-server
```

### "The referenced assembly could not be found." when enabling the WSL optional feature

This error is related to being in a bad install state. Please complete the following steps to try and fix this issue:

- If you are running the enable WSL feature command from PowerShell, try using the GUI instead by opening the start menu, searching for 'Turn Windows features on or off' and then in the list select 'Windows Subsystem for Linux' which will install the optional component.

- Update your version of Windows by going to Settings, Updates, and clicking 'Check for Updates'

- If both of those fail and you need to access WSL please consider upgrading in place by reinstalling Windows 10 using installation media and selecting 'Keep Everything' to ensure your apps and files are preserved. You can find instructions on how to do so at the [Reinstall Windows 10 page](https://support.microsoft.com/help/4000735/windows-10-reinstall).

### Correct (SSH related) permission errors

If you're seeing this error:

```bash
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@         WARNING: UNPROTECTED PRIVATE KEY FILE!          @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Permissions 0777 for '/home/artur/.ssh/private-key.pem' are too open.
```

To fix this, append the following to the the ```/etc/wsl.conf``` file:

```bash
[automount]
enabled = true
options = metadata,uid=1000,gid=1000,umask=0022
```

Please note that adding this command will include metadata and modify the file permissions on the Windows files seen from WSL. Please see the [File System Permissions](./file-permissions.md) for more information.

### Running Windows commands fails inside a distribution

Some distributions [available in Microsoft Store](install-win10.md#step-6---install-your-linux-distribution-of-choice) are yet not fully compatible to run Windows commands in [Terminal](https://en.wikipedia.org/wiki/Linux_console) out of the box. If you get an error `-bash: powershell.exe: command not found` running `powershell.exe /c start .` or any other Windows command, you can resolve it following these steps:

1. In your WSL distribution run `echo $PATH`.  
   If it does not include: `/mnt/c/Windows/system32` something is redefining the standard PATH variable.
2. Check profile settings with `cat /etc/profile`.  
   If it contains assignment of the PATH variable, edit the file to comment out PATH assignment block with a **#** character.
3. Check if wsl.conf is present `cat /etc/wsl.conf` and make sure it does not contain `appendWindowsPath=false`, otherwise comment it out.
4. Restart distribution by typing `wsl -t ` followed by distribution name or run `wsl --shutdown` either in cmd or PowerShell.