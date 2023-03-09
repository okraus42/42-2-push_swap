/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:28:42 by okraus            #+#    #+#             */
/*   Updated: 2023/03/08 17:52:11 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
