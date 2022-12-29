# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 20:39:12 by gkwon             #+#    #+#              #
#    Updated: 2022/12/29 20:57:20 by gkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap.a
LIBFT = ./libft/libft.a
SRCS_MAN = ft_printf.c\
				ft_unsigned_itoa.c\
				ft_to_add.c\
				ft_to_hex.c\
				ft_format1.c\
				ft_format2.c

OBJS_MAN = $(SRCS_MAN:.c=.o)

SRCS = $(SRCS_MAN)
OBJS = $(OBJS_MAN)
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
	rm -f $(OBJS_MAN)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all re fclean clean