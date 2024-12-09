/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:59:47 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/09 15:02:34 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*****************************************/
/*                 ORTHODOX              */
/*****************************************/
AMateria::AMateria() : p_type("none"), is_equiped(0)
{
	//std::cout << "AMateria Default Constructor" << std::endl;
}

AMateria::AMateria(const AMateria &src) : p_type(src.p_type), is_equiped(0)
{
	//std::cout << "AMateria Copy Constructor" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &src)
{
	std::cout << "AMateria Assignment Operator" << std::endl;
	if (this != &src)
	{
		//copy
		//std::cout << "AMateria Copy Constructor" << std::endl;
		//constant value is the same for both, no need to copy
		this->is_equiped = this->getIsEquiped();
	}
	return (*this);
}

AMateria::~AMateria()
{
	//std::cout << "AMateria Destructor" << std::endl;
}
/*****************************************/
/*                CONSTRUCTOR            */
/*****************************************/

AMateria::AMateria(std::string const & type) : p_type(type), is_equiped(0)
{
	//std::cout << "AMateria String Constructor" << std::endl;
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
/*            SETTER AND GETTER          */
/*****************************************/

void	AMateria::setIsEquiped(bool is)
{
	this->is_equiped = is;
}

bool	AMateria::getIsEquiped(void)
{
	return (this->is_equiped);
}

/*****************************************/
/*                Member Function        */
/*****************************************/
void AMateria::use(ICharacter& target)
{
	(void)target;
}
