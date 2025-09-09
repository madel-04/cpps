/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:33:58 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/15 12:33:58 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <ostream>

class Zombie
{
    public:
        Zombie();
        Zombie(const std::string &name);
        ~Zombie();

        void setName(const std::string &name);
        void announce() const;

    private:
        std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
