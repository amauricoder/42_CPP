/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:10:34 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/18 17:10:07 by aconceic         ###   ########.fr       */
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

int ScalarConverter::convert(const std::string &literal)
{
	int input_type = get_input_type(literal);
	if (input_type == TYPE_INVALID)
	{
		std::cout << "Invalid input" << std::endl;
		return (EXIT_FAILURE);
	}
	if (input_type >= TYPE_N_INF && input_type <= TYPE_NAN)
		print_special(input_type);
	else if (input_type == TYPE_CHAR)
		print_values(literal, 1);
	else
		print_values(literal, 0);
	return (input_type);
}
