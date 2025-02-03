/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:51:43 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/03 13:24:35 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/********************************/
/*           ORTHODOX           */
/********************************/
Span::Span()
{
	//std::cout << "Span Constructor" << std::endl;
}

Span::Span(const Span &src) : _maxqt(src._maxqt), _data(src._data)
{
	//std::cout << "Span Copy Constructor" << std::endl;
}

Span& Span::operator=(const Span &src)
{
	//std::cout << "Span Assignment Operator" << std::endl;
	if (this != &src)
	{
		this->_maxqt = src._maxqt;
		this->_data.clear();
		this->_data.insert(this->_data.end(), 
			src._data.begin(), src._data.end());
	}
	return (*this);
}

Span::~Span()
{
	//std::cout << "Span Destructor" << std::endl;
}

/********************************/
/*       OTHER CONSTRUCTOR      */
/********************************/

Span::Span(unsigned int N) : _maxqt(N)
{
	//std::cout << "Span U_Int Constructor" << std::endl;
}
/********************************/
/*            GETTER            */
/********************************/
const std::vector<int>& 	Span::getData(void) const
{
	return (this->_data);
};

const unsigned int& Span::getMaxQt(void) const
{
	return (this->_maxqt);
};

/********************************/
/*      MEMBER FUNCTIONS        */
/********************************/

void	Span::addNumber(int nbr)
{
	//std::cout << "addNumber Member Function" << std::endl;
	if (this->_maxqt == _data.size())
		throw MaxElementsStored();
	_data.push_back(nbr);
}

int		Span::shortestSpan(void)
{
	if (this->_data.size() < 2)
		throw NoRangeFound();
	std::vector<int> sorted = this->_data;
	std::sort(sorted.begin(), sorted.end());
	int	minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); i ++)
		minSpan = std::min(minSpan, sorted[i] - sorted[i - 1]);
	return (minSpan);
}

int		Span::longestSpan(void)
{
	if (this->_data.size() < 2)
		throw NoRangeFound();
	int maxVal = *std::max_element(this->_data.begin(), this->_data.end());
	int	minVal = *std::min_element(this->_data.begin(), this->_data.end());
	return (maxVal - minVal);
}

/********************************/
/*         		DEBUG           */
/********************************/
std::string	Span::ossSpan(void)
{
	std::ostringstream oss;

	for (std::vector<int>::iterator it = this->_data.begin(); it != this->_data.end(); it ++)
	{
		oss << (*it);
	}
	
	/* for (std::vector<int>::iterator it = this->_data.begin(); it != this->_data.end(); it ++)
	{
		std::cout << "Number: " << (*it) << std::endl;
	} */
	
	return (oss.str());
}

void	Span::printSpan(void)
{
	for (std::vector<int>::iterator it = this->_data.begin(); it != this->_data.end(); it ++)
	{
		std::cout << "Number: " << (*it) << std::endl;
	}
}

/********************************/
/*         EXCEPTIONS           */
/********************************/

const char * Span::MaxElementsStored::what(void) const throw()
{
	return ("Max Elements Stored!");
}

const char * Span::NoRangeFound::what(void) const throw()
{
	return ("No range found!");
}