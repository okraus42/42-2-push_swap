/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sortcheck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:15:52 by okraus            #+#    #+#             */
/*   Updated: 2023/03/20 15:28:14 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_ps_sortcheck(int *arr_i, int size)
{
	int	i;

	i = 0;
	while (i < size && i == arr_i[i] - 1)
	{
		i++;
	}
	if (i == size)
		return (0);
	return (1);
}
