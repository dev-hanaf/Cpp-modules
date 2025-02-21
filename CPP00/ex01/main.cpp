#include "PhoneBook.hpp"


int main()
{
	PhoneBook client;
	client.index = 0;
	
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

		if (command == "ADD")
			client.add();
		else if (command == "SEARCH")
			client.search();
		else if (command == "EXIT")
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