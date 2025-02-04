#include "PhoneBook.hpp"


void PhoneBook::search()
{
	int i = 0;
	while (i < 8 && contacts[i].get_first_name().size() > 0)
	{
		std::cout << std::setw(10) << std::left << i << "|";
		contacts[i].get_first_name().size() >= 10 ? std::cout << std::setw(10) <<  contacts[i].get_first_name().substr(0, 9) + ".|"  : std::cout<< std::setw(10)  << contacts[i].get_first_name() << "|";
		contacts[i].get_last_name().size() >= 10 ? std::cout << std::setw(10) <<  contacts[i].get_last_name().substr(0, 9) + ".|"  : std::cout<< std::setw(10)  << contacts[i].get_last_name() << "|";
		contacts[i].get_nickname().size() >= 10 ? std::cout << std::setw(10) <<  contacts[i].get_nickname().substr(0, 9) + "." << std::endl : std::cout << std::setw(10) << contacts[i].get_nickname()<< std::endl;
		i++;	
	}
	int nbr = i;
	std::string idx;
	std::cout << "Enter an index\t: ";
	std::getline(std::cin, idx);

	i = std::atoi(idx.c_str());
	if((i==0 && idx != "0") || i > nbr || nbr==0)
	{
		std::cout<<"____Bad index___"<<std::endl;
		return ;
	}
	if (i >= 0 && i <= 7)
	{
		std::cout << contacts[i].get_first_name() << std::endl;
		std::cout << contacts[i].get_last_name() << std::endl;
		std::cout << contacts[i].get_nickname() << std::endl;
		std::cout << contacts[i].get_phone_number() << std::endl;
		std::cout << contacts[i].get_dark_secret() << std::endl;
	}
}