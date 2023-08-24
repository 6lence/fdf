MAKEFLAGS += --silent

SRC = ./src/

FILES_C = $(SRC)fdf_draw.c \
		  ${SRC}fdf_utils.c \
		  ${SRC}fdf_draw_utils.c \
		  ${SRC}fdf_key.c \
		  ${SRC}fdf_key_utils.c \
		  ${SRC}fdf1.c \
		  ${SRC}fdf2.c \
		  ${SRC}fdf_atoi_base.c \
		  ${SRC}fdf_split_triple.c \

LIBFT_PATH = ${SRC}ft_printf/

MLX_PATH = ${SRC}minilibx-linux/

LIBFT = -L ${LIBFT_PATH} -lftprintf

MLX = -L ${MLX_PATH} -lmlx -lXext -lX11

FILES_O = ${FILES_C:.c=.o}

FILES_H = ./ft_fdf.h

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

NAME = fdf

all: ${NAME}

${LIBFT}:
	make -C ${LIBFT_PATH} all bonus
	make -C ${MLX_PATH}

${NAME}: ${LIBFT} ${FILES_O}
	${CC} ${FLAGS} ${FILES_O} ${MLX} ${LIBFT} -I ${FILES_H} -o ${NAME} -lm \
		&& echo "Make done successfully." \ || echo "Doesn't work, sadge. :c"

clean:
	rm -f ${FILES_O}
	make -C ${LIBFT_PATH} clean
	make -C ${MLX_PATH} clean

fclean: clean
	rm -f ${NAME}
	rm -rf ./execute
	make -C ${LIBFT_PATH} fclean \
	&& echo "Fclean done successfully." \ || echo "Haha your fclean suck."

re: fclean all
