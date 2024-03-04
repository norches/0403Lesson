CC = gcc
FLAGS = -Wall -Wextra -Werror -lm -g
SRC_FOLDER= src
FILES = $(SRC_FOLDER)/main.c
OUTPUT_FOLDER = ./build

all:
	@clang-format -i $(SRC_FOLDER)/*.c
	@$(CC) $(FILES) $(FLAGS) -o $(OUTPUT_FOLDER)/main

check_leaks: all
	cppcheck $(SRC_FOLDER)/*.c
	valgrind --tool=memcheck --leak-check=yes -s $(FILE)

run: all
	@$(OUTPUT_FOLDER)/main

run_debug: all
	@gdb $(OUTPUT_FOLDER)/main


clean:
	rm -rf ./build/*

rebuild: clean all