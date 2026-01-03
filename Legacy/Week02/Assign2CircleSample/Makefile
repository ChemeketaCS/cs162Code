# compiler options
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -std=c++17 -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion -Wno-deprecated-copy

# list your .h files here
HEADERS = Circle.h Point.h

# list .cpp files here
TEST_FILES = tests.cpp Circle.cpp Point.cpp

.PHONY: all
all: tests.exe

tests.exe: $(TEST_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_FILES) $(SHARED_FILES) -o $@

.PHONY: clean
clean:
	rm -f tests.exe
