/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:49:59 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 19:50:01 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	if (c == '\f' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int		is_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int		is_valid(char c)
{
	if (is_pos(c) || c == '0' || c == '1' || c == '2')
		return (1);
	return (0);
}

int		verif_format(char *s)
{
	int i;

	i = ft_strlen(s) - 4;
	if (i < 0)
		return (0);
	if (ft_strcmp(s + i, ".cub"))
		return (0);
	return (1);
}
