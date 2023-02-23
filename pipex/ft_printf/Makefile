# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 21:36:30 by gkwon             #+#    #+#              #
#    Updated: 2022/12/01 18:32:22 by gkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
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