/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:53:07 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/07 14:52:31 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <sstream>

class AAnimal
{
	protected:
		std::string	p_type;
	public:
	//Orthodox Canonical
		AAnimal();
		AAnimal(const AAnimal &src);
		AAnimal& operator=(const  AAnimal &src);
		virtual ~AAnimal();
	//Member functions
		virtual void	makeSound() const = 0;
	//to debug
		void	printAnimalType();
	//asked for the subject indirectly
		virtual std::string getType() const;
};

//Destructor as virtual to ensure that 
//all the derivated classes to destroy properly
#endif