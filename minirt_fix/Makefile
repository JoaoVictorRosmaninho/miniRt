NAME = minirt

CC = cc
CFLAGS = -Wall -Wextra -Werror 
CFLAGS += -Ofast
#CFLAGS += -fsanitize=address -fsanitize=leak -g3 
LDFLAGS = -lmlx -lm -lXext -lX11 -lz

SRCS = 	parser/minirt.c								\
	  	parser/check_elements.c						\
	  	parser/utils.c								\
	  	parser/utils2.c								\
	  	parser/get_next_line/get_next_line.c		\
	  	parser/get_next_line/get_next_line_utils.c	\
		parser/check_objects.c						\
		parser/atoi.c								\
		raytracing/vector.c 						\
		raytracing/vector_1.c 						\
		raytracing/vector_2.c 						\
		raytracing/camera.c 						\
		images/image.c 								\
		images/image_utils.c 						\
		transform/init_mtx.c 						\
		transform/transform_mtx.c					\
		matrix/init.c 								\
		matrix/matrix.c 							\
		matrix/inverse.c 							\
		matrix/minor.c 								\
		matrix/multiplication.c 					\
		objects/sphere.c 							\
		objects/plane.c 							\
		raytracing/rt_utils.c 						\
		raytracing/raytrace.c 						\
		material/material.c 						\
		material/diffuse.c 							\
		material/specular.c 						\
		objects/cylinder.c 							\
 		objects/cy_utils.c 							\
 		memory/arena.c 								\
 		memory/arena_utils.c 						\
 		memory/arena_align_utils.c 					\
 		memory/ft_smart_calloc.c 					\
		main.c										\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	make -C libft/ -j4
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(LDFLAGS) -o $(NAME)

clean :
	make clean -C libft/
	rm -rf $(OBJS)

fclean : clean
	make fclean -C libft/
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
