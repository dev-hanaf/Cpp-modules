CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SRC = $(wildcard *.cpp)
HPP = $(wildcard *.hpp)

OBJ = $(SRC:.cpp=.o)

NAME = PmergeMe

all : $(NAME)

$(NAME) : $(OBJ) $(HPP) 
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all