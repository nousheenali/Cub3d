
NAME	=	cub3D

SRC_DIR = mandatory

SRCS	= main.c get_map1.c get_map2.c error.c init.c raycaster.c hit.c move.c math.c \
		../gnl/get_next_line.c ../gnl/get_next_line_utils.c load_textures.c parse_map1.c parse_map2.c \
		render_texture.c render_utils.c buffer_utils.c player.c get_map3.c  get_map4.c ft_atoi_cube.c

SRCS1 = $(addprefix $(SRC_DIR)/, $(SRCS))

BONUS_DIR = Bonus

SRCS_BN = $(addprefix $(BONUS_DIR)/, $(SRCS))
				
LIBFT 	= libft

MLX_DIR = minilibx

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

IFLAGS	= -I. -I./libft -I./minilibx

LIBS	= libft.a libmlx.a

RM		= rm -f

all:	${NAME}

${NAME}:	${SRCS1} 
			make -C ${LIBFT}
			make -C ${MLX_DIR}
			cp libft/libft.a .
			cp minilibx/libmlx.a .
			$(CC) ${CFLAGS} ${IFLAGS} ${SRCS1} -L. ${LIBS} -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus :	${SRCS_BN} 
		make -C ${LIBFT}
		make -C ${MLX_DIR}
		cp libft/libft.a .
		cp minilibx/libmlx.a .
		$(CC) ${CFLAGS} ${IFLAGS} ${SRCS_BN} -L. ${LIBS} -lmlx -framework OpenGL -framework AppKit -o $(NAME)


clean:		
			${RM} ${OBJS}
			make clean -C ${LIBFT}

fclean:		clean
			${RM} ${NAME}
			${RM} ${LIBFT}/libft.a
			${RM} libft.a
			${RM} libmlx.a

re:			fclean all

.PHONY:		all clean fclean bonus re .c.o