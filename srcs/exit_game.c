#include "cub3d.h"

void	free_map(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_list(s_list *token)
{
	s_list *tmp;

	while (token != NULL)
	{
		if (token->str != NULL)
			free(token->str);
		tmp = token;
		token = token->next;
		free(tmp);
	}
}

void	free_path(t_path *path)
{
	if (path->north != NULL)
		free(path->north);
	if (path->south != NULL)
		free(path->south);
	if (path->east != NULL)
		free(path->east);
	if (path->west != NULL)
		free(path->west);
	if (path->sprite != NULL)
		free(path->sprite);
}

void	free_buffer(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->width)
	{
		free(info->buffer[i]);
		i++;
	}
	free(info->buffer);
}

int		exit_game(t_info *info)
{
	mlx_destroy_image(info->win.mlx_ptr, info->win.img_ptr);
	mlx_clear_window(info->win.mlx_ptr, info->win.win_ptr);
	mlx_destroy_window(info->win.mlx_ptr, info->win.win_ptr);
	free(info->win.mlx_ptr);
	free_map(info->map, info->map_h);
	free_path(&(info->path));
	free(info->sprite);
	free(info->ptrs[0]);
	free(info->ptrs[1]);
	free(info->ptrs[2]);
	free(info->ptrs[3]);
	free(info->ptrs[4]);
	free(info->ptrs);
	free(info->texture);
	free_buffer(info);
	free(info->zbuffer);
	exit(42);
}
