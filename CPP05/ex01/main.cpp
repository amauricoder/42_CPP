/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:29:27 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/15 14:29:53 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//class declaration
#include "Bureaucrat.hpp"
#include "Form.hpp"

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

//BUREUCRAT
static int	test_bureucrat_setGrade_toohigh(void);
static int	test_bureucrat_SetGrade_toolow(void);
static int	test_bureucrat_grade_increment(void);
static int	test_bureucrat_grade_increment2(void);
static int	test_bureucrat_grade_decrement(void);
static int	test_bureucrat_grade_decrement2(void);
static int	test_bureucrat_default_constructor(void);
static int	test_bureucrat_int_constructor(void);
static int	test_bureucrat_int_constructor_toohigh(void);
static int	test_bureucrat_int_constructor_toolow(void);
static int	test_bureucrat_copy_constructor(void);
static int	test_bureucrat_copy_assignment_operator(void);
//BUREUCRAT EXERCISE 01 ADDED
static int 	test_bureucrat_signForm_possible(void);
static int	test_bureucrat_signForm_not_possible(void);

//FORM
static int	test_form_default_constructor(void);
static int	test_form_copy_constructor(void);
static int	test_form_copy_assignment_operator(void);
static int	test_form_constructor_toohigh(void);
static int	test_form_constructor_toolow(void);
static int	test_form_beSigned_posible(void);
static int 	test_form_beSigned_not_possible(void);

//DEBUG
static int	err_invalid_test(std::string test_name, int line);

int main(void)
{
	std::cout << "*************************************" << std::endl;
	std::cout << "*****      TESTS BUREAUCRAT     *****" << std::endl;
	std::cout << "*************************************" << std::endl;

	// REMEMBER - 1 is the highest grade - 150 is the lowest grade
	if (test_bureucrat_setGrade_toohigh() || test_bureucrat_SetGrade_toolow()
		|| test_bureucrat_grade_increment() || test_bureucrat_grade_increment2() || test_bureucrat_grade_decrement()
		|| test_bureucrat_grade_decrement2() || test_bureucrat_default_constructor() || test_bureucrat_int_constructor()
		|| test_bureucrat_int_constructor_toohigh() || test_bureucrat_int_constructor_toolow()
		|| test_bureucrat_copy_constructor() || test_bureucrat_copy_assignment_operator()
		|| test_bureucrat_signForm_possible() || test_bureucrat_signForm_not_possible())
		return (EXIT_FAILURE);
	
	Bureaucrat a("burocrata");
	std::cout << "Test for ostream overload burocrat -> " << a << std::endl;

	std::cout << "*************************************" << std::endl;
	std::cout << "*****         TESTS FORM        *****" << std::endl;
	std::cout << "*************************************" << std::endl;
	// REMEMBER - 1 is the highest grade - 150 is the lowest grade
	
	if (test_form_default_constructor() || test_form_copy_constructor()
		|| test_form_copy_assignment_operator() || test_form_constructor_toohigh()
		|| test_form_constructor_toolow() || test_form_beSigned_posible()
		|| test_form_beSigned_not_possible())
		return (EXIT_FAILURE);
	
	Form b("formulario", 42, 13);
	std::cout << "Test for ostream overload FORM ->" << b << std::endl;

	return (0);
}


/****************************************************************/
/*                       BUREAUCRAT TESTS!                      */
/****************************************************************/

//test need to be done with value = 0
// needs to output toohigh msg.
int	test_bureucrat_setGrade_toohigh(void)
{
	std::cout << BG_ORANGE "test_bureucrat_setGrade_toohigh" RESET << std::endl;
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
		return (err_invalid_test("test_bureucrat_setGrade_toohigh" , __LINE__));
	}
	std::cout << BG_ORANGE "END test_bureucrat_setGrade_toohigh" RESET << std::endl;
	return (EXIT_SUCCESS);
}

// needs to output toolow msg.
int	test_bureucrat_SetGrade_toolow(void)
{
	std::cout << BG_MAGENTA "test_bureucrat_SetGrade_toolow" RESET << std::endl;
	try
	{
		Bureaucrat b;
		b.setGrade(151);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		return (err_invalid_test("test_bureucrat_SetGrade_toolow" , __LINE__));
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << BG_MAGENTA "END test_bureucrat_SetGrade_toolow" RESET << std::endl;
	return (EXIT_SUCCESS);
}

//test need to be done with value = 1
//needs to output toohigh msg.
int	test_bureucrat_grade_increment(void)
{
	std::cout << BG_GREEN "test_bureucrat_grade_increment" RESET << std::endl;
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
		return (err_invalid_test("test_bureucrat_grade_increment" , __LINE__));
	}
	std::cout << BG_GREEN "END test_bureucrat_grade_increment" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_bureucrat_grade_increment2(void)
{
	std::cout << BG_ORANGE "test_bureucrat_grade_increment2" RESET << std::endl;
	Bureaucrat a;

	a++;
	if (a.getGrade() != 149)
		return (err_invalid_test("test_bureucrat_grade_increment2" , __LINE__));
	std::cout << BG_ORANGE "test_bureucrat_grade_increment2" RESET << std::endl;
	return (EXIT_SUCCESS);
}

//tests need to be done with value = 150
//needs to output toolow msg
int	test_bureucrat_grade_decrement(void)
{
	std::cout << BG_BLUE "test_bureucrat_grade_decrement" RESET << std::endl;
	try
	{
		Bureaucrat b(150);
		b --;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		return (err_invalid_test("test_bureucrat_grade_decrement" , __LINE__));
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << BG_BLUE "END test_bureucrat_grade_decrement" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_bureucrat_grade_decrement2(void)
{
	std::cout << BG_GREEN "test_bureucrat_grade_decrement2" RESET << std::endl;
	Bureaucrat a(10);

	a--;
	if (a.getGrade() != 11)
		return (err_invalid_test("test_bureucrat_grade_increment2" , __LINE__));
	std::cout << BG_GREEN "test_bureucrat_grade_decrement2" RESET << std::endl;
	return (EXIT_SUCCESS);
}

//needs to init the object with 150
int	test_bureucrat_default_constructor(void)
{
	std::cout << BG_ORANGE "test_bureucrat_default_constructor" RESET << std::endl;
	Bureaucrat a;
	if (a.getGrade() != 150)
		return (err_invalid_test("test_bureucrat_default_constructor" , __LINE__));
	std::cout << BG_ORANGE "END test_bureucrat_default_constructor" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_bureucrat_int_constructor(void)
{
	std::cout << BG_MAGENTA "test_bureucrat_int_constructor" RESET << std::endl;
	Bureaucrat a(120);

	if (a.getGrade() != 120)
		return (err_invalid_test("test_bureucrat_int_constructor" , __LINE__));
	
	std::cout << BG_MAGENTA "END test_bureucrat_int_constructor" RESET << std::endl;
	return (EXIT_SUCCESS);
}

//must throw toohight error msg
int	test_bureucrat_int_constructor_toohigh(void)
{
	std::cout << BG_GREEN "test_bureucrat_int_constructor_toohigh" RESET << std::endl;
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
		return (err_invalid_test("test_bureucrat_int_constructor_toohigh" , __LINE__));
	}
	std::cout << BG_GREEN "END test_bureucrat_int_constructor_toohigh" RESET << std::endl;
	return (EXIT_SUCCESS);
}

//must throw toolow error msg
int	test_bureucrat_int_constructor_toolow(void)
{
	std::cout << BG_BLUE "test_bureucrat_int_constructor_toolow" RESET << std::endl;
	try 
	{
		Bureaucrat error(151);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		return (err_invalid_test("test_bureucrat_int_constructor_toolow" , __LINE__));
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << BG_BLUE "END test_bureucrat_int_constructor_toolow" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int test_bureucrat_copy_constructor(void)
{
	std::cout << BG_ORANGE "test_bureucrat_copy_constructor" RESET << std::endl;
	Bureaucrat a("A");
	Bureaucrat b(a);

	if (b.getGrade() != a.getGrade() || b.getName() != a.getName())
		return (err_invalid_test("test_bureucrat_copy_constructor" , __LINE__));
	std::cout << BG_ORANGE "test_bureucrat_copy_constructor" RESET << std::endl;
	return (EXIT_SUCCESS);	
}

//copy assignment operator
int	test_bureucrat_copy_assignment_operator(void)
{
	std::cout << BG_MAGENTA "test_bureucrat_copy_assignment_operator" RESET << std::endl;
	Bureaucrat a(150);
	Bureaucrat b("B");

	b = a;
	if (a.getGrade() != b.getGrade())
		return (err_invalid_test("test_bureucrat_copy_constructor" , __LINE__));
	std::cout << BG_MAGENTA "test_bureucrat_copy_assignment_operator" RESET << std::endl;
	return (EXIT_SUCCESS);
}

//Should not print any error msg
int	test_bureucrat_signForm_possible(void)
{
	Form f("formulario", 140, 142);
	Bureaucrat b("Burocrata");

	b.setGrade(42);
	std::cout << BG_ORANGE "test_bureucrat_signForm_possible" RESET << std::endl;
	try {
		b.signForm(f);
	}
	catch (std::exception& e)
	{
		return (err_invalid_test("test_bureucrat_signForm_possible", __LINE__));
	}
	std::cout << BG_ORANGE " END test_bureucrat_signForm_possible" RESET << std::endl;
	return (EXIT_SUCCESS);
}

//Should print personalized msg of Bureaucrat::signForm()
int	test_bureucrat_signForm_not_possible(void)
{
	Form f("formulario", 1, 142);
	Bureaucrat b("Burocrata");

	std::cout << BG_BLUE "test_bureucrat_signForm_not_possible" RESET << std::endl;
	try {
		b.signForm(f);
	}
	catch (std::exception& e)
	{
		return (err_invalid_test("test_bureucrat_signForm_not_possible", __LINE__));
	}
	std::cout << BG_BLUE " END test_bureucrat_signForm_not_possible" RESET << std::endl;
	return (EXIT_SUCCESS);
}

/****************************************************************/
/*                       FORM       TESTS!                      */
/****************************************************************/

//Test if the default constructor is ok
int	test_form_default_constructor(void)
{
	std::cout << BG_BLUE "test_form_default_constructor" RESET<< std::endl;
	Form a;
	
	if (a.getIsSigned() || a.getGradeExec() != 1 || a.getGradeSign() != 1)
		return (err_invalid_test("test_form_default_constructor", __LINE__));
	std::cout << BG_BLUE "END test_form_default_constructor" RESET << std::endl;
	return (EXIT_SUCCESS);
}

//test if the copy constructor is ok
int	test_form_copy_constructor(void)
{
	std::cout << BG_GREEN "test_form_copy_constructor" RESET<< std::endl;
	Form a("A", 13, 42);
	Form b(a);

	if (a.getGradeExec() != b.getGradeExec() || a.getGradeSign() != b.getGradeSign()
		|| a.getIsSigned() != b.getIsSigned())
		return (err_invalid_test("test_form_copy_constructor", __LINE__));
	std::cout << BG_GREEN "END test_form_copy_constructor" RESET<< std::endl;
	return (EXIT_SUCCESS);
}

//test if the copy assingment operator is ok
//This just tests for _is_signed operator. All the others are constants.
int	test_form_copy_assignment_operator(void)
{
	std::cout << BG_MAGENTA "test_form_copy_assignment_operator" RESET<< std::endl;
	Form a("A", 13, 42);
	Form b("B", 42, 23);

	if (a.getIsSigned() != b.getIsSigned())
		return (err_invalid_test("test_form_copy_assignment_operator", __LINE__));
	std::cout << BG_MAGENTA "END test_form_copy_assignment_operator" RESET<< std::endl;
	return (EXIT_SUCCESS);
}

//Needs to print msg of toohigh for form constructor
int	test_form_constructor_toohigh(void)
{
	std::cout << BG_ORANGE "test_form_constructor_toohigh" RESET<< std::endl;
	try {
		Form a("A", 0, 10);
		Form b("B", 10, 0);
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
		return (err_invalid_test("test_form_constructor_toohigh", __LINE__));
	}
	std::cout << BG_ORANGE "END test_form_constructor_toohigh" RESET<< std::endl;
	return (EXIT_SUCCESS);
}

//Needs to print msg of toolow for form constructor
int	test_form_constructor_toolow(void)
{
	std::cout << BG_BLUE "test_form_constructor_toolow" RESET<< std::endl;
	try {
		Form a("A", 10, 151);
		Form b("B", 151, 10);
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		return (err_invalid_test("test_form_constructor_toolow", __LINE__));
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << BG_BLUE "END test_form_constructor_toolow" RESET<< std::endl;
	return (EXIT_SUCCESS);
}

//Needs to sucessfully change the isSigned var
int	test_form_beSigned_posible(void)
{
	std::cout << BG_GREEN "test_form_beSigned_posible" RESET<< std::endl;
	Bureaucrat b(10);
	Form f("formulario", 12, 13);
	
	f.beSigned(b);
	std::cout << "After beSigned() : " << f.getIsSigned() << std::endl;
	if (f.getIsSigned() == 0)
		return (err_invalid_test("test_form_beSigned_posible", __LINE__)); 
	std::cout << BG_GREEN "END test_form_beSigned_posible" RESET<< std::endl;
	return (EXIT_SUCCESS);
}

//Needs to output form TooLow msg
int test_form_beSigned_not_possible(void)
{
	std::cout << BG_MAGENTA "test_form_beSigned_not_possible" RESET<< std::endl;
	try {
		Bureaucrat b(10);
		Form f("formulario", 1, 13);
		f.beSigned(b);
		std::cout << "After beSigned() : " << f.getIsSigned() << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		return (err_invalid_test("test_form_beSigned_not_possible", __LINE__)); 
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << BG_MAGENTA "END test_form_beSigned_not_possible" RESET<< std::endl;
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