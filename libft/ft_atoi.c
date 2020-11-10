/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:46:50 by nayache           #+#    #+#             */
/*   Updated: 2019/10/16 17:05:35 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		is_alpha(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int		is_space(char c)
{
	if (c == '\n' || c == '\t')
		return (1);
	if (c == '\r' || c == '\f')
		return (1);
	if (c == ' ' || c == '\v')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (is_space(str[i]) == 1)
		i++;
	while ((str[i] == '-' || str[i] == '+') && neg == 1)
	{
		neg++;
		if (str[i] == '-')
			neg = 3;
		i++;
	}
	while (is_alpha(str[i]) == 1)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	neg = (neg > 2) ? -1 : 1;
	return (res * neg);
}
