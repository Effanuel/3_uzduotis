CXX = g++


TARGET_EXEC ?= project

BUILD_DIR ?= ./build
#SRC_DIRS ?= ./3_uzduotis
TARGET_DIR ?= ./bin


SRCS := main.cpp test.cpp#$(find $(SRC_DIRS) -name "*.cpp")
OBJS := ./build/test.cpp.o ./build/main.cpp.o
DEPS := $(OBJS:.o=.d)

INC_DIRS := ./build ./bin
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

#===================gtest DIRECTORY
LIB_DIRS := -L /usr/local/lib -l gtest
#===================

CPPFLAGS ?= $(INC_FLAGS) $(LIB_DIRS) -MMD -MP -std=c++14 -O2

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
