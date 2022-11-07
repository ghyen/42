NAME	=	libft.a
SRCS	=	*.c
OBJS	=	${SRCS:.c=.o}
CC	=	gcc
RM	=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
.c.o:
		${CC}	${CFLAGS}	-I	includes	-c	$<	-o	${<:.c=.o}
$(NAME):	${OBJS}
		ar	rc	${NAME}	${OBJS}
all:	${NAME}
clean:
		${RM} ${OBJS}
fclean:	clean
		${RM} ${NAME}
re:	fclean all
.PHONY:	all	re	clean	fclean
