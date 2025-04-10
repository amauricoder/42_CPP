/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:07:56 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/28 15:19:15 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define RESET       "\033[0m"

int main(void)
{
	{
		//First test -> creating a ClapTrap without attributes
		//and checking its values and member function
		unsigned int a_test_value = 10;
		std::cout << BG_MAGENTA "1 Test" RESET << std::endl;
		ClapTrap a;
		a.attack("Paul Mccartney");
		a.beRepaired(a_test_value);
		a.takeDamage(a_test_value);
		a.printName();
		a.printAttackDamage();
		a.printHitPoints();
		a.printEnergyPoints();
	}
	{
		//Second test -> creating a Claptrap with name attribute
		//and checking its value and member function
		unsigned int a_test_value = 10;
		std::cout << BG_GREEN "2 Test" RESET << std::endl;
		ClapTrap a("John Lennon");
		a.attack("Paul Mccartney");
		a.beRepaired(a_test_value);
		a.takeDamage(a_test_value);
		a.printName();
		a.printAttackDamage();
		a.printHitPoints();
		a.printEnergyPoints();
	}
	{
		//Third test -> creating a ScavTrap with no
		//and checking its value and member functions
		std::cout << BG_MAGENTA "3 Test" RESET << std::endl;
		unsigned int a_test_value = 10;
		ScavTrap a;
		a.attack("Paul Mccartney");
		a.beRepaired(a_test_value);
		a.takeDamage(a_test_value);
		a.guardGate();
		a.printName();
		a.printAttackDamage();
		a.printHitPoints();
		a.printEnergyPoints();
	}
	{
		//Forth test -> creating a ScavTrap with a name
		//and checking its value and member functions
		std::cout << BG_MAGENTA "4 Test" RESET << std::endl;
		unsigned int a_test_value = 10;
		ScavTrap a("Papi noel");
		a.attack("Paul Mccartney");
		a.beRepaired(a_test_value);
		a.takeDamage(a_test_value);
		a.guardGate();
		a.printName();
		a.printAttackDamage();
		a.printHitPoints();
		a.printEnergyPoints();
	}
	{
		//Five test -> creating a ScavTrap with a name
		//and a ScavTrap with a name, and testing
		//the = assignment operator
		std::cout << BG_GREEN "5 Test" RESET << std::endl;
		ScavTrap a("Darth Vader");
		ScavTrap b("Anakin Skywalker");

		a.printName();
		b.printName();

		a = b;
		a.printName();

		a.guardGate();
	}
	return (0);
}