# Makefile for Foo Physics Project

# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
LDFLAGS = 

# Build type settings
ifdef DEBUG
CXXFLAGS += -g -O0
else
CXXFLAGS += -O2
endif

# Directories
SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build
BIN_DIR = bin

# Source files
SRCS = $(SRC_DIR)/foo_physics.cpp
TEST_SRCS = $(TEST_DIR)/foo_physics_test.cpp

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TEST_OBJS = $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Executables
MAIN_TARGET = $(BIN_DIR)/foo_physics
TEST_TARGET = $(BIN_DIR)/foo_physics_test

# Targets
.PHONY: all clean test debug

all: $(MAIN_TARGET)

test: CXXFLAGS += -lgtest -lgtest_main -pthread
test: $(TEST_TARGET)
	./$(TEST_TARGET)

debug: clean
	$(MAKE) DEBUG=1

# Create necessary directories
$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $@

# Main program
$(MAIN_TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Test program
$(TEST_TARGET): $(TEST_OBJS) | $(BIN_DIR)
	$(CXX) $(TEST_OBJS) -o $@ $(CXXFLAGS)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Assumed directory structure:
#
# project_root/
#   ├── Makefile
#   ├── src/
#   │   ├── foo_physics.cpp
#   │   └── foo_physics.hpp
#   ├── test/
#   │   └── foo_physics_test.cpp
#   ├── build/    (created by Makefile)
#   └── bin/      (created by Makefile)
