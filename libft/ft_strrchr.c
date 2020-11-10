/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:06:09 by nayache           #+#    #+#             */
/*   Updated: 2019/10/17 16:52:08 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long	int	i;
	char		d;
	char		*s1;

	d = (char)c;
	s1 = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == d)
			return (s1 + i);
		i--;
	}
	return (NULL);
}
