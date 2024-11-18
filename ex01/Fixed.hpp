/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:31:00 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/18 18:01:28 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fixed_point;
		static const int	_fract_bits;
	public:
		Fixed();
		Fixed(const int x);
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &src);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};

#endif