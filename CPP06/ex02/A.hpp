/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:41:01 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/14 14:47:41 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base 
{
	public:
		A();
		A(const A &src);
		A& operator=(const A &src);
		~A();
};

#endif