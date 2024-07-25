# Name of the unit test executable
TEST_NAME = unit_tests

# Directories
MINIRT_DIR = ../minirt
OBJ_DIR = obj

# Source directory:
SRCS_DIR = srcs

# Source Subdirectories:
FUNCTION_TESTS_DIR = function_tests

# Source Filenames
MAIN = unit_tests_main
FUNCTION_TESTS = test_tuple_arithmetic test_matrices test_ray_transformations test_inverse_matrix

# Mac Compiler tools
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(MINIRT_DIR)/mlx_linux -I$(MINIRT_DIR)/includes -g 
LDFLAGS = -L$(MINIRT_DIR)/mlx_linux -lmlx -framework OpenGL -framework AppKit

# Linux Compiler tools
#CC = gcc
#CFLAGS = -Wall -Wextra -Werror -I$(MINIRT_DIR)/mlx_linux -I$(MINIRT_DIR)/includes -g 
#LDFLAGS = -L$(MINIRT_DIR)/mlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm

# Source files for unit tests
UNIT_TESTS_SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(MAIN))) \
                	$(addprefix $(SRCS_DIR)/$(FUNCTION_TESTS_DIR)/, $(addsuffix .c, $(FUNCTION_TESTS)))

# Object files for unit tests
UNIT_TESTS_OBJS = $(UNIT_TESTS_SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

# Ensure the object directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/function_tests:
	mkdir -p $(OBJ_DIR)/function_tests

# Exclude main.o from the MINIRT object files
MINIRT_OBJS = $(filter-out $(MINIRT_DIR)/obj/main.o, $(shell find $(MINIRT_DIR)/obj -name '*.o'))

# Rule to build the unit tests executable
$(TEST_NAME): $(UNIT_TESTS_OBJS)
	$(CC) $(UNIT_TESTS_OBJS) $(MINIRT_OBJS) $(LDFLAGS) -o $(TEST_NAME)

# Compilation rule for unit test source files
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR) $(OBJ_DIR)/function_tests
	@echo "Compiling $< to $@"
	$(CC) $(CFLAGS) -o $@ -c $<

# Rule to build and run unit tests
test: $(TEST_NAME)
	./$(TEST_NAME)

# Clean rule to remove object files and the test executable
clean:
	rm -rf $(OBJ_DIR) $(TEST_NAME)

.PHONY: clean test
