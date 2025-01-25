#include "PhoneBook.hpp"

bool printable(std::string &input)
{
	int i = 0;
	while (input[i] && std::isprint(input[i++]));
	if (input[i])
		return false;
	return true;
}

std::string PhoneBook::get_non_empty_input(const std::string& prompt) {
	std::string input;
	while (true) {
		std::cout << GREEN << prompt << NC;
		std::getline(std::cin, input);
		if (!input.empty() && printable(input)) { 
			return input;
		}
		std::cout << RED << "Field cannot be empty. Please try again." << NC << std::endl;
	}
}

void PhoneBook::add()
{
    contacts[index % 8].first_name = get_non_empty_input("Enter your first name\t: ");
    contacts[index % 8].last_name = get_non_empty_input("Enter your last name\t: ");
    contacts[index % 8].nickname = get_non_empty_input("Enter your nickname\t: ");
    contacts[index % 8].phone_number = get_non_empty_input("Enter your phone number\t: ");
    contacts[index % 8].darkest_secret = get_non_empty_input("Enter your darkest secret\t: ");
	index++;
}