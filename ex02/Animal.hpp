/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:53:07 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/03 18:19:33 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <sstream>

class Animal
{
	protected:
		std::string	p_type;
	public:
	//Orthodox Canonical
		Animal();
		Animal(const Animal &src);
		Animal& operator=(const  Animal &src);
		virtual ~Animal();
	//Member functions
		virtual void	makeSound() const;
	//to debug
		void	printAnimalType();
	//asked for the subject indirectly
		virtual std::string getType() const;
};

//Destructor as virtual to ensure that 
//all the derivated classes to destroy properly
#endif