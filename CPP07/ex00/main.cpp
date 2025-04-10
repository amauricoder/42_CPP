/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:26:08 by aconceic          #+#    #+#             */
/*   Updated: 2025/01/20 14:35:28 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
	if (test_max_int_positive() || test_max_int_negative()
		|| test_max_int_positive_and_negative() || test_max_int_same_value()
		|| test_min_int_positive() || test_min_int_negative()
		|| test_min_int_positive_and_negative() || test_min_int_same_value()
		|| test_swap_int() || test_max_double_positive()
		|| test_max_double_negative() || test_max_double_positive_and_negative()
		|| test_max_double_same_value() || test_swap_double()
		|| test_max_int_ptr_pos())
		return (err_msg("Error tests", EXIT_FAILURE, __LINE__, __FILE__));
	test_subject();
	return (0);
}

/**********************************/
/*             TESTS              */
/**********************************/
int	test_max_int_positive(void)
{
	std::cout << BG_BLUE "1 - test_max_int_positive" RESET << std::endl;
	int a = 10;
	int b = 12;

	int c = max(a, b);
	/* std::cout << "b value: " << b << std::endl;
	std::cout << "c value: " << c << std::endl; */
	if (c != b)
		return (err_invalid_test("test_max_int_positive", __LINE__, __FILE__));
	std::cout << BG_BLUE "END 1 - test_max_int_positive" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_max_int_negative(void)
{
	std::cout << BG_GREEN "2 - test_max_int_negative" RESET << std::endl;
	int a = -20;
	int b = -10;

	int c = max(a, b);
	/* std::cout << "b value: " << b << std::endl;
	std::cout << "c value: " << c << std::endl; */
	if (c != b)
		return (err_invalid_test("test_max_int_negative", __LINE__, __FILE__));
	std::cout << BG_GREEN "END 2 - test_max_int_negative" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_max_int_positive_and_negative(void)
{
	std::cout << BG_MAGENTA "3 - test_max_int_positive_and_negative" RESET << std::endl;
	int a = -20;
	int b = 20;

	int c = max(a, b);
	/* std::cout << "b value: " << b << std::endl;
	std::cout << "c value: " << c << std::endl; */
	if (c != b)
		return (err_invalid_test("test_max_int_positive_and_negative", __LINE__, __FILE__));
	std::cout << BG_MAGENTA "END 3 - test_max_int_positive_and_negative" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_max_int_same_value(void)
{
	std::cout << BG_BLUE "4 - test_max_int_same_value" RESET << std::endl;
	int a = 10;
	int b = 10;

	int c = max(a, b);
	/* std::cout << "a value: " << a << std::endl;
	std::cout << "b value: " << b << std::endl;
	std::cout << "c value: " << c << std::endl; */
	if (c != b || c != a)
		return (err_invalid_test("test_max_int_same_value", __LINE__, __FILE__));
	std::cout << BG_BLUE "END 4 - test_max_int_same_value" RESET << std::endl;
	return (EXIT_SUCCESS);
}

//MIN
int	test_min_int_positive(void)
{
	std::cout << BG_ORANGE "5 - test_min_int_positive" RESET << std::endl;
	int a = 10;
	int b = 12;

	int c = min(a, b);
	/* std::cout << "b value: " << a << std::endl;
	std::cout << "c value: " << c << std::endl; */
	if (c != a)
		return (err_invalid_test("test_min_int_positive", __LINE__, __FILE__));
	std::cout << BG_ORANGE "END 5 - test_min_int_positive" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_min_int_negative(void)
{
	std::cout << BG_GREEN "6 - test_min_int_negative" RESET << std::endl;
	int a = -20;
	int b = -10;

	int c = min(a, b);
	/* std::cout << "b value: " << a << std::endl;
	std::cout << "c value: " << c << std::endl; */
	if (c != a)
		return (err_invalid_test("test_min_int_negative", __LINE__, __FILE__));
	std::cout << BG_GREEN "END 6 - test_min_int_negative" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_min_int_positive_and_negative(void)
{
	std::cout << BG_MAGENTA "7 - test_min_int_positive_and_negative" RESET << std::endl;
	int a = -20;
	int b = 20;

	int c = min(a, b);
	/* std::cout << "b value: " << a << std::endl;
	std::cout << "c value: " << c << std::endl; */
	if (c != a)
		return (err_invalid_test("test_min_int_positive_and_negative", __LINE__, __FILE__));
	std::cout << BG_MAGENTA "END 7 - test_min_int_positive_and_negative" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_min_int_same_value(void)
{
	std::cout << BG_BLUE "8 - test_min_int_same_value" RESET << std::endl;
	int a = 10;
	int b = 10;

	int c = min(a, b);
	/* std::cout << "a value: " << a << std::endl;
	std::cout << "b value: " << b << std::endl;
	std::cout << "c value: " << c << std::endl; */
	if (c != b || c != a)
		return (err_invalid_test("test_min_int_same_value", __LINE__, __FILE__));
	std::cout << BG_BLUE "END 8 - test_min_int_same_value" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_swap_int(void)
{
	std::cout << BG_GREEN "9 - test_swap_int" RESET << std::endl;
	int	a = 13;
	int	b = 42;

	int a_initial = a;
	int b_initial = b;

	std::cout << "a before swap: " << a << std::endl;
	std::cout << "b before swap: " << b << std::endl;
	swap(a, b);
	std::cout << "a after swap: " << a << std::endl;
	std::cout << "b after swap: " << b << std::endl;
	if (a == a_initial || b == b_initial)
		return (err_invalid_test("test_swap_int", __LINE__, __FILE__));
	std::cout << BG_GREEN "END 9 - test_swap_int" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_max_double_positive(void)
{
	std::cout << BG_BLUE "10 - test_max_double_positive" RESET << std::endl;
	double a = 10.254;
	double b = 12.123;

	double c = max(a, b);
	/* std::cout << "b value: " << b << std::endl;
	std::cout << "c value: " << c << std::endl; */
	if (c != b)
		return (err_invalid_test("test_max_double_positive", __LINE__, __FILE__));
	std::cout << BG_BLUE "END 10 - test_max_double_positive" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_max_double_negative(void)
{
	std::cout << BG_GREEN "11 - test_max_double_negative" RESET << std::endl;
	double a = -20.256;
	double b = -10.235;

	double c = max(a, b);
	/* std::cout << "b value: " << b << std::endl;
	std::cout << "c value: " << c << std::endl; */
	if (c != b)
		return (err_invalid_test("test_max_double_negative", __LINE__, __FILE__));
	std::cout << BG_GREEN "END 11 - test_max_double_negative" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_max_double_positive_and_negative(void)
{
	std::cout << BG_MAGENTA "12 - test_max_double_positive_and_negative" RESET << std::endl;
	double a = -20.123;
	double b = 20.123;

	double c = max(a, b);
	/* std::cout << "b value: " << b << std::endl;
	std::cout << "c value: " << c << std::endl; */
	if (c != b)
		return (err_invalid_test("test_max_double_positive_and_negative", __LINE__, __FILE__));
	std::cout << BG_MAGENTA "END 12 - test_max_double_positive_and_negative" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_max_double_same_value(void)
{
	std::cout << BG_BLUE "13 - test_max_double_positive_and_negative" RESET << std::endl;
	double a = 10.4242;
	double b = 10.4242;

	double c = max(a, b);
	/* std::cout << "a value: " << a << std::endl;
	std::cout << "b value: " << b << std::endl;
	std::cout << "c value: " << c << std::endl; */
	if (c != b || c != a)
		return (err_invalid_test("test_max_double_positive_and_negative", __LINE__, __FILE__));
	std::cout << BG_BLUE "END 13 - test_max_double_positive_and_negative" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_swap_double(void)
{
	std::cout << BG_GREEN "14 - test_swap_double" RESET << std::endl;
	double	a = 13.1245;
	double	b = 42.12;

	double a_initial = a;
	double b_initial = b;

	std::cout << "a before swap: " << a << std::endl;
	std::cout << "b before swap: " << b << std::endl;
	swap(a, b);
	std::cout << "a after swap: " << a << std::endl;
	std::cout << "b after swap: " << b << std::endl;
	if (a == a_initial || b == b_initial)
		return (err_invalid_test("test_swap_double", __LINE__, __FILE__));
	std::cout << BG_GREEN "END 14 - test_swap_double" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_max_int_ptr_pos(void)
{
	std::cout << BG_MAGENTA "15 - test_max_int_ptr_pos" RESET << std::endl;
	int	a = 1;
	int	b = 200;

	int *d = &a;
	int	*e = &b;

	int c = max(*d, *e);
	std::cout << "a value: " << a << std::endl;
	std::cout << "b value: " << b << std::endl;
	std::cout << "c value: " << c << std::endl;
	std::cout << "d value: " << *d << std::endl;
	std::cout << "e value: " << *e << std::endl;
	
	if (c != *e || c != b)
		return (err_invalid_test("test_max_int_ptr_pos", __LINE__, __FILE__));
	std::cout << BG_MAGENTA "END 15 - test_max_int_ptr_pos" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	test_subject(void)
{
	std::cout << BG_MAGENTA "16 - test_subject" RESET << std::endl;
	std::ostringstream oss;
	std::ostringstream oss_tocompare;

	int a = 2;
	int b = 3;
	::swap( a, b );
	oss << "a = " << a << ", b = " << b << std::endl;
	oss << "min(a, b) = " << ::min(a, b) << std::endl;
	oss << "max(a, b) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	oss << "c = " << c << ", d = " << d << std::endl;
	oss << "min(c, d) = " << ::min(c, d) << std::endl;
	oss << "max(c, d) = " << ::max(c, d) << std::endl;

	oss_tocompare << "a = 3, b = 2" << std::endl;
	oss_tocompare << "min(a, b) = 2" << std::endl;
	oss_tocompare << "max(a, b) = 3" << std::endl;
	oss_tocompare << "c = chaine2, d = chaine1" << std::endl;
	oss_tocompare << "min(c, d) = chaine1" << std::endl;
	oss_tocompare << "max(c, d) = chaine2" << std::endl;
	
	//std::cout << "OSS 1" << std::endl;
	if (oss.str() != oss_tocompare.str())
		return (err_invalid_test("test_subject", __LINE__, __FILE__));
	std::cout << oss.str() << std::endl;
	std::cout << BG_MAGENTA "16 - test_subject" RESET << std::endl;
	return (EXIT_FAILURE);
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