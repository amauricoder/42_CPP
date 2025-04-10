/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:19:19 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/15 20:12:30 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/**************************************/
/*              ORTHODOX              */
/**************************************/

AForm::AForm() : 	_name("default"), 
				_is_signed(false), 
				_grade_sign(1), 
				_grade_exec(1)
{
	//std::cout << "AForm Default Constructor" << std::endl;.
}

AForm::AForm(const AForm &src) : 	_name(src._name), 
								_is_signed(src._is_signed), 
								_grade_sign(src._grade_sign), 
								_grade_exec(src._grade_exec)
{
	//std::cout << "AForm Copy Constructor" << std::endl;
}

AForm&	AForm::operator=(const AForm &src)
{
	std::cout << "AForm Assignment Operator" << std::endl;
	if (this != &src)
	{
		this->_is_signed = src._is_signed;
	}
	return (*this);
}

AForm::~AForm()
{
	//std::cout << "AForm Destructor" << std::endl;	
};

/**************************************/
/*         OTHER CONSTRUCTORS         */
/**************************************/

AForm::AForm(std::string name, int grade_sign, int grade_exec) : 	_name(name),
																_is_signed(false),
																_grade_sign(grade_sign),
																_grade_exec(grade_exec)
{
	//std::cout << "AForm Values Constructor" << std::endl;
	if (this->_grade_sign > 150 || this->_grade_exec > 150)
		throw GradeTooLowException();
	if (this->_grade_sign <= 0 || this->_grade_exec <= 0)
		throw GradeTooHighException();
}

/**************************************/
/*              Getters               */
/**************************************/

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool		AForm::getIsSigned(void) const
{
	return (this->_is_signed);
}

int			AForm::getGradeSign(void) const
{
	return (this->_grade_sign);
}

int			AForm::getGradeExec(void) const
{
	return (this->_grade_exec);	
}

/**************************************/
/*      RECQUIRED BY THE SUBJECT      */
/**************************************/
void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeSign())
		this->_is_signed = true;
	if (b.getGrade() > this->getGradeSign())
		throw GradeTooLowException();		
}

void		AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_is_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_grade_exec)
		throw NotEnoughGradeToExecException();
	this->formAction();
	std::cout << this->_name << " was executed by " << executor.getName() << std::endl;
}

/**************************************/
/*              EXCEPTIONS            */
/**************************************/

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm : Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm : Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm : Form not signed";
}

const char* AForm::NotEnoughGradeToExecException::what() const throw()
{
	return "Bureaucrat doesnt have enough grade to exec form";
}

/**************************************/
/*    overload of the insertion («)   */
/**************************************/
std::ostream& operator<<(std::ostream& os, const AForm &obj)
{
	std::string is_signed;

	obj.getIsSigned() ? is_signed = "yes" : is_signed = "no";

	os 
	<< "\n"
	<< "AForm Name : " << obj.getName() << "\n"
	<< "AForm is signed? : " << is_signed << "\n"
	<< "AForm grade to sign : " << obj.getGradeSign() << "\n"
	<< "AForm grade to exec : " << obj.getGradeExec() << std::endl;  
	return (os);	
}