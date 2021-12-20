/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 23:06:33 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/13 13:11:58 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "utils.h"

static	void	print_error(char *message)
{
	printf("\033[0;31m" " Error\n%s\n" "\033[0m", message);
}

int	error_map(int index_error, t_map *map)
{
	if (index_error == 1)
		print_error(">>>>Error to open the file!<<<<");
	if (index_error == 2)
	{
		free_map(map);
		print_error(">>>>Respect the rules of the map!<<<<");
	}
	if (index_error == 3)
		print_error(">>>>The map must be a perfect rectangular!<<<<");
	if (index_error == 4)
		print_error(">>>>Forgot to pass the map file!<<<<");
	if (index_error == 5)
		print_error(">>>>the file needs to be a .ber<<<<");
	if (index_error == 6)
	{
		free_map(map);
		print_error(">>>>Error in get space to the malloc!<<<<");
	}
	if (index_error == 7)
		print_error(">>>>a lot of arguments passing!!<<<<");
	return (1);
}
