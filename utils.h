/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:04:50 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/13 12:04:52 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H
# define WIDTH_SPT 50
# define HEIGHT_SPT 50

# include "mlx_linux/mlx.h"
# include "gnl/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_map
{
	char	**map;
	char	**back_map;
	int		row_map;
	int		column_map;
	int		base;
	int		player_pos;
	int		items;
	int		exits;
	int		outsider;
}				t_map;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_player{
	t_img	up;
	t_img	left;
	t_img	down;
	t_img	rigth;
	int		px_player;
	int		py_player;
	int		steps;
	int		spt_move;
}				t_player;

typedef struct s_sprites{
	t_img		wall;
	t_img		floor;
	t_img		door;
	t_img		item;
	t_img		hostil;
	t_player	player;
}				t_sprites;

typedef struct s_win {
	void		*mlx;
	void		*win;
	t_map		*mlmap;
	t_sprites	*mlspt;
	int			height;
	int			width;
	float		reset_spt;
}				t_win;

int		ft_read_map(char *file, t_map *map);
int		ft_start_game(t_win *mlx);
int		actions(int keycode, t_win *mlx);
int		render_map(t_win *mlx, int p_direction);
void	init_var_map(t_map *map);
int		free_map(t_map *map);
int		error_map(int index_error, t_map *map);
int		make_backup_map(t_map *map);
void	reset_game(t_win *mlx);
int		ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);

#endif
