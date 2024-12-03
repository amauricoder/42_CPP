/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:51:57 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/03 18:56:45 by aconceic         ###   ########.fr       */
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
		Cat garfield;
		garfield.printCatIdeas();
	}
	{
		Dog snoopy;
		snoopy.printDogIdeas();
	}
	return (0);
}