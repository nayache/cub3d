#include "cub3d.h"

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
//	print_lst(token);   // print   a effacer
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
		return (0);
	}
	return (1);
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
		ft_bzero(info->buffer[i], info->height);
		i++;
	}
	if (!(info->zbuffer = (double *)malloc(sizeof(double) * info->width)))
		return (0);
	ft_bzero(info->zbuffer, info->width);
	return (1);
}

void	start_display(t_info *info)
{
	int	width_max;
	int	height_max;
	
	info->win.mlx_ptr = mlx_init();
	info->win.img_ptr = mlx_new_image(info->win.mlx_ptr, info->width,
			info->height);
	info->win.img = mlx_get_data_addr(info->win.img_ptr, &info->bpp, &info->sl,
			&info->endian);
	get_color(info);
	mlx_get_screen_size(info->win.mlx_ptr, &width_max, &height_max);
	if (info->width > width_max)
		info->width = width_max;
	if (info->height > height_max)
		info->height = height_max;
	info->vec.movespeed += info->height * 0.0001;
	info->vec.rotspeed += info->height * 0.0001;
	if (info->screenshot == 0)
		info->win.win_ptr = mlx_new_window(info->win.mlx_ptr, info->width,
		info->height,"CUB 3D LOOP");
}

int		init_game(t_info *info, char *file)
{
	s_list	*token;
	int		fd;
	
	if (verif_format(file) == 0)
		return (error("invalid format file."));
	if ((fd = open(file, O_RDONLY)) == -1)
		return (error("fail to open file."));
	if ((token = malloc(sizeof(s_list))) == NULL)
		return (error("fail for memory allocation."));
	token = init_elem(token);
	if (parse(fd, token, info) == 0)
		return (error("invalid datas in file."));
	if (verif_datas(info) == 0)
		return (0);
	start_display(info);
	if (init_buffer(info) == 0)
		return (error("fail for memory allocation."));
	return (1);
}

int		main(int argc, char **argv)
{
	t_info info;

	if (argc != 2 && argc != 3)
		return (error("numbers of arguments invalid."));
	if (argc == 3 && ft_strcmp(argv[2], "--save") != 0)
		return (error("invalid argument."));
	init_info(&info);
	if (argc == 3)
		info.screenshot = 1;
	if (init_game(&info, argv[1]) == 0)
		return (0);
	if ((init_texture(&info)) == 0)
		return (0);
	if (info.screenshot == 1)
		return (screenshot(&info));
	mlx_hook(info.win.win_ptr, 2, (1L<<0), key_press, &info);
	mlx_hook(info.win.win_ptr, 3, (1L<<1), key_release, &info);
	mlx_hook(info.win.win_ptr, 33, (1L<<17), exit_game, &info);
	mlx_loop_hook(info.win.mlx_ptr, raycast, &info);
	mlx_loop(info.win.mlx_ptr);
	return (0);
}
