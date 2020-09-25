#include "cub3d.h"

static void	coordinate_texture(t_info *info, int drawstart)
{
	if (info->vec.side == 0)
		info->txt.wallx = info->vec.posy + info->vec.perpwalldist
		* info->vec.raydiry;
	else           
		info->txt.wallx = info->vec.posx + info->vec.perpwalldist
		* info->vec.raydirx;
	info->txt.wallx -= floor(info->txt.wallx);
	info->txt.texX = (int)(info->txt.wallx * (double)texwidth);
	if (info->vec.side == 0 && info->vec.raydirx > 0) 
		info->txt.texX = texwidth - info->txt.texX - 1;
	if (info->vec.side == 1 && info->vec.raydiry < 0) 
		info->txt.texX = texwidth - info->txt.texX - 1;
	info->txt.step = 1.0 * texheight / info->txt.lineheight;
	info->txt.texpos = (drawstart - info->height / 2 + info->txt.lineheight / 2)
	* info->txt.step;
}

void		texture_cast(t_info *info, int drawstart, int drawend, int y)
{
	unsigned int	color;
	int				x;

	coordinate_texture(info, drawstart);
	x = drawstart;
	while (x < drawend)
	{
		info->txt.texY = (int)info->txt.texpos & (texheight - 1);
		info->txt.texpos += info->txt.step;
		if (info->vec.side == 0 && info->vec.raydirx > 0)
			color = info->texture[2][texheight * info->txt.texY
			+ info->txt.texX];
		if (info->vec.side == 0 && info->vec.raydirx < 0)
			color = info->texture[3][texheight * info->txt.texY
			+ info->txt.texX];
		if (info->vec.side == 1 && info->vec.raydiry > 0)
			color = info->texture[0][texheight * info->txt.texY
			+ info->txt.texX];
		if (info->vec.side == 1 && info->vec.raydiry < 0)
			color = info->texture[1][texheight * info->txt.texY
			+ info->txt.texX];
		if (info->vec.side == 1)
			color = (color >> 1) & 8355711;
		info->buffer[y][x] = color;
		x++;
	}
}
