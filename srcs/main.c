#include "cub3d.h"

void	print_map(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int		error(char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	ft_putchar('\n');
	return (0);
}

int		parse(int fd, s_list *token, t_info *info)
{
	if (save_tokens(token, fd, " \t\v\f\r\n") == 0)
	{
		free_list(token);
		close(fd);
		return (0);
	}
	close(fd);
	if (check_tokens(token) == 0)
	{
		free_list(token);
		return (0);
	}
	if (parse_tokens(token, info) == 0)
	{
		free_list(token);
		return (0);
	}
	free_list(token);
	if (save_sprites(info) == 0)
	{
		free_path(&(info->path));
		free_map(info->map, info->map_h);
	}
	return (1);
}


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

int		init_buffer(t_info *info)
{
	int i;

	if ((info->buffer = (int **)malloc(sizeof(int *) * info->width)) == NULL)
		return (0);
	i = 0;
	while (i < info->width)
	{
		info->buffer[i] = (int *)malloc(sizeof(int) * info->height);
		if (info->buffer[i] == NULL)
			return (0);
		i++;
	}
	return (1);
}

int		init_game(t_info *info, char *file)
{
	s_list	*token;
	int		fd;

	if ((token = malloc(sizeof(s_list))) == NULL)
		return (error("fail for memory allocation."));
	token = init_elem(token);
	if (verif_format(file) == 0)
		return (error("invalid format file."));
	if ((fd = open(file, O_RDONLY)) == -1)
		return (error("fail to open file."));
	if (parse(fd, token, info) == 0)
		return (error("invalid datas in file."));
	if (verif_datas(info) == 0)
		return (0);
	if (init_buffer(info) == 0)
		return (error("fail for memory allocation."));
	//print_info(info);
	info->win.mlx_ptr = mlx_init();
	info->win.win_ptr = mlx_new_window(info->win.mlx_ptr, info->width,
	info->height,"CUB 3D LOOP");
	info->win.img_ptr = mlx_new_image(info->win.mlx_ptr, info->width,
	info->height);
	info->win.img = mlx_get_data_addr(info->win.img_ptr, &info->bpp, &info->sl,
	&info->endian);
	get_color(info);
	return (1);
}

int		main(int ac, char **av)
{
	usleep(1000);
	t_info info;
	
	if (ac == 2 || ac == 3)
	{
		init_info(&info);
		if (init_game(&info, av[1]) == 0)
			return (0);
		if ((init_texture(&info)) == 0)
			return (0);
		if (!(info.zbuffer = (double *)malloc(sizeof(double) * info.width)))
			return (0);
		print_map(info.map, info.map_h);
		mlx_hook(info.win.win_ptr, 2, (1L<<0), key_press, &info);
		mlx_hook(info.win.win_ptr, 3, (1L<<1), key_release, &info);
		mlx_hook(info.win.win_ptr, 17, (1L<<17), exit_game, &info);
		mlx_loop_hook(info.win.mlx_ptr, raycast, &info);
		if (ac == 2)
			mlx_loop(info.win.mlx_ptr);
	}
	else
		return (error("numbers of arguments invalid."));
	return (0);
}
