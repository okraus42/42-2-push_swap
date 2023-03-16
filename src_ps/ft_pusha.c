/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pusha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:47:28 by okraus            #+#    #+#             */
/*   Updated: 2023/03/16 18:10:04 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//will need to split to two functions
void	ft_ps_prefill_ax1(int ***arr_x, t_ps_info *info, int size)
{
	int	**ax;
	int	i;
	t_dlist	*tmp;

	ax = *arr_x;
	i = 0;
	tmp = info->a_start;
	while (i < info->a_size)
	{
		ax[0][*(int *)tmp->content] = i;
		ax[1][*(int *)tmp->content] = info->a_size - i;
		ax[5][*(int *)tmp->content] = 0x7FFFFFFF;
		ax[6][*(int *)tmp->content] = 0x7FFFFFFF;
		ax[7][*(int *)tmp->content] = 0x7FFFFFFF;
		if (tmp->next)
			tmp = tmp->next;
		i++;
	}
	i = 0;
	tmp = info->b_start;
	while (i < info->b_size)
	{
		ax[0][*(int *)tmp->content] = i;
		ax[1][*(int *)tmp->content] = info->b_size - i;
		ax[2][*(int *)tmp->content] = 1;
		ax[5][*(int *)tmp->content] = i;
		ax[6][*(int *)tmp->content] = info->b_size - i;
		if (tmp->next)
			tmp = tmp->next;
		i++;
	}
}

int	ft_ps_findhigher(int ***arr_x, int i, int size)
{
	int	**ax;

	ax = *arr_x;
	while (ax[2][i])
		i++;
	return (i);
}

//prefill rows 3-4
void	ft_ps_prefill_ax3(int ***arr_x, t_ps_info *info, int size)
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
			//find first higher ax[2][i+j] == 0;
			j == ft_ps_findhigher(arr_x, i, size);
			ax[3][i] = ax[0][j];
			ax[4][i] = ax[1][j];
		}
		i++;
	}
}

//add to libft
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	ft_min4(int a, int b, int c, int d)
{
	int min;

	if (a < b)
		min = a;
	else
		min = b;
	if (min > c)
		min = c;
	if (min > d)
		min = d;
	return (min);
}

//fill row 7
int	ft_ps_findmin(int ra, int rra, int rb, int rrb)
{
	int	rarb;
	int	rrarb;
	int	rarrb;
	int	rrarrb;

	rarb = ft_max(ra, rb);
	rrarb = rra + rb;
	rarrb = ra +rrb;
	rrarrb = ft_max(ra, rb);
	return (ft_min4(rarb, rrarb, rarrb, rrarrb));
}

void	ft_ps_prefill_ax4(int ***arr_x, t_ps_info *info, int size)
{
	int	**ax;
	int	i;
	int	j;
	int	k;
	int	l;

	ax = *arr_x;
	i = 0;
	while (i < size)
	{
		if (ax[2][i])
		{
		/*	ax3 - ra (if b) 0x7FFFFFFF for a
			ax4 - rra (if b) 0x7FFFFFFF for a
			ax5 - rb
			ax6 - rrb	*/
			ax[7][i] = ft_ps_findmin(ax[3][i], ax[4][i], ax[5][i], ax[6][i]);
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
	//fill row 0 & 1
	ft_ps_prefill_ax1(&ax, t_ps_info *info, int size);
	//fill row 2
	//fill row 3 - 4
	//fill row 7 
}
/*
ax0 - rx
ax1 - rrx
ax2 - a(0) || b(1)
ax3 - ra (if b) 0x7FFFFFFF for a
ax4 - rra (if b) 0x7FFFFFFF for a
ax5 - rb
ax6 - rrb
ax7 - number of moves to move to a
ax8 - value
*/

void	ft_ps_smartpusha(int **arr_x, t_ps_info *info, int size)
{
	//find min ax[7];
	//do moves
	return ;
}

void	ft_ps_pusha(int **arr_x, t_ps_info *info, int size)
{
	while(info->b_size > 0)
	{
		ft_ps_prefill_ax(&arr_x, info, size);
		ft_ps_smartpusha(arr_x, info, size);
	}
}
