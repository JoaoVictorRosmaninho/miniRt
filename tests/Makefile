TESTS := vector

CYAN  := \33[1;36m
RESET := \033[0m
LOG   := printf "[$(CYAN)INFO$(RESET)] %s\n"

SRC_DIR   := ../src
OBJ_DIR   := ../dist
LIBFT_DIR := ../libs/libft
MLX_DIR   := ../libs/mlx_linux
INC_DIRS  := ../includes
SRC_DIRS  := $(shell find $(SRC) -type d)

vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

SOURCES := $(shell find $(SRC_DIR) -name '*.c' -exec basename {} \;)
SOURCES := $(filter-out main.c, $(SOURCES))
OBJS    := $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

CFLAGS  := -Wall -Werror -Wextra -O3 $(addprefix -I,$(INC_DIRS))
LDFLAGS := -L $(LIBFT_DIR) -L $(MLX_DIR)
GFLAGS  := -fsanitize=address -g
#  -lmlx -lXext -lX11 -lm
LDLIBS  := -lft -lcriterion -lm

define run
 	$(CC) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) $(GFLAGS) -o $@ && ./$@ --verbose
	rm ./$@
endef

################################################################################
##                                 TESTS                                      ##
################################################################################

all: $(TESTS) clean

.PHONY: vector

debug:
	@echo $(OBJS)

vector: $(OBJS) test_vector_creator.c
	@$(call run, "$^")

matrix: $(OBJS) test_matrix.c
	@$(call run, "$^")

(OBJ_DIR)/%.o: %.c

# Makefile rules to clean stdin/stdout/stderr test's files
clean:
	@$(RM) -r $(TESTS)
	@$(RM) -r $(UTILS:.c=.o)
	@$(LOG) "Removing objects"

fclean: clean

re: fclean all

.PHONY: all clean fclean re
