/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:37:59 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/13 15:04:29 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "DroppedMaterias.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria 	*_inventory[4];
	public:
//Orthodox
	Character();
	Character(const Character &src);
	Character& operator=(const Character &src);
	~Character();
//Other constructor
	Character(std::string name);
//inherit
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};
#endif