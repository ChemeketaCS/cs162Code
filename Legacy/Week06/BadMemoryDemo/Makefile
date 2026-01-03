.PHONY: all program
CPP = g++
CPP_FLAGS = -std=c++17 -g
WARNINGS = -Wall -Wextra -Wmissing-include-dirs -Wfloat-equal -Wredundant-decls -Winit-self -Wshadow -Wconversion
STANDARDS = -pedantic -pedantic-errors
PROGRAM_NAME = program.exe

PROGRAM_FILES = *.cpp
INCLUDE_DIRS = .
SHARED_FILES = 

all: program

program:
	-$(CPP) $(CPP_FLAGS) $(STANDARDS) $(WARNINGS) -I $(INCLUDE_DIRS) -o $(PROGRAM_NAME) $(SHARED_FILES) $(PROGRAM_FILES)