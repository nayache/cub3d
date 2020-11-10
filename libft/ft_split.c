/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:44:35 by nayache           #+#    #+#             */
/*   Updated: 2019/10/17 19:30:58 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_occurence(char const *s1, int index, char *sep)
{
	int i;

	i = 0;
	while (sep[i])
	{
		if (s1[index] == sep[i])
			return (1);
		i++;
	}
	return (0);
}

static int		ft_nb_word(char const *str, char *sep)
{
	int i;
	int word;

	i = 0;
	if (!ft_occurence(str, 0, sep))
		word = 1;
	else
		word = 0;
	while (str[i])
	{
		if (ft_occurence(str, i, sep) == 1 && !ft_occurence(str, i + 1, sep) &&
				str[i + 1] != '\0')
			word++;
		i++;
	}
	return (word);
}

static int		wlen(char const *str, int i, char *sep)
{
	int size;

	size = 0;
	while (!ft_occurence(str, i, sep) && str[i])
	{
		i++;
		size++;
	}
	return (size);
}

static char		**work(char **split, char const *str, char *sep)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0' && j < (ft_nb_word(str, sep)))
	{
		k = 0;
		if (!(ft_occurence(str, i, sep)))
		{
			if (!(split[j] = malloc(sizeof(char) * (wlen(str, i, sep) + 1))))
				return (NULL);
			while (str[i] != '\0' && ft_occurence(str, i, sep) == 0)
			{
				split[j][k] = str[i++];
				k++;
			}
			split[j][k] = '\0';
			j++;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

char			**ft_split(char const *str, char *sep)
{
	int		word;
	char	**split;
	int		i;

	word = ft_nb_word(str, sep);
	i = 0;
	if (!(split = (char **)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	while (str[i])
	{
		if (!(ft_occurence(str, i, sep)))
			break ;
		i++;
	}
	work(split, str, sep);
	return (split);
}
