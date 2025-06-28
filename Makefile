# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lm

# Directories
SRCDIR = src
BINDIR = bin
TARGET = $(BINDIR)/main

# Source files
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/cli.c

# Default target
all: $(TARGET)

# Compile directly to executable
$(TARGET): $(SOURCES)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Clean up
clean:
	rm -f $(TARGET)

.PHONY: all clean
