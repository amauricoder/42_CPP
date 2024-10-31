#include "Contact.hpp"

//Constructor
Contact::Contact()
{
	first_name = "";
	last_name = "";
	nick_name = "";
	phone_number = "";
	darkest_secret = "";
}

//Destructor
Contact::~Contact()
{
	
}
//Setter
/**
 * @brief Set the contact information with the input
 * useful -> https://www.geeksforgeeks.org/std-string-replace-in-cpp/
 */
void	Contact::setContactInfo(std::string input, std::string type)
{
	if (input.length() > 10)
	{
		input.resize(10);
		input.replace(9, 1, 1, '.');
	}
	if (type == "name")
		first_name = input;
	else if (type == "last")
		last_name = input;
	else if (type == "nick")
		nick_name = input;
	else if (type == "number")
		phone_number = input;
	else if (type == "secret")
		darkest_secret = input;
}

//Getters
std::string	Contact::getFirstName()
{
	return (this->first_name);
}

std::string	Contact::getLastName()
{
	return (this->last_name);
}
std::string Contact::getNickName()
{
	return (this->nick_name);
}

std::string Contact::getPhone()
{
	return (this->phone_number);
}

std::string Contact::getSecret()
{
	return (this->darkest_secret);
}


