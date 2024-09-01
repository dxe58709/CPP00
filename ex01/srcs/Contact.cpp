/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:56:48 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/01 18:11:02 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

using std::string;

//getName
string Contact::getFirstName() const{
	return firstName;
}

string Contact::getLastName() const{
	return lastName;
}

string Contact::getNickname() const{
	return nickname;
}

string Contact::getPhoneNumber() const{
	return phoneNumber;
}

string Contact::getDarkestSecret() const{
	return darkestSecret;
}

//setName
void	Contact::setFirstName(const std::string &newFirstName){
	firstName = newFirstName;
}

void	Contact::setLastName(const std::string &newLastName){
	lastName = newLastName;
}

void	Contact::setNickname(const std::string &newNickname){
	nickname = newNickname;
}

void	Contact::setPhoneNumber(const std::string &newPhoneNumber){
	phoneNumber = newPhoneNumber;
}

void	Contact::setDarkestSecret(const std::string &newDarkestSecret){
	darkestSecret = newDarkestSecret;
}
