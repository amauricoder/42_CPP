/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:10:49 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/03 18:40:06 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal 
{
	private:
		Brain	*_idea;
	public:
		//Orthodox Canonical
		Cat();
		Cat(const Cat &src);
		Cat& operator=(const Cat &src);
		~Cat();
		void	makeSound() const;
		void	printCatType();
		void	printCatIdeas();
};

#endif