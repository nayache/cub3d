/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:02:22 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 20:02:24 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_pos	*add_pos_sprite(t_pos *list)
{
	t_pos	*new;

	new = (t_pos *)malloc(sizeof(t_pos));
	if (new == NULL)
		return (0);
	new->y = -1;
	new->x = -1;
	while (list->next != NULL)
		list = list->next;
	list->next = new;
	new->next = NULL;
	return (new);
}

static int		numbers_sprite(char **map, int size, t_pos *list)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '2')
			{
				if (count > 0)
					if ((list = add_pos_sprite(list)) == NULL)
						return (-1);
				list->y = i;
				list->x = j;
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

static int		get_tab_sprite(t_pos *sprite_position, int size, t_info *info)
{
	int		i;
	t_pos	*tmp;

	info->size_sprite = size;
	info->sprite = (t_sprite *)malloc(sizeof(t_sprite) * size);
	if (info->sprite == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		info->sprite[i].y = sprite_position->y;
		info->sprite[i].x = sprite_position->x;
		tmp = sprite_position;
		sprite_position = sprite_position->next;
		free(tmp);
		i++;
	}
	return (1);
}

int				save_sprites(t_info *info)
{
	int		size;
	t_pos	*sprite_position;

	sprite_position = (t_pos *)malloc(sizeof(t_pos));
	if (sprite_position == NULL)
		return (0);
	sprite_position->next = NULL;
	size = numbers_sprite(info->map, info->map_h, sprite_position);
	if (size == -1)
		return (0);
	if (get_tab_sprite(sprite_position, size, info) == 0)
		return (0);
	return (1);
}
