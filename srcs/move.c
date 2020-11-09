#include "cub3d.h"

void	move_up(char ***map, t_vector *vec)
{
	printf("MOVE UP\n");
	printf("for posy :[%d][%d] == ", (int)(vec->posy + vec->diry * (vec->movespeed * 5)), (int)vec->posx);
	printf("%c\n", (*map)[(int)(vec->posy + vec->diry * (vec->movespeed * 5))][(int)vec->posx]);
	printf("for posx :[%d][%d] == ", (int)vec->posy, (int)(vec->posx + vec->dirx * (vec->movespeed * 5)));
	printf("%c\n", (*map)[(int)vec->posy][(int)(vec->posy + vec->diry * (vec->movespeed * 5))]);
	if ((*map)[(int)vec->posy][(int)(vec->posx + vec->dirx * (vec->movespeed * 5))] == '0')
		vec->posx += vec->dirx * vec->movespeed;
	if ((*map)[(int)(vec->posy + vec->diry * (vec->movespeed * 5))][(int)vec->posx] == '0')
		vec->posy += vec->diry * vec->movespeed;
}

void	move_down(char ***map, t_vector *vec)

{
	printf("MOVE DOWN\n");
	printf("for posy :[%i][%d] == ", (int)(vec->posy - vec->diry * (vec->movespeed * 5)), (int)vec->posx);
	printf("%c\n", (*map)[(int)(vec->posy - vec->diry * (vec->movespeed * 5))][(int)vec->posx]);
	printf("for posx :[%d][%i] == ", (int)vec->posy, (int)(vec->posx - vec->dirx * (vec->movespeed * 5)));
	printf("%c\n", (*map)[(int)vec->posy][(int)(vec->posy - vec->diry * (vec->movespeed * 5))]);
	if ((*map)[(int)vec->posy][(int)(vec->posx - vec->dirx * (vec->movespeed * 5))] == '0')
		vec->posx -= vec->dirx * vec->movespeed;
	if ((*map)[(int)(vec->posy - vec->diry * (vec->movespeed * 5))][(int)vec->posx] == '0')
		vec->posy -= vec->diry * vec->movespeed;
}

void	move_left(char ***map, t_vector *vec)
{
	printf("MOVE LEFT\n");
	printf("for posy :[%i][%d] == ", (int)(vec->posy - vec->planey * (vec->movespeed * 5)), (int)vec->posx);
	printf("%c\n", (*map)[(int)(vec->posy + vec->planey * (vec->movespeed * 5))][(int)vec->posx]);
	printf("for posx :[%d][%i] == ", (int)vec->posy, (int)(vec->posx - vec->planex * (vec->movespeed * 5)));
	printf("%c\n", (*map)[(int)vec->posy][(int)(vec->posx + vec->planex * (vec->movespeed * 5))]);
	if ((*map)[(int)vec->posy][(int)(vec->posx - vec->planex * (vec->movespeed * 5))] == '0')
		vec->posx -= vec->planex * vec->movespeed;
	if ((*map)[(int)(vec->posy - vec->planey * (vec->movespeed * 5))][(int)vec->posx] == '0')
		vec->posy -= vec->planey * vec->movespeed;
}

void	move_right(char ***map, t_vector *vec)
{
	printf("MOVE RIGHT\n");
	printf("for posy :[%i][%d] == ", (int)(vec->posy - vec->planey * (vec->movespeed * 5)), (int)vec->posx);
	printf("%c\n", (*map)[(int)(vec->posy + vec->planey * (vec->movespeed * 5))][(int)vec->posx]);
	printf("for posx :[%d][%i] == ", (int)vec->posy, (int)(vec->posx - vec->planex * (vec->movespeed * 5)));
	printf("%c\n", (*map)[(int)vec->posy][(int)(vec->posx + vec->planex * (vec->movespeed * 5))]);
	if ((*map)[(int)vec->posy][(int)(vec->posx + vec->planex * (vec->movespeed * 5))] == '0')
		vec->posx += vec->planex * vec->movespeed;
	if ((*map)[(int)(vec->posy + vec->planey * (vec->movespeed * 5))][(int)vec->posx] == '0')
		vec->posy += vec->planey * vec->movespeed;
}
