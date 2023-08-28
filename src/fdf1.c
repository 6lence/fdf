/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:02:22 by mescobar          #+#    #+#             */
/*   Updated: 2023/08/28 11:41:29 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

static char	*ft_strjoin2(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (s1[i])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	return (res[i] = 0, free(s1), res);
}

static char	**ft_get_open(char *map, t_fdf *fdf)
{
	char	**antaunio;
	char	*line;
	char	*buffer;
	int		r;

	fdf->file = open(map, O_RDONLY);
	if (fdf->file < 0 || read(fdf->file, 0, 0))
		ft_exit("Opening file error ", fdf);
	line = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(1, 1024);
	if (!buffer || !line)
		ft_exit("Malloc error ", fdf);
	r = 1;
	while (r != 0)
	{
		r = read(fdf->file, buffer, 1024);
		buffer[r] = '\0';
		line = ft_strjoin2(line, buffer);
	}
	antaunio = ft_split(line, '\n');
	free(buffer);
	free(line);
	close(fdf->file);
	return (antaunio);
}

static void	ft_char_int(char *str, t_fdf *l)
{
	char	**new;
	char	***tmp;
	int		i;
	int		j;

	new = ft_get_open(str, l);
	tmp = ft_split_triple((char const **)new, ' ');
	if (!tmp)
		ft_exit("Map creation error ", l);
	ft_db_malloc(tmp, l);
	ft_tmp_map(tmp, l);
	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
			free(tmp[i][j++]);
		free(tmp[i]);
		i++;
	}
	free(tmp);
	i = 0;
	while (i < l->h)
		free(new[i++]);
	free(new);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (0);
	fdf = ft_calloc(1, sizeof(t_fdf));
	fdf->img = ft_calloc(1, sizeof(t_image));
	fdf->cam = ft_calloc(1, sizeof(t_camera));
	fdf->ctrl = ft_calloc(1, sizeof(t_ctrl));
	ft_char_int(argv[1], fdf);
	ft_init(fdf);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_width,
			fdf->win_height, "--FDF--");
	ft_put_image(fdf);
	mlx_hook(fdf->win, KeyPress, KeyPressMask, key_hook, fdf);
	mlx_hook(fdf->win, 17, 0L, close_prog, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
