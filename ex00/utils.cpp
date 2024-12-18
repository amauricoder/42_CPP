/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:25:11 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/18 19:53:05 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	check_validity(const std::string literal)
{
	int	i = 0;
	int	dot = 0;
	int	double_e = 0;
	int	double_f = 0;

	while (literal[i])
	{
		if ((std::isspace(literal[i])) 
			|| (std::isalpha(literal[i]) 
				&& literal[i] != 'e' && literal[i] != 'f'))
			return (EXIT_FAILURE);
		if (literal[i] == '.')
			dot ++;
		if (literal[i] == 'e')
			double_e ++;
		if (literal[i] == 'f')
			double_f ++;
		i ++;
	}
	if (dot > 1 || double_e > 1 || double_f > 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_input_type(const std::string &literal)
{
	int		len = literal.length();
	size_t	pos = literal.find('.');
	if (literal.compare("nan") == 0 || literal.compare("nanf") == 0)
		return (TYPE_NAN);
	
	if (literal.compare("+inff") == 0 || literal.compare("+inf") == 0)
		return (TYPE_P_INF);
	
	if (literal.compare("-inff") == 0 || literal.compare("-inf") == 0)
		return (TYPE_N_INF);
	
	if ((len == 1 && literal[0] >= 0 && literal[0] <= 47)
		|| (len == 1 && literal[0] >= 58 && literal[0] <= 126))
		return (TYPE_CHAR);
	
	if (check_validity(literal) || literal.empty())
		return (TYPE_INVALID);

	if (pos != std::string::npos)
	{
		if (len > 1 && literal[len - 1] == 'f')
			return (TYPE_FLOAT);
		else
			return (TYPE_DOUBLE);
	}
	return (TYPE_INT);
}

//Print values and cast then if necessary
int	print_values(std::string literal, bool is_char)
{
	int		len = literal.length();
	std::string literal_copy = literal;
	if (literal[len - 1] == 'f')
		literal_copy.erase(len - 1);
	print_char(literal);
	print_int(literal_copy, is_char);
	print_float(literal_copy, is_char);
	print_double(literal_copy, is_char);
	return (EXIT_SUCCESS);
}

void	print_char(std::string literal)
{
	if (literal.length() > 1)
	{
		char *end;
   		int ascii_value = std::strtold(literal.c_str(), &end);
    	if (*end != '\0')
		{
    		std::cout << "char: invalid input" << std::endl;
    		return;
   		}
		if ((ascii_value >= 0 && ascii_value < 32) 
			|| (ascii_value > 126) || (ascii_value < 0))
		{
			std::cout << "char: non printable" << std::endl;
			return ;
		}
		else
			std::cout << "char: " << static_cast<char>(ascii_value) << std::endl;
		return ;
	}
	if ((literal.length() == 1 && literal[0] >= 0 && literal[0] < 32)
		|| (literal.length() == 1 && literal[0] >= '0' && literal[0] <= '9'))
		std::cout << "char: non printable" << std::endl;
	else if (literal.length() == 1)
		std::cout << "char: " << literal[0] << std::endl;
	else
		std::cout << "char: " << static_cast<char>(literal[0]) << std::endl;
}

void	print_int(std::string literal, bool	is_char)
{
	if (!is_char)
	{
		char *end;
   		long long int_value = std::strtold(literal.c_str(), &end);
    	if (*end != '\0')
		{
       		std::cout << "int: invalid input" << std::endl;
        	return;
    	}
		if (int_value > INT_MAX || int_value < INT_MIN)
			std::cout << "int: out of range" << std::endl;
		else 
		{
			int int_converted = static_cast<int>(int_value);
			std::cout << "int: " << int_converted << std::endl;
		}
	}
	else
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
}

void	print_float(std::string literal, bool is_char)
{
	std::cout << std::fixed << std::setprecision(1);
	if (!is_char)
	{
		char *end;
    	long double float_value = std::strtold(literal.c_str(), &end);
    	if (*end != '\0')
		{
    	    std::cout << "float: invalid input" << std::endl;
    	    return;
    	}
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
	else
		std::cout << "float: " << static_cast<float>(literal[0]) << "f" << std::endl;
}

void	print_double(std::string literal, bool is_char)
{
	std::cout << std::fixed << std::setprecision(1);
	if (!is_char)
	{
		char *end;
    	long double double_value = std::strtod(literal.c_str(), &end);
    	if (*end != '\0') 
		{
    	    std::cout << "double: invalid input" << std::endl;
    	    return;
    	}
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
	else
		std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
}

//Print special cases like NaN and -inff, +inff, -inf, +inf
int	print_special(int type)
{
	std::string type_str;
	if (type == TYPE_N_INF)
		type_str = "-inf";
	else if (type == TYPE_P_INF)
		type_str = "+inf";
	else
		type_str = "+inf";
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
    std::cout << "float: " <<  type_str << "f" << std::endl;
    std::cout << "double: " << type_str << std::endl;
	return (EXIT_SUCCESS);
}
