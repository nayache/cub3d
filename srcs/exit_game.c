/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:54:53 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 21:54:53 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_list(t_list *token)
{
	t_list *tmp;

	while (token != NULL)
	{
		if (token->str != NULL)
			free(token->str);
		tmp = token;
		token = token->next;
		free(tmp);
	}
}

void	free_path(t_path *path)
{
	if (path->north != NULL)
		free(path->north);
	if (path->south != NULL)
		free(path->south);
	if (path->east != NULL)
		free(path->east);
	if (path->west != NULL)
		free(path->west);
	if (path->sprite != NULL)
		free(path->sprite);
}

void	free_buffer(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->width)
	{
		free(info->buffer[i]);
		i++;
	}
	free(info->buffer);
}

int		exit_game(t_info *info)
{
	mlx_destroy_image(info->win.mlx_ptr, info->ptrs[0]);
	mlx_destroy_image(info->win.mlx_ptr, info->ptrs[1]);
	mlx_destroy_image(info->win.mlx_ptr, info->ptrs[2]);
	mlx_destroy_image(info->win.mlx_ptr, info->ptrs[3]);
	mlx_destroy_image(info->win.mlx_ptr, info->ptrs[4]);
	mlx_destroy_image(info->win.mlx_ptr, info->win.img_ptr);
	if (info->screenshot == 0)
	{
		mlx_clear_window(info->win.mlx_ptr, info->win.win_ptr);
		mlx_destroy_window(info->win.mlx_ptr, info->win.win_ptr);
	}
	free_map(info->map, info->map_h);
	free_path(&(info->path));
	free(info->texture);
	free(info->ptrs);
	free(info->sprite);
	free_buffer(info);
	free(info->zbuffer);
	mlx_destroy_display(info->win.mlx_ptr);
	free(info->win.mlx_ptr);
	exit(0);
}
