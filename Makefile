CC = gcc
FLAGS = -Wall -Wextra -Werror -lm -g
SRC_FOLDER= src
FILES = $(SRC_FOLDER)/main.c
OUTPUT_FOLDER = ./build

all:
	@clang-format -i $(SRC_FOLDER)/*.c
	@$(CC) $(FILES) $(FLAGS) -o $(OUTPUT_FOLDER)/main

run: all
	@$(OUTPUT_FOLDER)/main

clean:
	rm -rf ./build/*

rebuild: clean all