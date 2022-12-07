NAME	=	cube

SRCS = main.c get_map.c error.c init.c raycaster.c hit.c move.c parse_map.c \
	math.c gnl/get_next_line.c load_textures.c \
	render_texture.c render_utils.c buffer_utils.c

				
LIBFT 	= libft

MLX_DIR = minilibx
		
OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra

IFLAGS = -I. -I./libft -I./minilibx

LIBS = libft.a libmlx.a

RM		= rm -f

all:	${NAME}

${NAME}:	
			make -C ${LIBFT}
			make -C ${MLX_DIR}
			cp libft/libft.a .
			cp minilibx/libmlx.a .
			$(CC) ${CFLAGS} ${IFLAGS} ${SRCS} -L. ${LIBS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus:		
			make -C ${LIBFT}
			make -C ${MLX_DIR}
			cp libft/libft.a .
			cp mlx/libmlx.a .
			$(CC) ${CFLAGS} ${IFLAGS}  -D BONUS=1 ${SRCS} -L. ${LIBS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)		

clean:		
			${RM} ${OBJS}
			make clean -C ${LIBFT}

fclean:		clean
			${RM} ${NAME}
			${RM} ${LIBFT}/libft.a
			${RM} libft.a
			${RM} libmlx.a

re:			fclean all

.PHONY:		all clean fclean re .c.o