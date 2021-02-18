/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexing2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:55:25 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 19:55:41 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_occurence(char *s1, const char s2[8][3], int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(s1, (char *)s2[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	only_num(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_num(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
