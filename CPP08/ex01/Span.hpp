/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:51:45 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/04 11:33:36 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <sstream>
#include <limits>

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
		unsigned int		_maxqt;
		std::vector<int>	_data;
	public:
		//Orthodox
		Span(const Span &src);
		Span& operator=(const Span &src);
		~Span();
		//Other constructor
		Span(unsigned int N);
		//getter
		const std::vector<int>&	getData(void) const;
		const unsigned int& getMaxQt(void)const;
		//Member function
		void				addNumber(int nbr);
		int					shortestSpan(void);
		int					longestSpan(void);
		//debug
		std::string			ossSpan(void);
		void				printSpan(void);
		//exceptions
		class MaxElementsStored : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class NoRangeFound : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
		//template
		template <typename IT>
		void	addRange(IT begin, IT end)
		{
			if (_data.size() + std::distance(begin, end) > this->_maxqt)
				throw MaxElementsStored();
			_data.insert(this->_data.end(), begin, end);
		}
};

//TESTS
int test_subject(void);
int	test_addRange_1(void);
int	test_addRange_2(void);
int	test_addRange_3(void);
int	test_span_10000(void);
int	test_shortestSpan_1(void);
int	test_shortestSpan_2(void);
int	test_longestSpan_1(void);
int	test_longestSpan_2(void);
int	test_copy_constructor(void);
int	test_copy_assignment(void);
int	err_invalid_test(std::string test_name, int line, const char* file);
int	success_msg(std::string msg);
#endif