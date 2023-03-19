/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pusha_smart.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:47:28 by okraus            #+#    #+#             */
/*   Updated: 2023/03/19 15:47:16 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_ps_dosmartpushrarb(int ***arr_x, t_ps_info *info, int i)
{
	int	**ax;

	ax = *arr_x;
	while (ax[3][i] && ax[5][i])
	{
		ft_ps_rr(&info->a_start, &info->b_start, info);
		ft_printf("rr\n");
		ax[3][i]--;
		ax[5][i]--;
	}
	while (ax[3][i])
	{
		ft_ps_ra(&info->a_start, info);
		ft_printf("ra\n");
		ax[3][i]--;
	}
	while (ax[5][i])
	{
		ft_ps_rb(&info->b_start, info);
		ft_printf("rb\n");
		ax[5][i]--;
	}
}

void	ft_ps_dosmartpushrrarb(int ***arr_x, t_ps_info *info, int i)
{
	int	**ax;

	ax = *arr_x;
	while (ax[4][i])
	{
		ft_ps_rra(&info->a_start, info);
		ft_printf("rra\n");
		ax[4][i]--;
	}
	while (ax[5][i])
	{
		ft_ps_rb(&info->b_start, info);
		ft_printf("rb\n");
		ax[5][i]--;
	}
}

void	ft_ps_dosmartpushrarrb(int ***arr_x, t_ps_info *info, int i)
{
	int	**ax;

	ax = *arr_x;
	while (ax[3][i])
	{
		ft_ps_ra(&info->a_start, info);
		ft_printf("ra\n");
		ax[3][i]--;
	}
	while (ax[6][i])
	{
		ft_ps_rrb(&info->b_start, info);
		ft_printf("rrb\n");
		ax[6][i]--;
	}
}

void	ft_ps_dosmartpushrrarrb(int ***arr_x, t_ps_info *info, int i)
{
	int	**ax;

	ax = *arr_x;
	while (ax[4][i] && ax[6][i])
	{
		ft_ps_rrr(&info->a_start, &info->b_start, info);
		ft_printf("rrr\n");
		ax[4][i]--;
		ax[6][i]--;
	}
	while (ax[4][i])
	{
		ft_ps_rra(&info->a_start, info);
		ft_printf("rra\n");
		ax[4][i]--;
	}
	while (ax[6][i])
	{
		ft_ps_rrb(&info->b_start, info);
		ft_printf("rrb\n");
		ax[6][i]--;
	}
}

void	ft_ps_dosmartpusha(int ***arr_x, t_ps_info *info, int i)
{
	int	**ax;

	ax = *arr_x;
	if (ax[2][i] == 1)
		ft_ps_dosmartpushrarb(arr_x, info, i);
	else if (ax[2][i] == 2)
		ft_ps_dosmartpushrrarb(arr_x, info, i);
	else if (ax[2][i] == 3)
		ft_ps_dosmartpushrarrb(arr_x, info, i);
	else if (ax[2][i] == 4)
		ft_ps_dosmartpushrrarrb(arr_x, info, i);
	ft_ps_pa(&info->a_start, &info->b_start, info);
	ft_printf("pa\n");
}
