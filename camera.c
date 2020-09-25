#include "cub3d.h"

void	turn_left(t_vector *vec)
{
	vec->oldirx = vec->dirx;
    vec->oldplanex = vec->planex;
    vec->dirx = vec->dirx * cos(-vec->rotspeed) - vec->diry * sin(-vec->rotspeed);
    vec->diry = vec->oldirx * sin(-vec->rotspeed) + vec->diry * cos(-vec->rotspeed);
    vec->planex = vec->planex * cos(-vec->rotspeed) - vec->planey * sin(-vec->rotspeed);
    vec->planey = vec->oldplanex * sin(-vec->rotspeed) + vec->planey * cos(-vec->rotspeed);
}

void	turn_right(t_vector *vec)
{
	vec->oldirx = vec->dirx;
    vec->oldplanex = vec->planex;
    vec->dirx = vec->dirx * cos(vec->rotspeed) - vec->diry * sin(vec->rotspeed);
    vec->diry = vec->oldirx * sin(vec->rotspeed) + vec->diry * cos(vec->rotspeed);
    vec->planex = vec->planex * cos(vec->rotspeed) - vec->planey * sin(vec->rotspeed);
    vec->planey = vec->oldplanex * sin(vec->rotspeed) + vec->planey * cos(vec->rotspeed);
}
