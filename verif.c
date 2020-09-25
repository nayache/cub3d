#include "cub3d.h"

static int	check_path(char *path, char c)
{
	int fd;
	
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		if (c == 'N')
			return (error("failed to load north texture."));
		if (c == 'S')
			return (error("failed to load south texture."));
		if (c == 'E')
			return (error("failed to load east texture."));
		if (c == 'W')
			return (error("failed to load west texture."));
		if (c == 'P')
			return (error("failed to load sprite texture."));
	}
	close(fd);
	return (1);
}

static int	verif_path(t_path path)
{
	if (!check_path(path.north, 'N'))
		return (0);
	if (!check_path(path.south, 'S'))
		return (0);
	if (!check_path(path.east, 'E'))
		return (0);
	if (!check_path(path.west, 'W'))
		return (0);
	if (!check_path(path.sprite, 'P'))
		return (0);
	return (1);
}



int			verif_datas(t_info *info)
{
	if (!verif_path(info->path))
		return (0);
	if (!verif_map(info->map, info->map_h, &info->vec))
		return (0);
	return (1);
}
