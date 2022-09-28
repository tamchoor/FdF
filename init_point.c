/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:52:05 by tamchoor          #+#    #+#             */
/*   Updated: 2022/02/02 09:52:07 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_clr(int z, int *clr_elem, int clr)
{
	if (clr == -1)
	{
		if (z > 0)
			*clr_elem = HOTPINK;
		else if (z == 0)
			*clr_elem = RED;
		else
			*clr_elem = BLUE;
	}
	else
		*clr_elem = clr;
}

static void	rotate_x(float *y, float *z, double alpha, t_fdf ****fdf)
{
	float	previous_y;
	float	medium;

	previous_y = *y;
	medium = (WIDTH / 2) + (***fdf)->crdnts->medium_x;
	*y = (previous_y - medium) * cos(alpha) + *z * sin(alpha) + medium;
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

static void	rotate_y(float *y, float *z, double alpha, t_fdf ****fdf)
{
	float	previous_y;
	float	medium;

	previous_y = *y;
	medium = (HEIGHT / 2) + (***fdf)->crdnts->medium_y;
	*y = (previous_y - medium) * cos(alpha) + *z * sin(alpha) + medium ;
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

t_p	ft_init_point(int x, int y, t_fdf ***fdf)
{
	t_p		p;

	p.z = (**fdf)->crdnts->z_stack[y][x] * (**fdf)->zoom;
	if (p.z != 0)
		p.z = p.z + (**fdf)->key.change_z;
	ft_check_clr(p.z, &p.clr, (**fdf)->crdnts->clr_stack[y][x]);
	x = x - (**fdf)->crdnts->medium_x;
	y = y - (**fdf)->crdnts->medium_y;
	p.x = x * (**fdf)->zoom;
	p.y = y * (**fdf)->zoom;
	p.x = p.x + (WIDTH / 2);
	p.y = p.y + (HEIGHT / 2);
	p.x = p.x + (**fdf)->key.shift_x;
	p.y = p.y + (**fdf)->key.shift_y;
	rotate_x(&p.x, &p.z, (**fdf)->key.angl_x, &fdf);
	rotate_y(&p.y, &p.z, (**fdf)->key.angl_y, &fdf);
	return (p);
}
