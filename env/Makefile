NAME	=	minishell
CC		=	cc
LIBFT	=	libft.a
LIBFT_DIR = libft
LFLAGS = -lreadline

SRCS = minishell_test.c

OBJS = ${SRCS:.c=.o}

CC = cc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -g

.c.o:
	${CC} ${CFLAGS} -c $< -o $@


$(NAME)	:	${OBJS}
			make -C ${LIBFT_DIR}
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) -L ${LIBFT_DIR} ${LFLAGS}

# ${NAME}: ${OBJS}
# 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : 	clean
		${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re