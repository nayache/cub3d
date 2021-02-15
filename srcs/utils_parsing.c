#include "cub3d.h"

void	print_info(t_info *info)
{
	int i;
	
	i = 0;
	printf("%d %d\nNO %s\nSO %s\nEA %s\nWE %s\nS %s\n%d\n%d\n", info->width, 
	info->height, info->path.north, info->path.south, info->path.east, 
	info->path.west, info->path.sprite, info->color.floor, info->color.ceiling);
	if (info->map[i] != NULL)
	{
		while (i < info->map_h)
		{
			printf("%s\n", info->map[i]);
			i++;
		}
	}
}

int		str_num(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_num(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		traduct_count(char *str)
{
	int count;

	if (ft_strcmp(str, "R") == 0)
		count = 0;
	if (ft_strcmp(str, "NO") == 0 || ft_strcmp(str, "SO") == 0)
		count = 1;
	if (ft_strcmp(str, "EA") == 0 || ft_strcmp(str, "WE") == 0)
		count = 1;
	if (ft_strcmp(str, "S") == 0)
		count = 1;
	if (ft_strcmp(str, "C") == 0 || ft_strcmp(str, "F") == 0)
		count = 2;
	return (count);
}

int		check_id(char *str, int count)
{
	const char	id[8][3] = {"R\0", "NO\0", "SO\0", "WE\0", "EA\0", "S\0",
	"F\0", "C\0"};

	if (count == 8)
		return (-1);
	if (ft_strcmp(str, (char *)id[count]) == 0)
		return (count);
	else
		return (check_id(str, count + 1));
}

int		verif_color(char *str)
{
	int i;
	int	count;

	count = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == ',')
		{
				count++;
			if (str[i] == ',' && i == 0)
				return (0);
			if (str[i] == ',' && !is_num(str[i + 1]) && !is_num(str[i - 1]))
				return (0);
		}
		else
			if (is_num(str[i]) == 0)
				return (0);
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}

