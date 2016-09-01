## HW01 - Q02 Makefile ##

# Application Name
TARGET := q02

# Main Code
MAIN := main.c

# Headers
HEADER_DIR := headers/
HEADER_FILES := $(wildcard $(HEADER_DIR)*.h)

# Sources
SOURCE_DIR := sources/
SOURCE_FILES := $(wildcard $(SOURCE_DIR)*.c)

# Test Cases
TEST_CASE_ONE := 1 11 5 21 10 31 15 41 20 51 25
TEST_CASE_TWO := 20 20 15 15 30 30 40 5 5 2
TEST_CASE_THREE := -d 1 2 3 4 5 10 9 8 7 6
TEST_CASE_FOUR := -r 1 2 3 4 5 10 9 8 7 6
TEST_CASE_FIVE := -r 5 -d 2 -r 25
TEST_CASE_SIX := -40 40 -30 30 -20 20 -10 10 0

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
	@./$(TARGET) $(TEST_CASE_ONE)

tc2:
	@make all
	@./$(TARGET) $(TEST_CASE_TWO)

tc3:
	@make all
	@./$(TARGET) $(TEST_CASE_THREE)

tc4:
	@make all
	@./$(TARGET) $(TEST_CASE_FOUR)

tc5:
	@make all
	@./$(TARGET) $(TEST_CASE_FIVE)

tc6:
	@make all
	@./$(TARGET) $(TEST_CASE_SIX)

clean:
	@rm -f $(TARGET)
