/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:55:58 by tamchoor          #+#    #+#             */
/*   Updated: 2022/02/02 12:13:14 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_shift(int key, t_fdf *fdf)
{
	if (key == 126)
		fdf->key.shift_y = fdf->key.shift_y - 10;
	else if (key == 125)
		fdf->key.shift_y = fdf->key.shift_y + 10;
	else if (key == 123)
		fdf->key.shift_x = fdf->key.shift_x - 10;
	else if (key == 124)
		fdf->key.shift_x = fdf->key.shift_x + 10;
}

void	ft_zoom(int key, t_fdf *fdf)
{
	if (key == 24)
		fdf->zoom = fdf->zoom + 2;
	else if (key == 27)
		fdf->zoom = fdf->zoom - 2;
}

int	key_control(int key, t_fdf *fdf)
{
	if (key >= 123 && key <= 126)
		ft_shift(key, &(*fdf));
	else if (key == 53)
		exit (0);
	else if (key == 18)
		fdf->key.change_z = fdf->key.change_z + 10;
	else if (key == 19)
		fdf->key.change_z = fdf->key.change_z - 10;
	else if (key == 24 || key == 27)
		ft_zoom(key, &(*fdf));
	else if (key == 35)
	{
		fdf->key.angl_x = 0;
		fdf->key.angl_y = 0;
		fdf->key.change_z = 0;
	}
	else
		return (0);
	fdf->clear = 1;
	draw(&fdf);
	return (0);
}
