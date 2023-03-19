/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bruteforce2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:56:41 by okraus            #+#    #+#             */
/*   Updated: 2023/03/19 15:01:47 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//returns INT, MOD 12 contains the instructions;

void	ft_ps_copyinfo(t_ps_info *info, t_ps_info *info_t)
{
	info_t->a_size = info->a_size;
	info_t->a_start = NULL;
	info_t->b_size = info->b_size;
	info_t->b_start = NULL;
}

void	ft_ps_cpb(t_ps_info *inf, t_ps_info *it)
{
	int		i;
	t_dlist	*tmpd;
	t_dlist	*tmps;

	i = 0;
	if (it->b_size > 0)
	{
		tmps = inf->b_start;
		if (tmps->prev)
			tmps = tmps->prev;
		it->b_start = ft_dlstnew(tmps->content);
		i = it->b_size - 1;
	}
	while (i)
	{
		tmps = tmps->prev;
		tmpd = ft_dlstnew(tmps->content);
		ft_dlstadd(&it->b_start, tmpd);
		it->b_start = tmpd;
		i--;
	}
}

void	ft_ps_cpa(t_ps_info *inf, t_ps_info *it)
{
	int		i;
	t_dlist	*tmpd;
	t_dlist	*tmps;

	i = 0;
	if (it->a_size > 0)
	{
		tmps = inf->a_start;
		if (tmps->prev)
			tmps = tmps->prev;
		it->a_start = ft_dlstnew(tmps->content);
		i = it->a_size - 1;
	}
	while (i)
	{
		tmps = tmps->prev;
		tmpd = ft_dlstnew(tmps->content);
		ft_dlstadd(&it->a_start, tmpd);
		it->a_start = tmpd;
		i--;
	}
}

static void	ft_ps_putop2(int i)
{
	if (i % 12 == 1)
		ft_printf("sa\n");
	else if (i % 12 == 2)
		ft_printf("sb\n");
	else if (i % 12 == 3)
		ft_printf("ss\n");
	else if (i % 12 == 4)
		ft_printf("pa\n");
	else if (i % 12 == 5)
		ft_printf("pb\n");
	else if (i % 12 == 6)
		ft_printf("ra\n");
	else if (i % 12 == 7)
		ft_printf("rb\n");
	else if (i % 12 == 8)
		ft_printf("rr\n");
	else if (i % 12 == 9)
		ft_printf("rra\n");
	else if (i % 12 == 10)
		ft_printf("rrb\n");
	else if (i % 12 == 11)
		ft_printf("rrr\n");
}

void	ft_ps_putop(int i)
{
	while (i)
	{
		ft_ps_putop2(i);
		i /= 12;
	}
}
