/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:10:34 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/17 19:18:49 by aconceic         ###   ########.fr       */
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
	//Preciso verificar se eh um input valido
	int input_type = get_input_type(literal);
	switch (input_type)
	{
		case TYPE_CHAR:
			print_values(literal, 
							static_cast<int>(literal[0]), 
							static_cast<float>(literal[0]), 
							static_cast<double>(literal[0]));
			break;
		case TYPE_NAN:
			print_special("nan");
			break;
		case TYPE_P_INF:
			print_special("+inf");
			break;
		case TYPE_N_INF:
			print_special("-inf");
			break;
		default:
			break;
	}
	return (input_type);
}
