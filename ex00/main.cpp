/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:29:27 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/14 20:15:28 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//class declaration
#include "Bureaucrat.hpp"

#include <string>
#include <sstream>
//colors declaration
#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_ORANGE   "\033[48;5;202m"
#define BG_RED      "\033[41m"
#define RESET       "\033[0m"
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

//tests declaration
static int	test_setGrade_toohigh(void);
static int	test_SetGrade_toolow(void);
static int	test_grade_increment(void);
static int	test_grade_increment2(void);
static int	test_grade_decrement(void);
static int	test_grade_decrement2(void);
static int	test_default_constructor(void);
static int	test_int_constructor(void);
static int	test_int_constructor_toohigh(void);
static int	test_int_constructor_toolow(void);
static int	test_copy_constructor(void);
static int	test_copy_assignment_operator(void);

static int	err_invalid_test(std::string test_name, int line);

int main(void)
{
	// REMEMBER - 1 is the highest grade - 150 is the lowest grade
	if (test_setGrade_toohigh() || test_SetGrade_toolow()
		|| test_grade_increment() || test_grade_increment2() || test_grade_decrement()
		|| test_grade_decrement2() || test_default_constructor() || test_int_constructor()
		|| test_int_constructor_toohigh() || test_int_constructor_toolow()
		|| test_copy_constructor() || test_copy_assignment_operator())
		return (EXIT_FAILURE);
	
	Bureaucrat a("burocrata");
	std::cout << "Test for ostream overload -> " << a << std::endl;
	return (0);
}

//test need to be done with value = 0
// needs to output toohigh msg.
int	test_setGrade_toohigh(void)
{
	std::cout << BG_ORANGE "test_setGrade_toohigh" RESET << std::endl;
	try
	{
		Bureaucrat b;
		b.setGrade(0);
	}
	catch (const Bureaucrat::GradeTooHighException& e){
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
		return (err_invalid_test("test_setGrade_toohigh" , __LINE__));
	}
	std::cout << BG_ORANGE "END test_setGrade_toohigh" RESET << std::endl;
	return (EXIT_SUCCESS);
}

// needs to output toolow msg.
int	test_SetGrade_toolow(void)
{
	std::cout << BG_MAGENTA "test_SetGrade_toolow" RESET << std::endl;
	try
	{
		Bureaucrat b;
		b.setGrade(151);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		return (err_invalid_test("test_SetGrade_toolow" , __LINE__));
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << BG_MAGENTA "END test_SetGrade_toolow" RESET << std::endl;
	return (EXIT_SUCCESS);
}

//test need to be done with value = 1
//needs to output toohigh msg.
int	test_grade_increment(void)
{
	std::cout << BG_GREEN "test_grade_increment" RESET << std::endl;
	try
	{
		Bureaucrat b(1);
		b++;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
		return (err_invalid_test("test_grade_increment" , __LINE__));
	}
	std::cout << BG_GREEN "END test_grade_increment" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_grade_increment2(void)
{
	std::cout << BG_ORANGE "test_grade_increment2" RESET << std::endl;
	Bureaucrat a;

	a++;
	if (a.getGrade() != 149)
		return (err_invalid_test("test_grade_increment2" , __LINE__));
	std::cout << BG_ORANGE "test_grade_increment2" RESET << std::endl;
	return (EXIT_SUCCESS);
}

//tests need to be done with value = 150
//needs to output toolow msg
int	test_grade_decrement(void)
{
	std::cout << BG_BLUE "test_grade_decrement" RESET << std::endl;
	try
	{
		Bureaucrat b(150);
		b --;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		return (err_invalid_test("test_grade_decrement" , __LINE__));
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << BG_BLUE "END test_grade_decrement" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_grade_decrement2(void)
{
	std::cout << BG_GREEN "test_grade_decrement2" RESET << std::endl;
	Bureaucrat a(10);

	a--;
	if (a.getGrade() != 11)
		return (err_invalid_test("test_grade_increment2" , __LINE__));
	std::cout << BG_GREEN "test_grade_decrement2" RESET << std::endl;
	return (EXIT_SUCCESS);
}

//needs to init the object with 150
int	test_default_constructor(void)
{
	std::cout << BG_ORANGE "test_default_constructor" RESET << std::endl;
	Bureaucrat a;
	if (a.getGrade() != 150)
		return (err_invalid_test("test_default_constructor" , __LINE__));
	std::cout << BG_ORANGE "END test_default_constructor" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_int_constructor(void)
{
	std::cout << BG_MAGENTA "test_int_constructor" RESET << std::endl;
	Bureaucrat a(120);

	if (a.getGrade() != 120)
		return (err_invalid_test("test_int_constructor" , __LINE__));
	
	std::cout << BG_MAGENTA "END test_int_constructor" RESET << std::endl;
	return (EXIT_SUCCESS);
}

//must throw toohight error msg
int	test_int_constructor_toohigh(void)
{
	std::cout << BG_GREEN "test_int_constructor_toohigh" RESET << std::endl;
	try 
	{
		Bureaucrat error(-1);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
		return (err_invalid_test("test_int_constructor_toohigh" , __LINE__));
	}
	std::cout << BG_GREEN "END test_int_constructor_toohigh" RESET << std::endl;
	return (EXIT_SUCCESS);
}

//must throw toolow error msg
int	test_int_constructor_toolow(void)
{
	std::cout << BG_BLUE "test_int_constructor_toolow" RESET << std::endl;
	try 
	{
		Bureaucrat error(151);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		return (err_invalid_test("test_int_constructor_toolow" , __LINE__));
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << BG_BLUE "END test_int_constructor_toolow" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int test_copy_constructor(void)
{
	std::cout << BG_ORANGE "test_copy_constructor" RESET << std::endl;
	Bureaucrat a("A");
	Bureaucrat b(a);

	if (b.getGrade() != a.getGrade() || b.getName() != a.getName())
		return (err_invalid_test("test_copy_constructor" , __LINE__));
	std::cout << BG_ORANGE "test_copy_constructor" RESET << std::endl;
	return (EXIT_SUCCESS);	
}

//copy assignment operator
int	test_copy_assignment_operator(void)
{
	std::cout << BG_MAGENTA "test_copy_assignment_operator" RESET << std::endl;
	Bureaucrat a(150);
	Bureaucrat b("B");

	b = a;
	if (a.getGrade() != b.getGrade())
		return (err_invalid_test("test_copy_constructor" , __LINE__));
	std::cout << BG_MAGENTA "test_copy_assignment_operator" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	err_invalid_test(std::string test_name, int line)
{
	std::ostringstream oss;
	oss << line;

	std::cerr << BG_RED << test_name << RESET << std::endl;
	std::cerr << BG_RED  "Error! in line " 
		+ oss.str() + " in " + std::string(__FILE__) << RESET
	<< std::endl;

	return (EXIT_FAILURE);
}