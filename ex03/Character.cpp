/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:38:01 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/09 15:33:31 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/***********************************/
/*             ORTHODOX            */
/***********************************/
Character::Character()
{
	//std::cout << "Character constructor" << std::endl;
	this->_name = "default character";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &src) : _name(src._name)
{
	//std::cout << "Character copy constructor" << std::endl;
	this->_name = src._name;

	int i = 0;
	while (this->_inventory[i])
	{
		delete(this->_inventory[i]);
		this->_inventory[i] = NULL;
		i++;
	}

	for (int i = 0; i < 3; i ++)
	{
		if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character &src)
{
	//std::cout << "Character assignment operator" << std::endl;	
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i ++)
			this->_inventory[i] = NULL;
		
		int i = 0;
		while (this->_inventory[i])
		{
			delete(this->_inventory[i]);
			i++;
		}
	
		for (int i = 0; i < 3; i ++)
		{
			if (src._inventory[i])
					this->_inventory[i] = src._inventory[i]->clone();
				else
					this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	//std::cout << "Character destructor" << std::endl;	
	for (int i = 0; i < 4; i ++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

/***********************************/
/*         OTHER CONSTRUCTOR       */
/***********************************/

Character::Character(std::string name)
{
	//std::cout << "Character constructor" << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

/***********************************/
/*        		INHERIT            */
/***********************************/
std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	if (m->getIsEquiped())
	{
		std::cout << "Equipament already equiped" << std::endl;
		return ;
	}
	int i = 0;
	while (i < 4)
	{
		if (!this->_inventory[i])
			break;
		else
			i ++;
	}
	if (i == 4)
	{
		std::cout << "Full inventory" << std::endl;
		return ;
	}
	this->_inventory[i] = m;
	m->setIsEquiped(1);
	std::cout << "New materia equiped : " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
	{
		std::cout << "Invalid Materia to unequip" << std::endl;
		return ;
	}
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || this->_inventory[idx] == NULL)
	{
		std::cout << "Invalid Materia to use" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}

