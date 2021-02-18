/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:02:51 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 21:54:42 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*init_elem(t_list *elem)
{
	elem->str = NULL;
	elem->next = NULL;
	return (elem);
}

int		lst_add(t_list *first, char *s)
{
	t_list *new;
	t_list *tmp;

	if ((new = malloc(sizeof(t_list))) == NULL)
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

int		is_line_map(char *str)
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

void	print_lst(t_list *token)
{
	while (token->next != NULL)
	{
		ft_putchar('[');
		ft_putstr(token->str);
		ft_putchar(']');
		token = token->next;
	}
	ft_putchar('[');
	ft_putstr(token->str);
	ft_putchar(']');
}
