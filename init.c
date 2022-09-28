/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:55:55 by tamchoor          #+#    #+#             */
/*   Updated: 2022/02/02 11:41:23 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_crdnts(t_crdnts **crdnts)
{
	*crdnts = (t_crdnts *) ft_calloc (sizeof(t_crdnts), 1);
	if (!crdnts)
		ft_error_print(0, 0);
	(*crdnts)->y = 0;
}

void	init_fdf(t_fdf **fdf, t_crdnts **crdnts)
{
	(*fdf) = (t_fdf *) ft_calloc (sizeof(t_fdf), 1);
	if (!(*fdf))
		ft_error_print(0, 0);
	(*fdf)->mlx = mlx_init();
	(*fdf)->win = mlx_new_window((*fdf)->mlx, WIDTH, HEIGHT, "FdF");
	(*fdf)->img = mlx_new_image((*fdf)->mlx, WIDTH, HEIGHT);
	(*fdf)->addr = mlx_get_data_addr((*fdf)->img, &(*fdf)->bits_p_pix,
			&(*fdf)->line_length, &(*fdf)->endian);
	if ((*crdnts)->count_y < (*crdnts)->count_x)
		(*fdf)->zoom = ceil((WIDTH / (*crdnts)->count_x) + (*fdf)->zoom);
	else
		(*fdf)->zoom = ceil((HEIGHT / (*crdnts)->count_y) + (*fdf)->zoom);
	if (!((*fdf)->mlx) || !(*fdf)->win || !(*fdf)->img || !(*fdf)->addr)
		ft_error_print(0, 0);
	(*fdf)->crdnts = (*crdnts);
}
