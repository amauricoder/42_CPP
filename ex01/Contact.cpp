#include "Contact.hpp"

Contact::Contact()
{
	first_name = "Default";
	last_name = "Default";
	nick_name = "Default";
	phone_number = "00000000";
	darkest_secret = "Default";
}

Contact::~Contact()
{
	
}
//	************ Setter Functions ************
void	Contact::setContactInfo(std::string input, std::string type)
{
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

//	************ Getter Functions ************
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


