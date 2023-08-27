/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:45:42 by mescobar          #+#    #+#             */
/*   Updated: 2023/08/26 20:08:15 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

static void	ft_move(int key, t_fdf *l)
{
	if (key == XK_w)
		l->ctrl->y -= 10;
	if (key == XK_s)
		l->ctrl->y += 10;
	if (key == XK_d)
		l->ctrl->x += 10;
	if (key == XK_a)
		l->ctrl->x -= 10;
	if (key == XK_n)
		l->cam->alt_z += 0.05;
	if (key == XK_m)
		l->cam->alt_z -= 0.05;
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
	float	a;

	a = 1.0;
	if (key == ZOOM)
	{
		l->cam->zoom += a;
		l->ctrl->x -= a * (l->l / 2);
		l->ctrl->y -= a * (l->h / 2);
	}
	if (key == DEZOOM && l->cam->zoom > 1)
	{
		l->cam->zoom -= a;
		l->ctrl->x += a * (l->l / 2);
		l->ctrl->y += a * (l->h / 2);
	}
}

static void	set_all_angles(int key, t_fdf *l)
{
	int	a;

	a = 5;
	if (key == XK_q || key == XK_Q)
		l->cam->angle -= a;
	if (key == XK_e || key == XK_E)
		l->cam->angle += a;
	if (key == XK_r || key == XK_R)
		l->cam->angle2 -= a;
	if (key == XK_f || key == XK_F)
		l->cam->angle2 += a;
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
