/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:10:27 by nayache           #+#    #+#             */
/*   Updated: 2019/10/17 16:58:55 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t memo;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)(haystack));
	while (haystack[i] && i < len)
	{
		memo = 0;
		while (haystack[i + memo] == needle[memo] && (i + memo) < len)
		{
			memo++;
			if (needle[memo] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}
