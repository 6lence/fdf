/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:03:18 by mescobar          #+#    #+#             */
/*   Updated: 2023/08/24 10:16:21 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

int	ft_get_z(t_fdf *l, int y, int x)
{
	y = (y - l->tmph / 2) / l->tmph;
	x = (x - l->tmpl / 2) / l->tmpl;
	return (l->map[y][x]);
}

double	deg_to_rad(int x)
{
	return (x * (M_PI / 180.0F));
}

t_point	proj(t_fdf *l, int y, int x)
{
	t_point	pt;
	double	z;

	z = (double)l->map[y][x] * l->cam->alt_z;
	pt.color = ft_get_color(l, y, x);
	pt.x = x * cos(deg_to_rad(l->cam->angle))
		+ y * -sin(deg_to_rad(l->cam->angle));
	pt.y = x * sin(deg_to_rad(l->cam->angle))
		* cos(deg_to_rad(l->cam->angle2))
		+ y * cos(deg_to_rad(l->cam->angle)) * cos(deg_to_rad(l->cam->angle2))
		+ z * -sin(deg_to_rad(l->cam->angle2));
	pt.z = z;
	return (pt);
}
