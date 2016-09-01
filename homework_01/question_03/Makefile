## HW01 - Q03 Makefile ##

# Application Name
TARGET := q03

# Main Code
MAIN := main.c

# Headers
HEADER_DIR := headers/
HEADER_FILES := $(wildcard $(HEADER_DIR)*.h)

# Sources
SOURCE_DIR := sources/
SOURCE_FILES := $(wildcard $(SOURCE_DIR)*.c)

# Test Cases
TEST_CASE_ONE := tc1.in
TEST_CASE_TWO := tc2.in

# Compilation Settings
## gcc desired version: 4.9.2
GCC_FLAGS = -O2 -lm -Wall
COMPILE = gcc $(GCC_FLAGS) -I $(HEADER_DIR) $(HEADER_FILES) $(SOURCE_FILES) $(MAIN) -o $(TARGET)

.PHONY: all

all:
	@make --always-make --no-print-directory main

main:
	@$(COMPILE)

tc1:
	@make all
	@./$(TARGET) < $(TEST_CASE_ONE)

tc2:
	@make all
	@./$(TARGET) < $(TEST_CASE_TWO)

clean:
	@rm -f --no-print-directory $(TARGET)
