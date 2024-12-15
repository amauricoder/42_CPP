/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:29:27 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/15 20:15:08 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//class declaration
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

//shruberry form
static int	test_shruberry_default_constructor(void);
static int	test_shruberry_by_reference(void);
static int	test_shruberry_copy_constructor(void);
static int 	test_shruberry_target_constructor(void);
static int	test_shruberry_executeForm(void);

//RobotomyRequestForm:
static int	test_robotomy_default_constructor(void);
static int	test_robotomy_by_reference(void);
static int	test_robotomy_copy_constructor(void);
static int	test_robotomy_target_constructor(void);
static int	test_robotomy_executeForm(void);

//PresidentialPardonForm
static int	test_presidential_default_constructor(void);
static int	test_presidential_by_reference(void);
static int	test_presidential_copy_constructor(void);
static int	test_presidential_target_constructor(void);
static int	test_presidential_executeForm(void);

// Throw Exceptions
static int 	test_bureaucrat_too_low_to_sign(void);
static int	test_form_not_signed(void);
static int	test_bureaucrat_executeForm_negative(void);
static int	test_bureaucrat_executeForm_positive(void);

//DEBUG
static int	err_invalid_test(std::string test_name, int line);

int main(void)
{
	//Uncomment line below should return error(ABSTRACT CLASS).
	//AForm test;
	
	std::cout << "*************************************" << std::endl;
	std::cout << "*    TESTS ShrubberyCreationForm    *" << std::endl;
	std::cout << "*************************************" << std::endl;

	if (test_shruberry_default_constructor() || test_shruberry_by_reference()
		|| test_shruberry_copy_constructor() || test_shruberry_target_constructor()
		|| test_shruberry_executeForm())
		return (EXIT_FAILURE);

	std::cout << "*************************************" << std::endl;
	std::cout << "*    TESTS RobotomyRequestForm    *" << std::endl;
	std::cout << "*************************************" << std::endl;
	
	if (test_robotomy_default_constructor() || test_robotomy_by_reference()
	|| test_robotomy_copy_constructor() || test_robotomy_target_constructor()
	|| test_robotomy_executeForm())
		return (EXIT_FAILURE);

	std::cout << "*************************************" << std::endl;
	std::cout << "*    TESTS PresidentialPardonForm    *" << std::endl;
	std::cout << "*************************************" << std::endl;

	if (test_presidential_default_constructor() || test_presidential_by_reference()
	|| test_presidential_copy_constructor() || test_presidential_target_constructor()
	|| test_presidential_executeForm())
		return (EXIT_FAILURE);
	
	std::cout << "*************************************" << std::endl;
	std::cout << "*    TESTS THROW EXCEPTIONS         *" << std::endl;
	std::cout << "*************************************" << std::endl;
	
	if (test_bureaucrat_too_low_to_sign() || test_form_not_signed()
		|| test_bureaucrat_executeForm_negative() || test_bureaucrat_executeForm_positive())
		return (EXIT_FAILURE);
	return (0);
}


/****************************************************************/
/*                     ShrubberyCreationForm                    */
/****************************************************************/

int	test_shruberry_default_constructor(void)
{
	std::cout << BG_BLUE "1 test_shruberry_default_constructor" RESET <<  std::endl;
	ShrubberyCreationForm a;
	
	if (a.getGradeExec() != 137 || a.getGradeSign() != 145
		|| a.getName() != "ShrubberyCreationForm" || a.getTarget() != "")
		return (err_invalid_test("test_shruberry_default_constructor", __LINE__));
	std::cout << BG_BLUE "END 1 test_shruberry_default_constructor" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_shruberry_by_reference(void)
{
	std::cout << BG_GREEN "2 test_shruberry_by_reference" RESET <<  std::endl;

	AForm *ptr = new ShrubberyCreationForm();
	
	if (ptr->getGradeExec() != 137 || ptr->getGradeSign() != 145
		|| ptr->getName() != "ShrubberyCreationForm")
	{
		delete ptr;
		return (err_invalid_test("test_shruberry_by_reference", __LINE__));
	}
	std::cout << BG_GREEN "END 2 test_shruberry_by_reference" RESET <<  std::endl;
	delete ptr;
	return (EXIT_SUCCESS);
}

int	test_shruberry_copy_constructor(void)
{
	std::cout << BG_MAGENTA "3 test_shruberry_copy_constructor" RESET <<  std::endl;
	ShrubberyCreationForm a;
	ShrubberyCreationForm b(a);

	if (b.getGradeExec() != a.getGradeExec() || b.getGradeSign() != a.getGradeSign()
		|| b.getName() != a.getName() || b.getTarget() != a.getTarget())
		return (err_invalid_test("test_shruberry_copy_constructor", __LINE__));
	std::cout << BG_MAGENTA "END 3 test_shruberry_copy_constructor" RESET <<  std::endl;
	return (EXIT_SUCCESS);
}

int test_shruberry_target_constructor(void)
{
	std::cout << BG_ORANGE "4 test_shruberry_target_constructor" RESET <<  std::endl;
	ShrubberyCreationForm a("amauricoder");

	if (a.getTarget() != "amauricoder" || a.getGradeExec() != 137 
	|| a.getGradeSign() != 145 || a.getName() != "ShrubberyCreationForm")
		return (err_invalid_test("test_shruberry_target_constructor", __LINE__));
	std::cout << BG_ORANGE "4 test_shruberry_target_constructor" RESET <<  std::endl;
	return (EXIT_SUCCESS);
}

//Check if a file is correctly created with the specific name on it
int	test_shruberry_executeForm(void)
{
	std::cout << BG_BLUE "5 test_shruberry_executeForm" RESET <<  std::endl;
	ShrubberyCreationForm a("test");
	
	a.formAction();
	std::ifstream file("test_shrubbery");
	
	if (file.is_open())
	{
		std::string file_line;
		
		while (getline(file, file_line))
			std::cout << file_line << std::endl;
		file.close();
	}
	else
		return (err_invalid_test("test_shruberry_executeForm", __LINE__));
	std::cout << BG_BLUE "5 test_shruberry_executeForm" RESET <<  std::endl;
	return (EXIT_SUCCESS);
}

/****************************************************************/
/*                     RobotomyRequestForm:                     */
/****************************************************************/

int test_robotomy_default_constructor(void)
{
	std::cout << BG_GREEN "6 test_robotomy_default_constructor" RESET <<  std::endl;
	RobotomyRequestForm a;
	
	if (a.getGradeExec() != 45 || a.getGradeSign() != 72
		|| a.getName() != "RobotomyRequestForm" || a.getTarget() != "")
		return (err_invalid_test("test_robotomy_default_constructor", __LINE__));
	std::cout << BG_GREEN "END 6 test_robotomy_default_constructor" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_robotomy_by_reference(void)
{
	std::cout << BG_MAGENTA "7 test_robotomy_by_reference" RESET <<  std::endl;

	AForm *ptr = new RobotomyRequestForm();
	
	if (ptr->getGradeExec() != 45 || ptr->getGradeSign() != 72
		|| ptr->getName() != "RobotomyRequestForm" || ptr->getTarget() != "")
	{
		delete ptr;
		return (err_invalid_test("test_robotomy_by_reference", __LINE__));
	}
	std::cout << BG_MAGENTA "END 7 test_robotomy_by_reference" RESET <<  std::endl;
	delete ptr;
	return (EXIT_SUCCESS);
}

int	test_robotomy_copy_constructor(void)
{
	std::cout << BG_ORANGE "8 test_robotomy_copy_constructor" RESET <<  std::endl;
	RobotomyRequestForm a;
	RobotomyRequestForm b(a);

	if (b.getGradeExec() != a.getGradeExec() || b.getGradeSign() != a.getGradeSign()
		|| b.getName() != a.getName() || b.getTarget() != a.getTarget())
		return (err_invalid_test("test_robotomy_copy_constructor", __LINE__));
	std::cout << BG_ORANGE "END 8 test_robotomy_copy_constructor" RESET <<  std::endl;
	return (EXIT_SUCCESS);
}

int test_robotomy_target_constructor(void)
{
	std::cout << BG_BLUE "9 test_robotomy_target_constructor" RESET <<  std::endl;
	RobotomyRequestForm a("amauricoder");

	if (a.getTarget() != "amauricoder" || a.getGradeExec() != 45 
	|| a.getGradeSign() != 72 || a.getName() != "RobotomyRequestForm")
		return (err_invalid_test("test_shruberry_target_constructor", __LINE__));
	std::cout << BG_BLUE "9 test_robotomy_target_constructor" RESET <<  std::endl;
	return (EXIT_SUCCESS);
}

/* This test was made to compare the pairs 
the return of formAction (pair to robotomy ok and odd otherwise)
with the r_exec (that is the turn)
if their are not both pairs or both oods, the function is not working as expected
(50% of roboromization)  */
int	test_robotomy_executeForm(void)
{
	std::cout << BG_MAGENTA "10 test_robotomy_executeForm" RESET <<  std::endl;
	RobotomyRequestForm a("amauricoder");
	
	for (int r_exec = 1; r_exec <= 10; r_exec ++)
	{
		if (a.formAction() % 2 != 0 && r_exec % 2 == 0)
			return (err_invalid_test("test_robotomy_executeForm", __LINE__));
	}
	std::cout << BG_MAGENTA "10 test_robotomy_executeForm" RESET <<  std::endl;
	return (EXIT_SUCCESS);
}

/****************************************************************/
/*                     PresidentialPardonForm:                  */
/****************************************************************/

int test_presidential_default_constructor(void)
{
	std::cout << BG_BLUE "11 test_presidential_default_constructor" RESET <<  std::endl;
	PresidentialPardonForm a;
	
	if (a.getGradeExec() != PR_EXEC || a.getGradeSign() != PR_SIGN
		|| a.getName() != "PresidentialPardonForm" || a.getTarget() != "")
		return (err_invalid_test("test_presidential_default_constructor", __LINE__));
	std::cout << BG_BLUE "END 11 test_presidential_default_constructor" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_presidential_by_reference(void)
{
	std::cout << BG_GREEN "12 test_presidential_by_reference" RESET <<  std::endl;

	AForm *ptr = new PresidentialPardonForm();
	
	if (ptr->getGradeExec() != PR_EXEC || ptr->getGradeSign() != PR_SIGN
		|| ptr->getName() != "PresidentialPardonForm" || ptr->getTarget() != "")
	{
		delete ptr;
		return (err_invalid_test("test_presidential_by_reference", __LINE__));
	}
	std::cout << BG_GREEN "END 12 test_presidential_by_reference" RESET <<  std::endl;
	delete ptr;
	return (EXIT_SUCCESS);
}

int	test_presidential_copy_constructor(void)
{
	std::cout << BG_MAGENTA "13 test_presidential_copy_constructor" RESET <<  std::endl;
	PresidentialPardonForm a;
	PresidentialPardonForm b(a);

	if (b.getGradeExec() != a.getGradeExec() || b.getGradeSign() != a.getGradeSign()
		|| b.getName() != a.getName() || b.getTarget() != a.getTarget())
		return (err_invalid_test("test_presidential_copy_constructor", __LINE__));
	std::cout << BG_MAGENTA "END 13 test_presidential_copy_constructor" RESET <<  std::endl;
	return (EXIT_SUCCESS);
}

int test_presidential_target_constructor(void)
{
	std::cout << BG_ORANGE "14 test_presidential_target_constructor" RESET <<  std::endl;
	PresidentialPardonForm a("amauricoder");

	if (a.getTarget() != "amauricoder" || a.getGradeExec() != PR_EXEC 
	|| a.getGradeSign() != PR_SIGN || a.getName() != "PresidentialPardonForm")
		return (err_invalid_test("test_presidential_target_constructor", __LINE__));
	std::cout << BG_ORANGE "END 14 test_presidential_target_constructor" RESET <<  std::endl;
	return (EXIT_SUCCESS);
}

int	test_presidential_executeForm(void)
{
	std::cout << BG_BLUE "15 test_presidential_executeForm" RESET <<  std::endl;
	PresidentialPardonForm a("amauricoder");

	a.formAction();
	std::cout << BG_BLUE "END 15 test_presidential_executeForm" RESET <<  std::endl;
	return (EXIT_SUCCESS);
}

/****************************************************************/
/*                       THROW EXCEPTIONS                       */
/****************************************************************/

//needs to catch exception
int test_bureaucrat_too_low_to_sign(void)
{
	std::cout << BG_GREEN "16 test_bureaucrat_too_low_to_sign" RESET <<  std::endl;
	Bureaucrat d("D");
	Bureaucrat j("J");
	j.setGrade(1);
	AForm *f = new RobotomyRequestForm();
	try
	{
		f->beSigned(j);
		f->execute(d);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;	
		std::cout << BG_GREEN "16 test_bureaucrat_too_low_to_sign" RESET <<  std::endl;
		delete f;
		return (EXIT_SUCCESS);
	}
	delete f;
	return (err_invalid_test("END 16 test_bureaucrat_too_low_to_sign", __LINE__));
}

//needs to catch exception
int	test_form_not_signed(void)
{
	std::cout << BG_MAGENTA "17 test_form_not_signed" RESET <<  std::endl;
	Bureaucrat d("D");
	AForm *f = new PresidentialPardonForm();
	try
	{
		f->beSigned(d);	
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << BG_MAGENTA "17 test_form_not_signed" RESET <<  std::endl;
		delete f;
		return (EXIT_SUCCESS);
	}
	delete f;
	return (err_invalid_test("END 17 test_bureaucrat_too_low_to_sign", __LINE__));
}

//needs to catch exception
int	test_bureaucrat_executeForm_negative(void)
{
	std::cout << BG_ORANGE "18 test_bureaucrat_executeForm_negative" RESET <<  std::endl;
	Bureaucrat d("D");
	AForm *f = new PresidentialPardonForm();

	if (d.executeForm(*f) == 1)
	{
		delete f;
		std::cout << BG_ORANGE "18 END test_bureaucrat_executeForm_negative" RESET <<  std::endl;
		return (EXIT_SUCCESS);
	}
	delete f;
	return (err_invalid_test("END 18 test_bureaucrat_executeForm_negative", __LINE__));
}

//needs to work
int	test_bureaucrat_executeForm_positive(void)
{
	std::cout << BG_ORANGE "19 test_bureaucrat_executeForm_positive" RESET <<  std::endl;
	Bureaucrat d("D");
	d.setGrade(1);
	AForm *f = new ShrubberyCreationForm();
	
	f->beSigned(d);
	if (d.executeForm(*f) == 0)
	{
		delete f;
		std::cout << BG_ORANGE "19 END test_bureaucrat_executeForm_positive" RESET <<  std::endl;
		return (EXIT_SUCCESS);
	}
	delete f;
	return (err_invalid_test("END 18 test_bureaucrat_executeForm_positive", __LINE__));
	
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