SRCS = 	miniRT.c\
		vector.c\
		matrix.c\
		matrix_helpers.c\
		matrix_transfomations.c\
		ray_functions.c\
		sphere.c mutrix_inits.c\
		colour.c\
		light.c\
		material.c\
		world.c\
		camera.c\
		shadows.c\
		render.c\
		planes.c\
		cylinder.c


NAME = miniRT
MLX = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror
CC = gcc


all : $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) $(MLX) -o $(NAME) -O3

clean :

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re