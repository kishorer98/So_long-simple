/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:03:38 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/13 01:16:45 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static	int	init_image(t_img *img, char *file, t_win *win)
{
	int	x;
	int	y;

	x = WIDTH_SPT;
	y = HEIGHT_SPT;
	img->img = mlx_xpm_file_to_image(win->mlx, file, &x, &y);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	return (0);
}

static	void	init_img(t_win *mlx)
{
	mlx->mlspt->player.steps = 0;
	mlx->mlspt->player.spt_move = 1;
	mlx->reset_spt = 0;
	init_image(&mlx->mlspt->door, "sprites/door.xpm", mlx);
	init_image(&mlx->mlspt->item, "sprites/item.xpm", mlx);
	init_image(&mlx->mlspt->player.down, "sprites/pdown.xpm", mlx);
	init_image(&mlx->mlspt->player.up, "sprites/pup.xpm", mlx);
	init_image(&mlx->mlspt->player.left, "sprites/pleft.xpm", mlx);
	init_image(&mlx->mlspt->player.rigth, "sprites/pright.xpm", mlx);
	init_image(&mlx->mlspt->wall, "sprites/wall.xpm", mlx);
	init_image(&mlx->mlspt->floor, "sprites/floor.xpm", mlx);
	init_image(&mlx->mlspt->hostil, "sprites/fire.xpm", mlx);
}

static int	close_win(t_win *mlx)
{
	free_map(mlx->mlmap);
	exit(0);
}

static int	rendermap(t_win *mlx)
{
	mlx->reset_spt += 0.1;
	if (mlx->reset_spt >= 30)
	{
		mlx->reset_spt = 0;
		mlx_clear_window(mlx->mlx, mlx->win);
	}
	render_map(mlx, mlx->mlspt->player.spt_move);
	return (0);
}

int	ft_start_game(t_win *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "SO_LONG");
	init_img(mlx);
	render_map(mlx, 1);
	mlx_hook(mlx->win, 17, 0, close_win, mlx);
	mlx_key_hook(mlx->win, actions, mlx);
	mlx_loop_hook(mlx->mlx, rendermap, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
