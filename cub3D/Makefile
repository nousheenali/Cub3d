# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 12:01:29 by sfathima          #+#    #+#              #
#    Updated: 2022/11/07 13:06:01 by sfathima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ray
cc		= gcc
CFLAG	= -L minilibx -lmlx -framework OpenGL -framework Appkit
RM		= rm -f

all:
	make -C minilibx
	$(cc) $(CFLAG) main.c -o $(NAME)
	
clean	:
	make clean -C minilibx
	
fclean	: clean
	$(RM) $(NAME)

re		: fclean all