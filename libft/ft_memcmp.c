/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:54:33 by nayache           #+#    #+#             */
/*   Updated: 2019/10/18 19:13:28 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*s10;
	char		*s20;

	s10 = (char *)s1;
	s20 = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s10[i] == s20[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s10[i] - (unsigned char)s20[i]);
}
