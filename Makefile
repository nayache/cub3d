NAME = Cub3D

OS = $(shell uname)

CC = clang

CFLAGS = -Wall -Wextra -Werror

ifeq ($(OS),Darwin)
MLX = -lm -framework OpenGL -framework AppKit
else
MLX = -lm -lX11 -lXext
endif

SRCS =	camera.c init.c main.c raysprite.c utils.c verif.c draw.c init_plane.c \
		move.c raytext.c utils_lexing.c verif_map2.c exit_game.c lexing2.c \
		parsing.c save_sprite.c utils_parsing.c verif_map.c get_next_line.c \
		lexing.c raycasting.c utils2.c utils_sprite.c event_key.c screenshot.c \
		utils3.c utils4.c utils_lexing2.c

LIBS =	libft/libft.a minilibx-linux/libmlx_Linux.a

SRC = $(addprefix ./srcs/, $(SRCS))

OBJS = $(SRC:.c=.o)

$(NAME):	$(OBJS) $(LIBS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBS)
.c.o: 
		$(CC) $(CFLAGS) -I ./includes/ -c $< -o $@
$(LIBS):
		make -C libft/
		make -C minilibx-linux/

all :	$(NAME)

clean : 
	rm -rf $(OBJS)
	make clean -C libft/
	make clean -C minilibx-linux/

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft/
	rm -rf minilibx-linux/libmlx.a minilibx-linux/libmlx-Linux.a

re : fclean all
