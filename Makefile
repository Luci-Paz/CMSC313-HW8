# Makefile for Matrix Programs	

# Compiler
CC = gcc
CXX = g++


# Release flags
RELEASE_FLAGS_CXX = -std=c++11 -Wall -Wextra -O2
RELEASE_FLAGS_CC = -std=c99 -Wall -Wextra -O2

# Debug flags
DEBUG_FLAGS_CXX = -std=c++11 -Wall -Wextra -g
DEBUG_FLAGS_CC = -std=c99 -Wall -Wextra -g


# Default build type
CXXFLAGS = $(RELEASE_FLAGS_CXX)
CCFLAGS = $(RELEASE_FLAGS_CC)

# executable names
CPP_EXE = matrixTestCpp
CC_EXE = matrixTestC

# Source and object files
CPP_SRCS = testCaseCpp.cpp matrixCpp.cpp
CPP_OBJS = $(CPP_SRCS:.cpp=.o)

CC_SRCS = testCaseC.c matrixC.c
CC_OBJS = $(CC_SRCS:.c=.o)

# Default: Release build
all: CXXFLAGS := $(RELEASE_FLAGS_CXX)	
all: CCFLAGS := $(RELEASE_FLAGS_CC)
all: $(CPP_EXE) $(CC_EXE)

# Debug build
debug: CXXFLAGS := $(DEBUG_FLAGS_CXX)
debug: CCFLAGS := $(DEBUG_FLAGS_CC)
debug: $(CPP_EXE) $(CC_EXE)

# Link object files to create executable
$(CPP_EXE): $(CPP_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(CC_EXE): $(CC_OBJS)
	$(CC) $(CCFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(CPP_EXE) $(CPP_OBJS) $(CC_EXE) $(CC_OBJS)

.PHONY: all clean
