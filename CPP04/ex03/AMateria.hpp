/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:59:57 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/09 14:50:04 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

//forward declaration to break circular dependency

class ICharacter;

class AMateria
{
	protected:
		std::string		p_type;
		bool			is_equiped;
	public:
	//ORTHODOX CANONICAL
		AMateria();
		AMateria(const AMateria &src);
		AMateria& operator=(const AMateria &src);
		virtual ~AMateria();
	//REQUIRED CONSTRUCTOR
		AMateria(std::string const & type);
	//SETTER AND GETTER
		void	setIsEquiped(bool is);
		bool	getIsEquiped(void);	
	//Member function
		virtual std::string const & getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif