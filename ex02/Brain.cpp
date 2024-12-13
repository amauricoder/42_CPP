/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:35:32 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/12 14:04:51 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#define BG_RED      "\033[41m"
#define RESET       "\033[0m"

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
		this->_ideas[i] = "Idea added -> " + nbr;
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
        //std::cout << BG_RED "Before delete: this->_ideas address: " RESET << this->_ideas << std::endl;
        delete[] this->_ideas;
        this->_ideas = new std::string[100];
        //std::cout << BG_RED "After new allocation: this->_ideas address: " RESET << this->_ideas << std::endl;
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
		std::cout << this->_ideas[i] << " address : "<< &this->_ideas[i] << std::endl;
}

std::string* Brain::getIdeasAddress()
{
    return this->_ideas;
}

/***************************************/
/*                Getter               */
/***************************************/
std::string	Brain::getIdea(int	index)
{
	return (this->_ideas[index]);
}

/***************************************/
/*                Setter               */
/***************************************/
void		Brain::setIdea(std::string new_idea, int index)
{
	if (index > 99 || index < 0)
		return ;
	this->_ideas[index] = new_idea;
};
