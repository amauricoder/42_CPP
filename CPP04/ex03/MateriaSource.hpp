/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:21:18 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/09 14:36:00 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_backup[4];
	public:
	//ORTHODOX
		MateriaSource();
		MateriaSource(MateriaSource const &src);
		MateriaSource& operator=(const MateriaSource &src);
		~MateriaSource();
	//Required Member Functions
		void 		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
	//debug
		void		printMateria(int index);	
};
#endif