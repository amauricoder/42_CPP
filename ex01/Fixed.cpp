/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:31:02 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/18 18:24:20 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int   Fixed::_fract_bits = 8;

Fixed::Fixed() : _fixed_point(0)
{
    std::cout << "Default Constructor Called" << std::endl;
}

Fixed::Fixed(const int x)
{
    _fixed_point = x * (1 << _fract_bits)
}

Fixed::Fixed(const Fixed &obj)
{    
    std::cout << "Copy Constructor Called" << std::endl;
    _fixed_point = obj.getRawBits();
}

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

//getter
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point = raw;	
}