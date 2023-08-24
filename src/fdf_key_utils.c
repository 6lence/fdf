/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:01:26 by mescobar          #+#    #+#             */
/*   Updated: 2023/08/24 17:53:05 by miguel           ###   ########.fr       */
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
	ft_init(l);
	ft_refresh(l);
}

void	ft_free_all(t_fdf *l)
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
	free(l->mlx);
}
