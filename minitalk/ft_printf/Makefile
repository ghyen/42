# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 17:15:37 by gkwon             #+#    #+#              #
#    Updated: 2023/03/14 17:17:01 by gkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
LIB = ./libft/libft.a
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
$(NAME) : $(LIB) $(OBJS)
	cp $(LIB) $(NAME)
	ar -scr $@ $(OBJS)
%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@
$(LIB) :
	make -C ./libft bonus
clean :
	make -C ./libft fclean
	rm -f $(OBJS_MAN)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all re fclean clean