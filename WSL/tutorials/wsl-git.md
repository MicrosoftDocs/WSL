---
title: Get started using Git on WSL
description: Learn how to set up Git for version control on the Windows Subsystem for Linux, along with Git Credential Manager.
ms.date: 06/21/2023
ms.topic: article
---

# Get started using Git on Windows Subsystem for Linux

Git is the most commonly used version control system. With Git, you can track changes you make to files, so you have a record of what has been done, and have the ability to revert to earlier versions of the files if needed. Git also makes collaboration easier, allowing changes by multiple people to all be merged into one source.

## Git can be installed on Windows AND on WSL

An important consideration: when you enable WSL and install a Linux distribution, you are installing a new file system, separated from the Windows NTFS C:\ drive on your machine. In Linux, drives are not given letters. They are given mount points. The root of your file system `/` is the mount point of your root partition, or folder, in the case of WSL. Not everything under `/` is the same drive. For example, on my laptop, I've installed two version of Ubuntu (20.04 and 18.04), as well as Debian. If I open those distributions, select the home directory with the command `cd ~`, and then enter the command `explorer.exe .`, Windows File Explorer will open and show me the directory path for that distribution.

| Linux distro | Windows Path to access home folder |
| ----------- | ----------- |
| Ubuntu 20.04 | `\\wsl$\Ubuntu-20.04\home\username` |
| Ubuntu 18.04 | `\\wsl$\Ubuntu-18.04\home\username` |
| Debian | `\\wsl$\Debian\home\username` |
| Windows PowerShell | `C:\Users\username` |

> [!TIP]
> If you are seeking to access the Windows file directory from your WSL distribution command line, instead of `C:\Users\username`, the directory would be accessed using `/mnt/c/Users/username`, because the Linux distribution views your Windows file system as a mounted drive.

You will need to install Git on each file system that you intend to use it with.

![Showing Git versions by distro](../media/git-versions.gif)

## Installing Git

Git comes already installed with most of the Windows Subsystem for Linux distributions, however, you may want to update to the latest version. You also will need to set up your git config file.

To install Git, see the [Git Download for Linux](https://git-scm.com/download/linux) site. Each Linux distribution has their own package manager and install command.

For the latest stable Git version in Ubuntu/Debian, enter the command:

```bash
sudo apt-get install git
```

> [!NOTE]
> You also may want to [install Git for Windows](https://git-scm.com/download/win) if you haven't already.

## Git config file setup

To set up your Git config file, open a command line for the distribution you're working in and set your name with this command (replacing "Your Name" with your preferred username):

```bash
git config --global user.name "Your Name"
```

Set your email with this command (replacing "youremail@domain.com" with the email you prefer):

```bash
git config --global user.email "youremail@domain.com"
```

> [!TIP]
> If you don't yet have a GitHub account, you can [sign-up for one on GitHub](https://github.com/join). If you've never worked with Git before, [GitHub Guides](https://guides.github.com/) can help you get started. If you need to edit your Git config, you can do so with a built-in text editor like nano: `nano ~/.gitconfig`.

We recommend that you [secure your account with two-factor authentication (2FA)](https://help.github.com/en/github/authenticating-to-github/securing-your-account-with-two-factor-authentication-2fa).

## Git Credential Manager setup

[Git Credential Manager (GCM)](https://github.com/GitCredentialManager/git-credential-manager) is a secure Git credential helper built on [.NET](https://dotnet.microsoft.com/) that can be used with both WSL1 and WSL2. It enables multi-factor authentication support for GitHub repos, [Azure DevOps](https://dev.azure.com/), Azure DevOps Server, and Bitbucket. 

GCM integrates into the authentication flow for services like GitHub and, once you're authenticated to your hosting provider, requests a new authentication token. It then stores the token securely in the [Windows Credential Manager](https://support.microsoft.com/help/4026814/windows-accessing-credential-manager). After the first time, you can use Git to talk to your hosting provider without needing to re-authenticate. It will just access the token in the Windows Credential Manager.

In order to use GCM with WSL you must be on Windows 10 Version 1903 or later. This is the first version of Windows that includes the required `wsl.exe` tool that GCM uses to interoperate with Git in your WSL distributions. 

It is recommended to install the [latest Git for Windows](https://github.com/git-for-windows/git/releases/latest) in order to share credentials & settings between WSL and the Windows host. Git Credential Manager is included with Git for Windows and the latest version is included in each new Git for Windows release. During the installation, you will be asked to select a credential helper, with GCM set as the default.

If you have a reason not to install Git for Windows, you can install GCM as a Linux application directly in your WSL distribution, but note that doing so means GCM is running as a Linux application and cannot utilize the authentication or credential storage features of the host Windows operating system. See the GCM repo for instructions on how to [configure WSL without Git for Windows](https://github.com/GitCredentialManager/git-credential-manager/blob/main/docs/wsl.md#configuring-wsl-without-git-for-windows).



To set up GCM for use with a WSL distribution, open your distribution and enter this command:

If GIT installed is >= v2.39.0

```bash
git config --global credential.helper "/mnt/c/Program\ Files/Git/mingw64/bin/git-credential-manager.exe"
```

else if GIT installed is >= v2.36.1

```bash
git config --global credential.helper "/mnt/c/Program\ Files/Git/mingw64/libexec/git-core/git-credential-manager.exe"
```

else if version is < v2.36.1 enter this command: 

```bash
git config --global credential.helper "/mnt/c/Program\ Files/Git/mingw64/bin/git-credential-manager-core.exe"
```

> [!NOTE]
> Using GCM as a credential helper for a WSL Git installation means that any configuration set in WSL Git is NOT respected by GCM (by default). This is because GCM is running as a Windows application, and therefore will use the Git for Windows installation to query configuration. This means things like proxy settings for GCM need to be set in Git for Windows as well as WSL Git as they are stored in different files (`%USERPROFILE%\.gitconfig` vs `\\wsl$\distro\home\$USER\.gitconfig`). You can configure WSL so that GCM will use the WSL Git configuration, but this means that proxy settings will be unique to the specific WSL installation and not shared with others or the Windows host.

### Git with SSH

Git Credential Manager only works with HTTP(S) remotes. You can still use Git with SSH:

- [Azure DevOps SSH](/azure/devops/repos/git/use-ssh-keys-to-authenticate)
- [GitHub SSH](https://help.github.com/en/articles/connecting-to-github-with-ssh)
- [Bitbucket SSH](https://confluence.atlassian.com/bitbucket/ssh-keys-935365775.html)

### Additional configuration for Azure

If you intend to work with [Azure Repos](https://github.com/GitCredentialManager/git-credential-manager/blob/main/docs/configuration.md#credentialprovider) or [Azure DevOps](https://github.com/GitCredentialManager/git-credential-manager/blob/main/docs/wsl.md#configuring-wsl-with-git-for-windows-recommended), some additional configuration is required:

```Bash
git config --global credential.https://dev.azure.com.useHttpPath true
```

Now any git operation you perform within your WSL distribution will use GCM. If you already have credentials cached for a host, it will access them from the credential manager. If not, you'll receive a dialog response requesting your credentials, even if you're in a Linux console.

> [!TIP]
> If you are using a GPG key for code signing security, you may need to [associate your GPG key with your GitHub email](https://help.github.com/en/github/authenticating-to-github/associating-an-email-with-your-gpg-key).

## Adding a Git Ignore file

We recommend adding a [.gitignore file](https://help.github.com/en/articles/ignoring-files) to your projects. GitHub offers [a collection of useful .gitignore templates](https://github.com/github/gitignore) with recommended .gitignore file setups organized according to your use-case. For example, here is [GitHub's default gitignore template for a Node.js project](https://github.com/github/gitignore/blob/master/Node.gitignore).

If you choose to [create a new repo using the GitHub website](https://help.github.com/articles/create-a-repo), there are check boxes available to initialize your repo with a README file, .gitignore file set up for your specific project type, and options to add a license if you need one.

## Git and VS Code

Visual Studio Code comes with built-in support for Git, including a source control tab that will show your changes and handle a variety of git commands for you. Learn more about [VS Code's Git support](https://code.visualstudio.com/docs/editor/versioncontrol#_git-support).

## Git line endings

If you are working with the same repository folder between Windows, WSL, or a container, be sure to set up consistent line endings.

Since Windows and Linux use different default line endings, Git may report a large number of modified files that have no differences aside from their line endings. To prevent this from happening, you can disable line ending conversion using a `.gitattributes` file or globally on the Windows side. See this [VS Code doc about resolving Git line ending issues](https://code.visualstudio.com/docs/remote/troubleshooting#_resolving-git-line-ending-issues-in-wsl-resulting-in-many-modified-files).

## Additional resources

* [WSL & VS Code](./wsl-vscode.md)
* [GitHub Learning Lab: Online courses](https://github.com/apps/github-learning-lab)
* [Git Visualization Tool](http://git-school.github.io/visualizing-git/)
* [Git Tools - Credential Storage](https://git-scm.com/book/it/v2/Git-Tools-Credential-Storage)
