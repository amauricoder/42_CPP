/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:38:51 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/21 16:53:22 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


int	main(void)
{
	PhoneBook	phone_book;
	std::string	user_input;

	while(1)
	{
		print_header();
		print_options("main");
		std::cin >> user_input;
		if (user_input == "1")
		{
			std::cout << "Put User Information" << std::endl;
			phone_book.addContact();
		}
		else if (user_input == "2")
		{
			phone_book.contactList();
		}
		else if (user_input == "exit" || std::cin.eof() == true || user_input == "0")
			return (std::cout << "Exiting..." << std::endl, 0);
		else
			std::cout << "Invalid selection." << std::endl;
	}
	return (0);
}
