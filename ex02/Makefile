CC = g++

CFLAGS = -Wall -Wextra -Werror  -std=c++98

SRC = tests.cpp Account.cpp
OBJ = $(SRC:.cpp=.o)
NAME = account

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(NAME)

re : fclean all
