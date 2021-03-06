/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <nico.ayache@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:54:34 by nayache           #+#    #+#             */
/*   Updated: 2021/02/18 22:09:40 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define TEXWIDTH 64
# define TEXHEIGHT 64
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "mlx.h"

# ifdef __linux__

#  define ESC	65307
#  define ROTL	65361
#  define ROTR	65363
#  define UP	119
#  define DOWN	115
#  define RIGHT	100
#  define LEFT	97

# else

#  define ESC	53
#  define ROTL	123
#  define ROTR	124
#  define UP	13
#  define DOWN	1
#  define RIGHT	2
#  define LEFT	0

# endif

typedef	struct	s_list
{
	char			*str;
	struct s_list	*next;
}				t_list;

typedef	struct	s_element
{
	int				start;
	int				end;
}				t_element;

typedef	struct	s_vector
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				stepx;
	int				stepy;
	int				mapx;
	int				mapy;
	int				side;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			oldplanex;
	double			oldirx;
	double			rotspeed;
	double			movespeed;

}				t_vector;

typedef struct	s_spvector
{
	double			invdet;
	double			spritex;
	double			spritey;
	double			transformy;
	double			transformx;
	double			spr_screenx;
	int				sprite_h;
	int				sprite_w;
	int				drawstarty;
	int				drawstartx;
	int				drawendy;
	int				drawendx;
	int				texx;
	int				texy;
}				t_spvector;

typedef	struct	s_txt
{
	double			wallx;
	double			step;
	double			texpos;
	int				texx;
	int				texy;
	int				lineheight;
}				t_txt;

typedef struct	s_path
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
}				t_path;

typedef struct	s_color
{
	int				floor;
	int				ceiling;
}				t_color;

typedef struct	s_sprite
{
	double			y;
	double			x;
}				t_sprite;

typedef struct	s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img;
	int				bpp;
	int				sl;
	int				endian;
}				t_win;

typedef	struct	s_key
{
	int				esc;
	int				up;
	int				down;
	int				left;
	int				right;
	int				rotr;
	int				rotl;
}				t_key;

typedef struct	s_pos
{
	double			y;
	double			x;
	struct s_pos	*next;
}				t_pos;

typedef	struct	s_bmp
{
	unsigned int	first_px;
	unsigned int	size_infoheader;
	unsigned int	size_file;
	unsigned int	size_px;
	unsigned int	empty_px;
	unsigned int	plane;
}				t_bmp;

typedef struct	s_info
{
	int				height;
	int				width;
	char			**map;
	int				map_h;
	int				map_w;
	int				sl;
	int				bpp;
	int				endian;
	void			**ptrs;
	int				**texture;
	int				**buffer;
	double			*zbuffer;
	double			spr_dist;
	int				size_sprite;
	int				screenshot;
	t_color			color;
	t_vector		vec;
	t_path			path;
	t_win			win;
	t_txt			txt;
	t_sprite		*sprite;
	t_spvector		svec;
	t_key			key;
}				t_info;

int				save_sprites(t_info *info);
void			free_map(char **map, int size);
void			free_list(t_list *token);
void			free_path(t_path *path);
void			free_buffer(t_info *info);
int				exit_game(t_info *info);
void			init_start_camera(t_vector *vec, int c);
int				check_opening(char **map, int size);
int				verif_map(char **map, int size, t_vector *vec);
void			sort_sprites(double *dist, t_info *info, int size);
int				is_line_map(char *str);
int				traduct_count(char *str);
void			free_split(char **tab);
int				check_occurence(char *s1, const char s2[8][3], int size);
int				only_num(char *str);
int				str_num(char *str);
int				check_id(char *str, int count);
int				verif_color(char *str);
int				verif_format(char *str);
int				check_tokens(t_list *token);
int				parse_tokens(t_list *token, t_info *info);
int				parse_map_tokens(t_list *token, t_info *info);
int				size_map(t_list *token);
t_list			*init_elem(t_list *elem);
void			free_tab(char **tab, char *line);
int				lst_add(t_list *first, char *s);
void			print_lst(t_list *token);
int				is_empty(char **tab);
int				save_tokens(t_list *token, int fd, char *sep);
int				save_datas(t_info *info, char *file);
int				raycast(t_info *info);
int				get_next_line(int fd, char **line);
int				error(char *s);
int				is_space(char c);
int				is_num(char c);
int				is_valid(char c);
int				is_pos(char c);
void			draw(t_info *info, t_element *draw_tab);
void			get_color(t_info *info);
void			pixel_put(char *img, int x, char *color, int endian);
void			turn_right(t_vector *vec);
void			turn_left(t_vector *vec);
void			move_up(char ***map, t_vector *vec);
void			move_down(char ***map, t_vector *vec);
void			move_left(char ***map, t_vector *vec);
void			move_right(char ***map, t_vector *vec);
void			print_intro(t_info info);
int				init_texture(t_info *info);
void			texture_cast(t_info *info, int drawstart, int drawend,
				int y);
void			sprite_cast(t_info *info);
int				verif_datas(t_info *info);
void			init_info(t_info *info);
int				key_press(int keycode, t_info *info);
int				key_release(int keycode, t_info *info);
void			event_key(t_info *info);
int				screenshot(t_info *info);
int				save_to_list(t_list *token, char **tab);
void			init_distance(double *dist, t_info *info, int size);
int				check_wall(char **map, int size);
int				check_start_pos(char **map, int size, t_vector *vec);
#endif
