/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:56:23 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 19:59:51 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	it_close(char *str)
{
	while (is_space(*str))
		str++;
	if (*str != '1')
		if (*str == '\0')
			return (0);
	while (is_valid(*str))
	{
		if (!is_valid(*(str + 1)) && *str != '1')
			return (0);
		str++;
	}
	if (*str)
		it_close(str);
	return (1);
}

static int	full_wall(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			if (!is_space(str[i]))
				return (0);
		i++;
	}
	return (1);
}

int			check_wall(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (i == 0 || i == size - 1)
			if (!full_wall(map[i]))
				return (0);
		if (!it_close(map[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	find_opening(char **map, int y, int x)
{
	if (!map[y - 1][x] || !(map[y - 1][x] == '0' || map[y - 1][x] == '1' ||
		map[y - 1][x] == '2'))
		return (1);
	if (!map[y + 1][x] || !(map[y + 1][x] == '0' || map[y + 1][x] == '1' ||
		map[y + 1][x] == '2'))
		return (1);
	if (!map[y - 1][x] || !(map[y][x - 1] == '0' || map[y][x - 1] == '1' ||
		map[y][x - 1] == '2'))
		return (1);
	if (!map[y - 1][x] || !(map[y][x + 1] == '0' || map[y][x + 1] == '1' ||
		map[y][x + 1] == '2'))
		return (1);
	return (0);
}

int			check_opening(char **map, int size)
{
	int y;
	int	x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == '2')
				if (find_opening(map, y, x))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}
