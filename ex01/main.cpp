/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:38:51 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/31 17:41:45 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	user_input;

	while(1)
	{
		print_header("main");
		print_options("main");
		std::getline(std::cin, user_input);
		if (user_input == "1" || user_input == "ADD")
		{
			std::cout << "Put User Information" << std::endl;
			phone_book.addContact();
		}
		else if (user_input == "2" || user_input == "SEARCH")
		{
			phone_book.contactList();
		}
		else if (user_input == "EXIT" || std::cin.eof() == true || user_input == "0")
			return (std::cout << BG_RED "Exiting..." RESET << std::endl, 0);
		else
			std::cout << BG_RED "Invalid selection." RESET << std::endl;
	}
	return (0);
}
