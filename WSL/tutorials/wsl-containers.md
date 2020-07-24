---
title: Get started using Docker containers with Windows Subsystem for Linux
description: Learn how to set up Docker containers on the Windows Subsystem for Linux.
keywords: wsl, windows, windowssubsystem, windows 10, docker, containers
ms.date: 07/07/2020
ms.topic: article
ms.localizationpriority: medium
---

# Get started with Docker containers on Windows Subsystem for Linux

This step-by-step guide will help you get started setting up and working with Docker containers on Windows Subsystem for Linux (WSL).

## Prerequisites

- Running Windows 10, [updated to version 2004](ms-settings:windowsupdate), **Build 19041** or higher.
- [WSL enabled, installed, and updated to WSL 2](https://docs.microsoft.com/windows/wsl/install-win10).
- [Linux distribution installed](https://docs.microsoft.com/windows/wsl/install-win10#install-your-linux-distribution-of-choice) (Ubuntu 18.04 for our examples).
- Ensure your Ubuntu 18.04 distribution is [running in WSL 2 mode](https://docs.microsoft.com/windows/wsl/install-win10#set-your-distribution-version-to-wsl-1-or-wsl-2). (WSL can run distributions in both v1 or v2 mode.) You can check this by opening PowerShell and entering: `wsl -l -v`
- [Install Visual Studio Code](https://code.visualstudio.com/download).

## Overview of Docker containers

**Docker** is a tool used to create, deploy, and run applications using containers. Containers enable developers to package an app with all of the parts it needs (libraries, frameworks, dependencies, etc) and ship it all out as one package. Using a container ensures that the app will run the same regardless of any customized settings or previously installed libraries on the computer running it that could differ from the machine that was used to write and test the app's code. This permits developers to focus on writing code without worrying about the system that code will be run on.

Docker containers are similar to virtual machines, but don't create an entire virtual operating system. Instead, Docker enables the app to use the same Linux kernel as the system that it's running on. This allows the app package to only require parts not already on the host computer, reducing the package size and improving performance.

Continuous availability, using Docker containers with tools like [Kubernetes](https://docs.microsoft.com/azure/aks/), is another reason for the popularity of containers. This enables multiple versions of your app container to be created at different times. Rather than needing to take down an entire system for updates or maintenance, each container (and it's specific microservices) can be replaced on the fly. You can prepare a new container with all of your updates, set up the container for production, and just point to the new container once it's ready. You can also archive different versions of your app using containers and keep them running as a safety fallback if needed.

## Install Docker Desktop

Install [Docker Desktop Stable 2.3.0.2](https://docs.docker.com/docker-for-windows/wsl/#download).

## Additional resources

- [How does the Docker architecture work with WSL](https://code.visualstudio.com/blogs/2020/03/02/docker-in-wsl2#_how-it-works)
- []()
- []()
- [Hanselminutes Podcast: Making Docker lovely for Developers with Simon Ferquel](https://hanselminutes.com/736/making-docker-lovely-for-developers-with-simon-ferquel)
- []()