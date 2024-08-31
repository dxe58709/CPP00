/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:41:45 by nsakanou          #+#    #+#             */
/*   Updated: 2024/08/31 17:01:45 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv){
	size_t	i;
	size_t	j;

	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	i = 1;
	while (argv[i]) {
		j = 0;
		while (argv[i][j]){
			std::cout << argv[i][j];
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}
