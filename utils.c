/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:56:08 by tamchoor          #+#    #+#             */
/*   Updated: 2022/02/02 09:56:12 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_tab(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

long	ft_minus(int c, unsigned int *ptr_i)
{
	int	minus;

	minus = 1;
	if (c == '-' || c == '+')
	{
		if (c == '-')
			minus = minus * (-1);
		(*ptr_i)++;
	}
	return (minus);
}

void	ft_free_split(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i] != NULL)
	{
		free(((*str)[i]));
		i++;
	}
	free(*str);
}

void	calloc_two_stack(t_crdnts *****crdnts, int y)
{
	(****crdnts)->z_stack[y] = ft_calloc ((****crdnts)->count_x, sizeof(int));
	(****crdnts)->clr_stack[y] = ft_calloc ((****crdnts)->count_x, sizeof(int));
	if (!(****crdnts)->z_stack[y] || !(****crdnts)->clr_stack[y])
		ft_error_print("ERROR CALLOC", 0);
}

void	count_symb1(t_crdnts *****crdnts)
{
	int	i;

	i = 0;
	while ((****crdnts)->one_line[i])
	{
		if (ft_isdigit_and_sign((****crdnts)->one_line[i][0]) == 0)
			ft_error_print("ERROR Z NOT INT", 0);
		i++;
	}
	if ((****crdnts)->count_x != i)
		ft_error_print("ERROR COUNT_X", 0);
}
