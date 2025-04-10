/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:47:03 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/07 21:11:51 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
	//Orthodox canonical
		Cure();
		Cure(const Cure &src);
		Cure& operator=(const Cure &src);
		~Cure();
	//other constructs
		Cure(std::string type);
	//Member Func
		Cure* clone() const;
		void use(ICharacter& target);
	//Inherit
	std::string const & getType() const;
};

#endif