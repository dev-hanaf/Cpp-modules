#include "PhoneBook.hpp"
#include <string>

bool PhoneBook::printable(std::string input) {
  int i = 0;
  while (input[i] && std::isprint(input[i++]))
    ;
  if (input[i])
    return false;
  return true;
}

std::string PhoneBook::get_non_empty_input(std::string prompt) {
  std::string input;
  while (true) {
    std::cout << GREEN << prompt << NC;
    if (!std::getline(std::cin, input)) {
      return "";
    }
    if (!input.empty() && printable(input)) {
      return input;
    }
    std::cout << RED << "Field cannot be empty. Please try again." << NC
              << std::endl;
  }
  return "";
}

bool PhoneBook::checker(std::string value)
{
  if (value == "")
  {
    // std::cout << "EOF detectect" << std::endl;
    return (false);
  }
  buffer = value;
  return (true);

}
void PhoneBook::add() {
  if (!checker(get_non_empty_input("Enter your first name\t: ")))
    return;
  contacts[index % 8].set_first_name(buffer);
   if (!checker(get_non_empty_input("Enter your last name\t: ")))
    return;
  contacts[index % 8].set_last_name(buffer);
  if (!checker(get_non_empty_input("Enter your nickname\t: ")))
    return;
  contacts[index % 8].set_nickname(buffer);
  if (!checker(get_non_empty_input("Enter your phone number\t: ")))
    return;
  contacts[index % 8].set_phone_number(buffer);
  if (!checker(get_non_empty_input("Enter your darkest secret\t: ")))
    return;
  contacts[index % 8].set_dark_secret(buffer);
  index++;
}