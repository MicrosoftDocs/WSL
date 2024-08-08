---
title: Intune settings
description: Available settings in Intune for the Windows Subsystem for Linux (WSL)
ms.date: 01/10/2024
ms.topic: article
---

# Intune settings for WSL

You can now use management tools like Intune to manage WSL as a Windows component. 

To access these settings please navigate to your Microsoft Intune admin center portal, and then select: `Devices -> Configuration Profiles -> Create -> New Policy -> Windows 10 and later -> Settings catalog`, create a name for the new profile and search for "Windows Subsystem for Linux" to see and add the full list of available settings. 

## Recommended settings

To maximize security in an enterprise environment, we recommend that you specify these settings:

| Setting Name | Value | Description |
| --- | --- | --- |
| Allow the Inbox version of the Windows Subsystem for Linux | Disabled | When set to disabled, this policy disables the inbox version (optional component) of the Windows Subsystem For Linux. If this policy is disabled, only the store version of WSL can be used. [Learn more about the difference between Store WSL and Inbox WSL here](https://aka.ms/wslstoreinfo) |
| Allow WSL1 | Disabled | When set to disabled, this policy disables WSL1. When disabled, only WSL2 distributions can be used. |
| Allow the debug shell | Disabled | When set to disabled, this policy disables the debug shell (wsl.exe --debug-shell). This policy only applies to Store WSL. |
| Allow custom kernel configuration | Disabled | When set to disabled, this policy disables custom kernel configuration via .wslconfig (wsl2.kernel). This policy only applies to Store WSL. |
| Allow kernel command line configuration | Disabled | When set to disabled, this policy disables kernel command line configuration via .wslconfig (wsl2.kernelCommandLine). This policy only applies to Store WSL. |
| Allow custom system distribution configuration | Disabled | When set to disabled, this policy disables custom system distribution configuration via .wslconfig (wsl2.systemDistro). This policy only applies to Store WSL. |
| Allow custom networking configuration | Disabled | When set to disabled, this policy disables custom networking configuration via .wslconfig (wsl2.networkingmode). This policy only applies to Store WSL. |
| Allow user setting firewall configuration | Disabled | When set to disabled, this policy disables firewall configuration via .wslconfig (wsl2.firewall). This policy only applies to Store WSL. |
| Allow nested virtualization | Disabled | When set to disabled, this policy disables nested virtualization configuration via .wslconfig (wsl2.nestedVirtualization). This policy only applies to Store WSL. |
| Allow kernel debugging | Disabled | When set to disabled, this policy disables kernel debugging configuration via .wslconfig (wsl2.kernelDebugPort). This policy only applies to Store WSL. |

## Control access to WSL 

The `AllowWSL`, `AllowInboxWSL`, and `AllowWSL1` settings control user access to WSL. You can configure these settings to enable or disable access to the in-Windows version of WSL, WSL 1 distros, or WSL itself.

This will allow you to configure WSL to ensure that users are only using the latest version of WSL with Enterprise feature support.

## Control WSL commands

`AllowDebugShell` and `AllowDiskMount` control whether users can run the `wsl --debug-shell` and `wsl --mount` commands. Learn more about how to [Mount a disk in WSL 2](./wsl2-mount-disk.md) using the `wsl --mount` command.

## Control access to WSL settings in `.wslconfig`

The last group of settings that end with `*UserSettingConfigurable` control access to WSL advanced settings in `.wslconfig`. When these are set to disabled then users will only be able to use the default value for that setting, and not able to configure it to custom values. Learn more about [Configuration setting for .wslconfig](./wsl-config.md#configuration-settings-for-wslconfig), including a list of settings that can be configured globally for all Linux distributions running with WSL 2.

## Full list of available settings

| Setting Name | Description |
| --- | --- |
| Allow the Windows Subsystem For Linux | When set to disabled, this policy disables access to the Windows Subsystem For Linux for all users on the machine. |
| Allow the Inbox version of the Windows Subsystem For Linux | When set to disabled, this policy disables the inbox version (optional component) of the Windows Subsystem For Linux. If this policy is disabled, only the store version of WSL can be used. |
| Allow WSL1 | When set to disabled, this policy disables WSL1. When disabled, only WSL2 distributions can be used. |
| Allow the debug shell | When set to disabled, this policy disables the debug shell (wsl.exe --debug-shell). This policy only applies to Store WSL. |
| Allow passthrough disk mount | When set to disabled, this policy disables passthrough disk mounting in WSL2 (wsl.exe --mount). This policy only applies to Store WSL. |
| Allow custom kernel configuration | When set to disabled, this policy disables custom kernel configuration via .wslconfig (wsl2.kernel). This policy only applies to Store WSL. |
| Allow kernel command line configuration | When set to disabled, this policy disables kernel command line configuration via .wslconfig (wsl2.kernelCommandLine). This policy only applies to Store WSL. |
| Allow custom system distribution configuration | When set to disabled, this policy disables custom system distribution configuration via .wslconfig (wsl2.systemDistro). This policy only applies to Store WSL. |
| Allow custom networking configuration | When set to disabled, this policy disables custom networking configuration via .wslconfig (wsl2.networkingmode). This policy only applies to Store WSL. |
| Allow user setting firewall configuration | When set to disabled, this policy disables firewall configuration via .wslconfig (wsl2.firewall). This policy only applies to Store WSL. |
| Allow nested virtualization | When set to disabled, this policy disables nested virtualization configuration via .wslconfig (wsl2.nestedVirtualization). This policy only applies to Store WSL. |
| Allow kernel debugging | When set to disabled, this policy disables kernel debugging configuration via .wslconfig (wsl2.kernelDebugPort). This policy only applies to Store WSL. |
