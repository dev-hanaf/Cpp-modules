#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

int main() 
{
    try
    {

        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy reques    st", "Bender");
        if (rrf)
            std::cout << *rrf << std::endl;

    }
    catch (std::exception &e)
    {
        std::cout << "\n\n from catch handler -> ";
        std::cout << e.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "unhalded exception\n";
    }
    return 0;
}