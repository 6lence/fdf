/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:14:12 by mescobar          #+#    #+#             */
/*   Updated: 2023/08/23 03:25:17 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

void	ft_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	ft_get_color(t_fdf *l, int y, int x)
{
	int	color;

	if (!l->color[y][x])
		color = mlx_get_color_value(l->mlx, 0xFFFFFF);
	else
		color = mlx_get_color_value(l->mlx, l->color[y][x]);
	return (color);
}

