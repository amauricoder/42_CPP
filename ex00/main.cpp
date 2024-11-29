/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:07:56 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/29 13:52:05 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
		//3 test -> creating a ScavTrap with a name
		//and a ScavTrap with a name, and testing
		//the = assignment operator
		std::cout << BG_GREEN "3 Test" RESET << std::endl;
		ClapTrap a("Darth Vader");
		ClapTrap b("Anakin Skywalker");

		a.printName();
		b.printName();

		a = b;
		a.printName();
	}
	{
		//4 test -> Ending energy points
		std::cout << BG_MAGENTA "4 Test" RESET << std::endl;
		ClapTrap bardo("Bardo");
		bardo.attack("1");
		bardo.attack("2");
		bardo.attack("3");
		bardo.attack("4");
		bardo.attack("5");
		bardo.attack("6");
		bardo.attack("7");
		bardo.attack("8");
		bardo.attack("9");
		bardo.attack("10");
		//limit
		bardo.attack("11");
		bardo.attack("12");
		bardo.beRepaired(2);
	}
	{
		//5 test -> ending hit points
		std::cout << BG_GREEN "5 Test" RESET << std::endl;
		ClapTrap quinto("quinto");
		quinto.takeDamage(10);
		quinto.attack("qualquer");
		quinto.beRepaired(10);
	}
	return (0);
}