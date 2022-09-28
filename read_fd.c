/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:56:06 by tamchoor          #+#    #+#             */
/*   Updated: 2022/02/02 13:15:07 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_symb(char **line, t_crdnts ****crdnts)
{
	int	i;

	(***crdnts)->one_line = ft_split(*line, ' ');
	if ((***crdnts)->one_line == NULL)
		ft_error_print("ERROR MAP", 0);
	i = 0;
	while ((***crdnts)->one_line[i])
	{
		if (ft_isdigit_and_sign((***crdnts)->one_line[i][0]) == 0)
			ft_error_print("ERROR Z NOT INT", 0);
		free((***crdnts)->one_line[i]);
		i++;
	}
	free((***crdnts)->one_line);
	if ((***crdnts)->count_x == 0)
		(***crdnts)->count_x = i;
	else
	{
		if ((***crdnts)->count_x != i)
			ft_error_print("ERROR COUNT_X", 0);
	}
}

void	ft_count_x_y(char *argv, t_crdnts ***crdnts)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error_print(0, 0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			break ;
		}
		if (line[0] == '\0')
		{
			break ;
		}
		if ((**crdnts)->count_y == 0)
			count_symb(&line, &crdnts);
		free(line);
		(**crdnts)->count_y++;
	}
	close(fd);
}

void	find_z_and_clr(char **line, t_crdnts ****crdnts, int y)
{
	int	x;

	x = 0;
	(***crdnts)->one_line = ft_split(&(**line), ' ');
	if ((***crdnts)->one_line == NULL)
		ft_error_print("ERROR SPLIT", 0);
	count_symb1(&crdnts);
	calloc_two_stack(&crdnts, y);
	while ((***crdnts)->one_line[x])
	{
		(***crdnts)->one_var = ft_split((***crdnts)->one_line[x], ',');
		if ((***crdnts)->one_var == NULL)
			ft_error_print("ERROR SPLIT", 0);
		(***crdnts)->z_stack[y][x] = ft_atoi((***crdnts)->one_var[0]);
		if ((***crdnts)->one_var[1])
			(***crdnts)->clr_stack[y][x]
				= ft_atoi_base((***crdnts)->one_var[1], 16);
		else
			(***crdnts)->clr_stack[y][x] = -1;
		x++;
		ft_free_split(&((***crdnts)->one_var));
	}
	ft_free_split(&((***crdnts)->one_line));
}

void	ft_fill_stack(char *argv, t_crdnts ***crdnts)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error_print(0, 0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			break ;
		}
		if (line[0] == '\0')
		{
			break ;
		}
		find_z_and_clr(&line, &crdnts, (**crdnts)->y);
		free(line);
		(**crdnts)->y++;
	}
	close(fd);
}

void	read_fd(char *argv, t_crdnts **crdnts)
{
	ft_count_x_y(argv, &crdnts);
	(*crdnts)->z_stack = ft_calloc (((*crdnts)->count_x * (*crdnts)->count_y),
			sizeof(int));
	(*crdnts)->clr_stack = ft_calloc (((*crdnts)->count_x * (*crdnts)->count_y),
			sizeof(int));
	if (!(*crdnts)->z_stack || !(*crdnts)->clr_stack)
		ft_error_print("ERROR CALLOC", 0);
	ft_fill_stack(argv, &crdnts);
}
