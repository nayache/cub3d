#include "cub3d.h"

static int	save_start_pos(char ***map, int y, int x, t_vector *vec, int n)
{
	if (n != 1)
		return (0);
	init_start_camera(vec, (*map)[y][x]);
	vec->posy = (double)y + 0.5;
	vec->posx = (double)x + 0.5;
	(*map)[y][x] = '0';
	return (1);
}

static int	check_start_pos(char **map, int size, t_vector *vec)
{
	int y;
	int x;
	int	view_pos;

	y = 0;
	view_pos = 0;
	while (y < size)
	{
		x = 0;
		while (map[y][x])
		{
			if (is_pos(map[y][x]))
			{
				view_pos++;
				if (!save_start_pos(&map, y, x, vec, view_pos))
					return (error("Too many starting positions in the map."));
			}
			x++;
		}
		y++;
	}
	if (view_pos < 1)
		return (error("no starting position found."));
	return (1);
}

static int	check_joined(char *s1, char *s2, int index)
{
	int	touch;

	touch = 0;
	while (s1[index] && s2[index] && is_valid(s1[index]))
	{
		if (is_valid(s2[index]))
			touch++;
		index++;
	}
	if (touch == 0)
		return (0);
	return (1);
}

static int	is_joined(char *s1, char *s2)
{
	int i;
	int join;	

	i = 0;
	join = 0;
	while (s1[i] && s2[i])
	{
		if (is_valid(s1[i]))
			if (check_joined(s1, s2, i))
				join++;
		i++;
	}
	if (join == 0)
		return (0);
	return (1);
}

static int	check_is_compact(char **map, int size)
{
	int y;

	y = 0;
	while (y < size - 1)
	{
		if (!is_joined(map[y], map[y + 1]))
			return (0);
		y++;
	}
	return (1);
}

int			verif_map(char **map, int size, t_vector *vec)
{
	if (size < 3)
		return (error("invalid map."));
	if (!check_is_compact(map, size))
		return (error("invalid map."));
	if (!check_wall(map, size))
		return (error("Map is not close."));
	if (!check_start_pos(map, size, vec))
		return (0);
	if (!check_opening(map, size))
		return (error("iinvalid map."));
	return (1);
}
