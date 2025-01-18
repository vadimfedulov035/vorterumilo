# Makefile

CC = gcc

VOCAB_DIR = vocab
SEARCH_DIR = search
LOWER_DIR = lower
OUT_DIR = out

MAP_DIR = maps
CORE_MAP = $(MAP_DIR)/core_map.c
META_MAP = $(MAP_DIR)/meta_map.c
ROOT_MAP = $(MAP_DIR)/root_map.c
SUFFIX_MAP = $(MAP_DIR)/suffix_map.c
MAIN = vorterumilo.c

OUTPUT = vorterumilo

all: $(OUTPUT) 

$(MAP_DIR):
	mkdir -p $(MAP_DIR)

$(CORE_MAP): $(MAP_DIR)
	gperf -t -o $(VOCAB_DIR)/cores.gperf > $(CORE_MAP)

$(META_MAP): $(MAP_DIR)
	gperf -t -o $(VOCAB_DIR)/meta.gperf > $(META_MAP)

$(ROOT_MAP): $(MAP_DIR)
	gperf -t -o $(VOCAB_DIR)/roots.gperf > $(ROOT_MAP)

$(SUFFIX_MAP): $(MAP_DIR)
	gperf -t -o $(VOCAB_DIR)/suffixes.gperf > $(SUFFIX_MAP)

$(OUTPUT): $(MAIN) $(CORE_MAP) $(META_MAP) $(ROOT_MAP) $(SUFFIX_MAP)
	$(CC) -g -O2 -o $(OUTPUT) $(MAIN) $(MAP_DIR)/* $(SEARCH_DIR)/* $(LOWER_DIR)/* $(OUT_DIR)/*

clean:
	rm -rf $(OUTPUT)
cleaner:
	rm -rf $(OUTPUT) $(MAP_DIR)

.PHONY: all clean
