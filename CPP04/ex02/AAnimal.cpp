/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:53:57 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/07 14:54:01 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/**************************************************/
/*                Orthodox Canonical              */
/**************************************************/

AAnimal::AAnimal() : p_type("AAnimal")
{
	std::cout << "AAnimal Constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "AAnimal Copy Constructor" << std::endl;

	this->p_type = src.p_type;
}

AAnimal& AAnimal::operator=(const  AAnimal &src)
{
	std::cout << "AAnimal Assign Operator" << std::endl;
	if (this != &src)
	{
		this->p_type = src.p_type;
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor" << std::endl;
}

//Member functions
/* void	AAnimal::makeSound() const
{
	std::cout << "Silence" << std::endl;
} */


/**************************************************/
/*          TO DEBUG NOT ASKED ON SUBJECT         */
/**************************************************/
void	AAnimal::printAnimalType()
{
	std::cout << this->p_type << std::endl;	
};

/**************************************************/
/*          ASKED INDIRECTLY ON SUBJECT           */
/**************************************************/
std::string	AAnimal::getType() const
{
	return(this->p_type);
}