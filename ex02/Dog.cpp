/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:10:14 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/07 14:55:07 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/**************************************************/
/*                Orthodox Canonical              */
/**************************************************/
Dog::Dog() : AAnimal()
{
	std::cout << "Dog Constructor" << std::endl;
	this->p_type = "Dog";
	this->_idea = new Brain;
}

Dog::Dog(const Dog &src) : AAnimal(src)
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
	delete this->_idea;
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

void	Dog::printDogIdeas()
{
	for (int i = 0; i < 100; i ++)
		std::cout << "\033[45mDog idea\033[0m " << this->_idea->getIdea(i) << std::endl;
}