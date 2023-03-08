/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmoveone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:34:16 by okraus            #+#    #+#             */
/*   Updated: 2023/03/08 11:18:32 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_dlstmovein(t_dlist **dlst_dst, t_dlist *dlst_src)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;
	t_dlist	*tmp3;

	tmp = *dlst_dst;
	tmp3 = dlst_src;
	ft_printf("MI:**dlst_dst = %p, *dlst_dst = %p, *dlst_src = %p\n", *dlst_dst, dlst_dst, dlst_src);
	ft_printf("MI:tmp = %p\n", tmp);
	ft_printf("MI:tmp3 = %p\n", tmp3);
	if (tmp)
	{
		ft_printf("MI:tmp = %p, tmp->prev = %p, tmp->next = %p\n", tmp, tmp->prev, tmp->next);
		ft_printf("MI:tmp3 = %p, tmp3->prev = %p, tmp3->next = %p\n", tmp3, tmp3->prev, tmp3->next);
		tmp3->next = tmp;
		tmp3->prev = tmp;
		tmp2 = tmp->prev;
		if (tmp2)
			ft_printf("MI:tmp2 = %p, tmp2->prev = %p, tmp2->next = %p\n", tmp2, tmp2->prev, tmp2->next);
		tmp->prev = tmp3;
		if (tmp2)
		{
			tmp2->next = tmp3;
			tmp3->prev = tmp2;
		}
		else
		{
			tmp->next = tmp3;
			tmp->prev = tmp3;
		}
	}
}

void	ft_dlstmoveout(t_dlist **dlst_src)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;

	ft_printf("d\n");
	if (*dlst_src)
	{
		ft_printf("c\n");
		tmp = *dlst_src;
		ft_printf("tmp = %p, tmp->prev = %p, tmp->next = %p\n", tmp, tmp->prev, tmp->next);
		if (tmp->next)
		{
			ft_printf("a\n");
			tmp2 = tmp->next;
			if (tmp->next != tmp->prev)
			{
				ft_printf("tmp = %p, tmp->prev = %p, tmp->next = %p\n", tmp, tmp->prev, tmp->next);
				tmp = tmp->prev;
				ft_printf("tmp = %p, tmp->prev = %p, tmp->next = %p\n", tmp, tmp->prev, tmp->next);
				ft_printf("tmp2 = %p, tmp2->prev = %p, tmp2->next = %p\n", tmp2, tmp2->prev, tmp2->next);
				tmp2->prev = tmp;
				ft_printf("tmp2 = %p, tmp2->prev = %p, tmp2->next = %p\n", tmp2, tmp2->prev, tmp2->next);
				ft_printf("tmp = %p, tmp->prev = %p, tmp->next = %p\n", tmp, tmp->prev, tmp->next);
				tmp->next = tmp2;
				ft_printf("tmp = %p, tmp->prev = %p, tmp->next = %p\n", tmp, tmp->prev, tmp->next);
				ft_printf("tmp2 = %p, tmp2->prev = %p, tmp2->next = %p\n", tmp2, tmp2->prev, tmp2->next);
			}
			else
			{
				ft_printf("b\n");
				tmp2->next = NULL;
				tmp2->prev = NULL;
			}
		}
	}
}

void	ft_dlstmoveone(t_dlist **dlst_dst, t_dlist **dlst_src)
{
	t_dlist	*tmps;

	tmps = *dlst_src;
	ft_printf("tmps = %p, tmps->prev = %p, tmps->next = %p\n", tmps, tmps->prev, tmps->next);
	ft_printf("dlst_dst = %p", dlst_dst);
	ft_dlstmovein(dlst_dst, tmps);
	ft_printf("tmps = %p, tmps->prev = %p, tmps->next = %p\n", tmps, tmps->prev, tmps->next);
	ft_dlstmoveout(dlst_src);
	ft_printf("tmps = %p, tmps->prev = %p, tmps->next = %p\n", tmps, tmps->prev, tmps->next);
	if (!*dlst_dst)
	{
		tmps->next = NULL;
		tmps->prev = NULL;
	}
	*dlst_dst = tmps;
}
