/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:50:16 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 21:55:41 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_color(t_info *info)
{
	info->color.ceiling = mlx_get_color_value(info->win.mlx_ptr,
	info->color.ceiling);
	info->color.floor = mlx_get_color_value(info->win.mlx_ptr,
	info->color.floor);
}

void	pixel_put(char *img, int x, char *color, int endian)
{
	img[x] = color[0];
	img[x + 1] = color[1];
	img[x + 2] = color[2];
	img[x + 3] = endian;
}

void	free_split(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		size_map(t_list *token)
{
	int		size;

	size = 0;
	while (token != NULL)
	{
		if (is_line_map(token->str))
			size++;
		token = token->next;
	}
	return (size);
}
