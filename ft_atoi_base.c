/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:51:55 by tamchoor          #+#    #+#             */
/*   Updated: 2022/02/02 09:51:57 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned int	ft_strlen_dig(const char *s)
{
	long unsigned int	count;

	count = 0;
	while (ft_isdigit(s[count]))
	{
		count++;
	}
	return (count);
}

static long
	ft_find_res(long res, unsigned int count,
		long minus, const char *str)
{
	if (count <= 19)
	{
		if (count == 19 && minus == 1
			&& ft_strncmp(str, "9223372036854775807", 19) > 0)
			res = 9223372036854775807L;
		else if (count == 19 && minus == -1
			&& ft_strncmp(str, "9223372036854775808", 19) > 0)
			res = -9223372036854775807L - 1L;
		else
		{
			while (ft_isdigit(*(str)))
			{
				res = res * 10 + *(str) - '0';
				(str)++;
			}
		}
	}
	if (count > 19)
	{
		if (minus == 1)
			res = 9223372036854775807L;
		if (minus == -1)
			res = -9223372036854775807L - 1L;
	}
	return (res);
}

static long	ft_find_res_base(long res,
		int base, const char *str)
{
	const char	*digits;
	int			i;

	digits = "0123456789ABCDEF";
	while ((*(str)))
	{
		i = 0;
		while (i < base)
		{
			if (digits[i] == ft_toupper(*(str)))
			{
				res = res * base + i;
			}
			i++;
		}
		(str)++;
	}
	return (res);
}

static int	check_prefix(char **str, int base)
{
	int	i;

	i = 0;
	if (base == 10)
		return (1);
	if (base == 2 || base == 8 || base == 16)
	{
		if ((*str)[i++] != '0')
			return (-1);
		if (base == 2 && ((*str)[i] == 'b' || (*str)[i] == 'B'))
			return (1);
		if (base == 16 && ((*str)[i] == 'x' || (*str)[i] == 'X'))
			return (1);
		if (base == 8)
			return (1);
	}
	return (-1);
}

int	ft_atoi_base(char *str, int base)
{
	long			minus;
	long			res;
	unsigned int	i;
	unsigned int	count;

	res = 0;
	i = 0;
	while (ft_tab(str[i]))
		i++;
	if (check_prefix(&str + i, base) == -1)
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	minus = ft_minus(str[i], &i);
	count = ft_strlen_dig(str + i);
	if (base == 10)
	{
		res = ft_find_res(res, count, minus, str + i);
	}
	else
		res = ft_find_res_base(res, base, str + i);
	res = res * minus;
	return ((int) res);
}
