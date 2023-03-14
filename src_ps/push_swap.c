/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:42:22 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 16:22:31 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	push_swap_2(char *str)
{
	char	**nums;
	int		i;
	int		j;
	int		*arr_o;
	int		*arr_i;
	t_ps_info	inf;
	t_ps_info	*info;

	i = 0;
	nums = ft_split(str, ' ');
	while (nums[i])
		i++;
	arr_i = ft_calloc (sizeof(int), i);
	arr_o = ft_calloc (sizeof(int), i);
	j = 0;
	while (j < i)
	{
		arr_o[j] = ft_atoi(nums[j]);		
		j++;
	}
	ft_index_array(&arr_o, &arr_i, i);
	info = &inf;
	info->a_size = 0;
	info->a_start = NULL;
	info->b_size = 0;
	info->b_start = NULL;
	
	j = 9;
	
	info->a_size = i;
	i = 0;
	ft_initialize_stack_a(arr_i, info);
	i = 0;
	ft_ps_bruteforce(info);

	if (info->a_start)
		ft_dlstclear2(&info->a_start);
	if (info->b_start)
		ft_dlstclear2(&info->b_start);
	ft_free_split(nums);
	free(arr_i);
	free(arr_o);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	*arr_o;
	int	*arr_i;
	t_ps_info	inf;
	t_ps_info	*info;

	info = &inf;
	info->a_size = 0;
	info->a_start = NULL;
	info->b_size = 0;
	info->b_start = NULL;
	if (argc < 2)
	{
		return (0);
	}	
	else if (argc == 2)
	{
		push_swap_2(argv[1]);
		return (0);
	}
	else
	{
		arr_i = ft_calloc (sizeof(int), argc - 1);
		arr_o = ft_calloc (sizeof(int), argc - 1);
	}
	i = 1;
	while (i < argc)
	{
		arr_o[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	ft_index_array(&arr_o, &arr_i, argc - 1);
	info = &inf;
	info->a_size = 0;
	info->a_start = NULL;
	info->b_size = 0;
	info->b_start = NULL;
	i = 0;
	j = 9;
	
	info->a_size = argc - 1;
	ft_initialize_stack_a(arr_i, info);
	i = 0;
	ft_ps_bruteforce(info);

	if (info->a_start)
		ft_dlstclear2(&info->a_start);
	if (info->b_start)
	{
		ft_dlstclear2(&info->b_start);
	}
	free(arr_i);
	free(arr_o);

	return (0);
}