/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:25:15 by okraus            #+#    #+#             */
/*   Updated: 2023/03/07 17:24:27 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_dlstadd(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;

	if (*dlst)
	{
		tmp = *dlst;
		new->next = tmp;
		new->prev = tmp;
		tmp2 = tmp->prev;
		tmp->prev = new;
		if (tmp2)
		{
			tmp2->next = new;
			new->prev = tmp2;
		}
		else
		{
			tmp->next = new;
			tmp->prev = new;
		}
	}
	*dlst = new;
}
