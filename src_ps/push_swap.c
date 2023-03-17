/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:42:22 by okraus            #+#    #+#             */
/*   Updated: 2023/03/17 18:50:57 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//convert array of indexes into double linked list
void	push_swap_4(int *arr_i, int *arr_s, int size)
{
	t_ps_info	inf;
	t_ps_info	*info;
	int			**arr_x;

	info = &inf;
	info->a_size = size;
	info->a_start = NULL;
	info->b_size = 0;
	info->b_start = NULL;
	//ft_printf("haha1\n");
	ft_initialize_stack_a(arr_i, info);
	//SOLVE FUNCTION
	//ft_printf("haha2\n");
	ft_ps_pushb(arr_s, info, size);
	//ft_printf("haha3\n");
	ft_ps_bruteforce(info);
	arr_x = malloc(sizeof(int *) * 8);
	ft_create_arrx(arr_x, size);
	//ft_printf("arrx = %p\n", arr_x);
	ft_ps_pusha(&arr_x, info, size);
	ft_free_arrx(&arr_x);
	if (info->a_start)
		ft_dlstclear2(&info->a_start);
	if (info->b_start)
		ft_dlstclear2(&info->b_start);	
}

//convert array of original integers into array of indexes
int	push_swap_3(int *arr_o, int size)
{
	int		*arr_i;
	int		*arr_s;

	if (ft_check_error_duplicates(arr_o, size))
		return (1);
	if (size < 2)
		return (0);
	arr_i = ft_calloc (sizeof(int), size);
	arr_s = ft_calloc (sizeof(int), size);
	ft_index_array(&arr_o, &arr_i, size);
	ft_index_stack(&arr_s, size);
	push_swap_4(arr_i, arr_s, size);
	free(arr_i);
	free(arr_s);
	return (0);
}

//get array of strings from long string and convert them into array of integers
int	push_swap_2(char *str)
{
	char	**nums;
	int		size;
	int		j;
	int		*arr_o;

	size = 0;
	nums = ft_split(str, ' ');
	while (nums[size])
		size++;
	if (ft_check_error(nums, size))
		return (1);
	arr_o = ft_calloc (sizeof(int), size);
	j = 0;
	while (j < size)
	{
		arr_o[j] = ft_atoi(nums[j]);		
		j++;
	}
	j = push_swap_3(arr_o, size);
	ft_free_split(nums);
	free(arr_o);
	return (j);
}

//convert arguments into array of integers
int	push_swap_1(int argc, char *argv[])
{
	int		size;
	int		j;
	int		*arr_o;

	size = argc - 1;
	j = 0;
	argv = &argv[1];
	if (ft_check_error(argv, size))
		return (1);
	arr_o = ft_calloc (sizeof(int), size);
	while (j < size)
	{
		arr_o[j] = ft_atoi(argv[j]);		
		j++;
	}
	j = push_swap_3(arr_o, size);
	free(arr_o);
	return (j);
}

//call split if only one argument is passed to the function,
//else call the other function
int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (push_swap_2(argv[1]))
			ft_print_error();
	}
	else if (argc > 2)
	{
		if (push_swap_1(argc, argv))
			ft_print_error();
	}
	return (0);
}