/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:11:54 by okraus            #+#    #+#             */
/*   Updated: 2023/03/08 11:16:05 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//testing dlist & list manipulation
int	main(void)
{
	int	i;
	int	j;
	int	arr[10];
	void *test;
	t_dlist	**a;
	t_dlist	**b;
	t_dlist	*tmp;
	t_dlist	*start_a;
	t_dlist	*tmp2;
	t_ps_info	inf;
	t_ps_info	*info;

	info = &inf;
	info->a_size = 0;
	info->a_start = NULL;
	info->b_size = 0;
	info->b_start = NULL;
	i = 0;
	j = 9;
	arr[0] = 1;
	a = &info->a_start;
	b = &info->b_start;
	test = &i;
	ft_printf("%3i|%p|%3i\n", i, test, *(int *)test);
	start_a = ft_dlstnew(&arr[i]);
	info->a_size = 1;
	info->a_start = start_a;
	ft_printf("%i\n", i);

	while (i < 10)
	{
		arr[i] = i + 1;
		i++;
	}

	i = 3;

	while (i < j)
	{
		tmp = ft_dlstnew(&arr[i]);
		ft_printf("%i\n", i);
		ft_printf("%4CprintC:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		tmp2 = *a;
		ft_printf("%1CprintD:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp2->content, tmp2->prev, tmp2, tmp2->next);
		ft_dlstadd(a, tmp);
		info->a_size += 1;
		info->a_start = tmp;
		ft_printf("%2CprintB:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		i++;
	}
	ft_printf("%i\n", i);

	tmp = *a;
	i = 0;
	ft_printf("%7CprintA:%3i, num %3i|%p|%p|%p%0C\n", i, *(int *)tmp->content, a, *a, **a);
	while (i < 15)
	{
		ft_printf("%2CprintB:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		tmp = tmp->next;
		i++;
	}
	while (i < 30)
	{
		ft_printf("%3CprintB:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		tmp = tmp->prev;
		i++;
	}
	ft_ps_sa(a, info);
	tmp = info->a_start;
	i = 0;
	while (i < 12)
	{
		ft_printf("%1CprintF:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		tmp = tmp->next;
		i++;
	}
	ft_ps_pb(a, b, info);
	tmp = info->a_start;
	tmp2 = info->b_start;
	i = 0;
	while (i < 12)
	{
		ft_printf("%1CstackA:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		ft_printf("%2CstackB:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp2->content, tmp2->prev, tmp2, tmp2->next);
		if (tmp->next)
			tmp = tmp->next;
		if (tmp2->next)
			tmp2 = tmp2->next;
		i++;
	}
	ft_ps_pb(a, b, info);
	tmp = info->a_start;
	tmp2 = info->b_start;
	i = 0;
	while (i < 12)
	{
		ft_printf("%1CstackA:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		ft_printf("%2CstackB:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp2->content, tmp2->prev, tmp2, tmp2->next);
		if (tmp->next)
			tmp = tmp->next;
		if (tmp2->next)
			tmp2 = tmp2->next;
		i++;
	}
	ft_dlstclear2(a);
	ft_dlstclear2(b);

	return (0);
}


/*
int	main(void)
{
	int	*arr1;
	int	*arr2;
	int	size;
	int	i;

	i = 0;
	size = 10;
	arr1 = malloc(sizeof(int) * 10);
	arr2 = malloc(sizeof(int) * 10);
	arr1[0] = 2;
	arr1[1] = -2147483648;
	arr1[2] = 2147483647;
	arr1[3] = 0;
	arr1[4] = -42;
	arr1[5] = -2;
	arr1[6] = 42;
	arr1[7] = 5;
	arr1[8] = 9;
	arr1[9] = 8;
	while (i < size)
	{
		arr2[i] = 0;
		i++;
	}
	i = 0;
	ft_index_array(&arr1, &arr2, size);
	while (i < size)
	{
		ft_printf("arr2[%i]=%i|arr1[%i]=%i\n", i, arr2[i], i, arr1[i]);
		i++;
	}
	free(arr1);
	free(arr2);
	return (0);
}
*/

/*
//testing dlist
int	main(void)
{
	int	i;
	int	j;
	int	arr[10];
	void *test;
	t_dlist	**a;
	t_dlist	*tmp;
	t_dlist	*start;
	t_dlist	*tmp2;

	i = 0;
	j = 9;
	arr[0] = 1;
	a = NULL;
	test = &i;
	ft_printf("%3i|%p|%3i\n", i, test, *(int *)test);
	start = ft_dlstnew(&arr[i]);
	a = &start;
	ft_printf("%i\n", i);

	while (i < 10)
	{
		arr[i] = i + 1;
		i++;
	}

	i = 3;

	while (i < j)
	{
		tmp = ft_dlstnew(&arr[i]);
		ft_printf("%i\n", i);
		ft_printf("%4CprintC:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		tmp2 = *a;
		ft_printf("%1CprintD:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp2->content, tmp2->prev, tmp2, tmp2->next);
		ft_dlstadd(a, tmp);
		ft_printf("%2CprintB:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		i++;
	}
	ft_printf("%i\n", i);

	tmp = *a;
	i = 0;
	ft_printf("%7CprintA:%3i, num %3i|%p|%p|%p%0C\n", i, *(int *)tmp->content, a, *a, **a);
	while (i < 15)
	{
		ft_printf("%2CprintB:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		tmp = tmp->next;
		i++;
	}
	while (i < 30)
	{
		ft_printf("%3CprintB:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		tmp = tmp->prev;
		i++;
	}
	ft_dlstclear2(a);
	
	return (0);
}
*/

/*
TESTING GENERATION OF 5 PERMUTATION ARRAY
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
			ft_printf("%2C%i%0C", arr[i][j]);
			j++;
		}
		if (i < 120)
			ft_printf(", ");
		i++;
	}
	return (0);
}
*/
