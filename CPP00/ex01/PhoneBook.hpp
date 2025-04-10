/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 00:13:09 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/31 16:00:07 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Useful link
// https://en.cppreference.com/w/cpp/standard_library
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib> //For std::exit()
#include <string>
#include <cctype> //isdigit
#include "Contact.hpp"
#include "Print.hpp"

class	PhoneBook
{
	private:
		int	id;
		Contact contacts[8];

	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		int		searchContactInfo();
		void	contactList();
		int		print_contact_secrets(int id);
};

bool	isInputValid(std::string input, std::string type);

#endif