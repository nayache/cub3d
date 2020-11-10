/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:13:16 by nayache           #+#    #+#             */
/*   Updated: 2019/10/17 16:19:28 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			d;
	char			*s2;

	i = 0;
	d = (unsigned char)c;
	s2 = (char *)s;
	while (i < n)
	{
		if (s2[i] == d)
			return (void *)(s + i);
		i++;
	}
	return (NULL);
}
