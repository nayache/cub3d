#include "cub3d.h"

static int		save_to_list(s_list *token, char **tab)
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
			if (lst_add(token, tab[i++]) == 0)
				return (0);
	}
	if (!is_empty(tab) && tab + i != NULL) // si la line(tableau de str) n'est pas vide et que le dernier element de la line n'est pas null
		if (!lst_add(token, "\n"))          // pour mettre le \n pask mon gnl les enleve.
			return (0);
	return (1);
}

static int		save_tokens3(s_list *token, int fd, char *sep)
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
		if (save_to_list(token, tab) == 0)
			return (0);
		free(line);
		free_split(tab);
		if (value == 0)
			break;
	}
	if (value == -1)
		return (0);
	return (1);
}

static int		save_tokens2(s_list *token, int fd, char *sep)
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
			if (save_to_list(token, tab) == 0)
				return (0);
			free(line);
			free_split(tab);
			return (save_tokens3(token, fd, sep));
		}
		free(line);
		if (value == 0)
			break;
	}
	if (value == -1)
		return (0);
	return (0);
}

int		save_tokens(s_list *token, int fd, char *sep)
{
	char	*line;
	char	**tab;
	int		value;

	tab = NULL;
	while ((value = get_next_line(fd, &line)) > -1)
	{
		tab = ft_split(line, sep);
		if (save_to_list(token, tab) == 0)
			return (0);
		if (line[0] == 'C')
		{
			free(line);
			free_split(tab);
			break;
		}
		free(line);
		free_split(tab);
		if (value == 0)
			break;
	}
	if (value == -1)
		return (0);
	if (value > 0)
		return (save_tokens2(token, fd, "\n"));
	return (1);
}
