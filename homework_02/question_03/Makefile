## HW01 - Q03 Makefile ##

# Application Name
TARGET := q03

# Main Code
PROGRAM_A := q03a.c
PROGRAM_B := q03b.c
PROGRAM_C := q03c.c

# Headers
HEADER_DIR := headers/
HEADER_FILES := $(wildcard $(HEADER_DIR)*.h)

# Sources
SOURCE_DIR := sources/
SOURCE_FILES := $(wildcard $(SOURCE_DIR)*.c)

# Test Cases
TEST_CASE_ONE := tc1.in
TEST_CASE_TWO := tc2.in
TEST_CASE_THREE := tc3.in

# Compilation Settings
## gcc desired version: 4.9.2
GCC_FLAGS := -O2 -lm -Wall
COMPILE_A := gcc $(GCC_FLAGS) -I $(HEADER_DIR) $(HEADER_FILES) $(SOURCE_FILES) $(PROGRAM_A) -o $(TARGET)
COMPILE_B := gcc $(GCC_FLAGS) -lpthread -I $(HEADER_DIR) $(HEADER_FILES) $(SOURCE_FILES) $(PROGRAM_B) -o $(TARGET)
COMPILE_C := gcc $(GCC_FLAGS) -lpthread -I $(HEADER_DIR) $(HEADER_FILES) $(SOURCE_FILES) $(PROGRAM_C) -o $(TARGET)

.PHONY: a

a:
	@echo A version
	@$(COMPILE_A)

b:
	@echo B version
	@$(COMPILE_B)

c:
	@echo C version
	@$(COMPILE_C)

tc1:
	@./$(TARGET) < $(TEST_CASE_ONE)

tc2:
	@./$(TARGET) < $(TEST_CASE_TWO)

tc3:
	@./$(TARGET) < $(TEST_CASE_THREE)

clean:
	@rm -f $(TARGET)
