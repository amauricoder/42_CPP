/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:06:37 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/30 16:51:50 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name("Anonimous Diamond Trap")
{
    std::cout << "Diamond Trap Constructor" << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : 
                                             ClapTrap(name + "_clap_name"),
                                            _name(name)
{
    std::cout << "DiamondTrap String Constructor" << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : 
    ClapTrap(src._name + "_clap_name"),
    ScavTrap(src),
    FlagTrap(src)
{
    this->_name = src._name;
    this->_hit_points = src._hit_points;
    this->_energy_points = src._energy_points;
    this->_attack_damage = src._attack_damage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src)
{
    if (this != &src)
    {
        this->_name = src._name;
        this->_hit_points = src._hit_points;
        this->_energy_points = src._energy_points;
        this->_attack_damage = src._attack_damage;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Diamond Trap Destructor" << std::endl;
}

void    DiamondTrap::whoAmI()
{
    std::cout 
    << "Who Am I??? : "<< this->_name << " and ";
    ClapTrap::printName(); 
}
