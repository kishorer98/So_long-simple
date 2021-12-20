/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:04:53 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/23 23:16:51 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

// verify if the locale that the player want to go is free
// refresh the locale of the player
static void	verify_pos(t_win *mlx, int x, int y, int mark)
{
	int	px;
	int	py;

	px = mlx->mlspt->player.px_player;
	py = mlx->mlspt->player.py_player;
	if (mlx->mlmap->map[y][x] == '0' || mlx->mlmap->map[y][x] == 'C' ||
										mlx->mlmap->map[y][x] == 'P')
	{
		if (mlx->mlmap->map[y][x] == 'C')
			mlx->mlmap->items--;
		mlx->mlmap->map[py][px] = '0';
		mlx->mlmap->map[y][x] = 'P';
		if (mark == 1)
			mlx->mlspt->player.steps++;
	}
	else if (mlx->mlmap->map[y][x] == 'E' && mlx->mlmap->items == 0)
	{
		mlx->mlmap->map[py][px] = '0';
		mlx->mlspt->player.px_player = -1;
		mlx->mlspt->player.py_player = -1;
	}
	else if (mlx->mlmap->map[y][x] == 'H')
		reset_game(mlx);
}

//verify each key is pressed
static	int	check_key(int *x, int *y, int keycode, t_player *player)
{
	if (keycode == 97)
	{
		*x -= 1;
		player->spt_move = 3;
	}
	else if (keycode == 115)
	{
		*y += 1;
		player->spt_move = 1;
	}
	else if (keycode == 119)
	{
		*y -= 1;
		player->spt_move = 2;
	}
	else if (keycode == 100)
	{
		*x += 1;
		player->spt_move = 4;
	}
	else
		return (0);
	return (1);
}

//make actions of the player
int	actions(int keycode, t_win *mlx)
{
	int	mark;
	int	x;
	int	y;

	x = mlx->mlspt->player.px_player;
	y = mlx->mlspt->player.py_player;
	if (keycode == 65307)
	{
		free_map(mlx->mlmap);
		exit(0);
	}
	else if (keycode == 114)
		reset_game(mlx);
	else if (mlx->mlspt->player.py_player > 0
		&& mlx->mlspt->player.px_player > 0)
	{
		mark = check_key(&x, &y, keycode, &mlx->mlspt->player);
		verify_pos(mlx, x, y, mark);
	}
	return (0);
}
