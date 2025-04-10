/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:21:22 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/15 16:01:54 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "utils.hpp"

int	test_instanciate_Base()
{
	std::cout << BG_BLUE "1 - test_instanciate_Base()" RESET << std::endl;
	try 
	{
		Base b;
		std::cout << BG_BLUE "END - 1 - test_instanciate_Base()" RESET << std::endl;
		return (SUCCESS);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
		return (err_invalid_test("test_instanciate_Base()", __LINE__, __FILE__));
	}
}

/**
* @attention uncomment on construction of class "A"
* to check that function is working properly.
*/
int	test_instanciate_ABC(void)
{
	std::cout << BG_GREEN "2 - test_instanciate_ABC()" RESET << std::endl;
	try
	{
		A a;
		B b;
		C c;

		std::cout << BG_GREEN "END - 2 - test_instanciate_ABC()" RESET << std::endl;
		return (SUCCESS);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
		return (err_invalid_test("test_instanciate_ABC()", __LINE__, __FILE__));
	}
}

void test_identify_ptr_a(void)
{
	std::cout << BG_MAGENTA "3 - test_identify_ptr_a()" RESET << std::endl;
	A a;
	identify(&a);
	std::cout << BG_MAGENTA " END - 3 - test_identify_ptr_a()" RESET << std::endl;

}

void test_identify_ptr_b(void)
{
	std::cout << BG_ORANGE "4 - test_identify_ptr_b()" RESET << std::endl;
	B b;
	identify(&b);
	std::cout << BG_ORANGE "END - 4 - test_identify_ptr_b()" RESET << std::endl;

}

void test_identify_ptr_c(void)
{
	std::cout << BG_BLUE "5 - test_identify_ptr_c()" RESET << std::endl;
	C c;
	identify(&c);
	std::cout << BG_BLUE "END 5 - test_identify_ptr_c()" RESET << std::endl;
}

void test_identify_ref_a(void)
{
	std::cout << BG_GREEN "6 - test_identify_ref_a()" RESET << std::endl;
	Base *p = new A;
	identify(*p);
	std::cout << BG_GREEN "END 6 - test_identify_ref_a()" RESET << std::endl;
}


void test_identify_ref_b(void)
{
	std::cout << BG_MAGENTA "7 - test_identify_ref_b()" RESET << std::endl;
	Base *p = new B;
	identify(*p);
	std::cout << BG_MAGENTA "7 - test_identify_ref_b()" RESET << std::endl;
}

void test_identify_ref_c(void)
{
	std::cout << BG_ORANGE "8 - test_identify_ref_c()" RESET << std::endl;
	C p;
	identify(p);
	std::cout << BG_ORANGE "END - 8 - test_identify_ref_c()" RESET << std::endl;
}

void test_identify_unknown(void)
{
	std::cout << BG_BLUE "9 - test_identify_unknown()" RESET << std::endl;
	Base p;
	identify(p);
	identify(&p);
	std::cout << BG_BLUE "END - 9 - test_identify_unknown()" RESET << std::endl;
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

	return (FAIL);
}

//print error msg and return status
int	err_msg(std::string msg, int status, int line, const char* file)
{
	std::cerr << "Error! Line " << line << " file " << file << "\n" << msg << std::endl;
	return (status);
}