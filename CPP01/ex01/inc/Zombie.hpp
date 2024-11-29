/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:00:13 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/29 17:12:15 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# define ENDL std::endl
# define HORDE_SIZE 10

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	Zombie(const std::string& name);
	~Zombie();
	void	announce() const;
	void	setName(const std::string& name);
};

Zombie*	zombieHorde(int N, const std::string name);

#endif
