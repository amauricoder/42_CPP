/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:17:22 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/14 15:26:41 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base 
{
	public:
		C();
		C(const C &src);
		C& operator=(const C &src);
		~C();
};

#endif