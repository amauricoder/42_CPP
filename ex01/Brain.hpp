/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:35:30 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/03 18:42:09 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

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