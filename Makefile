# Define the compiler
CXX := g++

# Define the directories
SRC_DIR := src
BIN_DIR := bin
TEMP_DIR := .temp
INCLUDE_DIR := include

# Define the output executable
TARGET := $(BIN_DIR)/mtsp

# Define the source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

# Define the object files
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.cpp=$(TEMP_DIR)/%.o)

# Define the compiler flags
CXXFLAGS := -Wall -std=c++17 -O3 -I$(INCLUDE_DIR)

# Rule to build the target
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ_FILES)

# Rule to build object files
$(TEMP_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(TEMP_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
.PHONY: clean
clean:
	rm -f $(TEMP_DIR)/*.o $(TARGET)

all:
	mkdir -p $(BIN_DIR)
	mkdir -p $(TEMP_DIR)
	make $(TARGET)