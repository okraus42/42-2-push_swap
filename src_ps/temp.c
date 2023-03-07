/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:11:54 by okraus            #+#    #+#             */
/*   Updated: 2023/03/07 17:52:05 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
		ft_printf(1, "arr2[%i]=%i|arr1[%i]=%i\n", i, arr2[i], i, arr1[i]);
		i++;
	}
	return (0);
}
/*
testing dlist
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
	ft_printf(1, "%3i|%p|%3i\n", i, test, *(int *)test);
	start = ft_dlstnew(&arr[i]);
	a = &start;
	ft_printf(1, "%i\n", i);

	while (i < 10)
	{
		arr[i] = i + 1;
		i++;
	}

	i = 3;

	while (i < j)
	{
		tmp = ft_dlstnew(&arr[i]);
		ft_printf(1, "%i\n", i);
		ft_printf(1, "%4CprintC:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		tmp2 = *a;
		ft_printf(1, "%1CprintD:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp2->content, tmp2->prev, tmp2, tmp2->next);
		ft_dlstadd(a, tmp);
		ft_printf(1, "%2CprintB:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		i++;
	}
	ft_printf(1, "%i\n", i);

	tmp = *a;
	i = 0;
	ft_printf(1, "%7CprintA:%3i, num %3i|%p|%p|%p%0C\n", i, *(int *)tmp->content, a, *a, **a);
	while (i < 15)
	{
		ft_printf(1, "%2CprintB:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		tmp = tmp->next;
		i++;
	}
	while (i < 30)
	{
		ft_printf(1, "%3CprintB:%3i, num %3i|%p|%p|%p\n%0C", i, *(int *)tmp->content, tmp->prev, tmp, tmp->next);
		tmp = tmp->prev;
		i++;
	}
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
			ft_printf(1, "%2C%i%0C", arr[i][j]);
			j++;
		}
		if (i < 120)
			ft_printf(1, ", ");
		i++;
	}
	return (0);
}
*/
