SRCS = get_next_line.c get_next_line_utils.c

SRCS_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = lib.a

NAME_BONUS = libb.a

AR = ar rcs

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

${NAME_BONUS}: ${OBJS_BONUS}
	${AR} ${NAME_BONUS} ${OBJS_BONUS}

clean:
	${RM} ${OBJS} ${OBJS_BONUS} test testb

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}

run: ${NAME}
	clear
	${CC} ${CFLAGS} main.c ${NAME} -o test && ./test

runb: ${NAME_BONUS}
	clear
	${CC} ${CFLAGS} mainb.c ${NAME_BONUS} -o testb && ./testb

re: fclean all

.PHONY: all clean fclean re bonus