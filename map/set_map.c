/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:40:39 by jestevam          #+#    #+#             */
/*   Updated: 2021/08/23 23:14:32 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

//verify if is end of the line and put info into struct map;
static int	verify_number_column(char c, t_map *map)
{
	if (c != '\n' && map->row_map == 0)
		map->base++;
	if (c != '\n')
		map->column_map++;
	if (c == 'P')
		map->player_pos++;
	else if (c == 'C')
		map->items++;
	else if (c == 'E')
		map->exits++;
	else if (c != '1' && c != '0' && c != '\n' && c != 'H')
		map->outsider++;
	if (c == '\n')
	{
		if (map->base != map->column_map)
			return (-3);
		else
			map->column_map = 0;
		map->row_map++;
	}
	return (0);
}

//count the quantity of lines that map have
static int	count_lines(int fd, t_map *map)
{
	char	c;
	int		rslt;

	if (fd < 0)
		return (-1);
	rslt = read(fd, &c, 1);
	if (rslt < 0)
		return (-1);
	while (rslt > 0)
	{
		if (verify_number_column(c, map) < 0)
			return (-3);
		rslt = read(fd, &c, 1);
	}
	map->row_map++;
	if (map->base != map->column_map)
		return (-3);
	if (map->column_map < 3 || map->row_map < 3)
		return (-3);
	return (0);
}

//verify if my last line and first line is full 1
static int	verify_line(char *str)
{
	int	count;

	count = 0;
	while (str[count] != 0)
		if (str[count++] != '1')
			return (-2);
	return (0);
}

//verify if map have what is needed
static int	check_map(t_map *map)
{
	int	index;

	index = 0;
	while (index < map->row_map)
	{
		if (index == 0 || index == map->row_map - 1)
		{
			if (verify_line(map->map[index]) < 0)
				return (-2);
		}
		else
		{
			if (map->map[index][0] != '1' ||
				map->map[index][map->column_map - 1] != '1')
				return (-2);
		}
		index++;
	}
	if (map->exits <= 0 || map->items <= 0 || map->player_pos != 1
		|| map->outsider > 0)
		return (-2);
	return (0);
}

// read map and save in a table char ** if is all alright
// make backup for restart the game
int	ft_read_map(char *file, t_map *map)
{
	int		count;
	int		index;
	int		fd;

	index = 0;
	fd = open(file, O_RDONLY);
	count = count_lines(fd, map);
	close(fd);
	if (count < 0)
		return (count * -1);
	fd = open(file, O_RDONLY);
	map->map = ft_calloc(map->column_map * map->row_map + 1, sizeof(char));
	if (map->map == NULL)
		return (6);
	index = get_next_line(fd, &map->map[index++]);
	while (index < map->row_map)
		get_next_line(fd, &map->map[index++]);
	if (make_backup_map(map))
		return (-5);
	count = check_map(map);
	if (count < 0)
		return (count * -1);
	return (0);
}
