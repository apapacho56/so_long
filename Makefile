# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparedes <aparedes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 17:53:26 by aparedes          #+#    #+#              #
#    Updated: 2022/06/20 17:53:36 by aparedes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

NAMEBONUS	=	so_long_bonus

MLX			=	mlxLIB.a

SRCS			=	so_long.c	\
					display/*	\
					parsing/*	\
					GNL/*		\
					utils/*

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

$(NAME):
			@echo "\033[33m[Compilation of so_long...]"
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/$(MLX) .
			@$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(SRCS) -g -fsanitize=address -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "\033[32m[ ./so_long charged ]"

all:		$(NAME)

clean:
			@ echo "\033[31m[Removing ...]"
			@ $(MAKE) -C mlx clean

fclean:		clean
			@ rm $(MLX)
			@ rm so_long >/dev/null 2>&1

re:			fclean all

.PHONY:		$(NAME) all bonus test clean fclean re

