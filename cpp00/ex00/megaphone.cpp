/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:28:37 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/18 18:28:37 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else
    {
        for (int i = 1; i < argc; ++i)
        {
            for (int j = 0; argv[i][j]; ++j)
                std::cout << (char)std::toupper(argv[i][j]);
            if (i < argc - 1)
                std::cout << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
