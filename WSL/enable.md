---
title: Enable Windows Subsystem for Linux (WSL) on Windows 10
description: Steps to enable WSL.
ms.date: 09/25/2020
ms.topic: conceptual
---

# Enable Windows Subsystem for Linux on your Windows 10 machine

To enable Windows Subsystem for Linux (WSL) on your Windows 10 machine, follow these steps:

1. From your Windows menu, go to Settings > Update & Security > For developers.
2. Turn on **Developer Mode**.
3. From your Windows menu, open **Control Panel** and go to Programs > Programs & Features > Turn Windows features on or off.
4. Once the **Turn Windows features on or off** menu has opened, select the check box next to **Windows Subsystem for Linux**, ensuring that it is checked.
5. If you are planning to update to WSL 2, you should also select **VirtualMachinePlatform**, ensuring that it is enabled with a check.
6. You now need to restart your machine.

Return to the [install WSL instructions](/install-win10.md) for more information about what version of Windows 10 is required for running WSL or updating to WSL 2, in addition to more information on installing Linux distributions, etc.

![Screenshot of Developer Mode in the Settings menu](/media/settings-for-devs.png)

Turn on Developer Mode.

![Screenshot of Turn Windows features on or off menu](/media/control-panel-enable.png)

Open the **Turn Windows features on or off** menu and ensure that **Windows Subsystem for Linux** and  **VirtualMachinePlatform** (if you plan to use WSL 2) are both enabled.
