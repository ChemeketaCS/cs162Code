# compiler options
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -std=c++17 -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion -Wno-deprecated-copy

# list your .h files here
HEADERS = Circle.h

# list .cpp files here according to main program, tests, or both
PROGRAM_FILES = main.cpp
TEST_FILES = CircleTester.cpp
SHARED_FILES = Circle.cpp

.PHONY: all
all: program.exe tests.exe

program.exe: $(PROGRAM_FILES) $(SHARED_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(PROGRAM_FILES) $(SHARED_FILES) -o $@

tests.exe: $(TEST_FILES) $(SHARED_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_FILES) $(SHARED_FILES) -o $@

.PHONY: clean
clean:
	rm -f program.exe
