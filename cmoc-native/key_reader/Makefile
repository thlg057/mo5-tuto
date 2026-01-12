# ==========================================================
# MO5 Tutorial
# ==========================================================
#
# Author : Thierry Le Got
# License: MIT
#
# This Makefile builds a Thomson MO5 program using CMOC,
# and packages it into a bootable floppy disk image using
# BootFloppyDisk by OlivierP (https://github.com/OlivierP-To8/BootFloppyDisk)
#
# Requirements:
#   - CMOC installed (system or local)
#   - BootFloppyDisk tools (fdfs)
#   - BOOTMO.BIN bootloader
#
# Usage:
#   make          # compile and build .fd disk image
#   make clean    # remove binaries and output
#
# ==========================================================

PROGRAM     := KEY_READER

# External tools paths
TOOLS_DIR   := ../../tools
BOOTFD_DIR  := $(TOOLS_DIR)/BootFloppyDisk
FDFS        := $(BOOTFD_DIR)/tools/fdfs
BOOTMO_BIN  := $(TOOLS_DIR)/BOOTMO.BIN

# Project directories
SRC_DIR     := src
BIN_DIR     := bin
OUTPUT_DIR  := output

# Target files
PROGRAM_BIN := $(BIN_DIR)/$(PROGRAM).BIN
DISK_IMAGE  := $(OUTPUT_DIR)/$(PROGRAM).fd

# Compiler settings
CMOC        := cmoc
CMOC_FLAGS  := --thommo --org=2600 -Wno-assign-in-condition

# ==========================================================
# TARGETS
# ==========================================================

.PHONY: all clean

all: $(DISK_IMAGE)

# Compile the binary
$(PROGRAM_BIN): $(SRC_DIR)/main.c
	@mkdir -p $(BIN_DIR)
	@echo "Compiling with system CMOC..."
	@$(CMOC) $(CMOC_FLAGS) -o $@ $<
	@echo "✓ Binary ready: $@"

# Create the floppy disk image
$(DISK_IMAGE): $(PROGRAM_BIN)
	@mkdir -p $(OUTPUT_DIR)
	@echo "Generating .fd disk image..."
	@$(FDFS) -addBL $@ $(BOOTMO_BIN) $(PROGRAM_BIN)
	@echo "✓ Disk image ready: $@"

# Clean generated files
clean:
	@rm -rf $(BIN_DIR) $(OUTPUT_DIR)
	@echo "✓ Clean complete"
