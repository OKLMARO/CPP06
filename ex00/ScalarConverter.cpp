/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:03:01 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/25 19:16:52 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {(void) obj;}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &obj) {(void) obj; return *this;}

t_type	ScalarConverter::getType(std::string str)
{
	t_type	type = ERROR;
	if (str.size() == 3 && str[0] == 39 && str[2] == 39)
		return CHAR;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return INF;
	else if (str[0] == '-' || std::isdigit(str[0]))
	{
		for (size_t i = 1; i < str.size(); i++)
		{
			if (std::isdigit(str[i]) == false || type == DOUBLE)
			{
				if (std::isdigit(str[i]) == false && type == DOUBLE && str[i] != 'f')
					return ERROR;
				if (str[i] == '.' || type == DOUBLE)
				{
					type = DOUBLE;
					if (str[i] == 'f')
					{
						if (i + 1 == str.size())
							return FLOAT;
						return ERROR;
					}
					if (i + 1 == str.size())
						return DOUBLE;
				}
				else
					return ERROR;
			}
		}
		return INT;
	}
	return ERROR;
}

void	ScalarConverter::printChar(std::string str, t_type type)
{
	if (type == INT || type == FLOAT || type == DOUBLE)
	{
		long long num = std::atoll(str.c_str());
		if (num >= 0 && num <= 127)
		{
			if ((num >= 0 && num <= 31) || num == 127)
			{
				std::cout << "char: Non displayable\n";
				return ;
			}
			std::cout << "char: '" << (char) num << "'\n";
			return ;
		}
	}
	else if (type == CHAR)
	{
		std::cout << "char: " << str << "\n";
		return ;
	}
	std::cout << "char: impossible\n";
}

void	ScalarConverter::printInt(std::string str, t_type type)
{
	if (type == INT || type == FLOAT || type == DOUBLE)
	{
		long long num = std::atoll(str.c_str());
		if (num <= INT_MAX && num >= INT_MIN)
		{
			std::cout << "int: " << num <<"\n";
			return ;
		}
		std::cout << "int: impossible\n";
		return ;
	}
	else if (type == CHAR)
	{
		std::cout << "int: " << (int) str[1] <<"\n";
		return ;
	}
	std::cout << "int: impossible\n";
}

void	ScalarConverter::printFloat(std::string str, t_type type)
{
	if (type == INT || type == FLOAT || type == DOUBLE)
	{
			std::cout << "float: " << str <<"\n";
			return ;
	}
	else if (type == CHAR)
	{
		std::cout << "float: " << (int) str[1] <<"\n";
		return ;
	}
	else if (type == INF)
	{
		std::cout << "float: nanf\n";
		return ;
	}
	std::cout << "float: impossible\n";
}

void	ScalarConverter::printDouble(std::string str, t_type type)
{
	if (type == INT || type == FLOAT || type == DOUBLE)
	{
			std::cout << "double: " << str.substr(0, str.size() - 1) <<"\n";
			return ;
	}
	else if (type == CHAR)
	{
		std::cout << "double: " << (int) str[1] <<"\n";
		return ;
	}
	else if (type == INF)
	{
		std::cout << "double: nan\n";
		return ;
	}
	std::cout << "double: impossible\n";
}

void	ScalarConverter::printAllType(std::string str, t_type type)
{
	printChar(str, type);
	printInt(str, type);
	printFloat(str, type);
	printDouble(str, type);
}

void	ScalarConverter::convert(std::string str)
{
	printAllType(str, getType(str));
}

ScalarConverter::~ScalarConverter() {};
