# Thomson MO5 Assembly Tutorials

This repository contains a set of **assembly language tutorials for the Thomson MO5**, designed to demonstrate basic input/output and keyboard handling using real MO5-compatible tools.

Each tutorial is self-contained and built using a common root `Makefile`.

---

## Prerequisites

- [DCMOTO](http://dcmoto.free.fr/emulateur/index.html) emulator
- [LWTOOLS](https://www.lwtools.ca/) cross-development tools for the Motorola 6809 and Hitachi 6309 microprocessors
- [CMOC](http://gvlsywt.cluster051.hosting.ovh.net/dev/cmoc.html) Motorola 6809 compiler

⚠️ Most of these sites are served over HTTP (not secure), which triggers some warnings in modern browsers.
But don’t worry: they are reliable historical references in the retro-computing world.

## 📁 Project Structure

```text
.
├── Makefile              # Root Makefile (builds all tutorials)
├── tools/                # External tools (installed automatically)
│   └── BootFloppyDisk/   # BootFloppyDisk tools repository
├── libs/                 # Home made libs dedicated to mo5
│   ├── mo5_lib.h         # interface
│   └── mo5_lib.c         # implementation
├── tutorial1/            # Tutorial 1: User input example
│   └── Makefile
├── tutorial2/            # Tutorial 2: Keyboard scan example
│   └── Makefile
```

## 📦 Installing the Tools

Before building, install the required MO5 tools:
```bash
make install
```

This will:

- Clone the BootFloppyDisk repository
- Build the required tools
- Generate BOOTMO.BIN needed for disk images

## 🚀 Building the Project
### Build all tutorials
```bash
make
```

### Build a single tutorial
```bash
make tutorial1
make tutorial2
```

### Clean build files

#### Clean everything:
```bash
make clean
```

#### Clean a single tutorial:
```bash
make tutorial1-clean
```

## Shared Libraries (`libs/`)

Programs in this repository rely on shared C libraries located in the `libs/` directory.

```text
libs/
├── mo5_lib.c
└── mo5_lib.h
```


Each program has its own `src/main.c` and **does not copy** the library files.

The integration is handled entirely by the Makefile:
- Library source files (`.c`) are compiled and linked with the program
- Header files (`.h`) are included in the code using:

```c
#include "mo5_lib.h"
 ```

The library include path is passed to the compiler via -I

Example from the Makefile:

```make
LIBS_DIR   := ../libs
CMOC_FLAGS := --thommo --org=2600 -I$(LIBS_DIR)
```
This approach allows multiple programs to share the same MO5-specific code without duplication.

## 📘 Tutorials Overview
### Tutorial 1 — Name Greeting Program

This tutorial demonstrates basic user input.

The program asks the user to enter a first name

It then displays a greeting message:

Bonjour [name]

Concepts covered:

- Keyboard input
- String handling
- Text output
- Basic program flow

### Tutorial 2 — Key Code Display Program

This tutorial focuses on keyboard handling.

The program waits for a key press

It displays the character code of the pressed key

Concepts covered:

- Low-level keyboard scanning
- Character codes
- Real-time input handling

## 🙌 Credits

BootFloppyDisk tools by OlivierP-To8

Thomson MO5 documentation and community resources