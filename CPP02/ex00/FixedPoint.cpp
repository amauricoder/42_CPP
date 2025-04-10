/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPoint.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:03:33 by aconceic          #+#    #+#             */
/*   Updated: 2024/11/18 17:29:42 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FixedPoint.hpp"

const int FixedPoint::_fractional_bits = 8;

//Default constructor
FixedPoint::FixedPoint() : _fixed_pt_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @attention New concept!
 * @brief Copy constructor.
 */
FixedPoint::FixedPoint(const FixedPoint &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixed_pt_value = obj.getRawBits();
}

/**
 * @attention New concept!
 * @brief Copy assignment constructor.
 */
FixedPoint& FixedPoint::operator=(const FixedPoint &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_fixed_pt_value = src.getRawBits();
	}
	return (*this);	
}

//Destructor
FixedPoint::~FixedPoint()
{
	std::cout << "Destructor called" << std::endl;
}

//getter
int	FixedPoint::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_pt_value);
}

void	FixedPoint::setRawBits(int const raw)
{
	this->_fixed_pt_value = raw;	
}

