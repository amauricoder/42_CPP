/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:25:14 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/23 13:44:14 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	if (test_constructor_no_paramether()
		|| test_constructor_int_number_parameter()
		|| test_copy_constructor_int()
		|| test_copy_constructor_int_modify_values()
		|| test_try_to_access_empty_arr()
		|| test_try_to_access_out_of_bounds()
		|| test_constructor_double_number_parameter()
		|| test_struct_type())
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
		return (success_msg("test_constructor_no_paramether"));
	}
	return (err_invalid_test("FAIL test_constructor_no_paramether", __LINE__, __FILE__));
}

int	test_constructor_int_number_parameter(void)
{
	std::cout << "2 test_constructor_int_number_parameter" << std::endl;
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
		return (err_invalid_test("FAIL test_constructor_int_number_parameter", __LINE__, __FILE__));
	}
	return (success_msg("test_constructor_int_number_parameter"));
}

int	test_copy_constructor_int(void)
{
	std::cout << "3 test_constructor_int_number_parameter" << std::endl;
	Array<int> b(3);
	//set values to the array of b
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	std::cout << "b values: "<< b[0] << b[1] << b[2] << std::endl;
	Array<int> c(b);
	//Check values of array c -> they need to be the same as b
	std::cout << "c values: "<< c[0] << c[1] << c[2] << std::endl;
	//If they have the same address === TEST FAIL
	if (&c[0] == &b[0] || &c[1] == &b[1] || &c[2] == &b[2])
		return (err_invalid_test("FAIL test_constructor_int_number_parameter", __LINE__, __FILE__));
	return (success_msg("test_copy_constructor_int"));
}

int	test_copy_constructor_int_modify_values(void)
{
	std::cout << "4 test_constructor_int_number_parameter" << std::endl;
	Array<int> b(3);
	//set values to the array of b
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	std::cout << "b values: "<< b[0] << b[1] << b[2] << std::endl;
	Array<int> c(b);
	//Change c values
	c[0] = 4;
	c[1] = 5;
	c[2] = 6;
	std::cout << "c values: "<< c[0] << c[1] << c[2] << std::endl;
	std::cout << "b values after c modification: "<< b[0] << b[1] << b[2] << std::endl;
	//If they have the same address === TEST FAIL || if they have the same values === TEST FAIL
	if (&c[0] == &b[0] || &c[1] == &b[1] || &c[2] == &b[2]
		|| c[0] == b[0] || c[1] == b[1] || c[2] == b[2])
		return (err_invalid_test("FAIL test_constructor_int_number_parameter", __LINE__, __FILE__));
	return (success_msg("test_copy_constructor_int_modify_values"));
}

int test_assignment_operator_int(void)
{
	std::cout << "4 test_constructor_int_number_parameter" << std::endl;
	Array<int> b(1);
	b[0] = 42;
	Array<int> c;
	c = b;
	if (c[0] != 42)
		return (err_invalid_test("FAIL test_constructor_int_number_parameter", __LINE__, __FILE__));
	return (success_msg("test_assignment_operator_int"));
}

int	test_try_to_access_empty_arr(void)
{
	std::cout << "5 test_constructor_no_paramether" << std::endl;
	Array<int> b;
	try {
		std::cout << b[0] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (success_msg("test_constructor_no_paramether"));
	}
	return (err_invalid_test("FAIL test_constructor_no_paramether", __LINE__, __FILE__));
}

int	test_try_to_access_out_of_bounds(void)
{
	std::cout << "6 test_try_to_access_out_of_bounds" << std::endl;
	Array<int> b(1);
	try {
		//try to access out of bounds, needs to throw an exception
		std::cout << b[1] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (success_msg("test_try_to_access_out_of_bounds"));
	}
	return (err_invalid_test("FAIL test_try_to_access_out_of_bounds", __LINE__, __FILE__));
}

int	test_constructor_double_number_parameter(void)
{
	std::cout << "7 test_constructor_double_number_parameter" << std::endl;
	Array<double> b(3);
	//set values to the array of b
	try
	{
		b[0] = 1.1;
		b[1] = 2.2;
		b[2] = 3.3;
		std::cout << "b values: "<< b[0] << " " << b[1] << " " << b[2] << std::endl;
	}
	catch (std::exception &e)
	{
		//if it throws an exception, the test failed
		return (err_invalid_test("FAIL test_constructor_double_number_parameter", __LINE__, __FILE__));
	}
	return (success_msg("test_constructor_double_number_parameter"));
}

int	test_struct_type(void)
{
	std::cout << "7 test_struct_type" << std::endl;
	try
	{
		Array<s_struct> structArr(2);
		structArr[0].a = 42;
		structArr[0].b = 42.42;
		structArr[0].c = 'a';

		structArr[1].a = 21;
		structArr[1].b = 21.21;
		structArr[1].c = 'b';
		
		std::cout << "structArr[0].a: " << structArr[0].a << std::endl;
		std::cout << "structArr[0].b: " << structArr[0].b << std::endl;
		std::cout << "structArr[0].c: " << structArr[0].c << std::endl;
		std::cout << "structArr[1].a: " << structArr[1].a << std::endl;
		std::cout << "structArr[1].b: " << structArr[1].b << std::endl;
		std::cout << "structArr[1].c: " << structArr[1].c << std::endl;
	}
	catch (std::exception &e)
	{
		return (err_invalid_test("FAIL test_struct_type", __LINE__, __FILE__));
	}
	return (success_msg("test_struct_type"));
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

int	success_msg(std::string msg)
{
	std::cout << BG_GREEN << "SUCCESS - " << msg << RESET << std::endl;
	return (EXIT_SUCCESS);
}