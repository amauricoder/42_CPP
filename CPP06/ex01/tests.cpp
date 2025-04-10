/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:18:56 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/12 13:03:08 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Serializer.hpp"
#include <sstream>

//The ptr address must be the same after calling deserialize
int	test_compare_data_address()
{
	std::cout << BG_BLUE "1 test_compare_data_address" RESET << std::endl;
	Data *d;
	Data *new_d;
	uintptr_t raw;
	
	d = new Data;
	d->id = 1;
	d->str = "Data String!";
	
	raw = Serializer::serialize(d);
	std::cout << "Raw number :" << raw << std::endl;
	new_d = Serializer::deserialize(raw);

	if (d != new_d)
	{
		delete d;
		return (err_invalid_test("test_compare_data_address()", __LINE__, __FILE__));
	}
	std::cout << "Data of d: " << d << std::endl;
	std::cout << "Data of new_d " << new_d << std::endl;
	std::cout << BG_BLUE "SUCCESS 1 test_compare_data_address" RESET << std::endl;
	delete d;
	return (SUCCESS);
}

//The content must be the same
int	test_compare_content()
{
	std::cout << BG_GREEN "2 test_compare_content" RESET << std::endl;
	Data *d;
	Data *new_d;
	uintptr_t raw;
	int	compare_string;

	d = new Data;
	d->id = 1;
	d->str = "String!";
	
	raw = Serializer::serialize(d);
	new_d = Serializer::deserialize(raw);

	compare_string = d->str.compare(new_d->str);
	if (compare_string != 0 || d->id != new_d->id)
	{
		delete d;
		return (err_invalid_test("test_compare_content()", __LINE__, __FILE__));
	}
	std::cout << "STR of d: " << d->str << std::endl;
	std::cout << "ID of d: " << d->id << std::endl;
	std::cout << "STR of new_d: " << new_d->str << std::endl;
	std::cout << "ID of new_d: " << new_d->id << std::endl;
	std::cout << BG_GREEN "SUCCESS 2 test_compare_content" RESET << std::endl;
	delete d;
	return (SUCCESS);
}

//The address must not change
int	test_using_same_ptr()
{
	std::cout << BG_MAGENTA "3 test_using_same_ptr()" RESET << std::endl;
	Data 		*d;
	Data		*backup;
	uintptr_t 	raw;

	d = new Data;
	d->id = 1;
	d->str = "String!";
	
	backup = d;
	std::cout << "Data of d Before serialization: " << d << std::endl;
	raw = Serializer::serialize(d);
	d = Serializer::deserialize(raw);
	if (backup != d)
	{
		delete d;	
		return (err_invalid_test("test_using_same_ptr()", __LINE__, __FILE__));
	}
	std::cout << "Data of d After deserialize: " << d << std::endl;
	std::cout << BG_MAGENTA "SUCCESS 3 test_using_same_ptr" RESET << std::endl;
	delete d;
	return (SUCCESS);
}

int	test_stress()
{
	std::cout << BG_ORANGE "4 test_stress()" RESET << std::endl;
	Data 		*d;
	Data		*backup;
	uintptr_t 	raw;

	d = new Data;
	d->id = 1;
	d->str = "String!";
	
	backup = d;
	std::cout << "Data of d Before test: " << d << std::endl;
	for (int i = 0; i <= 99; i ++)
	{
		d->id = i;
		std::stringstream ss;
		ss << "Stress level " << i;
		d->str = ss.str();

		std::cout << "STR of d: " << d->str << std::endl;
		std::cout << "ID of d: " << d->id << std::endl;
		raw = Serializer::serialize(d);
		d = Serializer::deserialize(raw);
	}
	if (backup != d)
	{
		delete d;
		return (err_invalid_test("test_stress()", __LINE__, __FILE__));
	}
	std::cout << "Data of d After test: " << d << std::endl;
	std::cout << BG_ORANGE "SUCCESS 4 test_stress" RESET << std::endl;
	delete d;
	return (SUCCESS);
}

/***********************************************/
/*               DEBUG/ERROR MESSAGE           */
/***********************************************/

int	err_invalid_test(std::string test_name, int line, const char* file)
{
	std::ostringstream oss;
	oss << line;

	std::cerr << BG_RED << test_name << RESET << std::endl;
	std::cerr << BG_RED  "Error! in line " 
		+ oss.str() << " in file " << file << RESET
	<< std::endl;

	return (EXIT_FAILURE);
}

//print error msg and return status
int	err_msg(std::string msg, int status, int line, const char* file)
{
	std::cerr << "Error! Line " << line << " file " << file << "\n" << msg << std::endl;
	return (status);
}
