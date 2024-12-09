/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:35:32 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/09 18:26:04 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/***************************************/
/*       ORTHODOX CANONICAL FORM       */
/***************************************/
Brain::Brain()
{
	std::cout << "Brain Constructor" << std::endl;
	this->_ideas = new std::string[100]; 
	for(int i = 0; i < 100; i ++)
	{
		std::ostringstream oss;
		oss << i;
		std::string nbr = oss.str();
		this->_ideas[i] = "Idea " + nbr + " added to the brain";
	}
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain Copy Constructor" << std::endl;
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
}

Brain& Brain::operator=(const Brain &src)
{
	std::cout << "Brain Assign Operator" << std::endl;	
    if (this != &src)
	{
		delete[] this->_ideas;
		this->_ideas = new std::string[100];
	    for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain	Destructor" << std::endl;
	delete [] (this->_ideas);	
}

/***************************************/
/*                DEBUG                */
/***************************************/

void	Brain::printIdeas()
{
	for (int i = 0; i < 100; i ++)
		std::cout << this->_ideas[i] << std::endl;
}

/***************************************/
/*                Getter               */
/***************************************/
std::string	Brain::getIdea(int	index)
{
	return (this->_ideas[index]);
}