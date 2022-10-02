#*********** VARIABLES ************

#VARIABLE=VALUE
CC = clang
CFLAGS = -Wall -Werror -Wextra -Wconversion #-fsanitize=address -fsanitize=undefined
MLX_USED = mlx_linux
MLX_FLAGS	=	-L./${MLX_USED} -lmlx -lX11 -lbsd -lXext -lm   
INCS = -I ./include -I ./libft -I ./${MLX_USED}

LIBFTDIRNAME = libft
LIBFTNAME = libft.a

SRC_DIR = src
NAME = cub3d

#*********** SRC OBJ FILES ************

SRCS = $(SRC_DIR)/main.c\

OBJS=$(SRCS:.c=.o)

#*********** RULES ************
%.o : %.c
	$(CC) ${CFLAGS} ${INCS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	${MAKE} -C libft
	${MAKE} -C ${MLX_USED}
	${CC} -g ${CFLAGS} ${MLX_FLAGS} -o ${NAME} ${OBJS} libft/libft.a ${INCS}

clean:
	${MAKE} -C ${LIBFTDIRNAME} clean
	${MAKE} -C ${MLX_USED} clean
	rm -f ${OBJS}

fclean: clean
	${MAKE} -C ${LIBFTDIRNAME} fclean
	rm -f $(NAME)

re: fclean all

#in case files exist with same name as targets
.PHONY: all clean fclean re bonus
