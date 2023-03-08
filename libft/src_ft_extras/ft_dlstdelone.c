/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:27:59 by okraus            #+#    #+#             */
/*   Updated: 2023/03/08 08:29:44 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *))
{
	if (dlst)
	{
		(*del)(dlst->content);
		free(dlst);
	}		
}

void	ft_dlstdelone2(t_dlist *dlst)
{
	if (dlst)
	{
		free(dlst);
	}		
}
