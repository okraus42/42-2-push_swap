/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:11:54 by okraus            #+#    #+#             */
/*   Updated: 2023/03/05 17:19:58 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_prefill_array(int i, int ***array)
{
	int	**arr;
	int	j;
	int	k;
	int	l;

	j = 0;
	arr = *array;
	while (j < 5)
	{
		arr[0][j] = j + 1;
		j++;
	}
	i = 1;
	j = 4;
	while (i < 120)
	{
		while (arr[i - 1][j - 1] > arr[i - 1][j])
			j--;
		k = 0;
		l = 1;
		while (k < j - 1)
		{
			if (arr[i - 1][j - 1] + l == arr[i - 1][k])
			{
				l++;
				k = 0;
			}
			else
				k++;
		}
		arr[i][j - 1] = arr[i - 1][j - 1] + l;
		while (j > 1)
		{
			j--;
			arr[i][j - 1] = arr[i - 1][j - 1];
		}
		while (arr[i][j])
			j++;
		while (j < 5)
		{
			k = 1;
			l = 0;
			while (l < j)
			{
				if (arr[i][l] == k)
				{
					k++;
					l = 0;
				}
				else
					l++;
			}
			arr[i][j] = k;
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int	**arr;
	int	i;
	int	j;

	i = 0;
	arr = malloc(sizeof(int *) * 121);
	while (i < 120)
	{
		arr[i] = calloc(sizeof(int), 5);
		i++;
	}
	arr[i] = NULL;
	i = 0;
	ft_prefill_array(i, &arr);
	while (i < 120)
	{
		j = 0;
		while (j < 5)
		{
			printf("%i", arr[i][j]);
			j++;
		}
		printf(", ");
		i++;
	}
	return (0);
}