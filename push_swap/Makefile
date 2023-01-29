# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 20:39:12 by gkwon             #+#    #+#              #
#    Updated: 2023/01/29 18:07:49 by gkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./libft/libft.a
SRCS = push_swap.c\
			sorting/cal.c\
	     	sorting/rotate.c\
		 	sorting/sort.c\
			sorting/push.c\
			sorting/rotate2.c\
			sorting/swap.c\
			utils/init.c\
			utils/valid_check.c
				
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all : $(NAME)
$(NAME) : $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar -scr $@ $(OBJS)
	cc ${CFLAGS} ${SRCS} $(LIBFT) -o ${NAME}
%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@
$(LIBFT) :
	make -C ./libft bonus
clean :
	make -C ./libft fclean
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all re fclean clean