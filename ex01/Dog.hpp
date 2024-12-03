/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:10:45 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/03 18:56:15 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal 
{
	private:
		Brain	*_idea;
	public:
		//Orthodox Canonical
		Dog();
		Dog(const Dog &src);
		Dog& operator=(const Dog &src);
		~Dog();
		void	makeSound() const;
		//debug
		void	printDogType();
		void	printDogIdeas();
};

#endif