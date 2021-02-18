/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:50:33 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 21:55:51 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		error(char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	ft_putchar('\n');
	return (0);
}

void	print_map(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

int		save_to_list(t_list *token, char **tab)
{
	int i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
	{
		if (token->str == NULL)
		{
			token->str = ft_strdup(tab[i++]);
			if (token->str == NULL)
				return (0);
		}
		else
		{
			if (lst_add(token, tab[i++]) == 0)
				return (0);
		}
	}
	if (lst_add(token, "\n") == 0)
		return (0);
	return (1);
}

void	init_distance(double *dist, t_info *info, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		dist[i] = ((info->vec.posy - info->sprite[i].y) * (info->vec.posy -
		info->sprite[i].y) + (info->vec.posx - info->sprite[i].x) *
		(info->vec.posx - info->sprite[i].x));
		i++;
	}
}
