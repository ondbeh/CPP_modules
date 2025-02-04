/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:14:58 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/04 11:20:01 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB() {}

HumanB &HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	return (*this);
}

HumanB &HumanB::attack()
{
	if (weapon == NULL)
		std::cout << name << " has no weapon to attack with" << std::endl;
	else
		std::cout << name << " attacks with his " << weapon->getType() << std::endl;
	return (*this);
}
