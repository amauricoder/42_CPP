/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:51:57 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/04 16:42:04 by aconceic         ###   ########.fr       */
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
		//test 1
		//Make sure that Dog will bark
		std::cout << BG_MAGENTA "Test 1" RESET << std::endl;
		Animal *test = new Dog();
		test->makeSound();
		delete test;
	}
	{
		//test 2
		//Filling brain with ideas and
		//checking if there is no leaks
		std::cout << BG_GREEN "Test 2" RESET << std::endl;
		Brain a;
		a.printIdeas();
	}
	{
		//test 3
		//see cat ideas and check if there is leaks
		std::cout << BG_BLUE "Test 3" RESET << std::endl;
		Cat garfield;
		garfield.printCatIdeas();
	}
	{
		//test 4
		//see dog ideas and check if there is leaks
		std::cout << BG_MAGENTA "Test 4" RESET << std::endl;
		Dog snoopy;
		snoopy.printDogIdeas();
	}
	{
		//test 5
		//Test required by the subject
		std::cout << BG_GREEN "Test 5" RESET << std::endl;
		Animal **test = new Animal*[10];
		for (int i = 0; i < 5; i ++)
		{
			std::cout << BG_ORANGE "CREATING DOG IN ANIMAL ARRAY" RESET << std::endl;
			test[i] = new Dog; 
		}
		for (int i = 5; i < 9; i ++)
		{
			std::cout << BG_ORANGE "CREATING CAT IN ANIMAL ARRAY" RESET << std::endl;
			test[i] = new Cat; 
		}

		test[4]->makeSound();
		test[5]->makeSound();
		
		for (int i = 0; i < 9; i ++)
			delete test[i];
		delete [] test;
	}
	{
		//test 6
		//see if they are deep copies
		std::cout << BG_BLUE "Test 6" RESET << std::endl;
		Animal *dog = new Dog;
		dog->makeSound(); // need to auau.

		Animal *cat = new Cat;
		cat->makeSound(); // need to meow
		
		//If they were now deep copies, they would do the 
		//makeSound of the main Class.
		delete dog;
		delete cat;
	}
	return (0);
}