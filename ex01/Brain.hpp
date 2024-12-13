/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:35:30 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/12 12:46:19 by aconceic         ###   ########.fr       */
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
	//setter
		void		setIdea(std::string new_idea, int index);
	//Debug
		void	printIdeas();
		std::string*	getIdeasAddress();
	
};

#endif