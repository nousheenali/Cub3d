# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nali <nali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 12:01:29 by sfathima          #+#    #+#              #
#    Updated: 2022/11/22 13:14:52 by nali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ray
cc		= gcc
CFLAG	= -L minilibx -lmlx -framework OpenGL -framework Appkit
RM		= rm -f

all:
	make -C minilibx
	$(cc) $(CFLAG) main.c hit.c -o $(NAME)
	
clean	:
	make clean -C minilibx
	
fclean	: clean
	$(RM) $(NAME)

re		: fclean all