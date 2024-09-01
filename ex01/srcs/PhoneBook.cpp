/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:42:42 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/02 00:06:14 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

using std::string;
using std::cout;
using std::endl;
using std::setw;

PhoneBook::PhoneBook() : ContactCount(0) {}

string	PhoneBook::getInputString(const std::string &prompt) {
	string	input;
	
	while (true) {
		cout << prompt;
		getline(std::cin, input);//Enterキー押すまでの入力全体を文字列としてinputに格納
		if (std::cin.eof()) {
			cout << "Error: End of Input detected.\n";
			exit (1);
		}
		if (std::cin.fail()) {
			cout << "Error: Failed to input\n";
			exit (1);
		}
		if (input.empty()) {
			cout << "Error: Input empty. Please enter again.\n";
			continue;
		}
		break ;
	}
	return input;
}

void	PhoneBook::addContact() {
	Contact	newContact;
	string	input;

	if (ContactCount >= MAX_CONTACTS) {
		unsigned int	i = 1;
		while (i < MAX_CONTACTS) {
			i++;
			contacts[i - 1] = contacts[i];
		}
		--ContactCount;
	}

	input = getInputString("First Name: ");
	newContact.setFirstName(input);
	input = getInputString("Last Name: ");
	newContact.setLastName(input);
	input = getInputString("Nickname: ");
	newContact.setNickname(input);
	input = getInputString("Phone Number: ");
	newContact.setPhoneNumber(input);
	input = getInputString("Darkest Secret: ");
	newContact.setDarkestSecret(input);

	contacts[ContactCount++] = newContact;
	cout << "Contact added successfully.\n";
}

void	PhoneBook::searchContact() const {
	if (ContactCount == 0) {
		cout << "Error: PhoneBook is empty.\n";
		return ;
	}
	displayContacts();
	//ユーザーに表示したい連絡先の 表番号を入力させる
	cout << "Enter the index of the contact to view details: ";
	unsigned int	i;
	std::cin >> i;//ユーザーが入力した番号が入る
	if (std::cin.fail() || i < 1 || i > ContactCount) {
		cout << "Error: Invalid index.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 改行を取り除く
		return ;
	}
	//インデックスが有効な場合、連絡先の詳細を表示
	const Contact &contact = contacts[i - 1];
    cout << "First Name: " << contact.getFirstName() << endl;
    cout << "Last Name: " << contact.getLastName() << endl;
    cout << "Nickname: " << contact.getNickname() << endl;
    cout << "Phone Number: " << contact.getPhoneNumber() << endl;
    cout << "Darkest Secret: " << contact.getDarkestSecret() << endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// 改行を取り除く
}

void	PhoneBook::displayContacts() const {
	unsigned int	i;

	cout << setw(10) << "Index" << "|"
		 << setw(10) << "First Name" << "|"
		 << setw(10) << "Last Name" << "|"
		 << setw(10) << "Nickname" << endl;
	i = 0;
	while (i < ContactCount) {
		i++;
		cout << setw(10) << i << "|"
			 << setw(10) << truncateString(contacts[i - 1].getFirstName()) << "|"
			 << setw(10) << truncateString(contacts[i - 1].getLastName()) << "|"
			 << setw(10) << truncateString(contacts[i - 1].getNickname()) << endl;
	}
}

std::string PhoneBook::truncateString(const std::string &str) {
	if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}
