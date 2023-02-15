# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 12:26:15 by gkwon             #+#    #+#              #
#    Updated: 2023/02/15 23:41:49 by gkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra 
FFFFFF = -L ./minilibx -lmlx -framework OpenGL -framework AppKit
SRCS = so_long.c\
			map/valid_check.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c
			
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) ${CFLAGS} ${FFFFFF} ${SRCS} -o ${NAME} -I . -g

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all re fclean clean bonus