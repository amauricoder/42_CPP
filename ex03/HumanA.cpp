/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:49:57 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/05 15:42:58 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

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
HumanA::HumanA(std::string input, Weapon &type) : name(input), weapon(type)
{
	std::cout << BG_BLUE "HumanA Constructor" RESET<< std::endl;
	return ;
}

HumanA::~HumanA()
{
	std::cout << BG_RED "HumanA Destructor" RESET << std::endl; 
}

std::string HumanA::getHumanName()
{
	return (this->name);
}


void    HumanA::attack()
{
	std::string name = getHumanName();
	
	std::cout << name << " attacks with their "
	<< weapon.getType() << std::endl;
}