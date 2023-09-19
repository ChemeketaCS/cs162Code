.PHONY: all program tests
CPP = g++
CPP_FLAGS = -std=c++17 -g
WARNINGS = -Wall -Wextra -Wmissing-include-dirs -Wfloat-equal -Wredundant-decls -Winit-self -Wshadow -Wconversion
STANDARDS = -pedantic -pedantic-errors
PROGRAM_NAME = program.exe
TESTER_NAME = tests.exe

PROGRAM_FILES = main.cpp
TEST_FILES = CircleTester.cpp
INCLUDE_DIRS = . 
SHARED_FILES = Circle.cpp

all: program tests

program:
	-$(CPP) $(CPP_FLAGS) $(STANDARDS) $(WARNINGS) -I $(INCLUDE_DIRS) -o $(PROGRAM_NAME) $(SHARED_FILES) $(PROGRAM_FILES)

tests:
	-$(CPP) $(CPP_FLAGS) $(STANDARDS) $(WARNINGS) -I $(INCLUDE_DIRS) -o $(TESTER_NAME) $(SHARED_FILES) $(TEST_FILES)