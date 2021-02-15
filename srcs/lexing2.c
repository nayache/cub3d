#include "cub3d.h"

int			is_line_map(char *str)
{
	int i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (is_valid(str[i]) == 0 && is_space(str[i]) == 0)
				return (0);
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int				check_occurence(char *s1, const char s2[8][3], int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
//		printf("je compare : [%s] et [%s]\n", s1, s2[i]);
		if (ft_strcmp(s1, (char *)s2[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static s_list	*requiered_id(s_list *token)
{
	const char	requiered[8][3] = {"R\0", "NO\0", "SO\0", "WE\0", "EA\0", "S\0", "F\0", "C\0"};
	int			i;

	if (check_occurence(token->str, requiered, 8) == -1)
		return (NULL);
	i = 1;
	while (token != NULL && i < 8)
	{
		if (ft_strcmp(token->str, "\n") == 0)
		{
			token = token->next;
			if (check_occurence(token->str, requiered, 8) == -1)
				return (NULL);
			i++;
		}
		token = token->next;
	}
	return (token);
}

static int	requiered_map(s_list *token)
{
	while (token->next != NULL && token->str[0] != '\n') // chope le 1ere ligne de la map (je skip la value et \n de [C])
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

int			check_tokens(s_list *token)
{
	s_list *tmp;
	
	tmp = requiered_id(token);
	if (tmp == NULL)
		return (0);
	if (requiered_map(tmp) == 0)
		return (0);
	return (1);
}
