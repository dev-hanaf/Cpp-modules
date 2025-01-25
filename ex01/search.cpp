#include "PhoneBook.hpp"

void PhoneBook::search()
{
	int i = 0;
	while (i < 8 && contacts[i].first_name.size() > 0)
	{
		std::cout << std::setw(10) << std::left << i << "|";
		contacts[i].first_name.size() >= 10 ? std::cout << std::setw(10) <<  contacts[i].first_name.substr(0, 9) + ".|"  : std::cout<< std::setw(10)  << contacts[i].first_name << "|";
		contacts[i].last_name.size() >= 10 ? std::cout << std::setw(10) <<  contacts[i].last_name.substr(0, 9) + ".|"  : std::cout<< std::setw(10)  << contacts[i].last_name << "|";
		contacts[i].nickname.size() >= 10 ? std::cout << std::setw(10) <<  contacts[i].nickname.substr(0, 9) + "." << std::endl : std::cout << std::setw(10) << contacts[i].nickname << std::endl;
		i++;
	}
}