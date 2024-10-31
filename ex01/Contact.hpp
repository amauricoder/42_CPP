/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:38:22 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/30 17:43:15 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string	phone_number;
		std::string darkest_secret;

	public:
		Contact();
		~Contact();
		//setters
		void		setContactInfo(std::string input, std::string type);
		//getters
		std::string	getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhone();
		std::string getSecret();
};

#endif