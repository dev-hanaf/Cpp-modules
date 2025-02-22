CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)

NAME = Harl

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