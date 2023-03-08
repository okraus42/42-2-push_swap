/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_manipulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:35:25 by okraus            #+#    #+#             */
/*   Updated: 2023/03/08 11:17:48 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_ps_sa(t_dlist **a, t_ps_info *info)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;
	t_dlist	*tmp3;
	t_dlist	*tmp4;

	if (info->a_size > 1)
	{
		tmp2 = *a;
		tmp1 = tmp2->prev;
		tmp3 = tmp2->next;
		tmp4 = tmp3->next;
		info->a_start = tmp3;
		if (info->a_size > 2)
		{
			tmp1->next = tmp3;
			tmp2->next = tmp4;
			tmp3->next = tmp2;
			tmp2->prev = tmp3;
			tmp3->prev = tmp1;
			tmp4->prev = tmp2;
		}
	}
}

void	ft_ps_sb(t_dlist **b, t_ps_info *info)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;
	t_dlist	*tmp3;
	t_dlist	*tmp4;

	if (info->b_size > 1)
	{
		tmp2 = *b;
		tmp1 = tmp2->prev;
		tmp3 = tmp2->next;
		tmp4 = tmp3->next;
		info->b_start = tmp3;
		if (info->b_size > 2)
		{
			tmp1->next = tmp3;
			tmp2->next = tmp4;
			tmp3->next = tmp2;
			tmp2->prev = tmp3;
			tmp3->prev = tmp1;
			tmp4->prev = tmp2;
		}
	}
}

void	ft_ps_ss(t_dlist **a, t_dlist **b, t_ps_info *info)
{
	ft_ps_sa(a, info);
	ft_ps_sb(b, info);
}

void	ft_ps_pa(t_dlist **a, t_dlist **b, t_ps_info *info)
{
	if (info->b_size > 0)
	{
		info->a_size += 1;
		info->b_size -= 1;
		ft_dlstmoveone(a, b);
	}
}

void	ft_ps_pb(t_dlist **a, t_dlist **b, t_ps_info *info)
{
	t_dlist	*tmp;

	if (info->a_size > 0)
	{
		if(!info->b_size)
		{
			tmp = *a;
			ft_dlstmoveout(a);
			info->a_start = tmp->next;
			info->b_start = tmp;
			tmp->next = NULL;
			tmp->prev = NULL;			
		}
		else
		{
			tmp = *a;
			ft_dlstmoveone(b, a);
			info->a_start = tmp->next;
			info->b_start = tmp;
		}
		info->a_size -= 1;
		info->b_size += 1;
	}
}