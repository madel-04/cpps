/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:11:25 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/15 17:11:25 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 Implement a Weapon class that has:
 • Aprivate attribute type, which is a string.
 • AgetType() member function that returns a constant reference to type.
 • AsetType() member function that sets type using the new value passed as a pa
rameter.
*/

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
    public:
        Weapon(const std::string &type);
        const std::string &getType() const;
        void setType(const std::string &type);
    private:
        std::string _type;
};

#endif