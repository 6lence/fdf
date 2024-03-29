/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:25:30 by mescobar          #+#    #+#             */
/*   Updated: 2023/08/26 20:32:37 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

void	ft_db_malloc(char ***tmp, t_fdf *l)
{
	int	i;
	int	j;

	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
			j++;
		i++;
	}
	l->h = i;
	l->l = j;
	l->map = ft_calloc(sizeof(int *), i);
	l->color = ft_calloc(sizeof(unsigned long *), i);
	i = 0;
	while (i < l->h)
	{
		l->color[i] = ft_calloc(sizeof(unsigned long), j);
		l->map[i++] = ft_calloc(sizeof(int), j);
	}
}

unsigned long	ft_color(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == ',')
			return (ft_atoi_base(ft_strchr(tmp, ',') + 3, 16));
		i++;
	}
	return (0);
}

void	ft_tmp_map(char ***tmp, t_fdf *l)
{
	int	i;
	int	j;

	i = 0;
	while (i < l->h)
	{
		j = 0;
		while (j < l->l)
		{
			l->map[i][j] = ft_atoi(tmp[i][j]);
			l->color[i][j] = ft_color(tmp[i][j]);
			j++;
		}
		i++;
	}
}

char	***ft_split_triple(char const **s, char c)
{
	char	***tab;
	int		l;

	l = 0;
	tab = ft_calloc(sizeof(char **), ft_eny(s) + 1);
	while (s[l])
		l = ft_split_new(l, tab, s, c);
	if (l == 0)
		return (NULL);
	return (tab);
}

void	ft_init(t_fdf *l)
{
	l->win_width = 1820;
	l->win_height = 1080;
	l->tmph = l->img->height / l->h;
	l->tmpl = l->img->width / l->l;
	l->img->height = l->win_height;
	l->img->width = l->win_width;
	l->cam->alt_z = 0.1;
	l->cam->zoom = 10;
	l->cam->angle = 45;
	l->cam->angle2 = 45;
	l->ctrl->x = (l->win_width / 2 - ((l->l / 2) * l->cam->zoom));
	l->ctrl->y = (l->win_height / 2 - ((l->h / 2) * l->cam->zoom));
}
