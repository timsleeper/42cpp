NAME = serializer

CC = c++
FLAGS = -Werror -Wextra -Wall -std=c++98 -Wconversion

SRC = main.cpp Serializer.cpp

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

fclean : clean
	@rm -f $(NAME)

clean :
	@rm -f $(NAME)

re : fclean all