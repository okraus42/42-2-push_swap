/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bruteforce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:15:09 by okraus            #+#    #+#             */
/*   Updated: 2023/03/19 15:00:49 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_ps_bfdo2(t_ps_info *it, int i)
{
	if (i % 12 == 1)
		ft_ps_sa(&it->a_start, it);
	else if (i % 12 == 2)
		ft_ps_sb(&it->b_start, it);
	else if (i % 12 == 3)
		ft_ps_ss(&it->a_start, &it->b_start, it);
	else if (i % 12 == 4)
		ft_ps_pa(&it->a_start, &it->b_start, it);
	else if (i % 12 == 5)
		ft_ps_pb(&it->a_start, &it->b_start, it);
	else if (i % 12 == 6)
		ft_ps_ra(&it->a_start, it);
	else if (i % 12 == 7)
		ft_ps_rb(&it->b_start, it);
	else if (i % 12 == 8)
		ft_ps_rr(&it->a_start, &it->b_start, it);
	else if (i % 12 == 9)
		ft_ps_rra(&it->a_start, it);
	else if (i % 12 == 10)
		ft_ps_rrb(&it->b_start, it);
	else if (i % 12 == 11)
		ft_ps_rrr(&it->a_start, &it->b_start, it);
}

void	ft_ps_bfdo(t_ps_info *it, int i)
{
	while (i)
	{
		ft_ps_bfdo2(it, i);
		i /= 12;
	}
}

int	ft_ps_bftest(t_ps_info *it, int i)
{
	t_dlist	*tmp;

	ft_ps_bfdo(it, i);
	if ((!it->b_size && it->a_size <= 5) || it->a_size == 5)
	{
		tmp = it->a_start;
		i = it->a_size + it->b_size;
		while (i > it->a_size + it->b_size - 5 && i)
		{
			tmp = tmp->prev;
			if (*(int *)tmp->content == i)
				i--;
			else
				return (0);
		}
		if (i == it->a_size + it->b_size - 5 || !i)
			return (1);
	}
	return (0);
}

static int	ft_ps_bf2(t_ps_info *inf, t_ps_info *it)
{
	int		i;
	int		end;

	i = 0;
	end = 0;
	while (i < 0x7FFFFFFF)
	{
		ft_ps_copyinfo(inf, it);
		ft_ps_cpa(inf, it);
		ft_ps_cpb(inf, it);
		if (ft_ps_bftest(it, i))
			end = -1;
		if (it->a_start)
			ft_dlstclear2(&it->a_start);
		if (it->b_start)
			ft_dlstclear2(&it->b_start);
		if (end < 0)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_ps_bruteforce(t_ps_info *info)
{
	t_ps_info	*info_t;
	t_ps_info	inf2;
	int			i;

	info_t = &inf2;
	ft_ps_copyinfo(info, info_t);
	i = ft_ps_bf2(info, info_t);
	ft_ps_putop(i * 12);
	ft_ps_bfdo(info, i * 12);
	return (i);
}
