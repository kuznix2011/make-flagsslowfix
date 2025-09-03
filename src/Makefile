# Makefile for make-flagslowfix

CXX = g++
CXXFLAGS = -O2 -march=native -Wall -Wextra -std=c++17
SRC = src/main.cpp
TARGET = make-flagslowfix
BUILD_DIR = build

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $(BUILD_DIR)/$(TARGET)
	@echo "Built $(BUILD_DIR)/$(TARGET)"

install: all
	install -Dm755 $(BUILD_DIR)/$(TARGET) /usr/bin/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
	@echo "Cleaned build directory"
