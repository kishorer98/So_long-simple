/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:31:34 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/14 15:37:42 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(int argc, char *argv[])
{
	t_map		map;
	t_sprites	spt;
	t_win		mlx;
	int			return_map;

	if (argc < 2)
		return (error_map(4, &map));
	if (argc > 2)
		return (error_map(7, &map));
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == 0)
		return (error_map(5, &map));
	init_var_map(&map);
	return_map = ft_read_map(argv[1], &map);
	if (return_map > 0)
		return (error_map(return_map, &map));
	mlx.mlmap = &map;
	mlx.mlspt = &spt;
	mlx.width = WIDTH_SPT * map.column_map;
	mlx.height = HEIGHT_SPT * map.row_map;
	ft_start_game(&mlx);
	free_map(&map);
	return (0);
}
