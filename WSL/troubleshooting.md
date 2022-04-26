---
title: Troubleshooting Windows Subsystem for Linux
description: Provides detailed information about common errors and issues people run into while running Linux on the Windows Subsystem for Linux. 
ms.date: 09/27/2021
ms.topic: article
---

# Troubleshooting Windows Subsystem for Linux

We have covered some common troubleshooting scenarios associated with WSL below, but please consider searching the issues filed in the [WSL product repo on GitHub](https://github.com/Microsoft/wsl/issues) as well.

## File an issue, bug report, feature request

The [WSL product repo issues](https://github.com/Microsoft/wsl/issues) enables you to:

- **Search existing issues** to see if there are any associated with a problem that you are having. Note that in the search bar, you can remove "is:open" to include issues that have already been resolved in your search. Please consider commenting or giving a thumbs up to any open issues that you would like to express your interest in moving forward as a priority.
- **File a new issue**. If you have found a problem with WSL and there does not appear to be an existing issue, you can select the green *New issue* button and then choose *WSL - Bug Report*. You will need to include a title for the issue, your Windows build number (run `cmd.exe /c ver` to see your current build #), whether you're running WSL 1 or 2, your current Linux Kernel version # (run `wsl.exe --status` or `cat /proc/version`), the version # of your distribution (run `lsb_release -r`), any other software versions involved, the repro steps, expected behavior, actual behavior, and diagnostic logs if available and appropriate. For more info, see [contributing to WSL](https://github.com/microsoft/WSL/blob/master/CONTRIBUTING.md).
- **File a feature request** by selecting the green *New issue* button and then select *Feature request*. You will need to address a few questions describing your request.

You can also:

- **File a documentation issue** using the [WSL docs repo](https://github.com/MicrosoftDocs/wsl/issues). To contribute to the WSL docs, see the [Microsoft Docs contributor guide](/contribute).
- **File a Windows Terminal** issue using the the [Windows Terminal product repo](https://github.com/microsoft/terminal/issues) if your problem is related more to the Windows Terminal, Windows Console, or the command-line UI.

## Installation issues

- **Installation failed with error 0x80070003**
  - The Windows Subsystem for Linux only runs on your system drive (usually this is your `C:` drive). Make sure that distributions are stored on your system drive:  
  - On Windows 10 open **Settings** -> **System** -> **Storage** -> **More Storage Settings: Change where new content is saved**
    ![Picture of system settings to install apps on C: drive (Windows 10)](media/appstorage.png)
  - On Windows 11 open **Settings** -> **System** -> **Storage** -> **Advanced storage settings** -> **Where new content is saved**
    ![Picture of system settings to install apps on C: drive (Windows 11)](media/appstorage-11.png)  

- **WslRegisterDistribution failed with error 0x8007019e**
  - The Windows Subsystem for Linux optional component is not enabled:
  - Open **Control Panel** -> **Programs and Features** -> **Turn Windows Feature on or off** -> Check **Windows Subsystem for Linux** or using the PowerShell cmdlet mentioned at the beginning of this article.

- **Installation failed with error 0x80070003 or error 0x80370102**
  - Please make sure that virtualization is enabled inside of your computer's BIOS. The instructions on how to do this will vary from computer to computer, and will most likely be under CPU related options.
  - WSL2 requires that your CPU supports the Second Level Address Translation (SLAT) feature, which was introduced in Intel Nehalem processors (Intel Core 1st Generation) and AMD Opteron. Older CPUs (such as the Intel Core 2 Duo) will not be able to run WSL2, even if the Virtual Machine Platform is successfully installed. 

- **Error when trying to upgrade: `Invalid command line option: wsl --set-version Ubuntu 2`**
  - Ensure that you have the Windows Subsystem for Linux enabled, and that you're using Windows Build version 18362 or later. To enable WSL run this command in a PowerShell prompt with admin privileges: `Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux`.

- **The requested operation could not be completed due to a virtual disk system limitation. Virtual hard disk files must be uncompressed and unencrypted and must not be sparse.**
  - Deselect “Compress contents” (as well as “Encrypt contents” if that’s checked) by opening the profile folder for your Linux distribution. It should be located in a folder on your Windows file system, something like: `%USERPROFILE%\AppData\Local\Packages\CanonicalGroupLimited...`
  - In this Linux distro profile, there should be a LocalState folder. Right-click this folder to display a menu of options. Select Properties > Advanced and then ensure that the “Compress contents to save disk space” and “Encrypt contents to secure data” checkboxes are unselected (not checked). If you are asked whether to apply this to just to the current folder or to all subfolders and files, select “just this folder” because you are only clearing the compress flag. After this, the `wsl --set-version` command should work.

![Screenshot of WSL distro property settings](media/troubleshooting-virtualdisk-compress.png)

> [!NOTE]
> In my case, the LocalState folder for my Ubuntu 18.04 distribution was located at C:\Users\<my-user-name>\AppData\Local\Packages\CanonicalGroupLimited.Ubuntu18.04onWindows_79rhkp1fndgsc
>
> Check [WSL Docs GitHub thread #4103](https://github.com/microsoft/WSL/issues/4103) where this issue is being tracked for updated information.

- **The term 'wsl' is not recognized as the name of a cmdlet, function, script file, or operable program.**
  - Ensure that the [Windows Subsystem for Linux Optional Component is installed](./install-manual.md#step-3---enable-virtual-machine-feature). Additionally, if you are using an ARM64 device and running this command from PowerShell, you will receive this error. Instead run `wsl.exe` from [PowerShell Core](/powershell/scripting/install/installing-powershell-core-on-windows), or Command Prompt.

- **Error: Windows Subsystem for Linux has no installed distributions.**
  - If you receive this error after you have already installed WSL distributions:
  1. Run the distribution at least once before invoking it from the command line.
  2. Check whether you may be running separate user accounts. Running your primary user account with elevated permissions (in admin mode) should not result in this error, but you should ensure that you aren't accidentally running the built-in Administrator account that comes with Windows. This is a separate user account and will not show any installed WSL distributions by design. For more info, see [Enable and Disable the Built-in Administrator Account](/windows-hardware/manufacture/desktop/enable-and-disable-the-built-in-administrator-account).
  3. The WSL executable is only installed to the native system directory. When you’re running a 32-bit process on 64-bit Windows (or on ARM64, any non-native combination), the hosted non-native process actually sees a different System32 folder. (The one a 32-bit process sees on x64 Windows is stored on disk at \Windows\SysWOW64.) You can access the “native” system32 from a hosted process by looking in the virtual folder: `\Windows\sysnative`. It won’t actually be present on disk, mind you, but the filesystem path resolver will find it.

- **Error: This update only applies to machines with the Windows Subsystem for Linux.**
  - To install the Linux kernel update MSI package, WSL is required and should be enabled first. If it fails, it you will see the message: `This update only applies to machines with the Windows Subsystem for Linux`.
  - There are three possible reason you see this message:

  1. You are still in old version of Windows which doesn't support WSL 2. See step #2 for version requirements and links to update.

  2. WSL is not enabled. You will need to return to step #1 and ensure that the optional WSL feature is enabled on your machine.

  3. After you enabled WSL, a reboot is required for it to take effect, reboot your machine and try again.

- **Error: WSL 2 requires an update to its kernel component. For information please visit https://aka.ms/wsl2kernel .**
  - If the Linux kernel package is missing in the %SystemRoot%\system32\lxss\tools folder, you will encounter this error. Resolve it by installing the Linux kernel update MSI package in step #4 of these installation instructions. You may need to uninstall the MSI from ['Add or Remove Programs'](ms-settings:appsfeatures-app), and install it again.

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

The actual error for `0x1bc` is:

```powershell
WSL 2 requires an update to its kernel component. For information please visit https://aka.ms/wsl2kernel
```

For more information, please refer to issue [5749](https://github.com/microsoft/WSL/issues/5749)

### Cannot access WSL files from Windows

A 9p protocol file server provides the service on the Linux side to allow Windows to access the Linux file system. If you cannot access WSL using `\\wsl$` on Windows, it could be because 9P did not start correctly.

To check this, you can check the start up logs using: `dmesg |grep 9p`, and this will show you any errors. A successful output looks like the following:

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

```Bash
if [ "`id -u`" -eq 0 ]; then
  PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:$PATH"
else
  PATH="/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:$PATH"
fi
```

For more information, see issue [5296](https://github.com/microsoft/WSL/issues/5296) and issue [5779](https://github.com/microsoft/WSL/issues/5779).

### "Error: 0x80370102 The virtual machine could not be started because a required feature is not installed."

Please enable the Virtual Machine Platform Windows feature and ensure virtualization is enabled in the BIOS.

1. Check the [Hyper-V system requirements](/windows-server/virtualization/hyper-v/system-requirements-for-hyper-v-on-windows#:~:text=on%20Windows%20Server.-,General%20requirements,the%20processor%20must%20have%20SLAT.)

2. If your machine is a VM, please enable [nested virtualization](./faq.yml#can-i-run-wsl-2-in-a-virtual-machine-) manually. Launch powershell with admin, and run:

    ```powershell
    Set-VMProcessor -VMName <VMName> -ExposeVirtualizationExtensions $true
    ```

3. Please follow guidelines from your PC's manufacturer on how to enable virtualization. In general, this can involve using the system BIOS to ensure that these features are enabled on your CPU. Instructions for this process can vary from machine to machine, please see [this article](https://www.bleepingcomputer.com/tutorials/how-to-enable-cpu-virtualization-in-your-computer-bios/) from Bleeping Computer for an example.

4. Restart your machine after enabling the `Virtual Machine Platform` optional component.

5. Make sure that the hypervisor launch is enabled in your boot configuration. You can validate this by running (elevated powershell):

	```powershell
	bcdedit /enum | findstr -i hypervisorlaunchtype
	```

	If you see `hypervisorlaunchtype    Off`, then the hypervisor is disabled. To enable it run in an elevated powershell:

	```
	bcdedit /set {current} hypervisorlaunchtype Auto
	```

6. Additionally, if you have 3rd party hypervisors installed (Such as VMware or VirtualBox) then please ensure you have these on the latest versions which can support HyperV ([VMware 15.5.5+](https://blogs.vmware.com/workstation/2020/05/vmware-workstation-now-supports-hyper-v-mode.html) and [VirtualBox 6+](https://www.virtualbox.org/wiki/Changelog-6.0)) or are turned off.

Learn more about how to [Configure Nested Virtualization](/virtualization/hyper-v-on-windows/user-guide/nested-virtualization#configure-nested-virtualization) when running Hyper-V in a Virtual Machine.

### Bash loses network connectivity once connected to a VPN

If after connecting to a VPN on Windows, bash loses network connectivity, try this workaround from within bash. This workaround will allow you to manually override the DNS resolution through `/etc/resolv.conf`.

1. Take a note of the DNS server of the VPN from doing `ipconfig.exe /all`
2. Make a copy of the existing resolv.conf
   `sudo cp /etc/resolv.conf /etc/resolv.conf.new`
3. Unlink the current resolv.conf
   `sudo unlink /etc/resolv.conf`
4. `sudo mv /etc/resolv.conf.new /etc/resolv.conf`
5. Edit `/etc/wsl.conf` and add this content to the file. (More info on this set up can be found in [Advanced settings configuration](./wsl-config.md))
```
[network]
generateResolvConf=false
```
6. Open `/etc/resolv.conf` and <br/>
   a. Delete the first line from the file which has a comment describing automatic generation<br/>
   b. Add the DNS entry from (1) above as the very first entry in the list of DNS servers. <br/>
   c. Close the file. <br/>

Once you have disconnected the VPN, you will have to revert the changes to `/etc/resolv.conf`. To do this, do:

1. `cd /etc`
2. `sudo mv resolv.conf resolv.conf.new`
3. `sudo ln -s ../run/resolvconf/resolv.conf resolv.conf`

### Starting WSL or installing a distribution returns an error code

Follow [these instructions](https://github.com/Microsoft/WSL/blob/master/CONTRIBUTING.md#8-detailed-logs) to collect detailed logs and file an issue on our GitHub.

### Updating WSL

There are two components of Windows Subsystem for Linux that can require updating.

1. To update the Windows Subsystem for Linux itself, use the command `wsl --update` in PowerShell or CMD.

2. To update the specific Linux distribution user binaries, use the command: `apt-get update | apt-get upgrade` in the Linux distribution that you are seeking to update.
  
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

The Windows Subsystem for Linux feature may be disabled during a Windows update. If this happens the Windows feature must be re-enabled. Instructions for enabling the Windows Subsystem for Linux can be found in the [Manual Installation Guide](./install-manual.md).

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
4. Symantec Endpoint Protection

In some cases turning off the firewall allows for access.  In some cases simply having the firewall installed looks to block access.

If you are using Microsoft Defender Firewall, unchecking "Blocks all incoming connections, including those in the list of allowed apps." allows for access.

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

You can confirm that the Windows Subsystem for Linux is enabled by running the following in an elevated PowerShell window:  

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
   https://ubuntu.com/server/docs/service-openssh

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

- If both of those fail and you need to access WSL please consider upgrading in place by reinstalling Windows using installation media and selecting 'Keep Everything' to ensure your apps and files are preserved. You can find instructions on how to do so at the [Reinstall Windows 10 page](https://support.microsoft.com/help/4000735/windows-10-reinstall).

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

Some distributions [available in Microsoft Store](install-manual.md#step-6---install-your-linux-distribution-of-choice) are yet not fully compatible to run Windows commands out of the box. If you get an error `-bash: powershell.exe: command not found` running `powershell.exe /c start .` or any other Windows command, you can resolve it following these steps:

1. In your WSL distribution run `echo $PATH`.  
   If it does not include: `/mnt/c/Windows/system32` something is redefining the standard PATH variable.
2. Check profile settings with `cat /etc/profile`.  
   If it contains assignment of the PATH variable, edit the file to comment out PATH assignment block with a **#** character.
3. Check if wsl.conf is present `cat /etc/wsl.conf` and make sure it does not contain `appendWindowsPath=false`, otherwise comment it out.
4. Restart distribution by typing `wsl -t ` followed by distribution name or run `wsl --shutdown` either in cmd or PowerShell.

### Unable to boot after installing WSL 2

We are aware of an issue affecting users where they are unable to boot after installing WSL 2. While we fully diagnose those issue, users have reported that [changing the buffer size](https://github.com/microsoft/WSL/issues/4784#issuecomment-639219363) or [installing the right drivers](https://github.com/microsoft/WSL/issues/4784#issuecomment-675702244) can help address this. Please view this [Github issue](https://github.com/microsoft/WSL/issues/4784) to see the latest updates on this issue. 

### WSL 2 errors when ICS is disabled

Internet Connection Sharing (ICS) is a required component of WSL 2. The ICS service is used by the Host Network Service (HNS) to create the underlying virtual network which WSL 2 relies on for NAT, DNS, DHCP, and host connection sharing.

Disabling the ICS service (SharedAccess) or disabling ICS through group policy will prevent the WSL HNS network from being created. This will result in failures when creating a new WSL version 2 image, and the following error when trying to convert a version 1 image to version 2.

```console
There are no more endpoints available from the endpoint mapper.
```

Systems that require WSL 2 should leave the ICS service (SharedAccess) in it's default start state, Manual (Trigger Start), and any policy that disables ICS should be overwritten or removed. While disabling the ICS service will break WSL 2, and we do not recommend disabling ICS, portions of ICS can be disabled [using these instructions](/windows/security/threat-protection/microsoft-defender-application-guard/faq-md-app-guard)ng-application-guard-)

## Using older versions of Windows and WSL

There are several differences to note if you're running an older version of Windows and WSL, like the Windows 10 Creators Update (Oct 2017, Build 16299) or Anniversary Update (Aug 2016, Build 14393). We recommend that you [update to the latest Windows version](ms-settings:windowsupdate), but if that's not possible, we have outlined some of the differences below.

Interoperability command differences:

- `bash.exe` has been replaced with `wsl.exe`. Linux commands can be run from the Windows Command Prompt or from PowerShell, but for early Windows versions, you man need to use the `bash` command. For example: `C:\temp> bash -c "ls -la"`. The WSL commands passed into `bash -c` are forwarded to the WSL process without modification.  File paths must be specified in the WSL format and care must be taken to escape relevant characters. For example: `C:\temp> bash -c "ls -la /proc/cpuinfo"` or `C:\temp> bash -c "ls -la \"/mnt/c/Program Files\""`.
- To see what commands are available for a particular distribution, run `[distro.exe] /?`. For example, with Ubuntu: `C:\> ubuntu.exe /?`.
- Windows path is included in the WSL `$PATH`.
- When calling a Windows tool from a WSL distribution in an earlier version of Windows 10, you will need to specify the directory path. For example, to call the Windows Notepad app from your WSL command line, enter: `/mnt/c/Windows/System32/notepad.exe`
- To change the default user to `root` use this command in PowerShell: `C:\> lxrun /setdefaultuser root` and then run Bash.exe to log in: `C:\> bash.exe`. Reset your password using the distributions password command: `$ passwd username` and then close the Linux command line: `$ exit`. From Windows command prompt or Powershell, reset your default user back to your normal Linux user account: `C:\> lxrun.exe /setdefaultuser username`.

## Uninstall legacy version of WSL

If you originally installed WSL on a version of Windows 10 prior to Creators update (Oct 2017, Build 16299), we recommend that you migrate any necessary files, data, etc. from the older Linux distribution you installed, to a newer distribution installed via the Microsoft Store. To remove the legacy distribution from your machine, run the following from a Command Line or PowerShell instance: `wsl --unregister Legacy`. You also have the option to manually remove the older legacy distribution by deleting the `%localappdata%\lxss\` folder (and all it's sub-contents) using Windows File Explorer or with PowerShell: `rm -Recurse $env:localappdata/lxss/`.
