# Makefile for Thomson MO5 development
#
# Usage:
#   make                 - Build all tutorials
#   make tutorial1       - Build everything (binary + disk image)
#   make tutorial1-clean - Remove all generated files
#   make install         - Install BootFloppyDisk tools
#   make clean           - Remove all generated files

# ========================================
# CONFIGURATION
# ========================================

.DEFAULT_GOAL := all

# Paths
TOOLS_DIR  := tools
BOOTFD_DIR := $(TOOLS_DIR)/BootFloppyDisk
FDFS       := $(BOOTFD_DIR)/tools/fdfs
BOOTMO_BIN := $(TOOLS_DIR)/BOOTMO.BIN

TEMPLATES  := tutorial1 tutorial2

# ========================================
# TARGETS
# ========================================

.PHONY: all clean $(TEMPLATES) $(addsuffix -clean,$(TEMPLATES)) install

# Build all tutorials
all: $(TEMPLATES)

# Build each tutorial
$(TEMPLATES):
	$(MAKE) -C $@

# Clean global
clean: $(addsuffix -clean,$(TEMPLATES))

# Clean individual
$(addsuffix -clean,$(TEMPLATES)):
	$(MAKE) -C $(patsubst %-clean,%,$@) clean

# Install BootFloppyDisk
install:
	@command -v git >/dev/null || { echo "git is required"; exit 1; }
	@echo "Installing BootFloppyDisk..."
	@mkdir -p "$(TOOLS_DIR)"
	@if [ ! -d "$(BOOTFD_DIR)" ]; then \
		git clone https://github.com/OlivierP-To8/BootFloppyDisk.git "$(BOOTFD_DIR)"; \
	fi
	@chmod +x "$(BOOTFD_DIR)/tools/"* 2>/dev/null || true
	@$(MAKE) -C "$(BOOTFD_DIR)"
	@cd "$(BOOTFD_DIR)" && ./tools/c6809 -bl BootMO.asm "../../$(BOOTMO_BIN)"
	@echo "✓ Installation complete!"
