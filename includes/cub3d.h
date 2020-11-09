#ifndef CUB_H
#define CUB_H

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "libft.h"
#include "mlx.h"
#define texwidth 64
#define texheight 64

typedef	struct	s_list	s_list;
struct	s_list
{
	char	*str;
	s_list	*next;
};

	typedef	struct	s_element
	{
		int			start;
		int			end;
	}				t_element;

	typedef	struct	s_vector
	{
		double		posx;
		double		posy;
		double		dirx;
		double		diry;
		double		planex;
		double		planey;
		double		camerax;
		double		raydirx;
		double		raydiry;
		int			stepx;
		int			stepy;
		int			mapx;
		int			mapy;
		int			side;
		double		sidedistx;
		double		sidedisty;
		double		deltadistx;
		double		deltadisty;
		double		perpwalldist;
		double		oldplanex;
		double		oldirx;
		double		rotspeed;
		double		movespeed;

	}				t_vector;

	typedef struct	s_spvector
	{
		double		invdet;
		double		spritex;
		double		spritey;
		double		transformy;
		double		transformx;
		double		spr_screenx;
		int			sprite_h;
		int			sprite_w;
		int			drawstarty;
		int			drawstartx;
		int			drawendy;
		int			drawendx;
		int			texx;
		int			texy;
	}				t_spvector;
	
	typedef	struct  s_txt
	{
		double		wallx;
		double		step;
		double		texpos;
		int			texX;
		int			texY;
		int			lineheight;
	}				t_txt;

	typedef struct	s_path
	{
		char		*north;
		char		*south;
		char		*west;
		char		*east;
		char		*sprite;
	}				t_path;

	typedef struct		s_color
	{
		int				floor;
		int				ceiling;
	}					t_color;
	
	typedef struct 	s_sprite
	{
		double		y;
		double		x;
	}				t_sprite;
	
	typedef struct	s_win
	{
		void		*mlx_ptr;
		void		*win_ptr;
		void		*img_ptr;
		char		*img;
		int			bpp;
		int			sl;
		int			endian;
	}				t_win;

	typedef	struct	s_key
	{
		int			esc;
		int			up;
		int			down;
		int			left;
		int			right;
		int			rotr;
		int			rotl;
	}				t_key;
	
	typedef struct	t_pos	t_pos;
	struct	t_pos
	{
		double			y;
		double			x;
		t_pos		*next;
	};

	typedef struct	s_info
	{
		int			height;
		int			width;
		char		**map;
		int			map_h;
		int			map_w;
		int			sl;
		int			bpp;
		int			endian;
		void		**ptrs;
		int			**texture;
		int			**buffer;
		double		*zbuffer;
		double		spr_dist;
		int			size_sprite;
		t_color     color;
		t_vector	vec;
		t_path		path;
		t_win		win;
		t_txt		txt;
		t_sprite	*sprite;
		t_spvector	svec;
		t_key		key;
	}				t_info;

int		save_sprites(t_info *info);
void	free_map(char **map, int size);
void	free_list(s_list *token);
void	free_path(t_path *path);
void	free_buffer(t_info *info);
int		exit_game(t_info *info);
void	init_start_camera(t_vector *vec, int c);
int		check_opening(char **map, int size);
int		check_wall(char **map, int size);
int		verif_map(char **map, int size, t_vector *vec);
void	sort_sprites(double *dist, t_info *info, int size);
int		is_line_map(char *str);
int		traduct_count(int count);
void	free_split(char **tab);	
void	print_info(t_info *info);
int		str_num(char *str);
int		check_id(char *str, int count);
int		verif_color(char *str);
int		verif_format(char *str);
int		check_tokens(s_list *token);
int		parse_tokens(s_list *token, t_info *info);
int		parse_map_tokens(s_list *token, t_info *info);
int		size_map(s_list *token);
s_list	*init_elem(s_list *elem);
void	free_tab(char **tab, char *line);
int		lst_add(s_list *first, char *s);
void	print_lst(s_list *token);
int		is_empty(char **tab);	
int		save_tokens(s_list *token, int fd, char *sep);
int		save_datas(t_info *info, char *file);
int		raycast(t_info *info);
int		get_next_line(int fd, char **line);
int		error(char *s);
int		is_space(char c);
int		is_num(char c);
int		is_valid(char c);
int		is_pos(char c);
void	draw(t_info *info, t_element *draw_tab);
void	get_color(t_info *info);
void	pixel_put(char *img, int x, char *color, int endian);
void	turn_right(t_vector *vec);
void	turn_left(t_vector *vec);
void	move_up(char ***map, t_vector *vec);
void	move_down(char ***map, t_vector *vec);
void	move_left(char ***map, t_vector *vec);
void	move_right(char ***map, t_vector *vec);
void	print_intro(t_info info);
int		init_texture(t_info *info);
void	texture_cast(t_info *info, int drawstart, int drawend, int y);
void	sprite_cast(t_info *info);
int		verif_datas(t_info *info);
void	init_info(t_info *info);
void	event_key(t_info *info);
#endif
