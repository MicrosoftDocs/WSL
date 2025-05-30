---
title: Run Linux GUI apps with WSL 
description: Learn how WSL support running Linux GUI apps. 
ms.date: 01/04/2024
ms.topic: article
---

# Run Linux GUI apps on the Windows Subsystem for Linux

Windows Subsystem for Linux (WSL) now supports running Linux GUI applications (X11 and Wayland) on Windows in a fully integrated desktop experience.

WSL 2 enables Linux GUI applications to feel native and natural to use on Windows.

- Launch Linux apps from the Windows Start menu
- Pin Linux apps to the Windows task bar
- Use alt-tab to switch between Linux and Windows apps
- Cut + Paste across Windows and Linux apps

You can now integrate both Windows and Linux applications into your workflow for a seamless desktop experience.

![Screenshot of Linux and Windows apps open on a desktop](../media/wsl-gui-screenshot.png)

## Install support for Linux GUI apps

### Prerequisites

- You will need to be on **Windows 10 Build 19044+** or **Windows 11** to access this feature.

- **Installed driver for vGPU**

    To run Linux GUI apps, you should first install the driver matching your system below. This will enable you to use a virtual GPU (vGPU) so you can benefit from hardware accelerated OpenGL rendering.

  - [**Intel** GPU driver](https://www.intel.com/content/www/us/en/download/19344/intel-graphics-windows-dch-drivers.html)
  - [**AMD** GPU driver](https://www.amd.com/en/support)
  - [**NVIDIA** GPU driver](https://www.nvidia.com/Download/index.aspx?lang=en-us)

### Fresh install - No prior WSL installation

You can now install everything you need to run Windows Subsystem for Linux (WSL) by entering this command in an administrator PowerShell or Windows Command Prompt and then restarting your machine.

```powershell
wsl --install
```

Once your machine has finished rebooting, installation will continue and you will be asked to enter a username and password. This will be your Linux credential for the Ubuntu distribution.

You're now ready to begin using Linux GUI apps on WSL!

For more info check [install WSL](../install.md).

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
> Linux GUI apps are only supported with WSL 2 and will not work with a Linux distribution configured for WSL 1. Read about [how to change your distribution from WSL 1 to WSL 2](../basic-commands.md#set-wsl-version-to-1-or-2).

## Run Linux GUI apps

You can run the following commands from your Linux terminal to download and install these popular Linux applications. If you are using a different distribution than Ubuntu, it may use a different package manager than apt. Once the Linux application is installed, you can find it in your **Start** menu under the distribution name. For example: `Ubuntu -> Microsoft Edge`.

> [!NOTE]
> Support for GUI apps on WSL does not provide a full desktop experience. It relies on Windows desktop, so installing desktop-focused tools or apps may not be supported. To request additional support, you can file an issue in the [WSLg repo on GitHub](https://github.com/microsoft/wslg/issues).

### Update the packages in your distribution

```bash
sudo apt update
```

### Install Gnome Text Editor

Gnome Text Editor is the default text editor of the GNOME desktop environment.

```bash
sudo apt install gnome-text-editor -y
```

To launch your bashrc file in the editor, enter: `gnome-text-editor ~/.bashrc`

> [!NOTE]
> [GNOME Text Editor](https://en.wikipedia.org/wiki/GNOME_Text_Editor) replaces gedit as GNOME/Ubuntu's default text editor in Ubuntu 22.10. If you're running an older version of Ubuntu and want to use [gedit](https://en.wikipedia.org/wiki/Gedit), the previous default text editor, use `sudo apt install gedit -y`.

### Install GIMP

GIMP is a free and open-source raster graphics editor used for image manipulation and image editing, free-form drawing, transcoding between different image file formats, and more specialized tasks.

```bash
sudo apt install gimp -y
```

To launch, enter: `gimp`

### Install Nautilus

Nautilus, also known as GNOME Files, is the file manager for the GNOME desktop. (Similar to Windows File Explorer).

```bash
sudo apt install nautilus -y
```

To launch, enter: `nautilus`

### Install VLC

VLC is a free and open source cross-platform multimedia player and framework that plays most multimedia files.

```bash
sudo apt install vlc -y
```

To launch, enter: `vlc`

### Install X11 apps

X11 is the Linux windowing system and this is a miscellaneous collection of apps and tools that ship with it, such as the xclock, xcalc calculator, xclipboard for cut and paste, xev for event testing, etc. See the [x.org docs](https://www.x.org/wiki/UserDocumentation/GettingStarted/) for more info.

```bash
sudo apt install x11-apps -y
```

To launch, enter the name of the tool you would like to use. For example:

- `xcalc`, `xclock`, `xeyes`

### Install Google Chrome for Linux

To install the Google Chrome for Linux:

1. Change directories into the temp folder: `cd /tmp`
2. Use wget to download it: `wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb`
3. Install the package: `sudo apt install --fix-missing ./google-chrome-stable_current_amd64.deb`

*The `--fix-missing` option is used to fix missing dependencies that may arise during the installation process. The `./` in the command specifies the current directory where the .deb file is located. If the .deb file is located in a different directory, you will need to specify the path to the file in the command.

To launch, enter: `google-chrome`

### Install Microsoft Edge browser for Linux

Find information on how to [install the Microsoft Edge browser for Linux using the command line on the Edge Insider site](https://www.microsoftedgeinsider.com/download/?platform=linux-deb). Select **Get instructions** under the Command line installation section of the page.

To launch, enter: `microsoft-edge`

## Troubleshooting

If you have any problem starting GUI applications please check this guide first: [Diagnosing "cannot open display" type issues with WSLg](https://github.com/microsoft/wslg/wiki/Diagnosing-%22cannot-open-display%22-type-issues-with-WSLg)
