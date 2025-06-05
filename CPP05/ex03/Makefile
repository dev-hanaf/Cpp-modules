CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = AForm.cpp Bureaucrat.cpp Intern.cpp main.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp


OBJ = $(SRC:.cpp=.o)

NAME = intern

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