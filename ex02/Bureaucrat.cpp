/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:29:22 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/15 19:50:10 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/**************************************/
/*              ORTHODOX              */
/**************************************/

Bureaucrat::Bureaucrat() : _name("default"), 
							_grade(150)
{
	//std::cout << "Bureaucrat Constructor" << std::endl;
	//exceptions
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : 
							_name(src._name),
							_grade(src._grade)
{
	//std::cout << "Bureaucrat Copy Constructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	//std::cout << "Bureaucrat Assign Operator" << std::endl;
	if (this != &src)
	{
		//const attributes dont change
		this->_grade = src.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << "Bureaucrat Destructor" << std::endl;
}

/**************************************/
/*         OTHER CONSTRUCTORS         */
/**************************************/
Bureaucrat::Bureaucrat(int grade) : _name("int"), 
									_grade(grade)
{
	//std::cout << "Bureaucrat INT Constructor" << std::endl;
	if (this->_grade <= 0)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name) :	_name(name), 
											_grade(150)
{
	//std::cout << "Bureaucrat STRING Constructor" << std::endl;										
}

/**************************************/
/*              GETTERS               */
/**************************************/

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

/**************************************/
/*              SETTERS               */
/**************************************/

void		Bureaucrat::setGrade(int grade)
{
	if (grade <= 0){
		throw GradeTooHighException();
	}
	if (grade > 150){
		throw GradeTooLowException();
	}
	this->_grade = grade;
}

/**************************************/
/*      MEMBER FUNCTIONS REQUIRED     */
/**************************************/
//Remember. Since grade 1 is the highest one and 150 the lowest,
//incrementing a grade 3 should give a grade 2 to the bureaucrat.
Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat temp = *this; // Save the current state
    this->_grade--;          // Increment grade

	if (this->_grade <= 0)
		throw GradeTooHighException();
    return temp; 
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat temp = *this; // Save the current state
    this->_grade++;          // Increment grade

	if (this->_grade > 150)
		throw GradeTooLowException();
    return temp; 
}

void			Bureaucrat::signForm(AForm &f)
{
	try
    {
        f.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << '\n';
		return ;
    }
	std::cout << this->_name << " signed " << f.getName() << std::endl;
};

int				Bureaucrat::executeForm(AForm const &form)
{
	try 
	{
		form.execute(*this);
	}
	catch (std::exception& e)
	{
		std::cerr << this->_name << " is not able to execute the form action" << std::endl;
		return (1);
	}
	std::cout << this->_name << " executed form " << form.getName() << std::endl;
	return (0);
}

/**************************************/
/*              EXCEPTIONS            */
/**************************************/

const char * Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

/**************************************/
/*    overload of the insertion («)   */
/**************************************/

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}

