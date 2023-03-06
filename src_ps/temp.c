/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:11:54 by okraus            #+#    #+#             */
/*   Updated: 2023/03/06 15:41:16 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(void)
{
	int	i;
	int	j;
	int	**arr;

	i = 0;
	j = 0;
	arr = NULL;
	arr = (int **)ft_prefill_array(&arr);
	while (i < 120)
	{
		j = 0;
		while (j < 5)
		{
			ft_printf(1, "%2C%i%0C", arr[i][j]);
			j++;
		}
		if (i < 120)
			ft_printf(1, ", ");
		i++;
	}
	return (0);
}
