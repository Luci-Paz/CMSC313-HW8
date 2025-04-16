# Makefile for Matrix Programs	

# Compiler
CXX = g++

# Build types
RELEASE_FLAGS = -std=c++11 -Wall -Wextra -O2
DEBUG_FLAGS = -std=c++11 -Wall -Wextra -g

# Default build type
CXXFLAGS = $(RELEASE_FLAGS)

# executable names
CXX_EXE = matrixTestCpp

# Source and object files
SRCS = matrixTest.cpp matrix.cpp
OBJS = $(SRCS:.cpp=.o)

# Default: Release build
all: CXXFLAGS := $(RELEASE_FLAGS)
all: $(CXX_EXE)

# Debug build
debug: CXXFLAGS := $(DEBUG_FLAGS)
debug: $(CXX_EXE)

# Link object files to create executable
$(CXX_EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(CXX_EXE) $(OBJS)

.PHONY: all clean
