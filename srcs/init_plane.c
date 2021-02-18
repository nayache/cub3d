/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:27:21 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 19:34:50 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_plane(t_vector *vec, double y, double px, double py)
{
	vec->diry = y;
	vec->planex = px;
	vec->planey = py;
}

void		init_start_camera(t_vector *vec, int c)
{
	if (c == 'N')
	{
		vec->dirx = 0.00;
		init_plane(vec, -1.00, 0.60, 0.00);
	}
	if (c == 'S')
	{
		vec->dirx = 0.00;
		init_plane(vec, 1.00, -0.60, 0.00);
	}
	if (c == 'W')
	{
		vec->dirx = -1.00;
		init_plane(vec, 0.00, 0.00, -0.60);
	}
	if (c == 'E')
	{
		vec->dirx = 1.00;
		init_plane(vec, 0.00, 0.00, 0.60);
	}
}
