# Makefile

# Compiler
CC = gcc

# Directories
SEARCH_DIR = search
VOCAB_DIR = vocab
MAP_DIR = maps

# Source files
CORE_MAP = $(MAP_DIR)/core_map.c
META_MAP = $(MAP_DIR)/meta_map.c
ROOT_MAP = $(MAP_DIR)/root_map.c
SUFFIX_MAP = $(MAP_DIR)/suffix_map.c
MAIN = main.c

# Output executable
OUTPUT = main

# Default target
all: $(OUTPUT)

# Precompile directives
$(CORE_MAP): 
	mkdir -p $(MAP_DIR) 
	gperf -t -o $(VOCAB_DIR)/cores.gperf > $(CORE_MAP)

$(META_MAP): 
	gperf -t -o $(VOCAB_DIR)/meta.gperf > $(META_MAP)

$(ROOT_MAP): 
	gperf -t -o $(VOCAB_DIR)/roots.gperf > $(ROOT_MAP)

$(SUFFIX_MAP): 
	gperf -t -o $(VOCAB_DIR)/suffixes.gperf > $(SUFFIX_MAP)

# Compile directives
$(OUTPUT): $(MAIN) $(CORE_MAP) $(META_MAP) $(ROOT_MAP) $(SUFFIX_MAP)
	$(CC) -O2 -o $(OUTPUT) $(MAIN) $(MAP_DIR)/* $(SEARCH_DIR)/*

# Clean directives
clean:
	rm -rf $(MAP_DIR) $(OUTPUT)

.PHONY: all clean
