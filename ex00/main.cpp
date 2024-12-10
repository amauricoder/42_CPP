/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:51:57 by aconceic          #+#    #+#             */
/*   Updated: 2024/12/10 18:22:57 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "tests.hpp"

int main(void)
{
	test_dog_make_sound();
	test_cat_make_sound();
	test_animal_make_sound();
	test_inherit_dog_make_sound();
	test_inherit_cat_make_sound();
	test_subject();
	test_wrong_animal();
	return (0);
}