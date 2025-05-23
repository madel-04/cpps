/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:12:39 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/15 17:12:39 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <string>
# include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(const std::string &name);
        void setWeapon(Weapon &Weapon);
        void attack() const;
    private:
        std::string _name;
        Weapon *_weapon;

};

# endif
