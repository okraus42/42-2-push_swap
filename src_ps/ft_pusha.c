/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pusha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:47:28 by okraus            #+#    #+#             */
/*   Updated: 2023/03/19 15:44:42 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_ps_smartpusha(int ***arr_x, t_ps_info *info, int size)
{
	int	i;
	int	min;
	int	index;
	int	**ax;

	ax = *arr_x;
	i = 0;
	min = 0x7FFFFFFF;
	index = 0;
	while (i < size)
	{
		if (ax[7][i] < min)
		{
			min = ax[7][i];
			index = i;
		}
		i++;
	}
	ft_ps_dosmartpusha(arr_x, info, index);
}

void	ft_ps_rota(t_ps_info *info)
{
	t_dlist		*tmp;

	tmp = info->a_start;
	while (tmp && tmp->next && *(int *)tmp->content != 1)
	{
		ft_ps_ra(&info->a_start, info);
		ft_printf("ra\n");
		tmp = tmp->next;
	}
}

void	ft_ps_pusha(int ***arr_x, t_ps_info *info, int size)
{
	while (info->b_size > 0)
	{
		ft_ps_prefill_ax(arr_x, info, size);
		ft_ps_smartpusha(arr_x, info, size);
	}
	ft_ps_rota(info);
}
