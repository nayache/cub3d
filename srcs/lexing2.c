/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:52:01 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 21:55:03 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_list	*requiered_id(t_list *token)
{
	const char	requiered[8][3] = {"R\0", "NO\0", "SO\0", "WE\0", "EA\0", "S\0",
	"F\0", "C\0"};
	int			i;

	if (token->str == NULL)
		return (NULL);
	if (check_occurence(token->str, requiered, 8) == -1)
		return (NULL);
	i = 1;
	while (token != NULL && i < 8)
	{
		if (ft_strcmp(token->str, "\n") == 0)
		{
			if (token->next == NULL)
				return (NULL);
			token = token->next;
			if (check_occurence(token->str, requiered, 8) == -1)
				return (NULL);
			i++;
		}
		token = token->next;
	}
	return (token);
}

static int		requiered_map(t_list *token)
{
	while (token->next != NULL && token->str[0] != '\n')
		token = token->next;
	if (token->str[0] == '\n' && token->next != NULL)
		token = token->next;
	else
		return (0);
	while (token != NULL)
	{
		if (!is_line_map(token->str) && ft_strcmp(token->str, "\n") != 0)
			return (0);
		token = token->next;
	}
	return (1);
}

static int		check_color(t_list *token)
{
	while (token != NULL)
	{
		if (ft_strcmp(token->str, "F") == 0 || ft_strcmp(token->str, "C") == 0)
		{
			token = token->next;
			if (ft_strcmp(token->next->str, "\n") != 0)
				return (0);
			if (verif_color(token->str) == 0)
				return (0);
		}
		token = token->next;
	}
	return (1);
}

static int		check_resolution(t_list *token)
{
	while (token != NULL)
	{
		if (ft_strcmp(token->str, "R") == 0)
		{
			token = token->next;
			if (only_num(token->str) == 0)
				return (0);
			token = token->next;
			if (only_num(token->str) == 0)
				return (0);
			if (ft_strcmp(token->next->str, "\n") != 0)
				return (0);
		}
		token = token->next;
	}
	return (1);
}

int				check_tokens(t_list *token)
{
	t_list *tmp;

	tmp = requiered_id(token);
	if (tmp == NULL)
		return (0);
	if (requiered_map(tmp) == 0)
		return (0);
	if (check_color(token) == 0)
		return (0);
	if (check_resolution(token) == 0)
		return (0);
	return (1);
}
