/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:03:01 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/25 13:38:46 by oamairi          ###   ########.fr       */
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
				if (std::isdigit(str[i]) == false && type == DOUBLE)
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

void	ScalarConverter::convert(std::string str)
{
	std::cout << getType(str) << "\n";
}

ScalarConverter::~ScalarConverter() {};
