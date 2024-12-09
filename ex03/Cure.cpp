/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:47:05 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/09 15:00:34 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*************************************/
/*               ORTHODOX            */
/*************************************/

Cure::Cure() : AMateria()
{
	//std::cout << "Cure Default Constructor" << std::endl;
	this->p_type = "cure";
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	//std::cout << "Cure Copy Constructor" << std::endl;
}

Cure& Cure::operator=(const Cure &src)
{
	//std::cout << "Cure assignment operator" << std::endl;
	if (this != &src)
	{
		//only const att
	}
	return (*this);
}

Cure::~Cure()
{
	//std::cout << "Cure Destructor" << std::endl;	
}

/*************************************/
/*             CONSTRUCTOR           */
/*************************************/
Cure::Cure(std::string type) : AMateria(type + "_abs")
{
	//std::cout << "string constructor" << std::endl;
	this->p_type = type;
}

/*************************************/
/*               MEMBER FUNC         */
/*************************************/

Cure* Cure::clone() const
{
	Cure	*newCure = new Cure;
	return (newCure);
}

void Cure::use(ICharacter& target)
{
	std::cout
	<< "Cure: '* heals " << target.getName() << "'s wounds *'"
	<< std::endl;
};

/*************************************/
/*             Inherit FUNC          */
/*************************************/

std::string const & Cure::getType() const
{
	return (this->p_type);
}

