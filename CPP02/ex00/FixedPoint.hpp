/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPoint.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:03:33 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/18 17:29:30 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXEDPOINT_HPP
#define FIXEDPOINT_HPP

#include <iostream>

class FixedPoint
{
	private:
		int					_fixed_pt_value;
		static const int	_fractional_bits;
	public:
		FixedPoint();
		FixedPoint(const FixedPoint &obj); //1. New Concept
		FixedPoint& operator=(const FixedPoint &src); //2. New Concept
		~FixedPoint();
		//getter
		int	getRawBits(void) const;
		//setter
		void setRawBits( int const raw );
		
};

#endif