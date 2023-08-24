HEADER = ./

FILES_C = ft_printf.c \
		  ft_put.c \
		  ft_hexa.c \
		  ft_verifs.c \
		  ft_flags.c \
		  ft_flags2.c \
		  ft_flags3.c \
		  ft_flags4.c \
		  ft_flags5.c \
		  ft_flags6.c \
		  ft_flags_fonct.c \

LIBFT_PATH = libft/

LIBFT = libft/libft.a

FILES_O = ${FILES_C:.c=.o}

FILES_H = ${HEADER}ft_printf.h

FLAGS = -Wall -Wextra -Werror -g

NAME = libftprintf.a

all: ${NAME}

${LIBFT}:
	make -C ${LIBFT_PATH} all bonus

.c.o:
	gcc ${FLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

bonus: all

${NAME}: ${LIBFT} ${FILES_O}
	cp ${LIBFT} .
	mv libft.a ${NAME}
	ar -rc ${NAME} ${FILES_O}

clean:
	rm -f ${FILES_O}
	make -C ${LIBFT_PATH} fclean

fclean: clean
	rm -f ${NAME}

re: fclean all

