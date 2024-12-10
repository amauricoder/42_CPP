/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:51:57 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/10 19:21:23 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "tests.hpp"

int main(void)
{
	test_inherit_dog_make_sound();
	test_filling_brain_with_ideas();
	test_cat_ideas();
	test_dog_ideas();
	test_half_cats_and_dogs_in_array();
	test_deep_copies();
	test_brain_constructor();
	test_assign_dog();
	test_deep_dog();
	return (0);
}