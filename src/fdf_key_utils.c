/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:01:26 by mescobar          #+#    #+#             */
/*   Updated: 2023/08/24 13:45:31 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

void	ft_refresh(t_fdf *l)
{
	if (l->img->img_ptr)
		mlx_destroy_image(l->mlx, l->img->img_ptr);
	ft_put_image(l);
}

void	ft_reset(t_fdf *l)
{
	float	tmp;
	float	x;
	float	y;

	y = l->ctrl->y;
	x = l->ctrl->x;
	tmp = l->cam->zoom;
	ft_init(l);
	l->ctrl->x = x;
	l->ctrl->y = y;
	l->cam->zoom = tmp;
	l->cam->angle = 20;
	l->cam->angle2 = 35;
	ft_refresh(l);
}
