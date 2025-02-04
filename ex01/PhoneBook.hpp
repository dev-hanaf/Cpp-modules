
#ifndef PHONEBOOK
#define PHONEBOOK

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"
#include <cstdlib>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define NC "\033[0m"

class PhoneBook{
	private:
		Contact contacts[8];
		std::string get_non_empty_input(std::string);
		bool printable(std::string );
		bool checker(std::string);
		std::string buffer;
	public:
		int index;
		void add();
		void search();
};

#endif