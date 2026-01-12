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

PROGRAM := KEY_READER

# Paths
TOOLS_DIR  := ../../tools
BOOTFD_DIR := $(TOOLS_DIR)/BootFloppyDisk
FDFS       := $(BOOTFD_DIR)/tools/fdfs
BOOTMO_BIN := $(TOOLS_DIR)/BOOTMO.BIN

# Directories
LIBS_DIR   := ../libs
SRC_DIR    := src
BIN_DIR    := bin
OUTPUT_DIR := output

# Files
MAIN_SRC    := $(SRC_DIR)/main.c
LIB_SRC     := $(LIBS_DIR)/mo5_ctype.c $(LIBS_DIR)/mo5_stdio.c $(LIBS_DIR)/mo5_defs.c
LIB_HDR     := $(LIBS_DIR)/mo5_ctype.h $(LIBS_DIR)/mo5_stdio.h $(LIBS_DIR)/mo5_defs.h
PROGRAM_BIN := $(BIN_DIR)/$(PROGRAM).BIN
DISK_IMAGE  := $(OUTPUT_DIR)/$(PROGRAM).fd

# Compiler
CMOC       := cmoc
CMOC_FLAGS := --thommo --org=2600 -I$(LIBS_DIR) -Wno-assign-in-condition

# ========================================
# TARGETS
# ========================================

.PHONY: all clean

# Build everything
all: $(DISK_IMAGE)

# Compile binary
$(PROGRAM_BIN): $(MAIN_SRC) $(LIB_SRC) $(LIB_HDR)
	@mkdir -p $(BIN_DIR)
	@echo "Compiling..."
	@$(CMOC) $(CMOC_FLAGS) -o $@ $(MAIN_SRC) $(LIB_SRC)
	@echo "✓ Binary: $@"

# Create disk image
$(DISK_IMAGE): $(PROGRAM_BIN)
	@mkdir -p $(OUTPUT_DIR)
	@echo "Creating disk image..."
	@$(FDFS) -addBL $@ $(BOOTMO_BIN) $(PROGRAM_BIN)
	@echo "✓ Disk: $@"

# Clean
clean:
	@rm -rf $(BIN_DIR) $(OUTPUT_DIR)
	@echo "✓ Clean"
