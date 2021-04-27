---
title: Run Linux GUI apps with WSL 
description: Learn how WSL support running Linux GUI apps.
keywords: wsl, windows, windows subsystem for linux, gui apps 
ms.date: 04/26/2021
ms.topic: article
ms.localizationpriority: medium
---

# Run Linux GUI apps on the Windows Subsystem for Linux

You can now run Linux GUI applications (X11 and Wayland) on Windows in a fully integrated desktop experience thanks to Windows Subsystem for Linux (WSL).

WSLg strives to make Linux GUI applications feel native and natural to use on Windows. From integration into the Start Menu for launch to appearing in the task bar, alt-tab experience to enabling cut/paste across Windows and Linux applications, WSLg enables a seamless desktop experience and workflow leveraging Windows and Linux applications.

## Install support for Linux GUI apps

### Prerequisites

- **[Windows 10 Insider Preview build 21362+](https://insider.windows.com)**

    Support for Linux GUI apps via WSL will become generally available in the upcoming release of Windows. To access to the preview build of Windows and try running Linux GUI apps now, you'll need to join the [Windows Insider Program](https://insider.windows.com/) and run a Windows 10 Insider Preview build from the dev channel.

- **Installed driver for vGPU**

    To run Linux GUI apps, you should first install the preview driver matching your system below. This will enable you to use a virtual GPU (vGPU) so you can benefit from hardware accelerated OpenGL rendering.

  - [**Intel** GPU driver for WSL](https://downloadcenter.intel.com/download/29526)
  - [**AMD** GPU driver for WSL](https://community.amd.com/community/radeon-pro-graphics/blog/2020/06/17/announcing-amd-support-for-gpu-accelerated-machine-learning-training-on-windows-10)
  - [**NVIDIA** GPU driver for WSL](https://developer.nvidia.com/cuda/wsl)

### Fresh install - No prior WSL installation

If you have not already followed the steps to [install WSL](../install-win10.md), you can use the new simplified install command.

1. Open a command prompt with administrator privileges. 

    *Select **Start**, type **PowerShell**, right-click **Windows PowerShell**, and then select **Run as administrator**.*
2. Run this command and reboot your machine when prompted:

    ```powershell
    wsl --install -d Ubuntu
    ```

3. Once your machine has finished rebooting, installation will continue and you will be asked to enter a username and password. This will be your Linux credential for the Ubuntu distribution.

You're now ready to begin using Linux GUI apps on WSL!

### Existing WSL install

If you already have WSL installed on your machine, you can update to the latest version that includes Linux GUI support by running the update command from an elevated command prompt.

1. Select **Start**, type **PowerShell**, right-click **Windows PowerShell**, and then select **Run as administrator**.

2. Enter the WSL update command:

    ```powershell
    wsl --update
    ```

3. You will need to restart WSL for the update to take effect. You can restart WSL by running the shutdown command in PowerShell.

    ```powershell
    wsl --shutdown
    ```

> [!NOTE]
> Linux GUI apps are only supported with WSL 2 and will not work with a Linux distribution configured for WSL 1. Read about [how to change your distribution from WSL 1 to WSL 2](./reference.md#set-your-distribution-version-to-wsl-1-or-wsl-2).

## Install and run Linux GUI apps

You can run the following commands from your Linux terminal to download and install these popular Linux applications. If you are using a different distribution than Ubuntu, it may use a different package manager than apt.

### Update the packages in your distribution

```bash
sudo apt update
```

### Install Gedit

Gedit is the default text editor of the GNOME desktop environment.

```bash
sudo apt install gedit -y
```

### Install GIMP

GIMP is a free and open-source raster graphics editor used for image manipulation and image editing, free-form drawing, transcoding between different image file formats, and more specialized tasks.

```bash
sudo apt install gimp -y
```

### Install Nautilus

Nautilus, also known as GNOME Files, is the file manager for the GNOME desktop. (Similiar to Windows File Explorer).

```bash
sudo apt install nautilus -y
```

### Install VLC

VLC is a free and open source cross-platform multimedia player and framework that plays most multimedia files.

```bash
sudo apt install vlc -y
```

### Install X11 apps

X11 is the Linux windowing system and this is a miscellaneous collection of apps and tools that ship with it, such as the xclock, xcalc calculator, xclipboard for cut and paste, xmark, x11perf, and x11perfcomp tools for benchmarking graphical operations, etc.

```bash
sudo apt install x11-apps -y
```

### Install Google Chrome for Linux

To install the Google Chrome for Linux:

1. Change directories into the temp folder: `cd /tmp`
2. Use wget to download it: `sudo wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb`
3. Get the current stable version: `sudo dpkg -i google-chrome-stable_current_amd64.deb`
4. Fix the package: `sudo apt install --fix-broken -y`
5. Configure the package: `sudo dpkg -i google-chrome-stable_current_amd64.deb`

### Install Microsoft Teams for Linux

To install Microsoft Teams for Linux:

1. Change directories into the temp folder: `cd /tmp`
2. Use curl to download the package: `sudo curl -L -o "./teams.deb" "https://teams.microsoft.com/downloads/desktopurl?env=production&plat=linux&arch=x64&download=true&linuxArchiveType=deb"`
3. Use apt to install it: `sudo apt install ./teams.deb -y`

### Microsoft Edge browser for Linux

To install Microsoft Edge for Linux:

1. Use curl to download the package: `sudo curl https://packages.microsoft.com/repos/edge/pool/main/m/microsoft-edge-dev/microsoft-edge-dev_91.0.852.0-1_amd64.deb -o /tmp/edge.deb`
2. Use apt to install it: `sudo apt install /tmp/edge.deb -y`

Once these applications are installed, you can find them in your **Start** menu under the distribution name. For example: `Ubuntu -> Microsoft Edge`. You can also launch these from your terminal window using the commands:

- `xcalc`, `xclock`, `xeyes`
- `gimp`
- `gedit ~/.bashrc`
- `nautilus`
- `vlc`
- `google-chrome`
- `teams`
- `microsoft-edge`
