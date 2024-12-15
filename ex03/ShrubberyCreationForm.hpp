/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:38:29 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/15 19:56:48 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#define SH_SIGN 145
#define SH_EXEC 137

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
	//Orthodox
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
	//Other constructors
		ShrubberyCreationForm(const std::string target);
	//Getter
		std::string	getTarget(void);
	//Required by the subject
		int	formAction(void) const;
};

#endif