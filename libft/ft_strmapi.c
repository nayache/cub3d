/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:07:04 by nayache           #+#    #+#             */
/*   Updated: 2019/10/15 14:12:50 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*t;
	char	*result;

	t = (char *)s;
	i = 0;
	if (!(result = malloc(sizeof(char) * (ft_strlen(t) + 1))))
		return (NULL);
	while (t[i])
	{
		result[i] = f(i, t[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
