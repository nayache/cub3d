/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:21:55 by nayache           #+#    #+#             */
/*   Updated: 2019/10/17 16:08:03 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*b2;
	size_t	i;
	char	d;

	d = (unsigned char)c;
	b2 = (char *)b;
	i = 0;
	while (i < len)
	{
		b2[i] = d;
		i++;
	}
	return (b);
}
