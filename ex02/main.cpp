/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:25:14 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/23 11:53:59 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	//int *a = new int();
	//std::cout << (*a) << std::endl; 
	if (test_constructor_no_paramether()
		|| test_constructor_int_number())
		return (EXIT_FAILURE);
	return (0);
}

/***************************************/
/*                TESTS                */
/***************************************/
int	test_constructor_no_paramether(void)
{
	std::cout << "1 test_constructor_no_paramether" << std::endl;
	Array<int> b;
	try {
		std::cout << b[0] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		std::cout << BG_GREEN "SUCCESS" RESET << std::endl;
		return (EXIT_SUCCESS);
	}
	return (err_invalid_test("FAIL test_constructor_no_paramether", __LINE__, __FILE__));
}

int	test_constructor_int_number(void)
{
	std::cout << "2 test_constructor_int_number" << std::endl;
	Array<int> b(5);
	//Try to access indexes of the array.
	//needs to display the default value (0);
	try {
		std::cout << b[0] << std::endl;
		std::cout << b[1] << std::endl;
		std::cout << b[2] << std::endl;
		std::cout << b[3] << std::endl;
		std::cout << b[4] << std::endl;
	}
	catch (std::exception &e)
	{
		return (err_invalid_test("FAIL test_constructor_int_number", __LINE__, __FILE__));
	}
	std::cout << BG_GREEN "SUCCESS" RESET << std::endl;
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