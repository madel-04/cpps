/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:04:20 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/14 20:04:20 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
    Contact _contacts[8];
    int _count;
public:
    PhoneBook();
    ~PhoneBook();

    void addContact(const Contact &newContact);
    void displayList() const;
    bool displayContact(int index) const;
    int size() const;
};

#endif
