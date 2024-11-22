/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:50:42 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/22 16:42:58 by aconceic         ###   ########.fr       */
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
		Fixed(const Fixed &obj);
		Fixed(const int x);
		Fixed(const float y);
		Fixed& operator=(const Fixed &src);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
		bool	operator>(Fixed &to_compare);
		bool	operator<(Fixed &to_compare);
		bool	operator>=(Fixed &to_compare);
		bool	operator<=(Fixed &to_compare);
		bool	operator==(Fixed &to_compare);
		bool	operator!=(Fixed &to_compare);
		Fixed	operator+(const Fixed &to_sum) const;
		Fixed	operator-(const Fixed &to_diff) const;
		Fixed	operator*(const Fixed &to_mult) const;
		Fixed	operator/(const Fixed &to_div) const;
		Fixed&	operator++();
		Fixed	operator++(int); //pre (dummy int to make it difference)
		Fixed&	operator--();
		Fixed	operator--(int); //pre (dummy int to make it difference)
		
		static Fixed&		min(Fixed &obj1, Fixed &obj2);
		static const Fixed&	min(Fixed const &obj1, Fixed const &obj2);
		static Fixed&		max(Fixed &obj1, Fixed &obj2);
		static const Fixed&	max(Fixed const &obj1, Fixed const &obj2);
};

std::ostream& operator<<(std::ostream& os, const Fixed &obj);


#endif
