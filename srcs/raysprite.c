#include "cub3d.h"
#define texWidth 64
#define texHeight 64

static void	draw_sprite(t_info *info, int stripe)
{
	unsigned int	color;
	int				x;
	int				d;

	x = info->svec.drawstartx;
	while (x < info->svec.drawendx)
	{
		d = x * 256 - info->height * 128 + info->svec.sprite_h * 128;
		info->svec.texx = ((d * texHeight) / info->svec.sprite_h) / 256;
		color = info->texture[4][texWidth * info->svec.texx + info->svec.texy];
		if (color != 0)
		{
			pixel_put(info->win.img, x * info->sl + stripe * 4, 
			(char *)&color, info->endian);
		}
		x++;
	}
}

static void	raycast_sprite(t_info *info)
{
	int		stripe;

	stripe = info->svec.drawstarty;
	while (stripe < info->svec.drawendy)
	{
		info->svec.texy = (int)(256 * (stripe - (-info->svec.sprite_w / 2 + 
						info->svec.spr_screenx)) * texWidth / info->svec.sprite_w) / 256;
		if (info->svec.transformx > 0 && stripe > 0 && stripe < info->width && 
				info->svec.transformx < info->zbuffer[stripe])
			draw_sprite(info, stripe);
		stripe++;
	}
}

static void	draw_vector_sprite(t_info *info)
{
	info->svec.drawstartx = -info->svec.sprite_h / 2 + info->height / 2;
	if (info->svec.drawstartx < 0)
		info->svec.drawstartx = 0;
	info->svec.drawendx = info->svec.sprite_h / 2 + info->height / 2;
	if (info->svec.drawendx >= info->height)
		info->svec.drawendx = info->height - 1;
	info->svec.drawstarty = -info->svec.sprite_w / 2 + info->svec.spr_screenx;
	if (info->svec.drawstarty < 0)
		info->svec.drawstarty = 0;
	info->svec.drawendy = info->svec.sprite_w / 2 + info->svec.spr_screenx;
	if (info->svec.drawendy >= info->width)
		info->svec.drawendy = info->width - 1;
}

static void	init_vector_sprite(t_info *info, int count)
{
	info->svec.spritey = info->sprite[count].y + 0.5 - info->vec.posy;
	info->svec.spritex = info->sprite[count].x + 0.5 - info->vec.posx;
	info->svec.invdet = 1.0 / (info->vec.planey * info->vec.dirx -
			info->vec.diry * info->vec.planex);
	info->svec.transformy = info->svec.invdet * (info->vec.dirx * 
			info->svec.spritey - info->vec.diry * info->svec.spritex);
	info->svec.transformx = info->svec.invdet * (-info->vec.planex * 
			info->svec.spritey + info->vec.planey * info->svec.spritex);
	info->svec.spr_screenx = (int)((info->width / 2) * (1 + 
				info->svec.transformy / info->svec.transformx));
	info->svec.sprite_h = abs((int)(info->height / (info->svec.transformx)));
	info->svec.sprite_w = abs((int)(info->height / (info->svec.transformx)));
}

static void	init_distance(double *dist, t_info *info, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		dist[i] = ((info->vec.posy - info->sprite[i].y) * (info->vec.posy - 
		info->sprite[i].y) + (info->vec.posx - info->sprite[i].x) *
		(info->vec.posx - info->sprite[i].x));
		i++;
	}
}

void		sprite_cast(t_info *info)
{	
	double		sprite_dist[info->size_sprite];
	int			i;

	init_distance(sprite_dist, info, info->size_sprite);
	sort_sprites(sprite_dist, info, info->size_sprite);
	i = 0;
	while (i < info->size_sprite)
	{
		init_vector_sprite(info, i);
		draw_vector_sprite(info);
		raycast_sprite(info);
		i++;
	}
}
