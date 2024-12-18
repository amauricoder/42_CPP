/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:10:32 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/18 16:40:04 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "tests.hpp"
#include "utils.hpp"
#include <typeinfo> //for typeid
#include <limits> //for numeric limits
#include <cmath> //for std::isnan, std::isinf
#include <cctype> //to std::isalpha() and etc
#include <iomanip> // For setprecision
#include <cstdlib> //strtoold
enum 
{
	TYPE_CHAR = 0,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_N_INF,
	TYPE_P_INF,
	TYPE_NAN,
	TYPE_INVALID
};

#define INT_MAX 	std::numeric_limits<int>::max()
#define INT_MIN 	std::numeric_limits<int>::min()
#define FLOAT_MAX 	std::numeric_limits<float>::max()
#define DOUBLE_MAX 	std::numeric_limits<double>::max()
//#define FLOAT_MIN	std::numeric_limits<float>::min()
//#define DOUBLE_MIN	std::numeric_limits<double>::min()

class ScalarConverter
{
	private:
	//Orthodox
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter& operator=(const ScalarConverter &src);
		~ScalarConverter();
	public :
	//required
		static int convert(const std::string &literal);
};

#endif