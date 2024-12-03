/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:10:14 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/03 16:53:58 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/**************************************************/
/*                Orthodox Canonical              */
/**************************************************/
Dog::Dog() : Animal()
{
	std::cout << "Dog Constructor" << std::endl;
	this->p_type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog Copy Constructor" << std::endl;
	this->p_type = src.p_type;
}

Dog&	Dog::operator=(const Dog &src)
{
	std::cout << "Dog Assign Operator" << std::endl;
	if (this != &src)
	{
		this->p_type = src.p_type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << std::endl;
}


//Member function to makeSound
void	Dog::makeSound() const
{
	std::cout << "AUUUUU AUUUUU" << std::endl;
}

//To Debug
void	Dog::printDogType()
{
	std::cout << this->p_type << std::endl;
}