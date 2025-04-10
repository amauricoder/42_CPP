/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:31:02 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/05 14:58:15 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

#define RESET       "\033[0m"
#define BG_BLUE     "\033[44m"
#define BG_RED      "\033[41m"

class   Weapon
{
	private:
		std::string type;

	public:
		Weapon(std::string type);
		~Weapon();
		//setter
		void				setType(std::string to_set);
		//getter
		const std::string& getType() const;
};

#endif

