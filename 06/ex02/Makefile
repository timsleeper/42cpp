NAME = identify

CC = c++
FLAGS = -Werror -Wextra -Wall -std=c++98 -Wconversion

SRC = main.cpp A.cpp B.cpp C.cpp Base.cpp

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

fclean : clean
	@rm -f $(NAME)

clean :
	@rm -f $(NAME)

re : fclean all