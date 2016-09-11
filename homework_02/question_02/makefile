NAME = q02
SEQUENTIAL_NAME = sequential_q02

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
SEQUENTIAL_DIR = sequential

TARGET = $(BIN_DIR)/$(NAME)
SEQUENTIAL = $(BIN_DIR)/$(SEQUENTIAL_NAME)

PROGRAM_SEQUENTIAL = sequential/sequential.c

CC = gcc
CFLAGS = -Wall -g -lpthread

SRC = ${wildcard $(SRC_DIR)/*.c}
SEQUENTIAL_SRC =  src/vector_handler.c src/arguments_handler.c src/benchmark.c
OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SRC:.c=.o}}}
SEQUENTIAL_OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SEQUENTIAL_SRC:.c=.o}}}

COMPILE_SEQUENTIAL := $(CC) $(CFLAGS) -I$(INC_DIR) $(SEQUENTIAL_SRC) $(PROGRAM_SEQUENTIAL) -o $(SEQUENTIAL)

.PHONY: clean dist-clean sequential

all:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)
	$(MAKE) $(TARGET)

sequential:
	@echo Sequential Version
	@echo $(COMPILE_SEQUENTIAL)
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)
	@$(COMPILE_SEQUENTIAL)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo construindo o objeto $@
	@$(CC) -c $(CFLAGS) -I$(INC_DIR) $< -o $@

$(TARGET): $(OBJ)
	@echo criando executável...
	$(CC) $(OBJ) $(CFLAGS) -o $@
	@echo terminado

clean:
	@echo Limpando....
	@find . -name *.o -exec rm {} \;
	@rm -rf *~ *.o prog out.txt

dist-clean: clean
	@echo Limpando com dist-clean...
	@rm -f $(TARGET)/$(NAME)
	@rm -rf $(BIN_DIR)
	@rm -rf $(OBJ_DIR)
