/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:04:12 by obehavka          #+#    #+#             */
/*   Updated: 2025/02/04 11:00:05 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie() : name("Unnamed") {}

Zombie::Zombie(const std::string &name) : name(name) {}

Zombie::~Zombie()
{
	std::cout << name << "'s body has decayed" << ENDL;
}

void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << ENDL;
}

void Zombie::setName(const std::string &name)
{
	this->name = name;
}
