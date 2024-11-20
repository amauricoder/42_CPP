/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:50:42 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/20 19:10:08 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define RESET       "\033[0m"


class Fixed
{
	private:
		int _number;
		static const int _fract_bits;
	public:
		Fixed();
		Fixed(Fixed &obj);
		Fixed(const int x);
		Fixed(const float y);
		Fixed& operator=(Fixed &src);
		~Fixed();
		int getRawBits(void);
		void setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
		bool	operator>(Fixed &to_compare);
		bool	operator<(Fixed &to_compare);
		bool	operator>=(Fixed &to_compare);
		bool	operator<=(Fixed &to_compare);
};

std::ostream& operator<<(std::ostream& os, Fixed &obj);


#endif
