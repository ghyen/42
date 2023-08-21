CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = 	Account.cpp\
		test.cpp
		
OBJS=$(SRCS:.cpp=.o)

NAME=Account

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all re fclean clean bonus