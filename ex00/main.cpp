/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:07:56 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/27 16:34:38 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	//test default constructor
	ClapTrap a;

	ClapTrap b("Baygon");

	ClapTrap c;

	c = b;

	std::cout << "C NAME -> "; c.printName();

	a.attack("Baygon");
	b.takeDamage(0);
	c.beRepaired(2);
	return (0);
}