/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:29:27 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/15 22:35:34 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//class declaration
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

//INTERT
static int	test_intern_creation_shrubbery(void);
static int 	test_intern_creation_robotomy(void);
static int	test_intern_creation_presidential(void);
static int 	test_intern_creation_invalid(void);
static int	test_subject(void);
//DEBUG
static int	err_invalid_test(std::string test_name, int line);

int main(void)
{
	std::cout << "*************************************" << std::endl;
	std::cout << "*           TESTS Intern            *" << std::endl;
	std::cout << "*************************************" << std::endl;

	if (test_intern_creation_shrubbery() || test_intern_creation_robotomy()
		|| test_intern_creation_presidential() || test_intern_creation_invalid()
		|| test_subject())
		return (EXIT_FAILURE);
	
	return (0);
}

/****************************************************************/
/*                           INTERN                             */
/****************************************************************/

//Should not cat the err
int	test_intern_creation_shrubbery(void)
{
	Intern a;
	AForm *f;

	try
	{
		f = a.makeForm("shrubbery creation", "Amauri");
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (err_invalid_test("test_intern_creation_shrubbery", __LINE__));
	}
	std::cout << *f << std::endl;
	delete f;
	return (EXIT_SUCCESS);
}

//Should not cat the err
int test_intern_creation_robotomy(void)
{
	Intern a;
	AForm *f;
	
	try
	{
		f = a.makeForm("robotomy request", "Bozo");
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (err_invalid_test("test_intern_creation_shrubbery", __LINE__));
	}
	std::cout << *f << std::endl;
	delete f;
	return (EXIT_SUCCESS);
}

//Should not cat the err
int test_intern_creation_presidential(void)
{
	Intern a;
	AForm *f;
	
	try
	{
		f = a.makeForm("presidential pardon", "Lula");
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (err_invalid_test("test_intern_creation_presidential", __LINE__));
	}
	std::cout << *f << std::endl;
	delete f;
	return (EXIT_SUCCESS);
}

//Should cat the err
int test_intern_creation_invalid(void)
{
	Intern a;
	AForm *f;
	
	try
	{
		f = a.makeForm("invalido", "Lula");
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_SUCCESS);
	}
	return (err_invalid_test("test_intern_creation_invalid", __LINE__));
}

int	test_subject(void)
{
	Intern someRandomIntern;
	AForm *rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	
	std::cout << *rrf << "Target : " << rrf->getTarget() << std::endl;
	delete rrf;
	return (EXIT_SUCCESS);
}

/****************************************************************/
/*                       DEBUUUUUGGGGGGGGG                      */
/****************************************************************/

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