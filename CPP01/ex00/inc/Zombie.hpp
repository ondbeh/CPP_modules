/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:00:13 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/29 16:19:02 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# define ENDL std::endl

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie(const std::string& name);
	~Zombie();
	void	announce() const;
};

Zombie* newZombie(const std::string& name);
void	randomChump(const std::string& name);


#endif
