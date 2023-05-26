# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arthurabel <arthurabel@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 14:43:44 by arthurabel        #+#    #+#              #
#    Updated: 2023/05/26 14:48:26 by arthurabel       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/game/so_long.c	src/game/init.c \
							src/parsing/parsing.c \
							inc/G_N_L/get_next_line.c \
							inc/G_N_L/get_next_line_utils.c \
							src/parsing/utils.c \
							src/game/free_all.c \
							src/parsing/checker.c \
							src/game/draw.c \
							src/game/move.c \
							src/game/move_bis.c \
							src/parsing/checker_2.c \
							src/game/hitbox.c \
							src/game/collectible.c \
							src/game/collectible_bis.c \

OBJS = $(SRC:%.c=%.o)

FLAGS	= -Wall -Wextra -Werror
CC		= gcc $(FLAGS)

LIBFT_DIR = inc/libft/libft.a
MLX42_INC = -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
MLX42_DIR = MLX42/build/libmlx42.a

all: $(NAME)

$(NAME): $(OBJS)
	@cmake MLX42 -B MLX42/build
	@cmake --build MLX42/build -j4
	@make -C inc/libft/
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT_DIR) $(MLX42_DIR) $(MLX42_INC)

clean:
	@rm -f $(OBJS)
	@make -C inc/libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C inc/libft fclean

re: fclean all

.PHONY: all clean fclean re