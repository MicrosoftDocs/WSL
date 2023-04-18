---
title: How to enable systemd in WSL2
description: Learn how to how to enable systemd in WSL2, ...
ms.date: 048/18/2023
ms.topic: article
---

# How to enable systemd in WSL2

WSL now supports systemd, an init system and service manager used by many popular Linux distributions such as Ubuntu, Debian, and more. Enabling systemd means that WSL will be even more similar to using your favorite Linux distributions on a bare metal machine and will let you use software that depends on systemd support.

In this tutorial, we will cover:

- [How to enable systemd in WSL2]
- 
- 

## Enable systemd in the configuration settings of your wsl.conf file

<!-- wsl.conf is on a per-distro basis.. can this be enabled globally in .wslconfig, or is that a bad idea? -->
You can enable systemd in the `wsl.conf` configuration file associated with any Linux distributions that you install using WSL2.

1. You will need WSL version 0.67.6+ in order to enable systemd. Check your WSL version using teh command: `wsl --version`. If you need to update, you can download the [latest version of WSL in the Microsoft Store](https://aka.ms/wslstorepage).

2. To enable systemd, open your `wsl.conf` file in a text editor using `sudo` for admin permissions and add these lines to the `/etc/wsl.conf`:

    ```bash
    [boot]
    systemd=true
    ```

3. You will then need to close your WSL distribution using `wsl.exe --shutdown` from PowerShell to restart your WSL instances. 

Once your distribution restarts, systemd should be running. You can confirm using the command: `systemctl list-unit-files --type=service`, which will show the status of your services.

## What is systemd and how does it work in a WSL context?

According to [systemd.io](https://systemd.io): "systemd is a suite of basic building blocks for a Linux system. 
It provides a system and service manager that runs as PID 1 and starts the rest of the system."

Primarily an init system and service manager, systemd includes features like on-demand starting of daemons, mount and automount point maintenance, snapshot support, and processes tracking using Linux control groups.

Supporting systemd required changes to the WSL architecture. As systemd requires PID 1, the WSL init process started within the Linux distribution becomes a child process of the systemd. Because the WSL init process is responsible for providing the infrastructure for communication between the Linux and Windows components, changing this hierarchy required rethinking some of the assumptions made with the WSL init process. Additional modifications had to be made to ensure a clean shutdown (as that shutdown is controlled by systemd now) and to have compatibility with [WSLg](./gui-apps.md). It is also important to note that with these change, systemd services will NOT keep your WSL instance alive. Your WSL instance will stay alive in the same way it did previous to this update, which you can read more about in this [Background Task Support blog post from 2017](https://devblogs.microsoft.com/commandline/background-task-support-in-wsl/).

## Linux apps enabled by systemd support

A few examples of Linux applications that depend on systemd are:

- [snap](): A handy binary that allows you to install and manage software inside Ubuntu. Try running the command: `snap install spotify` or `snap install postman`.
- [microk8s](): Get Kubernetes running locally on your system quickly. Try the getting started tutorial.
- [systemctl](): A tool that’s part of systemd, interact with services on your Linux machine. Try systemctl list-units --type=service to see which services are available and their status.

## Related tutorials
