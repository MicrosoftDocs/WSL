---
title: GPU accelerated ML training in WSL
description: Learn how to setup the Windows Subsystem for Linux with NVIDIA CUDA, TensorFlow-DirectML, and PyTorch-DirectML. Read about using GPU acceleration with WSL to support machine learning training scenarios.
ms.date: 05/03/2022
ms.topic: article
---

# Get started with GPU acceleration for ML in WSL

Machine learning (ML) is becoming a key part of many development workflows. Whether you're a data scientist, ML engineer, or starting your learning journey with ML the Windows Subsystem for Linux (WSL) offers a great environment to run the most common and popular GPU accelerated ML tools.

There are lots of different ways to set up these tools. For example, [NVIDIA CUDA in WSL](https://developer.nvidia.com/cuda/wsl), [TensorFlow-DirectML](https://pypi.org/project/tensorflow-directml/) and [PyTorch-DirectML](https://pypi.org/project/pytorch-directml/) all offer different ways you can use your GPU for ML with WSL. To learn more about the reasons for choosing one versus another, see [GPU accelerated ML training](/windows/ai/directml/gpu-accelerated-training).

This guide will show how to set up:

* NVIDIA CUDA if you have an NVIDIA graphics card and run a sample ML framework container
* TensorFlow-DirectML and PyTorch-DirectML on your AMD, Intel, or NVIDIA graphics card

## Prerequisites

* Ensure you are running [Windows 11](https://microsoft.com/software-download/windows11) or [Windows 10, version 21H2](https://microsoft.com/software-download/windows10) or higher.
* [Install WSL and set up a username and password for your Linux distribution](/windows/wsl/install).

## Setting up NVIDIA CUDA with Docker

1. [Download and install the latest driver for your NVIDIA GPU](https://www.nvidia.com/Download/index.aspx)
2. Install [Docker Desktop](/windows/wsl/tutorials/wsl-containers#install-docker-desktop) or install the Docker engine directly in WSL by running the following command

    ```bash
    curl https://get.docker.com | sh
    ````
    
    ```bash
    sudo service docker start
    ````

3. If you installed the Docker engine directly then [install the NVIDIA Container Toolkit](https://docs.nvidia.com/cuda/wsl-user-guide/index.html#ch04-sub02-install-nvidia-docker) following the steps below.  
    
    Set up the stable repository for the NVIDIA Container Toolkit by running the following commands:

    ```bash
    distribution=$(. /etc/os-release;echo $ID$VERSION_ID)
    ```
    
    ```bash
    curl -s -L https://nvidia.github.io/nvidia-docker/gpgkey | sudo gpg --dearmor -o /usr/share/keyrings/nvidia-docker-keyring.gpg
    ```
    
    ```bash
    curl -s -L https://nvidia.github.io/nvidia-docker/$distribution/nvidia-docker.list | sed 's#deb https://#deb [signed-by=/usr/share/keyrings/nvidia-docker-keyring.gpg] https://#g' | sudo tee /etc/apt/sources.list.d/nvidia-docker.list
    ```

    Install the NVIDIA runtime packages and dependencies by running the commands:

    ```bash
    sudo apt-get update
    ```
    
    ```bash
    sudo apt-get install -y nvidia-docker2
    ```

4. Run a machine learning framework container and sample.
    
    To run a machine learning framework container and start using your GPU with this NVIDIA NGC TensorFlow container, enter the command:
        
    ````bash
    docker run --gpus all -it --shm-size=1g --ulimit memlock=-1 --ulimit stack=67108864 nvcr.io/nvidia/tensorflow:20.03-tf2-py3
    ````

    ![TensorFlow with CUDA running inside a Docker container](https://user-images.githubusercontent.com/2146704/165866792-0fc1b9f6-a7be-49e2-8eb4-919a9b13a07c.png)

    You can run a pre-trained model sample that is built into this container by running the commands:

    ```bash
    cd nvidia-examples/cnn/
    ```
    
    ```bash
    python resnet.py --batch_size=64
    ```

    ![TensorFlow sample model training within Docker container](https://user-images.githubusercontent.com/2146704/165867329-fae2f8ec-e86d-412e-9e2c-dcfec0ec2429.gif)


Additional ways to get setup and utilize NVIDIA CUDA can be found in the [NVIDIA CUDA on WSL User Guide](https://docs.nvidia.com/cuda/wsl-user-guide/index.html#getting-started-with-cuda-on-wsl).

## Setting up TensorFlow-DirectML or PyTorch-DirectML

1. Download and install the latest driver from your GPU vendors website: [AMD](https://www.amd.com/en/support), [Intel](https://www.intel.com/content/www/us/en/download/19344/intel-graphics-windows-dch-drivers.html), or [NVIDIA](https://www.nvidia.com/Download/index.aspx).

2. Setup a Python environment.

    We recommend setting up a virtual Python environment. There are many tools you can use to setup a virtual Python environment — for these instructions, we'll use [Anaconda's Miniconda](https://docs.conda.io/en/latest/miniconda.html).

    ```bash
    wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh
    ```
    
    ```bash
    bash Miniconda3-latest-Linux-x86_64.sh
    ```
    
    ```bash
    conda create --name directml python=3.7 -y
    ```
    
    ```bash
    conda activate directml
    ```

3. Install the machine learning framework backed by DirectML of your choice.

    TensorFlow-DirectML:
    
    ```bash
    pip install tensorflow-directml
    ```

    PyTorch-DirectML:

    ```bash
    sudo apt install libblas3 libomp5 liblapack3
    ```
    
    ```bash
    pip install pytorch-directml
    ```

4. Run a quick addition sample in an interactive Python session for [TensorFlow-DirectML](/windows/ai/directml/gpu-tensorflow-wsl#install-the-tensorflow-with-directml-package) or [PyTorch-DirectML](/windows/ai/directml/gpu-pytorch-wsl#install-the-pytorch-with-directml-package) to make sure everything is working.

If you have questions or run into issues, visit the [DirectML repo on GitHub](https://github.com/microsoft/DirectML#feedback).

## Multiple GPUs

If you have multiple GPUs on your machine you can also access them inside of WSL. However, you will only be able to access one at a time. To choose a specific GPU please set the environment variable below to the name of your GPU as it appears in device manager:

```bash
export MESA_D3D12_DEFAULT_ADAPTER_NAME="<NameFromDeviceManager>"
```

This will do a string match, so if you set it to "NVIDIA" it will match the first GPU that starts with "NVIDIA".

## Additional Resources

* [Guidance for setting up NVIDIA CUDA in WSL](https://docs.nvidia.com/cuda/wsl-user-guide/index.html)
* [Guidance for setting up TensorFlow with DirectML in WSL](/windows/ai/directml/gpu-tensorflow-wsl)
* [TensorFlow with DirectML Samples](https://github.com/microsoft/DirectML/tree/master/TensorFlow)
* [Guidance for setting up PyTorch with DirectML in WSL](/windows/ai/directml/gpu-pytorch-wsl)
* [PyTorch with DirectML Samples](https://github.com/microsoft/DirectML/tree/master/PyTorch)
