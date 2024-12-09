/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:53:34 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/09 16:35:54 by aconceic         ###   ########.fr       */
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



void    test_inherit_dog_make_sound(void)
{
	std::cout << BG_MAGENTA "TEST Inherit Dog MakeSound()" << RESET << std::endl;
	AAnimal *test = new Dog();
	test->makeSound();
	test->printAnimalType();
	delete test;
}

void    test_inherit_cat_make_sound(void)
{
   std::cout << BG_GREEN "TEST Inherit Cat MakeSound()" << RESET << std::endl;
	AAnimal *test = new Cat();
	test->makeSound();
	test->printAnimalType();
	delete test;
}

void    test_filling_brain_with_ideas(void)
{
	std::cout << BG_GREEN "TEST Filling brain with ideas" RESET << std::endl;
	Brain a;
	a.printIdeas();
	std::cout << BG_GREEN "END OF Filling brain with ideas" RESET << std::endl;
}

void	test_cat_ideas(void)
{
	//test
	//see cat ideas and check if there is leaks
	std::cout << BG_BLUE "TEST cat ideas" RESET << std::endl;
	Cat garfield;
	garfield.printCatIdeas();
	std::cout << BG_BLUE "END cat ideas" RESET << std::endl;
}

void	test_dog_ideas(void)
{
	//test
	//see dog ideas and check if there is leaks
	std::cout << BG_GREEN "TEST dog ideas" RESET << std::endl;
	Dog snoopy;
	snoopy.printDogIdeas();
	std::cout << BG_GREEN "END dog ideas" RESET << std::endl;
}

void    test_half_cats_and_dogs_in_array(void)
{
	std::cout << BG_MAGENTA "Test half cats and dogs in array" RESET << std::endl;
	AAnimal **test = new AAnimal*[10];
	for (int i = 0; i < 5; i ++)
	{
		std::cout << BG_ORANGE "CREATING DOG IN ANIMAL ARRAY" RESET << std::endl;
		test[i] = new Dog; 
	}
	for (int i = 5; i < 10; i ++)
	{
		std::cout << BG_ORANGE "CREATING CAT IN ANIMAL ARRAY" RESET << std::endl;
		test[i] = new Cat; 
	}
	for (int i = 0; i < 10; i ++)
		test[i]->makeSound();
	
	for (int i = 0; i < 10; i ++)
		delete test[i];
	delete [] test;
	std::cout << BG_MAGENTA "END half cats and dogs in array" RESET << std::endl;
}

void	test_deep_copies(void)
{
	//test 6
	//see if they are deep copies
	std::cout << BG_BLUE "TEST deep copies" RESET << std::endl;
	AAnimal *dog = new Dog;
	dog->makeSound(); // need to auau.
	AAnimal *cat = new Cat;
	cat->makeSound(); // need to meow
	
	//If they were now deep copies, they would do the 
	//makeSound of the main Class.
	delete dog;
	delete cat;
	std::cout << BG_BLUE "END deep copies" RESET << std::endl;
}
