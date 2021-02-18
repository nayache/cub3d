/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:06:10 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 20:11:03 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	save_start_pos(char **map, int y, int x, t_vector *vec)
{
	init_start_camera(vec, map[y][x]);
	vec->posy = (double)y + 0.5;
	vec->posx = (double)x + 0.5;
	map[y][x] = '0';
	return (1);
}

int			check_start_pos(char **map, int size, t_vector *vec)
{
	int y;
	int x;
	int	view_pos;

	y = 0;
	view_pos = 0;
	while (y < size)
	{
		x = 0;
		while (map[y][x])
		{
			if (is_pos(map[y][x]))
			{
				view_pos++;
				if (view_pos > 1)
					return (error("Too many starting positions in the map."));
				save_start_pos(map, y, x, vec);
			}
			x++;
		}
		y++;
	}
	if (view_pos < 1)
		return (error("no starting position found."));
	return (1);
}
