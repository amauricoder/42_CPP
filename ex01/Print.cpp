#include "PhoneBook.hpp"

/**
 * @brief Print personalized header;
 * Colors defined on Print.hpp
 */
void	print_header(std::string menu)
{
	if (menu == "main")
	{
		std::cout <<
		YELLOW " ____  _                      ____              _    \n"
		"|  _ \\| |__   ___  _ __   ___| __ )  ___   ___ | | __\n"
		"| |_) | '_ \\ / _ \\| '_ \\ / _ \\  _ \\ / _ \\ / _ \\| |/ /\n"
		"|  __/| | | | (_) | | | |  __/ |_) | (_) | (_) |   < \n"
		"|_|   |_| |_|\\___/|_| |_|\\___|____/ \\___/ \\___/|_|\\_\\ \n" RESET
		<< std::endl;
	}
	else if (menu == "contact list")
	{
		std::cout <<
		GREEN "  ____            _             _     _     _     _  \n"
		" / ___|___  _ __ | |_ __ _  ___| |_  | |   (_)___| |_\n"
		"| |   / _ \\| '_ \\| __/ _` |/ __| __| | |   | / __| __|\n"
		"| |__| (_) | | | | || (_| | (__| |_  | |___| \\__ \\ |_ \n"
		" \\____\\___/|_| |_|\\__\\__,_|\\___|\\__| |_____|_|___/\\__|\n" RESET	
		<< std::endl;
	}
}

/**
 * @brief Print interactions;
 * @param menu string to select the kind of interaction
 * if "menu" -> print options to menu.
 * if "contact list" -> print options to contact list.
 */
void	print_options(std::string menu)
{
	std::cout << BG_GREEN "CHOOSE AN OPTION" RESET << std::endl;
	if (menu == "main")
	{
		std::cout << GREEN "[1] ADD NEW USER" RESET << std::endl;
		std::cout << BLUE "[2] SEARCH USER" RESET << std::endl;
		std::cout << MAGENTA "[0] EXIT\n" RESET << std::endl;
	}
	else if (menu == "contact list")
	{
		std::cout << GREEN "[CONTACT ID] FOR SENSITIVE INFORMATION" RESET << std::endl;
		std::cout << MAGENTA "[0] BACK TO MENU" RESET << std::endl;
	}
}

/**
 * @brief Print contact colunn heads.
 * User setw() method from std::string class to set the qt of characters.
 */
void	print_contact_column(void)
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

/**
 * @brief Print contact information.
 * User setw() method from std::string class to set the qt of characters.
 */
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

/**
 * @brief Prints "secrets of contacts"
 * Check if the contact is empty for first try, when its empty.
 * @return 1 for empty, 0 for Success.
 */
int	PhoneBook::print_contact_secrets(int id)
{
	if (contacts[id - 1].getPhone().empty() == true
		&& contacts[id - 1].getSecret().empty() == true)
	{
		std::cout 
		<< BG_RED "THERE IS NO SENSITIVE INFO FOR THIS CONTACT" RESET
		<< "\n"
		<< std::endl;
		return (1);
	}
	std::cout
		<< "|"
		<< std::setw(10)
        << "Phone"
		<< "|"
		<< std::setw(10)
        << "Secret"
		<< "|"
	<< std::endl;
	std::cout
        << std::setw(10)
        << contacts[id - 1].getPhone()
        << "|"
        << std::setw(10)
        << contacts[id - 1].getSecret()
        << "|"
    << std::endl;
	return (0);
}
