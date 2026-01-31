#!CUSTOM!
# force macs to use g++-15 to avoid clang mapped to g++
OS_NAME := $(shell uname -s)
ifeq ($(OS_NAME),Darwin)
	CXX = g++-15
else
	CXX = g++
endif

# compiler options
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -std=c++20 -fmodules-ts -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion -Wuninitialized
# uncomment the following lines to enable address sanitizer on non-Windows platforms
ifneq ($(OS),Windows_NT)
	CXXFLAGS += -fsanitize=address
endif

# list .h files here
HEADERS = TemplateLibrary.h PlainLibrary.h

# list .cpp files here
PROGRAM_FILES = main.cpp
SHARED_FILES = PlainLibrary.cpp

.PHONY: all
all: program.exe

.PHONY: program.exe # Always force rebuild of program
program.exe:  $(SHARED_FILES) $(PROGRAM_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SHARED_FILES) $(PROGRAM_FILES) -o $@

.PHONY: clean
clean:
	rm -f program.exe
