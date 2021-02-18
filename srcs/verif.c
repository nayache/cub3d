/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:45:49 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 19:46:25 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_path(char *path, char c)
{
	int fd;

	if ((fd = open(path, O_RDONLY)) == -1)
	{
		if (c == 'N')
			return (error("failed to load north texture."));
		if (c == 'S')
			return (error("failed to load south texture."));
		if (c == 'E')
			return (error("failed to load east texture."));
		if (c == 'W')
			return (error("failed to load west texture."));
		if (c == 'P')
			return (error("failed to load sprite texture."));
	}
	close(fd);
	return (1);
}

static int	verif_path(t_path path)
{
	if (!check_path(path.north, 'N'))
		return (0);
	if (!check_path(path.south, 'S'))
		return (0);
	if (!check_path(path.east, 'E'))
		return (0);
	if (!check_path(path.west, 'W'))
		return (0);
	if (!check_path(path.sprite, 'P'))
		return (0);
	return (1);
}

int			verif_datas(t_info *info)
{
	if (verif_path(info->path) == 0)
	{
		free(info->path.north);
		free(info->path.south);
		free(info->path.east);
		free(info->path.west);
		free(info->path.sprite);
		free(info->sprite);
		free_map(info->map, info->map_h);
		return (0);
	}
	if (verif_map(info->map, info->map_h, &info->vec) == 0)
	{
		free(info->path.north);
		free(info->path.south);
		free(info->path.east);
		free(info->path.west);
		free(info->path.sprite);
		free(info->sprite);
		free_map(info->map, info->map_h);
		return (0);
	}
	return (1);
}
