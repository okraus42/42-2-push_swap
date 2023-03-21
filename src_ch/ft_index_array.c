/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:28:42 by okraus            #+#    #+#             */
/*   Updated: 2023/03/19 14:14:14 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_create_arrx(int **ax, int size)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		ax[i] = ft_calloc(sizeof(int), size);
		if (!ax[i])
			ax[i] = NULL;
		i++;
	}
}

void	ft_free_arrx(int ***arr_x)
{
	int	i;
	int	**ax;

	i = 0;
	ax = *arr_x;
	while (i < 8)
	{
		free(ax[i]);
		ax[i] = NULL;
		i++;
	}
	free(ax);
	ax = NULL;
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
*/

//can fine tune settings later
void	ft_index_stack(int **array, int size)
{
	t_ps_arr	a;
	int			*arr;

	a.i = 0;
	a.j = 0;
	a.tmp = size / 6;
	a.min = 1;
	arr = *array;
	while (a.i < size)
	{	
		if (a.i == a.tmp)
		{
			a.tmp += size / (5 + a.min / 2);
			a.min++;
		}
		arr[a.i] = a.min;
		if (a.i > size - 6)
			arr[a.i] = 0x7FFFFFFF;
		a.i++;
	}
}

// arr2 must be full of 0;
void	ft_index_array(int **array1, int **array2, int size)
{
	t_ps_arr	stats;
	int			*arr1;
	int			*arr2;

	stats.i = 0;
	arr1 = *array1;
	arr2 = *array2;
	while (stats.i < size)
	{
		stats.min = 0x7FFFFFFF;
		stats.j = 0;
		while (stats.j < size)
		{
			if (arr1[stats.j] <= stats.min && !arr2[stats.j])
			{
				stats.min = arr1[stats.j];
				stats.tmp = stats.j;
			}
			stats.j++;
		}
		arr2[stats.tmp] = stats.i + 1;
		stats.i++;
	}
}
