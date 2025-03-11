CC = c++
#  -Wshadow -Wno-shadow 
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

NAME = Animal

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp %.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.SECONDARY : $(OBJ)