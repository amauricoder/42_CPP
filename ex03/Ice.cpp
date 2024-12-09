/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:45:59 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/09 11:52:26 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*************************************/
/*               ORTHODOX            */
/*************************************/

Ice::Ice() : AMateria()
{
	//std::cout << "Ice Default Constructor" << std::endl;
	this->p_type = "ice";
}

Ice::Ice(const Ice &src) : AMateria(src)
{
	//std::cout << "Ice Copy Constructor" << std::endl;
}

Ice& Ice::operator=(const Ice &src)
{
	//std::cout << "Ice assignment operator" << std::endl;
	if (this != &src)
	{
		//no need to copy the type
	}
	return (*this);
}

Ice::~Ice()
{
	//std::cout << "Ice Destructor" << std::endl;	
}
/*************************************/
/*             CONSTRUCTOR           */
/*************************************/
Ice::Ice(std::string type) : AMateria(type + "_abs")
{
	//std::cout << "Ice string constructor" << std::endl;
	this->p_type = type;
}

/*************************************/
/*             MEMBER FUNC           */
/*************************************/
Ice* Ice::clone() const
{
	Ice *newIce = new Ice("ice");
	return (newIce);
}

void Ice::use(ICharacter& target)
{
	std::cout
	<< "Ice: '* shoots and ice bolt at "
	<< target.getName() << " *'"
	<< std::endl;
}

/*************************************/
/*             Inherit FUNC          */
/*************************************/

std::string const & Ice::getType() const
{
	return (this->p_type);
}
