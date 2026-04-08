NAME = cub3d

SRC = main.c utils_color.c utils_texture.c init.c parsing.c utils.c other_utils.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c

OBJECT = ${SRC:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all : ${NAME}

${NAME}: ${OBJECT}
	make -C Libft
	${CC} ${CFLAGS} ${SRC} Libft/libft.a -o ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $^ -o $@

clean :
	rm -f ${OBJECT}
	make clean -C Libft
fclean : clean
	rm -rf Libft/libft.a
	rm -f ${NAME}
re : fclean all
.PHONY : all clean fclean re