/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:48:45 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 19:49:14 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ceiling(t_info *info, t_element *draw_tab)
{
	int y;
	int	start;

	y = 0;
	while (y < info->width)
	{
		start = 0;
		while (start < draw_tab[y].start)
		{
			pixel_put(info->win.img, start * info->sl + y * 4,
			(char *)&info->color.ceiling, info->endian);
			start++;
		}
		y++;
	}
}

static void	draw_walls(t_info *info, t_element *draw_tab)
{
	int	y;
	int	start;
	int	end;

	y = 0;
	while (y < info->width)
	{
		start = draw_tab[y].start;
		end = draw_tab[y].end;
		while (start < end)
		{
			pixel_put(info->win.img, start * info->sl + y * 4,
			(char *)info->buffer[y] + start * 4,
			info->endian);
			start++;
		}
		y++;
	}
}

static void	draw_floor(t_info *info, t_element *draw_tab)
{
	int	y;
	int	start;

	y = 0;
	while (y < info->width)
	{
		start = draw_tab[y].end + 1;
		while (start < info->height)
		{
			pixel_put(info->win.img, start * info->sl + y * 4,
			(char *)&info->color.floor, info->endian);
			start++;
		}
		y++;
	}
}

void		draw(t_info *info, t_element *draw_tab)
{
	draw_ceiling(info, draw_tab);
	draw_walls(info, draw_tab);
	draw_floor(info, draw_tab);
}
