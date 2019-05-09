# CXX = g++
# CC = gcc
#
#
# TARGET_EXEC ?= project
#
# BUILD_DIR ?= ./build
# SRC_DIRS ?= ./3_uzduotis
# TARGET_DIR ?= ./bin
#
#
# SRCS := ./3_uzduotis/Studentas.cpp ./3_uzduotis/3_uzduotis.cpp#$(find $(SRC_DIRS) -name "*.cpp")
# OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)#./build/Studentas.o ./build/3_uzduotis.o
# DEPS := $(OBJS:.o=.d)
#
# # INC_DIRS := ./build ./bin
# # INC_FLAGS := $(addprefix -I,$(INC_DIRS))
#
# CPPFLAGS ?= -MMD -MP -std=c++17 -O3
#
# $(TARGET_DIR)/$(TARGET_EXEC): $(OBJS)
# 	$(MKDIR_P) $(dir $@)
# 	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
#
# $(BUILD_DIR)/%.cpp.o: %.cpp
# 	$(MKDIR_P) $(dir $@)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
#
#
# .PHONY: clean run all
#
# all: $(TARGET_DIR)/$(TARGET_EXEC)
#
#
# run: all
# 	$(TARGET_DIR)/$(TARGET_EXEC)
#
# clean:
# 	$(RM) -r $(BUILD_DIR)
# 	$(RM) -r $(TARGET_DIR)
#
#
#
# -include $(DEPS)
#
# MKDIR_P ?= mkdir -p
#
CXX = g++
CC = gcc


TARGET_EXEC ?= project

BUILD_DIR ?= ./build
#SRC_DIRS ?= ./3_uzduotis
TARGET_DIR ?= ./bin


SRCS := Studentas.cpp 3_uzduotis.cpp#$(find $(SRC_DIRS) -name "*.cpp")
OBJS := ./build/Studentas.o ./build/3_uzduotis.o
DEPS := $(OBJS:.o=.d)

INC_DIRS := ./build ./bin
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -std=c++17 -O3

$(TARGET_DIR)/$(TARGET_EXEC): $(OBJS)
	$(MKDIR_P) $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean

all: $(TARGET_DIR)/$(TARGET_EXEC)


run: all
	$(TARGET_DIR)/$(TARGET_EXEC)

clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) -r $(TARGET_DIR)



-include $(DEPS)

MKDIR_P ?= mkdir -p
