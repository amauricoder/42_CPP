/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:51:43 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/29 22:23:20 by aconceic         ###   ########.fr       */
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

Span::Span(const Span &src) : _N(src._N), _data(src._data)
{
	//std::cout << "Span Copy Constructor" << std::endl;
}

Span& Span::operator=(const Span &src)
{
	//std::cout << "Span Assignment Operator" << std::endl;
	if (this != &src)
	{
		this->_N = src._N;
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

Span::Span(unsigned int N) : _N(N)
{
	//std::cout << "Span U_Int Constructor" << std::endl;
}

/********************************/
/*      MEMBER FUNCTIONS        */
/********************************/

void	Span::addNumber(int nbr)
{
	//std::cout << "addNumber Member Function" << std::endl;
	if (this->_N == _data.size())
		throw MaxElementsStored();
	_data.push_back(nbr);
}

int		Span::shortestSpan(void)
{
	if (this->_data.size() < 2)
		throw NoSpanFound();
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
		throw NoSpanFound();
	int maxVal = *std::max_element(this->_data.begin(), this->_data.end());
	int	minVal = *std::min_element(this->_data.begin(), this->_data.end());
	return (maxVal - minVal);
}

/********************************/
/*         EXCEPTIONS           */
/********************************/

const char * Span::MaxElementsStored::what(void) const throw()
{
	return ("Max Elements Stored!");
}

const char * Span::NoSpanFound::what(void) const throw()
{
	return ("No Span found!");
}