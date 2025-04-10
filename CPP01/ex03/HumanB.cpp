/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:03:11 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/05 15:43:02 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/**
 * @attention New Concept : Initilizer List
 * A Initializer List (lista de inicialização) em um construtor é uma 
 * parte da sintaxe que permite inicializar membros de uma classe antes
 * da execução do corpo do construtor. A lista de inicialização é 
 * especificada logo após o cabeçalho do construtor e é 
 * precedida por dois pontos (:).
 * Quando usar?
 * Quando houver membros const
 * Quando houver referencias
 * Objectos com construtores nao triviais, ou seja, quando um membro que eh uma
 * classe tem um construtor que exige parametros
 * Lista de initializacao evita copias
 */
HumanB::HumanB(std::string str) : name(str), weapon(NULL)
{
    std::cout << BG_BLUE "HumanB Constructor" RESET << std::endl;
}

HumanB::~HumanB()
{
    std::cout << BG_RED "HumanB Destructor" RESET << std::endl;
}

std::string HumanB::getName()
{
    return (this->name);
}

void    HumanB::setWeapon(Weapon &obj)
{
    this->weapon = &obj;
}

void    HumanB::attack()
{
    std::string name = getName();
    if (weapon == NULL)
    {
        std::cout << name << " attacks with their hands" << std::endl;
        return ;
    }
    std::cout << name << " attacks with their "
    << weapon->getType() << std::endl;
}