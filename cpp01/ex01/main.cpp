/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:37:57 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/15 12:37:57 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    std::string name = "JD";

    Zombie* horde = zombieHorde(N, name);
    if (!horde)
    {
        std::cerr << "Failed to create zombie horde." << std::endl;
        return 1;
    }
    for (int i = 0; i < N; ++i)
    {
        horde[i].announce();
    }
    delete[] horde;
    // Memory cleanup
    return 0;
}
