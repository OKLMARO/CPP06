/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:27:43 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/25 19:04:05 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
		ScalarConverter::convert(av[1]);
	else
	{
		std::cerr << "Usage: ./convert <element>\n";
		return (1);
	}
	return (0);
}
