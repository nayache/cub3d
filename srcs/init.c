/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:09:06 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 21:22:58 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			init_texture(t_info *info)
{
	int tp;

	if (!(info->ptrs = malloc(sizeof(void *) * 5)))
		return (0);
	if (!(info->texture = (int **)malloc(sizeof(int *) * 5)))
		return (0);
	info->ptrs[0] = mlx_xpm_file_to_image(info->win.mlx_ptr, info->path.north,
	&tp, &tp);
	info->texture[0] = (int *)mlx_get_data_addr(info->ptrs[0], &tp, &tp, &tp);
	info->ptrs[1] = mlx_xpm_file_to_image(info->win.mlx_ptr, info->path.south,
	&tp, &tp);
	info->texture[1] = (int *)mlx_get_data_addr(info->ptrs[1], &tp, &tp, &tp);
	info->ptrs[2] = mlx_xpm_file_to_image(info->win.mlx_ptr, info->path.west,
	&tp, &tp);
	info->texture[2] = (int *)mlx_get_data_addr(info->ptrs[2], &tp, &tp, &tp);
	info->ptrs[3] = mlx_xpm_file_to_image(info->win.mlx_ptr, info->path.east,
	&tp, &tp);
	info->texture[3] = (int *)mlx_get_data_addr(info->ptrs[3], &tp, &tp, &tp);
	info->ptrs[4] = mlx_xpm_file_to_image(info->win.mlx_ptr, info->path.sprite,
	&tp, &tp);
	info->texture[4] = (int *)mlx_get_data_addr(info->ptrs[4], &tp, &tp, &tp);
	return (1);
}

static void	init_txt(t_txt *txt)
{
	txt->wallx = 0;
	txt->step = 0;
	txt->texpos = 0;
	txt->texx = 0;
	txt->texy = 0;
	txt->lineheight = 0;
}

static void	init_vector(t_vector *vec)
{
	vec->posx = 0.00;
	vec->posy = 0.00;
	vec->dirx = 0.00;
	vec->diry = 0.00;
	vec->planex = 0.00;
	vec->planey = 0.00;
	vec->camerax = 0.00;
	vec->raydirx = 0.00;
	vec->raydiry = 0.00;
	vec->stepx = 0;
	vec->stepy = 0;
	vec->mapx = 0;
	vec->mapy = 0;
	vec->sidedistx = 0.00;
	vec->sidedisty = 0.00;
	vec->deltadistx = 0.00;
	vec->deltadisty = 0.00;
	vec->oldplanex = 0.00;
	vec->oldirx = 0.00;
	vec->rotspeed = 0.04;
	vec->movespeed = 0.02;
}

static void	init_key(t_key *key)
{
	key->esc = 0;
	key->up = 0;
	key->down = 0;
	key->left = 0;
	key->right = 0;
	key->rotr = 0;
	key->rotl = 0;
}

void		init_info(t_info *info)
{
	info->height = 0;
	info->width = 0;
	info->map = NULL;
	info->map_h = 0;
	info->map_w = 0;
	info->sl = 0;
	info->bpp = 0;
	info->endian = 0;
	info->buffer = NULL;
	info->zbuffer = NULL;
	info->spr_dist = 0;
	info->screenshot = 0;
	init_vector(&info->vec);
	init_txt(&info->txt);
	init_key(&info->key);
}
