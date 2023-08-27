/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:46:44 by mescobar          #+#    #+#             */
/*   Updated: 2023/08/26 20:08:13 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

void	ft_put_pixel(t_fdf *l, int y, int x)
{
	l->pixel = (y * l->img->line) + x * 4;
	ft_endian(l);
}

void	ft_endian(t_fdf *l)
{
	if (l->img->endian == 1)
	{
		l->img->addr_img[l->pixel + 0] = (l->img->color >> 24);
		l->img->addr_img[l->pixel + 1] = (l->img->color >> 16) & 0xFF;
		l->img->addr_img[l->pixel + 2] = (l->img->color >> 8) & 0xFF;
		l->img->addr_img[l->pixel + 3] = (l->img->color) & 0xFF;
	}
	else
	{
		l->img->addr_img[l->pixel + 0] = (l->img->color) & 0xFF;
		l->img->addr_img[l->pixel + 1] = (l->img->color >> 8) & 0xFF;
		l->img->addr_img[l->pixel + 2] = (l->img->color >> 16) & 0xFF;
		l->img->addr_img[l->pixel + 3] = (l->img->color >> 24);
	}
}

void	line(t_fdf *l, t_point pt1, t_point pt2)
{
	pt1.x *= l->cam->zoom;
	pt1.y *= l->cam->zoom;
	pt2.x *= l->cam->zoom;
	pt2.y *= l->cam->zoom;
	pt1.x += l->ctrl->x;
	pt1.y += l->ctrl->y;
	pt2.x += l->ctrl->x;
	pt2.y += l->ctrl->y;
	l->dx = pt2.x - pt1.x;
	l->dy = pt2.y - pt1.y;
	l->m = ft_max(ft_abs(l->dx), ft_abs(l->dy));
	l->dx /= l->m;
	l->dy /= l->m;
	l->img->color = pt1.color;
	while (((int)(pt1.x - pt2.x) || (int)(pt1.y - pt2.y)))
	{
		if (pt1.x < l->win_width && pt1.x > 0 && pt1.y < l->win_height
			&& pt1.y > 0)
			ft_put_pixel(l, (int)pt1.y, (int)pt1.x);
		pt1.x += l->dx;
		pt1.y += l->dy;
	}
}

static void	ft_drawing(t_fdf *l)
{
	if (l->x1 < l->l - 1)
		line(l, proj(l, l->y1, l->x1), proj(l, l->y1, l->x1 + 1));
	if (l->y1 < l->h - 1)
		line(l, proj(l, l->y1, l->x1), proj(l, l->y1 + 1, l->x1));
	l->x1++;
}

void	ft_put_image(t_fdf *l)
{
	l->img->img_ptr = mlx_new_image(l->mlx, l->img->width, l->img->height);
	l->img->addr_img = mlx_get_data_addr(l->img->img_ptr, &l->img->bpp,
			&l->img->line, &l->img->endian);
	l->y1 = 0;
	while (l->y1 < l->h)
	{
		l->x1 = 0;
		while (l->x1 < l->l)
			ft_drawing(l);
		l->y1++;
	}
	mlx_put_image_to_window(l->mlx, l->win, l->img->img_ptr,
		0, 0);
	draw_controls(l);
}
