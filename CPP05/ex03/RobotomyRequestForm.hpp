/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:17:16 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/15 19:56:51 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#define RB_SIGN 72
#define RB_EXEC 45
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
	//orthodox
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &src);
		~RobotomyRequestForm();
	//other constructors
		RobotomyRequestForm(std::string target);
	//Getter
		std::string getTarget(void);
	//Required by the subject
		int	formAction(void) const;
};

#endif