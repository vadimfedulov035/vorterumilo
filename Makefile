# Makefile

CC = gcc

SEARCH_DIR = search
VOCAB_DIR = vocab
MAP_DIR = maps

CORE_MAP = $(MAP_DIR)/core_map.c
META_MAP = $(MAP_DIR)/meta_map.c
ROOT_MAP = $(MAP_DIR)/root_map.c
SUFFIX_MAP = $(MAP_DIR)/suffix_map.c
MAIN = main.c

INPUT = data/tekstaro.txt
OUTPUT = main

all: $(INPUT) $(OUTPUT) 

$(INPUT):
	[ ! -f data/tekstaro.txt ] && ./data/extract.py

$(CORE_MAP): 
	mkdir -p $(MAP_DIR) 
	gperf -t -o $(VOCAB_DIR)/cores.gperf > $(CORE_MAP)

$(META_MAP): 
	gperf -t -o $(VOCAB_DIR)/meta.gperf > $(META_MAP)

$(ROOT_MAP): 
	gperf -t -o $(VOCAB_DIR)/roots.gperf > $(ROOT_MAP)

$(SUFFIX_MAP): 
	gperf -t -o $(VOCAB_DIR)/suffixes.gperf > $(SUFFIX_MAP)

$(OUTPUT): $(MAIN) $(CORE_MAP) $(META_MAP) $(ROOT_MAP) $(SUFFIX_MAP)
	$(CC) -g -O2 -o $(OUTPUT) $(MAIN) $(MAP_DIR)/* $(SEARCH_DIR)/*

clean:
	rm -rf $(OUTPUT)
cleaner:
	rm -rf $(OUTPUT) $(MAP_DIR)
cleanest:
	rm -rf $(OUTPUT) $(MAP_DIR) $(INPUT)

.PHONY: all clean
