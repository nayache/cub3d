#include "cub3d.h"

static int		write_datas(int fd, t_info *info, int empty_px)
{
	int				w;
	int				h;
	int				i;
	char			str[empty_px];

	h = info->height - 1;
	i = 0;
	while (h >= 0)
	{
		w = 0;
		while (w < info->width)
		{
			write(fd, info->win.img + (info->sl * h) + (w * 4), 4);
			w++;
		}
		h--;
	}
	if (empty_px > 0)
	{
		ft_bzero(str, empty_px);
		write(fd, str, empty_px);
	}
	return (0);
}

static void		write_header(int fd, t_info *info, t_bmp info_bmp)
{
	write(fd, "BM", 2);
	write(fd, &info_bmp.size_file, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &info_bmp.first_px, 4);
	write(fd, &info_bmp.size_infoheader, 4);
	write(fd, &info->width, 4);
	write(fd, &info->height, 4);
	write(fd, &info_bmp.plane, 2);
	write(fd, &info->bpp, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &info_bmp.size_px, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

static void		init_info_bmp(t_bmp *info_bmp, int width, int height)
{
	info_bmp->plane = 1;
	info_bmp->first_px = 54;
	info_bmp->size_infoheader = 40;
	info_bmp->size_file = info_bmp->first_px + ((width * height) * 4);
	info_bmp->size_px = (width * height);
	info_bmp->empty_px = 0;
	while (info_bmp->size_file % 4 != 0)
	{
		info_bmp->size_file++;
		info_bmp->empty_px++;
	}
}

int		screenshot(t_info *info)
{
	t_bmp	info_bmp;
	int		fd;

	init_info_bmp(&info_bmp, info->width, info->height);
	fd = open("screenshot.bmp", O_RDWR | O_CREAT, S_IRWXU);
	if (fd < 0)
		return (error("cant open info_bmp file."));
	write_header(fd, info, info_bmp);
	raycast(info);
	write_datas(fd, info, info_bmp.empty_px);	
	close(fd);
	return (exit_game(info));
}
