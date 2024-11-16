/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:42:42 by nsakanou          #+#    #+#             */
/*   Updated: 2024/11/16 14:10:22 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::print(int index)
{
	if (!this->contacts[index].getFirstName().size() && std::cout << "There is no contact at this index." << std::endl)
		return;

	std::cout << "First Name: "
			  << this->contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: "
			  << this->contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: "
			  << this->contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: "
			  << this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: "
			  << this->contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::addContact()
{
	std::string str;

	str = "";
	while (!std::cin.eof() && str == "" && std::cout << "ADD> first name>")
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].setFirstName(str);
	str = "";
	while (!std::cin.eof() && str == "" && std::cout << "ADD> last name>")
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].setLastName(str);
	str = "";
	while (!std::cin.eof() && str == "" && std::cout << "ADD> nickname>")
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].setNickname(str);
	str = "";
	while (!std::cin.eof() && str == "" && std::cout << "ADD> phone number>")
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].setPhoneNumber(str);
	str = "";
	while (!std::cin.eof() && str == "" && std::cout << "ADD> darkest secret>")
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].setDarkestSecret(str);
	this->index++;
}

std::string set10(std::string str)
{
	if (str.size() > 10)
	{
		str.resize(9);
		str += ".";
	}
	else
		while (str.size() < 10)
			str = " " + str;
	return (str);
}

void PhoneBook::searchContact()
{
	int index;
	std::string index_str;

	index = 0;
	if (this->index == 0 && std::cout << "There is no contact." << std::endl)
		return;
	while (++index <= this->index && index <= 8)
	{
		std::cout << "|" << set10(std::string(1, index + '0'));
		std::cout << "|" << set10(this->contacts[index - 1].getFirstName());
		std::cout << "|" << set10(this->contacts[index - 1].getLastName());
		std::cout << "|" << set10(this->contacts[index - 1].getNickname());
		std::cout << "|" << std::endl;
	}
	while (!std::cin.eof())
	{
		std::cout << "SEARCH> index>";
		if (std::getline(std::cin, index_str), index_str != "")
		{
			if (index_str.size() == 1 && '1' <= index_str[0] && index_str[0] <= '8')
			{
				index = index_str[0] - '0';
				this->print(index - 1);
				break;
			}
		}
		if (index_str != "")
			std::cout << "Wrong index." << std::endl;
	}
}
