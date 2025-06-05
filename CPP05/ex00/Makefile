CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Bureaucrat.cpp main.cpp


OBJ = $(SRC:.cpp=.o)

NAME = bureaucrat

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf ${NAME}

re : fclean all