NAME	=	cube

SRCS = main.c get_map1.c get_map2.c error.c init.c raycaster.c hit.c move.c \
		math.c gnl/get_next_line.c load_textures.c parse_map.c parse_map1.c \
		render_texture.c render_utils.c buffer_utils.c player.c parse_map3.c get_map3.c 

				
LIBFT 	= libft

MLX_DIR = minilibx

CC		= gcc

CFLAGS	= -Wall -Wextra

IFLAGS = -I. -I./libft -I./minilibx

LIBS = libft.a libmlx.a

RM		= rm -f

all:	${NAME}

${NAME}:	$(SRCS) 
			make -C ${LIBFT}
			make -C ${MLX_DIR}
			cp libft/libft.a .
			cp minilibx/libmlx.a .
			$(CC) ${CFLAGS} ${IFLAGS} ${SRCS} -L. ${LIBS} -lmlx -framework OpenGL -framework AppKit -o $(NAME)

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