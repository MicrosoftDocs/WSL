---
title: WSL container API C++ reference
description: C++ API reference for the WSL container API (Microsoft.WSL.Containers) used to create sessions, run Linux containers, manage processes, images, and VHD-backed storage on Windows.
keywords: wsl, windows subsystem for linux, container, wslc, Microsoft.WSL.Containers, C++/WinRT, cppwinrt, developer reference, sdk
ms.date: 06/24/2026
ms.topic: reference
---

# WSL container API C++ reference

This reference documents the **C++/WinRT projection** in `Microsoft::WSL::Containers`.

> **Preview notice:** `wslcsdk.h` explicitly marks this API as **preview** and subject to breaking changes.
>
> **Header:** `#include <winrt/Microsoft.WSL.Containers.h>`
>
> **Namespace:** `winrt::Microsoft::WSL::Containers`

The projection is layered as **Session → Container → Process**. Errors surface as `winrt::hresult_error`. Image and installation operations use `IAsyncActionWithProgress<T>`.

---

## Table of Contents

- [Data Classes](#data-classes)
  - [ImageInfo](#imageinfo)
  - [ImageProgress](#imageprogress)
  - [InstallProgress](#installprogress)
  - [ContainerPortMapping](#containerportmapping)
  - [ContainerVolume](#containervolume)
  - [ContainerNamedVolume](#containernamedvolume)
  - [Referenced](#referenced)
- [Settings Classes](#settings-classes)
  - [SessionSettings](#sessionsettings)
  - [ContainerSettings](#containersettings)
  - [ProcessSettings](#processsettings)
- [Core Classes](#core-classes)
  - [Session](#session)
  - [Container](#container)
  - [Process](#process)
- [Service Class](#service-class)
  - [WslcService](#wslcservice)
- [Delegates and Events](#delegates-and-events)
  - [SessionTerminationHandler](#sessionterminationhandler)
  - [ProcessOutputHandler](#processoutputhandler)
  - [ProcessExitHandler](#processexithandler)
- [Enumerations](#enumerations)
  - [SessionFeatureFlags](#sessionfeatureflags)
  - [SessionTerminationReason](#sessionterminationreason)
  - [ContainerNetworkingMode](#containernetworkingmode)
  - [ContainerFlags](#containerflags)
  - [PortProtocol](#portprotocol)
  - [ContainerState](#containerstate)
  - [Signal](#signal)
  - [DeleteContainerFlags](#deletecontainerflags)
  - [ProcessOutputMode](#processoutputmode)
  - [ProcessOutputHandle](#processoutputhandle)
  - [ProcessState](#processstate)
  - [ImageProgressStatus](#imageprogressstatus)
  - [ComponentFlags](#componentflags)
- [Not Yet Implemented and Known Gaps](#not-yet-implemented-and-known-gaps)
- [End-to-End Example](#end-to-end-example)

---

## Data Classes

### ImageInfo

Read-only wrapper created from `WslcImageInfo`.

**Properties**
- `Name()` → image name
- `Sha256()` → 32-byte buffer
- `SizeBytes()` → image size
- `CreatedTimestamp()` → WinRT `DateTime`

```cpp
auto images = session.Images();
for (auto const& image : images)
{
    auto name = image.Name();
    auto hash = image.Sha256();
    auto size = image.SizeBytes();
    auto created = image.CreatedTimestamp();
}
```

### ImageProgress

Progress item reported by image pull/import/load/push operations.

**Properties**
- `Id()`
- `Status()`
- `CurrentBytes()`
- `TotalBytes()`

```cpp
auto op = session.LoadImageAsync(L"C:\\images\\demo.tar");
op.Progress([](auto&&, ImageProgress const& p)
{
    printf("layer=%ws status=%d %llu/%llu\n",
        p.Id().c_str(),
        static_cast<int>(p.Status()),
        p.CurrentBytes(),
        p.TotalBytes());
});
co_await op;
```

### InstallProgress

Progress item reported by `WslcService::InstallWithDependenciesAsync()`.

**Properties**
- `Component()`
- `Progress()`
- `Total()`

```cpp
auto install = WslcService::InstallWithDependenciesAsync();
install.Progress([](auto&&, InstallProgress const& p)
{
    printf("component=%d step=%u/%u\n",
        static_cast<int>(p.Component()),
        p.Progress(),
        p.Total());
});
co_await install;
```

### ContainerPortMapping

Maps a Windows host port to a container port.

**Constructors / properties**
- `ContainerPortMapping(uint16_t windowsPort, uint16_t containerPort, PortProtocol protocol)`
- `WindowsPort()` / setter
- `ContainerPort()` / setter
- `Protocol()` / setter
- `WindowsAddress()` / setter

**Important notes**
- `WindowsAddress` is implemented.
- The setter accepts only `Windows::Networking::HostName` values whose type is `Ipv4` or `Ipv6`.
- `ToStruct()` uses `inet_pton` and stores a real `sockaddr_in` / `sockaddr_in6`.

```cpp
using namespace winrt::Windows::Networking;

ContainerPortMapping mapping{ 8080, 80, PortProtocol::TCP };
mapping.WindowsAddress(HostName{ L"127.0.0.1" });

auto hostPort = mapping.WindowsPort();
auto guestPort = mapping.ContainerPort();
auto protocol = mapping.Protocol();
auto bindAddress = mapping.WindowsAddress();
```

### ContainerVolume

Binds a Windows path into the container.

**Constructors / properties**
- `ContainerVolume(hstring windowsPath, hstring containerPath, bool readOnly)`
- `WindowsPath()` / setter
- `ContainerPath()` / setter
- `ReadOnly()` / setter

```cpp
ContainerVolume volume{ L"C:\\data", L"/workspace", false };
volume.ReadOnly(true);
volume.WindowsPath(L"C:\\data");
volume.ContainerPath(L"/workspace");
```

### ContainerNamedVolume

Attaches a named session VHD volume to a container.

**Constructors / properties**
- `ContainerNamedVolume(hstring name, hstring containerPath, bool readOnly)`
- `Name()` / setter
- `ContainerPath()` / setter
- `ReadOnly()` / setter

```cpp
ContainerNamedVolume named{ L"build-cache", L"/cache", false };
named.Name(L"build-cache");
named.ContainerPath(L"/cache");
named.ReadOnly(false);
```

### Referenced 

- `Session::PullImageAsync(PullImageOptions)` forwards a struct whose C shape is `{ uri, progressCallback, progressCallbackContext, registryAuth }`.
- `Session::PushImageAsync(PushImageOptions)` forwards a struct whose C shape is `{ image, registryAuth, progressCallback, progressCallbackContext }`.
- `Session::TagImage(TagImageOptions)` forwards a struct whose C shape is `{ image, repo, tag }`.
- `Session::CreateVhdVolume(VhdOptions)` and `SessionSettings::VhdRequirements(VhdOptions)` use the C `WslcVhdRequirements` shape `{ name, sizeBytes, type, flags, uid, gid }`.
- `WslcService::GetVersion()` returns a `ServiceVersion` created from C `major`, `minor`, and `revision` values.



```cpp
PullImageOptions pullOptions = /* construct using the wrapper available in your build */;
auto pull = session.PullImageAsync(pullOptions);
pull.Progress([](auto&&, ImageProgress const& p) { /* ... */ });
co_await pull;

PushImageOptions pushOptions = /* construct using the wrapper available in your build */;
co_await session.PushImageAsync(pushOptions);

TagImageOptions tagOptions = /* construct using the wrapper available in your build */;
session.TagImage(tagOptions);

VhdOptions vhdOptions = /* construct using the wrapper available in your build */;
session.CreateVhdVolume(vhdOptions);

auto version = WslcService::GetVersion();
(void)version;
```

---

## Settings Classes

All three settings objects become effectively immutable after the wrapper materializes the underlying C struct.

### SessionSettings

**Constructor**
- `SessionSettings(hstring name, hstring storagePath)`
  - `name` must be non-empty.
  - `storagePath` must be non-empty.

**Properties**
- `Name()` / setter
- `StoragePath()` / setter
- `CpuCount()` / setter (`0` rejected)
- `MemoryMB()` / setter (`0` rejected)
- `Timeout()` / setter
  - cannot be zero
  - cannot be negative
  - converted to **milliseconds** and must fit in `uint32_t`
- `VhdRequirements()` / setter
  - setter rejects `nullptr`
- `FeatureFlags()` / setter

```cpp
SessionSettings settings{ L"demo", L"C:\\WSLC\\demo" };
settings.Name(L"demo");
settings.StoragePath(L"C:\\WSLC\\demo");
settings.CpuCount(winrt::box_value<uint32_t>(4).as<winrt::Windows::Foundation::IReference<uint32_t>>());
settings.MemoryMB(winrt::box_value<uint32_t>(4096).as<winrt::Windows::Foundation::IReference<uint32_t>>());
settings.Timeout(winrt::box_value(winrt::Windows::Foundation::TimeSpan{ std::chrono::minutes(5) })
    .as<winrt::Windows::Foundation::IReference<winrt::Windows::Foundation::TimeSpan>>());
settings.FeatureFlags(SessionFeatureFlags::None);

auto name = settings.Name();
auto path = settings.StoragePath();
auto cpu = settings.CpuCount();
auto memory = settings.MemoryMB();
auto timeout = settings.Timeout();
auto flags = settings.FeatureFlags();
```

### ContainerSettings

**Constructor**
- `ContainerSettings(hstring imageName)`
  - `imageName` must be non-empty.

**Properties**
- `ImageName()` / setter
- `Name()` / setter
- `InitProcess()` / setter
- `NetworkingMode()` / setter (`None` and `Bridged` only)
- `HostName()` / setter
- `DomainName()` / setter
- `Flags()` / setter
- `PortMappings()` / setter
- `Volumes()` / setter
- `NamedVolumes()` / setter

**Important notes**
- Collection setters reject `nullptr`.
- When converting to the C struct, null elements inside the collections are rejected.

```cpp
using namespace winrt::Windows::Foundation::Collections;

ContainerSettings containerSettings{ L"demo-image:latest" };
containerSettings.Name(L"demo-container");
containerSettings.NetworkingMode(
    winrt::box_value(ContainerNetworkingMode::Bridged)
        .as<winrt::Windows::Foundation::IReference<ContainerNetworkingMode>>());
containerSettings.HostName(L"demo-host");
containerSettings.DomainName(L"localdomain");
containerSettings.Flags(static_cast<ContainerFlags>(0));

auto ports = single_threaded_vector<ContainerPortMapping>();
ports.Append(ContainerPortMapping{ 8080, 80, PortProtocol::TCP });
containerSettings.PortMappings(ports);

auto volumes = single_threaded_vector<ContainerVolume>();
volumes.Append(ContainerVolume{ L"C:\\src", L"/src", false });
containerSettings.Volumes(volumes);

auto namedVolumes = single_threaded_vector<ContainerNamedVolume>();
namedVolumes.Append(ContainerNamedVolume{ L"cache", L"/cache", false });
containerSettings.NamedVolumes(namedVolumes);
```

### ProcessSettings

**Properties**
- `WorkingDirectory()` / setter
- `CmdLine()` / setter
- `EnvironmentVariables()` / setter
- `OutputMode()` / setter

**Important notes**
- `CmdLine(nullptr)` and `EnvironmentVariables(nullptr)` are rejected.
- `Process::Start()` later requires a **non-empty** `CmdLine()`.
- `OutputMode::Event` installs C callbacks; `OutputMode::Stream` expects stream access; `Discard` is the default.

```cpp
using namespace winrt::Windows::Foundation::Collections;

ProcessSettings procSettings;
procSettings.WorkingDirectory(L"/workspace");
procSettings.OutputMode(ProcessOutputMode::Event);

auto cmd = single_threaded_vector<hstring>();
cmd.Append(L"/bin/sh");
cmd.Append(L"-lc");
cmd.Append(L"echo hello");
procSettings.CmdLine(cmd);

auto env = single_threaded_map<hstring, hstring>();
env.Insert(L"DEMO", L"1");
procSettings.EnvironmentVariables(env);
```

---

## Core Classes

### Session

**Constructor**
- `Session(SessionSettings settings)`
  - rejects `nullptr` settings.

**Methods**
- `Start()`
- `Terminate()`
- `CreateContainer(ContainerSettings containerSettings)`
- `PullImageAsync(PullImageOptions options)`
- `ImportImageAsync(hstring path, hstring imageName)`
- `LoadImageAsync(hstring path)`
- `PushImageAsync(PushImageOptions options)`
- `DeleteImage(hstring nameOrId)`
- `TagImage(TagImageOptions options)`
- `CreateVhdVolume(VhdOptions options)`
- `DeleteVhdVolume(hstring name)`
- `Authenticate(Uri serverAddress, hstring username, hstring password)`
- `Images()`
- event `Terminated`

**Behavior notes**
- `Start()` is one-shot; calling it twice throws.
- Most methods call `EnsureStarted()` first.
- `ImportImageAsync` and `LoadImageAsync` are path-based only.
- `Authenticate` requires a non-null `Uri` and non-empty username.
- `Images()` materializes WinRT `ImageInfo` objects from the C array returned by `WslcListSessionImages`.

**Examples**

```cpp
Session session{ settings };
session.Terminated([](SessionTerminationReason reason)
{
    printf("session terminated: %d\n", static_cast<int>(reason));
});
session.Start();
```

```cpp
auto container = session.CreateContainer(containerSettings);
```

```cpp
auto importOp = session.ImportImageAsync(L"C:\\images\\alpine.tar", L"demo/alpine:latest");
importOp.Progress([](auto&&, ImageProgress const& p) { /* progress */ });
co_await importOp;
```

```cpp
auto loadOp = session.LoadImageAsync(L"C:\\images\\bundle.tar");
co_await loadOp;
```

```cpp
session.DeleteImage(L"demo/alpine:latest");
```

```cpp
auto token = session.Authenticate(
    winrt::Windows::Foundation::Uri{ L"https://registry.example.com" },
    L"user",
    L"password");
```

```cpp
auto images = session.Images();
for (auto const& image : images)
{
    printf("%ws\n", image.Name().c_str());
}
```

```cpp
PullImageOptions pullOptions = ;
auto pullOp = session.PullImageAsync(pullOptions);
pullOp.Progress([](auto&&, ImageProgress const& p) { /* progress */ });
co_await pullOp;

PushImageOptions pushOptions = ;
co_await session.PushImageAsync(pushOptions);

TagImageOptions tagOptions = ;
session.TagImage(tagOptions);

VhdOptions vhdOptions = ;
session.CreateVhdVolume(vhdOptions);
session.DeleteVhdVolume(L"build-cache");
```

```cpp
session.Terminate();
```

### Container

**Methods**
- `Start()`
- `Stop(Signal signal, TimeSpan timeout)`
- `Delete(DeleteContainerFlags flags)`
- `CreateProcess(ProcessSettings newProcessSettings)`
- `Inspect()`
- `Id()`
- `InitProcess()`
- `State()`

**Behavior notes**
- `Start()` automatically sets `WSLC_CONTAINER_START_FLAG_ATTACH` if an init process exists and its output mode is `Event` or `Stream`.
- `Stop()` converts the timeout to **seconds**, rejects negative values, and rejects values that exceed `uint32_t`.
- `InitProcess()` throws if the container was not configured with one.

**Examples**

```cpp
container.Start();
```

```cpp
container.Stop(static_cast<Signal>(15), std::chrono::seconds(10));
```

```cpp
container.Delete(static_cast<DeleteContainerFlags>(0));
```

```cpp
auto proc = container.CreateProcess(procSettings);
```

```cpp
auto inspectJson = container.Inspect();
auto id = container.Id();
auto state = container.State();
```

```cpp
auto init = container.InitProcess();
```

### Process

`Process` objects are returned by `Container::CreateProcess()` and `Container::InitProcess()`.

**Methods / events**
- `Start()`
- `Pid()`
- `State()`
- `ExitCode()`
- `Signal(Signal signal)`
- `GetOutputStream(ProcessOutputHandle outputHandle)`
- `GetInputStream()`
- event `OutputReceived`
- event `ErrorReceived`
- event `Exited`

**Behavior notes**
- `Start()` cannot be called on the init process.
- `Start()` requires a non-empty `ProcessSettings::CmdLine()`.
- `GetOutputStream()` requires `OutputMode::Stream`.
- `OutputReceived` and `ErrorReceived` require `OutputMode::Event`.
- `Exited` is raised by the exit callback in event mode, and by waiting on the process exit event in stream/discard mode.

**Examples**

```cpp
auto proc = container.CreateProcess(procSettings);
proc.Exited([](int32_t exitCode)
{
    printf("process exited: %d\n", exitCode);
});
proc.Start();
```

```cpp
auto pid = proc.Pid();
auto state = proc.State();
```

```cpp
proc.Signal(static_cast<Signal>(2)); // SIGINT
```

```cpp
auto stdinStream = proc.GetInputStream();
```

```cpp
ProcessSettings streamSettings;
streamSettings.OutputMode(ProcessOutputMode::Stream);
// ... set CmdLine ...
auto streamProc = container.CreateProcess(streamSettings);
streamProc.Start();
auto stdoutStream = streamProc.GetOutputStream(static_cast<ProcessOutputHandle>(1));
auto stderrStream = streamProc.GetOutputStream(static_cast<ProcessOutputHandle>(2));
```

```cpp
ProcessSettings eventSettings;
eventSettings.OutputMode(ProcessOutputMode::Event);
// ... set CmdLine ...
auto eventProc = container.CreateProcess(eventSettings);
eventProc.OutputReceived([](auto const& data)
{
    printf("stdout bytes: %zu\n", data.size());
});
eventProc.ErrorReceived([](auto const& data)
{
    printf("stderr bytes: %zu\n", data.size());
});
eventProc.Exited([](int32_t exitCode)
{
    printf("done: %d\n", exitCode);
});
eventProc.Start();
```

```cpp
auto exitCode = proc.ExitCode();
```

---

## Service Class

### WslcService

Static entry points over the service-level C API.

**Methods**
- `GetMissingComponents()`
- `GetVersion()`
- `InstallWithDependenciesAsync()`

**Behavior notes**
- `GetMissingComponents()` returns the direct cast of `WslcComponentFlags`.
- `GetVersion()` returns a `ServiceVersion` constructed from `major`, `minor`, and `revision`.
- `InstallWithDependenciesAsync()` runs on a background thread and reports `InstallProgress`.

```cpp
auto missing = WslcService::GetMissingComponents();
if (missing != static_cast<ComponentFlags>(0))
{
    auto install = WslcService::InstallWithDependenciesAsync();
    install.Progress([](auto&&, InstallProgress const& p)
    {
        printf("install %u/%u\n", p.Progress(), p.Total());
    });
    co_await install;
}
```

```cpp
auto version = WslcService::GetVersion();
(void)version; 
```

---

## Delegates and Events

### SessionTerminationHandler

Observed use:
- `Session::Terminated` raises one argument: `SessionTerminationReason reason`.

```cpp
session.Terminated([](SessionTerminationReason reason)
{
    printf("terminated: %d\n", static_cast<int>(reason));
});
```

### ProcessOutputHandler

Observed use:
- `Process::OutputReceived` and `Process::ErrorReceived` raise one argument containing raw output bytes.
- The wrapper forwards a `winrt::array_view<const uint8_t>` produced from the C callback buffer.

```cpp
process.OutputReceived([](auto const& data)
{
    std::string text(data.begin(), data.end());
    printf("stdout: %s\n", text.c_str());
});
```

### ProcessExitHandler

Observed use:
- `Process::Exited` raises one `int32_t exitCode`.

```cpp
process.Exited([](int32_t exitCode)
{
    printf("exit code: %d\n", exitCode);
});
```

---

## Enumerations

For enums that are directly `static_cast` to/from the C API, the numeric values match the corresponding `Wslc*` enum in `wslcsdk.h`.

### SessionFeatureFlags


- `None` is the default in `winrt_SessionSettings.h`.
- `SessionSettings::FeatureFlags` is passed directly to `WslcSetSessionSettingsFeatureFlags`.

Underlying C values:
- `None = 0x00000000`
- `EnableGpu = 0x00000004`

```cpp
SessionSettings settings{ L"demo", L"C:\\WSLC\\demo" };
settings.FeatureFlags(SessionFeatureFlags::None);
```

### SessionTerminationReason

`Session::OnTerminated` converts `WslcSessionTerminationReason` directly to the WinRT enum.

Underlying C values:
- `Unknown = 0`
- `Shutdown = 1`
- `Crashed = 2`

```cpp
session.Terminated([](SessionTerminationReason reason)
{
    if (reason == static_cast<SessionTerminationReason>(2))
    {
        // crashed
    }
});
```

### ContainerNetworkingMode

`winrt_ContainerSettings.cpp` explicitly validates only:
- `None`
- `Bridged`

Underlying C values:
- `None = 0`
- `Bridged = 1`

```cpp
containerSettings.NetworkingMode(ContainerNetworkingMode::Bridged);
```

### ContainerFlags


- `None` is the default in `winrt_ContainerSettings.h`.
- Flags are passed directly to `WslcSetContainerSettingsFlags`.

Underlying C values:
- `None = 0x00000000`
- `AutoRemove = 0x00000001`
- `EnableGpu = 0x00000002`
- `Privileged = 0x00000004`

```cpp
containerSettings.Flags(static_cast<ContainerFlags>(0x00000001)); // AutoRemove
```

### PortProtocol

- `TCP` is the default in `winrt_ContainerPortMapping.h`.
- The value is passed directly to `WslcContainerPortMapping::protocol`.

Underlying C values:
- `TCP = 0`
- `UDP = 1`

```cpp
ContainerPortMapping mapping{ 8080, 80, PortProtocol::TCP };
```

### ContainerState

`Container::State()` casts directly from `WslcContainerState`.

Underlying C values:
- `Invalid = 0`
- `Created = 1`
- `Running = 2`
- `Exited = 3`
- `Deleted = 4`

```cpp
auto state = container.State();
if (state == static_cast<ContainerState>(2))
{
    // running
}
```

### Signal

`Container::Stop()` and `Process::Signal()` cast directly to `WslcSignal`.

Underlying C values in `wslcsdk.h`:
- `0` none
- `1` SIGHUP
- `2` SIGINT
- `3` SIGQUIT
- `9` SIGKILL
- `15` SIGTERM



```cpp
process.Signal(static_cast<Signal>(2));   // SIGINT
container.Stop(static_cast<Signal>(15), std::chrono::seconds(10)); // SIGTERM
```

### DeleteContainerFlags

`Container::Delete()` casts directly to `WslcDeleteContainerFlags`.

Underlying C values:
- `0` none
- `0x01` force

```cpp
container.Delete(static_cast<DeleteContainerFlags>(0x01));
```

### ProcessOutputMode


- `Discard` (default in `winrt_Process.h` and `winrt_ProcessSettings.h`)
- `Event` (`winrt_Process.cpp`)
- `Stream` (`winrt_Process.cpp`, `winrt_Container.cpp`)

Behavior:
- `Discard`: no stdout/stderr events or output streams.
- `Event`: stdout/stderr are delivered by callbacks and `OutputReceived` / `ErrorReceived`.
- `Stream`: `GetOutputStream(...)` can be used.

```cpp
procSettings.OutputMode(ProcessOutputMode::Event);
```

### ProcessOutputHandle

`Process::GetOutputStream(ProcessOutputHandle)` casts directly to `WslcProcessIOHandle`.
The underlying C handles are:
- `0` stdin
- `1` stdout
- `2` stderr



```cpp
auto stdoutStream = process.GetOutputStream(static_cast<ProcessOutputHandle>(1));
```

### ProcessState

`Process::State()` casts directly from `WslcProcessState`.

Underlying C values:
- `Unknown = 0`
- `Running = 1`
- `Exited = 2`
- `Signalled = 3`

```cpp
if (process.State() == static_cast<ProcessState>(1))
{
    // running
}
```

### ImageProgressStatus

`ImageProgress` casts directly from `WslcImageProgressStatus`.

Underlying C values:
- `Unknown = 0`
- `Pulling = 1`
- `Waiting = 2`
- `Downloading = 3`
- `Verifying = 4`
- `Extracting = 5`
- `Complete = 6`

```cpp
auto status = progress.Status();
if (status == static_cast<ImageProgressStatus>(6))
{
    // complete
}
```

### ComponentFlags

`WslcService` converts directly to/from `WslcComponentFlags`.

Underlying C values:
- `0` none
- `1` virtual machine platform
- `2` WSL package
- `4` SDK needs update

\

```cpp
auto missing = WslcService::GetMissingComponents();
if (missing != static_cast<ComponentFlags>(0))
{
    co_await WslcService::InstallWithDependenciesAsync();
}
```

---

## Not Yet Implemented and Known Gaps



| Gap | Details |
|---|---|
| Session crash-dump callbacks | `wslcsdk.h` exposes `WslcRegisterSessionCrashDumpCallback` / `WslcReleaseCrashDumpSubscription`, but no WinRT wrapper source for them is present. |
| Handle-based image import/load | The C API exposes `WslcImportSessionImage` and `WslcLoadSessionImage` from a `HANDLE`; the WinRT wrapper only exposes `ImportImageAsync(path, imageName)` and `LoadImageAsync(path)`. |
| Explicit container start flags | `Container::Start()` takes no parameters. In `winrt_Container.cpp`, the wrapper automatically sets `WSLC_CONTAINER_START_FLAG_ATTACH` when the init process output mode is `Event` or `Stream`. |
| Raw process callback plumbing | The C API exposes `WslcSetProcessSettingsCallbacks`, `WslcGetProcessExitEvent`, and raw I/O handles. The WinRT projection hides that behind `ProcessSettings::OutputMode`, `OutputReceived`, `ErrorReceived`, `Exited`, `GetInputStream`, and `GetOutputStream`. |
| Missing wrapper source files in this drop | `winrt_CMakeLists.txt` references `PullImageOptions`, `PushImageOptions`, `TagImageOptions`, `VhdOptions`, and `ServiceVersion`|

---

## End-to-End Example

The example below shows one full lifecycle matching the C API example:

1. Check prerequisites
2. Print SDK version
3. Create a session (4 CPUs, 4 GB RAM)
4. Pull alpine:latest
5. Configure an init process (`/bin/echo "Hello from WSL Container!"`)
6. Create and start the container
7. Wait for the init process to exit
8. Print exit code
9. Stop and delete the container
10. Terminate the session

```cpp
#include <cstdio>
#include <string>
#include <chrono>
#include <winrt/Microsoft.WSL.Containers.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>

using namespace winrt;
using namespace winrt::Microsoft::WSL::Containers;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Collections;
using namespace std::chrono_literals;

int main()
{
    init_apartment();

    // 0. Check prerequisites
    auto missing = WslcService::GetMissingComponents();
    if (missing != ComponentFlags::None)
    {
        printf("WSL components are missing. Run: wsl --install\n");
        return 1;
    }

    auto ver = WslcService::GetVersion();
    printf("WSL version: %u.%u.%u\n", ver.Major(), ver.Minor(), ver.Revision());

    // 1. Create a session
    SessionSettings sessionSettings{ L"MyApp", L"C:\\WslcData" };
    sessionSettings.CpuCount(4);
    sessionSettings.MemoryMB(4096);

    Session session{ sessionSettings };
    session.Start();

    // 2. Pull an image
    PullImageOptions pullOpts{ L"docker.io/library/alpine:latest" };
    auto pullOp = session.PullImageAsync(pullOpts);
    co_await pullOp;

    // 3. Configure an init process
    ProcessSettings initProcSettings;
    initProcSettings.OutputMode(ProcessOutputMode::Event);
    auto argv = single_threaded_vector<hstring>();
    argv.Append(L"/bin/echo");
    argv.Append(L"Hello from WSL Container!");
    initProcSettings.CmdLine(argv);

    // 4. Configure and create a container
    ContainerSettings containerSettings{ L"alpine:latest" };
    containerSettings.Name(L"hello-container");
    containerSettings.InitProcess(initProcSettings);

    auto container = session.CreateContainer(containerSettings);

    // 5. Subscribe to init process events before starting
    auto initProcess = container.InitProcess();
    auto exitedEvent = handle{ CreateEvent(nullptr, TRUE, FALSE, nullptr) };
    int32_t initExitCode = -1;

    initProcess.OutputReceived([](auto const& data)
    {
        std::string text(data.begin(), data.end());
        printf("%s", text.c_str());
    });
    initProcess.Exited([&](int32_t exitCode)
    {
        initExitCode = exitCode;
        SetEvent(exitedEvent.get());
    });

    // 6. Start the container
    container.Start();

    // 7. Wait for the init process to exit (30-second timeout)
    WaitForSingleObject(exitedEvent.get(), 30000);
    printf("Process exited with code: %d\n", initExitCode);

    // 8. Clean up
    if (container.State() == ContainerState::Running)
    {
        container.Stop(Signal::SigTerm, 10s);
    }
    container.Delete(DeleteContainerFlags::None);
    session.Terminate();

    return 0;
}
```
