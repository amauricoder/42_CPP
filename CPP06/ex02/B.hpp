/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:10:17 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/14 15:33:07 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base
{
	public:
		B();
		B(const B &src);
		B& operator=(const B &src);
		~B();

};

#endif