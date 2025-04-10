/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:53:57 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/03 16:53:14 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/**************************************************/
/*                Orthodox Canonical              */
/**************************************************/

Animal::Animal() : p_type("Animal")
{
	std::cout << "Animal Constructor" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal Copy Constructor" << std::endl;

	this->p_type = src.p_type;
}

Animal& Animal::operator=(const  Animal &src)
{
	std::cout << "Animal Assign Operator" << std::endl;
	if (this != &src)
	{
		this->p_type = src.p_type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor" << std::endl;
}

//Member functions
void	Animal::makeSound() const
{
	std::cout << "Silence" << std::endl;
}


/**************************************************/
/*          TO DEBUG NOT ASKED ON SUBJECT         */
/**************************************************/
void	Animal::printAnimalType()
{
	std::cout << this->p_type << std::endl;	
};

/**************************************************/
/*          ASKED INDIRECTLY ON SUBJECT           */
/**************************************************/
std::string	Animal::getType() const
{
	return(this->p_type);
}