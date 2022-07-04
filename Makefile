# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparedes <aparedes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 17:53:26 by aparedes          #+#    #+#              #
#    Updated: 2022/07/04 12:48:58 by aparedes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS			=	so_long.c				\
					display/display.c		\
					display/draw.c			\
					display/keyboard.c		\
					display/moveplayer.c	\
					display/printtexture.c	\
					parsing/checkmap.c		\
					parsing/extras.c		\
					parsing/parsing.c		\
					parsing/stockmap.c		\
					GNL/get_next_line.c		\
					utils/freeandexit.c		\
					utils/utils.c			\

OBJ		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ./mlx/
	$(CC) -o $@ -Imlx $^ -g -fsanitize=address -Lmlx -lmlx -lm -framework OpenGL -framework AppKit

%.o:%.c
			$(CC) $(CFLAGS) -c $< -o $@
	
clean:
			@$(MAKE) -C ./mlx clean

fclean:		clean
			rm -f $(NAME)
			rm $(OBJ)

re:			fclean all

.PHONY:		all test clean fclean re
