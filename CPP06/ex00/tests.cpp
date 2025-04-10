/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:03:24 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/18 19:58:06 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

/***********************************************/
/*                   TESTS                     */
/***********************************************/
int	test_instantiate_ScalarConverter(void)
{
	std::cout << BG_GREEN "1 test_instantiate_ScalarConverter" RESET << std::endl;
	//uncomment line below, need to return error by the compiler.
	//ScalarConverter test;
	
	std::cout << BG_GREEN "1 test_instantiate_ScalarConverter TEST OK" RESET << std::endl;
	return (EXIT_SUCCESS);	
}

//Test for all the characters, UP and lowercase.
//Should print all the chars without error.
int	test_ScalarConverter_char_type_alphabet(void)
{
	std::cout << BG_BLUE "2 test_ScalarConverter_char_type_alphabet" RESET << std::endl;
	for (int i = 0; i < 52; i ++)
	{	
		std::cout << BG_BLUE << "START TEST LOOP" RESET << std::endl;
		char letter = (i < 26) ? ('a' + i) : ('A' + (i - 26));
		std::string letter_str(1, letter);
		if (ScalarConverter::convert(letter_str) != TYPE_CHAR)
			return (err_invalid_test("test_ScalarConverter_char_type_alphabet TEST FAIL", __LINE__, __FILE__));
		std::cout << BG_BLUE << "END TEST LOOP" RESET << std::endl;
	}
	std::cout << BG_BLUE "2 test_ScalarConverter_char_type_alphabet TEST OK" RESET << std::endl;
	return (EXIT_SUCCESS);
}

//Needs to print non displayable to char
int	test_ScalarConverter_char_not_printable_ASCII(void)
{
	std::cout << BG_MAGENTA "3 test_ScalarConverter_char_not_printable_ASCII" RESET << std::endl;
	for (int i = 0; i < 32; i ++)
	{	
		std::cout << BG_MAGENTA << "START TEST LOOP" RESET << std::endl;
		char letter = i;
		std::string letter_str(1, letter);
		std::cout << BG_ORANGE "Value(char) : " << i << RESET << std::endl;
		if (ScalarConverter::convert(letter_str) != TYPE_CHAR)
			return (err_invalid_test("test_ScalarConverter_char_type_alphabet TEST FAIL", __LINE__, __FILE__));
		std::cout << BG_MAGENTA << "END TEST LOOP" RESET << std::endl;
	}
	std::cout << BG_MAGENTA "3 test_ScalarConverter_char_not_printable_ASCII TEST OK" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_ScalarConverter_ASCII_symbols(void)
{
	std::cout << BG_ORANGE "4 test_ScalarConverter_ASCII_symbols" RESET << std::endl;
	for (int i = 33; i < 48; i ++)
	{	
		std::cout << BG_ORANGE << "START TEST LOOP" RESET << std::endl;
		char letter = i;
		std::string letter_str(1, letter);
		if (ScalarConverter::convert(letter_str) != TYPE_CHAR)
			return (err_invalid_test("test_ScalarConverter_ASCII_symbols TEST FAIL", __LINE__, __FILE__));
		std::cout << BG_ORANGE << "END TEST LOOP" RESET << std::endl;
	}
	for (int i = 58; i < 64; i ++)
	{
		std::cout << BG_ORANGE << "START TEST LOOP" RESET << std::endl;
		char letter = i;
		std::string letter_str(1, letter);
		if (ScalarConverter::convert(letter_str) != TYPE_CHAR)
			return (err_invalid_test("test_ScalarConverter_ASCII_symbols TEST FAIL", __LINE__, __FILE__));
		std::cout << BG_ORANGE << "END TEST LOOP" RESET << std::endl;
	}
	std::cout << BG_ORANGE "4 test_ScalarConverter_ASCII_symbols TEST OK" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int test_ScalarConverter_nan(void)
{
	std::cout << BG_BLUE << "5 test_ScalarConverter_nan " RESET << std::endl;
	
	if (ScalarConverter::convert("nan") != TYPE_NAN || ScalarConverter::convert("nanf") != TYPE_NAN)
			return (err_invalid_test("test_ScalarConverter_nan TEST FAIL", __LINE__, __FILE__));

	std::cout << BG_BLUE "5 test_ScalarConverter_nan TEST OK" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_inf_positive(void)
{
	std::cout << BG_GREEN << "6 test_inf_positive " RESET << std::endl;
	
	if (ScalarConverter::convert("+inf") != TYPE_P_INF || ScalarConverter::convert("+inff") != TYPE_P_INF)
			return (err_invalid_test("test_inf_positive TEST FAIL", __LINE__, __FILE__));

	std::cout << BG_GREEN "6 test_inf_positive TEST OK" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_inf_negative(void)
{
	std::cout << BG_MAGENTA << "7 test_inf_negative " RESET << std::endl;
	
	if (ScalarConverter::convert("-inf") != TYPE_N_INF || ScalarConverter::convert("-inff") != TYPE_N_INF)
			return (err_invalid_test("test_inf_negative TEST FAIL", __LINE__, __FILE__));

	std::cout << BG_MAGENTA "7 test_inf_negative TEST OK" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_ScalarConverter_only_space(void)
{
	std::cout << BG_ORANGE << "8 test_ScalarConverter_only_space " RESET << std::endl;
	
	if (ScalarConverter::convert(" ") != TYPE_CHAR)
			return (err_invalid_test("test_ScalarConverter_only_space TEST FAIL", __LINE__, __FILE__));
	std::cout << BG_ORANGE "8 test_ScalarConverter_only_space TEST OK" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_ScalarConverter_int(void)
{
	std::cout << BG_BLUE << "9 test_ScalarConverter_int " RESET << std::endl;
	if (ScalarConverter::convert("42") != TYPE_INT 
		|| ScalarConverter::convert("-42") != TYPE_INT
		|| ScalarConverter::convert("2147483648") != TYPE_INT  
		|| ScalarConverter::convert("-2147483649") != TYPE_INT)
	{
			return (err_invalid_test("test_ScalarConverter_int TEST FAIL", __LINE__, __FILE__));
	}
	std::cout << BG_BLUE << "9 test_ScalarConverter_int TEST" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int test_ScalarConverter_0_to_10_int(void)
{
	std::cout << BG_GREEN << "10 test_ScalarConverter_0_to_10_int " RESET << std::endl;
	for (int i = 0; i <= 10; i++)
	{
		std::cout << "****LOOP test_ScalarConverter_0_to_10_int****" << std::endl;
		std::ostringstream oss;
		oss << i;
		if (ScalarConverter::convert(oss.str()) != TYPE_INT)
			return (err_invalid_test("test_ScalarConverter_0_to_10_int TEST FAIL", __LINE__, __FILE__));
	}
	std::cout << BG_GREEN << "10 test_ScalarConverter_0_to_10_int " RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_ScalarConverter_0_to_150_int(void)
{
	std::cout << BG_MAGENTA << "11 test_ScalarConverter_0_to_150_int " RESET << std::endl;
	for (int i = 0; i <= 150; i++)
	{
		std::cout << "****LOOP test_ScalarConverter_0_to_150_int****" << std::endl;
		std::cout << BG_ORANGE "Value(int) : " << i << RESET << std::endl;
		std::ostringstream oss;
		oss << i;
		if (ScalarConverter::convert(oss.str()) != TYPE_INT)
			return (err_invalid_test("test_ScalarConverter_0_to_150_int TEST FAIL", __LINE__, __FILE__));
	}
	std::cout << BG_MAGENTA << "11 test_ScalarConverter_0_to_150_int " RESET << std::endl;
	return (EXIT_SUCCESS);
}
/***********************************************/
/*               DEBUG/ERROR MESSAGE           */
/***********************************************/

int	err_invalid_test(std::string test_name, int line, const char* file)
{
	std::ostringstream oss;
	oss << line;

	std::cerr << BG_RED << test_name << RESET << std::endl;
	std::cerr << BG_RED  "Error! in line " 
		+ oss.str() << " in file " << file << RESET
	<< std::endl;

	return (EXIT_FAILURE);
}

//print error msg and return status
int	err_msg(std::string msg, int status, int line, const char* file)
{
	std::cerr << "Error! Line " << line << " file " << file << "\n" << msg << std::endl;
	return (status);
}