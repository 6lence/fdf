/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:25:13 by miguel            #+#    #+#             */
/*   Updated: 2023/08/26 20:08:15 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

#define MENU_TAB 30
#define LINE_SIZE 30
#define CONTROL_BOX 280
#define TEXT_COLOR 0xEAEAEA

static void	print_str(t_fdf *map, int x, int y, char *str)
{
	mlx_string_put(map->mlx, map->win, x, y, TEXT_COLOR, str);
}

void	draw_controls(t_fdf *map)
{
	int	line;

	line = CONTROL_BOX;
	print_str(map, MENU_TAB, line, "CONTROLS");
	line += LINE_SIZE;
	print_str(map, MENU_TAB, line, "Arrow Up/Down : Zoom in/out");
	line += LINE_SIZE;
	print_str(map, MENU_TAB, line, "WASD : Movement");
	line += LINE_SIZE;
	print_str(map, MENU_TAB, line, "Q-E : Rotate");
	line += LINE_SIZE;
	print_str(map, MENU_TAB, line, "R-F : Change Angle");
	line += LINE_SIZE;
	print_str(map, MENU_TAB, line, "N-M : Change Altitude");
	line += LINE_SIZE;
	print_str(map, MENU_TAB, line, "X : Reset All");
	line += LINE_SIZE;
	print_str(map, MENU_TAB, line, "T : Set to 2d view");
	line += LINE_SIZE;
	print_str(map, MENU_TAB, line, "Y : Set to Altitude view");
	line += LINE_SIZE;
	print_str(map, MENU_TAB, line, "U : Set to Isometric");
}
