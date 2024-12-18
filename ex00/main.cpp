/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:29:27 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/18 15:46:13 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//static int	err_invalid_test(std::string test_name, int line);
#include "tests.hpp"
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	
	/* if (argc != 2)
		return (err_msg("invalid argument.", 1, __LINE__, __FILE__)); */
	
	if (test_instantiate_ScalarConverter() || test_ScalarConverter_char_type_alphabet()
		|| test_ScalarConverter_char_not_printable() || test_ScalarConverter_char_not_letter()
		|| test_ScalarConverter_nan() || test_inf_positive() || test_inf_negative())
		return (EXIT_FAILURE);

	//print_double("0");


	return (0);
}
