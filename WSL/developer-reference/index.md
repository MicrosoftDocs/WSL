---
title: WSL container API developer reference
description: Developer reference for the WSL container API (wslc), including the C, C#, and C++ API references used to run and manage Linux containers on Windows.
keywords: wsl, windows subsystem for linux, container, wslc, wslcsdk, Microsoft.WSL.Containers, sdk, api, developer reference
ms.date: 06/24/2026
ms.topic: reference
---

# WSL container API developer reference

The WSL container API lets Windows app developers use Linux containers as part of their app logic. For an overview of the WSL container feature and the `wslc.exe` command-line interface, see [WSL container](../wsl-container.md).

> [!IMPORTANT]
> The WSL container API is currently in **preview** and may have breaking changes in future releases. Please use this preview to evaluate feasibility and then only deploy production grade code once this API goes to general availability in fall 2026.

## API reference

The API is available across the following language projections. Each reference documents the same underlying capabilities, layered as **Session → Container → Process**.

| Language | Namespace / header | Reference |
|---|---|---|
| C | `wslcsdk.h` (`wslcsdk.lib` / `wslcsdk.dll`) | [C API reference](wslc-c-api.md) |
| C# | `Microsoft.WSL.Containers` | [C# API reference](wslc-csharp-api.md) |
| C++ | `Microsoft::WSL::Containers` | [C++ API reference](wslc-cppwinrt-api.md) |

## Related content

- [WSL container](../wsl-container.md)
- [Get started with Linux containers](../tutorials/wsl-containers.md)
