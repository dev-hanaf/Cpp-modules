CC = c++
#  -Wshadow -Wno-shadow 
CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

SRC = ClapTrap.cpp DiamondTrap.cpp FragTrap.cpp main.cpp ScavTrap.cpp

OBJ = $(SRC:.cpp=.o)

NAME = DiamondTrap

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