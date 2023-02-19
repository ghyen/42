# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 15:14:40 by gkwon             #+#    #+#              #
#    Updated: 2023/02/19 19:45:58 by gkwon            ###   ########.fr        #
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
			utils/valid_check.c\
			utils/utils.c

BONUS_SRCS = checker.c\
				get_next_line/get_next_line.c\
				get_next_line/get_next_line_utils.c\
				main_bonus.c\
				sorting/cal.c\
	     		sorting/rotate.c\
		 		sorting/sort.c\
				sorting/push.c\
				sorting/rotate2.c\
				sorting/swap.c\
				utils/init.c\
				utils/valid_check.c\
				utils/utils.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)
NAME = push_swap
BONUS_NAME = checker

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar -scr $@ $(OBJS)
	$(CC) ${CFLAGS} ${SRCS} $(LIBFT) -o ${NAME}

$(BONUS_NAME) : $(LIBFT) $(BONUS_OBJS)
	ar -scr $@ $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_SRCS) $(LIBFT) -o $(BONUS_NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C ./libft bonus

bonus : $(BONUS_NAME)

clean :
	make -C ./libft fclean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY: all re fclean clean bonus