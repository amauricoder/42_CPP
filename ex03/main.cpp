/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:59:21 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/09 15:38:10 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_ORANGE   "\033[48;5;202m"
#define RESET       "\033[0m"

int main(void)
{
	{
		//test1 - Subject
		std::cout << "**************************" << std::endl;
		std::cout << BG_ORANGE "          TEST 1          " RESET << std::endl;
		std::cout << "**************************" << std::endl;
		
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		//test 2 - Materia tests
		std::cout << "**************************" << std::endl;
		std::cout << BG_ORANGE "          TprestoEST 2          " RESET << std::endl;
		std::cout << "**************************" << std::endl;
		
		//declare src
		IMateriaSource	*src = new MateriaSource();
		//declare materias(to learn later)
		AMateria 		*ice_materia = new Ice();
		AMateria		*cure_materia = new Cure();
		
		//learn materias
		src->learnMateria(ice_materia);
		src->learnMateria(cure_materia);

		//create materias and saving them to pointers
		AMateria* creation1 = src->createMateria("ice");
		AMateria* creation2 = src->createMateria("cure");
		src->createMateria("farofa"); //invalid should return invalid type
	
		//create characters
		ICharacter *presto = new Character("Presto");
		ICharacter *alvo = new Character("Alvo");
		
		//equip materias 
		presto->equip(creation1); //[0] ice
		presto->equip(creation2); //[1] cure
		presto->equip(creation1); //try to equip an already Materia (must retorn error)
		
		presto->equip(src->createMateria("ice")); //[2] try to create directly (must not give leak) and create ICE
		presto->equip(src->createMateria("cure")); //[3] try to create directly (must not give leak) and create ICE
		//[DISCLAMER] If you unequip materias that are created directly,
		//we will find leaks, because there is no way to clean them with the subject restrictions...

		//try to equip a materia that is already in use
		//in another character
		alvo->equip(creation1); //must return error msg

		//Try to equip more than 4 materias
		alvo->equip(src->createMateria("cure")); //cure
		alvo->equip(src->createMateria("ice")); //ice
		alvo->equip(src->createMateria("cure")); //cure
		alvo->equip(src->createMateria("ice")); //ice
		
		AMateria* creation3 = src->createMateria("cure");
		alvo->equip(creation3); //should return error of full inventory

		alvo->use(0, *presto); //should print cure msg
		alvo->use(1, *presto); //should print ice msg
		alvo->use(2, *presto); //should print cure msg
		alvo->use(3, *presto); //should print ice msg

		alvo->use(-1, *presto); // should return error
		alvo->use(4, *presto); // should return error

		presto->unequip(0); //should unequip
		presto->unequip(1); //should unequip

		presto->use(0, *alvo); //should print error msg
		presto->use(1, *alvo); //should print error msg
		
		delete src;
		delete presto;
		delete alvo;
		delete creation1; //need to clean this if unequiped
		delete creation2; //need to clean this if unequiped
		delete creation3;
	}
	return (0);
}