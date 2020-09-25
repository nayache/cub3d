#include "cub3d.h"

static void	init_plane(t_vector *vec, double x, double y, double px, double py)
{
	vec->dirx = x;
	vec->diry = y;
	vec->planex = px;
	vec->planey = py;
}

void		init_start_camera(t_vector *vec, int c)
{
	if (c == 'N')
		init_plane(vec, 0.00, -1.00, 0.60, 0.00);
	if (c == 'S')
		init_plane(vec, 0.00, 1.00, -0.60, 0.00);
	if (c == 'W')
		init_plane(vec, -1.00, 0.00, 0.00, -0.60);
	if (c == 'E')
		init_plane(vec, 1.00, 0.00, 0.00, 0.60);
}
