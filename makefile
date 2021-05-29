.PHONY : all clean

ROOT_DIR := src
OUTPUT_DIR := build
OUTPUT := asteroids

CXX := g++
LIBS := -lsfml-graphics -lsfml-window -lsfml-system

$(shell mkdir -p $(OUTPUT_DIR))
CPP_FILES:=$(shell find $(ROOT_DIR) -name "*.cpp")
all: $(OUTPUT_DIR)/$(OUTPUT)

$(OUTPUT_DIR)/$(OUTPUT): $(CPP_FILES)
	$(CXX) -o $(OUTPUT_DIR)/$(OUTPUT) $(CPP_FILES) $(LIBS)

clean:
	$(RM) -r $(OUTPUT_DIR)