/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:52:25 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 18:55:32 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include "libft.h"

static void	side_dist(t_info *info)
{
	if (info->vec.raydirx < 0)
	{
		info->vec.stepx = -1;
		info->vec.sidedistx = (info->vec.posx - info->vec.mapx)
			* info->vec.deltadistx;
	}
	else
	{
		info->vec.stepx = 1;
		info->vec.sidedistx = (info->vec.mapx + 1.0 - info->vec.posx)
			* info->vec.deltadistx;
	}
	if (info->vec.raydiry < 0)
	{
		info->vec.stepy = -1;
		info->vec.sidedisty = (info->vec.posy - info->vec.mapy)
			* info->vec.deltadisty;
	}
	else
	{
		info->vec.stepy = 1;
		info->vec.sidedisty = (info->vec.mapy + 1.0 - info->vec.posy)
			* info->vec.deltadisty;
	}
}

static void	dda_algorithm(t_info *info, int hit)
{
	while (hit == 0)
	{
		if (info->vec.sidedistx < info->vec.sidedisty)
		{
			info->vec.sidedistx += info->vec.deltadistx;
			info->vec.mapx += info->vec.stepx;
			info->vec.side = 0;
		}
		else
		{
			info->vec.sidedisty += info->vec.deltadisty;
			info->vec.mapy += info->vec.stepy;
			info->vec.side = 1;
		}
		if (info->map[info->vec.mapy][info->vec.mapx] == '1')
			hit = 1;
	}
	if (info->vec.side == 0)
		info->vec.perpwalldist = (info->vec.mapx - info->vec.posx +
		(1 - info->vec.stepx) / 2) / info->vec.raydirx;
	else
		info->vec.perpwalldist = (info->vec.mapy - info->vec.posy +
		(1 - info->vec.stepy) / 2) / info->vec.raydiry;
}

static void	save_coordinate(t_info *info, t_element *draw_tab, int y)
{
	int		drawstart;
	int		drawend;

	info->txt.lineheight = (int)(info->height / info->vec.perpwalldist);
	drawstart = -info->txt.lineheight / 2 + info->height / 2;
	drawend = info->txt.lineheight / 2 + info->height / 2;
	if (drawstart < 0)
		drawstart = 0;
	if (drawend >= info->height)
		drawend = info->height - 1;
	draw_tab[y].start = drawstart;
	draw_tab[y].end = drawend;
	info->zbuffer[y] = info->vec.perpwalldist;
}

static void	init_raycast(t_info *info, int x)
{
	info->vec.camerax = 2 * x / (double)info->width - 1;
	info->vec.raydirx = info->vec.dirx + info->vec.planex * info->vec.camerax;
	info->vec.raydiry = info->vec.diry + info->vec.planey * info->vec.camerax;
	info->vec.mapy = (int)info->vec.posy;
	info->vec.mapx = (int)info->vec.posx;
	info->vec.deltadistx = fabs(1 / info->vec.raydirx);
	info->vec.deltadisty = fabs(1 / info->vec.raydiry);
}

int			raycast(t_info *info)
{
	int			y;
	t_element	draw_tab[info->width];

	y = 0;
	event_key(info);
	while (y < info->width)
	{
		init_raycast(info, y);
		side_dist(info);
		dda_algorithm(info, 0);
		save_coordinate(info, draw_tab, y);
		texture_cast(info, draw_tab[y].start, draw_tab[y].end, y);
		y++;
	}
	draw(info, draw_tab);
	sprite_cast(info);
	if (info->screenshot == 1)
		return (0);
	mlx_put_image_to_window(info->win.mlx_ptr, info->win.win_ptr,
	info->win.img_ptr, 0, 0);
	return (0);
}
