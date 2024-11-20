/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:31:02 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/20 15:49:47 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int   Fixed::_fract_bits = 8;

Fixed::Fixed() : _fixed_point(0)
{
	std::cout << "Default Constructor Called" << std::endl;
}

//Convets an INT to a fix point
//This is the same as x * 2 ^ _fract_bits
Fixed::Fixed(const int x)
{
	std::cout << "Int Constructor Called" << std::endl;
	_fixed_point = x << _fract_bits;
}

//Converts a float to a fix point
//This is the same as x * 2 ^ _fract_bits
Fixed::Fixed(const float x)
{
	std::cout << "Float Constructor Called" << std::endl;
	_fixed_point = x * roundf((1 << _fract_bits));
}

//Copy Construcor
Fixed::Fixed(const Fixed &obj)
{    
	std::cout << "Copy Constructor Called" << std::endl;
	_fixed_point = obj.getRawBits();
}

//Copy assignment operator
Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_fixed_point = src.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor Called" << std::endl;
}

//Member Functions

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point = raw;	
}

float   Fixed::toFloat(void) const
{
	return (float)this->_fixed_point / (float)(1 << _fract_bits);
}

int     Fixed::toInt(void) const
{
	return (this->_fixed_point >> Fixed::_fract_bits);
}

std::ostream&	operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}