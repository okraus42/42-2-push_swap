/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:25:34 by okraus            #+#    #+#             */
/*   Updated: 2023/03/19 14:27:51 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_ps_countinarr(int *arr_s, int i, int size)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (j < size)
	{
		if (arr_s[j] == i || arr_s[j] == i + 1)
			count++;
		j++;
	}
	return (count);
}

void	ft_ps_smart_pushb(int a, t_ps_info *info)
{
	t_dlist	*tmpa;
	t_dlist	*tmpb;
	int		b;

	tmpa = info->a_start;
	tmpb = info->b_start;
	if (tmpb)
		b = *(int *)tmpb->content;
	if (a % 2)
	{
		ft_ps_pb(&info->a_start, &info->b_start, info);
		ft_printf("pb\n");
	}
	else
	{
		ft_ps_pb(&info->a_start, &info->b_start, info);
		ft_printf("pb\nrb\n");
		ft_ps_rb(&info->b_start, info);
	}
}

int	ft_ps_pushb2(int *arr_s, t_ps_info *info, int counter, int i)
{
	int		c;
	t_dlist	*tmp;

	tmp = info->a_start;
	c = *(int *)tmp->content - 1;
	if (arr_s[c] == i || arr_s[c] == i + 1)
	{
		ft_ps_smart_pushb(arr_s[c], info);
		counter--;
	}
	else
	{
		ft_ps_ra(&info->a_start, info);
		ft_printf("ra\n");
	}
	return (counter);
}

void	ft_ps_pushb(int *arr_s, t_ps_info *info, int size)
{
	int		i;
	int		counter;

	i = 1;
	while (info->a_size > 5)
	{
		counter = ft_ps_countinarr(arr_s, i, size);
		while (counter > 0)
		{
			counter = ft_ps_pushb2(arr_s, info, counter, i);
		}
		i += 2;
	}
}
