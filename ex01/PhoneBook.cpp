/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:13:16 by aconceic          #+#    #+#             */
/*   Updated: 2024/07/28 20:55:09 by aconceic         ###   ########.fr       */
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

void	PhoneBook::addContact() {
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

void    PhoneBook::searchContactInfo()
{
	//Print for debugging purposes
	//std::cout << "searchContactInfo" << std::endl;
}

void    PhoneBook::contactList()
{
	//Print for debugging purposes
	//std::cout << "contactList" << std::endl;
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
