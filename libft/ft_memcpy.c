/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:35:55 by nayache           #+#    #+#             */
/*   Updated: 2019/10/18 17:06:14 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst2;
	char	*src2;
	size_t	i;

	i = 0;
	dst2 = (char *)dst;
	src2 = (char *)src;
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
