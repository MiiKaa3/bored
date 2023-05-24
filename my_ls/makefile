BIN = ./bin
SRC = ./src
OBJ = ./obj
INC = ./include

CC = gcc
CC_ARGS = -Werror -Wall -Wpedantic -Wextra -std=c99 -I$(INC)
CC_DEBUG = -D__LS_DEBUG__ 
APP = ./ls

HASHFUNC = python3 ./hash.py

default: mkdirs debug release
	@echo DONE!

release: mkdirs main.o my_ls.o
	@echo Building Release ...
	@$(CC) $(CC_ARGS) $(OBJ)/*.o -o $(BIN)/$(APP)

debug: mkdirs main.o my_ls.o
	@echo Building Debug ...
	@$(CC) $(CC_ARGS) $(CC_DEBUG) $(OBJ)/*.o -o $(BIN)/$(APP)_debug
	
clean:
	@echo Cleaning ...
	@rm -rf $(BIN) $(OBJ)

mkdirs:
	@echo Creating Directories ...
	@mkdir -p $(BIN) $(OBJ) 

main.o:
	@echo Compiling main.c ...
	@$(HASHFUNC) $(SRC)/main.c > $(OBJ)/main.checksum
	@$(CC) $(CC_ARGS) $(SRC)/main.c -c -o $(OBJ)/main.o

my_ls.o:
	@echo Compiling my_ls.c ...
	@$(HASHFUNC) $(SRC)/my_ls.c > $(OBJ)/my_ls.checksum
	@$(CC) $(CC_ARGS) $(SRC)/my_ls.c -c -o $(OBJ)/my_ls.o
