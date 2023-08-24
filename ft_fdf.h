/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:58:08 by mescobar          #+#    #+#             */
/*   Updated: 2023/08/24 23:31:02 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "src/ft_printf/ft_printf.h"
# include "src/minilibx-linux/mlx.h"
# include <unistd.h>
# include <sys/types.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ZOOM 65362
# define DEZOOM 65364
# define M_PI 3.14159265358979323846

typedef struct s_ctrl
{
	int	x;
	int	y;
}		t_ctrl;

typedef struct s_image
{
	void			*img_ptr;
	char			*addr_img;
	int				height;
	int				width;
	int				x;
	int				y;
	unsigned int	color;
	int				bpp;
	int				line;
	int				endian;
}					t_image;

typedef struct s_point
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
}		t_point;

typedef struct s_camera
{
	double	angle;
	double	angle2;
	double	alt_z;
	double	zoom;
}		t_camera;

typedef struct s_fdf
{
	int				**map;	
	unsigned long	**color;
	void			*mlx;
	void			*win;
	int				win_width;
	int				win_height;
	int				file;
	int				pixel;
	int				h;
	int				l;
	int				tmph;
	int				tmpl;
	int				x1;
	int				y1;
	float			dx;
	float			dy;
	int				d;
	int				de;
	int				dne;
	int				m;
	int				ayo;
	t_camera		*cam;
	t_image			*img;
	t_ctrl			*ctrl;
}					t_fdf;

void			ft_init(t_fdf *l);
void			ft_init1(t_fdf *n);
void			ft_exit(char *str);
void			ft_get_map(char *str, t_fdf *l);
void			ft_put_image(t_fdf *l);
int				ft_get_color(t_fdf *l, int i, int j);
char			***ft_split_triple(char const **s, char c);
int				ft_split_new(int l, char ***tab, char const **s, char c);
int				ft_eny(const char **str);
int				ft_atoi_base(const char *str, int str_base);
void			ft_db_malloc(char ***tmp, t_fdf *l);
void			ft_tmp_map(char ***tmp, t_fdf *l);
void			ft_endian(t_fdf *l);
void			ft_swap(int *a, int *b);
void			ft_swap_more(int *a, int *a1, int *b, int *b1);
void			ft_put_pixel(t_fdf *l, int y, int x);
void			ft_horizontal(t_fdf *l, t_point pt1, t_point pt2);
void			ft_vertical(t_fdf *l, t_point pt1, t_point pt2);
void			last_line(t_fdf *l);
t_point			proj(t_fdf *l, int y, int x);
void			bresenham(t_fdf *l, t_point pt1, t_point pt2);
int				key_hook(int key, t_fdf *l);
void			ft_reset(t_fdf *l);
void			ft_refresh(t_fdf *l);
int				ft_abs(int a);
double			deg_to_rad(int x);
void			ft_free_all(t_fdf *l);
void			draw_controls(t_fdf *map);

#endif