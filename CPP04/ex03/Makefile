CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = AMateria.cpp  Cure.cpp Ice.cpp main.cpp


OBJ = $(SRC:.cpp=.o)

NAME = Materia

# echo:
# 	@echo $(wildcard *.cpp)
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