#include "PhoneBook.hpp"


int main()
{
	PhoneBook nokia;
	nokia.index = 0;
	
	while (true)
	{
		std::cout << CYAN;
   		std::cout << "-----------" << std::endl;
    	std::cout << "ADD" << std::endl;
    	std::cout << "SEARCH" << std::endl;
    	std::cout << "EXIT" << std::endl;
    	std::cout << "-----------" << NC << std::endl; 

        std::string command;
        std::getline(std::cin >> std::ws, command);

        if (command == "ADD" || command == "add")
            nokia.add();
		else if (command == "SEARCH" || command == "search")
			nokia.search();
        else if (command == "EXIT" || command == "exit")
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