/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:01:26 by mescobar          #+#    #+#             */
/*   Updated: 2023/08/26 20:36:37 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

int	close_prog(t_fdf *l)
{
	ft_free_all(l);
	exit(EXIT_SUCCESS);
	return (0);
}

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

static void	ft_free_struct(t_fdf *l)
{
	free(l->mlx);
	free(l->img);
	free(l->cam);
	free(l->ctrl);
	free(l);
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
			free(l->color[i++]);
		}
		free(l->map);
		free(l->color);
	}
	if (l->img->img_ptr)
		mlx_destroy_image(l->mlx, l->img->img_ptr);
	if (l->mlx)
	{
		mlx_destroy_window(l->mlx, l->win);
		mlx_destroy_display(l->mlx);
	}
	ft_free_struct(l);
}
