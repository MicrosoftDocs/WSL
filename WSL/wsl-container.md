---
title: WSL container
description: An overview of what the WSL container feature is, and how to use it to run Linux container workflows on Windows
keywords: BashOnWindows, bash, wsl, windows, windows subsystem, distro, custom, Linux, container
ms.date: 05/01/2026
ms.topic: how-to
ms.custom: sfi-image-nochange
---

# WSL container

WSL container is a new feature coming to WSL with the goal of making it easier to use Linux containers on Windows. It has two major components: a CLI called `wslc.exe` to build, run and interact with Linux containers and a WSL container API allowing Windows app developers to use Linux containers as part of their app logic. 

Currently WSL container is in development, and since WSL is open sourced you can view the progress at [the WSL GitHub repo microsoft/wsl](https://github.com/microsoft/wsl). To learn more when this feature is fully released please stay tuned to the [Windows command line blog](https://aka.ms/cliblog)!

## WSL container CLI

In the next WSL update, `wslc.exe` will be an included command as part of the regular update. Its goal is to have a familiar CLI interface, allowing you to easily build, run and interact with Linux containers. 

See some of the example commands below:

```powershell
# Run a container
wslc run --rm -it ubuntu:latest bash -c "echo Hello world from WSL container!"
# List available images
wslc image ls
# Run a web server
wslc run -it --rm -d -p 8080:80 --name web nginx
# Get its content
curl localhost:8080
# List the container
wslc container ps
# Stop the container
wslc container stop web
```

## WSL container API

Windows applications can make use of Linux containers as well! A nuget package will be available allowing you to programmatically pull, run, and interact with Linux containers. Including key interactions like stdin and stdout, file mounts, networking mounts, GPU access and more. 