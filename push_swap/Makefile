# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edwin <edwin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 20:39:12 by gkwon             #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2023/01/13 13:45:38 by edwin            ###   ########.fr        #
=======
#    Updated: 2023/01/16 21:12:09 by gkwon            ###   ########.fr        #
>>>>>>> 0670d6ae7014e3f09f7047077eaf606bfabd6bec
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
NAME = push_swap.a

all : $(NAME)
$(NAME) : $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar -scr $@ $(OBJS)
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