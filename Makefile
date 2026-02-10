CC      := gcc
CFLAGS  := -O2 -std=c11 -Wall -Wextra -Iinclude
LDFLAGS := -pthread -lm

# Default submission
SUBMISSION ?= submissions/example/sort.c

SRC := src/benchmark.c src/baseline.c $(SUBMISSION)
BIN := arena

.PHONY: all run clean

all: $(BIN) ## Build the benchmark

$(BIN): $(SRC) include/arena.h
	$(CC) $(CFLAGS) -o $@ $(SRC) $(LDFLAGS)

run: $(BIN) ## Run benchmark (1K ~ 10K)
	./$(BIN)

clean: ## Clean build artifacts
	rm -f $(BIN)
