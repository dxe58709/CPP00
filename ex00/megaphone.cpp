/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:41:45 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/18 14:17:03 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	ft_upper(const char *str){
	int	i;
	if (str == NULL)
		return;
	i = 0;
	while (str[i]) {
		std::cout << (char)std::toupper(str[i]);
		i++;
	}
}

int	main(int argc, char **argv){
	int	i;

	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	i = 1;
	while (i < argc) {
		ft_upper(argv[i]);
		i++;
	}
	std::cout << std::endl;
	return 0;
}
