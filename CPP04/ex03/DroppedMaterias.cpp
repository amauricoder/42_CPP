/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DroppedMaterias.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:28:11 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/13 15:02:42 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DroppedMaterias.hpp"

/**************************************/
/*               ORTHODOX             */
/**************************************/

DroppedMateria::DroppedMateria() : _count(0)
{
	for (int i = 0; i < MAX_DROPPED; i ++)
		this->_dropped[i] = NULL;
}

DroppedMateria::DroppedMateria(const DroppedMateria &src)
{
	int i = 0;

	this->_count = src._count;
	while (this->_dropped[i])
	{
		delete this->_dropped[i];
		this->_dropped[i] = NULL;
		i ++;
	}
	i = 0;
	while (src._dropped[i])
	{
		this->_dropped[i] = src.getDropped(i)->clone();
		i ++;
	}
}

DroppedMateria& DroppedMateria::operator=(const DroppedMateria &src)
{
	int i = 0;

	if (this != &src)
	{
		this->_count = src._count;
		while (this->_dropped[i])
		{
			delete this->_dropped[i];
			this->_dropped[i] = NULL;
			i ++;
		}
		i = 0;
		while (src._dropped[i])
		{
			this->_dropped[i] = src.getDropped(i)->clone();
			i ++;
		}
	}
	return (*this);
}

DroppedMateria::~DroppedMateria()
{}


/**************************************/
/*               METHODS             */
/**************************************/
AMateria* DroppedMateria::getDropped(int idx) const
{
	return (this->_dropped[idx]);
}

DroppedMateria&	DroppedMateria::getInstance()
{
	static DroppedMateria instance;
	return (instance);
}

void	DroppedMateria::addDropped(AMateria *materia)
{
	if (_count < MAX_DROPPED)
	{
		_dropped[_count ++] = materia;
	}
	else
	{
		std::cout << "You can't drop more materias" << std::endl;
	}
}