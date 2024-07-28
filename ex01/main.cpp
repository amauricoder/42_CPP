/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:38:51 by aconceic          #+#    #+#             */
/*   Updated: 2024/07/28 20:39:02 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	user_input;

	while(1)
	{
		std::cout << "Press 1 to ADD new user or 0 to EXIT" << std::endl;
		std::cin >> user_input;
		if (user_input == "1")
		{
			std::cout << "Put User Information" << std::endl;
			phone_book.addContact();
		}
		else if (user_input == "exit" || std::cin.eof() == true || user_input == "0")
			return (std::cout << "Exiting..." << std::endl, 0);
		else
			std::cout << "Invalid selection." << std::endl;
	}
	return (0);
}
