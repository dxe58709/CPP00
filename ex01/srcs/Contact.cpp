/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:56:48 by nsakanou          #+#    #+#             */
/*   Updated: 2024/11/16 13:53:04 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

using std::string;

Contact::Contact()
{
}

Contact::~Contact()
{
}

//getName
string Contact::getFirstName() const{
	return (this->firstName);
}

string Contact::getLastName() const{
	return (this->lastName);
}

string Contact::getNickname() const{
	return (this->nickname);
}

string Contact::getPhoneNumber() const{
	return (this->phoneNumber);
}

string Contact::getDarkestSecret() const{
	return (this->darkestSecret);
}

//setName
void	Contact::setFirstName(std::string newFirstName){
	this->firstName = newFirstName;
}

void	Contact::setLastName(std::string newLastName){
	this->lastName = newLastName;
}

void	Contact::setNickname(std::string newNickname){
	this->nickname = newNickname;
}

void	Contact::setPhoneNumber(std::string newPhoneNumber){
	this->phoneNumber = newPhoneNumber;
}

void	Contact::setDarkestSecret(std::string newDarkestSecret){
	this->darkestSecret = newDarkestSecret;
}
