/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 00:13:09 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/21 16:46:58 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Useful link
// https://en.cppreference.com/w/cpp/standard_library
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
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
		int		searchContactInfo();
		void	contactList();
		void	print_contact_secrets(int id);
};

int		isInputValid(std::string input, std::string type);
void	print_header(void);
void	print_options(std::string menu);
void    print_clist_header(void);
void	print_clist_column(void);
void	print_contact_info(Contact contact, int i);

#endif