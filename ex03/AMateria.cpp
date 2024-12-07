/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:59:47 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/07 19:29:53 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*****************************************/
/*                 ORTHODOX              */
/*****************************************/
AMateria::AMateria() : p_type("default")
{
	std::cout << "AMateria Default Constructor" << std::endl;
}

AMateria::AMateria(const AMateria &src) : p_type(src.p_type)
{
	std::cout << "AMateria Copy Constructor" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &src)
{
	std::cout << "AMateria Assignment Operator" << std::endl;
	if (this != &src)
	{
		//copy
		std::cout << "AMateria Copy Constructor" << std::endl;
		//constant value is the same for both, no need to copy
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor" << std::endl;
}
/*****************************************/
/*                CONSTRUCTOR            */
/*****************************************/

AMateria::AMateria(std::string const & type) : p_type(type)
{
	std::cout << "AMateria String Constructor" << std::endl;
}

/*****************************************/
/*                 GETTER                */
/*****************************************/

//return the materia type
std::string const&  AMateria::getType() const
{
	return (this->p_type);
}

/*****************************************/
/*                Member Functio         */
/*****************************************/
void AMateria::use(ICharacter& target)
{
	(void)target;
}
