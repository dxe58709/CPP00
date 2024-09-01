/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:42:37 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/01 18:15:43 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <vector>
# include <iostream>
# include <string>
# include <iomanip>

class PhoneBook
{
	private:
		std::vector<Contact> contacts;
		std::string getInputString(const std::string &prompt);
		static std::string truncateString(const std::string &str);

	public:
	void	addContact();
	void	searchContact() const;
	void	displayContacts() const;
};

#endif
