---
title: WSL container settings
description: Learn how to configure WSL container (wslc.exe) settings, such as CPU, memory, storage, and port binding options, using the wslc settings.yaml file.
keywords: wsl, windows, windows subsystem, wslc, container, settings, settings.yaml, configuration
ms.date: 10/16/2026
ms.topic: how-to
---

# WSL container settings

You can customize how [`wslc.exe`](./wsl-container.md#wsl-container-cli) runs containers, such as how many CPUs and how much memory the container session can use, with a per-user YAML settings file located at `%LOCALAPPDATA%\wslc\settings.yaml`.

## Open the settings file

The settings file doesn't exist by default. To create it and open it in your default editor for `.yaml` files (or Notepad, if no editor is associated), run:

```powershell
wslc settings
```

The first time you run this command, `wslc` creates the file with every setting commented out and set to `default`. Uncomment a line and replace `default` with your value to change a setting. To overwrite the file with the commented-out defaults again, run:

```powershell
wslc settings reset
```

Here's an example `settings.yaml` file:

```yaml
session:
  cpuCount: 4
  memorySize: 8GB
  maxStorageSize: 500GB
  storagePath: D:\data
  defaultBindingAddress: 127.0.0.1
  hostLoopback: host.wslc.internal
  idleTimeout: 60
```

## Available settings

Every setting accepts the value `default`, which uses the built-in default. Settings that are missing from the file also use the built-in default.

| Setting | Value | Default | Description |
| --- | --- | --- | --- |
| `session.cpuCount` | number | All logical processors | Number of virtual processors assigned to the container session. Must be greater than 0. |
| `session.memorySize` | size | 50% of total memory on Windows | Maximum amount of memory assigned to the container session, for example `8GB`. |
| `session.maxStorageSize` | size | `1TB` | Maximum size of the virtual disk (VHDX) that stores the session's images and containers, for example `500GB`. |
| `session.storagePath` | path | `%LOCALAPPDATA%` | Absolute base directory for the default session's storage. The virtual disk is created at `<storagePath>\wslc\sessions\<session>\storage.vhdx`. |
| `session.defaultBindingAddress` | IPv4 address | `127.0.0.1` | Host address that published ports bind to when you use `wslc container run -p` without specifying an address. Set to `0.0.0.0` to bind to all host interfaces. |
| `session.hostLoopback` | string | `host.wslc.internal` | DNS name that containers can use to reach the Windows host. Set to `none` to disable this name. |
| `session.idleTimeout` | number | `30` | Number of seconds the session VM stays running after it becomes idle before it shuts down. Must be greater than 0. |
| `credentialStore` | `wincred` or `file` | `wincred` | Where container registry credentials from `wslc login` are stored. `wincred` uses Windows Credential Manager. `file` uses a DPAPI-encrypted file at `%LOCALAPPDATA%\wslc\registry-credentials.json`. |

Size values are an integer followed by an optional unit: `B`, `K`/`KB`, `M`/`MB`, `G`/`GB`, `T`/`TB`, or `P`/`PB` (case-insensitive). Units are binary, so `1GB` is 1024 MB. A value without a unit is interpreted as bytes, and the minimum value is 1 MB.

> [!NOTE]
> Changing `session.storagePath` after a session already exists doesn't move existing images, containers, or storage. The previous storage is left in place, and a new, empty session is created at the new location.

## When changes take effect

- Session settings (`session.*`) are read when the container session starts. If a session is already running, stop it with `wslc system session terminate` so that the next `wslc` command starts a new session with your updated settings. A session also shuts down on its own after it has been idle for `session.idleTimeout` seconds.
- `session.defaultBindingAddress` and `credentialStore` are read each time you run a `wslc` command.

If the settings file contains an unknown setting, an invalid value, or invalid YAML, `wslc` prints a warning that includes the file path and line number, and uses the built-in default for the affected settings.

> [!NOTE]
> These settings apply to the session that `wslc.exe` uses. Settings in [`.wslconfig`](./wsl-config.md#wslconfig) don't apply to WSL containers. Applications that use the [WSL container API](./wsl-container.md#wsl-container-api) configure their own sessions in code, for example with `SessionSettings`.

## Additional resources

- [WSL container](./wsl-container.md)
- [Get started with WSL container](./tutorials/wsl-containers.md)
- [Advanced settings configuration in WSL](./wsl-config.md)
