/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:13:16 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/21 16:53:02 by aconceic         ###   ########.fr       */
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
	std::string input;
	std::string fields[5] = {"First Name", "Last Name", "Nick Name",
								"Number", "Darkest Secret"};
	std::string keys[5] = {"name", "last", "nick", "number", "secret"};

	for (int i = 0; i < 5; ++i) 
	{
		std::cout << "Contact " << fields[i] << ": " << std::endl;
		std::cin >> input;
		if (std::cin.eof() == true)
			std::cout << "Canceling operation..." << std::endl, std::exit(1);
		if (!isInputValid(input, keys[i]))
		{
			i --;
			continue;
		}
		contacts[id].setContactInfo(input, keys[i]);
	}
}

int    PhoneBook::searchContactInfo()
{
	std::string user_input;

	print_options("contact list");
	std::cin >> user_input;
	if (std::cin.eof() == true)
		std::cout << "Canceling operation..." << std::endl, std::exit(1);
	if (user_input.length() > 1 || user_input.length() < 0
		|| !isInputValid(user_input, "number"))
		return (std::cout << "ERROR - DIGIT A VALID ID" << std::endl, 1);
	else if (user_input[0] >= '1' && user_input[0] <= '9')
		print_contact_secrets(std::atoi(user_input.c_str()));
	return (0);
}

void    PhoneBook::contactList()
{
	int	waiting_input = 1;

	print_clist_header();
	print_clist_column();
	for (int i = 0; i < 8; i ++)
		print_contact_info(contacts[i], i);
	std::cout << std::endl;

	while (waiting_input)
	{
		waiting_input = searchContactInfo();
	}
	
}

int		isInputValid(std::string input, std::string type)
{
	if (input.empty() == true)
		return (std::cout << "Empty fields are not allowed!" << std::endl, 0);
	if (type == "number")
	{
		for (int j = 0; input[j]; j ++)
			if(!std::isdigit(input[j]))
				return (std::cout << "Only numbers allowed!" << std::endl, 0);
	}
	else
	{
		for (int i = 0; input[i]; i ++)
			if (!std::isalpha(input[i]))
				return (std::cout << "Invalid Character!" << std::endl, 0);
	}
	return (1);
}
