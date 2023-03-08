/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_stack_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:54:29 by okraus            #+#    #+#             */
/*   Updated: 2023/03/08 14:55:20 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_initialize_stack_a(int *arr, t_ps_info *info)
{
	int		i;
	t_dlist	*tmp;

	ft_printf("%6CprintX:%i%0C\n", arr[0]);
	info->a_start = ft_dlstnew(&arr[0]);
	tmp = info->a_start;
	ft_printf("%8CprintB:%3i, num %3i|%p|%p|%p%0C\n", 0, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
	i = 1;
	info->b_size = 1;
	while (i < info->a_size)
	{
		tmp = ft_dlstnew(&arr[i]);
		ft_printf("%7CprintB:%3i, num %3i|%p|%p|%p%0C\n", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		info->b_size += 1;
		info->a_start = tmp;
		i++;
	}
	info->a_size = info->b_size;
	info->b_size = 0;
}

	/*
	info->a_start = ft_dlstnew(&arr_i[0]);

	i = 1;

	while (i < argc - 1)
	{
		tmp = ft_dlstnew(&arr_i[i]);
		tmp2 = *a;
		info->a_size += 1;
		info->a_start = tmp;
		i++;
	}*/
