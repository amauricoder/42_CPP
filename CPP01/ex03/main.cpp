/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:01:01 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/05 15:33:38 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

#define BG_MAGENTA  "\033[45m"
#define RESET       "\033[0m"

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		HumanB joe("Joe");
		joe.attack();
	}
	return (0);
}

/*
	std::string &stringREF = str;
	Creates a reference called stringREF to str. 
	A reference in C++ is an alias for an existing variable, 
	so stringREF is essentially another name for str. 
	When you use stringREF, it directly accesses the str variable's 
	value and memory address without any need for dereferencing.
*/