/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:25:11 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/17 19:21:01 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	get_input_type(const std::string &literal)
{
	//std::cout << "get_input_type : " << literal << std::endl;
	//size_t 	pos = literal.find('.');
	//int		len = literal.length();

	if ((literal.length() == 1 && literal[0] >= 0 && literal[0] <= 47)
		|| (literal.length() == 1 && literal[0] >= 58 && literal[0] <= 126))
		return (TYPE_CHAR);
	
	if (literal.compare("nan") == 0 || literal.compare("nanf") == 0)
		return (TYPE_NAN);
	
	if (literal.compare("+inff") == 0 || literal.compare("+inf") == 0)
		return (TYPE_P_INF);
	
	if (literal.compare("-inff") == 0 || literal.compare("-inf") == 0)
		return (TYPE_N_INF);

	//strtod() string to double
	
	return (-1);
}

//Print values and cast then if necessary
int	print_values(std::string literal, long long int_value, long double float_value, long double double_value)
{
	print_char(literal);
	print_int(int_value);
	print_float(float_value);
	print_double(double_value);
	return (EXIT_SUCCESS);
}

void	print_char(std::string literal)
{
	if (literal.length() == 1 && literal[0] >= 0 && literal[0] <= 32)
		std::cout << "char: non printable" << std::endl;
	else if (literal.length() == 1)
		std::cout << "char: " << literal[0] << std::endl;
	else
		std::cout << "char: " << literal << std::endl;
}

void	print_int(long long int_value)
{
	if (int_value > INT_MAX || int_value < INT_MIN)
		std::cout << "int: out of range" << std::endl;
	else 
	{
		int int_converted = static_cast<int>(int_value);
		std::cout << "int: " << int_converted << std::endl;
	}
}

void	print_float(long double float_value)
{
	std::cout << std::fixed << std::setprecision(1);
	if (float_value > FLOAT_MAX || float_value < -FLOAT_MAX )
    	std::cout << "float: out of range" << std::endl;
	else 
	{
		float float_converted = static_cast<float>(float_value);
		if (std::isinf(float_converted))  // Check for overflow
			std::cout << "float: out of range" << std::endl;
		else if (std::isnan(float_converted))  // Check for NaN
			std::cout << "float: nanf" << std::endl;
		else
			std::cout << "float: " << float_converted << "f" << std::endl;
	}
}

void	print_double(long double double_value)
{
	std::cout << std::fixed << std::setprecision(1);
	if (double_value > DOUBLE_MAX || double_value < -DOUBLE_MAX)
		std::cout << "double: out of range" << std::endl;
	else 
	{
		double double_converted = static_cast<double>(double_value);
		if (std::isinf(double_converted))  // Check for overflow
			std::cout << "double: out of range" << std::endl;
		else if (std::isnan(double_converted))  // Check for NaN
			std::cout << "double: nan" << std::endl;
		else
			std::cout << "double: " << double_converted << std::endl;
	}
}

//Print special cases like NaN and -inff, +inff, -inf, +inf
int	print_special(std::string type)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
    std::cout << "float: " <<  type << "f" << std::endl;
    std::cout << "double: " << type << std::endl;
	return (EXIT_SUCCESS);
}

