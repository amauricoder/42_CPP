/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:38:27 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/15 19:57:13 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/************************************************/
/*               ORTHODOX CANONICAL             */
/************************************************/

ShrubberyCreationForm::ShrubberyCreationForm()
: 	AForm("ShrubberyCreationForm", SH_SIGN, SH_EXEC),
	_target("")
{
	//std::cout << "ShrubberyCreationForm Default Constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
:	AForm::AForm(src),
	_target(src._target)
{
	//std::cout << "ShrubberyCreationForm Copy Constructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	//std::cout << "ShrubberyCreationForm Assign Operator" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//std::cout << "ShrubberyCreationForm Destructor" << std::endl;
}

/************************************************/
/*               OTHER CONSTRUCTORS             */
/************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
:	AForm("ShrubberyCreationForm", SH_SIGN, SH_EXEC),
	_target(target)
{
	//std::cout << "ShrubberyCreationForm target constructor" << std::endl;
}

/************************************************/
/*                    GETTERS                   */
/************************************************/

std::string	ShrubberyCreationForm::getTarget()
{
	return (this->_target);
}

/************************************************/
/*            REQUIRED BY THE SUBJECT           */
/************************************************/
int	ShrubberyCreationForm::formAction() const
{
	std::string file_name = this->_target + "_shrubbery";
	const char *file_name_ptr = file_name.c_str();
	std::string tree = 
						"           333           \n"
						"          33333          \n"
						"         3333333         \n"
						"        333333333        \n"
						"       33333333333       \n"
						"      3333333333333      \n"
						"     333333333333333     \n"
						"    33333333333333333    \n"
						"   3333333333333333333   \n"
						"  333333333333333333333  \n"
						"          33333          \n"
						"          33333          \n"
						"          33333          \n"
						"          33333          \n"
						"          33333          ";

	std::ofstream file;
	file.open(file_name_ptr);
	if (file.is_open())
	{
		file << tree << std::endl;
		file.close();
		return (0);
	}
	std::cerr << "Error with file creation" << std::endl;
	return (1);
}