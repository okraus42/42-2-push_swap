/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pusha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:47:28 by okraus            #+#    #+#             */
/*   Updated: 2023/03/17 18:03:07 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//will need to split to two functions
void	ft_ps_prefill_ax1(int ***arr_x, t_ps_info *info)
{
	int	**ax;
	int	i;
	t_dlist	*tmp;

	ax = *arr_x;
	i = 0;
	tmp = info->a_start;
	//ft_printf("test0a0\n");
	//ft_printf("ax[0] = %p\n", &ax[0]);
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
	i = 0;
	//ft_printf("test0a1\n");
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

int	ft_ps_findhigher(int ***arr_x, int i)
{
	int	**ax;

	ax = *arr_x;
	while (ax[2][i])
		i++;
	return (i);
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

int	ft_min4b(int a, int b, int c, int d)
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
	if (min == a)
		return (1);
	else if (min == b)
		return (2);
	else if (min == c)
		return (3);
	else
		return (4);
}

//fill row 7
int	ft_ps_findmin(int ***arr_x, int i)
{
	int	**ax;
	int	rarb;
	int	rrarb;
	int	rarrb;
	int	rrarrb;

	ax = *arr_x;
	rarb = ft_max(ax[3][i], ax[5][i]);
	rrarb = ax[4][i] + ax[5][i];
	rarrb = ax[3][i] + ax[6][i];
	rrarrb = ft_max(ax[4][i], ax[6][i]);
	ax[2][i] = ft_min4b(rarb, rrarb, rarrb, rrarrb);
	return (ft_min4(rarb, rrarb, rarrb, rrarrb));
}

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
		/*	ax3 - ra (if b) 0x7FFFFFFF for a
			ax4 - rra (if b) 0x7FFFFFFF for a 
			ax5 - rb
			ax6 - rrb	*/
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
	//fill row 0 & 1
	//ft_printf("test0a\n");
	ft_ps_prefill_ax1(&ax, info);
	//ft_printf("test0b\n");
	ft_ps_prefill_ax3(&ax, size);
	//ft_printf("test0c\n");
	ft_ps_prefill_ax7(&ax, size);
	//ft_printf("test0d\n");
	//fill row 2
	//fill row 3 - 4
	//fill row 7 
}
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
		//ft_printf("ax[6][%i] = %i\n", i, ax[6][i]);
		//ft_printf("ax[2][%i] = %i\n", i, ax[2][i]);
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

void	ft_ps_smartpusha(int ***arr_x, t_ps_info *info, int size)
{
	int	i;
	int min;
	int	index;
	int	**ax;

	ax = *arr_x;
	//find min i ax[7][i];
	i = 0;
	min = 0x7FFFFFFF;
	index = 0;
	while (i < size) //&& ax[2][i]
	{
		//ft_printf("1min = %i, ax[7][%i] = %i, index = %i\n", min, i, ax[7][i], index);
		if (ax[7][i] < min)
		{
			//ft_printf("2min = %i, ax[7][%i] = %i, index = %i\n", min, i, ax[7][i], index);
			min = ax[7][i];
			index = i;
		}
		//ft_printf("3min = %i, ax[7][%i] = %i, index = %i\n", min, i, ax[7][i], index);
		i++;
	}
	//do move%is arr_x, info, index
	/*ft_printf("%1C%i%0C\n", index);
	ft_printf("%2Cax[0][%i] = %i | %p%0C\n", index, ax[0][index], &ax[0][0]);
	ft_printf("ax[1][%i] = %i\n", index, ax[1][index]);
	ft_printf("ax[2][%i] = %i\n", index, ax[2][index]);
	ft_printf("ax[3][%i] = %i\n", index, ax[3][index]);
	ft_printf("ax[4][%i] = %i\n", index, ax[4][index]);
	ft_printf("ax[5][%i] = %i\n", index, ax[5][index]);
	ft_printf("ax[6][%i] = %i\n", index, ax[6][index]);
	ft_printf("ax[7][%i] = %i\n", index, ax[7][index]);
	ft_printf("4min = %i, ax[7][%i] = %i, index = %i\n", min, i, ax[7][i], index);*/
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
	//t_dlist		*tmp;	//remove later
	//t_dlist		*tmp2;	//remove later
	//int			i;		//remove later

	while (info->b_size > 0)
	{
		//ft_printf("test0%p\n", arr_x);
		ft_ps_prefill_ax(arr_x, info, size);
		//ft_printf("test1\n");
		ft_ps_smartpusha(arr_x, info, size);
		//ft_printf("test2\n");
	}
	ft_ps_rota(info);
	/*tmp = info->a_start;
	tmp2 = info->b_start;
	i = 0;
	if (info->a_size || info->b_size)
	{
		i = 0;
		while (tmp && i < info->a_size)
		{
			ft_printf("%1CstackA2:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
			if (tmp->next)
				tmp = tmp->next;
			i++;
		}
		i = 0;
		while (tmp2 && i < info->b_size)
		{
			ft_printf("%2CstackB2:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp2->content, tmp2->prev, tmp2, tmp2->next);
			if (tmp2->next)
				tmp2 = tmp2->next;
			i++;
		}
	}*/
}
