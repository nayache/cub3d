/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:53:49 by nayache           #+#    #+#             */
/*   Updated: 2019/10/17 19:23:48 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t lendest;
	size_t lensrc;
	size_t i;

	lendest = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	if (dstsize > lendest)
	{
		while (src[i] != '\0' && i < dstsize - lendest - 1)
		{
			dst[lendest + i] = src[i];
			i++;
		}
		dst[lendest + i] = '\0';
	}
	if (dstsize <= lendest)
		return (lensrc + dstsize);
	return (lendest + lensrc);
}
