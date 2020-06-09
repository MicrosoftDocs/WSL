---
title: GPU accelerated Machine Learning training in the Windows Subsystem for Linux
description: Learn how to set up Git for version control on the Windows Subsystem for Linux.
keywords: wsl, windows, windowssubsystem, gnu, linux, bash, git, github, version control
ms.date: 06/04/2020
ms.topic: article
ms.localizationpriority: medium
---

# GPU accelerated Machine Learning training in the Windows Subsystem for Linux

Support for GPU compute, the #1 most requested WSL feature, is now available for preview via the Windows Insider program.

## What is GPU Compute?

GPU computing is the use of a GPU (graphics processing unit) as a co-processor to accelerate CPUs (central processing units). GPUs typically handle only computation for graphics. GPU computing instead uses those powerful video cards or graphics chips to establish a parallel processing with the CPU to analyze data as if it were an image. The process migrates data into graphical form and uses the GPU to offload some of the compute-intensive and time consuming portions of the code, while the rest of the code continues to run on the CPU. This typically creates significant processing speed improvements.

## Support for Machine Learning tools like PyTorch and TensorFlow

Training machine learning models is a time-consuming computational task even when using small datasets. You can now experience the familiarity of using Windows for personal and productivity tools side by side with all the tools you use for these heavy machine learning tasks on native Linux. Thanks to a partnership with NVIDIA, WSL will now support these GPU compute tools, libraries, frameworks, and workflows.

### NVIDIA CUDA

To speed-up training, many machine learning tools utilize [CUDA compute platform from NVIDIA](https://developer.nvidia.com/about-cuda) as the default backend for hardware acceleration, including PyTorch and TensorFlow.

### NVIDIA Container Toolkit

The [NVIDIA Container Toolkit](https://github.com/NVIDIA/nvidia-docker) allows users to build and run GPU accelerated Docker containers.

### DirectML

Windows 10, version 1903, introduced [Direct Machine Learning (DirectML)](https://docs.microsoft.com/windows/win32/direct3d12/dml). DirectML enables hardware accelerated training across the breadth of Windows hardware. It is a low-level API for machine learning with a familiar (native C++, nano-COM) programming interface and enables accelerated inference for machine learning models on any DirectX 12 based GPU. DirectML support has now been extended to WSL with AMD, Intel, and NVIDIA all releasing preview drivers that enable the DirectML TensorFlow package to run both directly on Windows and inside WSL. Read more on the [DirectX Developer blog](https://devblogs.microsoft.com/directx/directx-heart-linux/).

## Sign up for Windows Insider

1. Register for the [Windows Insider program](https://insider.windows.com/).

2. Install the latest build from the Fast ring (Build 20145 or higher) as these newer builds are the only ones that currently supports the GPU Compute functionality.

3. Install the preview driver for your GPU’s hardware vendor:
    - [AMD Driver](.)
    - [Intel Driver](.)
    - [NVIDIA Driver](.)

## Prerequisites

1. Ensure the latest kernel for WSL 2 is installed by hitting “Check for Updates” in Windows Update.

2. Ensure that your Linux distribution is set to use WSL 2 by opening PowerShell or Windows Command Prompt and entering the command `wsl -l -v`, this will display each Linux distribution you have installed and whether it is set to use WSL 1 or WSL 2. To [update to WSL 2](../install-win10.md#set-your-distribution-version-to-wsl-1-or-wsl-2), use the command: `wsl --set-version <distribution name> 2`

## Enable DirectML preview

1. Download [DirectML] and extract the folder to a known location. (We should suggest a place here as an example.)

2. Install the [tensorflow-directml package]() via pip into your Python environment of choice, using the following command:

    ```bash
    pip install ...
    ```

3. Set an environment variable to the location where you extracted DirectML, using the command:

    ```bash
    $env:TF_DIRECTML_PATH=<location_of_directml>
    ```

4. Check out the [TensorFlow tutorials](https://www.tensorflow.org/tutorials) or the [PyTorch SqueezeNet sample](https://pytorch.org/hub/pytorch_vision_squeezenet/) to get started training!

### Install NVIDIA CUDA preview

1. Install [NVIDIA’s preview driver for WSL](.)

2. Start using your Linux workflows with NVIDIA Docker or by installing PyTorch or TensorFlow natively inside WSL to start training. **We should show how to install PyTorch and TensorFlow.*

## Additional resources

- [CUDA on Windows Subsystem for Linux - Public Preview](https://developer.nvidia.com/cuda/wsl)

- [DirectML Samples](https://github.com/Microsoft/DirectML-Samples)
