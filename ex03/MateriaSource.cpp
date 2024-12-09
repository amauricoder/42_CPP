/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:10:58 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/09 15:14:25 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	//std::cout << "Materia Source Constructor" << std::endl;	
	for (int i = 0; i < 4; i++)
	{
		this->_backup[i] = NULL;
	}
}
MateriaSource::MateriaSource(MateriaSource const &src)
{
	//std::cout << "Materia Source Copy Constructor" << std::endl;	
	for (int i = 0; i < 4; i ++)
		this->_backup[i] = src._backup[i];
}
MateriaSource& MateriaSource::operator=(const MateriaSource &src)
{
	//std::cout << "Materia Source Assignment operator" << std::endl;	
	if (this != &src)
	{
		for (int i = 0; i < 4; i ++)
			this->_backup[i] = src._backup[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	//std::cout << "Materia Source Destructor" << std::endl;
	for (int i = 0; i < 4; i ++)
	{
		if (this->_backup[i])
		{
			delete this->_backup[i];
			this->_backup[i] = NULL;
		}
	}
}
void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << "Cannot Learn NULL Materia" << std::endl;
		return ;
	}

	int i = 0;
	while(this->_backup[i])
		i++;
	if (i == 4)
		std::cout << "Cannot Lean Materia! Materia Source is full!" << std::endl;
	else
	{
		std::cout << "New Materia " << m->getType() << " learned!" << std::endl;
		this->_backup[i] = m;	
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{

	for (int i = 3; i >= 0; i--)
    {
        if (this->_backup[i] && this->_backup[i]->getType() == type)
        {
            std::cout << "Creating " << type << " materia" << std::endl;
            return (this->_backup[i]->clone());
        }
    }
	std::cout << "Type is unknow! No materia created" << std::endl;
	return (0);
}



/**************************/
/*            DEGUB       */
/**************************/
void	MateriaSource::printMateria(int index)
{
	if (index < 0 || index > 3 || !this->_backup[index])
		return ;
	std::cout << this->_backup[index]->getType() << std::endl;
}

		