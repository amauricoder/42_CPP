/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:12:10 by aconceic          #+#    #+#             */
/*   Updated: 2025/02/10 17:52:41 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/**********************************************/
/*                   FUNCTIONS                */
/**********************************************/

/*              ARGUMENT TREATMENT            */

bool	is_argument_valid(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
		return (failure_msg("Error!\nInvalid Argument.", false));

	std::string arg = argv[1];
	if (arg.empty() || arg.find_first_not_of(" \t\n\r\f\v") == std::string::npos)
		return (failure_msg("Error!\nEmpty Argument.", false));
		
	std::string valid_chars = " +-/*";
	for (int i = 0; argv[1][i] != '\0'; i++) {
		if (std::isdigit(argv[1][i]) && std::isdigit(argv[1][i + 1]) && argv[1][i] != '0')
			return failure_msg("Error!\nInvalid Argument.", false);
		if (!(std::isdigit(argv[1][i]) || valid_chars.find(argv[1][i]) != std::string::npos))
			return failure_msg("Error!\nInvalid Argument.", false);
	}
	return (true);
}

/*              RPN              */

int do_rpn(std::string expr)
{
	std::stack<int> s;
	int				expr_nbr;
	std::string operators = "+-/*";

	for (int i = 0; expr[i] != '\0'; i ++)
	{
		if (std::isdigit(expr[i]))
		{
			expr_nbr = std::atoi(expr.substr(i, i+1).c_str());
			s.push(expr_nbr);
		}
		if (operators.find(expr[i]) != std::string::npos)
		{
			if (s.size() < 2)
				return (failure_msg("Error!\nInvalid Expression.", EXIT_FAILURE));
			do_operation(expr[i], s);
		}
	}
	if (s.size() > 1)
				return (failure_msg("Error!\nInvalid Expression.", EXIT_FAILURE));
	print_stack(s);
	return (EXIT_SUCCESS);
}

void	do_operation(char op, std::stack<int> &s)
{
	int		new_value = 0;
	int		second_value = 0;

	new_value = s.top();
	s.pop();
	if (op == '+')
	{
		new_value += s.top();
		s.pop();
	}
	else if (op == '*')
	{
		new_value *= s.top();
		s.pop();
	}
	else if (op == '/')
	{
		second_value = s.top();
		s.pop();
		if (new_value == 0)
			exit(failure_msg("Error\nNaN.", EXIT_FAILURE));
		new_value = second_value / new_value;
	}
	else if (op == '-')
	{
		second_value = s.top();
		s.pop();
		new_value = second_value - new_value;
	}
	s.push(new_value);
}

/**********************************************/
/*               DEBUG / ERROR MSG            */
/**********************************************/

void	print_stack(std::stack<int> s)
{
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();	
	}
	std::cout << std::endl;
}

int	success_msg(std::string name)
{
	std::cout << BG_GREEN << name << " SUCESS!" RESET << std::endl;
	return (EXIT_SUCCESS);
}

int	failure_msg(std::string msg, int ret_value)
{
	std::cerr << msg << std::endl;
	return (ret_value);
}