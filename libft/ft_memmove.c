/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:44:38 by nayache           #+#    #+#             */
/*   Updated: 2019/10/18 16:44:15 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst2;
	char	*src2;

	dst2 = (char *)dst;
	src2 = (char *)src;
	i = 0;
	if (!n || src == dst)
		return (dst);
	if (src < dst)
		while (n-- > 0)
			dst2[n] = src2[n];
	else
		while (i < n)
		{
			dst2[i] = src2[i];
			i++;
		}
	return (dst);
}
