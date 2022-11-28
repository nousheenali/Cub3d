# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 12:01:29 by sfathima          #+#    #+#              #
#    Updated: 2022/11/28 08:43:35 by sfathima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ray
cc		= gcc
CFLAG	= -L minilibx -lmlx -framework OpenGL -framework Appkit
RM		= rm -f

all:
	make -C minilibx
	$(cc) $(CFLAG) main.c get_map.c error.c init.c raycaster.c hit.c move.c parse_map.c math.c gnl/get_next_line.c gnl/get_next_line_utils.c -o $(NAME)
	
clean	:
	make clean -C minilibx
	
fclean	: clean
	$(RM) $(NAME)

re		: fclean all