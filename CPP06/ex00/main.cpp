/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:29:27 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/15 16:26:48 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "ScalarConverter.hpp"

//static_cast<type>(var)
//used on compilation time, to more secure convertions
int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	
	if (argc != 2)
		return (err_msg("invalid argument.", 1, __LINE__, __FILE__));
	
	//Uncomment this to run tests
	/* if (test_instantiate_ScalarConverter() || test_ScalarConverter_char_type_alphabet()
		|| test_ScalarConverter_char_not_printable_ASCII() || test_ScalarConverter_ASCII_symbols()
		|| test_ScalarConverter_nan() || test_inf_positive() || test_inf_negative()
		|| test_ScalarConverter_only_space() || test_ScalarConverter_int()
		|| test_ScalarConverter_0_to_10_int() || test_ScalarConverter_0_to_150_int())
		return (EXIT_FAILURE); */

	return (ScalarConverter::convert(argv[1]));
}
