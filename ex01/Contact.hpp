
#ifndef CONTACT
#define CONTACT



#include <string>

class Contact{
	private:
		std::string first_name ;
		std::string last_name ;
		std::string nickname;
		std::string phone_number ;
		std::string darkest_secret;
	public:
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nickname();
		std::string get_phone_number();
		std::string get_dark_secret();
		void set_first_name(std::string param);
		void set_last_name(std::string param);
		void set_nickname(std::string param);
		void set_phone_number(std::string param);
		void set_dark_secret(std::string param);
};

#endif