SRCS		= ft_printf.c libft/*.c

OBJS		= *.o 

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			make -C libft
			${CC} ${CFLAGS} -c ${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${NAME}

re:			fclean all

.PHONY:		all clean fclean re