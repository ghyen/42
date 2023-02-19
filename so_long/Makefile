# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 12:26:15 by gkwon             #+#    #+#              #
#    Updated: 2023/02/19 18:35:20 by gkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra 
LIBFT = ./libft/libft.a
LIBFLAGS = -L ./minilibx -lmlx -framework OpenGL -framework AppKit
SRCS = so_long.c\
			valid_check.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			draw_map.c\
			key_hook.c\
			
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar -scr $@ $(OBJS)
	$(CC) ${CFLAGS} ${LIBFLAGS} ${SRCS} $(LIBFT) -o ${NAME} -I .

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C ./libft bonus

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all re fclean clean bonus