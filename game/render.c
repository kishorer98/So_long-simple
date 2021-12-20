/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:01:20 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/13 01:28:02 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static	void	print_image(t_win *mlx, t_img *img, int count, int index)
{
	if (count < 0 || index < 0)
		return ;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img,
		WIDTH_SPT * count, HEIGHT_SPT * index);
}

static	void	choice_img(t_win *win, t_img *p_spt, int count, int index)
{
	if (win->mlmap->map[index][count] == '0')
		print_image(win, &win->mlspt->floor, count, index);
	else if (win->mlmap->map[index][count] == '1')
		print_image(win, &win->mlspt->wall, count, index);
	else if (win->mlmap->map[index][count] == 'C')
		print_image(win, &win->mlspt->item, count, index);
	else if (win->mlmap->map[index][count] == 'E')
		print_image(win, &win->mlspt->door, count, index);
	else if (win->mlmap->map[index][count] == 'H')
		print_image(win, &win->mlspt->hostil, count, index);
	else if (win->mlmap->map[index][count] == 'P')
	{
		win->mlspt->player.py_player = index;
		win->mlspt->player.px_player = count;
		print_image(win, p_spt, count, index);
	}
}

static	void	render(t_win *win, t_img *p_spt, int count, int index)
{
	char	*n_steps;

	n_steps = ft_itoa(win->mlspt->player.steps);
	while (index++ < win->mlmap->row_map - 1)
	{
		while (count++ < win->mlmap->column_map - 1)
		{
			choice_img(win, p_spt, count, index);
			mlx_string_put(win->mlx, win->win, 25, 25,
				15921152, "Curent steps: ");
			mlx_string_put(win->mlx, win->win, 120, 25, 15921152, n_steps);
		}
		count = -1;
	}
	free(n_steps);
}

int	render_map(t_win *mlx, int p_direction)
{
	if (p_direction == 1)
		render(mlx, &mlx->mlspt->player.down, -1, -1);
	else if (p_direction == 2)
		render(mlx, &mlx->mlspt->player.up, -1, -1);
	else if (p_direction == 3)
		render(mlx, &mlx->mlspt->player.left, -1, -1);
	else if (p_direction == 4)
		render(mlx, &mlx->mlspt->player.rigth, -1, -1);
	return (0);
}
