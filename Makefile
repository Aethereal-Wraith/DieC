TARGET_EXEC := diec
TARGET_LIB := libdiec.so

# NOTE: This Makefile uses implicit gnumake rules and flags for c/cpp compilation
# Program for compiling C programs; default cc
CC := clang
# NOTE: CPP =/= C++ here
# Extra flags to give to the C preprocessor
CPPFLAGS := -MMD -MP
# Extra flags to give to the C compiler
CFLAGS := -std=c99 -Wall -Werror -include-pch
TESTFLAGS := -g -Og

BUILD_DIR := build
SRC_DIR := src
TEST_DIR := tests

SRCS := $(wildcard $(SRC_DIR)/*)
TESTS := $(wildcard $(TEST_DIR)/*)

SRC_OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
TEST_OBJS := $(TESTS:$(TEST_DIR)/%.c=$(BUILD_DIR)/%.o)

DEPS := $(SRC_OBJS:.o=.d) $(TEST_OBJS:.o=.d)

all: test $(TARGET_EXEC) $(TARGET_LIB)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET_EXEC): $(SRC_OBJS)
	$(CC) -o $@ $^

$(TARGET_LIB): $(SRC_OBJS)
		$(CC) -shared -fPIC -o $@ $^

test: $(TEST_OBJS)
		$(CC) $(TESTFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(TESTFLAGS) -o $@ -c $<

clean:
	rm -rf $(BUILD_DIR) $(TARGET_EXEC) $(TARGET_LIB) test

-include $(DEPS)

.PHONY: all clean test
