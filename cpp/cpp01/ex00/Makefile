CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = 	Zombie.cpp\
		main.cpp\
		newZombie.cpp\
		randomChump.cpp
		
OBJS=$(SRCS:.cpp=.o)

NAME=BraiiiiiiinnnzzzZ

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