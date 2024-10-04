TARGET_EXEC := gerar

BUILD_DIR := ./build

# Find all the C files we want to compile in the current directory
# SRCS := $(wildcard *.c)
SRCS := gerar.c

# Prepends BUILD_DIR and appends .o to every src file
# As an example, hello.c turns into ./build/hello.c.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %).
# As an example, ./build/hello.c.o turns into ./build/hello.c.d
DEPS := $(OBJS:.o=.d)

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CPPFLAGS := -MMD -MP

# The final build step.
$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ -Wall -Werror

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
	rm pesquisa

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(DEPS)

# Build and run valgrind on the built executable
.PHONY: valgrind
valgrind: CFLAGS += -g
valgrind: $(BUILD_DIR)/$(TARGET_EXEC)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $<