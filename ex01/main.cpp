#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
int main()
{
	PhoneBook nokia;
	nokia.index = 0;
	
	while (true)
	{
		std::cout << CYAN;
   		std::cout << "-----------" << std::endl;
    	std::cout << "Add" << std::endl;
    	std::cout << "Search" << std::endl;
    	std::cout << "Exit" << std::endl;
    	std::cout << "-----------" << NC << std::endl; 

        std::string command;
        std::getline(std::cin >> std::ws, command);

        if (command == "Add" || command == "add")
            nokia.add();
		else if (command == "Search" || command == "search")
			nokia.search();
        else if (command == "Exit" || command == "exit")
        {
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            return 0;
        }
	  	if (std::cin.fail())
        {
            std::cout << "EOF Detected!" << std::endl;
			return (0);
		}
	}
}

// int main() {
//     int number;
//     std::cout << "Enter a number: ";
//     std::cin >> number;

//     if (std::cin.fail()) {
//         std::cout << "cin failed: Invalid input detected!" << std::endl;
//     }

//     return 0;
// }
