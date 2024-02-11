CC = clang
CFLAGS = -Wall -Wextra -Werror -ggdb  -c 
LFLAGS = -L./dist -lft 
GFLAGS = -fsanitize=address
NAME = minirt
AR = ar -crs
NAME_LIB = minitrt.a


#----------------- directories
OBJ_DIR = dist
OBJ_DIRS = $(OBJ_DIR) \
			$(OBJ_DIR)/ray \
			$(OBJ_DIR)/memory \
			$(OBJ_DIR)/vector

# -------------- end directories			

# --------------------- source code
TARGETS = 	main.c \
			vector/vector.c \
			memory/memory.c \
			ray/ray.c
			
SRC = $(addprefix ./src/,$(TARGETS))
SRC_OBJ = $(addprefix ./$(OBJ_DIR)/,$(TARGETS:.c=.o)) 
# --------------------- end source code

# ---------------- tests
TEST_TARGETS =  tests/main.c

TESTS_OBJS = $(addprefix ./$(OBJ_DIR)/,$(TEST_TARGETS:.c=.o))
# -------------------- end tests
 
LIBFT = $(OBJ_DIR)/libft.a

VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=supp.supp -s

all: $(NAME) 

valgrind: $(NAME)	
	valgrind $(VALGRIND_FLAGS) ./$(NAME) 

$(NAME): $(OBJ_DIR) $(LIBFT) $(SRC_OBJ)
	cp libs/libft/libft.a $(LIBFT)
	$(CC) $(SRC_OBJ) $(LFLAGS) $(GFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) $< -o $@

$(LIBFT): $(OBJ_DIR)
	make -C libs/libft

$(OBJ_DIRS):
	mkdir -p $(OBJ_DIRS)

dclean: fclean
	make -C libs/libft fclean

dtest:
	make -C libs/libft test

clean: 
	rm -f $(SRC_OBJ)
	rm -f $(TESTS_OBJS)

fclean: clean 
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(NAME_LIB)

re: fclean $(NAME)

.PHONY: dclean clean fclean all re
