/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:19:19 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/14 22:26:11 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/**************************************/
/*              ORTHODOX              */
/**************************************/

Form::Form() : 	_name("default"), 
				_is_signed(false), 
				_grade_sign(1), 
				_grade_exec(1)
{
	//std::cout << "Form Default Constructor" << std::endl;.
}

Form::Form(const Form &src) : 	_name(src._name), 
								_is_signed(src._is_signed), 
								_grade_sign(src._grade_sign), 
								_grade_exec(src._grade_exec)
{
	//std::cout << "Form Copy Constructor" << std::endl;
}

Form&	Form::operator=(const Form &src)
{
	std::cout << "Form Assignment Operator" << std::endl;
	if (this != &src)
	{
		this->_is_signed = src._is_signed;
	}
	return (*this);
}

Form::~Form()
{
	//std::cout << "Form Destructor" << std::endl;	
};

/**************************************/
/*         OTHER CONSTRUCTORS         */
/**************************************/

Form::Form(std::string name, int grade_sign, int grade_exec) : 	_name(name),
																_is_signed(false),
																_grade_sign(grade_sign),
																_grade_exec(grade_exec)
{
	//std::cout << "Form Values Constructor" << std::endl;
	if (this->_grade_sign > 150 || this->_grade_exec > 150)
		throw GradeTooLowException();
	if (this->_grade_sign <= 0 || this->_grade_exec <= 0)
		throw GradeTooHighException();
}

/**************************************/
/*              Getters               */
/**************************************/

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool		Form::getIsSigned(void) const
{
	return (this->_is_signed);
}

int			Form::getGradeSign(void) const
{
	return (this->_grade_sign);
}

int			Form::getGradeExec(void) const
{
	return (this->_grade_exec);	
}

/**************************************/
/*      RECQUIRED BY THE SUBJECT      */
/**************************************/
void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeSign())
		this->_is_signed = true;
	if (b.getGrade() > this->getGradeSign())
		throw GradeTooLowException();		
}

/**************************************/
/*              EXCEPTIONS            */
/**************************************/

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form : Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form : Grade too low!";
}

/**************************************/
/*    overload of the insertion («)   */
/**************************************/
std::ostream& operator<<(std::ostream& os, const Form &obj)
{
	std::string is_signed;

	obj.getIsSigned() ? is_signed = "yes" : is_signed = "no";

	os 
	<< "\n"
	<< "Form Name : " << obj.getName() << "\n"
	<< "Form is signed? : " << is_signed << "\n"
	<< "Form grade to sign : " << obj.getGradeSign() << "\n"
	<< "Form grade to exec : " << obj.getGradeExec() << std::endl;  
	return (os);	
}