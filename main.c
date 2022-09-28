/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:56:00 by tamchoor          #+#    #+#             */
/*   Updated: 2022/02/02 09:56:02 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_destroy(void)
{
	exit (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_crdnts	*crdnts;
	t_fdf		*fdf;

	if (argc != 2)
		ft_error_print("ARGC ERROR", 0);
	init_crdnts(&crdnts);
	read_fd(argv[1], &crdnts);
	init_fdf(&fdf, &crdnts);
	(fdf)->crdnts->medium_x = (fdf)->crdnts->count_x / 2;
	(fdf)->crdnts->medium_y = (fdf)->crdnts->count_y / 2;
	draw(&fdf);
	mlx_key_hook(fdf->win, key_control, fdf);
	mlx_hook(fdf->win, BUTTONPRESS, 0, deal_mouse_press, fdf);
	mlx_hook(fdf->win, BUTTONRELEASE, 0, deal_mouse_release, fdf);
	mlx_hook(fdf->win, BUTTONMOVE, 0, deal_mouse_move, fdf);
	mlx_hook(fdf->win, ON_DESTROY, 0, deal_destroy, 0);
	mlx_loop(fdf->mlx);
	return (0);
}
