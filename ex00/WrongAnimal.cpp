/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:09:45 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/10 18:28:08 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/**************************************************/
/*                Orthodox Canonical              */
/**************************************************/

WrongAnimal::WrongAnimal() : p_type("WrongAnimal")
{
	std::cout << "WrongAnimal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "WrongAnimal Copy Constructor" << std::endl;

	this->p_type = src.p_type;
}

WrongAnimal& WrongAnimal::operator=(const  WrongAnimal &src)
{
	std::cout << "WrongAnimal Assign Operator" << std::endl;
	if (this != &src)
	{
		this->p_type = src.p_type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor" << std::endl;
}

//Member functions
void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong Silence" << std::endl;
}

/**************************************************/
/*          ASKED INDIRECTLY ON SUBJECT           */
/**************************************************/
std::string	WrongAnimal::getType() const
{
	return(this->p_type);
}