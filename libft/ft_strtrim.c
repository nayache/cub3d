/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:53:00 by nayache           #+#    #+#             */
/*   Updated: 2019/10/16 18:26:01 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_occurence(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	cut_set(char const *s1, char const *set, int cut)
{
	int i;

	i = 0;
	cut = 0;
	while (ft_occurence(s1[i], set) == 1)
	{
		cut++;
		i++;
	}
	if (cut == (int)ft_strlen(s1))
		return (cut);
	i = ft_strlen(s1) - 1;
	while (ft_occurence(s1[i], set) == 1)
	{
		cut++;
		i--;
	}
	return (cut);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	int		cut;
	int		i;
	char	*str;

	cut = 0;
	cut = cut_set(s1, set, cut);
	size = ft_strlen(s1) - cut;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	size--;
	i = ft_strlen(s1) - 1;
	while (ft_occurence(s1[i], set) == 1)
		i--;
	while (size >= 0)
	{
		str[size] = s1[i];
		i--;
		size--;
	}
	return (str);
}
