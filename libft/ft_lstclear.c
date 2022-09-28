/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamchoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:42:54 by tamchoor          #+#    #+#             */
/*   Updated: 2021/10/16 20:42:56 by tamchoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*old_lst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		old_lst = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = old_lst;
	}
}
