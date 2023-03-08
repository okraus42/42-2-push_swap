/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:28:16 by okraus            #+#    #+#             */
/*   Updated: 2023/03/08 08:29:45 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_dlstclear(t_dlist **dlst, void (*del)(void *))
{
	t_dlist	*tmp;

	if (dlst)
	{
		tmp = *dlst;
		if (tmp->prev)
		{
			tmp = tmp->prev;
			tmp->next = NULL;
		}
		while (*dlst)
		{
			tmp = (*dlst)->next;
			ft_dlstdelone(*dlst, del);
			(*dlst) = tmp;
		}
	}
	dlst = NULL;
}

void	ft_dlstclear2(t_dlist **dlst)
{
	t_dlist	*tmp;

	if (dlst)
	{
		tmp = *dlst;
		if (tmp->prev)
		{
			tmp = tmp->prev;
			tmp->next = NULL;
		}
		while (*dlst)
		{
			tmp = (*dlst)->next;
			ft_dlstdelone2(*dlst);
			(*dlst) = tmp;
		}
	}
	dlst = NULL;
}
