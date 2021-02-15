#include "cub3d.h"

void	event_key(t_info *info)
{
	if (info->key.esc == 1)
		exit_game(info);
	if (info->key.rotl == 1)
		turn_left(&info->vec);
	if (info->key.rotr == 1)
		turn_right(&info->vec);
	if (info->key.up == 1)
		move_up(&info->map, &info->vec);
	if (info->key.down == 1)
		move_down(&info->map, &info->vec);
	if (info->key.right == 1)
		move_right(&info->map, &info->vec);
	if (info->key.left == 1)
		move_left(&info->map, &info->vec);
}

int		key_press(int keycode, t_info *info)
{
	if (keycode == ESC)
		info->key.esc = 1;
	if (keycode == ROTL)
		info->key.rotl = 1;
	if (keycode == ROTR)
		info->key.rotr = 1;
	if (keycode == UP)
		info->key.up = 1;
	if (keycode == DOWN)
		info->key.down = 1;
	if (keycode == RIGHT)
		info->key.right = 1;
	if (keycode == LEFT)
		info->key.left = 1;
	return (0);
}

int		key_release(int keycode, t_info *info)
{
	if (keycode == 65307)
		info->key.esc = 0; 
	if (keycode == 65361)
		info->key.rotl = 0;
	if (keycode == 65363)
		info->key.rotr = 0;
	if (keycode == 'w')
		info->key.up = 0;
	if (keycode == 's')
		info->key.down = 0;
	if (keycode == 'd')
		info->key.right = 0;
	if (keycode == 'a')
		info->key.left = 0;
	return (0);
}
