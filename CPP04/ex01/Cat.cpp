/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:10:52 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/12 12:33:36 by aconceic         ###   ########.fr       */
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
	this->_idea = new Brain;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat Copy Constructor" << std::endl;
	this->p_type = src.p_type;
    this->_idea = new Brain(*src._idea);
}

Cat&	Cat::operator=(const Cat &src)
{
	std::cout << "Cat Assign Operator" << std::endl;
	if (this != &src)
	{
		this->p_type = src.p_type;
        if (this->_idea)
		{
            delete this->_idea; // Delete the existing Brain
        }
        this->_idea = new Brain(*src._idea); 
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
	delete this->_idea;
}

/**************************************************/
/*                Member function                 */
/**************************************************/
void	Cat::makeSound() const
{
	std::cout << "MINHAAAAAAAAAAAAAAU" << std::endl;
}

/**************************************************/
/*                DEBUG FUNCTIONS	              */
/**************************************************/
void	Cat::printCatType()
{
	std::cout << this->p_type << std::endl;
}

void	Cat::printCatIdeas()
{
	for (int i = 0; i < 100; i ++)
		std::cout << "\033[48;5;202mCat idea\033[0m " << this->_idea->getIdea(i) << std::endl;
}