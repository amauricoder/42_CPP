#include "PhoneBook.hpp"

/**
 * @brief Print header;
 */
void	print_header(void)
{
	std::cout <<
	
	" ____  _                      ____              _    \n"
	"|  _ \\| |__   ___  _ __   ___| __ )  ___   ___ | | __\n"
	"| |_) | '_ \\ / _ \\| '_ \\ / _ \\  _ \\ / _ \\ / _ \\| |/ /\n"
	"|  __/| | | | (_) | | | |  __/ |_) | (_) | (_) |   < \n"
	"|_|   |_| |_|\\___/|_| |_|\\___|____/ \\___/ \\___/|_|\\_\\ \n"

	<< std::endl;
}

/**
 * @brief Print interactions;
 */
void	print_options(std::string menu)
{
	std::cout << "DIGIT A NUMBER" << std::endl;
	if (menu == "main")
	{
		std::cout << "[1] ADD NEW USER" << std::endl;
		std::cout << "[2] SEARCH USER" << std::endl;
		std::cout << "[0] EXIT\n" << std::endl;
	}
	else if (menu == "contact list")
	{
		std::cout << "[CONTACT ID] FOR SECRETS" << std::endl;
		std::cout << "[0] BACK TO MENU" << std::endl;
	}
}

void    print_clist_header(void)
{
	std::cout <<

	"  ____            _             _     _     _     _  \n"
	" / ___|___  _ __ | |_ __ _  ___| |_  | |   (_)___| |_\n"
	"| |   / _ \\| '_ \\| __/ _` |/ __| __| | |   | / __| __|\n"
	"| |__| (_) | | | | || (_| | (__| |_  | |___| \\__ \\ |_ \n"
	" \\____\\___/|_| |_|\\__\\__,_|\\___|\\__| |_____|_|___/\\__|\n"
	
	<< std::endl;
}

void	print_clist_column(void)
{
	std::cout
		<< "|"
		<< std::setw(10)
        << "Id"
		<< "|"
		<< std::setw(10)
        << "First Name"
		<< "|"
		<< std::setw(10)
        << "Last Name"
		<< "|"
		<< std::setw(10)
        << "Nick Name"
		<< "|"
    << std::endl;
}

void	print_contact_info(Contact contact, int i)
{
	std::cout
		<< "|"
        << std::setw(10)
		<< i + 1
		<< "|"
        << std::setw(10)
        << contact.getFirstName()
        << "|"
        << std::setw(10)
        << contact.getLastName()
        << "|"
        << std::setw(10)
        << contact.getNickName()
        << "|"
    << std::endl;
}

void	PhoneBook::print_contact_secrets(int id)
{
	(void)id;
	std::cout << "PRINTANDO" << std::endl;
};