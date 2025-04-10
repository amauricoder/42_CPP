/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:10:00 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/10 18:16:14 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	p_type;
	public:
	//Orthodox Canonical
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal& operator=(const  WrongAnimal &src);
		virtual ~WrongAnimal();
	//Member functions
		virtual void	makeSound() const;
	//asked for the subject indirectly
		virtual std::string getType() const;
};

#endif