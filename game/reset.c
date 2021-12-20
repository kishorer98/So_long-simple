/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:42:03 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/13 01:28:41 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static	void	reset_var_game(t_win *mlx)
{
	mlx->mlspt->player.steps = 0;
	mlx->mlspt->player.spt_move = 1;
}

static	void	reset_map(t_map *map)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	if (map->items != 0)
		map->items = 0;
	while (y < map->row_map)
	{
		while (x < map->column_map)
		{
			map->map[y][x] = map->back_map[y][x];
			if (map->map[y][x] == 'C')
				map->items++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	reset_game(t_win *mlx)
{
	reset_var_game(mlx);
	reset_map(mlx->mlmap);
}
