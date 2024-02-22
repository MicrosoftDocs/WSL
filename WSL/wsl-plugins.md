---
title: WSL Plugins
description: Learn how Windows applications can use WSL plugins to integrate their workflow inside of WSL
ms.date: 10/14/2023
ms.topic: article
---

# WSL Plugins

Windows applications can now create and interact with Linux processes running inside of the Windows Subsystem for Linux (WSL) with WSL plugins. This article gives an overview of how they work, and how to get started using them. 

## Understanding Plugin functionality

WSL plugins provide these core functionalities:

- Allows applications to specify a Windows executable that starts when the WSL virtual machine is started
- The Windows executable can create Linux processes inside of WSL, and it can communicate directly to them using a virtualized socket

Using these, Windows applications can build ontop of WSL experiences and provide additional functionality related to the Windows Subsystem for Linux.

## Installing a Plugin 

As a WSL plugin creator, you can install your plugin on a machine by setting a registry key to point to your plugin’s DLL file. 

And as a WSL user, any application that you use will automatically install WSL plugins as part of their normal install process.

## Creating your own Plugin

To start a plugin project  you will need to build a Win32 dll. The simplest way to get set up with this is to try our WSL plugin sample project. You can do this by cloning the [WSL plugin sample repository](https://github.com/microsoft/wsl-plugin-sample) to a local folder with `git clone` and open it in Visual Studio.

When you open the project please navigate to the `dllmain.cpp` file (https://github.com/microsoft/wsl-plugin-sample/blob/main/plugin.cpp) and you will see the list of functions available to WSL plugins. 

You can then press the “Build” tab and build your project, which will output a DLL ready you to use, likely under `wsl-plugin-sample\x64\Debug\WSLPluginSample.dll`.

### Testing your Plugin

WSL plugins will only run if they are [digitally signed](/windows-hardware/drivers/install/digital-signatures). To test this you will need to enable test signing on your machine. 

#### Enabling test signing and creating a test certification

Open an elevated PowerShell Window and [enable test signing](/windows-hardware/drivers/install/the-testsigning-boot-configuration-option#enable-or-disable-use-of-test-signed-code) by running this command:
```powershell
## If this command results in "The value is protected by Secure Boot policy and cannot be modified or deleted"
## Then reboot the PC, go into BIOS settings, and disable Secure Boot. BitLocker may also affect your ability to modify this setting.
Bcdedit.exe -set TESTSIGNING ON
```

Once test signing is enabled (A reboot may required), in an elevated Powershell command prompt that is at the directory of your WSLPluginSample.dll file created above we will create a WSL test certificate:

```powershell
# Create the cert
$certname = "WSLPluginTestCert"
$cert = New-SelfSignedCertificate -Subject "CN=$certname" -CertStoreLocation "Cert:\CurrentUser\My" -KeyExportPolicy Exportable -KeySpec Signature -KeyLength 2048 -KeyAlgorithm RSA -HashAlgorithm SHA256 -Type CodeSigningCert

# Export it to a local path
Export-Certificate -Cert $cert -FilePath ".\$certname.cer"

# Sign the DLL file
Set-AuthenticodeSignature -FilePath "C:\dev\Path\To\Your\WSLPlugin.dll" -Certificate $cert
```

Last import the certificate to the Trusted Root Certification Authority:

```powershell
certutil -addstore "Root" ".\$certname.cer"
```

See the [how to create a self signed certificate](/entra/identity-platform/howto-create-self-signed-certificate) docs page for more info.

#### Install the plugin

In the same elevated PowerShell window, run the command below to install the plugin, and be sure to change the path to the plugin DLL to your existing path: 

```powershell
Reg.exe add HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Lxss\Plugins /v demo-plugin /t REG_SZ /d C:\Path\to\plugin.dll  /f
```

To use the plugin, restart the wsl service via: 

```powershell
sc.exe stop wslservice
wsl.exe echo “test”
```

Your plugin should now be loaded. See the [Troubleshooting and additional information](#troubleshooting-and-additional-information) section for more information if the plugin failed to load.

And then when you are finished, you can run this command to remove the plugin (Please keep in mind you will need to restart the WSL service for it to take effect):

```powershell
Reg.exe delete HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Lxss\Plugins /v demo-plugin
```

## Troubleshooting and additional information


Common error codes:

- Wsl/Service/CreateInstance/CreateVm/Plugin/ERROR_MOD_NOT_FOUND -> The plugin DLL could not be loaded. Check that the plugin registration path is correct
- Wsl/Service/CreateInstance/CreateVm/Plugin/TRUST_E_NOSIGNATURE -> The plugin DLL is not signed, or its signature is not trusted by the computer
   - Please [enable test signing](/windows-hardware/drivers/install/the-testsigning-boot-configuration-option#enable-or-disable-use-of-test-signed-code) and see [the signing section above on how to set up a test certificate](#enabling-test-signing-and-creating-a-test-certification).
- Wsl/Service/CreateInstance/CreateVm/Plugin/* -> The plugin DLL returned an error in WSLPLUGINAPI_ENTRYPOINTV1 or OnVmStarted()
- Wsl/Service/CreateInstance/Plugin/* -> The plugin DLL returned an error in OnDistributionStarted()

## Plugins Linux user space

Linux processes created via ExecuteBinary() will run in the root namespace of the WSL2 Virtual Machine. This namespace is not associated to any distribution and has a very minimal Mariner based root file system.

That file system is a writable tmpfs, meaning that all changes made to it will be dropped when the WSL2 Virtual Machine is shut down.

You can inspect the content of the root namespace by running `wsl --debug-shell` while WSL is running.

### Additional considerations 

-	All WSL plugin hooks are synchronous, meaning that WSL will wait for the plugin hooks to be completed before continuing. 
-	Any error returned by a plugin is considered fatal by WSL (meaning that the user’s distribution will not start)
-	The plugin code runs in the same address space as the WSL service. Any crash in a plugin will crash the entire WSL service, potentially causing data loss
