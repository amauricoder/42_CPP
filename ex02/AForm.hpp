/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:19:17 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/14 22:48:52 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	const	_name;
		bool				_is_signed;
		int	const			_grade_sign;
		int	const			_grade_exec;
	public:
	//orthodox
		AForm();
		AForm(const AForm &src);
		AForm&	operator=(const AForm &src);
		virtual ~AForm();

	//other constructors
		AForm(std::string name, int grade_sign, int grade_exec);
		
	//getters
		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeSign(void) const;
		int			getGradeExec(void) const;
	//Required by the subject
		void		beSigned(const Bureaucrat &b);
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
	//Pure virtual not required by the suject, but I need it.
		virtual	std::string getTarget(void) = 0;
};

//overload of the insertion («)
std::ostream& operator<<(std::ostream &os, const AForm &obj);

#endif