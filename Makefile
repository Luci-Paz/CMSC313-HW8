# Makefile for Matrix Programs	

# Compiler
CC = gcc
CXX = g++


# Release flags
# for 32-bit compilation ==============================================================
RELEASE_FLAGS_m32_CXX = -std=c++11 -m32 -Wall -Wextra -O2
RELEASE_FLAGS_m32_CC = -std=c99 -m32 -Wall -Wextra -O2

# for 64-bit compilation
RELEASE_FLAGS_m64_CXX = -std=c++11 -m64 -Wall -Wextra -O2
RELEASE_FLAGS_m64_CC = -std=c99 -m64 -Wall -Wextra -O2


# Debug flags =========================================================================
# for 32-bit compilation
DEBUG_FLAGS_m32_CXX = -std=c++11 -m32 -Wall -Wextra -g -O0
DEBUG_FLAGS_m32_CC = -std=c99 -m32 -Wall -Wextra -g -O0

# for 64-bit compilation
DEBUG_FLAGS_m64_CXX = -std=c++11 -m64 -Wall -Wextra -g -O0
DEBUG_FLAGS_m64_CC = -std=c99 -m64 -Wall -Wextra -g -O0


# Default build type ==================================================================
CXXFLAGS = $(RELEASE_FLAGS_m64_CXX)
CCFLAGS = $(RELEASE_FLAGS_m64_CC)


# executable names ====================================================================
CPP64_EXE = matrixTestCpp64
CC64_EXE = matrixTestC64

CPP32_EXE = matrixTestCpp32
CC32_EXE = matrixTestC32



# Source and object files =============================================================
CPP_SRCS = testCaseCpp.cpp matrixCpp.cpp
CPP_OBJS = $(CPP_SRCS:.cpp=.o)

CC_SRCS = testCaseC.c matrixC.c
CC_OBJS = $(CC_SRCS:.c=.o)


# Release Builds ======================================================================
# Default release build (uses 64-bit flags by default) ================================
all: CXXFLAGS := $(RELEASE_FLAGS_m64_CXX)	
all: CCFLAGS := $(RELEASE_FLAGS_m64_CC)
all: $(CPP64_EXE) $(CC64_EXE)

# Release build for -m32
Release32bit: CXXFLAGS := $(RELEASE_FLAGS_m32_CXX)
Release32bit: CCFLAGS := $(RELEASE_FLAGS_m32_CC)
Release32bit: $(CPP32_EXE) $(CC32_EXE)


# Debug Builds ========================================================================
# Default debug build (uses 64-bit flags by default) =================================
debug: CXXFLAGS := $(DEBUG_FLAGS_m64_CXX)
debug: CCFLAGS := $(DEBUG_FLAGS_m64_CC)
debug: $(CPP64_EXE) $(CC64_EXE)

# Debug build for -m32
debug32bit: CXXFLAGS := $(DEBUG_FLAGS_m32_CXX)
debug32bit: CCFLAGS := $(DEBUG_FLAGS_m32_CC)
debug32bit: $(CPP32_EXE) $(CC32_EXE)


# Link object files to create executable
$(CPP64_EXE): $(CPP_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(CC64_EXE): $(CC_OBJS)
	$(CC) $(CCFLAGS) -o $@ $^

$(CPP32_EXE): $(CPP_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(CC32_EXE): $(CC_OBJS)
	$(CC) $(CCFLAGS) -o $@ $^


# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(CPP32_EXE) $(CPP_OBJS) $(CC32_EXE) $(CC_OBJS) $(CPP64_EXE) $(CC64_EXE)

.PHONY: all clean
