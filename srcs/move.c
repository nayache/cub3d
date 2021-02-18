/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:50:31 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 18:50:48 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(char ***map, t_vector *vec)
{
	if ((*map)[(int)vec->posy][(int)(vec->posx + vec->dirx *
		(vec->movespeed * 5))] == '0')
		vec->posx += vec->dirx * vec->movespeed;
	if ((*map)[(int)(vec->posy + vec->diry * (vec->movespeed * 5))]
		[(int)vec->posx] == '0')
		vec->posy += vec->diry * vec->movespeed;
}

void	move_down(char ***map, t_vector *vec)
{
	if ((*map)[(int)vec->posy][(int)(vec->posx - vec->dirx *
		(vec->movespeed * 5))] == '0')
		vec->posx -= vec->dirx * vec->movespeed;
	if ((*map)[(int)(vec->posy - vec->diry * (vec->movespeed * 5))]
		[(int)vec->posx] == '0')
		vec->posy -= vec->diry * vec->movespeed;
}

void	move_left(char ***map, t_vector *vec)
{
	if ((*map)[(int)vec->posy][(int)(vec->posx - vec->planex *
		(vec->movespeed * 5))] == '0')
		vec->posx -= vec->planex * vec->movespeed;
	if ((*map)[(int)(vec->posy - vec->planey * (vec->movespeed * 5))]
		[(int)vec->posx] == '0')
		vec->posy -= vec->planey * vec->movespeed;
}

void	move_right(char ***map, t_vector *vec)
{
	if ((*map)[(int)vec->posy][(int)(vec->posx + vec->planex *
		(vec->movespeed * 5))] == '0')
		vec->posx += vec->planex * vec->movespeed;
	if ((*map)[(int)(vec->posy + vec->planey * (vec->movespeed * 5))]
		[(int)vec->posx] == '0')
		vec->posy += vec->planey * vec->movespeed;
}
