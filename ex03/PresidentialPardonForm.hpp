/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:34:30 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/15 19:56:54 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#define PR_SIGN 25
#define PR_EXEC 5

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
	//Orthodox
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &src);
		~PresidentialPardonForm();
	//Other Constructors
		PresidentialPardonForm(std::string target);
	//Getter
		std::string	getTarget(void);
	//required by the subject
		int	formAction(void) const;
};

#endif