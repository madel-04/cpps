/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:24:43 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/15 13:24:43 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::string x = "HI THIS IS BRAIN";
    std::string* stringPTR = &x; // Pointer stores the address of x
    std::string& stringREF = x; // Reference stores the address of x

    std::cout << "Memory address of the string variable: " << &x << std::endl;
    std::cout << "Memory address held by stringPTR:      " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF:      " << &stringREF << std::endl;

    std::cout << "Value of the string variable:          " << x << std::endl;
    std::cout << "Value pointed to by stringPTR:         " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF:         " << stringREF << std::endl;

    return 0;
}