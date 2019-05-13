CXX = g++
CC = gcc


TARGET_EXEC ?= project

BUILD_DIR ?= ./build
SRC_DIRS ?= ./
TARGET_DIR ?= ./bin


SRCS := Studentas.cpp 3_uzduotis.cpp
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)


INC_DIRS := ./build ./bin
INC_FLAGS := $(addprefix -I,$(INC_DIRS))




CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -std=c++17 -O2


$(TARGET_DIR)/$(TARGET_EXEC): $(OBJS)
	$(MKDIR_P) $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
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
