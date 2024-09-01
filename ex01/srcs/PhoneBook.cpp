/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:42:42 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/01 21:44:08 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

using std::string;
using std::cout;
using std::endl;
using std::setw;

string	PhoneBook::getInputString(const std::string &prompt) {
	string	input;
	
	while (1) {
		cout << prompt;
		getline(std::cin, input);//Enterキー押すまでの入力全体を文字列としてinputに格納
		if (std::cin.eof()) {
			cout << "Error: End of Input detected.\n";
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

	if (contacts.size() >= 8) {
		contacts.erase(contacts.begin());//contactsの一番最初の要素(一番古い連絡先)を削除
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

	contacts.push_back(newContact);
	cout << "Contact added successfully.\n";
}

void	PhoneBook::searchContact() const {
	if (contacts.empty()) {
		cout << "Error: PhoneBook is empty.\n";
		return ;
	}
	displayContacts();
	//ユーザーに表示したい連絡先のインデックスを入力させる
	cout << "Enter the index of the contact to view details: ";
	int	index;
	std::cin >> index;//ユーザーが入力した番号が入る
	if (std::cin.fail() || index < 1 || index > static_cast<int>(contacts.size())) {
		cout << "Error: Invalid index.\n";
		std::cin.clear();//入力エラーをクリア
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 改行を取り除く
		cout << "Error: Invalid command. Please try again.\n";
		return ;
	}
	//インデックスが有効な場合、連絡先の詳細を表示
	const Contact &contact = contacts[index - 1];
    cout << "First Name: " << contact.getFirstName() << endl;
    cout << "Last Name: " << contact.getLastName() << endl;
    cout << "Nickname: " << contact.getNickname() << endl;
    cout << "Phone Number: " << contact.getPhoneNumber() << endl;
    cout << "Darkest Secret: " << contact.getDarkestSecret() << endl;
}

void	PhoneBook::displayContacts() const {
	size_t	i;

	cout << setw(10) << "Index" << "|"
		 << setw(10) << "First Name" << "|"
		 << setw(10) << "Last Name" << "|"
		 << setw(10) << "Nickname" << endl;
	i = 0;
	while (i < contacts.size()) {
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
