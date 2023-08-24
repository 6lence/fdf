/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:45:42 by mescobar          #+#    #+#             */
/*   Updated: 2023/08/24 10:39:32 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

static void	ft_free_all(t_fdf *l)
{
	int	i;

	if (l->map)
	{
		i = 0;
		while (i < l->h)
		{
			free(l->map[i]);
			free(l->color[i]);
			i++;
		}
	}
	if (l->img->img_ptr)
		mlx_destroy_image(l->mlx, l->img->img_ptr);
	if (l->mlx)
	{
		mlx_destroy_window(l->mlx, l->win);
		mlx_destroy_display(l->mlx);
	}
}

static void	ft_move(int key, t_fdf *l)
{
	float	a;
	float	b;

	b = l->win_height / 3 / 10;
	a = l->win_width / 3 / 10;
	if (key == XK_w)
		l->ctrl->y -= b;
	if (key == XK_s)
		l->ctrl->y += b;
	if (key == XK_d)
		l->ctrl->x += a;
	if (key == XK_a)
		l->ctrl->x -= a;
	if (key == XK_n)
		l->cam->alt_z += 0.1;
	if (key == XK_m)
		l->cam->alt_z -= 0.1;
	if (key == XK_x)
		ft_reset(l);
}

static void	set_dim(t_fdf *l, int a, int b)
{
	l->cam->angle = a;
	l->cam->angle2 = b;
}

int	key_hook(int key, t_fdf *l)
{
	if (key == XK_Escape)
	{
		ft_free_all(l);
		exit(EXIT_SUCCESS);
	}
	if (key == ZOOM)
		l->cam->zoom += 0.5;
	if (key == DEZOOM && l->cam->zoom > 0)
		l->cam->zoom -= 0.5;
	if (key == XK_q || key == XK_Q)
		l->cam->angle -= 5;
	if (key == XK_e || key == XK_E)
		l->cam->angle += 5;
	if (key == XK_r || key == XK_R)
		l->cam->angle2 -= 5;
	if (key == XK_f || key == XK_F)
		l->cam->angle2 += 5;
	if (key == XK_t)
		set_dim(l, 0, 45);
	if (key == XK_y)
		set_dim(l, 45, 25);
	ft_move(key, l);
	ft_refresh(l);
	return (0);
}
