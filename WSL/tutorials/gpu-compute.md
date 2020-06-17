---
title: GPU accelerated Machine Learning training in the Windows Subsystem for Linux
description: Learn more about WSL 2 support for NVIDIA CUDA, DirectML, Tensorflow, and PyTorch.
keywords: wsl, windows, windows subsystem, gpu compute, gpu acceleration, NVIDIA, CUDA, DirectML, Tensorflow, PyTorch, NVIDIA CUDA preview, GPU driver, NVIDIA Container Toolkit, Docker
ms.date: 06/17/2020
ms.topic: article
ms.localizationpriority: medium
---

# GPU accelerated machine learning training in the Windows Subsystem for Linux

Support for GPU compute, the #1 most requested WSL feature, is now available for preview via the Windows Insider program. [Read the blog post](https://blogs.windows.com/windowsdeveloper/?p=55781).

## What is GPU compute?

Leveraging GPU acceleration for compute-intensive tasks is generally referred  to as "GPU compute". GPU computing leverages the GPU (graphics processing unit) to accelerate math heavy workloads and uses its parallel processing to complete the required calculations faster, in many cases, than utilizing only a CPU. This parallelization enables significant processing speed improvements for these math heavy workloads then when running on a CPU. Training machine learning models is a great example in which GPU compute can significantly accelerate the time to complete this computationally expensive task.

## Install and set up

Learn more about WSL 2 support and how to start training machine learning models in the [GPU Accelerated Training guide](https://docs.microsoft.com/windows/win32/direct3d12/gpu-accelerated-training) inside the DirectML docs. This guide covers:

* Guidance for beginners or students to set up TensorFlow with DirectML
* Guidance for professionals to start running their exisiting CUDA ML workflows
