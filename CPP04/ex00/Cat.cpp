/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:10:52 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/03 16:54:03 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/**************************************************/
/*                Orthodox Canonical              */
/**************************************************/
Cat::Cat() : Animal()
{
	std::cout << "Cat Constructor" << std::endl;
	this->p_type = "Cat";
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat Copy Constructor" << std::endl;
	this->p_type = src.p_type;
}

Cat&	Cat::operator=(const Cat &src)
{
	std::cout << "Cat Assign Operator" << std::endl;
	if (this != &src)
	{
		this->p_type = src.p_type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
}

//Member function to makeSound
void	Cat::makeSound() const
{
	std::cout << "MINHAAAAAAAAAAAAAAU" << std::endl;
}

//To Debug
void	Cat::printCatType()
{
	std::cout << this->p_type << std::endl;
}