/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_manipulation_rrx.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:35:25 by okraus            #+#    #+#             */
/*   Updated: 2023/03/19 15:03:38 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
