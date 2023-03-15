/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:25:34 by okraus            #+#    #+#             */
/*   Updated: 2023/03/15 16:02:07 by okraus           ###   ########.fr       */
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
		ft_printf("j = %i, size = %i, i = %i\n", j, size, i);
		ft_printf("arr_s[%i] = %i, size = %i, i = %i\n", j, arr_s[j], size, i);
		if (arr_s[j] == i || arr_s[j] == i + 1)
			count++;
		j++;
	}
	ft_printf("count = %i\n", count);
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
		ft_ps_rb(&info->b_start, info);
	}
	else
	{
		ft_ps_pb(&info->a_start, &info->b_start, info);
	}
}

void	ft_ps_pushb(int *arr_s, t_ps_info *info, int size)
{
	int		i;
	int		c;
	int		counter;
	t_dlist	*tmp;

	i = 1;
	tmp = info->a_start;
	while (info->a_size > 5)
	{
		counter = ft_ps_countinarr(arr_s, i, size);
		tmp = info->a_start;
		ft_printf("haha^\n");
		while (counter > 0)
		{
			c = *(int *)tmp->content;
			if (c == i || c == i + 1)
			{
				ft_printf("haha-\n");
				ft_ps_smart_pushb(c, info);
				ft_printf("haha+\n");
				counter--;
			}
			else
				ft_ps_ra(&info->a_start, info);
		}
		i += 2;
	}

}
