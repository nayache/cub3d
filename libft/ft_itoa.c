/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:32:38 by nayache           #+#    #+#             */
/*   Updated: 2019/10/14 15:07:21 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	workit(char *str, long int n)
{
	if (n >= 10)
	{
		workit(str - 1, n / 10);
		*str = (n % 10) + 48;
	}
	*str = (n % 10) + 48;
}

static int	sizework(long int n)
{
	int		size;

	if (n != 0)
		size = 1;
	if (n < 0)
		n = n * -1;
	else if (n == 0)
		size = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	long int	nb;
	long int	supp;
	char		*result;

	nb = (long int)n;
	supp = (nb < 0) ? 2 : 1;
	if (!(result = malloc(sizeof(char) * (sizework(n) + supp))))
		return (NULL);
	if (nb < 0)
	{
		result[0] = '-';
		nb = nb * -1;
	}
	workit(result + ((sizework(nb) - 1) + supp - 1), nb);
	result[sizework(nb) + (supp - 1)] = '\0';
	return (result);
}
