# ==========================================================
# Thomson MO5 Development - Multi-Tutorial Makefile
# ==========================================================
#
# Author : Thierry Le Got
# License: MIT
#
# This Makefile manages building multiple CMOC tutorials for
# the Thomson MO5 platform, including binary compilation
# and creation of bootable floppy disk images using
# BootFloppyDisk by OlivierP (https://github.com/OlivierP-To8/BootFloppyDisk)
#
# Usage:
#   make                 - Build all tutorials
#   make sample1       	 - Build sample1 (binary + disk image)
#   make sample1-clean   - Remove all generated files for tutorial1
#   make install         - Install BootFloppyDisk tools
#   make clean           - Remove all generated files
#
# ==========================================================

# Default target
.DEFAULT_GOAL := all

# Paths
TOOLS_DIR   := ../tools
BOOTFD_DIR  := $(TOOLS_DIR)/BootFloppyDisk
FDFS        := $(BOOTFD_DIR)/tools/fdfs
BOOTMO_BIN  := $(TOOLS_DIR)/BOOTMO.BIN

# List of tutorials
TUTORIALS   := what_is_your_name key_reader fusee

# ==========================================================
# TARGETS
# ==========================================================

.PHONY: all clean $(TUTORIALS) $(addsuffix -clean,$(TUTORIALS))

# Build all tutorials
all: $(TUTORIALS)

# Build individual tutorial
$(TUTORIALS):
	$(MAKE) -C $@

# Clean all tutorials
clean: $(addsuffix -clean,$(TUTORIALS))

# Clean individual tutorial
$(addsuffix -clean,$(TUTORIALS)):
	$(MAKE) -C $(patsubst %-clean,%,$@) clean
