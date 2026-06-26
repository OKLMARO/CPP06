/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 09:02:15 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/26 09:07:53 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data* original = new Data();
	uintptr_t raw = Serializer::serialize(original);
	Data* result = Serializer::deserialize(raw);
	if (original == result)
		std::cout << "VRAI !\n";
	else
		std::cout << "FAUX !\n";
	return (0);
}
