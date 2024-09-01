/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:42:37 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/02 00:05:00 by nsakanou         ###   ########.fr       */
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
		static const int MAX_CONTACTS = 8;
		Contact contacts[MAX_CONTACTS];
		unsigned int	ContactCount;
		std::string getInputString(const std::string &prompt);
		static std::string truncateString(const std::string &str);

	public:
		PhoneBook();
		void	addContact();
		void	searchContact() const;
		void	displayContacts() const;
};

#endif
