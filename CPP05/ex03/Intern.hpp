/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:24:58 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/15 22:28:42 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern 
{
	public:
	//Orthodox
		Intern();
		Intern(const Intern &src);
		Intern& operator=(const Intern &src);
		~Intern();
	//Required by the subject
		AForm*	makeForm(std::string form_name, std::string target);
	//exception
	class FormNotCreated : public std::exception
	{
		virtual const char* what() const throw();	
	};
};


#endif