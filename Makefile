
CC     	  := clang
CFLAGS 	  := -Wall -Wextra -Werror -ggdb  -c 
LFLAGS 	  := -L./dist -lft -lm
GFLAGS 	  := -fsanitize=address
NAME   	  := miniRT
AR     	  := ar -crs

RESET := \033[0m
CYAN  := \033[1;36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"


OBJ_DIR   :=  dist
LIBFT_DIR := ./libs/libft
MLX_DIR   := ./libs/mlx_linux

SOURCES   := $(shell find src -type f -name '*.c') 
OBJECTS   := $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.c=.o)))
LIBFT     := $(OBJ_DIR)/libft.a
DIRS      := $(dir $(SOURCES))

vpath %.h ./includes
vpath %.c $(DIRS)

# --------------------- valgrind
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=supp.supp -s

all: $(NAME)

debug:
	@echo $(SOURCES)
	@echo $(OBJECTS)
	@echo $(DIRS)

valgrind: $(NAME)	
	valgrind $(VALGRIND_FLAGS) ./$(NAME) 

$(NAME): $(OBJECTS) $(LIBFT)
	cp libs/libft/libft.a $(LIBFT)
	$(CC) $(OBJECTS) $(LFLAGS) $(GFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(OBJ_DIR)
	@$(LOG) "Compiling $(notdir $<)"
	$(CC) $(CFLAGS) $< -o $@

$(LIBFT): $(OBJ_DIR)
	make -C libs/libft

$(OBJ_DIR):
	@$(LOG) "Creating objects directory"
	@mkdir -p $@

dclean: fclean
	make -C libs/libft fclean

dtest:
	make -C libs/libft test

clean: 
	rm -f $(OBJECTS)
	rm -f $(TESTS_OBJECTS)

fclean: clean 
	rm -f $(NAME)
	rm -f $(LIBFT)

re: dclean $(NAME)

.PHONY: dclean clean fclean all re
