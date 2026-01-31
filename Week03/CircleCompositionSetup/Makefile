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

# list .h files here
HEADERS = Circle.h Point.h

# list .cpp files here
TEST_FILES = tests.cpp
SHARED_FILES = Circle.cpp Point.cpp

.PHONY: all
all: tests.exe

.PHONY: tests.exe # Always force rebuild of program
tests.exe:  $(SHARED_FILES) $(TEST_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SHARED_FILES) $(TEST_FILES) -o $@

.PHONY: clean
clean:
	rm -f tests.exe
