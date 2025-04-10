/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:46:52 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/04 12:33:50 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

/****************************************************************/
/*                         ORTHODOX                             */
/****************************************************************/

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src)
{
	this = src;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &src)
{
	if (this != &src)
	{
		this->c = src.c;
	}
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{}

/****************************************************************/
/*                         ITERATORS                            */
/****************************************************************/

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

#endif