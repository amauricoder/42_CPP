/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:29:19 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/15 19:41:06 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string	const	_name;
		int					_grade;
	public:
	//Orthodoxc
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat& operator=(const Bureaucrat &src);
		~Bureaucrat();
	//other constructors
		Bureaucrat(int grade);
		Bureaucrat(std::string name);
	//getters
		std::string 	getName(void) const;
		int				getGrade(void) const;
		//setter
		void			setGrade(int grade);
		//member functions required
		Bureaucrat		operator++(int); //post increment
		Bureaucrat		operator--(int); //post decrement
		void			signForm(AForm &f);
		int				executeForm(AForm const &form);
		//exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

//function implementation of an overload of the insertion («)
std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj);
#endif 