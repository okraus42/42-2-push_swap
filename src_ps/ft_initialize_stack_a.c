/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_stack_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:54:29 by okraus            #+#    #+#             */
/*   Updated: 2023/03/08 17:26:24 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_initialize_stack_a(int *arr, t_ps_info *info)
{
	int		i;
	t_dlist	*tmp;

	i = 0;
	while (i < info->a_size)
	{
		ft_printf("arr[%i] = %i\n", i, arr[i]);
		i++;
	}
	ft_printf("%6CprintX:%i%0C\n", arr[0]);

	i = info->a_size;
	info->b_size = 1;
	i -= 1;
	info->a_start = ft_dlstnew(&arr[i]);
	tmp = info->a_start;
	ft_printf("%8CprintB:%3i, num %3i|%p|%p|%p%0C\n", 0, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
	while (i)
	{
		tmp = ft_dlstnew(&arr[i - 1]);
		ft_dlstadd(&info->a_start, tmp);
		ft_printf("%7CprintB:%3i, num %3i|%p|%p|%p%0C\n", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		info->b_size += 1;
		info->a_start = tmp;
		i--;
	}
	info->a_size = info->b_size;
	info->b_size = 0;
}
