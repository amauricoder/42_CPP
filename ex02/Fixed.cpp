/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:50:45 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/22 16:33:09 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed() : _number(0)
{
	//std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &obj)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->_number = obj._number;
}

//This is the same as x * 2^_fract_bits
Fixed::Fixed(const int x)
{
	this->_number = x << _fract_bits;
}

Fixed::Fixed(const float y)
{
	this->_number = y * roundf((1 << _fract_bits));	
}

Fixed&	Fixed::operator=(const Fixed &src)
{
	//std::cout << "Assign constructor called" << std::endl;
	if (this != &src)
	{
		this->_number = src._number;
	}
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Default destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->_number);
}

void Fixed::setRawBits(int const raw)
{
	this->_number = raw;	
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_number / (float)(1 << _fract_bits));
}

int		Fixed::toInt(void) const
{
	return ((int)_number >> Fixed::_fract_bits);
}

//OVERLOADS OPERATORS
std::ostream& operator<<(std::ostream& os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}

bool	Fixed::operator>(Fixed &to_compare)
{
	return (this->getRawBits() > to_compare.getRawBits());
}

bool	Fixed::operator<(Fixed &to_compare)
{
	return (this->getRawBits() < to_compare.getRawBits());
}

bool	Fixed::operator>=(Fixed &to_compare)
{
	return (this->getRawBits() >= to_compare.getRawBits());
}

bool	Fixed::operator<=(Fixed &to_compare)
{
	return (this->getRawBits() <= to_compare.getRawBits());
}

bool	Fixed::operator==(Fixed &to_compare)
{
	return (this->getRawBits() == to_compare.getRawBits());
}

bool	Fixed::operator!=(Fixed &to_compare)
{
	return (this->getRawBits() != to_compare.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &to_sum) const
{
	Fixed sum;

	sum.setRawBits(this->getRawBits() + to_sum.getRawBits());
	return (sum);
}

Fixed	Fixed::operator-(const Fixed &to_diff) const
{
	Fixed diff;

	diff.setRawBits(this->getRawBits() - to_diff.getRawBits());
	return (diff);
}

Fixed	Fixed::operator*(const Fixed &to_mult) const
{
	Fixed mult;

	mult.setRawBits(this->getRawBits() * to_mult.getRawBits() >> _fract_bits);
	return (mult);
}

Fixed	Fixed::operator/(const Fixed &to_div) const
{
	Fixed div;

	div.setRawBits(this->getRawBits() / to_div.getRawBits() << _fract_bits);
	return (div);
}

//Post Increment
//Value is modified in the expression
Fixed&	Fixed::operator++()
{
	this->_number ++;
	return (*this);
}

//Pre increment - takes an int dummy paramether to make it different
//from post increment
//value modified before the expression
Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	this->_number --;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed&	Fixed::min(Fixed &obj1, Fixed &obj2)
{
	return (obj1.getRawBits() < obj2.getRawBits() ? obj1 : obj2);
}

const Fixed&	Fixed::min(Fixed const &obj1, Fixed const &obj2)
{
	return (obj1.getRawBits() < obj2.getRawBits() ? obj1 : obj2);
}

Fixed&	Fixed::max(Fixed &obj1, Fixed &obj2)
{
	return (obj1.getRawBits() > obj2.getRawBits() ? obj1 : obj2);
}

const Fixed&	Fixed::max(Fixed const &obj1, Fixed const &obj2)
{
	return (obj1.getRawBits() > obj2.getRawBits() ? obj1 : obj2);
}