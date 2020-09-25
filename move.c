#include "cub3d.h"

void	move_up(char ***map, t_vector *vec)
{
	if ((*map)[(int)vec->posy][(int)(vec->posx + vec->dirx * (vec->movespeed * 10.20))] == '0')
		vec->posx += vec->dirx * vec->movespeed;
	if ((*map)[(int)(vec->posy + vec->diry * (vec->movespeed * 10.20))][(int)vec->posx] == '0')
		vec->posy += vec->diry * vec->movespeed;
}

void	move_down(char ***map, t_vector *vec)
{
	if ((*map)[(int)vec->posy][(int)(vec->posx + vec->dirx * (vec->movespeed * 10.20))] == '0')
		vec->posx -= vec->dirx * vec->movespeed;
	if ((*map)[(int)(vec->posy + vec->diry * (vec->movespeed * 10.20))][(int)vec->posx] == '0')
		vec->posy -= vec->diry * vec->movespeed;
}

void	move_left(char ***map, t_vector *vec)
{
	if ((*map)[(int)vec->posy][(int)(vec->posx + vec->planex * (vec->movespeed * 10.20))] == '0')
		vec->posx -= vec->planex * vec->movespeed;
	if ((*map)[(int)(vec->posy + vec->planey * (vec->movespeed * 10.20))][(int)vec->posx] == '0')
		vec->posy -= vec->planey * vec->movespeed;
}

void	move_right(char ***map, t_vector *vec)
{
	if ((*map)[(int)vec->posy][(int)(vec->posx + vec->planex * (vec->movespeed * 10.20))] == '0')
		vec->posx += vec->planex * vec->movespeed;
	if ((*map)[(int)(vec->posy + vec->planey * (vec->movespeed * 10.20))][(int)vec->posx] == '0')
		vec->posy += vec->planey * vec->movespeed;
}
