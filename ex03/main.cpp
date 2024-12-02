/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:07:56 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/02 15:13:34 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define RESET       "\033[0m"

//Quando usamos heranca virtual, a classe derivada mais baixa (a classe
//que nao gherda de mais ninguem, como D) eh responsavel por
//inicializar a classe base.
//Usar virtual informa ao compilador que a classe base sera
//compartilhada entre todas as classes derivadas.
int main(void)
{
	{
		//test 1 - Diamond Trap default constructor
		//and whoAmI() member function, and values
		std::cout << BG_MAGENTA "1 Test" RESET << std::endl;
		DiamondTrap a("objeto");
		a.printHitPoints(); 
		a.printEnergyPoints();
		a.printAttackDamage();
		a.attack("objecto 2");
		a.whoAmI();
	}
	{
		//test 2 - Diamond Trap default constructor
		//and whoAmI() member function, and values
		std::cout << BG_GREEN "2 Test" RESET << std::endl;
		DiamondTrap a;
		a.printHitPoints(); 
		a.printEnergyPoints();
		a.printAttackDamage();
		a.attack("objecto 1");
		a.attack("objecto 1");
		a.attack("objecto 1");
		a.attack("objecto 1");
		a.takeDamage(110);
		a.attack("Objecto 2");
		a.beRepaired(5);
		a.whoAmI();
	}
	{
		//test 3 - ScavTrap attack
		std::cout << BG_MAGENTA "3 Test" RESET << std::endl;
		ScavTrap test("test");
		test.attack("teste 2");
	}
	{
		//test 4 - ScavTrap copy constructor
		std::cout << BG_GREEN "4 Test" RESET << std::endl;
		DiamondTrap copy("copy");
		DiamondTrap copy2(copy);

		copy2.whoAmI();
	}
	return (0);
}


