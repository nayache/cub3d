#include "cub3d.h"

s_list	*init_elem(s_list *elem)
{
	elem->str = NULL;
	elem->next = NULL;
	return (elem);
}

int		lst_add(s_list *first, char *s)
{
	s_list *new;
	s_list *tmp;

	if ((new = malloc(sizeof(s_list))) == NULL)
		return (0);
	new = init_elem(new);
	new->str = ft_strdup(s);
	if (new->str == NULL)
		return (0);
	tmp = first;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
		new->next = NULL;
	return (1);
}

int		is_empty(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!is_space(tab[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_lst(s_list *token)
{
	while (token->next != NULL)
	{
		printf("[%s]", token->str);
		token = token->next;
	}
	printf("[%s]", token->str);
}
