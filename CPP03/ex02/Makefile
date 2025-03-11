CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ClapTrap.cpp FragTrap.cpp main.cpp ScavTrap.cpp

OBJ = $(SRC:.cpp=.o)

NAME = FragTrap

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.SECONDARY : $(OBJ)
