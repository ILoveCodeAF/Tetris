#.RECIPEPREFIX = \t
CXX := g++
CC := gcc
RM := rm -f
MKDIR := mkdir -p

INCLUDE_DIR := include
SRC_DIR := source
DEP_DIR := .deps
OBJ_DIR := .obj

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(patsubst $(SRC_DIR)/%.cpp,$(DEP_DIR)/%.d,$(SRCS))

CFLAGS := -Wall -I$(INCLUDE_DIR)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td
POSTCOMPILE = mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d


TARGET := tetris

all: option $(TARGET)
	@echo "done."

option:
	@echo "compiling..."

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(CFLAGS) $(OBJS)

# $@= target_name; $< first_dependency
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEP_DIR)/%.d | $(DEP_DIR) $(OBJ_DIR)
	$(CXX) -o $@ $(DEPFLAGS) $(CFLAGS) -c $<
	$(POSTCOMPILE)

$(OBJ_DIR):
	@mkdir -p $@

$(DEP_DIR):
	@mkdir -p $@

# check if dependencies exsit
$(DEPS):

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) $(TARGET)

include $(wildcard $(DEPS))
.PHONY: all clean distclean option
