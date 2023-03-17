# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 21:21:25 by gkwon             #+#    #+#              #
#    Updated: 2023/03/16 21:22:59 by gkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIB = ./ft_printf/libftprintf.a

SERVER_SRCS = src/server.c
CLIENT_SRCS = src/client.c
SERVER_BONUS_SRCS = src/server_bonus.c
CLIENT_BONUS_SRCS = src/client_bonus.c
SERVER_OBJS=$(SERVER_SRCS:.c=.o)
CLIENT_OBJS=$(CLIENT_SRCS:.c=.o)
SERVER_BONUS_OBJS=$(SERVER_BONUS_SRCS:.c=.o)
CLIENT_BONUS_OBJS=$(CLIENT_BONUS_SRCS:.c=.o)

ifdef BONUS
	T_SERVER_OBJS=$(SERVER_BONUS_OBJS)
	T_CLIENT_OBJS=$(CLIENT_BONUS_OBJS)
else
	T_SERVER_OBJS=$(SERVER_OBJS)
	T_CLIENT_OBJS=$(CLIENT_OBJS)
endif

NAME=minitalk
SERVER=server
CLIENT=client

all : $(NAME)

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER): $(T_SERVER_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $(SERVER) $(T_SERVER_OBJS) $(LIB)

$(CLIENT): $(T_CLIENT_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $(CLIENT) $(T_CLIENT_OBJS) $(LIB)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB) :
	make -C ./ft_printf

bonus :
	make BONUS=1

clean :
	make -C ./ft_printf fclean
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)

fclean : clean
	rm -f $(NAME) $(SERVER) $(CLIENT) $(BONUS_NAME)

re : fclean all

.PHONY: all re fclean clean bonus