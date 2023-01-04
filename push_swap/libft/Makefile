# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 21:36:30 by gkwon             #+#    #+#              #
#    Updated: 2022/11/20 21:36:31 by gkwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRCS_MAN	=	ft_isalpha.c\
				ft_isdigit.c\
				ft_isalnum.c\
				ft_isascii.c\
				ft_isprint.c\
				ft_strlen.c\
				ft_memset.c\
				ft_bzero.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_strlcpy.c\
				ft_strlcat.c\
				ft_toupper.c\
				ft_tolower.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_strncmp.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_strnstr.c\
				ft_strdup.c\
				ft_atoi.c\
				ft_calloc.c\
				ft_substr.c\
				ft_strjoin.c\
				ft_strtrim.c\
				ft_split.c\
				ft_itoa.c\
				ft_strmapi.c\
				ft_striteri.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c

SRCS_BONUS = 	ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c

OBJS_MAN	=	$(SRCS_MAN:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
CC	=	cc
RM	=	rm -f
CFLAGS	=	-Wall -Wextra -Werror  -std=c99

$(NAME): all

all bonus:
	rm -f all bonus $(NAME)
	ar rc $(NAME) $^
	touch $@

all: $(OBJS_MAN)

%.o:%.c
	$(CC)	$(CFLAGS) -c $<

bonus: $(OBJS_MAN) $(OBJS_BONUS)

clean:
	rm -f $(OBJS_MAN) $(OBJS_BONUS) all bonus

fclean: clean
	rm -f $(NAME)

re : 
	make fclean 
	make all

.PHONY : clean fclean re 