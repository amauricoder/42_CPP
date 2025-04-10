/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:34:28 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/15 19:57:18 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/****************************************/
/*               ORTHODOX               */
/****************************************/

PresidentialPardonForm::PresidentialPardonForm()
:	AForm("PresidentialPardonForm", PR_SIGN, PR_EXEC),
	_target("")
{
	//std::cout << "PresidentialPardonForm Default Constructor" << std::endl;	
}

PresidentialPardonForm:: PresidentialPardonForm(const PresidentialPardonForm &src)
:	AForm(src),
	_target(src._target)
{
	//std::cout << "PresidentialPardonForm copy Constructor" << std::endl;	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	//std::cout << "PresidentialPardonForm assign operator" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "PresidentialPardonForm Destructor" << std::endl;		
}

/****************************************/
/*          OTHER CONSTRUCOTRS          */
/****************************************/

PresidentialPardonForm::PresidentialPardonForm(std::string target)
:	AForm("PresidentialPardonForm", PR_SIGN, PR_EXEC),
	_target(target)
{
	//std::cout << "PresidentialPardonForm Target Constructor" << std::endl;
}


/****************************************/
/*          Gettr CONSTRUCOTRS          */
/****************************************/
std::string PresidentialPardonForm::getTarget(void)
{
	return (this->_target);
}

/****************************************/
/*          REQUIRED BY THE SUBJECT     */
/****************************************/
int	PresidentialPardonForm::formAction(void) const
{
	std::cout << this->_target 
		<< " has received presidential pardon by Zaphod Beeblebrox"
	<< std::endl;
	return (0);
}
