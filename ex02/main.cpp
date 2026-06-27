/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:39:54 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/27 15:07:02 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "A.hpp"
#include "B.hpp"
#include "C.hpp"*/
#include <cstdlib>
#include <iostream>
#include "Base.hpp"

Base	*generate(void)
{
	int	r = rand() % 3;
	if (r == 0)
		return new A();
	if (r == 1)
		return new B();
	return new C();
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "is A !\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "is B !\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "is C !\n";
}

void	identify(Base &p)
{
	try {(void) dynamic_cast<A&>(p); std::cout << "is A !\n";} catch(const std::exception& e){}
	try {(void) dynamic_cast<B&>(p); std::cout << "is B !\n";} catch(const std::exception& e){}
	try {(void) dynamic_cast<C&>(p); std::cout << "is C !\n";} catch(const std::exception& e){}
}

int	main(void)
{
	srand(time(NULL));
	Base*	obj = generate();

	identify(obj);
	identify(*obj);

	delete obj;
	return 0;
}
