/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:51:47 by tamchoor          #+#    #+#             */
/*   Updated: 2022/02/02 12:59:20 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(int x, int y, int clr, t_fdf ****fdf)
{
	int	i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = y * (***fdf)->line_length + x * ((***fdf)->bits_p_pix / 8);
		(***fdf)->addr[i] = clr;
		(***fdf)->addr[++i] = clr >> 8;
		(***fdf)->addr[++i] = clr >> 16;
	}
}

void	draw_line(t_p p1, t_p p2, t_fdf ***fdf)
{
	float	step_x;
	float	step_y;
	float	max;
	float	medium;

	step_x = (p2.x - p1.x);
	medium = p1.x + step_x / 2;
	step_y = (p2.y - p1.y);
	if (fabsf(step_y) > fabsf(step_x))
		max = fabsf(step_y);
	else
		max = fabsf(step_x);
	step_x = step_x / max;
	step_y = step_y / max;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		my_pixel_put(p1.x, p1.y, p1.clr, &fdf);
		if (p1.x > medium)
			p1.clr = p2.clr;
		p1.x += step_x;
		p1.y += step_y;
	}
}

void	draw_map(t_fdf **fdf, int y, int x)
{
	t_p		p1;
	t_p		p2;

	while (y < (*fdf)->crdnts->count_y)
	{
		x = 0;
		while (x < (*fdf)->crdnts->count_x)
		{
			p1 = ft_init_point(x, y, &fdf);
			if (x < (*fdf)->crdnts->count_x - 1)
			{
				p2 = ft_init_point(x + 1, y, &fdf);
				draw_line(p1, p2, &fdf);
			}
			if (y < (*fdf)->crdnts->count_y - 1)
			{
				p2 = ft_init_point(x, y + 1, &fdf);
				draw_line(p1, p2, &fdf);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window((*fdf)->mlx, (*fdf)->win, (*fdf)->img, 0, 0);
}

void	draw(t_fdf **fdf)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	ft_print_background(&(fdf));
	draw_map(&(*fdf), y, x);
	ft_print_menu(&fdf);
}
