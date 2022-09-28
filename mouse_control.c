/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:56:03 by tamchoor          #+#    #+#             */
/*   Updated: 2022/02/02 12:13:03 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_mouse_press(int button, int x, int y, t_fdf *fdf)
{
	if (button == 1)
	{
		fdf->key.press_x = x;
		fdf->key.press_y = y;
		fdf->key.button = 1;
	}
	return (0);
}

int	deal_mouse_release(int button, int x, int y, t_fdf *fdf)
{
	if (button == 1)
	{
		fdf->key.button = 0;
	}
	x = 0;
	y = 0;
	return (0);
}

int	deal_mouse_move(int x, int y, t_fdf *fdf)
{
	if (fdf->key.button != 0)
	{
		fdf->key.angl_x = fdf->key.angl_x + (x - fdf->key.press_x) * 0.002;
		fdf->key.angl_y = fdf->key.angl_y + (y - fdf->key.press_y) * 0.002;
		fdf->key.press_x = x;
		fdf->key.press_y = y;
		fdf->clear = 1;
		draw(&fdf);
	}
	return (0);
}
