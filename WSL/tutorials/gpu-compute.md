---
title: GPU accelerated ML training in WSL
description: Learn more about WSL 2 support for NVIDIA CUDA, DirectML, TensorFlow, and PyTorch. Read about Windows Subsystem for Linux support for GPU acceleration when performing Machine Learning training.
keywords: wsl, windows, windows subsystem, gpu compute, gpu acceleration, NVIDIA, CUDA, DirectML, TensorFlow, PyTorch, NVIDIA CUDA preview, GPU driver, NVIDIA Container Toolkit, Docker
ms.date: 09/27/2021
ms.topic: article
---

# GPU accelerated machine learning training in the Windows Subsystem for Linux

Support for GPU compute, the #1 most requested WSL feature, is now available in [Windows 11](https://microsoft.com/software-download/windows11) and [Windows 10, version 21H2](https://microsoft.com/software-download/windows10).

## What is GPU compute?

Leveraging GPU acceleration for compute-intensive tasks is generally referred  to as "GPU compute". GPU computing leverages the GPU (graphics processing unit) to accelerate math heavy workloads and uses its parallel processing to complete the required calculations faster, in many cases, than utilizing only a CPU. This parallelization enables significant processing speed improvements for these math heavy workloads then when running on a CPU. Training machine learning models is a great example in which GPU compute can significantly accelerate the time to complete this computationally expensive task.

## Install and set up

Learn more about WSL 2 support and how to start training machine learning models in the [GPU Accelerated ML Training guide](/windows/ai/directml/gpu-accelerated-training) inside the Windows AI docs. This guide covers:

* Guidance for setting up TensorFlow with DirectML
* Guidance for setting up PyTorch with DirectML
* Guidance for running existing NVIDIA CUDA workflows
