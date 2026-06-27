/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:23:38 by oamairi           #+#    #+#             */
/*   Updated: 2026/06/27 14:45:27 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base
{
public:
	virtual ~Base();
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);
