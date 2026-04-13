# compiler options
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -std=c++20 -fmodules-ts -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion -Wuninitialized

# list your .h files here
HEADERS = 

# list .cpp files here according to main program, tests, or both
PROGRAM_FILES = *.cpp
TEST_FILES = *.cpp
SHARED_FILES =

.PHONY: all
all: program.exe

.PHONY: program.exe # Always force rebuild of tests
program.exe: $(PROGRAM_FILES) $(SHARED_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SHARED_FILES) $(PROGRAM_FILES) -o $@


.PHONY: clean
clean:
	rm -f program.exe
