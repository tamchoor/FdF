/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:55:08 by tamchoor          #+#    #+#             */
/*   Updated: 2022/02/02 09:52:04 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_strjoin1(char **line1, char buf)
{
	char	*new;
	int		count;
	char	*line;

	count = 0;
	line = *line1;
	while (line[count])
		count++;
	new = (char *)malloc(sizeof(char) * (count + 2));
	count--;
	if (!new)
		return (NULL);
	new[count + 2] = '\0';
	new[count + 1] = buf;
	while (count >= 0)
	{
		new[count] = line[count];
		count--;
	}
	free(line);
	return (new);
}

static int	ft_return_err(char **new)
{
	free(*new);
	return (-1);
}

int	get_next_line(char **line1, int fd)
{
	char	buffer[2];
	char	*new;
	int		count;

	count = 1;
	if (!line1)
		return (-1);
	new = *line1;
	new = malloc(1);
	if (!new)
		return (-1);
	new[0] = '\0';
	while (buffer[0] != '\n' && count != 0)
	{
		count = read(fd, buffer, 1);
		if (count == -1)
			return (ft_return_err(&new));
		if (buffer[0] == '\n')
			break ;
		buffer[count] = '\0';
		new = ft_strjoin1(&new, buffer[0]);
	}
	*line1 = new;
	return (count);
}
