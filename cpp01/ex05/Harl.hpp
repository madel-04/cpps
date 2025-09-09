/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:24:53 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/16 13:24:53 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <string>
# include <iostream>

class Harl
{
    public:
        void complain(std::string level);

    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
};

#endif