/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytext.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:55:42 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 21:22:39 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	coordinate_texture(t_info *info, int drawstart)
{
	if (info->vec.side == 0)
		info->txt.wallx = info->vec.posy + info->vec.perpwalldist
		* info->vec.raydiry;
	else
		info->txt.wallx = info->vec.posx + info->vec.perpwalldist
		* info->vec.raydirx;
	info->txt.wallx -= floor(info->txt.wallx);
	info->txt.texx = (int)(info->txt.wallx * (double)TEXWIDTH);
	if (info->vec.side == 0 && info->vec.raydirx > 0)
		info->txt.texx = TEXWIDTH - info->txt.texx - 1;
	if (info->vec.side == 1 && info->vec.raydiry < 0)
		info->txt.texx = TEXWIDTH - info->txt.texx - 1;
	info->txt.step = 1.0 * TEXHEIGHT / info->txt.lineheight;
	info->txt.texpos = (drawstart - info->height / 2 + info->txt.lineheight / 2)
	* info->txt.step;
}

void		texture_cast(t_info *info, int drawstart, int drawend, int y)
{
	unsigned int	color;
	int				x;

	coordinate_texture(info, drawstart);
	x = drawstart - 1;
	while (++x < drawend)
	{
		info->txt.texy = (int)info->txt.texpos & (TEXHEIGHT - 1);
		info->txt.texpos += info->txt.step;
		if (info->vec.side == 0 && info->vec.raydirx > 0)
			color = info->texture[2][TEXHEIGHT * info->txt.texy
			+ info->txt.texx];
		if (info->vec.side == 0 && info->vec.raydirx < 0)
			color = info->texture[3][TEXHEIGHT * info->txt.texy
			+ info->txt.texx];
		if (info->vec.side == 1 && info->vec.raydiry > 0)
			color = info->texture[0][TEXHEIGHT * info->txt.texy
			+ info->txt.texx];
		if (info->vec.side == 1 && info->vec.raydiry < 0)
			color = info->texture[1][TEXHEIGHT * info->txt.texy
			+ info->txt.texx];
		if (info->vec.side == 1)
			color = (color >> 1) & 8355711;
		info->buffer[y][x] = color;
	}
}
