/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:26:23 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/22 20:20:36 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <sstream>

//Value return
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
//Colors
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define RESET       "\033[0m"

template <class T>
class Array
{
	private:
		T				*_arr;
		unsigned int	_arr_size;
	public:
	//Orthodox
		Array();
		Array(const Array &src);
		Array& operator=(const Array &src);
		~Array();
	
	//Other constructors
		Array(unsigned int n);
		T&	operator[](unsigned int index);
	
	//member function
		unsigned int	size(void) const;
	
	//Exception
	class OutOfBounds : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class EmptyArray : public std::exception
	{
		public:
			virtual const char *what() const throw();	
	};
};

//TESTS FUNCTIONS
int	test_constructor_no_paramether(void);
int	test_constructor_int_number(void);
int	err_invalid_test(std::string test_name, int line, const char* file);
int	err_msg(std::string msg, int status, int line, const char* file);

#include "Array.tpp"

#endif
