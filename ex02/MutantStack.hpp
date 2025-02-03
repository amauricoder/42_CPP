/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:46:54 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/03 21:46:34 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#define BG_GREEN    "\033[42m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_ORANGE   "\033[48;5;202m"
#define BG_RED      "\033[41m"
#define RESET       "\033[0m"

#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>

//stack<T>does not offers iterators, but
//the underlying container does.
//c is protected.
//https://www.cppreference.com/Cpp_STL_ReferenceManual.pdf
template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	//Orthodox
		MutantStack();
		MutantStack(const MutantStack &src);
		MutantStack<T>& operator=(const MutantStack<T> &src);
		~MutantStack();
	//typedef
		typedef typename std::stack<T>::container_type 			underlying_container;
		typedef typename underlying_container::const_iterator	const_iterator;
		typedef typename underlying_container::iterator 		iterator;
	//iterators
		const_iterator begin() const;
		const_iterator end() const;
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"

//tests
int	test_subject(void);
int	test_with_list(void);
int	test_print_using_iterator(void);

int	err_invalid_test(std::string test_name, int line, const char* file);
int	success_msg(std::string msg);
#endif