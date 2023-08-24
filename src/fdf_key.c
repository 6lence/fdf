/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:45:42 by mescobar          #+#    #+#             */
/*   Updated: 2023/08/24 18:45:49 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

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

static void	set_zoom(int key, t_fdf *l)
{
	double	a;
	double	b;

	a = l->cam->zoom / l->y1;
	b = l->cam->zoom / l->x1;
	if (key == ZOOM)
	{
		l->cam->zoom += 0.5;
		l->ctrl->x -= b;
		l->ctrl->y -= a;
	}
	if (key == DEZOOM && l->cam->zoom > 0)
	{
		l->cam->zoom -= 0.5;
		l->ctrl->x += b;
		l->ctrl->y += a;
	}
}

static void	set_all_angles(int key, t_fdf *l)
{
	if (key == XK_q || key == XK_Q)
		l->cam->angle -= 5;
	if (key == XK_e || key == XK_E)
		l->cam->angle += 5;
	if (key == XK_r || key == XK_R)
		l->cam->angle2 -= 5;
	if (key == XK_f || key == XK_F)
		l->cam->angle2 += 5;
}

int	key_hook(int key, t_fdf *l)
{
	if (key == XK_Escape)
	{
		ft_free_all(l);
		exit(EXIT_SUCCESS);
	}
	set_zoom(key, l);
	set_all_angles(key, l);
	if (key == XK_t)
		set_dim(l, 0, 0);
	if (key == XK_y)
		set_dim(l, 0, 90);
	if (key == XK_u)
		set_dim(l, 45, 45);
	ft_move(key, l);
	ft_refresh(l);
	return (0);
}
