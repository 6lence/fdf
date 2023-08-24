/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:02:22 by mescobar          #+#    #+#             */
/*   Updated: 2023/08/25 00:25:54 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

int	ft_abs(int a)
{
	if (a < 0)
		return ((a * -1));
	return (a);
}

static char	**ft_get_open(char *map, t_fdf *fdf)
{
	char	**antaunio;
	char	*line;
	char	*buffer;
	int		r;

	fdf->file = open(map, O_RDONLY);
	if (fdf->file < 0 || read(fdf->file, 0, 0))
		ft_exit("Opening file error: ");
	line = ft_calloc(sizeof(char), 1);
	buffer = malloc(1024);
	if (!buffer)
		ft_exit("Buffer malloc error: ");
	r = 1;
	while (r != 0)
	{
		r = read(fdf->file, buffer, 1024);
		buffer[r] = '\0';
		line = ft_strjoin(line, buffer);
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
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_width, fdf->win_height, "FDF");
	ft_put_image(fdf);
	mlx_hook(fdf->win, KeyPress, KeyPressMask, key_hook, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
