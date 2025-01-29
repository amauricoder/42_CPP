/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:51:45 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/29 22:22:59 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_ORANGE   "\033[48;5;202m"
#define BG_RED      "\033[41m"
#define RESET       "\033[0m"


class Span
{
	private:
		//garantee instantiation only with unsigned int
		Span();
		unsigned int		_N;
		std::vector<int>	_data;
	public:
		//Orthodox
		Span(const Span &src);
		Span& operator=(const Span &src);
		~Span();
		//Other constructor
		Span(unsigned int N);
		//Member function
		void	addNumber(int nbr);
		int		shortestSpan(void);
		int		longestSpan(void);
		//exceptions
		class MaxElementsStored : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class NoSpanFound : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
		//template function
		template <typename T>
		void	addNumber(T start, T end)
		{
			if (std::distance(start, end) + this->_data.size() > this->_N)
				throw MaxElementsStored();
			this->_data.insert(this->_data.end(), start, end);
		}
};

//TESTS
int test_subject(void);
int	err_invalid_test(std::string test_name, int line, const char* file);

#endif