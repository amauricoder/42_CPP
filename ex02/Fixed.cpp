/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:50:45 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/20 19:12:50 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed() : _number(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
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

Fixed&	Fixed::operator=(Fixed &src)
{
	std::cout << "Assign constructor called" << std::endl;
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

int	Fixed::getRawBits(void)
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

std::ostream& operator<<(std::ostream& os, Fixed &obj)
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
