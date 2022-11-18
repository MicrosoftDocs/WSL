---
title: Get started with Linux using WSL
description: Learn some basics for working with Linux and a Bash command line using WSL.
ms.date: 08/05/2022
ms.topic: article
---

# Getting started with Linux and Bash

This tutorial will help those new to Linux to get started installing and updating packages using the Ubuntu distribution of Linux that is installed by default using WSL, as well as using some basic commands with the Bash command line.

## Installing and Updating Software

You can install and update software programs directly from the command line using the preferred package manager for the distribution you are running.

In Ubuntu, for example, first update the list of software available by running ‘sudo apt update’. Then, you can directly get software by using the ‘sudo apt-get install’ command followed by the name of the program you wish to install:  

```bash
sudo apt-get install <app_name> 
```

To update programs that have already been installed, you can run:

```bash
sudo apt update && sudo apt upgrade
```
![upgrade_and_update](https://user-images.githubusercontent.com/98557455/183468063-35b00e76-d11a-4260-aa3c-9f8e0dab2e47.gif)

> [!TIP]
> Different distributions of Linux often have different package managers and will require using an install command specific to the associated package manager. For example, the main package manager for Arch Linux is called [pacman](https://wiki.archlinux.org/title/pacman) and the install command would be `sudo pacman -S <app_name>`. The main package manager for OpenSuse is called [Zypper](https://doc.opensuse.org/documentation/leap/archive/42.2/reference/html/book.opensuse.reference/cha.sw_cl.html#sec.zypper) and the install command would be `sudo zypper install <app_name>`. The main package manager for Alpine is called [apk](https://wiki.alpinelinux.org/wiki/Package_management) and the install command would be `sudo apk add <app_name>`. The two main package managers for Red Hat distributions, like CentOS, are [YUM and RPM](https://www.redhat.com/sysadmin/how-manage-packages) and an install command could be `sudo yum install <app_name>` or `sudo rpo -i <app_name>`. Refer to the documentation of the distribution you are working with to find out what tools are available for you to install and update software.

## Working with files and directories

To view the path of the directory you are currently in, use the ‘pwd’ command:

```bash
pwd
```

To create a new directory, use the ‘mkdir’ command followed by the name of the directory you want to create: 

```bash
mkdir hello_world 
```
 

To change directories, use the ‘cd’ command followed by the name of the directory you want to navigate to:

```bash
cd hello_world 
```
 
To see the contents within the directory you are currently in, type ‘ls’ into the command line: 

```bash
ls
```
![directory-and-file-commands1](https://user-images.githubusercontent.com/98557455/183470971-7b188fdd-bb01-44e0-ac17-56f246ffd78e.gif)

By default, the ‘ls’ command will print the name of all the files and directories only. To get additional information such as the last time a file was modified or file permissions, use the flag “-l”:

```bash
ls -l 
```


You can create a new file via the ‘touch’ command followed by the name of the file you would like to create: 

```bash
touch hello_world.txt 
```
You can edit files using any downloaded graphical text-editor or the VS Code Remote – WSL extension. You can learn more about getting started with VS Code [here](/windows/wsl/tutorials/wsl-vscode)

If you prefer to edit a file directly from the command-line, you’ll need to use a command-line editor such as vim, emacs, or nano. Many distributions come with one or more of these programs installed, but you can always install these programs by following the installation instructions outlined in the guide from [above](https://github.com/MicrosoftDocs/WSL/edit/linux-tutorial/WSL/tutorials/linux.md#installing-and-updating-software). 

To edit your file with your preferred method of editing, simply run the program name followed by the name of the file you’d like to edit: 

```bash
code hello_world.txt
```

```bash
notepad.exe hello_world.txt
```

To see the contents of a file in the command line, use the ‘cat’ command followed by the file you’d like to read:

```bash
cat hello_world.txt 
```

![directory-and-file-commands2](https://user-images.githubusercontent.com/98557455/183481394-25bc0b2f-3d6d-465f-8f0b-aa5393f88727.gif)

## Using Pipes and Redirect Operators 

A pipe ‘|’ redirects the output from one command as input into another command. For example, lhscmd | rhscmd would direct the output from lhscmd to rhscmd. Pipes can be used in a variety of ways to quickly accomplish tasks through the command line. Below are just a few simple examples of how pipes can be used. 

Imagine you want to quickly sort the contents of a file. Take the fruits.txt example below:

```bash
cat fruits.txt 

Orange 

Banana 

Apple 

Pear 

Plum 

Kiwi 

Strawberry 

Peach 
```

You can quickly sort this list by using a pipe:

```bash
$ cat fruits.txt | sort 

Apple 

Banana 

Kiwi 

Orange 

Peach 

Pear 

Plum 

Strawberry 
```

By default, the output of the ‘cat’ command is sent to standard output; however, the ‘|’ allows us to instead redirect the output as the input to another command, ‘sort’.

Another use case is searching. You can use ‘grep’ which is a helpful command that searches input for a particular search string.

```bash
cat fruits.txt | grep P 

Pear 

Plum 

Peach 
```

You can also use redirect operators like ‘>’ to pass the output to a file or stream. For example, if you wanted to create a new .txt file with the sorted contents of fruit.txt:

```bash
cat fruits.txt | sort > sorted_fruit.txt 
```

```bash
$ cat sorted_fruit.txt 

Apple 

Banana 

Kiwi 

Orange 

Peach 

Pear 

Plum 

Strawberry 
```

By default, the output of the sort command is sent to standard output; however, the ‘>’ operator allows us to instead redirect the output into a new file named sorted_fruits.txt.

You can use pipes and redirect operators in many interesting ways to more efficiently complete tasks directly from the command line.

## Recommended content

- [Microsoft Learn: Introduction to Bash](/learn/modules/bash-introduction/)

- [Command Line for Beginners](https://ubuntu.com/tutorials/command-line-for-beginners#1-overview)

- [Microsoft Learn: Get Started with WSL](/learn/modules/get-started-with-windows-subsystem-for-linux/)