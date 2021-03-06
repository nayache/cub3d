/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:47:37 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 19:48:37 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_swap_double(double *a, double *b)
{
	double	c;

	c = *a;
	*a = *b;
	*b = c;
}

void		sort_sprites(double *dist, t_info *info, int size)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (dist[i] < dist[j])
			{
				ft_swap_double(dist + i, dist + j);
				tmp = info->sprite[i];
				info->sprite[i] = info->sprite[j];
				info->sprite[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
