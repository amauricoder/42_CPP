/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:51:57 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/12 13:39:25 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "tests.hpp"

int main(void)
{
	test_instantiate_abstract_class();
	test_inherit_dog_make_sound();
	test_filling_brain_with_ideas();
	test_cat_ideas();
	test_dog_ideas();
	test_half_cats_and_dogs_in_array();
	test_deep_copies();
	test_brain_constructor_and_deep_copies();
	test_assign_dog();
	test_deep_dog();
	return (0);
}