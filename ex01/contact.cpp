#include "Contact.hpp"

std::string Contact::get_first_name()
{
    return first_name;
}
std::string Contact::get_last_name()
{
    return last_name;
}
std::string  Contact::get_nickname()
{
    return nickname;
}
std::string Contact::get_phone_number()
{
    return phone_number;
}
std::string Contact::get_dark_secret()
{
    return darkest_secret;
}
void Contact::set_first_name(std::string param)
{
    first_name = param;
}
void Contact::set_last_name(std::string param)
{
    last_name = param;
}
void Contact::set_nickname(std::string param)
{
    nickname = param;
}
void Contact::set_phone_number(std::string param)
{
    phone_number = param;
}
void Contact::set_dark_secret(std::string param)
{
    darkest_secret = param;
}