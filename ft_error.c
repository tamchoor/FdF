/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:51:58 by tamchoor          #+#    #+#             */
/*   Updated: 2022/02/02 09:52:00 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_print(char *str, t_crdnts *crdnts)
{
	crdnts = 0;
	if (str == NULL)
		perror("Error ");
	else
		write(2, str, ft_strlen(str));
	exit (EXIT_FAILURE);
}
