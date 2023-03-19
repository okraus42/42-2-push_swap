/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pusha_prefill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:47:28 by okraus            #+#    #+#             */
/*   Updated: 2023/03/19 15:36:13 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

/*
ax0 - rx
ax1 - rrx
ax2 - a(0) || b(1 or which number to use)
ax3 - ra (if b) 0x7FFFFFFF for a
ax4 - rra (if b) 0x7FFFFFFF for a
ax5 - rb
ax6 - rrb
ax7 - number of moves to move to a
*/
//prefills most of a
void	ft_ps_prefill_ax1a(int ***arr_x, t_ps_info *info)
{
	int		**ax;
	int		i;
	t_dlist	*tmp;

	ax = *arr_x;
	i = 0;
	tmp = info->a_start;
	while (i < info->a_size)
	{
		ax[0][*(int *)tmp->content - 1] = i;
		ax[1][*(int *)tmp->content - 1] = info->a_size - i;
		ax[2][*(int *)tmp->content - 1] = 0;
		ax[5][*(int *)tmp->content - 1] = 0x7FFFFFFF;
		ax[6][*(int *)tmp->content - 1] = 0x7FFFFFFF;
		ax[7][*(int *)tmp->content - 1] = 0x7FFFFFFF;
		if (tmp && tmp->next)
			tmp = tmp->next;
		i++;
	}
}

//prefills most of b
void	ft_ps_prefill_ax1b(int ***arr_x, t_ps_info *info)
{
	int		**ax;
	int		i;
	t_dlist	*tmp;

	ax = *arr_x;
	i = 0;
	tmp = info->b_start;
	while (i < info->b_size)
	{
		ax[0][*(int *)tmp->content - 1] = i;
		ax[1][*(int *)tmp->content - 1] = info->b_size - i;
		ax[2][*(int *)tmp->content - 1] = 1;
		ax[5][*(int *)tmp->content - 1] = i;
		ax[6][*(int *)tmp->content - 1] = info->b_size - i;
		if (tmp && tmp->next)
			tmp = tmp->next;
		i++;
	}
}

//prefill rows 3-4
void	ft_ps_prefill_ax3(int ***arr_x, int size)
{
	int	**ax;
	int	i;
	int	j;

	ax = *arr_x;
	i = 0;
	while (i < size)
	{
		if (ax[2][i])
		{
			j = ft_ps_findhigher(arr_x, i);
			ax[3][i] = ax[0][j];
			ax[4][i] = ax[1][j];
		}
		i++;
	}
}

//fill row 7
void	ft_ps_prefill_ax7(int ***arr_x, int size)
{
	int	**ax;
	int	i;

	ax = *arr_x;
	i = 0;
	while (i < size)
	{
		if (ax[2][i])
		{
			ax[7][i] = ft_ps_findmin(arr_x, i);
		}
		i++;
	}
}

void	ft_ps_prefill_ax(int ***arr_x, t_ps_info *info, int size)
{
	int	**ax;
	int	i;

	i = 0;
	ax = *arr_x;
	ft_ps_prefill_ax1a(&ax, info);
	ft_ps_prefill_ax1b(&ax, info);
	ft_ps_prefill_ax3(&ax, size);
	ft_ps_prefill_ax7(&ax, size);
}
