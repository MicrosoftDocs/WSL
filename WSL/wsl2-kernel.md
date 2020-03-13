---
title: Updating the WSL 2 Linux kernel
description: Instructions on how to update your WSL 2 Linux kernel manually
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, wsl.conf, wslconfig
ms.date: 03/12/2020
ms.topic: article
ms.assetid: 7afaeacf-435a-4e58-bff0-a9f0d75b8a51
ms.localizationpriority: high
ms.custom: seodec18
---

# Updating the WSL 2 Linux kernel

To manually update the Linux kernel inside of WSL 2 please follow these steps. 

## Download the Linux kernel update package

Please click on [this link](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi) to download the latest WSL2 Linux kernel update package for AMD64 machines.

> [!NOTE] if you're using an ARM64 machine, please download [this package](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_arm64.msi) instead.

## Install the Linux kernel update package

To install the Linux kernel update package:
	1. Run the update package downloaded in the previous step.
	2. You will be prompted for elevated permissions, select ‘yes’ to approve this installation.
	3. Once the installation is complete, you are ready to begin using WSL2!

## Future plans for updating the WSL2 Linux kernel

For more info on these changes, please read [this blog post](https://devblogs.microsoft.com/commandline/wsl2-will-be-generally-available-in-windows-10-version-2004) on the [Windows Command Line Blog](https://aka.ms/cliblog).
