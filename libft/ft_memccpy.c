/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:52:41 by nayache           #+#    #+#             */
/*   Updated: 2019/10/18 19:13:13 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dst2;
	char			*src2;
	size_t			i;
	char			d;

	d = (unsigned char)c;
	dst2 = (char *)dst;
	src2 = (char *)src;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == d)
			return (dst + (i + 1));
		i++;
	}
	return (NULL);
}
