/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:35:30 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/07 14:54:44 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "AAnimal.hpp"

class Brain
{
	private:
		std::string	*_ideas;
	public:
		//orthodox canonical form
		Brain();
		Brain(const Brain &src);
		Brain& operator=(const Brain &src);
		~Brain();
	//getter
		std::string getIdea(int	index);
	//Debug
		void	printIdeas();
	
};

#endif