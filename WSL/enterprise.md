---
title: Windows Subsystem for Linux for Enterprise
description: Resources and instructions on how to best use the Windows Subsystem for Linux in an Enterprise environment.
keywords: BashOnWindows, bash, wsl, windows, windows subsystem for linux, windowssubsystem, ubuntu, debian, suse, windows 10, enterprise, deployment, offline, packaging, store, distribution, installation, install
ms.date: 05/15/2020
ms.topic: article
ms.localizationpriority: high
---

# Set up Windows Subsystem for Linux for your enterprise company

The Microsoft Store for Business offers a variety of solutions to Enterprises who want to deploy WSL to their company. The [Microsoft Store for Business and Education docs](/microsoft-store/) are a great resource to find out general information about the Store experience.

If you're a company that's just looking to get set up to start deploying WSL, follow these steps:

* [Sign up for the Microsoft Store for Business and get started](/microsoft-store/sign-up-microsoft-store-for-business-overview)
* [Manage your products and services (including who can access which apps in your private store)](/microsoft-store/manage-apps-microsoft-store-for-business-overview). Here you can add WSL distros to your store and control who can install them
* [Use a distribution method of your choice to deploy the software to your company](/microsoft-store/distribute-apps-to-your-employees-microsoft-store-for-business)
* Communicate to the employees of your company that they can use this documentation link to install WSL: [Install the Windows Subsystem for Linux](./install-win10.md)

## How to distribute a Linux distribution on Windows offline

If the computers in your company don't have access to the Microsoft Store or the Microsoft Store for Business, then you can download the installer of a Linux distribution that has an offline license by following these steps.

### Set up an Azure Active Directory account

You need to [sign up for an Azure AD account](/azure/active-directory/fundamentals/sign-up-organization?WT.mc_id=windows-c9-niner) and be the global administrator for your organization to get the installer of Microsoft Store apps. If you already have an account, you can skip this step.

### Set up WSL using your Microsoft Store for Business account

The instructions to register an account are found here:
https://docs.microsoft.com/microsoft-store/sign-up-microsoft-store-for-business

1. Sign into the Store for Business and go to the homepage: https://www.microsoft.com/business-store

    ![MS Store for business home page](media/offlineinstallscreens/1-screen.png)

2. Go to Manage > Settings and enable 'Show offline apps'.

    ![MS Store for business Settings page](media/offlineinstallscreens/2-screen.png)

3. Go back to the main page by selecting 'Shop for my group'.

    ![MS Store for business home page](media/offlineinstallscreens/1-screen.png)

4. Search for your desired distribution and select it.

    ![MS Store for business home page with active search](media/offlineinstallscreens/3-screen.png)

5. Select an 'Offline' license in the License type dropdown menu and select 'Get the app'. (Some Linux distributions may elect not to provide an offline license).

    ![MS Store for business Ubuntu select offline](media/offlineinstallscreens/4-screen.png)

6. Select the 'Manage' button to get to the app's product page.

    ![MS Store for business Ubuntu select manage](media/offlineinstallscreens/5-screen.png)

7. Select your architecture and download the package for offline use.

    ![MS Store for business Ubuntu select architecture](media/offlineinstallscreens/6-screen.png)

This installer can then be distributed to any computer where you would like to install WSL.
