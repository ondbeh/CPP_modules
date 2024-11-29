/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:14:04 by obehavka          #+#    #+#             */
/*   Updated: 2024/11/29 17:07:24 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::cout << "Creating a horde of " << HORDE_SIZE << "zombies on the heap" << ENDL;
	Zombie* horde = zombieHorde(HORDE_SIZE, "Heapinator");
	for (int i = 0; i < HORDE_SIZE; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
