/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_stack_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:54:29 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:11:01 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_initialize_stack_a(int *arr, t_ps_info *info)
{
	int		i;
	t_dlist	*tmp;

	i = 0;
	while (i < info->a_size)
		i++;
	i = info->a_size;
	info->b_size = 1;
	i -= 1;
	info->a_start = ft_dlstnew(&arr[i]);
	tmp = info->a_start;
	while (i)
	{
		tmp = ft_dlstnew(&arr[i - 1]);
		ft_dlstadd(&info->a_start, tmp);
		info->b_size += 1;
		info->a_start = tmp;
		i--;
	}
	info->a_size = info->b_size;
	info->b_size = 0;
}
