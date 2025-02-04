/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:08:49 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/04 11:15:59 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {}

HumanA &HumanA::attack()
{
	std::cout << name << " attacks with his " << weapon.getType() << std::endl;
	return (*this);
}
