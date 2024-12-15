/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:25:00 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/15 22:29:52 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/************************************/
/*            ORTHODOX              */
/************************************/

Intern::Intern()
{
	//std::cout << "Intern Default Constructor " << std::endl;
}

Intern::Intern(const Intern &src)
{
	//std::cout << "Intern Copy Constructor " << std::endl;
	*this = src;
}

Intern& Intern::operator=(const Intern &src)
{
	//std::cout << "Intern Assign Operator " << std::endl;
	(void)src;
	return (*this);
}

Intern::~Intern()
{
	//std::cout << "Intern Destructor " << std::endl;
}

/************************************/
/*     Required by the subject      */
/************************************/

AForm* makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

/************************************/
/*             Exception            */
/************************************/
const char* Intern::FormNotCreated::what() const throw()
{
	return "Form not created. Inexistent form";
}


AForm*	Intern::makeForm(std::string requested_form, std::string target)
{
	int i = 0;
	AForm* (*ptr_func[3])(std::string target) = {&makeShrubbery, &makeRobotomy, &makePresidential};
	std::string available_forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	while (i < 3) 
	{ 
		if (requested_form == available_forms[i])
			return (ptr_func[i](target));
		i++;
	}
	throw FormNotCreated();
}
