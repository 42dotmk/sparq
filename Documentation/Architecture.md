
# sparq, an architecture overview

This document explains the internal layering of `sparq`, how it is intended to be consumed by downstream projects and recommended workflows for working with both host builds (via `vcpkg`) and ESP32 firmware builds (via ESP-IDF Component Manager). It contains a short guide for beginners and deeper notes for senior engineers.

## High-level goals
- Provide a small, well-scoped C++ framework for embedded projects (drones, robotics, IoT).
- Keep MCU-specific code separated from framework logic so host-side simulation and unit tests are easy.
- Let each build system do what it does best: `vcpkg` for host/package management; ESP-IDF for ESP32 firmware builds.

## Layering

The repository is intentionally small and focused. The following layers are the canonical structure and the ones you should treat as public API surfaces when consuming `sparq`.

- `Common/`
  - Pure header-only utilities, types, common definitions and small helpers used across layers.
  - Must be portable and not depend on target-specific APIs.

- `HardwareAbstractionLayer/` (`HAL`)
  - The framework-facing contracts: abstract interfaces describing hardware features the application needs (e.g., `IMotorController`, `IImu`, `IBatteryMonitor`).
  - HAL must be header-only / interface-only so host code can mock or implement it.

- `PlatformAbstractionLayer/` (`PAL`)
  - MCU-specific implementations of HAL contracts. For example `PlatformAbstractionLayer/Esp32` contains implementations that use ESP-IDF drivers and FreeRTOS primitives.
  - PAL is the place to put concrete peripheral integrations, DMA/PWM drivers and board-specific configuration.

Notes:
- Keep `HAL` and `Common` fully platform-agnostic. This makes them safe to publish via `vcpkg` as the canonical shared component.
- Keep `PAL` out of `vcpkg` builds (it is only compiled when an ESP-IDF build is running and should be fetched by ESP-IDF's component manager for firmware builds).
- If you later add another RTOS or a host runtime, reintroduce a small OS abstraction layer with one stable interface.
- If drivers become reusable across MCUs and OSes, they can be introduced as a top-level directory `Drivers/`, otherwise keep them inside PAL implementations.

## How downstream users should consume `sparq`

Two distinct workflows are supported intentionally:

1. Host / Simulation / Unit Tests (developer machine)

   - Use `vcpkg` to install `sparq` from our registry (`base42-vcpkg-registry`).
   - `vcpkg` builds the portable parts (`Common`, `HardwareAbstractionLayer`) as libraries or header-only packages the host can link against.
   - This workflow enables fast iteration, CI unit tests and desktop simulation without requiring ESP32 toolchains.

2. ESP32 / Target Firmware (flashed to hardware)

   - Use ESP-IDF's *Component Manager* to fetch `sparq` as a component and build it together with the app via `idf.py build`.
   - ESP-IDF expects `idf_component_register()` style components and compiles them with the exact ESP32 cross-toolchain and build flags. This guarantees correct linking, partition tables and Kconfig integration.
   - Do not attempt to use `vcpkg` to cross-compile ESP-IDF components for target firmware builds, the tooling philosophies differ and it leads to fragile builds.

   Example `idf_component.yml` entry in your app to consume only the ESP32 component subtree:

   ```yaml
   dependencies:
     sparq:
       git: https://github.com/42dotmk/sparq.git
       path: PlatformAbstractionLayer/Esp32
   ```

   Then in the app repository:

   ```bash
   > idf.py set-target esp32
   > idf.py build
   > idf.py flash
   ```

## Packaging and the base42 `vcpkg` registry

- Publish only the portable framework surfaces to `vcpkg` (`Common`, `HardwareAbstractionLayer`). The root package `sparq` in the registry should not include ESP32 PAL sources in its `vcpkg` build. The `PlatformAbstractionLayer/Esp32` directory is consumed only by ESP-IDF Component Manager.
- This repository already includes a `vcpkg.json` at the root that enumerates the package metadata. Keep that manifest minimal and portable.
- `base42-vcpkg-registry` contains a `ports/sparq/portfile.cmake` that clones `sparq` and runs `vcpkg_cmake_configure()` for the portable parts. That port must not pass ESP-specific flags.

## Beginner checklist

1. For desktop test builds:
   - Install `vcpkg`, set it up as a CMake toolchain.
   - Run `vcpkg install sparq` (using `base42-vcpkg-registry`).
   - `find_package(sparq CONFIG REQUIRED)` and link `sparq` to your app.

2. For flashing to ESP32:
   - Add `idf_component.yml` to your app pointing to `sparq` `PlatformAbstractionLayer/Esp32`.
   - Run `idf.py build` / `idf.py flash`.

## Senior notes / rationale (for maintainers)

- Separating portable API and platform implementation reduces CI complexity. `vcpkg` remains the single source of truth for host consumers and CI, while ESP-IDF remains the single source of truth for target firmware builds.
- Avoid trying to jam ESP-IDF into `vcpkg` or vice versa. Differences in toolchains, Kconfig, and component discovery make cross-compilation brittle.
- If you ever need to support multiple RTOSes or host runtimes (POSIX threads, Windows threads), reintroduce a thin OS abstraction. Keep it minimal: only the APIs you actually need (timers, threads, mutexes). Prioritize adapters over large virtual machine layers.
- Keep driver code inside PAL until you identify code that is truly shared across unrelated MCUs, then move it to a `Drivers/` layer with stable public API.

## FAQ

- Q: Can I install `sparq` with `vcpkg` and also use ESP-IDF?

> A: Yes, use `vcpkg` for host builds and ESP-IDF Component Manager for target firmware. They serve different purposes and can coexist.

- Q: Should `PlatformAbstractionLayer/Esp32` be part of the `vcpkg` port?

> A: No. Keep it out of `vcpkg` so the port remains portable and small. ESP-IDF will fetch the ESP32 component independently.
