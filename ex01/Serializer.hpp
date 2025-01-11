/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:30:36 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/11 15:07:10 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "Data.h"
#include <stdint.h> //for uintptr_t

class Serializer 
{
	private:
	//Orthodox - Non instanciable
		Serializer();
		Serializer(const Serializer &src);
		Serializer& operator=(const Serializer &src);
		~Serializer();
	public:
	//static methods
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif