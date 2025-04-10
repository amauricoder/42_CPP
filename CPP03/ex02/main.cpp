/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:07:56 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/29 16:38:56 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define RESET       "\033[0m"

int main(void)
{
	{
		//test 1 - create FlagTrap without name and display
		//member functions and values
		unsigned int a_test_value = 10;
		std::cout << BG_MAGENTA "1 Test" RESET << std::endl;
		FragTrap a;
		a.attack("DigriJohnson");
		a.beRepaired(a_test_value);
		a.takeDamage(5);
		a.highFivesGuys();
		a.printName();
		a.printAttackDamage();
		a.printEnergyPoints();
		a.printHitPoints();
	}
	{
		//test 2 - test of copy assign operator
		std::cout << BG_GREEN "2 Test" RESET << std::endl;
		unsigned int a_test_value = 10;
		FragTrap b("bicho papao");
		FragTrap a;
		
		a = b;
		a.attack("DigriJohnson");
		a.beRepaired(a_test_value);
		a.takeDamage(5);
		a.highFivesGuys();
		a.printName();
		a.printAttackDamage();
		a.printEnergyPoints();
		a.printHitPoints();
	}
	{
		//test 3 - Test Copy Constructor
		std::cout << BG_MAGENTA "3 Test" RESET << std::endl;
		unsigned int a_test_value = 10;
		FragTrap a("General Kenobi");

		a.attack("DigriJohnson");
		a.beRepaired(a_test_value);
		a.takeDamage(5);
		a.highFivesGuys();
		a.printName();
		a.printAttackDamage();
		a.printEnergyPoints();
		a.printHitPoints();
		FragTrap b(a);
		b.highFivesGuys();
		b.printName();
		b.printAttackDamage();
		b.printEnergyPoints();
		b.printHitPoints();
	}
	return (0);
}