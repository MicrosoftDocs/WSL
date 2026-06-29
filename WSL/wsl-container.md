---
title: WSL container
description: An overview of what the WSL container feature is, and how to use it to run Linux container workflows on Windows
keywords: BashOnWindows, bash, wsl, windows, windows subsystem, distro, custom, Linux, container
ms.date: 05/01/2026
ms.topic: how-to
ms.custom: sfi-image-nochange
---

# WSL container

The WSL container feature has two major components: a CLI called `wslc.exe` to build, run and interact with Linux containers and a WSL container API allowing Windows app developers to use Linux containers as part of their app logic. 

## WSL container CLI

WSL now includes `wslc.exe` as a built in binary. Its goal is to have a familiar CLI interface, allowing you to easily build, run and interact with Linux containers. 

See some of the example commands below:

```powershell
# Run a container
wslc run --rm -it ubuntu:latest bash -c "echo Hello world from WSL container!"
# List available images
wslc image ls
# Run a web server
wslc run -it --rm -d -p 8080:80 --name web nginx
# Get its content
curl localhost:8080
# List the container
wslc container ps
# Stop the container
wslc container stop web
```

You can learn more on how to get started with this feature at [our container tutorial](./tutorials/wsl-containers.md).

## WSL container API

Windows applications can make use of Linux containers as well! The WSL container API NuGet package allows you to programmatically pull, run, and interact with Linux containers, including key interactions like stdin and stdout, file mounts, networking mounts, GPU access and more.

For the complete API surface across the C, C#, and C++ projections, see the [WSL container API reference](https://wsl.dev/api-reference/).

### Install the API

The WSL container API ships in the `Microsoft.WSL.Containers` NuGet package, which provides both the C# projection and the C++/WinRT headers.

# [C#](#tab/csharp)

Add the package to your project with the .NET CLI:

```powershell
dotnet add package Microsoft.WSL.Containers
```

Then import the namespace in your code:

```csharp
using Microsoft.WSL.Containers;
```

# [C++](#tab/cpp)

Add the `Microsoft.WSL.Containers` NuGet package to your C++/WinRT project, then include the projected header and bring the namespace into scope:

```cpp
#include <winrt/Microsoft.WSL.Containers.h>

using namespace winrt::Microsoft::WSL::Containers;
```

> [!NOTE]
> The C++/WinRT projection is in preview and is subject to breaking changes.

---

### API overview

The API is organized around a small set of objects that mirror the lifecycle of running a container:

| Object | Description |
| --- | --- |
| `WslcService` | Static entry point for service-level operations. Use it to check that the required WSL components are installed, query the service version, and install missing dependencies. |
| `Session` | A WSL-backed host that runs your containers. A session manages images (pull, import, load, push, tag, delete) and creates containers. |
| `Container` | A container created inside a session. Use it to start, stop, inspect, and delete the container, and to run additional processes inside it. |
| `Process` | A Linux process running in a container. Use it to read `stdout`/`stderr`, write to `stdin`, send signals, and observe exit codes through events. |

A typical flow is: verify prerequisites with `WslcService`, create and start a `Session`, pull an image, configure and create a `Container`, then start it and interact with its `Process` objects.

### Sample snippets

The snippets below show the same core building blocks in each supported language. Use the tabs to switch between C# and C++.

# [C#](#tab/csharp)

**Check that the required components are installed:**

```csharp
ComponentFlags missing = WslcService.GetMissingComponents();
if (missing != ComponentFlags.None)
{
    Console.WriteLine($"WSL components are missing ({missing}). Run: wsl --install");
    return;
}
```

**Create and start a session:**

```csharp
var sessionSettings = new SessionSettings("MyApp", @"C:\WslcData")
{
    CpuCount = 4,
    MemoryMB = 4096
};

var session = new Session(sessionSettings);
session.Start();
```

**Pull an image with progress reporting:**

```csharp
var pull = session.PullImageAsync(new PullImageOptions("docker.io/library/alpine:latest"));
pull.Progress = (op, progress) =>
    Console.WriteLine($"Pull: {progress.Status} {progress.CurrentBytes}/{progress.TotalBytes}");
await pull;
```

**Create a container, run a command, and read its output:**

```csharp
var initProcess = new ProcessSettings
{
    CmdLine = new[] { "/bin/echo", "Hello from WSL Container!" },
    OutputMode = ProcessOutputMode.Event
};

var containerSettings = new ContainerSettings("alpine:latest")
{
    Name = "hello-container",
    InitProcess = initProcess
};

var container = session.CreateContainer(containerSettings);

container.InitProcess.OutputReceived += data =>
    Console.Write(Encoding.UTF8.GetString(data));

container.Start();
```

When you're finished, stop and delete the container, then terminate the session to release resources:

```csharp
container.Stop(Signal.SIGTERM, TimeSpan.FromSeconds(10));
container.Delete(DeleteContainerFlags.None);
session.Terminate();
```

# [C++](#tab/cpp)

These snippets use C++/WinRT. The asynchronous calls use `co_await`, so they must run inside a coroutine.

**Check that the required components are installed:**

```cpp
auto missing = WslcService::GetMissingComponents();
if (missing != ComponentFlags::None)
{
    printf("WSL components are missing. Run: wsl --install\n");
    return;
}
```

**Create and start a session:**

```cpp
SessionSettings sessionSettings{ L"MyApp", L"C:\\WslcData" };
sessionSettings.CpuCount(4);
sessionSettings.MemoryMB(4096);

Session session{ sessionSettings };
session.Start();
```

**Pull an image with progress reporting:**

```cpp
PullImageOptions pullOptions{ L"docker.io/library/alpine:latest" };
auto pull = session.PullImageAsync(pullOptions);
pull.Progress([](auto&&, ImageProgress const& progress)
{
    printf("Pull: %d %llu/%llu\n",
        static_cast<int>(progress.Status()),
        progress.CurrentBytes(),
        progress.TotalBytes());
});
co_await pull;
```

**Create a container, run a command, and read its output:**

```cpp
using namespace winrt::Windows::Foundation::Collections;

ProcessSettings initProcess;
initProcess.OutputMode(ProcessOutputMode::Event);

auto cmdLine = single_threaded_vector<hstring>();
cmdLine.Append(L"/bin/echo");
cmdLine.Append(L"Hello from WSL Container!");
initProcess.CmdLine(cmdLine);

ContainerSettings containerSettings{ L"alpine:latest" };
containerSettings.Name(L"hello-container");
containerSettings.InitProcess(initProcess);

auto container = session.CreateContainer(containerSettings);

container.InitProcess().OutputReceived([](auto const& data)
{
    std::string text(data.begin(), data.end());
    printf("%s", text.c_str());
});

container.Start();
```

When you're finished, stop and delete the container, then terminate the session to release resources:

```cpp
container.Stop(Signal::SIGTERM, std::chrono::seconds(10));
container.Delete(DeleteContainerFlags::None);
session.Terminate();
```

---

### Full end-to-end samples

The snippets above show the core building blocks. For complete, runnable examples that cover the full container lifecycle, image management, port mappings, volume mounts, GPU access, and interactive `stdin`/`stdout` streaming, see the [WSL container API samples](https://aka.ms/wslc-samples).

