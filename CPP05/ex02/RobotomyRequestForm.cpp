/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:17:14 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/15 19:57:15 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*******************************************/
/*                 ORTHODOX                */
/*******************************************/
RobotomyRequestForm::RobotomyRequestForm()
: 	AForm("RobotomyRequestForm", RB_SIGN, RB_EXEC),
	_target("")
{
	//std::cout << "RobotomyRequestForm Default Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
: 	AForm(src),
	_target(src._target)
{
	//std::cout << "RobotomyRequestForm Copy Constructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	//std::cout << "RobotomyRequestForm Assignment Operator" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << "RobotomyRequestForm Destructor" << std::endl;
}


/*******************************************/
/*            OTHER CONSTRUCTORS           */
/*******************************************/

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: 	AForm("RobotomyRequestForm", RB_SIGN, RB_EXEC),
	_target(target)
{
	//std::cout << "RobotomyRequestForm target Constructor" << std::endl;
}

/*******************************************/
/*                GETTERS                  */
/*******************************************/

std::string RobotomyRequestForm::getTarget(void)
{
	return (this->_target);
}

/*******************************************/
/*         REQUIRED BY THE SUBJECT         */
/*******************************************/

int	RobotomyRequestForm::formAction(void) const
{
	static int n = 1;

	std::cout << "Driill-Drill-Drill" << std::endl;
	if (n % 2 == 0)
	{
		std::cout << this->_target 
			<< " has being robotomized sucesfully! Bzzz..." 
		<< std::endl;
		n ++;
		return (0);
	}
	std::cout << "Can't robotomy " << this->_target << std::endl;
	n ++;
	return (1);
}
