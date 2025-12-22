# Thomson MO5 Assembly Tutorials

This repository contains a set of **assembly language tutorials for the Thomson MO5**, designed to demonstrate basic input/output and keyboard handling using real MO5-compatible tools.

Each tutorial is self-contained and built using a common root `Makefile`.

---

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

## 📘 Tutorials Overview
### Tutorial 1 — Name Greeting Program

This tutorial demonstrates basic user input.

The program asks the user to enter a first name

It then displays a greeting message:

Bonjour <name>


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