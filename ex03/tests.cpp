/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:40:57 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/13 15:19:59 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void    test_subject(void)
{
	//test1 - Subject
	std::cout << BG_ORANGE "          TEST SUBJECT          " RESET << std::endl;
	
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

	std::cout << BG_ORANGE "          END TEST SUBJECT          " RESET << std::endl;
}

void    test_materias(void)
{
	std::cout << BG_GREEN "          TEST MATERIAS          " RESET << std::endl;
	//declare src
	IMateriaSource	*src = new MateriaSource();

	//declare materias(to learn later)
	AMateria 		*ice_materia = new Ice();
	AMateria		*cure_materia = new Cure();
	
	//try to create materia without learning (must return error)
	src->createMateria("ice");
	src->createMateria("cure");
	
	//learn materias
	src->learnMateria(ice_materia);
	src->learnMateria(cure_materia);

	//create materias and saving them to pointers
	AMateria* creation1 = src->createMateria("ice");
	AMateria* creation2 = src->createMateria("cure");
	src->createMateria("farofa"); //invalid should return invalid type
	
	std::cout << "Type : " << cure_materia->getType() << std::endl;
	std::cout << "Type : " << ice_materia->getType() << std::endl;
	std::cout << "Type : " << creation1->getType() << std::endl;
	std::cout << "Type : " << creation2->getType() << std::endl;
	delete src;
	delete creation1;
	delete creation2;
	std::cout << BG_GREEN "          END TEST MATERIAS          " RESET << std::endl;
}

void    test_characteres(void)
{
	std::cout << BG_MAGENTA "          TEST CHARACTERES          " RESET << std::endl;

	//create characters
	ICharacter *presto = new Character("Presto");
	ICharacter *alvo = new Character("Alvo");

	//create materias and learn to use (to use with character)
	IMateriaSource	*src = new MateriaSource();
	AMateria		*cure_materia = new Cure();
	AMateria 		*ice_materia = new Ice();
	src->learnMateria(ice_materia);
	src->learnMateria(cure_materia);
	AMateria* creation1 = src->createMateria("ice");
	AMateria* creation2 = src->createMateria("cure");
	
	//equip materias
	presto->equip(creation1); //[0] ice
	presto->equip(creation2); //[1] cure
	presto->equip(creation1); //try to equip an already filled Materia (must retorn error)
	presto->equip(NULL); //try to equip NULL (must return error)

	//try to equip a materia that is already in use
	//in another character
	alvo->equip(creation1); //must return error msg (already equiped materia)
	
	//Try to equip more than 4 materias
	alvo->equip(src->createMateria("cure")); //cure
	alvo->equip(src->createMateria("ice")); //ice
	alvo->equip(src->createMateria("cure")); //cure
	alvo->equip(src->createMateria("ice")); //ice
	AMateria* creation3 = src->createMateria("cure");
	alvo->equip(creation3); //should return error of full inventory

	//use character inventary
	alvo->use(0, *presto); //should print cure msg
	alvo->use(1, *presto); //should print ice msg
	alvo->use(2, *presto); //should print cure msg
	alvo->use(3, *presto); //should print ice msg
	
	//try to use invalid inventary
	alvo->use(-1, *presto); // should return error
	alvo->use(4, *presto); // should return error

	//test unequip
	presto->unequip(0); //should unequip
	presto->unequip(1); //should unequip

	presto->use(0, *alvo); //should print error msg
	presto->use(1, *alvo); //should print error msg

	//try to used enquiped materias on another characther
	//and use it.
	ICharacter *merlin = new Character("merlin");
	
	merlin->equip(creation1); //[0]should equip
	merlin->equip(creation2); //[1]should equip
	merlin->equip(creation2); //should return error
	
	merlin->use(0, *alvo); //should print msg of use
	merlin->use(1, *alvo);	//should print msg of use
	
	presto->unequip(0); //should unequip
	presto->unequip(1); //should unequip
	
	delete src;
	delete presto;
	delete alvo;
	delete merlin;
	delete creation3;

	std::cout << BG_MAGENTA "         END TEST CHARACTERES          " RESET << std::endl;

}


