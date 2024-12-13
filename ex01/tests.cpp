/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:53:34 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/12 13:53:29 by aconceic         ###   ########.fr       */
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
	std::cout << BG_BLUE "TEST Given by the subject(1)" << RESET << std::endl;

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
	Animal **test = new Animal*[10];
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
	Animal *dog = new Dog;
	Animal *dogcpy = dog;

	dog->makeSound(); // need to auau.
	std::cout << "Dog address memory : " << &dog << "\n"
	<< "Dog Copy address memory : " << &dogcpy  << std::endl;

	Animal *cat = new Cat;
	Animal *catcpy = cat;
	cat->makeSound(); // need to meow
	std::cout << "Cat address memory : " << &cat << "\n"
	<< "Cat Copy address memory : " << &catcpy << std::endl;
	
	//If they were now deep copies, they would do the 
	//makeSound of the main Class.
	delete dog;
	delete cat;
	std::cout << BG_BLUE "END deep copies" RESET << std::endl;
}

void test_brain_constructor_and_deep_copies(void)
{
    std::cout << BG_ORANGE "TEST BRAIN constructor and deep copies" RESET << std::endl;

    Brain brain;
    std::cout << "brain memory address       : " << &brain << std::endl;
    std::cout << "brain._ideas memory address: " << brain.getIdeasAddress() << std::endl;

    Brain brain2;
    std::cout << "brain2 memory address       : " << &brain2 << std::endl;
    std::cout << "brain2._ideas memory address: " << brain2.getIdeasAddress() << std::endl;

    // Assignment
    brain = brain2;
	std::cout << "ATTENTTION HERE -> THIS FUCKING 42 PC IS ALLOCATING FOR THE SAME MEMORY ADDRESS AFTER DELETE IN BRAIN. YOU WILL NEED TO SHOW THIS TO EVALUATOR AND SHOW DEBUG CASE IN BRAIN ASSIGNMENT OPERATOR." << std::endl;
    std::cout << "After assignment:" << std::endl;
    std::cout << "brain memory address       : " << &brain << std::endl;
    std::cout << "brain._ideas memory address: " << brain.getIdeasAddress() << std::endl;

	std::cout << "Modifying idea in brain (brain2 must be unchanged)" << std::endl;
	brain.setIdea("NEW IDEA IN BRAIN(NOT BRAIN2)", 0);
	std::cout << "Print idea brain : " << brain.getIdea(0) << std::endl;
	std::cout << "Print idea brain2 : " << brain2.getIdea(0) << std::endl;
	
    // Copy Constructor
    Brain brain3(brain);
    std::cout << "brain3 memory address       : " << &brain3 << std::endl;
    std::cout << "brain3._ideas memory address: " << brain3.getIdeasAddress() << std::endl;

    std::cout << BG_ORANGE "END TEST BRAIN constructor and deep copies" RESET << std::endl;
}

void	test_assign_dog(void)
{
	std::cout << BG_BLUE "TEST dog assignment operator" RESET << std::endl;
	Dog snoopy;
	Dog	scooby;

	scooby = snoopy;

	std::cout << &snoopy << " " << &scooby << std::endl;

	std::cout << BG_BLUE "END TEST TEST dog assignment operator" RESET << std::endl;
}

void	test_deep_dog(void)
{
	std::cout << BG_MAGENTA "TEST deep dog" RESET << std::endl;

	Dog originalDog;
	originalDog.printDogIdeas();

	Dog copyDog = originalDog;

	std::cout << BG_ORANGE "MODIFY ORIGINAL DOG BRAIN" RESET << std::endl;
	for (int i = 0; i < 100; i++)
		originalDog.getBrain()->setIdea("New Idea", i);
	
	std::cout << "\nOriginal Dog's Ideas After Modification:\n";
    originalDog.printDogIdeas();

    std::cout << "\nCopied Dog's Ideas Should Be Unchanged:\n";
    copyDog.printDogIdeas();
	std::cout << BG_MAGENTA "END TEST deep dog" RESET << std::endl;
}

void	test_evaluation_sheet(void)
{
	std::cout << BG_MAGENTA "TEST evaluation sheet" RESET << std::endl;
	Dog basic;
	Dog tmp = basic;
	Dog tmp2(basic);
	std::cout << BG_MAGENTA "END TEST evaluation sheet" RESET << std::endl;
}
