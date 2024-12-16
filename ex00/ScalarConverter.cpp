/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:10:34 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/16 17:25:41 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/************************************************/
/*					ORTHODOX					*/
/************************************************/

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default Constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	std::cout << "ScalarConverter Copy Constructor" << std::endl;
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src)
{
	std::cout << "ScalarConverter Assignment operator" << std::endl;
	if (this != &src)
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor" << std::endl;
}

/************************************************/
/*			REQUIRED BY THE SUBJECT				*/
/************************************************/

void ScalarConverter::Convert(std::string common_form)
{
	(void)common_form;
}
