NAME = phonebook

CC = g++
FLAGS = -Werror -Wextra -Wall -std=c++98

SRC = main.cpp \
		phonebook.cpp \
		contact.cpp

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(FLAG) $(SRC) -o $(NAME)

fclean : clean
	@rm -f $(NAME)

clean :
	@rm -f $(NAME)

re : fclean all
