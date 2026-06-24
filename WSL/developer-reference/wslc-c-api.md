---
title: WSL container API C reference
description: C API reference for the WSL container API (wslcsdk.h) used to create sessions, run Linux containers, manage processes, images, and VHD-backed storage on Windows.
keywords: wsl, windows subsystem for linux, container, wslc, wslcsdk, C API, developer reference, sdk
ms.date: 06/24/2026
ms.topic: reference
---

# WSL container API C reference

The WSL container API exposes a C API for creating sessions, creating containers inside those sessions, starting processes, managing images, managing VHD-backed storage, and checking/installing required platform components.

> **Header:** `wslcsdk.h`
>
> **Library:** `wslcsdk.lib` / `wslcsdk.dll`
>
> **PREVIEW NOTICE:** This API is currently in preview and is subject to breaking changes in future releases without prior notice. Do not rely on API stability for production workloads. Features, function signatures, and behaviors may change between releases during the preview period.

---

## Table of Contents

- [Structures](#structures)
  - [Handle Types](#handle-types)
  - [Constants](#constants)
  - [WslcSessionSettings](#wslcsessionsettings)
  - [WslcContainerSettings](#wslccontainersettings)
  - [WslcProcessSettings](#wslcprocesssettings)
  - [WslcVhdRequirements](#wslcvhdrequirements)
  - [WslcSessionCrashDumpInfo](#wslcsessioncrashdumpinfo)
  - [WslcContainerPortMapping](#wslccontainerportmapping)
  - [WslcContainerVolume](#wslccontainervolume)
  - [WslcContainerNamedVolume](#wslccontainernamedvolume)
  - [WslcProcessCallbacks](#wslcprocesscallbacks)
  - [WslcImageProgressDetail](#wslcimageprogressdetail)
  - [WslcImageProgressMessage](#wslcimageprogressmessage)
  - [WslcPullImageOptions](#wslcpullimageoptions)
  - [WslcImportImageOptions](#wslcimportimageoptions)
  - [WslcLoadImageOptions](#wslcloadimageoptions)
  - [WslcImageInfo](#wslcimageinfo)
  - [WslcTagImageOptions](#wslctagimageoptions)
  - [WslcPushImageOptions](#wslcpushimageoptions)
  - [WslcVersion](#wslcversion)
- [Callback Types](#callback-types)
  - [WslcSessionCrashDumpCallback](#wslcsessioncrashdumpcallback)
  - [WslcStdIOCallback](#wslcstdiocallback)
  - [WslcProcessExitCallback](#wslcprocessexitcallback)
  - [WslcContainerImageProgressCallback](#wslccontainerimageprogresscallback)
  - [WslcInstallCallback](#wslcinstallcallback)
- [Session APIs](#session-apis)
  - [WslcInitSessionSettings](#wslcinitsessionsettings)
  - [WslcCreateSession](#wslccreatesession)
  - [WslcSetSessionSettingsCpuCount](#wslcsetsessionsettingscpucount)
  - [WslcSetSessionSettingsMemory](#wslcsetsessionsettingsmemory)
  - [WslcSetSessionSettingsTimeout](#wslcsetsessionsettingstimeout)
  - [WslcSetSessionSettingsVhd](#wslcsetsessionsettingsvhd)
  - [WslcSetSessionSettingsFeatureFlags](#wslcsetsessionsettingsfeatureflags)
  - [WslcGetSessionTerminationEvent](#wslcgetsessionterminationevent)
  - [WslcGetSessionTerminationReason](#wslcgetsessionterminationreason)
  - [WslcRegisterSessionCrashDumpCallback](#wslcregistersessioncrashdumpcallback)
  - [WslcReleaseCrashDumpSubscription](#wslcreleasecrashdumpsubscription)
  - [WslcTerminateSession](#wslcterminatesession)
  - [WslcReleaseSession](#wslcreleasesession)
  - [WslcSessionAuthenticate](#wslcsessionauthenticate)
- [Container APIs](#container-apis)
  - [WslcInitContainerSettings](#wslcinitcontainersettings)
  - [WslcCreateContainer](#wslccreatecontainer)
  - [WslcStartContainer](#wslcstartcontainer)
  - [WslcSetContainerSettingsName](#wslcsetcontainersettingsname)
  - [WslcSetContainerSettingsInitProcess](#wslcsetcontainersettingsinitprocess)
  - [WslcSetContainerSettingsNetworkingMode](#wslcsetcontainersettingsnetworkingmode)
  - [WslcSetContainerSettingsHostName](#wslcsetcontainersettingshostname)
  - [WslcSetContainerSettingsDomainName](#wslcsetcontainersettingsdomainname)
  - [WslcSetContainerSettingsFlags](#wslcsetcontainersettingsflags)
  - [WslcSetContainerSettingsPortMappings](#wslcsetcontainersettingsportmappings)
  - [WslcSetContainerSettingsVolumes](#wslcsetcontainersettingsvolumes)
  - [WslcSetContainerSettingsNamedVolumes](#wslcsetcontainersettingsnamedvolumes)
  - [WslcCreateContainerProcess](#wslccreatecontainerprocess)
  - [WslcGetContainerID](#wslcgetcontainerid)
  - [WslcGetContainerInitProcess](#wslcgetcontainerinitprocess)
  - [WslcInspectContainer](#wslcinspectcontainer)
  - [WslcGetContainerState](#wslcgetcontainerstate)
  - [WslcStopContainer](#wslcstopcontainer)
  - [WslcDeleteContainer](#wslcdeletecontainer)
  - [WslcReleaseContainer](#wslcreleasecontainer)
- [Process APIs](#process-apis)
  - [WslcInitProcessSettings](#wslcinitprocesssettings)
  - [WslcSetProcessSettingsWorkingDirectory](#wslcsetprocesssettingsworkingdirectory)
  - [WslcSetProcessSettingsCmdLine](#wslcsetprocesssettingscmdline)
  - [WslcSetProcessSettingsEnvVariables](#wslcsetprocesssettingsenvvariables)
  - [WslcSetProcessSettingsCallbacks](#wslcsetprocesssettingscallbacks)
  - [WslcGetProcessPid](#wslcgetprocesspid)
  - [WslcGetProcessExitEvent](#wslcgetprocessexitevent)
  - [WslcGetProcessState](#wslcgetprocessstate)
  - [WslcGetProcessExitCode](#wslcgetprocessexitcode)
  - [WslcSignalProcess](#wslcsignalprocess)
  - [WslcGetProcessIOHandle](#wslcgetprocessiohandle)
  - [WslcReleaseProcess](#wslcreleaseprocess)
- [Image APIs](#image-apis)
  - [WslcPullSessionImage](#wslcpullsessionimage)
  - [WslcImportSessionImage](#wslcimportsessionimage)
  - [WslcImportSessionImageFromFile](#wslcimportsessionimagefromfile)
  - [WslcLoadSessionImage](#wslcloadsessionimage)
  - [WslcLoadSessionImageFromFile](#wslcloadsessionimagefromfile)
  - [WslcDeleteSessionImage](#wslcdeletesessionimage)
  - [WslcListSessionImages](#wslclistsessionimages)
  - [WslcTagSessionImage](#wslctagsessionimage)
  - [WslcPushSessionImage](#wslcpushsessionimage)
- [Storage APIs](#storage-apis)
  - [WslcCreateSessionVhdVolume](#wslccreatesessionvhdvolume)
  - [WslcDeleteSessionVhdVolume](#wslcdeletesessionvhdvolume)
- [Install and Version APIs](#install-and-version-apis)
  - [WslcGetMissingComponents](#wslcgetmissingcomponents)
  - [WslcGetVersion](#wslcgetversion)
  - [WslcInstallWithDependencies](#wslcinstallwithdependencies)
  - [DllMain](#dllmain)
  - [DllGetActivationFactory](#dllgetactivationfactory)
  - [DllCanUnloadNow](#dllcanunloadnow)
- [Enumerations](#enumerations)
  - [WslcContainerNetworkingMode](#wslccontainernetworkingmode)
  - [WslcVhdType](#wslcvhdtype)
  - [WslcVhdRequirementsFlags](#wslcvhdrequirementsflags)
  - [WslcSessionFeatureFlags](#wslcsessionfeatureflags)
  - [WslcSessionTerminationReason](#wslcsessionterminationreason)
  - [WslcPortProtocol](#wslcportprotocol)
  - [WslcContainerFlags](#wslccontainerflags)
  - [WslcContainerStartFlags](#wslccontainerstartflags)
  - [WslcContainerState](#wslccontainerstate)
  - [WslcSignal](#wslcsignal)
  - [WslcDeleteContainerFlags](#wslcdeletecontainerflags)
  - [WslcProcessIOHandle](#wslcprocessiohandle)
  - [WslcProcessState](#wslcprocessstate)
  - [WslcImageProgressStatus](#wslcimageprogressstatus)
  - [WslcComponentFlags](#wslccomponentflags)
- [Error Codes](#error-codes)
- [Not Yet Implemented APIs](#not-yet-implemented-apis)
- [End-to-End Example](#end-to-end-example)

---

## Structures

### Handle Types

The header declares these opaque handles:

```c
DECLARE_HANDLE(WslcSession);
DECLARE_HANDLE(WslcContainer);
DECLARE_HANDLE(WslcProcess);
DECLARE_HANDLE(WslcCrashDumpSubscription);
```

### Constants

```c
#define WSLC_SESSION_OPTIONS_SIZE 72
#define WSLC_SESSION_OPTIONS_ALIGNMENT 8
#define WSLC_CONTAINER_OPTIONS_SIZE 104
#define WSLC_CONTAINER_OPTIONS_ALIGNMENT 8
#define WSLC_CONTAINER_PROCESS_OPTIONS_SIZE 72
#define WSLC_CONTAINER_PROCESS_OPTIONS_ALIGNMENT 8
#define WSLC_CONTAINER_ID_BUFFER_SIZE 65
#define WSLC_IMAGE_NAME_LENGTH 256
```

| Constant | Value |
|---|---|
| `WSLC_SESSION_OPTIONS_SIZE` | `72` |
| `WSLC_SESSION_OPTIONS_ALIGNMENT` | `8` |
| `WSLC_CONTAINER_OPTIONS_SIZE` | `104` |
| `WSLC_CONTAINER_OPTIONS_ALIGNMENT` | `8` |
| `WSLC_CONTAINER_PROCESS_OPTIONS_SIZE` | `72` |
| `WSLC_CONTAINER_PROCESS_OPTIONS_ALIGNMENT` | `8` |
| `WSLC_CONTAINER_ID_BUFFER_SIZE` | `65` |
| `WSLC_IMAGE_NAME_LENGTH` | `256` |

### WslcSessionSettings

```c
typedef struct WslcSessionSettings
{
    __declspec(align(WSLC_SESSION_OPTIONS_ALIGNMENT)) BYTE _opaque[WSLC_SESSION_OPTIONS_SIZE];
} WslcSessionSettings;
```

### WslcContainerSettings

```c
typedef struct WslcContainerSettings
{
    __declspec(align(WSLC_CONTAINER_OPTIONS_ALIGNMENT)) BYTE _opaque[WSLC_CONTAINER_OPTIONS_SIZE];
} WslcContainerSettings;
```

### WslcProcessSettings

```c
typedef struct WslcProcessSettings
{
    __declspec(align(WSLC_CONTAINER_PROCESS_OPTIONS_ALIGNMENT)) BYTE _opaque[WSLC_CONTAINER_PROCESS_OPTIONS_SIZE];
} WslcProcessSettings;
```

### WslcVhdRequirements

```c
typedef struct WslcVhdRequirements
{
    _In_z_ PCSTR name;
    _In_ uint64_t sizeBytes; // Desired size (for create/expand)
    _In_ WslcVhdType type;
    _In_ WslcVhdRequirementsFlags flags;
    _In_ uint32_t uid; // honored iff (flags & WSLC_VHD_REQ_FLAG_OWNER)
    _In_ uint32_t gid; // honored iff (flags & WSLC_VHD_REQ_FLAG_OWNER)
} WslcVhdRequirements;
```

| Field | Type |
|---|---|
| `name` | `PCSTR` |
| `sizeBytes` | `uint64_t` |
| `type` | `WslcVhdType` |
| `flags` | `WslcVhdRequirementsFlags` |
| `uid` | `uint32_t` |
| `gid` | `uint32_t` |

Header notes:

- `name` is ignored by `WslcSetSessionSettingsVhd`.
- The remaining fields after `type` are only honored by `WslcCreateSessionVhdVolume`.
- `WslcSetSessionSettingsVhd` rejects non-`NONE` flags with `E_INVALIDARG`.

### WslcSessionCrashDumpInfo

```c
typedef struct WslcSessionCrashDumpInfo
{
    _Field_z_ PCWSTR dumpPath;
    _Field_z_ PCSTR processName;
    uint64_t pid;
    uint32_t signal;
    uint64_t timestamp;
} WslcSessionCrashDumpInfo;
```

| Field | Type |
|---|---|
| `dumpPath` | `PCWSTR` |
| `processName` | `PCSTR` |
| `pid` | `uint64_t` |
| `signal` | `uint32_t` |
| `timestamp` | `uint64_t` |

### WslcContainerPortMapping

```c
typedef struct WslcContainerPortMapping
{
    _In_ uint16_t windowsPort;      // Port on Windows host
    _In_ uint16_t containerPort;    // Port inside container
    _In_ WslcPortProtocol protocol; // TCP or UDP

    // if you want to override the default binding address
    _In_opt_ struct sockaddr_storage* windowsAddress; // accepts ipv4/6
} WslcContainerPortMapping;
```

| Field | Type |
|---|---|
| `windowsPort` | `uint16_t` |
| `containerPort` | `uint16_t` |
| `protocol` | `WslcPortProtocol` |
| `windowsAddress` | `struct sockaddr_storage*` |

### WslcContainerVolume

```c
typedef struct WslcContainerVolume
{
    _In_z_ PCWSTR windowsPath;
    _In_z_ PCSTR containerPath;
    _In_ BOOL readOnly;
} WslcContainerVolume;
```

| Field | Type |
|---|---|
| `windowsPath` | `PCWSTR` |
| `containerPath` | `PCSTR` |
| `readOnly` | `BOOL` |

### WslcContainerNamedVolume

```c
typedef struct WslcContainerNamedVolume
{
    _In_z_ PCSTR name;          // Name of the session volume (from WslcVhdRequirements.name)
    _In_z_ PCSTR containerPath; // Absolute path inside the container
    _In_ BOOL readOnly;
} WslcContainerNamedVolume;
```

| Field | Type |
|---|---|
| `name` | `PCSTR` |
| `containerPath` | `PCSTR` |
| `readOnly` | `BOOL` |

### WslcProcessCallbacks

```c
typedef struct WslcProcessCallbacks
{
    WslcStdIOCallback onStdOut;
    WslcStdIOCallback onStdErr;
    WslcProcessExitCallback onExit;
} WslcProcessCallbacks;
```

| Field | Type |
|---|---|
| `onStdOut` | `WslcStdIOCallback` |
| `onStdErr` | `WslcStdIOCallback` |
| `onExit` | `WslcProcessExitCallback` |

### WslcImageProgressDetail

```c
typedef struct WslcImageProgressDetail
{
    _Out_ uint64_t currentBytes; // bytes downloaded so far
    _Out_ uint64_t totalBytes;   // total bytes expected
} WslcImageProgressDetail;
```

| Field | Type |
|---|---|
| `currentBytes` | `uint64_t` |
| `totalBytes` | `uint64_t` |

### WslcImageProgressMessage

```c
typedef struct WslcImageProgressMessage
{
    _Out_ PCSTR id;                       // layer ID or digest
    _Out_ WslcImageProgressStatus status; // "Downloading", "Extracting", etc.
    _Out_ WslcImageProgressDetail detail;
} WslcImageProgressMessage;
```

| Field | Type |
|---|---|
| `id` | `PCSTR` |
| `status` | `WslcImageProgressStatus` |
| `detail` | `WslcImageProgressDetail` |

### WslcPullImageOptions

```c
typedef struct WslcPullImageOptions
{
    _In_z_ PCSTR uri;
    WslcContainerImageProgressCallback progressCallback;
    PVOID progressCallbackContext;
    _In_opt_z_ PCSTR registryAuth;
} WslcPullImageOptions;
```

| Field | Type |
|---|---|
| `uri` | `PCSTR` |
| `progressCallback` | `WslcContainerImageProgressCallback` |
| `progressCallbackContext` | `PVOID` |
| `registryAuth` | `PCSTR` |

### WslcImportImageOptions

```c
typedef struct WslcImportImageOptions
{
    _In_opt_ WslcContainerImageProgressCallback progressCallback;
    _In_opt_ PVOID progressCallbackContext;
} WslcImportImageOptions;
```

| Field | Type |
|---|---|
| `progressCallback` | `WslcContainerImageProgressCallback` |
| `progressCallbackContext` | `PVOID` |

### WslcLoadImageOptions

```c
typedef struct WslcLoadImageOptions
{
    _In_opt_ WslcContainerImageProgressCallback progressCallback;
    _In_opt_ PVOID progressCallbackContext;
} WslcLoadImageOptions;
```

| Field | Type |
|---|---|
| `progressCallback` | `WslcContainerImageProgressCallback` |
| `progressCallbackContext` | `PVOID` |

### WslcImageInfo

```c
typedef struct WslcImageInfo
{
    CHAR name[WSLC_IMAGE_NAME_LENGTH];
    uint8_t sha256[32];
    int64_t sizeBytes;
    uint64_t createdUnixTime;
} WslcImageInfo;
```

| Field | Type |
|---|---|
| `name` | `CHAR[WSLC_IMAGE_NAME_LENGTH]` |
| `sha256` | `uint8_t[32]` |
| `sizeBytes` | `int64_t` |
| `createdUnixTime` | `uint64_t` |

### WslcTagImageOptions

```c
typedef struct WslcTagImageOptions
{
    _In_z_ PCSTR image; // Source image name or ID.
    _In_z_ PCSTR repo;  // Target repository name.
    _In_z_ PCSTR tag;   // Target tag name.
} WslcTagImageOptions;
```

| Field | Type |
|---|---|
| `image` | `PCSTR` |
| `repo` | `PCSTR` |
| `tag` | `PCSTR` |

### WslcPushImageOptions

```c
typedef struct WslcPushImageOptions
{
    _In_z_ PCSTR image;
    _In_z_ PCSTR registryAuth; // Base64-encoded X-Registry-Auth header value.
    _In_opt_ WslcContainerImageProgressCallback progressCallback;
    _In_opt_ PVOID progressCallbackContext;
} WslcPushImageOptions;
```

| Field | Type |
|---|---|
| `image` | `PCSTR` |
| `registryAuth` | `PCSTR` |
| `progressCallback` | `WslcContainerImageProgressCallback` |
| `progressCallbackContext` | `PVOID` |

### WslcVersion

```c
typedef struct WslcVersion
{
    uint32_t major;
    uint32_t minor;
    uint32_t revision;
} WslcVersion;
```

| Field | Type |
|---|---|
| `major` | `uint32_t` |
| `minor` | `uint32_t` |
| `revision` | `uint32_t` |

---

## Callback Types

### WslcSessionCrashDumpCallback

```c
typedef __callback void(CALLBACK* WslcSessionCrashDumpCallback)(_In_ const WslcSessionCrashDumpInfo* info, _In_opt_ PVOID context);
```

Parameters:

| Parameter | Type |
|---|---|
| `info` | `const WslcSessionCrashDumpInfo*` |
| `context` | `PVOID` |

### WslcStdIOCallback

```c
typedef __callback void(CALLBACK* WslcStdIOCallback)(
    WslcProcessIOHandle ioHandle, _In_reads_bytes_(dataBytes) const BYTE* data, _In_ uint32_t dataBytes, _In_opt_ PVOID context);
```

Header notes:

- Only `STDOUT` and `STDERR` receive callbacks.
- `data` is owned by WSLC and is only valid during the callback.
- The buffer is not null-terminated.
- The callback should return promptly.

### WslcProcessExitCallback

```c
typedef __callback void(CALLBACK* WslcProcessExitCallback)(INT32 exitCode, _In_opt_ PVOID context);
```

| Parameter | Type |
|---|---|
| `exitCode` | `INT32` |
| `context` | `PVOID` |

### WslcContainerImageProgressCallback

```c
typedef HRESULT(CALLBACK* WslcContainerImageProgressCallback)(const WslcImageProgressMessage* progress, PVOID context);
```

| Parameter | Type |
|---|---|
| `progress` | `const WslcImageProgressMessage*` |
| `context` | `PVOID` |

### WslcInstallCallback

```c
typedef __callback void(CALLBACK* WslcInstallCallback)(
    _In_ WslcComponentFlags component, _In_ uint32_t progressSteps, _In_ uint32_t totalSteps, _In_opt_ PVOID context);
```

| Parameter | Type |
|---|---|
| `component` | `WslcComponentFlags` |
| `progressSteps` | `uint32_t` |
| `totalSteps` | `uint32_t` |
| `context` | `PVOID` |

---

## Session APIs

### WslcInitSessionSettings

```c
STDAPI WslcInitSessionSettings(_In_ PCWSTR name, _In_ PCWSTR storagePath, _Out_ WslcSessionSettings* sessionSettings);
```

| Parameter | Type | Direction |
|---|---|---|
| `name` | `PCWSTR` | in |
| `storagePath` | `PCWSTR` | in |
| `sessionSettings` | `WslcSessionSettings*` | out |

Return value: `HRESULT`.

Example:

```c
WslcSessionSettings sessionSettings;
HRESULT hr = WslcInitSessionSettings(
    L"demo-session",
    L"C:\\WSLC\\demo-session",
    &sessionSettings);
```

### WslcCreateSession

```c
STDAPI WslcCreateSession(_In_ WslcSessionSettings* sessionSettings, _Out_ WslcSession* session, _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `sessionSettings` | `WslcSessionSettings*` | in |
| `session` | `WslcSession*` | out |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Example:

```c
WslcSession session = NULL;
HRESULT hr = WslcCreateSession(&sessionSettings, &session, NULL);
```

### WslcSetSessionSettingsCpuCount

```c
STDAPI WslcSetSessionSettingsCpuCount(_In_ WslcSessionSettings* sessionSettings, _In_ uint32_t cpuCount);
```

| Parameter | Type | Direction |
|---|---|---|
| `sessionSettings` | `WslcSessionSettings*` | in |
| `cpuCount` | `uint32_t` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcSetSessionSettingsCpuCount(&sessionSettings, (uint32_t)4);
```

### WslcSetSessionSettingsMemory

```c
STDAPI WslcSetSessionSettingsMemory(_In_ WslcSessionSettings* sessionSettings, _In_ uint32_t memoryMB);
```

| Parameter | Type | Direction |
|---|---|---|
| `sessionSettings` | `WslcSessionSettings*` | in |
| `memoryMB` | `uint32_t` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcSetSessionSettingsMemory(&sessionSettings, (uint32_t)4096);
```

### WslcSetSessionSettingsTimeout

```c
STDAPI WslcSetSessionSettingsTimeout(_In_ WslcSessionSettings* sessionSettings, _In_ uint32_t timeoutMS);
```

| Parameter | Type | Direction |
|---|---|---|
| `sessionSettings` | `WslcSessionSettings*` | in |
| `timeoutMS` | `uint32_t` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcSetSessionSettingsTimeout(&sessionSettings, (uint32_t)120000);
```

### WslcSetSessionSettingsVhd

```c
STDAPI WslcSetSessionSettingsVhd(_In_ WslcSessionSettings* sessionSettings, _In_opt_ const WslcVhdRequirements* vhdRequirements);
```

| Parameter | Type | Direction |
|---|---|---|
| `sessionSettings` | `WslcSessionSettings*` | in |
| `vhdRequirements` | `const WslcVhdRequirements*` | in, optional |

Return value: `HRESULT`.

Header notes:

- `WslcSetSessionSettingsVhd` rejects non-`NONE` flags with `E_INVALIDARG`.
- `WSLC_VHD_TYPE_FIXED` is only honored by `WslcCreateSessionVhdVolume`.

Example:

```c
WslcVhdRequirements vhdRequirements = { 0 };
vhdRequirements.name = "ignored-by-WslcSetSessionSettingsVhd";
vhdRequirements.sizeBytes = (uint64_t)64 * 1024 * 1024 * 1024;
vhdRequirements.type = WSLC_VHD_TYPE_DYNAMIC;
vhdRequirements.flags = WSLC_VHD_REQ_FLAG_NONE;
vhdRequirements.uid = (uint32_t)0;
vhdRequirements.gid = (uint32_t)0;

HRESULT hr = WslcSetSessionSettingsVhd(&sessionSettings, &vhdRequirements);
```

### WslcSetSessionSettingsFeatureFlags

```c
STDAPI WslcSetSessionSettingsFeatureFlags(_In_ WslcSessionSettings* sessionSettings, _In_ WslcSessionFeatureFlags flags);
```

| Parameter | Type | Direction |
|---|---|---|
| `sessionSettings` | `WslcSessionSettings*` | in |
| `flags` | `WslcSessionFeatureFlags` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcSetSessionSettingsFeatureFlags(
    &sessionSettings,
    WSLC_SESSION_FEATURE_FLAG_ENABLE_GPU);
```

### WslcGetSessionTerminationEvent

```c
STDAPI WslcGetSessionTerminationEvent(_In_ WslcSession session, _Out_ HANDLE* terminationEvent);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `terminationEvent` | `HANDLE*` | out |

Return value: `HRESULT`.

Example:

```c
HANDLE terminationEvent = NULL;
HRESULT hr = WslcGetSessionTerminationEvent(session, &terminationEvent);
if (SUCCEEDED(hr))
{
    WaitForSingleObject(terminationEvent, 1000);
}
```

### WslcGetSessionTerminationReason

```c
STDAPI WslcGetSessionTerminationReason(_In_ WslcSession session, _Out_ WslcSessionTerminationReason* reason);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `reason` | `WslcSessionTerminationReason*` | out |

Return value: `HRESULT`.

Example:

```c
WslcSessionTerminationReason reason = WSLC_SESSION_TERMINATION_REASON_UNKNOWN;
HRESULT hr = WslcGetSessionTerminationReason(session, &reason);
```

### WslcRegisterSessionCrashDumpCallback

```c
STDAPI WslcRegisterSessionCrashDumpCallback(
    _In_ WslcSession session,
    _In_ WslcSessionCrashDumpCallback crashDumpCallback,
    _In_opt_ PVOID crashDumpContext,
    _Out_ WslcCrashDumpSubscription* subscription,
    _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `crashDumpCallback` | `WslcSessionCrashDumpCallback` | in |
| `crashDumpContext` | `PVOID` | in, optional |
| `subscription` | `WslcCrashDumpSubscription*` | out |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Example:

```c
void CALLBACK OnCrashDump(const WslcSessionCrashDumpInfo* info, PVOID context)
{
    UNREFERENCED_PARAMETER(context);
    wprintf(L"dump=%ls\n", info->dumpPath);
}

WslcCrashDumpSubscription subscription = NULL;
HRESULT hr = WslcRegisterSessionCrashDumpCallback(
    session,
    OnCrashDump,
    NULL,
    &subscription,
    NULL);
```

### WslcReleaseCrashDumpSubscription

```c
STDAPI WslcReleaseCrashDumpSubscription(_In_ WslcCrashDumpSubscription subscription);
```

| Parameter | Type | Direction |
|---|---|---|
| `subscription` | `WslcCrashDumpSubscription` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcReleaseCrashDumpSubscription(subscription);
subscription = NULL;
```

### WslcTerminateSession

```c
STDAPI WslcTerminateSession(_In_ WslcSession session);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcTerminateSession(session);
```

### WslcReleaseSession

```c
STDAPI WslcReleaseSession(_In_ WslcSession session);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcReleaseSession(session);
session = NULL;
```

### WslcSessionAuthenticate

```c
STDAPI WslcSessionAuthenticate(
    _In_ WslcSession session,
    _In_z_ PCSTR serverAddress,
    _In_z_ PCSTR username,
    _In_z_ PCSTR password,
    _Outptr_result_z_ PSTR* identityToken,
    _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `serverAddress` | `PCSTR` | in |
| `username` | `PCSTR` | in |
| `password` | `PCSTR` | in |
| `identityToken` | `PSTR*` | out |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Header note: `identityToken` is allocated using `CoTaskMemAlloc`; free it with `CoTaskMemFree`.

Example:

```c
PSTR identityToken = NULL;
HRESULT hr = WslcSessionAuthenticate(
    session,
    "127.0.0.1:5000",
    "user",
    "password",
    &identityToken,
    NULL);

if (SUCCEEDED(hr))
{
    printf("token=%s\n", identityToken);
    CoTaskMemFree(identityToken);
}
```

---

## Container APIs

### WslcInitContainerSettings

```c
STDAPI WslcInitContainerSettings(_In_ PCSTR imageName, _Out_ WslcContainerSettings* containerSettings);
```

| Parameter | Type | Direction |
|---|---|---|
| `imageName` | `PCSTR` | in |
| `containerSettings` | `WslcContainerSettings*` | out |

Return value: `HRESULT`.

Example:

```c
WslcContainerSettings containerSettings;
HRESULT hr = WslcInitContainerSettings("docker.io/library/alpine:latest", &containerSettings);
```

### WslcCreateContainer

```c
STDAPI WslcCreateContainer(_In_ WslcSession session, _In_ const WslcContainerSettings* containerSettings, _Out_ WslcContainer* container, _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `containerSettings` | `const WslcContainerSettings*` | in |
| `container` | `WslcContainer*` | out |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Example:

```c
WslcContainer container = NULL;
HRESULT hr = WslcCreateContainer(session, &containerSettings, &container, NULL);
```

### WslcStartContainer

```c
STDAPI WslcStartContainer(_In_ WslcContainer container, _In_ WslcContainerStartFlags flags, _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `container` | `WslcContainer` | in |
| `flags` | `WslcContainerStartFlags` | in |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcStartContainer(container, WSLC_CONTAINER_START_FLAG_ATTACH, NULL);
```

### WslcSetContainerSettingsName

```c
STDAPI WslcSetContainerSettingsName(_In_ WslcContainerSettings* containerSettings, _In_ PCSTR name);
```

| Parameter | Type | Direction |
|---|---|---|
| `containerSettings` | `WslcContainerSettings*` | in |
| `name` | `PCSTR` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcSetContainerSettingsName(&containerSettings, "demo-container");
```

### WslcSetContainerSettingsInitProcess

```c
STDAPI WslcSetContainerSettingsInitProcess(_In_ WslcContainerSettings* containerSettings, _In_ WslcProcessSettings* initProcess);
```

| Parameter | Type | Direction |
|---|---|---|
| `containerSettings` | `WslcContainerSettings*` | in |
| `initProcess` | `WslcProcessSettings*` | in |

Return value: `HRESULT`.

Example:

```c
WslcProcessSettings initProcess;
PCSTR const argv[] = { "/bin/sh", "-c", "sleep 3600" };

WslcInitProcessSettings(&initProcess);
WslcSetProcessSettingsCmdLine(&initProcess, argv, _countof(argv));

HRESULT hr = WslcSetContainerSettingsInitProcess(&containerSettings, &initProcess);
```

### WslcSetContainerSettingsNetworkingMode

```c
STDAPI WslcSetContainerSettingsNetworkingMode(_In_ WslcContainerSettings* containerSettings, _In_ WslcContainerNetworkingMode networkingMode);
```

| Parameter | Type | Direction |
|---|---|---|
| `containerSettings` | `WslcContainerSettings*` | in |
| `networkingMode` | `WslcContainerNetworkingMode` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcSetContainerSettingsNetworkingMode(
    &containerSettings,
    WSLC_CONTAINER_NETWORKING_MODE_BRIDGED);
```

### WslcSetContainerSettingsHostName

```c
STDAPI WslcSetContainerSettingsHostName(_In_ WslcContainerSettings* containerSettings, _In_ PCSTR hostName);
```

| Parameter | Type | Direction |
|---|---|---|
| `containerSettings` | `WslcContainerSettings*` | in |
| `hostName` | `PCSTR` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcSetContainerSettingsHostName(&containerSettings, "demo-host");
```

### WslcSetContainerSettingsDomainName

```c
STDAPI WslcSetContainerSettingsDomainName(_In_ WslcContainerSettings* containerSettings, _In_ PCSTR domainName);
```

| Parameter | Type | Direction |
|---|---|---|
| `containerSettings` | `WslcContainerSettings*` | in |
| `domainName` | `PCSTR` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcSetContainerSettingsDomainName(&containerSettings, "example.internal");
```

### WslcSetContainerSettingsFlags

```c
STDAPI WslcSetContainerSettingsFlags(_In_ WslcContainerSettings* containerSettings, _In_ WslcContainerFlags flags);
```

| Parameter | Type | Direction |
|---|---|---|
| `containerSettings` | `WslcContainerSettings*` | in |
| `flags` | `WslcContainerFlags` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcSetContainerSettingsFlags(
    &containerSettings,
    (WslcContainerFlags)(WSLC_CONTAINER_FLAG_AUTO_REMOVE | WSLC_CONTAINER_FLAG_ENABLE_GPU));
```

### WslcSetContainerSettingsPortMappings

```c
STDAPI WslcSetContainerSettingsPortMappings(
    _In_ WslcContainerSettings* containerSettings,
    _In_reads_opt_(portMappingCount) const WslcContainerPortMapping* portMappings,
    _In_ uint32_t portMappingCount);
```

| Parameter | Type | Direction |
|---|---|---|
| `containerSettings` | `WslcContainerSettings*` | in |
| `portMappings` | `const WslcContainerPortMapping*` | in, optional |
| `portMappingCount` | `uint32_t` | in |

Return value: `HRESULT`.

Example:

```c
WslcContainerPortMapping portMappings[1] = { 0 };
portMappings[0].windowsPort = (uint16_t)8080;
portMappings[0].containerPort = (uint16_t)80;
portMappings[0].protocol = WSLC_PORT_PROTOCOL_TCP;
portMappings[0].windowsAddress = NULL;

HRESULT hr = WslcSetContainerSettingsPortMappings(
    &containerSettings,
    portMappings,
    (uint32_t)_countof(portMappings));
```

### WslcSetContainerSettingsVolumes

```c
STDAPI WslcSetContainerSettingsVolumes(
    _In_ WslcContainerSettings* containerSettings, _In_reads_opt_(volumeCount) const WslcContainerVolume* volumes, _In_ uint32_t volumeCount);
```

| Parameter | Type | Direction |
|---|---|---|
| `containerSettings` | `WslcContainerSettings*` | in |
| `volumes` | `const WslcContainerVolume*` | in, optional |
| `volumeCount` | `uint32_t` | in |

Return value: `HRESULT`.

Example:

```c
WslcContainerVolume volumes[1] = { 0 };
volumes[0].windowsPath = L"C:\\data";
volumes[0].containerPath = "/mnt/data";
volumes[0].readOnly = FALSE;

HRESULT hr = WslcSetContainerSettingsVolumes(
    &containerSettings,
    volumes,
    (uint32_t)_countof(volumes));
```

### WslcSetContainerSettingsNamedVolumes

```c
STDAPI WslcSetContainerSettingsNamedVolumes(
    _In_ WslcContainerSettings* containerSettings,
    _In_reads_opt_(namedVolumeCount) const WslcContainerNamedVolume* namedVolumes,
    _In_ uint32_t namedVolumeCount);
```

| Parameter | Type | Direction |
|---|---|---|
| `containerSettings` | `WslcContainerSettings*` | in |
| `namedVolumes` | `const WslcContainerNamedVolume*` | in, optional |
| `namedVolumeCount` | `uint32_t` | in |

Return value: `HRESULT`.

Example:

```c
WslcContainerNamedVolume namedVolumes[1] = { 0 };
namedVolumes[0].name = "cache";
namedVolumes[0].containerPath = "/var/cache/demo";
namedVolumes[0].readOnly = FALSE;

HRESULT hr = WslcSetContainerSettingsNamedVolumes(
    &containerSettings,
    namedVolumes,
    (uint32_t)_countof(namedVolumes));
```

### WslcCreateContainerProcess

```c
STDAPI WslcCreateContainerProcess(
    _In_ WslcContainer container, _In_ WslcProcessSettings* newProcessSettings, _Out_ WslcProcess* newProcess, _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `container` | `WslcContainer` | in |
| `newProcessSettings` | `WslcProcessSettings*` | in |
| `newProcess` | `WslcProcess*` | out |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Example:

```c
WslcProcessSettings processSettings;
WslcProcess process = NULL;
PCSTR const argv[] = { "/bin/echo", "hello from wscl" };

WslcInitProcessSettings(&processSettings);
WslcSetProcessSettingsCmdLine(&processSettings, argv, _countof(argv));

HRESULT hr = WslcCreateContainerProcess(container, &processSettings, &process, NULL);
```

### WslcGetContainerID

```c
STDAPI WslcGetContainerID(_In_ WslcContainer container, _Out_writes_(WSLC_CONTAINER_ID_BUFFER_SIZE) CHAR containerID[WSLC_CONTAINER_ID_BUFFER_SIZE]);
```

| Parameter | Type | Direction |
|---|---|---|
| `container` | `WslcContainer` | in |
| `containerID` | `CHAR[WSLC_CONTAINER_ID_BUFFER_SIZE]` | out |

Return value: `HRESULT`.

Example:

```c
CHAR containerID[WSLC_CONTAINER_ID_BUFFER_SIZE] = { 0 };
HRESULT hr = WslcGetContainerID(container, containerID);
```

### WslcGetContainerInitProcess

```c
STDAPI WslcGetContainerInitProcess(_In_ WslcContainer container, _Out_ WslcProcess* initProcess);
```

| Parameter | Type | Direction |
|---|---|---|
| `container` | `WslcContainer` | in |
| `initProcess` | `WslcProcess*` | out |

Return value: `HRESULT`.

Example:

```c
WslcProcess initProcess = NULL;
HRESULT hr = WslcGetContainerInitProcess(container, &initProcess);
```

### WslcInspectContainer

```c
STDAPI WslcInspectContainer(_In_ WslcContainer container, _Outptr_result_z_ PSTR* inspectData);
```

| Parameter | Type | Direction |
|---|---|---|
| `container` | `WslcContainer` | in |
| `inspectData` | `PSTR*` | out |

Return value: `HRESULT`.

Header note: `inspectData` is allocated using `CoTaskMemAlloc`; free it with `CoTaskMemFree`.

Example:

```c
PSTR inspectData = NULL;
HRESULT hr = WslcInspectContainer(container, &inspectData);
if (SUCCEEDED(hr))
{
    puts(inspectData);
    CoTaskMemFree(inspectData);
}
```

### WslcGetContainerState

```c
STDAPI WslcGetContainerState(_In_ WslcContainer container, _Out_ WslcContainerState* state);
```

| Parameter | Type | Direction |
|---|---|---|
| `container` | `WslcContainer` | in |
| `state` | `WslcContainerState*` | out |

Return value: `HRESULT`.

Example:

```c
WslcContainerState state = WSLC_CONTAINER_STATE_INVALID;
HRESULT hr = WslcGetContainerState(container, &state);
```

### WslcStopContainer

```c
STDAPI WslcStopContainer(_In_ WslcContainer container, _In_ WslcSignal signal, _In_ uint32_t timeoutSeconds, _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `container` | `WslcContainer` | in |
| `signal` | `WslcSignal` | in |
| `timeoutSeconds` | `uint32_t` | in |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcStopContainer(
    container,
    WSLC_SIGNAL_SIGTERM,
    (uint32_t)30,
    NULL);
```

### WslcDeleteContainer

```c
STDAPI WslcDeleteContainer(_In_ WslcContainer container, _In_ WslcDeleteContainerFlags flags, _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `container` | `WslcContainer` | in |
| `flags` | `WslcDeleteContainerFlags` | in |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcDeleteContainer(
    container,
    WSLC_DELETE_CONTAINER_FLAG_FORCE,
    NULL);
```

### WslcReleaseContainer

```c
STDAPI WslcReleaseContainer(_In_ WslcContainer container);
```

| Parameter | Type | Direction |
|---|---|---|
| `container` | `WslcContainer` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcReleaseContainer(container);
container = NULL;
```

---

## Process APIs

### WslcInitProcessSettings

```c
STDAPI WslcInitProcessSettings(_Out_ WslcProcessSettings* processSettings);
```

| Parameter | Type | Direction |
|---|---|---|
| `processSettings` | `WslcProcessSettings*` | out |

Return value: `HRESULT`.

Example:

```c
WslcProcessSettings processSettings;
HRESULT hr = WslcInitProcessSettings(&processSettings);
```

### WslcSetProcessSettingsWorkingDirectory

```c
STDAPI WslcSetProcessSettingsWorkingDirectory(_In_ WslcProcessSettings* processSettings, _In_ PCSTR workingDirectory);
```

| Parameter | Type | Direction |
|---|---|---|
| `processSettings` | `WslcProcessSettings*` | in |
| `workingDirectory` | `PCSTR` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcSetProcessSettingsWorkingDirectory(&processSettings, "/work");
```

### WslcSetProcessSettingsCmdLine

```c
STDAPI WslcSetProcessSettingsCmdLine(_In_ WslcProcessSettings* processSettings, _In_reads_(argc) PCSTR const* argv, size_t argc);
```

| Parameter | Type | Direction |
|---|---|---|
| `processSettings` | `WslcProcessSettings*` | in |
| `argv` | `PCSTR const*` | in |
| `argc` | `size_t` | in |

Return value: `HRESULT`.

Example:

```c
PCSTR const argv[] = { "/bin/sh", "-c", "echo ready" };
HRESULT hr = WslcSetProcessSettingsCmdLine(&processSettings, argv, _countof(argv));
```

### WslcSetProcessSettingsEnvVariables

```c
STDAPI WslcSetProcessSettingsEnvVariables(_In_ WslcProcessSettings* processSettings, _In_reads_(argc) PCSTR const* key_value, size_t argc);
```

| Parameter | Type | Direction |
|---|---|---|
| `processSettings` | `WslcProcessSettings*` | in |
| `key_value` | `PCSTR const*` | in |
| `argc` | `size_t` | in |

Return value: `HRESULT`.

Example:

```c
PCSTR const key_value[] = { "HOME=/root", "DEMO_FLAG=1" };
HRESULT hr = WslcSetProcessSettingsEnvVariables(&processSettings, key_value, _countof(key_value));
```

### WslcSetProcessSettingsCallbacks

```c
STDAPI WslcSetProcessSettingsCallbacks(_In_ WslcProcessSettings* processSettings, _In_ const WslcProcessCallbacks* callbacks, _In_opt_ PVOID context);
```

| Parameter | Type | Direction |
|---|---|---|
| `processSettings` | `WslcProcessSettings*` | in |
| `callbacks` | `const WslcProcessCallbacks*` | in |
| `context` | `PVOID` | in, optional |

Return value: `HRESULT`.

Header note: using callbacks consumes the process I/O handles and prevents later acquisition through `WslcGetProcessIOHandle`.

Example:

```c
void CALLBACK OnStdOut(WslcProcessIOHandle ioHandle, const BYTE* data, uint32_t dataBytes, PVOID context)
{
    UNREFERENCED_PARAMETER(ioHandle);
    UNREFERENCED_PARAMETER(context);
    fwrite(data, 1, dataBytes, stdout);
}

void CALLBACK OnExit(INT32 exitCode, PVOID context)
{
    UNREFERENCED_PARAMETER(context);
    printf("exit=%ld\n", (long)exitCode);
}

WslcProcessCallbacks callbacks = { 0 };
callbacks.onStdOut = OnStdOut;
callbacks.onStdErr = OnStdOut;
callbacks.onExit = OnExit;

HRESULT hr = WslcSetProcessSettingsCallbacks(&processSettings, &callbacks, NULL);
```

### WslcGetProcessPid

```c
STDAPI WslcGetProcessPid(_In_ WslcProcess process, _Out_ uint32_t* pid);
```

| Parameter | Type | Direction |
|---|---|---|
| `process` | `WslcProcess` | in |
| `pid` | `uint32_t*` | out |

Return value: `HRESULT`.

Example:

```c
uint32_t pid = 0;
HRESULT hr = WslcGetProcessPid(process, &pid);
```

### WslcGetProcessExitEvent

```c
STDAPI WslcGetProcessExitEvent(_In_ WslcProcess process, _Out_ HANDLE* exitEvent);
```

| Parameter | Type | Direction |
|---|---|---|
| `process` | `WslcProcess` | in |
| `exitEvent` | `HANDLE*` | out |

Return value: `HRESULT`.

Example:

```c
HANDLE exitEvent = NULL;
HRESULT hr = WslcGetProcessExitEvent(process, &exitEvent);
if (SUCCEEDED(hr))
{
    WaitForSingleObject(exitEvent, INFINITE);
}
```

### WslcGetProcessState

```c
STDAPI WslcGetProcessState(_In_ WslcProcess process, _Out_ WslcProcessState* state);
```

| Parameter | Type | Direction |
|---|---|---|
| `process` | `WslcProcess` | in |
| `state` | `WslcProcessState*` | out |

Return value: `HRESULT`.

Example:

```c
WslcProcessState state = WSLC_PROCESS_STATE_UNKNOWN;
HRESULT hr = WslcGetProcessState(process, &state);
```

### WslcGetProcessExitCode

```c
STDAPI WslcGetProcessExitCode(_In_ WslcProcess process, _Out_ PINT32 exitCode);
```

| Parameter | Type | Direction |
|---|---|---|
| `process` | `WslcProcess` | in |
| `exitCode` | `PINT32` | out |

Return value: `HRESULT`.

Example:

```c
INT32 exitCode = 0;
HRESULT hr = WslcGetProcessExitCode(process, &exitCode);
```

### WslcSignalProcess

```c
STDAPI WslcSignalProcess(_In_ WslcProcess process, _In_ WslcSignal signal);
```

| Parameter | Type | Direction |
|---|---|---|
| `process` | `WslcProcess` | in |
| `signal` | `WslcSignal` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcSignalProcess(process, WSLC_SIGNAL_SIGTERM);
```

### WslcGetProcessIOHandle

```c
STDAPI WslcGetProcessIOHandle(_In_ WslcProcess process, _In_ WslcProcessIOHandle ioHandle, _Out_ HANDLE* handle);
```

| Parameter | Type | Direction |
|---|---|---|
| `process` | `WslcProcess` | in |
| `ioHandle` | `WslcProcessIOHandle` | in |
| `handle` | `HANDLE*` | out |

Return value: `HRESULT`.

Example:

```c
HANDLE stdoutHandle = NULL;
HRESULT hr = WslcGetProcessIOHandle(process, WSLC_PROCESS_IO_HANDLE_STDOUT, &stdoutHandle);
```

### WslcReleaseProcess

```c
STDAPI WslcReleaseProcess(_In_ WslcProcess process);
```

| Parameter | Type | Direction |
|---|---|---|
| `process` | `WslcProcess` | in |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcReleaseProcess(process);
process = NULL;
```

---

## Image APIs

### WslcPullSessionImage

```c
STDAPI WslcPullSessionImage(_In_ WslcSession session, _In_ const WslcPullImageOptions* options, _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `options` | `const WslcPullImageOptions*` | in |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Example:

```c
HRESULT CALLBACK OnImageProgress(const WslcImageProgressMessage* progress, PVOID context)
{
    UNREFERENCED_PARAMETER(context);
    printf("%s %llu/%llu\n",
        progress->id,
        (unsigned long long)progress->detail.currentBytes,
        (unsigned long long)progress->detail.totalBytes);
    return S_OK;
}

WslcPullImageOptions pullOptions = { 0 };
pullOptions.uri = "docker.io/library/alpine:latest";
pullOptions.progressCallback = OnImageProgress;
pullOptions.progressCallbackContext = NULL;
pullOptions.registryAuth = NULL;

HRESULT hr = WslcPullSessionImage(session, &pullOptions, NULL);
```

### WslcImportSessionImage

```c
STDAPI WslcImportSessionImage(
    _In_ WslcSession session,
    _In_z_ PCSTR imageName,
    _In_ HANDLE imageContent,
    _In_ uint64_t imageContentBytes,
    _In_opt_ const WslcImportImageOptions* options,
    _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `imageName` | `PCSTR` | in |
| `imageContent` | `HANDLE` | in |
| `imageContentBytes` | `uint64_t` | in |
| `options` | `const WslcImportImageOptions*` | in, optional |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Important: the header declares `imageContent` as `HANDLE`, not `void*`.

Example:

```c
HANDLE imageContent = CreateFileW(
    L"C:\\images\\demo-import.tar",
    GENERIC_READ,
    FILE_SHARE_READ,
    NULL,
    OPEN_EXISTING,
    FILE_ATTRIBUTE_NORMAL,
    NULL);

LARGE_INTEGER size = { 0 };
GetFileSizeEx(imageContent, &size);

WslcImportImageOptions importOptions = { 0 };
HRESULT hr = WslcImportSessionImage(
    session,
    "demo/imported:latest",
    imageContent,
    (uint64_t)size.QuadPart,
    &importOptions,
    NULL);

CloseHandle(imageContent);
```

### WslcImportSessionImageFromFile

```c
STDAPI WslcImportSessionImageFromFile(
    _In_ WslcSession session, _In_z_ PCSTR imageName, _In_z_ PCWSTR path, _In_opt_ const WslcImportImageOptions* options, _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `imageName` | `PCSTR` | in |
| `path` | `PCWSTR` | in |
| `options` | `const WslcImportImageOptions*` | in, optional |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Example:

```c
WslcImportImageOptions importOptions = { 0 };
HRESULT hr = WslcImportSessionImageFromFile(
    session,
    "demo/imported:latest",
    L"C:\\images\\demo-import.tar",
    &importOptions,
    NULL);
```

### WslcLoadSessionImage

```c
STDAPI WslcLoadSessionImage(
    _In_ WslcSession session,
    _In_ HANDLE imageContent,
    _In_ uint64_t imageContentBytes,
    _In_opt_ const WslcLoadImageOptions* options,
    _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `imageContent` | `HANDLE` | in |
| `imageContentBytes` | `uint64_t` | in |
| `options` | `const WslcLoadImageOptions*` | in, optional |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Important: the header declares `imageContent` as `HANDLE`, not `void*`.

Example:

```c
HANDLE imageContent = CreateFileW(
    L"C:\\images\\demo-load.tar",
    GENERIC_READ,
    FILE_SHARE_READ,
    NULL,
    OPEN_EXISTING,
    FILE_ATTRIBUTE_NORMAL,
    NULL);

LARGE_INTEGER size = { 0 };
GetFileSizeEx(imageContent, &size);

WslcLoadImageOptions loadOptions = { 0 };
HRESULT hr = WslcLoadSessionImage(
    session,
    imageContent,
    (uint64_t)size.QuadPart,
    &loadOptions,
    NULL);

CloseHandle(imageContent);
```

### WslcLoadSessionImageFromFile

```c
STDAPI WslcLoadSessionImageFromFile(
    _In_ WslcSession session, _In_z_ PCWSTR path, _In_opt_ const WslcLoadImageOptions* options, _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `path` | `PCWSTR` | in |
| `options` | `const WslcLoadImageOptions*` | in, optional |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Example:

```c
WslcLoadImageOptions loadOptions = { 0 };
HRESULT hr = WslcLoadSessionImageFromFile(
    session,
    L"C:\\images\\demo-load.tar",
    &loadOptions,
    NULL);
```

### WslcDeleteSessionImage

```c
STDAPI WslcDeleteSessionImage(_In_ WslcSession session, _In_z_ PCSTR nameOrID, _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `nameOrID` | `PCSTR` | in |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcDeleteSessionImage(session, "demo/imported:latest", NULL);
```

### WslcListSessionImages

```c
STDAPI WslcListSessionImages(_In_ WslcSession session, _Outptr_result_buffer_(*count) WslcImageInfo** images, _Out_ uint32_t* count);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `images` | `WslcImageInfo**` | out |
| `count` | `uint32_t*` | out |

Return value: `HRESULT`.

Header note: `images` is allocated using `CoTaskMemAlloc`; free it with `CoTaskMemFree`.

Example:

```c
WslcImageInfo* images = NULL;
uint32_t count = 0;
HRESULT hr = WslcListSessionImages(session, &images, &count);

if (SUCCEEDED(hr))
{
    for (uint32_t i = 0; i < count; ++i)
    {
        printf("%s\n", images[i].name);
    }
    CoTaskMemFree(images);
}
```

### WslcTagSessionImage

```c
STDAPI WslcTagSessionImage(_In_ WslcSession session, _In_ const WslcTagImageOptions* options, _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `options` | `const WslcTagImageOptions*` | in |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Example:

```c
WslcTagImageOptions tagOptions = { 0 };
tagOptions.image = "docker.io/library/alpine:latest";
tagOptions.repo = "demo/alpine";
tagOptions.tag = "stable";

HRESULT hr = WslcTagSessionImage(session, &tagOptions, NULL);
```

### WslcPushSessionImage

```c
STDAPI WslcPushSessionImage(_In_ WslcSession session, _In_ const WslcPushImageOptions* options, _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `options` | `const WslcPushImageOptions*` | in |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Example:

```c
WslcPushImageOptions pushOptions = { 0 };
pushOptions.image = "demo/alpine:stable";
pushOptions.registryAuth = "BASE64_X_REGISTRY_AUTH";
pushOptions.progressCallback = OnImageProgress;
pushOptions.progressCallbackContext = NULL;

HRESULT hr = WslcPushSessionImage(session, &pushOptions, NULL);
```

---

## Storage APIs

### WslcCreateSessionVhdVolume

```c
STDAPI WslcCreateSessionVhdVolume(_In_ WslcSession session, _In_ const WslcVhdRequirements* options, _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `options` | `const WslcVhdRequirements*` | in |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Header notes:

- `WSLC_VHD_TYPE_FIXED` is only honored by `WslcCreateSessionVhdVolume`.
- `uid` and `gid` are honored iff `flags & WSLC_VHD_REQ_FLAG_OWNER`.

Example:

```c
WslcVhdRequirements options = { 0 };
options.name = "cache";
options.sizeBytes = (uint64_t)8 * 1024 * 1024 * 1024;
options.type = WSLC_VHD_TYPE_DYNAMIC;
options.flags = WSLC_VHD_REQ_FLAG_OWNER;
options.uid = (uint32_t)1000;
options.gid = (uint32_t)1000;

HRESULT hr = WslcCreateSessionVhdVolume(session, &options, NULL);
```

### WslcDeleteSessionVhdVolume

```c
STDAPI WslcDeleteSessionVhdVolume(_In_ WslcSession session, _In_z_ PCSTR name, _Outptr_opt_result_z_ PWSTR* errorMessage);
```

| Parameter | Type | Direction |
|---|---|---|
| `session` | `WslcSession` | in |
| `name` | `PCSTR` | in |
| `errorMessage` | `PWSTR*` | out, optional |

Return value: `HRESULT`.

Example:

```c
HRESULT hr = WslcDeleteSessionVhdVolume(session, "cache", NULL);
```

---

## Install and Version APIs

### WslcGetMissingComponents

```c
STDAPI WslcGetMissingComponents(_Out_ WslcComponentFlags* missingComponents);
```

| Parameter | Type | Direction |
|---|---|---|
| `missingComponents` | `WslcComponentFlags*` | out |

Return value: `HRESULT`.

Example:

```c
WslcComponentFlags missingComponents = WSLC_COMPONENT_FLAG_NONE;
HRESULT hr = WslcGetMissingComponents(&missingComponents);
```

### WslcGetVersion

```c
STDAPI WslcGetVersion(_Out_writes_(1) WslcVersion* version);
```

| Parameter | Type | Direction |
|---|---|---|
| `version` | `WslcVersion*` | out |

Return value: `HRESULT`.

Example:

```c
WslcVersion version = { 0 };
HRESULT hr = WslcGetVersion(&version);
if (SUCCEEDED(hr))
{
    printf("%u.%u.%u\n", version.major, version.minor, version.revision);
}
```

### WslcInstallWithDependencies

```c
STDAPI WslcInstallWithDependencies(_In_opt_ WslcInstallCallback progressCallback, _In_opt_ PVOID context);
```

| Parameter | Type | Direction |
|---|---|---|
| `progressCallback` | `WslcInstallCallback` | in, optional |
| `context` | `PVOID` | in, optional |

Return value: `HRESULT`.

Header note: callbacks are only made for components actively installed by this call. The header comment also says that list can be acquired beforehand with `WslcCanRun`, although `wslcsdk.h` does not declare a public `WslcCanRun` prototype.

Example:

```c
void CALLBACK OnInstallProgress(
    WslcComponentFlags component,
    uint32_t progressSteps,
    uint32_t totalSteps,
    PVOID context)
{
    UNREFERENCED_PARAMETER(context);
    printf("component=%u %u/%u\n", (unsigned)component, progressSteps, totalSteps);
}

HRESULT hr = WslcInstallWithDependencies(OnInstallProgress, NULL);
```

---


### DllMain

Exported in `wslcsdk.def`:

```def
DllMain
```

Public prototype in `wslcsdk.h`: none.

Usage note: no direct SDK consumer example is provided because the public header does not declare this export.

### DllGetActivationFactory

Exported in `wslcsdk.def`:

```def
DllGetActivationFactory = WINRT_GetActivationFactory PRIVATE
```

Public prototype in `wslcsdk.h`: none.

Usage note: no direct SDK consumer example is provided because the public header does not declare this export.

### DllCanUnloadNow

Exported in `wslcsdk.def`:

```def
DllCanUnloadNow         = WINRT_CanUnloadNow         PRIVATE
```

Public prototype in `wslcsdk.h`: none.

Usage note: no direct SDK consumer example is provided because the public header does not declare this export.

---

## Enumerations

### WslcContainerNetworkingMode

```c
typedef enum WslcContainerNetworkingMode
{
    WSLC_CONTAINER_NETWORKING_MODE_NONE = 0, // No networking / isolated
    WSLC_CONTAINER_NETWORKING_MODE_BRIDGED = 1
} WslcContainerNetworkingMode;
```

| Enumerator | Value |
|---|---|
| `WSLC_CONTAINER_NETWORKING_MODE_NONE` | `0` |
| `WSLC_CONTAINER_NETWORKING_MODE_BRIDGED` | `1` |

### WslcVhdType

```c
typedef enum WslcVhdType
{
    WSLC_VHD_TYPE_DYNAMIC = 0, // Expanding VHDX (default)
    WSLC_VHD_TYPE_FIXED = 1    // Fixed-allocation VHDX (only honored by WslcCreateSessionVhdVolume)
} WslcVhdType;
```

| Enumerator | Value |
|---|---|
| `WSLC_VHD_TYPE_DYNAMIC` | `0` |
| `WSLC_VHD_TYPE_FIXED` | `1` |

### WslcVhdRequirementsFlags

```c
typedef enum WslcVhdRequirementsFlags
{
    WSLC_VHD_REQ_FLAG_NONE = 0x00000000,
    WSLC_VHD_REQ_FLAG_OWNER = 0x00000001,
} WslcVhdRequirementsFlags;
```

| Enumerator | Value |
|---|---|
| `WSLC_VHD_REQ_FLAG_NONE` | `0x00000000` |
| `WSLC_VHD_REQ_FLAG_OWNER` | `0x00000001` |

### WslcSessionFeatureFlags

```c
typedef enum WslcSessionFeatureFlags
{
    WSLC_SESSION_FEATURE_FLAG_NONE = 0x00000000,
    WSLC_SESSION_FEATURE_FLAG_ENABLE_GPU = 0x00000004
} WslcSessionFeatureFlags;
```

| Enumerator | Value |
|---|---|
| `WSLC_SESSION_FEATURE_FLAG_NONE` | `0x00000000` |
| `WSLC_SESSION_FEATURE_FLAG_ENABLE_GPU` | `0x00000004` |

### WslcSessionTerminationReason

```c
typedef enum WslcSessionTerminationReason
{
    WSLC_SESSION_TERMINATION_REASON_UNKNOWN = 0,
    WSLC_SESSION_TERMINATION_REASON_SHUTDOWN = 1,
    WSLC_SESSION_TERMINATION_REASON_CRASHED = 2,
} WslcSessionTerminationReason;
```

| Enumerator | Value |
|---|---|
| `WSLC_SESSION_TERMINATION_REASON_UNKNOWN` | `0` |
| `WSLC_SESSION_TERMINATION_REASON_SHUTDOWN` | `1` |
| `WSLC_SESSION_TERMINATION_REASON_CRASHED` | `2` |

### WslcPortProtocol

```c
typedef enum WslcPortProtocol
{
    WSLC_PORT_PROTOCOL_TCP = 0,
    WSLC_PORT_PROTOCOL_UDP = 1
} WslcPortProtocol;
```

| Enumerator | Value |
|---|---|
| `WSLC_PORT_PROTOCOL_TCP` | `0` |
| `WSLC_PORT_PROTOCOL_UDP` | `1` |

### WslcContainerFlags

```c
typedef enum WslcContainerFlags
{
    WSLC_CONTAINER_FLAG_NONE = 0x00000000,
    WSLC_CONTAINER_FLAG_AUTO_REMOVE = 0x00000001,
    WSLC_CONTAINER_FLAG_ENABLE_GPU = 0x00000002,
    WSLC_CONTAINER_FLAG_PRIVILEGED = 0x00000004,

} WslcContainerFlags;
```

| Enumerator | Value |
|---|---|
| `WSLC_CONTAINER_FLAG_NONE` | `0x00000000` |
| `WSLC_CONTAINER_FLAG_AUTO_REMOVE` | `0x00000001` |
| `WSLC_CONTAINER_FLAG_ENABLE_GPU` | `0x00000002` |
| `WSLC_CONTAINER_FLAG_PRIVILEGED` | `0x00000004` |

### WslcContainerStartFlags

```c
typedef enum WslcContainerStartFlags
{
    WSLC_CONTAINER_START_FLAG_NONE = 0x00000000,
    WSLC_CONTAINER_START_FLAG_ATTACH = 0x00000001,

} WslcContainerStartFlags;
```

| Enumerator | Value |
|---|---|
| `WSLC_CONTAINER_START_FLAG_NONE` | `0x00000000` |
| `WSLC_CONTAINER_START_FLAG_ATTACH` | `0x00000001` |

### WslcContainerState

```c
typedef enum WslcContainerState
{
    WSLC_CONTAINER_STATE_INVALID = 0,
    WSLC_CONTAINER_STATE_CREATED = 1,
    WSLC_CONTAINER_STATE_RUNNING = 2,
    WSLC_CONTAINER_STATE_EXITED = 3,
    WSLC_CONTAINER_STATE_DELETED = 4,
} WslcContainerState;
```

| Enumerator | Value |
|---|---|
| `WSLC_CONTAINER_STATE_INVALID` | `0` |
| `WSLC_CONTAINER_STATE_CREATED` | `1` |
| `WSLC_CONTAINER_STATE_RUNNING` | `2` |
| `WSLC_CONTAINER_STATE_EXITED` | `3` |
| `WSLC_CONTAINER_STATE_DELETED` | `4` |

### WslcSignal

```c
typedef enum WslcSignal
{
    WSLC_SIGNAL_NONE = 0,     // No signal; reserved for future use
    WSLC_SIGNAL_SIGHUP = 1,   // SIGHUP: reload / hangup
    WSLC_SIGNAL_SIGINT = 2,   // SIGINT: interrupt (Ctrl-C)
    WSLC_SIGNAL_SIGQUIT = 3,  // SIGQUIT: quit with core dump
    WSLC_SIGNAL_SIGKILL = 9,  // SIGKILL: immediate termination
    WSLC_SIGNAL_SIGTERM = 15, // SIGTERM: graceful shutdown
} WslcSignal;
```

| Enumerator | Value |
|---|---|
| `WSLC_SIGNAL_NONE` | `0` |
| `WSLC_SIGNAL_SIGHUP` | `1` |
| `WSLC_SIGNAL_SIGINT` | `2` |
| `WSLC_SIGNAL_SIGQUIT` | `3` |
| `WSLC_SIGNAL_SIGKILL` | `9` |
| `WSLC_SIGNAL_SIGTERM` | `15` |

### WslcDeleteContainerFlags

```c
typedef enum WslcDeleteContainerFlags
{
    WSLC_DELETE_CONTAINER_FLAG_NONE = 0,
    WSLC_DELETE_CONTAINER_FLAG_FORCE = 0x01
} WslcDeleteContainerFlags;
```

| Enumerator | Value |
|---|---|
| `WSLC_DELETE_CONTAINER_FLAG_NONE` | `0` |
| `WSLC_DELETE_CONTAINER_FLAG_FORCE` | `0x01` |

### WslcProcessIOHandle

```c
typedef enum WslcProcessIOHandle
{
    WSLC_PROCESS_IO_HANDLE_STDIN = 0,
    WSLC_PROCESS_IO_HANDLE_STDOUT = 1,
    WSLC_PROCESS_IO_HANDLE_STDERR = 2
} WslcProcessIOHandle;
```

| Enumerator | Value |
|---|---|
| `WSLC_PROCESS_IO_HANDLE_STDIN` | `0` |
| `WSLC_PROCESS_IO_HANDLE_STDOUT` | `1` |
| `WSLC_PROCESS_IO_HANDLE_STDERR` | `2` |

### WslcProcessState

```c
typedef enum WslcProcessState
{
    WSLC_PROCESS_STATE_UNKNOWN = 0,
    WSLC_PROCESS_STATE_RUNNING = 1,
    WSLC_PROCESS_STATE_EXITED = 2,
    WSLC_PROCESS_STATE_SIGNALLED = 3
} WslcProcessState;
```

| Enumerator | Value |
|---|---|
| `WSLC_PROCESS_STATE_UNKNOWN` | `0` |
| `WSLC_PROCESS_STATE_RUNNING` | `1` |
| `WSLC_PROCESS_STATE_EXITED` | `2` |
| `WSLC_PROCESS_STATE_SIGNALLED` | `3` |

### WslcImageProgressStatus

```c
typedef enum WslcImageProgressStatus
{
    WSLC_IMAGE_PROGRESS_STATUS_UNKNOWN = 0,
    WSLC_IMAGE_PROGRESS_STATUS_PULLING = 1,     // "Pulling fs layer"
    WSLC_IMAGE_PROGRESS_STATUS_WAITING = 2,     // "Waiting"
    WSLC_IMAGE_PROGRESS_STATUS_DOWNLOADING = 3, // "Downloading"
    WSLC_IMAGE_PROGRESS_STATUS_VERIFYING = 4,   // "Verifying Checksum"
    WSLC_IMAGE_PROGRESS_STATUS_EXTRACTING = 5,  // "Extracting"
    WSLC_IMAGE_PROGRESS_STATUS_COMPLETE = 6     // "Pull complete"
} WslcImageProgressStatus;
```

| Enumerator | Value |
|---|---|
| `WSLC_IMAGE_PROGRESS_STATUS_UNKNOWN` | `0` |
| `WSLC_IMAGE_PROGRESS_STATUS_PULLING` | `1` |
| `WSLC_IMAGE_PROGRESS_STATUS_WAITING` | `2` |
| `WSLC_IMAGE_PROGRESS_STATUS_DOWNLOADING` | `3` |
| `WSLC_IMAGE_PROGRESS_STATUS_VERIFYING` | `4` |
| `WSLC_IMAGE_PROGRESS_STATUS_EXTRACTING` | `5` |
| `WSLC_IMAGE_PROGRESS_STATUS_COMPLETE` | `6` |

### WslcComponentFlags

```c
typedef enum WslcComponentFlags
{
    WSLC_COMPONENT_FLAG_NONE = 0,
    WSLC_COMPONENT_FLAG_VIRTUAL_MACHINE_PLATFORM = 1,
    WSLC_COMPONENT_FLAG_WSL_PACKAGE = 2,
    WSLC_COMPONENT_FLAG_SDK_NEEDS_UPDATE = 4,
} WslcComponentFlags;
```

| Enumerator | Value |
|---|---|
| `WSLC_COMPONENT_FLAG_NONE` | `0` |
| `WSLC_COMPONENT_FLAG_VIRTUAL_MACHINE_PLATFORM` | `1` |
| `WSLC_COMPONENT_FLAG_WSL_PACKAGE` | `2` |
| `WSLC_COMPONENT_FLAG_SDK_NEEDS_UPDATE` | `4` |

---

## Error Codes

```c
#define WSLC_E_BASE (0x0600)
#define WSLC_E_IMAGE_NOT_FOUND MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, WSLC_E_BASE + 1)             /* 0x80040601 */
#define WSLC_E_CONTAINER_PREFIX_AMBIGUOUS MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, WSLC_E_BASE + 2)  /* 0x80040602 */
#define WSLC_E_CONTAINER_NOT_FOUND MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, WSLC_E_BASE + 3)         /* 0x80040603 */
#define WSLC_E_VOLUME_NOT_FOUND MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, WSLC_E_BASE + 4)            /* 0x80040604 */
#define WSLC_E_CONTAINER_NOT_RUNNING MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, WSLC_E_BASE + 5)       /* 0x80040605 */
#define WSLC_E_CONTAINER_IS_RUNNING MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, WSLC_E_BASE + 6)        /* 0x80040606 */
#define WSLC_E_SESSION_RESERVED MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, WSLC_E_BASE + 7)            /* 0x80040607 */
#define WSLC_E_INVALID_SESSION_NAME MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, WSLC_E_BASE + 8)        /* 0x80040608 */
#define WSLC_E_NETWORK_NOT_FOUND MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, WSLC_E_BASE + 9)           /* 0x80040609 */
#define WSLC_E_WU_SEARCH_FAILED MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, WSLC_E_BASE + 10)           /* 0x8004060A */
#define WSLC_E_SDK_UPDATE_NEEDED MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, WSLC_E_BASE + 11)          /* 0x8004060B */
#define WSLC_E_CONTAINER_DISABLED MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, WSLC_E_BASE + 12)         /* 0x8004060C */
#define WSLC_E_REGISTRY_BLOCKED_BY_POLICY MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, WSLC_E_BASE + 13) /* 0x8004060D */
#define WSLC_E_VOLUME_NOT_AVAILABLE MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, WSLC_E_BASE + 14)       /* 0x8004060E */
```

| Symbol | Hex Value |
|---|---|
| `WSLC_E_BASE` | `0x0600` |
| `WSLC_E_IMAGE_NOT_FOUND` | `0x80040601` |
| `WSLC_E_CONTAINER_PREFIX_AMBIGUOUS` | `0x80040602` |
| `WSLC_E_CONTAINER_NOT_FOUND` | `0x80040603` |
| `WSLC_E_VOLUME_NOT_FOUND` | `0x80040604` |
| `WSLC_E_CONTAINER_NOT_RUNNING` | `0x80040605` |
| `WSLC_E_CONTAINER_IS_RUNNING` | `0x80040606` |
| `WSLC_E_SESSION_RESERVED` | `0x80040607` |
| `WSLC_E_INVALID_SESSION_NAME` | `0x80040608` |
| `WSLC_E_NETWORK_NOT_FOUND` | `0x80040609` |
| `WSLC_E_WU_SEARCH_FAILED` | `0x8004060A` |
| `WSLC_E_SDK_UPDATE_NEEDED` | `0x8004060B` |
| `WSLC_E_CONTAINER_DISABLED` | `0x8004060C` |
| `WSLC_E_REGISTRY_BLOCKED_BY_POLICY` | `0x8004060D` |
| `WSLC_E_VOLUME_NOT_AVAILABLE` | `0x8004060E` |

---

## Not Yet Implemented APIs

The following APIs or features are **not yet implemented** and will return **`E_NOTIMPL`** when called. This list is provided so callers can plan accordingly:

| API / Feature | Details |
|---|---|
| **`WslcSetContainerSettingsPortMappings`** — UDP protocol | Only **TCP** (`WSLC_PORT_PROTOCOL_TCP`) is supported. Passing `WSLC_PORT_PROTOCOL_UDP` returns `E_NOTIMPL`. |
| **`WslcCreateSessionVhdVolume`** / **`WslcSetSessionSettingsVhd`** — fixed VHD type | Only **dynamic** VHDs (`WSLC_VHD_TYPE_DYNAMIC`) are supported. Passing `WSLC_VHD_TYPE_FIXED` returns `E_NOTIMPL`. |

---

## End-to-End Example

The example below shows one full lifecycle:

1. Initialize session settings
2. Create a session
3. Pull an image
4. Configure a container
5. Create and start the container
6. Inspect it
7. Create a second process
8. Stop and delete the container
9. Release handles and terminate the session

```c

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <objbase.h>
#include <filesystem>
#include "wslcsdk.h"

#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "wslcsdk.lib")

int main()
{
    // Initialize COM
    CoInitializeEx(nullptr, COINIT_MULTITHREADED);

    HRESULT hr;
    PWSTR error = nullptr;

    // 0. Check prerequisites
    WslcComponentFlags missing = WSLC_COMPONENT_FLAG_NONE;
    hr = WslcGetMissingComponents(&missing);
    if (FAILED(hr) || missing != WSLC_COMPONENT_FLAG_NONE) {
        printf("WSL components are missing. Run: wsl --install\n");
        CoUninitialize();
        return 1;
    }

    WslcVersion ver = {};
    WslcGetVersion(&ver);
    printf("WSL version: %u.%u.%u\n", ver.major, ver.minor, ver.revision);

    // 1. Initialize and create a session
    std::filesystem::path storagePath = std::filesystem::current_path();

    WslcSessionSettings sessionSettings;
    hr = WslcInitSessionSettings(L"MyApp", storagePath.c_str(), &sessionSettings);
    if (FAILED(hr)) return 1;

    // Optionally customize resources
    WslcSetSessionSettingsCpuCount(&sessionSettings, 4);
    WslcSetSessionSettingsMemory(&sessionSettings, 4096);

    WslcSession session = nullptr;
    hr = WslcCreateSession(&sessionSettings, &session, &error);
    if (FAILED(hr)) {
        wprintf(L"Session creation failed: %s\n", error ? error : L"unknown");
        CoTaskMemFree(error);
        CoUninitialize();
        return 1;
    }

    // 2. Pull an image
    WslcPullImageOptions pullOpts = {};
    pullOpts.uri = "docker.io/library/alpine:latest";
    hr = WslcPullSessionImage(session, &pullOpts, &error);
    if (FAILED(hr)) {
        wprintf(L"Pull failed: %s\n", error ? error : L"unknown");
        CoTaskMemFree(error);
        WslcTerminateSession(session);
        WslcReleaseSession(session);
        CoUninitialize();
        return 1;
    }

    // 3. Configure an init process
    WslcProcessSettings initProcSettings;
    WslcInitProcessSettings(&initProcSettings);

    PCSTR argv[] = { "/bin/echo", "Hello from WSL Container!" };
    WslcSetProcessSettingsCmdLine(&initProcSettings, argv, 2);

    // 4. Configure and create a container
    WslcContainerSettings containerSettings;
    WslcInitContainerSettings("alpine:latest", &containerSettings);
    WslcSetContainerSettingsName(&containerSettings, "hello-container");
    WslcSetContainerSettingsInitProcess(&containerSettings, &initProcSettings);

    WslcContainer container = nullptr;
    hr = WslcCreateContainer(session, &containerSettings, &container, &error);
    if (FAILED(hr)) {
        wprintf(L"Container creation failed: %s\n", error ? error : L"unknown");
        CoTaskMemFree(error);
        WslcTerminateSession(session);
        WslcReleaseSession(session);
        CoUninitialize();
        return 1;
    }

    // 5. Start the container
    hr = WslcStartContainer(container, WSLC_CONTAINER_START_FLAG_NONE, &error);
    if (FAILED(hr)) {
        wprintf(L"Start failed: %s\n", error ? error : L"unknown");
        CoTaskMemFree(error);
        WslcDeleteContainer(container, WSLC_DELETE_CONTAINER_FLAG_FORCE, nullptr);
        WslcReleaseContainer(container);
        WslcTerminateSession(session);
        WslcReleaseSession(session);
        CoUninitialize();
        return 1;
    }

    // 6. Wait for the init process to exit
    WslcProcess initProc = nullptr;
    hr = WslcGetContainerInitProcess(container, &initProc);
    if (SUCCEEDED(hr)) {
        HANDLE exitEvent = nullptr;
        if (SUCCEEDED(WslcGetProcessExitEvent(initProc, &exitEvent))) {
            WaitForSingleObject(exitEvent, 30000); // 30-second timeout
        }

        INT32 exitCode = 0;
        if (SUCCEEDED(WslcGetProcessExitCode(initProc, &exitCode))) {
            printf("Process exited with code: %d\n", exitCode);
        }
        WslcReleaseProcess(initProc);
    }

    // 7. Clean up
    WslcContainerState containerState = WSLC_CONTAINER_STATE_INVALID;
    if (SUCCEEDED(WslcGetContainerState(container, &containerState)) &&
        containerState == WSLC_CONTAINER_STATE_RUNNING) {
        WslcStopContainer(container, WSLC_SIGNAL_SIGTERM, 10, nullptr);
    }
    WslcDeleteContainer(container, WSLC_DELETE_CONTAINER_FLAG_NONE, nullptr);
    WslcReleaseContainer(container);
    WslcTerminateSession(session);
    WslcReleaseSession(session);

    CoUninitialize();
    return 0;
}
```
