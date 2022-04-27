---
title: Connect USB devices
description: Learn how to connect a USB device to your WSL 2 Linux distribution using usbipd-win.
ms.date: 11/09/2021
ms.topic: article
---

# Connect USB devices

This guide will walk through the steps necessary to connect a USB device to a Linux distribution running on WSL 2 using the USB/IP open-source project, [usbipd-win](https://github.com/dorssel/usbipd-win).

Setting up the USB/IP project on your Windows machine will enable common developer USB scenarios like flashing an Arduino or accessing a smartcard reader.

## Prerequisites

- Running Windows 11 (Build 22000 or later). *(Windows 10 support is possible, see note below).*
- A machine with an x64/x86 processor is required. (Arm64 is currently not supported with usbipd-win).
- Linux distribution installed and [set to WSL 2](./basic-commands.md#set-wsl-version-to-1-or-2).
- Running [Linux kernel 5.10.60.1 or later](./kernel-release-notes.md).

> [!NOTE]
> To check your Windows version and build number, select **Windows logo key + R**, type **winver**, select **OK**. You can update to the latest Windows version by selecting **Start** > **Settings** > **Windows Update** > **[Check for updates](ms-settings:windowsupdate)**.
> To check your Linux kernel version, open your Linux distribution and enter the command: `uname -a`. To manually update to the latest kernel, open PowerShell and enter the command: 'wsl --update`.

> [!IMPORTANT]
> Windows 11 is recommended for connecting USB devices to a Linux distribution running on WSL 2. However, Windows 10 can be used to connect USB devices by building your own USBIP enabled WSL 2 kernel following the [instructions in the USBIPD-WIN project repo](https://github.com/dorssel/usbipd-win/wiki/WSL-support).

## Install the USBIPD-WIN project

Support for connecting USB devices is not natively available in WSL, so you will need to install the open-source usbipd-win project.

1. Go to the [latest release page for the usbipd-win project](https://github.com/dorssel/usbipd-win/releases).
2. Select the .msi file, which will download the installer. (You may get a warning asking you to confirm that you trust this download).
3. Run the downloaded usbipd-win_x.msi installer file.

> [!NOTE]
> Alternatively, you can also install the usbipd-win project using [Windows Package Manager](/windows/package-manager/winget/) (winget). If you have already installed winget, just use the command: `winget install --interactive --exact dorssel.usbipd-win` to install usbipd-win. If you leave out --interactive, winget may immediately restart your computer if that is required to install the drivers.

This will install:

- A service called `usbipd` (display name: USBIP Device Host). You can check the status of this service using the Services app from Windows.
- A command line tool `usbipd`. The location of this tool will be added to the PATH environment variable.
- A firewall rule called `usbipd` to allow all local subnets to connect to the service. You can modify this firewall rule to fine tune access control.

## Install the USBIP tools and hardware database in Linux

Once the USB/IP project has completed installing, you will need to install the user space tools and a database of USB hardware identifiers. These instructions are for Ubuntu — [other distributions may require a different usbip client package](https://github.com/dorssel/usbipd-win/wiki/WSL-support#usbip-client-tools).

On Ubuntu, run this command:

```bash
sudo apt install linux-tools-5.4.0-77-generic hwdata
sudo update-alternatives --install /usr/local/bin/usbip usbip /usr/lib/linux-tools/5.4.0-77-generic/usbip 20
```

At this point a service is running on Windows to share USB devices, and the necessary tools are installed in WSL to attach to shared devices.

## Attach a USB device

Before attaching your USB device, ensure that a WSL command line is open.  This will keep the WSL 2 lightweight VM active.

1. List all of the USB devices connected to Windows by opening PowerShell in *administrator* mode and entering the command:

    ```powershell
    usbipd wsl list
    ```

2. Select the bus ID of the device you’d like to attach to WSL and run this command. You’ll be prompted by WSL for a password to run a sudo command. The Linux distribution to be attached must be your default distribution. (See the [Basic comands for WSL](./basic-commands.md#set-default-linux-distribution) doc to change your default distribution).

    ```powershell
    usbipd wsl attach --busid <busid>
    ```

3. Open Ubuntu (or your preferred WSL command line) and list the attached USB devices using the command:

    ```bash
    lsusb
    ```

    You should see the device you just attached and be able to interact with it using normal Linux tools. Depending on your application, you may need to configure udev rules to allow non-root users to access the device.

4. Once you are done using the device in WSL, you can either physically disconnect the USB device or run this command from PowerShell in *administrator* mode:

    ```powershell
    usbipd wsl detach --busid <busid>
    ```

To learn more about how this works, see the [Windows Command Line Blog](https://devblogs.microsoft.com/commandline/connecting-usb-devices-to-wsl/#how-it-works) and the [usbipd-win repo on GitHub](https://devblogs.microsoft.com/commandline/connecting-usb-devices-to-wsl/#how-it-works).

For a video demonstration, see [WSL 2: Connect USB devices (Tabs vs Spaces show)](https://www.youtube.com/watch?v=I2jOuLU4o8E).
