
#ifndef PHONEBOOK
#define PHONEBOOK

#include <iostream>
#include <string>
#include <iomanip>

#include "Contact.hpp"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define NC "\033[0m"

class PhoneBook{
		Contact contacts[8];
	private:
		std::string get_non_empty_input(const std::string &);
	public:
		int index;
		void add();
		void search();
};

#endif