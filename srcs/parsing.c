/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:54:19 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 21:55:20 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	save_map(t_list *token, t_info *info)
{
	int		i;

	info->map_h = size_map(token);
	if ((info->map = (char **)malloc(sizeof(char *) * info->map_h)) == NULL)
		return (0);
	i = 0;
	while (token != NULL)
	{
		if (is_line_map(token->str))
			if ((info->map[i++] = ft_strdup(token->str)) == NULL)
				return (0);
		token = token->next;
	}
	return (1);
}

static int	save_color(t_list *token, t_info *info)
{
	char **tab;
	char *tmp;

	tmp = token->next->next->str;
	if (ft_strcmp(tmp, "\n") != 0 && check_id(tmp, 0) == -1)
		return (0);
	if (verif_color(token->next->str) == 0)
		return (0);
	if ((tab = ft_split(token->next->str, ",")) == NULL)
		return (0);
	if (ft_strcmp(token->str, "F") == 0)
	{
		info->color.floor = ft_atoi(tab[0]);
		info->color.floor = info->color.floor << 8 | ft_atoi(tab[1]);
		info->color.floor = (info->color.floor << 8 | ft_atoi(tab[2]));
	}
	else
	{
		info->color.ceiling = 0 | ft_atoi(tab[0]);
		info->color.ceiling = info->color.ceiling << 8 | ft_atoi(tab[1]);
		info->color.ceiling = info->color.ceiling << 8 | ft_atoi(tab[2]);
	}
	free_split(tab);
	return (1);
}

static int	save_path(t_list *token, t_info *info)
{
	if (ft_strcmp("NO", (char *)token->str) == 0)
		if ((info->path.north = ft_strdup(token->next->str)) == NULL)
			return (0);
	if (ft_strcmp("SO", (char *)token->str) == 0)
		if ((info->path.south = ft_strdup(token->next->str)) == NULL)
			return (0);
	if (ft_strcmp("WE", (char *)token->str) == 0)
		if ((info->path.west = ft_strdup(token->next->str)) == NULL)
			return (0);
	if (ft_strcmp("EA", (char *)token->str) == 0)
		if ((info->path.east = ft_strdup(token->next->str)) == NULL)
			return (0);
	if (ft_strcmp("S", (char *)token->str) == 0)
		if ((info->path.sprite = ft_strdup(token->next->str)) == NULL)
			return (0);
	return (1);
}

static int	save_resolution(t_list *token, t_info *info)
{
	if (str_num(token->next->str) == 0)
		return (0);
	token = token->next;
	if (ft_strlen(token->str) > 5)
		token->str[5] = '\0';
	info->width = ft_atoi(token->str);
	if (info->width <= 0)
		return (0);
	if (str_num(token->next->str) == 0)
		return (0);
	token = token->next;
	if (ft_strlen(token->str) > 5)
		token->str[5] = '\0';
	info->height = ft_atoi(token->str);
	if (info->height <= 0)
		return (0);
	if (ft_strcmp(token->next->str, "\n") != 0)
		return (0);
	return (1);
}

int			parse_tokens(t_list *token, t_info *info)
{
	int		(*f_save[4])(t_list *, t_info *);
	int		count;

	f_save[0] = save_resolution;
	f_save[1] = save_path;
	f_save[2] = save_color;
	f_save[3] = save_map;
	count = 0;
	while (token != NULL && count < 8)
	{
		if (check_id(token->str, 0) != -1)
		{
			if ((f_save[traduct_count(token->str)](token, info)) == 0)
				return (0);
			count++;
		}
		token = token->next;
	}
	while (token != NULL && !is_line_map(token->str))
		token = token->next;
	if ((f_save[3](token, info)) == 0)
		return (0);
	return (1);
}
