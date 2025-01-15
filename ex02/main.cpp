/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:29:27 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/15 16:02:37 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Base.hpp"
#include "utils.hpp"

//new concept - dynamic_cast<type>(var)
//The dynamic_cast in C++ is a powerful feature used for safe runtime polymorphism and type conversion.
int main(void)
{
	//uncomment lines below to run tests
	/* if (test_instanciate_Base() || test_instanciate_ABC())
		return (FAIL);

	test_identify_ptr_a();
	test_identify_ptr_b();
	test_identify_ptr_c();
	test_identify_ref_a();
	test_identify_ref_b();
	test_identify_ref_c();
	test_identify_unknown(); */

	Base *misterious_type = generate();
	identify(misterious_type);
	identify(*misterious_type);
	return (0);
}
