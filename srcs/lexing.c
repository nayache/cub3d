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
//	if (!is_empty(tab) && tab + i != NULL) // si la line(tableau de str) n'est pas vide et que le dernier element de la line n'est pas null
		if (lst_add(token, "\n") == 0)          // pour mettre le \n pask mon gnl les enleve.
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
		free(line);
		if (save_to_list(token, tab) == 0)
			return (0);
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
			free(line);
			if (save_to_list(token, tab) == 0)
				return (0);
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

static int		count_id(s_list *token)
{
	const char	id[8][3] = {"NO\0", "SO\0", "WE\0", "EA\0", "R\0", "C\0", "F\0", "S\0"};
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

int		save_it(char *line, char **tab, char *sep, s_list *token)
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

int		save_tokens(s_list *token, int fd, char *sep)
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
			break;
	}
	if (value == -1)
		return (0);
	if (value > 0)
		return (save_tokens2(token, fd, "\n"));
	return (1);
}
