/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:46:36 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/07 21:03:38 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
	//Orthodox canonical
		Ice();
		Ice(const Ice &src);
		Ice& operator=(const Ice &src);
		virtual ~Ice();
	//other constructors
		Ice(std::string type);
	//functions
		Ice* clone() const;
		void use(ICharacter &target);
	//inherit
		std::string const & getType() const;
};

#endif