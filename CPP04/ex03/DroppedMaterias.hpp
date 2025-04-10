/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DroppedMaterias.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:28:13 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/13 15:02:37 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DROPPEDMATERIAS_HPP
#define DROPPEDMATERIAS_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#define MAX_DROPPED 10

class DroppedMateria {
	private:
		AMateria	*_dropped[MAX_DROPPED];
		int		_count;
	public:
	//orthodox
		DroppedMateria();
		DroppedMateria(const DroppedMateria &src);
		DroppedMateria& operator=(const DroppedMateria &src);
		~DroppedMateria();
	//methods
		AMateria* 				getDropped(int idx) const;
		static DroppedMateria&	getInstance();
		void					addDropped(AMateria *materia);
		
};

#endif