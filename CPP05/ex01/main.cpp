#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
    Bureaucrat b1("Alice", 1);
    Bureaucrat b2("Bob", 150);

    Form f1("Tax Form", 50, 100);
    Form f2("Application", 150, 150);
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    // Test signing
    try {
        std::cout << "\nTesting form signing:" << std::endl;
        Bureaucrat b("Manager", 40);
        std::cout << "Before signing: " << f1 << std::endl;
        f1.signForm(b);
        std::cout << " After signing: " << f1 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test insufficient grade
    try {
        std::cout << "\n\n";
        std::cout << b1 << std::endl;
        f1.beSigned(b2);
    }
     catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}