/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:20:16 by nsakanou          #+#    #+#             */
/*   Updated: 2024/11/16 14:16:58 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "PhoneBook.hpp"

int main(){
	PhoneBook	PhoneBook;
	std::string	command;

	while (1) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return (0);
		}
		if (command == "ADD") {
			PhoneBook.addContact();
		} else if (command == "SEARCH") {
			PhoneBook.searchContact();
		} else if (command == "EXIT") {
			std::cout << "EXIT" << std::endl;
			break ;
		} else {
			std::cout << "Error: Invalid command. Please try again.\n";
		}
	}
	return 0;
}
