/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:51:57 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/03 16:57:12 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "Cat.hpp"
#include "Dog.hpp"

#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_ORANGE   "\033[48;5;202m"
#define RESET       "\033[0m"

int main(void)
{
	{
		//test 1 -> Dog makeSound()
		std::cout << BG_MAGENTA "TEST 1" << RESET << std::endl;
		
		Dog snoopy;
		snoopy.makeSound();
		snoopy.printDogType();
	}
	{
		//test 2 -> Cat makeSound()
		std::cout << BG_GREEN "TEST 2" << RESET << std::endl;

		Cat garfield;
		garfield.makeSound();	
		garfield.printCatType();
	}
	{
		//test 3 -> Animal MakeSound()
		std::cout << BG_BLUE "TEST 3" << RESET << std::endl;
		Animal mammal;
		mammal.makeSound();
		mammal.printAnimalType();	
	}
	{
		//test 4 -> Be Sure that the makeSound function called
		//is the one inherit from Animal
		std::cout << BG_MAGENTA "TEST 4" << RESET << std::endl;
		Animal *test = new Dog();
		test->makeSound();
		test->printAnimalType();
		delete test;
	}
	{
		//test 5 -> Be Sure that the makeSound function called
		//is the one inherit from Animal
		std::cout << BG_GREEN "TEST 5" << RESET << std::endl;
		Animal *test = new Cat();
		test->makeSound();
		test->printAnimalType();
		delete test;
	}
	{
		//test 6 -> Subject Test
		std::cout << BG_BLUE "TEST 6" << RESET << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete i;
		delete j;
	}
	return (0);
}