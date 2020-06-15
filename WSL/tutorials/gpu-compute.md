---
title: GPU accelerated Machine Learning training in the Windows Subsystem for Linux
description: Learn more about WSL 2 support for NVIDIA CUDA, DirectML, Tensorflow, and PyTorch.
keywords: wsl, windows, windowssubsystem, gpu compute, gpu acceleratin, NVIDIA, CUDA, DirectML, Tensorflow, PyTorch, NVIDIA CUDA preview, GPU driver, NVIDIA Container Toolkit, Docker
ms.date: 06/17/2020
ms.topic: article
ms.localizationpriority: medium
---

# GPU accelerated Machine Learning training in the Windows Subsystem for Linux

Support for GPU compute, the #1 most requested WSL feature, is now available for preview via the Windows Insider program. [Learn more.](https://docs.microsoft.com/windows/win32/direct3d12/gpu-accelerated-training)

## What is GPU Compute?

GPU acceleration is also sometimes referred to as "GPU Compute." GPU computing is the use of a GPU (graphics processing unit) as a co-processor to accelerate CPUs (central processing units). GPUs typically handle only computation for graphics. GPU computing instead uses those powerful video cards or graphics chips to establish a parallel processing with the CPU to analyze data as if it were an image. The process migrates data into graphical form and uses the GPU to offload some of the compute-intensive and time consuming portions of the code, while the rest of the code continues to run on the CPU. This typically creates significant processing speed improvements. Training machine learning models is a great example in which GPU compute can significantly accelerate the time to complete a computational task.

## Install and set up

Learn more about WSL 2 support and how to start training machine learning models in the [GPU Accelerated Training guide](https://docs.microsoft.com/windows/win32/direct3d12/gpu-accelerated-training) inside the Direct Machine Learning docs. This guide covers:

* Enabling the NVIDIA CUDA preview
* Installing the correct GPU driver, which might include:
  * AMD Radeon™ RX series and Radeon™ VII graphics
  * AMD Radeon™ Pro series graphics
  * AMD Ryzen™ and Ryzen™ PRO Processors with Radeon™ Vega graphics
  * AMD Ryzen™ and Ryzen™ PRO Mobile Processors with Radeon™ Vega graphics
  * Intel DirectML preview driver
  * NVIDIA CUDA-enabled driver
* Guidance for beginners or students to set up TensorFlow with a DirectML backend
* Guidance for professionals to start using your existing Linux workflows through NVIDIA Docker or by installing PyTorch or TensorFlow
* Support for NVIDIA Container Toolkit
