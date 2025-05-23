/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:59:40 by madel-va          #+#    #+#             */
/*   Updated: 2025/05/14 19:59:40 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
private:
    std::string	_firstName;
    std::string	_lastName;
    std::string	_nickname;
    std::string	_phoneNumber;
    std::string	_darkestSecret;

public:
    Contact();
    ~Contact();

    bool        setFirstName(const std::string &firstName);
    bool        setLastName(const std::string &lastName);
    bool        setNickname(const std::string &nickname);
    bool        setPhoneNumber(const std::string &phoneNumber);
    bool        setDarkestSecret(const std::string &darkestSecret);

    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getNickname() const;
    const std::string &getPhoneNumber() const;
    const std::string &getDarkestSecret() const;
};

#endif
