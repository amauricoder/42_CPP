/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:53:34 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/09 16:09:26 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void    test_dog_make_sound(void)
{
	std::cout << BG_MAGENTA "TEST Cat MakeSounde()" << RESET << std::endl;
		
	Dog snoopy;
	snoopy.makeSound();
	snoopy.printDogType();
}

void    test_cat_make_sound(void)
{
	std::cout << BG_GREEN "TEST Cat MakeSounde()" << RESET << std::endl;
	Cat garfield;
	garfield.makeSound();	
	garfield.printCatType();
}

void    test_animal_make_sound(void)
{
	std::cout << BG_BLUE "TEST Animal MakeSound()" << RESET << std::endl;
	Animal mammal;
	mammal.makeSound();
	mammal.printAnimalType();	
}

void    test_inherit_dog_make_sound(void)
{
	std::cout << BG_MAGENTA "TEST Inherit Dog MakeSound()" << RESET << std::endl;
	Animal *test = new Dog();
	test->makeSound();
	test->printAnimalType();
	delete test;
}

void    test_inherit_cat_make_sound(void)
{
   std::cout << BG_GREEN "TEST Inherit Cat MakeSound()" << RESET << std::endl;
	Animal *test = new Cat();
	test->makeSound();
	test->printAnimalType();
	delete test;
}

void	test_subject(void)
{
	std::cout << BG_BLUE "TEST Given by the subject" << RESET << std::endl;

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