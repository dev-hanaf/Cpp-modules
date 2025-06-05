#include "Bureaucrat.hpp"

int main() 
{
    Bureaucrat b1("Alice", 1);
    Bureaucrat b2("Bob", 150);
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    try {
        std::cout << "\nTesting increment/decrement:" << std::endl;
        Bureaucrat b3("Charlie", 2);
        std::cout << "Before increment: " << b3 << std::endl;
        b3.increment();
        std::cout << "After increment: " << b3 << std::endl;
        
        Bureaucrat b4("Dave", 149);
        std::cout << "Before decrement: " << b4 << std::endl;
        b4.decrement();
        std::cout << "After decrement: " << b4 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test edge cases
    try {
        std::cout << "\nTesting edge cases:" << std::endl;
        Bureaucrat b5("Eve", 1);
        b5.increment();  // Should throw
    } catch (std::exception& e) {
        std::cout << "Expected error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b6("Frank", 150);
        b6.decrement();  // Should throw
    } catch (std::exception& e) {
        std::cout << "Expected error: " << e.what() << std::endl;
    }
    return 0;
}