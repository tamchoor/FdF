/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:45:56 by tamchoor          #+#    #+#             */
/*   Updated: 2022/02/03 11:45:57 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_background(t_fdf ***fdf)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_pixel_put(x, y, PURPLE, &fdf);
			x++;
		}
		y++;
	}
}

void	ft_print_menu(t_fdf ***fdf)
{
	mlx_string_put((**fdf)->mlx, (**fdf)->win, 15, 35, BLUE, "Zoom: +/-");
	mlx_string_put((**fdf)->mlx, (**fdf)->win, 15, 50, BLUE,
		"Rotate: Press mouse & move");
	mlx_string_put((**fdf)->mlx, (**fdf)->win, 15, 65, BLUE, "Parallel: P Key");
	mlx_string_put((**fdf)->mlx, (**fdf)->win, 15, 95, BLUE,
		"Translate: </> || ^/v");
	mlx_string_put((**fdf)->mlx, (**fdf)->win, 15, 110, BLUE, "Altitude: 1/2");
}
