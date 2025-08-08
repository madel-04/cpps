/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:03:09 by madel-va          #+#    #+#             */
/*   Updated: 2025/08/07 20:03:09 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot("May");
    ClapTrap robot2("JD");

    robot.attack("JD");
    robot2.takeDamage(3);
    robot2.beRepaired(5);
    robot.takeDamage(20);
    robot.attack("target2"); // sin vida
    robot.beRepaired(2);     // sin vida

    ClapTrap copyBot = robot2;
    copyBot.attack("May");

    return 0;
}
