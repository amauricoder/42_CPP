/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:59:21 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/07 21:21:18 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_ORANGE   "\033[48;5;202m"
#define RESET       "\033[0m"

int main(void)
{
	{
		//test1 - testing constructors and getter
		//test made before turning class into
		//Abstract class
		//uncomment /**/ to test
		/* std::cout << BG_ORANGE "TEST 1" RESET << std::endl;
		
		AMateria a;
		std::cout << a.getType() << std::endl;
		AMateria b("word");
		std::cout << b.getType() << std::endl;
		a = b;
		//This should print the initial value, because its constant
		std::cout << a.getType() << std::endl;
		//This shoulf print the type of b "word"
		AMateria c(b);
		std::cout << c.getType() << std::endl; */
	}
	{
		AMateria *i = new Ice("ice");
		std::cout << i->getType() << std::endl;
		
		AMateria *c = new Cure("cure");
		std::cout << c->getType() << std::endl;

		delete i;
		delete c;
	}
	return (0);
}