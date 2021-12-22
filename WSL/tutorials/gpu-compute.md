---
title: GPU accelerated ML training in WSL
description: Learn more about WSL 2 support for NVIDIA CUDA, DirectML, Tensorflow, and PyTorch. Read about Windows Subsystem for Linux support for GPU acceleration when performing Machine Learning training.
keywords: wsl, windows, windows subsystem, gpu compute, gpu acceleration, NVIDIA, CUDA, DirectML, Tensorflow, PyTorch, NVIDIA CUDA preview, GPU driver, NVIDIA Container Toolkit, Docker
ms.date: 09/27/2021
ms.topic: article
---

# GPU accelerated machine learning training in the Windows Subsystem for Linux

Support for GPU compute, the #1 most requested WSL feature, is now available for preview via the Windows Insider program. [Read the blog post](https://blogs.windows.com/windowsdeveloper/?p=55781).

> [!NOTE]
> You need to be using a Windows build 20150 or higher to use this feature. You can join the [Windows Insiders Program](https://insider.windows.com/) to get the latest preview builds.

## What is GPU compute?

Leveraging GPU acceleration for compute-intensive tasks is generally referred  to as "GPU compute". GPU computing leverages the GPU (graphics processing unit) to accelerate math heavy workloads and uses its parallel processing to complete the required calculations faster, in many cases, than utilizing only a CPU. This parallelization enables significant processing speed improvements for these math heavy workloads then when running on a CPU. Training machine learning models is a great example in which GPU compute can significantly accelerate the time to complete this computationally expensive task.

## Install and set up

Learn more about WSL 2 support and how to start training machine learning models in the [GPU Accelerated Training guide](/windows/win32/direct3d12/gpu-accelerated-training) inside the DirectML docs. This guide covers:

* Guidance for beginners or students to set up TensorFlow with DirectML
* Guidance for professionals to start running their existing CUDA ML workflows
