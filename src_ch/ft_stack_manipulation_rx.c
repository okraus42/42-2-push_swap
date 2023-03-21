/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_manipulation_rx.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:35:25 by okraus            #+#    #+#             */
/*   Updated: 2023/03/19 15:04:27 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
