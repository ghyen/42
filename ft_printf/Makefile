# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 21:36:30 by gkwon             #+#    #+#              #
#    Updated: 2022/11/26 16:41:24 by gkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_printf.a
SRCS_MAN	=	ft_printf.c\
				ft_strlen.c\
				ft_print_memory.c\
				ft_itoa.c\
				ft_ft_strdup.c

OBJS_MAN	=	$(SRCS_MAN:.c=.o)
CC	=	cc
RM	=	rm -f
CFLAGS	=	-Wall -Wextra -Werror  -std=c99

$(NAME): all

all:
	rm -f all $(NAME)
	ar rc $(NAME) $^

all: $(OBJS_MAN)

%.o:%.c
	$(CC)	$(CFLAGS) -c $<

clean:
	rm -f $(OBJS_MAN) $(OBJS_BONUS) all bonus

fclean: clean
	rm -f $(NAME)

re : 
	make fclean 
	make all

.PHONY : clean fclean re 