---
title: Connect USB devices
description: Learn how to connect a USB device to your WSL 2 Linux distribution using usbipd-win.
ms.date: 04/16/2024
ms.topic: article
---

# Connect USB devices

This guide will walk through the steps necessary to connect a USB device to a Linux distribution running on WSL 2 using the USB/IP open-source project, [usbipd-win](https://github.com/dorssel/usbipd-win).

Setting up the USB/IP project on your Windows machine will enable common developer USB scenarios like flashing an Arduino or accessing a smartcard reader.

## Prerequisites

- Running Windows 11 (Build 22000 or later). *(Windows 10 support is possible, see note below).*
- A machine with an x64 processor is required. (x86 and Arm64 are currently not supported with usbipd-win).
- WSL is [installed and set up with the latest version](./install.md).
- Linux distribution installed and [set to WSL 2](./basic-commands.md#set-wsl-version-to-1-or-2).

> [!NOTE]
> To check your Windows version and build number, select **Windows logo key + R**, type **winver**, select **OK**. You can update to the latest Windows version by selecting **Start** > **Settings** > **Windows Update** > **[Check for updates](ms-settings:windowsupdate)**.
> To check your Linux kernel version, open your Linux distribution and enter the command: `uname -a`. To manually update to the latest kernel, open PowerShell and enter the command: `wsl --update`.

> [!IMPORTANT]
> WSL now supports both Windows 10 and Windows 11 via the Microsoft Store, meaning that Windows 10 users now have access to the latest kernel versions without needing to compile from source. See [WSL in the Microsoft Store is now generally available on Windows 10 and 11](https://devblogs.microsoft.com/commandline/the-windows-subsystem-for-linux-in-the-microsoft-store-is-now-generally-available-on-windows-10-and-11/) for info on how to update to the Store-supported version of WSL. If you are unable to update to the Store-supported version of WSL and automatically receive kernel updates, see the [USBIPD-WIN project repo](https://github.com/dorssel/usbipd-win/wiki/WSL-support) for instructions on connecting USB devices to a Linux distribution running on WSL 2 by building your own USBIP enabled WSL 2 kernel.

## Install the USBIPD-WIN project

Support for connecting USB devices is not natively available in WSL, so you will need to install the open-source usbipd-win project.

**Kernel requirements**

To use USBIPD with Windows Subsystem for Linux (WSL), you need to have a [Linux kernel version of 5.10.60.1 or higher](https://github.com/dorssel/usbipd-win/wiki/WSL-support/6befeedd4c8e2a49468e4b03532c9a20478f8677). If the installed kernel version is older than 5.10.60.1, then it can be updated by first shutting down any running instances of WSL with `wsl --shutdown`, then running the command: `wsl --update`.

**Install USBIPD on WSL**

1. Go to the [latest release page for the usbipd-win project](https://github.com/dorssel/usbipd-win/releases).
2. Select the .msi file, which will download the installer. (You may get a warning asking you to confirm that you trust this download).
3. Run the downloaded usbipd-win_x.msi installer file.

> [!NOTE]
> Alternatively, you can also install the usbipd-win project using [Windows Package Manager](/windows/package-manager/winget/) (winget). If you have already installed winget, just use the command: `winget install --interactive --exact dorssel.usbipd-win` to install usbipd-win. If you leave out --interactive, winget may immediately restart your computer if that is required to install the drivers.

This will install:

- A service called `usbipd` (display name: USBIP Device Host). You can check the status of this service using the Services app from Windows.
- A command line tool `usbipd`. The location of this tool will be added to the PATH environment variable.
- A firewall rule called `usbipd` to allow all local subnets to connect to the service. You can modify this firewall rule to fine tune access control.

## Attach a USB device

Before attaching your USB device, ensure that a WSL command line is open.  This will keep the WSL 2 lightweight VM active.

> [!NOTE]
> This doc assumes that you have [`usbipd-win 4.0.0` or higher installed](https://github.com/dorssel/usbipd-win/releases/latest)

1. List all of the USB devices connected to Windows by opening PowerShell in *administrator* mode and entering the following command. Once the devices are listed, select and copy the bus ID of the device you’d like to attach to WSL.

    ```powershell
    usbipd list
    ```

2. Before attaching the USB device, the command `usbipd bind` must be used to share the device, allowing it to be attached to WSL. This requires administrator privileges. Select the bus ID of the device you would like to use in WSL and run the following command. After running the command, verify that the device is shared using the command `usbipd list` again.

    ```powershell
    usbipd bind --busid 4-4
    ```

3. To attach the USB device, run the following command. (You no longer need to use an elevated administrator prompt.) Ensure that a WSL command prompt is open in order to keep the WSL 2 lightweight VM active. Note that as long as the USB device is attached to WSL, it cannot be used by Windows. Once attached to WSL, the USB device can be used by any distribution running as WSL 2. Verify that the device is attached using `usbipd list`. From the WSL prompt, run `lsusb` to verify that the USB device is listed and can be interacted with using Linux tools.

    ```powershell
    usbipd attach --wsl --busid <busid>
    ```

3. Open Ubuntu (or your preferred WSL command line) and list the attached USB devices using the command:

    ```bash
    lsusb
    ```

    You should see the device you just attached and be able to interact with it using normal Linux tools. Depending on your application, you may need to configure udev rules to allow non-root users to access the device.

4. Once you are done using the device in WSL, you can either physically disconnect the USB device or run this command from PowerShell:

    ```powershell
    usbipd detach --busid <busid>
    ```

To learn more about how this works, see the [Windows Command Line Blog](https://devblogs.microsoft.com/commandline/connecting-usb-devices-to-wsl/#how-it-works) and the [usbipd-win repo on GitHub](https://devblogs.microsoft.com/commandline/connecting-usb-devices-to-wsl/#how-it-works).

For a video demonstration, see [WSL 2: Connect USB devices (Tabs vs Spaces show)](https://www.youtube.com/watch?v=I2jOuLU4o8E).
