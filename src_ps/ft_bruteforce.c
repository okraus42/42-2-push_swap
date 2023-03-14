/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bruteforce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:15:09 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:10:51 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//returns INT, MOD 12 contains the instructions;

static void	ft_copyinfo(t_ps_info *info, t_ps_info *info_t)
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

void	ft_ps_putop(int i)
{
	while (i)
	{
		ft_printf("%i", i % 12);
		if (i % 12 == 1)
			ft_printf(" = sa\n");
		else if (i % 12 == 2)
			ft_printf(" = sb\n");
		else if (i % 12 == 3)
			ft_printf(" = ss\n");
		else if (i % 12 == 4)
			ft_printf(" = pa\n");
		else if (i % 12 == 5)
			ft_printf(" = pb\n");
		else if (i % 12 == 6)
			ft_printf(" = ra\n");
		else if (i % 12 == 7)
			ft_printf(" = rb\n");
		else if (i % 12 == 8)
			ft_printf(" = rr\n");
		else if (i % 12 == 9)
			ft_printf(" = rra\n");
		else if (i % 12 == 10)
			ft_printf(" = rrb\n");
		else if (i % 12 == 11)
			ft_printf(" = rrr\n");
		i /= 12;
	}
}

void	ft_ps_bfdo(t_ps_info *it, int i)
{
	//ft_printf("\n%6Ci = %i%0C\n", i);
	while (i)
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
		i /= 12;
	}
}

int	ft_ps_bftest(t_ps_info *it, int i)
{
	t_dlist	*tmp;

	ft_ps_bfdo(it, i);
	if (!it->b_size)
	{
		tmp = it->a_start;
		i = it->a_size;
		while (i)
		{
			tmp = tmp->prev;
			if (*(int *)tmp->content == i)
				i--;
			else
				return (0);
		}
		if (!i)
			return (1);
	}
	return (0);
}

static int	ft_ps_bf2(t_ps_info *inf, t_ps_info *it)
{
	//t_dlist **at;
	//t_dlist **bt;
	//t_dlist	*tmp;	//remove later
	//t_dlist	*tmp2;	//remove later
	int		i;
	//int		j;		//remove later
	int		end;

	i = 0;
	end = 0;
	//at = NULL;
	//bt = NULL;
	while (i < 0x7FFFFFFF)
	{
		ft_copyinfo(inf, it);
		ft_ps_cpa(inf, it);
		ft_ps_cpb(inf, it);
		/*j = i;
		while (j)
		{
			ft_ps_pb(&it->a_start, &it->b_start, it);	
			j--;
		}
		*/
		if (ft_ps_bftest(it, i))
			end = -1;
		/*ft_printf("\n\n%7CBRUTE FORCE YEAH %i%0C\n\n", i);
		tmp = it->a_start;
		j = 0;
		tmp2 = it->b_start;
		if (it->a_size || it->b_size)
		{
			while (tmp && j < it->a_size)
			{
				ft_printf("%1CstackA2:%3i, num %3i|%p|%p|%p\n%0C", j, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
				if (tmp->next)
					tmp = tmp->next;
				j++;
			}
			j = 0;
			while (tmp2 && j < it->b_size)
			{
				ft_printf("%2CstackB2:%3i, num %3i|%p|%p|%p\n%0C", j, *(int *)tmp2->content, tmp2->prev, tmp2, tmp2->next);
				if (tmp2->next)
					tmp2 = tmp2->next;
				j++;
			}
		}*/
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
	t_dlist		*tmp;	//remove later
	t_dlist		*tmp2;	//remove later
	int			i;

	info_t = &inf2;
	ft_copyinfo(info, info_t);
	i = ft_ps_bf2(info, info_t);
	tmp = info_t->a_start;
	tmp2 = info_t->b_start;
	ft_printf("\n\n%7CBRUTE FORCE == %i%0C\n\n", i);
	ft_ps_putop(i);
	i = 0;
	if (info_t->a_size || info_t->b_size)
	{
		while (tmp && i < info_t->a_size)
		{
			ft_printf("%1CstackA2:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
			if (tmp->next)
				tmp = tmp->next;
			i++;
		}
		i = 0;
		while (tmp2 && i < info_t->b_size)
		{
			ft_printf("%2CstackB2:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp2->content, tmp2->prev, tmp2, tmp2->next);
			if (tmp2->next)
				tmp2 = tmp2->next;
			i++;
		}
	}

	return (i);
}
