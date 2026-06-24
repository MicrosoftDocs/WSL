---
title: WSL container API C# reference
description: C# API reference for the WSL container API (Microsoft.WSL.Containers) used to create sessions, run Linux containers, manage processes, images, and VHD-backed storage on Windows.
keywords: wsl, windows subsystem for linux, container, wslc, Microsoft.WSL.Containers, C# API, csharp, developer reference, sdk
ms.date: 06/24/2026
ms.topic: reference
---

# WSL container API C# reference

This document describes the **C# projection** in the `Microsoft.WSL.Containers` namespace.

---

## Table of Contents

- [Overview](#overview)
- [Projected Namespace](#projected-namespace)
- [Common CsWinRT Type Mappings](#common-cswinrt-type-mappings)
- [Data Classes](#data-classes)
  - [ContainerPortMapping](#containerportmapping)
  - [ContainerVolume](#containervolume)
  - [ContainerNamedVolume](#containernamedvolume)
  - [ImageInfo](#imageinfo)
  - [ImageProgress](#imageprogress)
  - [InstallProgress](#installprogress)
  - [ServiceVersion](#serviceversion)
- [Settings Classes](#settings-classes)
  - [SessionSettings](#sessionsettings)
  - [VhdOptions](#vhdoptions)
  - [PullImageOptions](#pullimageoptions)
  - [PushImageOptions](#pushimageoptions)
  - [TagImageOptions](#tagimageoptions)
  - [ContainerSettings](#containersettings)
  - [ProcessSettings](#processsettings)
- [Core Classes](#core-classes)
  - [Session](#session)
  - [Container](#container)
  - [Process](#process)
- [Service Class](#service-class)
  - [WslcService](#wslcservice)
- [Delegates and Events](#delegates-and-events)
- [Enumerations](#enumerations)
  - [SessionFeatureFlags](#sessionfeatureflags)
  - [SessionTerminationReason](#sessionterminationreason)
  - [ContainerNetworkingMode](#containernetworkingmode)
  - [ContainerFlags](#containerflags)
  - [PortProtocol](#portprotocol)
  - [ContainerState](#containerstate)
  - [Signal](#signal)
  - [DeleteContainerFlags](#deletecontainerflags)
  - [ProcessOutputHandle](#processoutputhandle)
  - [ProcessOutputMode](#processoutputmode)
  - [ProcessState](#processstate)
  - [ImageProgressStatus](#imageprogressstatus)
  - [ComponentFlags](#componentflags)
  - [VhdType](#vhdtype)
- [Known Gaps](#known-gaps)
- [End-to-End Example](#end-to-end-example)

---

## Overview

- The public C# surface mirrors the WinRT surface implemented by the `winrt_*.h` / `winrt_*.cpp` wrappers.

---

## Projected Namespace

```csharp
using Microsoft.WSL.Containers;
```

---

## Common CsWinRT Type Mappings

| WinRT type | C# projection |
|---|---|
| `hstring` | `string` |
| `Windows.Foundation.Uri` | `System.Uri` |
| `Windows.Foundation.TimeSpan` | `System.TimeSpan` |
| `IReference<uint32_t>` | `uint?` |
| `IReference<TimeSpan>` | `TimeSpan?` |
| `IReference<ContainerNetworkingMode>` | `ContainerNetworkingMode?` |
| `IVector<T>` | `IList<T>` |
| `IVectorView<T>` | `IReadOnlyList<T>` |
| `IMap<string, string>` | `IDictionary<string, string>` |
| `Windows.Foundation.DateTime` | `DateTimeOffset` |
| `com_array<uint8_t>` event payload | `byte[]` |
| `Windows.Networking.HostName` | `Windows.Networking.HostName` |
| `IAsyncActionWithProgress<T>` | awaitable WinRT async operation |

---

## Data Classes

### ContainerPortMapping

Represents a published port.

```csharp
using Windows.Networking;

public sealed class ContainerPortMapping
{
    public ContainerPortMapping(ushort windowsPort, ushort containerPort, PortProtocol protocol);

    public ushort WindowsPort { get; set; }
    public ushort ContainerPort { get; set; }
    public PortProtocol Protocol { get; set; }
    public HostName WindowsAddress { get; set; }
}
```

Notes:
- `WindowsAddress` **is implemented**.
- It accepts only `HostNameType.Ipv4` and `HostNameType.Ipv6` values.
- DNS names are rejected.
- `null` means the default host bind address.

Example:

```csharp
using Windows.Networking;

var mapping = new ContainerPortMapping(8080, 80, PortProtocol.TCP)
{
    WindowsAddress = new HostName("127.0.0.1")
};
```

### ContainerVolume

Maps a Windows path into the container.

```csharp
public sealed class ContainerVolume
{
    public ContainerVolume(string windowsPath, string containerPath, bool readOnly);

    public string WindowsPath { get; set; }
    public string ContainerPath { get; set; }
    public bool ReadOnly { get; set; }
}
```

Example:

```csharp
var volume = new ContainerVolume(@"C:\data", "/workspace/data", readOnly: false);
```

### ContainerNamedVolume

Maps a session-managed named VHD volume into the container.

```csharp
public sealed class ContainerNamedVolume
{
    public ContainerNamedVolume(string name, string containerPath, bool readOnly);

    public string Name { get; set; }
    public string ContainerPath { get; set; }
    public bool ReadOnly { get; set; }
}
```

Example:

```csharp
var namedVolume = new ContainerNamedVolume("cache", "/var/cache/app", readOnly: false);
```

### ImageInfo

Metadata returned by `Session.Images`.

```csharp
using Windows.Storage.Streams;

public sealed class ImageInfo
{
    public string Name { get; }
    public IBuffer Sha256 { get; }
    public ulong SizeBytes { get; }
    public DateTimeOffset CreatedTimestamp { get; }
}
```

Example:

```csharp
foreach (var image in session.Images)
{
    Console.WriteLine($"{image.Name} ({image.SizeBytes / 1024 / 1024} MB)");
}
```

### ImageProgress

Progress payload for pull/import/load/push operations.

```csharp
public sealed class ImageProgress
{
    public string Id { get; set; }
    public ImageProgressStatus Status { get; set; }
    public ulong CurrentBytes { get; set; }
    public ulong TotalBytes { get; set; }
}
```

Example:

```csharp
void PrintImageProgress(ImageProgress progress) =>
    Console.WriteLine($"{progress.Status,-12} {progress.Id} {progress.CurrentBytes}/{progress.TotalBytes}");
```

### InstallProgress

Progress payload for dependency installation.

```csharp
public sealed class InstallProgress
{
    public ComponentFlags Component { get; }
    public uint Progress { get; }
    public uint Total { get; }
}
```

Example:

```csharp
void PrintInstallProgress(InstallProgress progress) =>
    Console.WriteLine($"{progress.Component}: {progress.Progress}/{progress.Total}");
```

### ServiceVersion

WSL service version information.

```csharp
public sealed class ServiceVersion
{
    public uint Major { get; }
    public uint Minor { get; }
    public uint Revision { get; }
}
```

Example:

```csharp
var version = WslcService.GetVersion();
Console.WriteLine($"WSL service: {version.Major}.{version.Minor}.{version.Revision}");
```

---

## Settings Classes

### SessionSettings

Configures a session before `Session.Start()`.

```csharp
public sealed class SessionSettings
{
    public SessionSettings(string name, string storagePath);

    public string Name { get; set; }
    public string StoragePath { get; set; }
    public uint? CpuCount { get; set; }
    public uint? MemoryMB { get; set; }
    public TimeSpan? Timeout { get; set; }
    public VhdOptions VhdRequirements { get; set; }
    public SessionFeatureFlags FeatureFlags { get; set; }
}
```

Notes:
- `CpuCount`, `MemoryMB`, and `Timeout` are optional nullable values.
- `Timeout` must be positive and must fit in a `uint32` millisecond count.
- `VhdRequirements` is optional.

Example:

```csharp
var sessionSettings = new SessionSettings("demo-session", @"C:\WslcData")
{
    CpuCount = 4,
    MemoryMB = 4096,
    Timeout = TimeSpan.FromMinutes(5),
    FeatureFlags = SessionFeatureFlags.EnableGpu
};
```

### VhdOptions

Describes a session VHD requirement or a named session VHD volume.

```csharp
public sealed class VhdOptions
{
    public VhdOptions(string name, ulong sizeInBytes, VhdType type);

    public string Name { get; set; }
    public ulong SizeInBytes { get; set; }
    public VhdType Type { get; set; }

    public void SetOwner(uint uid, uint gid);
}
```

Notes:
- Use `SessionSettings.VhdRequirements` for session-level storage requirements.
- Use `Session.CreateVhdVolume(...)` for named session volumes.
- Owner flags are intended for named-volume creation. The C header explicitly says owner flags are rejected by `WslcSetSessionSettingsVhd`.

Example:

```csharp
var vhd = new VhdOptions("cache", 2UL * 1024 * 1024 * 1024, VhdType.Dynamic);
vhd.SetOwner(1000, 1000);
```

### PullImageOptions

```csharp
public sealed class PullImageOptions
{
    public PullImageOptions(string uri);

    public string Uri { get; set; }
    public string RegistryAuth { get; set; }
}
```

Example:

```csharp
var pullOptions = new PullImageOptions("docker.io/library/alpine:latest")
{
    RegistryAuth = string.Empty // optional for public registries
};
```

### PushImageOptions

```csharp
public sealed class PushImageOptions
{
    public PushImageOptions(string image, string registryAuth);

    public string Image { get; set; }
    public string RegistryAuth { get; set; }
}
```

Example:

```csharp
var pushOptions = new PushImageOptions("registry.example.com/demo:latest", authToken);
```

### TagImageOptions

```csharp
public sealed class TagImageOptions
{
    public TagImageOptions(string image, string repository, string tag);

    public string Image { get; set; }
    public string Repository { get; set; }
    public string Tag { get; set; }
}
```

Example:

```csharp
var tagOptions = new TagImageOptions("alpine:latest", "registry.example.com/alpine", "v1");
```

### ContainerSettings

Configures a container before creation.

```csharp
public sealed class ContainerSettings
{
    public ContainerSettings(string imageName);

    public string ImageName { get; set; }
    public string Name { get; set; }
    public ProcessSettings InitProcess { get; set; }
    public ContainerNetworkingMode? NetworkingMode { get; set; }
    public string HostName { get; set; }
    public string DomainName { get; set; }
    public ContainerFlags Flags { get; set; }
    public IList<ContainerPortMapping> PortMappings { get; set; }
    public IList<ContainerVolume> Volumes { get; set; }
    public IList<ContainerNamedVolume> NamedVolumes { get; set; }
}
```

Notes:
- `PortMappings`, `Volumes`, and `NamedVolumes` are mutable collections.
- `InitProcess` is optional.
- `NetworkingMode` is nullable; `null` means “leave default behavior”.

Example:

```csharp
var init = new ProcessSettings
{
    CmdLine = new List<string> { "/bin/sh", "-c", "echo hello from init" },
    OutputMode = ProcessOutputMode.Event
};

var containerSettings = new ContainerSettings("docker.io/library/alpine:latest")
{
    Name = "demo-container",
    InitProcess = init,
    NetworkingMode = ContainerNetworkingMode.Bridged,
    Flags = ContainerFlags.AutoRemove,
    PortMappings = new List<ContainerPortMapping>
    {
        new(8080, 80, PortProtocol.TCP)
    },
    Volumes = new List<ContainerVolume>
    {
        new(@"C:\data", "/workspace/data", false)
    },
    NamedVolumes = new List<ContainerNamedVolume>
    {
        new("cache", "/var/cache/app", false)
    }
};
```

### ProcessSettings

Configures a process before start.

```csharp
public sealed class ProcessSettings
{
    public string WorkingDirectory { get; set; }
    public IList<string> CmdLine { get; set; }
    public IDictionary<string, string> EnvironmentVariables { get; set; }
    public ProcessOutputMode OutputMode { get; set; }
}
```

Notes:
- `CmdLine` must be non-empty before calling `Process.Start()`.
- The init process is started by `Container.Start()`, not by `Process.Start()`.
- `OutputMode.Event` enables `OutputReceived` / `ErrorReceived`.
- `OutputMode.Stream` enables `GetOutputStream(...)`.

Example:

```csharp
var processSettings = new ProcessSettings
{
    WorkingDirectory = "/workspace",
    CmdLine = new List<string> { "/bin/sh", "-c", "env | sort" },
    EnvironmentVariables = new Dictionary<string, string>
    {
        ["DEMO"] = "1",
        ["PATH"] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
    },
    OutputMode = ProcessOutputMode.Event
};
```

---

## Core Classes

### Session

Represents a WSL-backed container host session.

```csharp
public sealed class Session
{
    public Session(SessionSettings settings);

    public IReadOnlyList<ImageInfo> Images { get; }
    public event SessionTerminationHandler Terminated;

    public void Start();
    public void Terminate();
    public Container CreateContainer(ContainerSettings containerSettings);
    public IAsyncActionWithProgress<ImageProgress> PullImageAsync(PullImageOptions options);
    public IAsyncActionWithProgress<ImageProgress> ImportImageAsync(string path, string imageName);
    public IAsyncActionWithProgress<ImageProgress> LoadImageAsync(string path);
    public IAsyncActionWithProgress<ImageProgress> PushImageAsync(PushImageOptions options);
    public void DeleteImage(string nameOrId);
    public void TagImage(TagImageOptions options);
    public void CreateVhdVolume(VhdOptions options);
    public void DeleteVhdVolume(string name);
    public string Authenticate(Uri serverAddress, string username, string password);
}
```

#### Session constructor

```csharp
var session = new Session(sessionSettings);
```

#### Session.Start()

Starts the session VM and registers the internal termination wait.

```csharp
session.Start();
```

#### Session.Terminate()

Terminates the session.

```csharp
session.Terminate();
```

#### Session.CreateContainer(ContainerSettings)

Creates a container object owned by the session.

```csharp
Container container = session.CreateContainer(containerSettings);
```

#### Session.PullImageAsync(PullImageOptions)

Awaitable pull with progress.

```csharp
var pull = session.PullImageAsync(new PullImageOptions("docker.io/library/alpine:latest"));
pull.Progress = (op, progress) =>
    Console.WriteLine($"pull: {progress.Status} {progress.Id} {progress.CurrentBytes}/{progress.TotalBytes}");
await pull;
```

#### Session.ImportImageAsync(string path, string imageName)

Imports an image tarball from a file path.

```csharp
var importOp = session.ImportImageAsync(@"C:\images\demo.tar", "demo:imported");
importOp.Progress = (op, progress) =>
    Console.WriteLine($"import: {progress.Status} {progress.Id}");
await importOp;
```

#### Session.LoadImageAsync(string path)

Loads an image archive from disk.

```csharp
var loadOp = session.LoadImageAsync(@"C:\images\docker-save.tar");
loadOp.Progress = (op, progress) =>
    Console.WriteLine($"load: {progress.Status} {progress.Id}");
await loadOp;
```

#### Session.PushImageAsync(PushImageOptions)

Pushes an image to a registry.

```csharp
var pushOp = session.PushImageAsync(new PushImageOptions("registry.example.com/demo:latest", authToken));
pushOp.Progress = (op, progress) =>
    Console.WriteLine($"push: {progress.Status} {progress.Id}");
await pushOp;
```

#### Session.DeleteImage(string nameOrId)

Deletes an image by name or ID.

```csharp
session.DeleteImage("demo:old");
```

#### Session.TagImage(TagImageOptions)

Applies a new repository/tag to an existing image.

```csharp
session.TagImage(new TagImageOptions("alpine:latest", "registry.example.com/alpine", "v1"));
```

#### Session.CreateVhdVolume(VhdOptions)

Creates a named session VHD volume.

```csharp
var vhd = new VhdOptions("cache", 2UL * 1024 * 1024 * 1024, VhdType.Dynamic);
vhd.SetOwner(1000, 1000);
session.CreateVhdVolume(vhd);
```

#### Session.DeleteVhdVolume(string name)

Deletes a named session VHD volume.

```csharp
session.DeleteVhdVolume("cache");
```

#### Session.Authenticate(Uri, string, string)

Authenticates to a registry and returns an identity token string.

```csharp
string token = session.Authenticate(
    new Uri("https://registry.example.com"),
    "user1",
    "p@ssw0rd");
```

#### Session.Images

Returns a snapshot of images known to the session.

```csharp
foreach (var image in session.Images)
{
    Console.WriteLine(image.Name);
}
```

#### Session.Terminated event

Raised when the session termination event is signaled.

```csharp
session.Terminated += reason =>
    Console.WriteLine($"Session terminated: {reason}");
```

### Container

Represents a container inside a session.

```csharp
public sealed class Container
{
    public string Id { get; }
    public Process InitProcess { get; }
    public ContainerState State { get; }

    public void Start();
    public void Stop(Signal signal, TimeSpan timeout);
    public void Delete(DeleteContainerFlags flags);
    public Process CreateProcess(ProcessSettings newProcessSettings);
    public string Inspect();
}
```

Notes:
- `Start()` has **no flags parameter**.
- If `InitProcess.OutputMode` is `Event` or `Stream`, `Start()` automatically requests native attach.
- `InitProcess` is only available when `ContainerSettings.InitProcess` was configured.

#### Container.Start()

Starts the container and, if configured, attaches the init process handle.

```csharp
container.Start();
```

#### Container.Stop(Signal, TimeSpan)

Stops the container with a signal and timeout.

```csharp
container.Stop(Signal.SIGTERM, TimeSpan.FromSeconds(10));
```

#### Container.Delete(DeleteContainerFlags)

Deletes the container.

```csharp
container.Delete(DeleteContainerFlags.Force);
```

#### Container.CreateProcess(ProcessSettings)

Creates a secondary process object inside the container.

```csharp
var execSettings = new ProcessSettings
{
    CmdLine = new List<string> { "/bin/sh", "-c", "echo secondary process" },
    OutputMode = ProcessOutputMode.Event
};

Process process = container.CreateProcess(execSettings);
```

#### Container.Inspect()

Returns the raw inspect payload as a string.

```csharp
string inspectJson = container.Inspect();
Console.WriteLine(inspectJson);
```

#### Container.Id

Returns the container ID string.

```csharp
Console.WriteLine(container.Id);
```

#### Container.InitProcess

Gets the configured init process object.

```csharp
Process init = container.InitProcess;
```

#### Container.State

Gets the current container state.

```csharp
Console.WriteLine(container.State);
```

### Process

Represents a Linux process in a container.

```csharp
using Windows.Storage.Streams;

public sealed class Process
{
    public uint Pid { get; }
    public ProcessState State { get; }
    public int ExitCode { get; }

    public event ProcessOutputHandler OutputReceived;
    public event ProcessOutputHandler ErrorReceived;
    public event ProcessExitHandler Exited;

    public void Start();
    public void Signal(Signal signal);
    public IInputStream GetOutputStream(ProcessOutputHandle outputHandle);
    public IOutputStream GetInputStream();
}
```

Notes:
- Call `Start()` only for **secondary processes** created by `Container.CreateProcess(...)`.
- The init process is started by `Container.Start()`.
- `OutputReceived` and `ErrorReceived` require `OutputMode.Event`.
- `GetOutputStream(...)` requires `OutputMode.Stream`.
- `Exited` is available for all output modes.

#### Process.Start()

Starts a secondary process.

```csharp
process.Start();
```

#### Process.Signal(Signal)

Signals the process.

```csharp
process.Signal(Signal.SIGTERM);
```

#### Process.GetOutputStream(ProcessOutputHandle)

Gets stdout or stderr as a WinRT input stream.

```csharp
using Windows.Storage.Streams;

using IInputStream stdout = process.GetOutputStream(ProcessOutputHandle.StandardOutput);
using var reader = new DataReader(stdout);
await reader.LoadAsync(4096);
string text = reader.ReadString(reader.UnconsumedBufferLength);
Console.WriteLine(text);
```

#### Process.GetInputStream()

Gets stdin as a WinRT output stream.

```csharp
using Windows.Storage.Streams;

using IOutputStream stdin = process.GetInputStream();
using var writer = new DataWriter(stdin);
writer.WriteString("hello from C#\n");
await writer.StoreAsync();
await writer.FlushAsync();
```

#### Process.Pid

```csharp
Console.WriteLine($"PID: {process.Pid}");
```

#### Process.State

```csharp
Console.WriteLine($"State: {process.State}");
```

#### Process.ExitCode

Valid after exit.

```csharp
Console.WriteLine($"Exit code: {process.ExitCode}");
```

#### Process.OutputReceived event

```csharp
using System.Text;

process.OutputReceived += data =>
    Console.Write(Encoding.UTF8.GetString(data));
```

#### Process.ErrorReceived event

```csharp
using System.Text;

process.ErrorReceived += data =>
    Console.Error.Write(Encoding.UTF8.GetString(data));
```

#### Process.Exited event

```csharp
process.Exited += exitCode =>
    Console.WriteLine($"Process exited with {exitCode}");
```

---

## Service Class

### WslcService

Static entry point for service-level operations.

```csharp
public static class WslcService
{
    public static ComponentFlags GetMissingComponents();
    public static ServiceVersion GetVersion();
    public static IAsyncActionWithProgress<InstallProgress> InstallWithDependenciesAsync();
}
```

#### WslcService.GetMissingComponents()

```csharp
ComponentFlags missing = WslcService.GetMissingComponents();
if (missing == ComponentFlags.None)
{
    Console.WriteLine("All required components are installed.");
}
else
{
    Console.WriteLine($"Missing: {missing}");
}
```

#### WslcService.GetVersion()

```csharp
ServiceVersion version = WslcService.GetVersion();
Console.WriteLine($"{version.Major}.{version.Minor}.{version.Revision}");
```

#### WslcService.InstallWithDependenciesAsync()

```csharp
var install = WslcService.InstallWithDependenciesAsync();
install.Progress = (op, progress) =>
    Console.WriteLine($"install: {progress.Component} {progress.Progress}/{progress.Total}");
await install;
```

---

## Delegates and Events

The WinRT delegates project to normal C# delegates and are consumed as normal C# events.

```csharp
public delegate void SessionTerminationHandler(SessionTerminationReason reason);
public delegate void ProcessOutputHandler(byte[] data);
public delegate void ProcessExitHandler(int exitCode);
```

Typical event usage:

```csharp
using System.Text;

session.Terminated += reason => Console.WriteLine($"Session ended: {reason}");
container.InitProcess.OutputReceived += data => Console.Write(Encoding.UTF8.GetString(data));
container.InitProcess.ErrorReceived += data => Console.Error.Write(Encoding.UTF8.GetString(data));
container.InitProcess.Exited += code => Console.WriteLine($"Init exited: {code}");
```

---

## Enumerations

### SessionFeatureFlags

```csharp
[Flags]
public enum SessionFeatureFlags : uint
{
    None = 0,
    EnableGpu = 0x00000004
}
```

### SessionTerminationReason

```csharp
public enum SessionTerminationReason
{
    Unknown = 0,
    Shutdown = 1,
    Crashed = 2
}
```

### ContainerNetworkingMode

```csharp
public enum ContainerNetworkingMode
{
    None = 0,
    Bridged = 1
}
```

### ContainerFlags

```csharp
[Flags]
public enum ContainerFlags : uint
{
    None = 0,
    AutoRemove = 0x00000001,
    EnableGpu = 0x00000002,
    Privileged = 0x00000004
}
```

### PortProtocol

```csharp
public enum PortProtocol
{
    TCP = 0,
    UDP = 1
}
```

### ContainerState

```csharp
public enum ContainerState
{
    Invalid = 0,
    Created = 1,
    Running = 2,
    Exited = 3,
    Deleted = 4
}
```

### Signal

```csharp
public enum Signal
{
    None = 0,
    SIGHUP = 1,
    SIGINT = 2,
    SIGQUIT = 3,
    SIGKILL = 9,
    SIGTERM = 15
}
```

### DeleteContainerFlags

```csharp
[Flags]
public enum DeleteContainerFlags : uint
{
    None = 0,
    Force = 0x00000001
}
```

### ProcessOutputHandle

Only stdout/stderr are modeled here. Stdin is accessed through `Process.GetInputStream()`.

```csharp
public enum ProcessOutputHandle
{
    StandardOutput = 1,
    StandardError = 2
}
```

### ProcessOutputMode

```csharp
public enum ProcessOutputMode
{
    Discard = 0,
    Stream = 1,
    Event = 2
}
```

### ProcessState

```csharp
public enum ProcessState
{
    Unknown = 0,
    Running = 1,
    Exited = 2,
    Signalled = 3
}
```

### ImageProgressStatus

```csharp
public enum ImageProgressStatus
{
    Unknown = 0,
    Pulling = 1,
    Waiting = 2,
    Downloading = 3,
    Verifying = 4,
    Extracting = 5,
    Complete = 6
}
```

### ComponentFlags

```csharp
[Flags]
public enum ComponentFlags : uint
{
    None = 0,
    VirtualMachinePlatform = 1,
    WslPackage = 2,
    SdkNeedsUpdate = 4
}
```

### VhdType

```csharp
public enum VhdType
{
    Dynamic = 0,
    Fixed = 1
}
```

> `wslcsdk.h` notes that `Fixed` is only honored for `WslcCreateSessionVhdVolume`. Session boot-disk requirements use the same underlying struct, but owner flags are explicitly rejected there.

---

## Known Gaps

These C API features are **not** available through the WinRT/C# projection:

| C API feature | C# status |
|---|---|
| `WslcRegisterSessionCrashDumpCallback`, `WslcReleaseCrashDumpSubscription`, `WslcSessionCrashDumpInfo` | **Not projected.** Crash dump callbacks are available only in the native C API. |
| `WslcImportSessionImage(...)` and `WslcLoadSessionImage(...)` overloads that take raw `HANDLE` + byte count | **Not projected.** C# only exposes file-path-based `ImportImageAsync(string path, string imageName)` and `LoadImageAsync(string path)`. |
| Raw native handles (`WslcGetSessionTerminationEvent`, `WslcGetProcessExitEvent`, `WslcGetProcessIOHandle`) | **Wrapped, not exposed directly.** Use C# events and WinRT streams instead. |
| `WslcProcessCallbacks` registration surface | **Wrapped as events.** Use `OutputReceived`, `ErrorReceived`, and `Exited`. |
| `WslcContainerStartFlags` | **Not exposed directly.** `Container.Start()` automatically sets `ATTACH` when the init process uses `ProcessOutputMode.Event` or `ProcessOutputMode.Stream`. |

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

```csharp
using Microsoft.WSL.Containers;
using System;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static async Task<int> Main()
    {
        // 0. Check prerequisites
        var missing = WslcService.GetMissingComponents();
        if (missing != ComponentFlags.None)
        {
            Console.WriteLine("WSL components are missing. Run: wsl --install");
            return 1;
        }

        var ver = WslcService.GetVersion();
        Console.WriteLine($"WSL version: {ver.Major}.{ver.Minor}.{ver.Revision}");

        // 1. Create a session
        var sessionSettings = new SessionSettings("MyApp", @"C:\WslcData")
        {
            CpuCount = 4,
            MemoryMB = 4096
        };

        var session = new Session(sessionSettings);
        session.Start();

        // 2. Pull an image
        var pullOp = session.PullImageAsync(new PullImageOptions("docker.io/library/alpine:latest"));
        pullOp.Progress = (op, progress) =>
            Console.WriteLine($"Pull: {progress.Status} {progress.CurrentBytes}/{progress.TotalBytes}");
        await pullOp;

        // 3. Configure an init process
        var initProcSettings = new ProcessSettings
        {
            CmdLine = new[] { "/bin/echo", "Hello from WSL Container!" },
            OutputMode = ProcessOutputMode.Event
        };

        // 4. Configure and create a container
        var containerSettings = new ContainerSettings("alpine:latest")
        {
            Name = "hello-container",
            InitProcess = initProcSettings
        };

        var container = session.CreateContainer(containerSettings);

        // 5. Subscribe to init process events before starting
        var exited = new TaskCompletionSource<int>(TaskCreationOptions.RunContinuationsAsynchronously);

        container.InitProcess.OutputReceived += data =>
            Console.Write(Encoding.UTF8.GetString(data));
        container.InitProcess.Exited += code =>
            exited.TrySetResult(code);

        // 6. Start the container
        container.Start();

        // 7. Wait for the init process to exit (30-second timeout)
        var completed = await Task.WhenAny(exited.Task, Task.Delay(TimeSpan.FromSeconds(30)));
        int exitCode = completed == exited.Task ? exited.Task.Result : -1;
        Console.WriteLine($"Process exited with code: {exitCode}");

        // 8. Clean up
        if (container.State == ContainerState.Running)
        {
            container.Stop(Signal.SigTerm, TimeSpan.FromSeconds(10));
        }
        container.Delete(DeleteContainerFlags.None);
        session.Terminate();

        return exitCode;
    }
}
```
