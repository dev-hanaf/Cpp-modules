#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

int main() 
{
    try
    {
        Bureaucrat manager("ahanaf" , 1);

        std::cout << manager << std::endl;

        ShrubberyCreationForm berry("home");
        std::cout << berry << std::endl;

        berry.signForm(manager);
        std::cout << berry << std::endl;
        
        berry.execute(manager);


        std::cout << "\n new example : \n";
        ///////////////////

        Bureaucrat wat;

        std::cout << "\n" << wat << std::endl;
        RobotomyRequestForm roboto("alien");

        std::cout << roboto << std::endl;

        roboto.signForm(manager);
        roboto.execute(manager);

        ///////////////////////

        std::cout << "\n\n\n";

        manager.executeForm(roboto);
    }
    catch (std::exception &e)
    {
        std::cout << "\n\n from catch handler -> ";
        std::cout << e.what() << std::endl;
    }
    return 0;
}