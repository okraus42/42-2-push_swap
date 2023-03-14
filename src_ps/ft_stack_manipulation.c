/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_manipulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:35:25 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:11:03 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*t_dlist	*tmp;
	int		j;

	ft_printf("a_size = %i\n", info->a_size);
	tmp = info->a_start;
	j = 0;
	tmp2 = info->b_start;
	if (info->a_size || info->b_size)
	{
		while (tmp && j < info->a_size)
		{
			ft_printf("%1CstackA2:%3i, num %3i|%p|%p|%p\n%0C", j, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
			if (tmp->next)
				tmp = tmp->next;
			j++;
		}
		j = 0;
		while (tmp2 && j < info->b_size)
		{
			ft_printf("%2CstackB2:%3i, num %3i|%p|%p|%p\n%0C", j, *(int *)tmp2->content, tmp2->prev, tmp2, tmp2->next);
			if (tmp2->next)
				tmp2 = tmp2->next;
			j++;
		}
	}*/

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
	t_dlist	*tmp;
	t_dlist	*tmp2;

	if (info->b_size > 0)
	{
		tmp = *b;
		if (info->b_size == 1)
		{
			ft_dlstadd(a, tmp);
			info->a_start = tmp;
			info->b_start = NULL;
		}
		else
		{
			tmp2 = tmp->next;
			ft_dlstmoveone(a, b);
			info->b_start = tmp2;
			info->a_start = tmp;
		}
		info->a_size += 1;
		info->b_size -= 1;
	}
}

void	ft_ps_pb(t_dlist **a, t_dlist **b, t_ps_info *info)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;

	if (info->a_size > 0)
	{
		tmp = *a;
		if (info->a_size == 1)
		{
			ft_dlstadd(b, tmp);
			info->a_start = NULL;
			info->b_start = tmp;
		}
		else
		{
			tmp2 = tmp->next;
			ft_dlstmoveone(b, a);
			info->a_start = tmp2;
			info->b_start = tmp;
		}
		info->a_size -= 1;
		info->b_size += 1;
	}
}

void	ft_ps_ra(t_dlist **a, t_ps_info *info)
{
	t_dlist	*tmp;

	if (info->a_size > 1)
	{
		tmp = *a;
		tmp = tmp->next;
		info->a_start = tmp;
	}
}

void	ft_ps_rb(t_dlist **b, t_ps_info *info)
{
	t_dlist	*tmp;

	if (info->b_size > 1)
	{
		tmp = *b;
		tmp = tmp->next;
		info->b_start = tmp;
	}
}

void	ft_ps_rr(t_dlist **a, t_dlist **b, t_ps_info *info)
{
	ft_ps_ra(a, info);
	ft_ps_rb(b, info);
}

void	ft_ps_rra(t_dlist **a, t_ps_info *info)
{
	t_dlist	*tmp;

	if (info->a_size > 1)
	{
		tmp = *a;
		tmp = tmp->prev;
		info->a_start = tmp;
	}
}

void	ft_ps_rrb(t_dlist **b, t_ps_info *info)
{
	t_dlist	*tmp;

	if (info->b_size > 1)
	{
		tmp = *b;
		tmp = tmp->prev;
		info->b_start = tmp;
	}
}

void	ft_ps_rrr(t_dlist **a, t_dlist **b, t_ps_info *info)
{
	ft_ps_rra(a, info);
	ft_ps_rrb(b, info);
}
