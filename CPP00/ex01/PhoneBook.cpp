/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:13:16 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/01 13:16:58 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	id = 0;
	//Print for debugging purposes
	//std::cout << "Constructor PhoneBook" << std::endl;
}

PhoneBook::~PhoneBook()
{
	//Print for debugging purposes
	//std::cout << "Destructor PhoneBook" << std::endl;
}

/**
 * @brief Prompts the user to input and validate contact details for a new contact.
 * If the input is valid, it sets the contact info; 
 * otherwise, it repeats the prompt or exits if the input stream is closed.
 */
void	PhoneBook::addContact() 
{
	static int	id;
	std::string input;
	std::string fields[5] = {"First Name", "Last Name", "Nick Name",
								"Number", "Darkest Secret"};
	std::string keys[5] = {"name", "last", "nick", "number", "secret"};

	for (int i = 0; i < 5; ++i) 
	{
		std::cout << "Contact " << fields[i] << ": " << std::endl;
		if (std::getline(std::cin, input).eof() == true)
			std::cout << BG_RED "Canceling operation..." RESET << std::endl, std::exit(1);
		if (!isInputValid(input, keys[i]))
		{
			i --;
			continue;
		}
		contacts[id].setContactInfo(input, keys[i]);
	}
	id ++;
	if (id == 8)
		id = 0;
}

/**
 * @brief Prompts user to search for a contact by ID 
 * and displays contact details if valid.
 */
int    PhoneBook::searchContactInfo()
{
	std::string user_input;

	print_options("contact list");
	if (std::getline(std::cin, user_input).eof() == true)
		std::cout << BG_RED "Canceling operation..." RESET << std::endl, std::exit(1);
	if (user_input.length() > 1 || user_input.length() <= 0
		|| !isInputValid(user_input, "id"))
		return (std::cout << BG_RED "ERROR - DIGIT A VALID ID" RESET << std::endl, 1);
	else if (user_input[0] >= '1' && user_input[0] <= '8')
	{
		return (print_contact_secrets(std::atoi(user_input.c_str())));
	}
	return (0);
}

/**
 * @brief Displays the contact list and initiates
 * the search prompt for contact selection.
 */
void    PhoneBook::contactList()
{
	int	waiting_input = 1;

	print_header("contact list");
	print_contact_column();
	for (int i = 0; i < 8; i ++)
	{
		print_contact_info(contacts[i], i);
	}
	std::cout << std::endl;
	while (waiting_input)
	{
		waiting_input = searchContactInfo();
	}
}

/**
 * @brief Validation function for types.
 * Checks -> input is empty, for phonebook -> if is only numbers and have 9 digits
 * First and last Name -> IF there is invalid char(except for spaces ' ')
 * id -> if is only number
 * @return true for valid, false for invalid.
 */
bool		isInputValid(std::string input, std::string type)
{
	if (input.empty() == true || input == " ")
		return (std::cout << BG_RED "Empty fields are not allowed!" RESET << std::endl, false);
	if (type == "number")
	{
		for (int j = 0; input[j]; j ++)
			if(!std::isdigit(input[j]))
				return (std::cout << BG_RED "Only numbers allowed!" RESET << std::endl, false);
		if (input.length() != 9)
			return (std::cout << BG_RED "Phone needs to have 9 digits!" RESET << std::endl, false);
	}
	else if (type == "name" || type == "last")
	{
		for (int i = 0; input[i]; i ++)
		{
			if (!std::isalpha(input[i]))
			{
				if (input[i] != ' ')
					return (std::cout << BG_RED "Invalid Character!" RESET << std::endl, false);
			}
		}
		if (input.find("  ") != std::string::npos)
			return (std::cout << BG_RED "Invalid Character!" RESET << std::endl, false);
		if (input.length() < 3)
			return (std::cout << BG_RED "Name must have at least 3 char" RESET << std::endl, false);
	}
	else if (type == "nick")
	{
		if (input.find("  ") != std::string::npos)
			return (std::cout << BG_RED "Invalid Name!" RESET << std::endl, false);
		if (input.length() < 3)
			return (std::cout << BG_RED "Name must have at least 3 char" RESET << std::endl, false);
	}
	if (type == "id")
	{
		for (int j = 0; input[j]; j ++)
			if(!std::isdigit(input[j]))
				return (std::cout << BG_RED "Only numbers allowed!" RESET << std::endl, false);
	}
	return (true);
}
