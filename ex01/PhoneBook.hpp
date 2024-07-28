/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 00:13:09 by aconceic          #+#    #+#             */
/*   Updated: 2024/07/28 20:43:32 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Useful link
// https://en.cppreference.com/w/cpp/standard_library
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib> // For std::exit()
#include <string>
#include <cctype> //isdigit
#include "Contact.hpp"

class	PhoneBook
{
	private:
		int	id;
		Contact contacts[8];

	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContactInfo();
		void	contactList();
};

int		isInputValid(std::string input, std::string type);
#endif