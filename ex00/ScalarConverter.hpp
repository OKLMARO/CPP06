/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:00:08 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/25 19:02:18 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <climits>
#include <cstdlib>
#include <iostream>

typedef enum e_type
{
	INT,
	INF,
	CHAR,
	ERROR,
	FLOAT,
	DOUBLE,
}	t_type;

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &obj);
	ScalarConverter	&operator=(const ScalarConverter &obj);

	static t_type	getType(std::string str);
	static void		printAllType(std::string str, t_type type);

	~ScalarConverter();
public:
	static void	convert(std::string str);
};
