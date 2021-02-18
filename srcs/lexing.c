/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:51:47 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 21:55:30 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	save_tokens3(t_list *token, int fd, char *sep)
{
	char	*line;
	char	**tab;
	int		value;

	while ((value = get_next_line(fd, &line)) > -1)
	{
		if (is_line_map(line) == 0)
		{
			if (!(line[0] == '\0' && value == 0))
			{
				free(line);
				return (0);
			}
		}
		tab = ft_split(line, sep);
		free(line);
		if (save_to_list(token, tab) == 0)
			return (0);
		free_split(tab);
		if (value == 0)
			break ;
	}
	if (value == -1)
		return (0);
	return (1);
}

static int	save_tokens2(t_list *token, int fd, char *sep)
{
	char	*line;
	char	**tab;
	int		value;

	while ((value = get_next_line(fd, &line)) > -1)
	{
		if (line[0] != '\0')
		{
			if (is_line_map(line) == 0)
				return (0);
			tab = ft_split(line, sep);
			free(line);
			if (save_to_list(token, tab) == 0)
				return (0);
			free_split(tab);
			return (save_tokens3(token, fd, sep));
		}
		free(line);
		if (value == 0)
			break ;
	}
	if (value == -1)
		return (0);
	return (0);
}

static int	count_id(t_list *token)
{
	const char	id[8][3] = {"NO\0", "SO\0", "WE\0", "EA\0", "R\0", "C\0", "F\0",
	"S\0"};
	int			count;

	if (token->str == NULL)
		return (0);
	count = 0;
	if (check_occurence(token->str, id, 8) != -1)
		count++;
	while (token->next != NULL)
	{
		if (ft_strcmp(token->str, "\n") == 0)
		{
			token = token->next;
			if (check_occurence(token->str, id, 8) != -1)
				count++;
			else
				return (-1);
		}
		token = token->next;
	}
	return (count);
}

static int	save_it(char *line, char **tab, char *sep, t_list *token)
{
	tab = ft_split(line, sep);
	if (save_to_list(token, tab) == 0)
	{
		free_split(tab);
		free(line);
		return (0);
	}
	free_split(tab);
	if (count_id(token) == 8)
		return (8);
	return (1);
}

int			save_tokens(t_list *token, int fd, char *sep)
{
	char	*line;
	char	**tab;
	int		value;
	int		tmp;

	tab = NULL;
	tmp = 1;
	while ((value = get_next_line(fd, &line)) > -1)
	{
		if (line[0] != '\0')
			tmp = save_it(line, tab, sep, token);
		free(line);
		if (tmp == 0)
			return (0);
		if (tmp == 8 || value == 0)
			break ;
	}
	if (value == -1)
		return (0);
	if (value > 0)
		return (save_tokens2(token, fd, "\n"));
	return (1);
}
