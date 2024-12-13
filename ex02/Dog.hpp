/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:10:45 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/12 13:49:07 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal 
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
		//getter
		Brain*	getBrain(void);
		//debug
		void	printDogType();
		void	printDogIdeas();
};

#endif