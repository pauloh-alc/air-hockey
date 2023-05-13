# Compiler
CC := g++
# Compiler flags
CFLAGS := -Wall -Wextra -std=c++11 -lglut -lGL -lGLU

# Directories
SRC_DIR := ./src
INC_DIR := ./include

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp) ./main.cpp
HDRS := $(wildcard $(INC_DIR)/*.h)

# Output executable
TARGET := ./bin/air-hockey

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -o $@ $(SRCS) -I $(INC_DIR)

# Clean target
clean:
	rm -f $(TARGET)

