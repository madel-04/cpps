/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:09:23 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/14 20:09:23 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <sstream>

static std::string promptNonEmpty(const std::string& field) {
    std::string s;
    while (true) {
        std::cout << field << ": ";
        if (!std::getline(std::cin, s))
            return "";
        if (!s.empty())
            return s;
        std::cout << "  [ERROR] El campo no puede estar vacío.\n";
    }
}

int main() {
    PhoneBook   phonebook;
    std::string cmd;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd))
            break;
        if (cmd == "EXIT")
            break;
        else if (cmd == "ADD") {
            Contact c;
            if (!c.setFirstName   ( promptNonEmpty("First Name"   ) )) continue;
            if (!c.setLastName    ( promptNonEmpty("Last Name"    ) )) continue;
            if (!c.setNickname    ( promptNonEmpty("Nickname"     ) )) continue;
            if (!c.setPhoneNumber ( promptNonEmpty("Phone Number" ) )) continue;
            if (!c.setDarkestSecret( promptNonEmpty("Darkest Secret") )) continue;
            phonebook.addContact(c);
        }
        else if (cmd == "SEARCH") {
            if (phonebook.size() == 0) {
                std::cout << "[INFO] No hay contactos.\n";
                continue;
            }
            phonebook.displayList();
            std::cout << "Index to display: ";
            std::string idxs;
            if (!std::getline(std::cin, idxs)) break;
            std::istringstream iss(idxs);
            int idx;
            if (!(iss >> idx) || !iss.eof()) {
                std::cout << "[ERROR] Índice inválido.\n";
                continue;
            }
            if (!phonebook.displayContact(idx))
                std::cout << "[ERROR] Índice inválido.\n";
        }
        else {
            std::cout << "[ERROR] Comando no reconocido.\n";
        }
    }
    std::cout << "Goodbye!\n";
    return 0;
}
