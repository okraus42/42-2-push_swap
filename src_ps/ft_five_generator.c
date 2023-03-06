/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:04:51 by okraus            #+#    #+#             */
/*   Updated: 2023/03/06 15:31:04 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_prefill_array_3(int i, int j, int ***array)
{
	int	**arr;
	int	k;
	int	l;

	arr = *array;
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
}

static void	ft_prefill_array_4(int i, int j, int ***array)
{
	int	**arr;
	int	k;
	int	l;

	arr = *array;
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
}

static void	ft_prefill_array_2(int i, int j, int ***array)
{
	int	**arr;

	arr = *array;
	while (arr[i - 1][j - 1] > arr[i - 1][j])
		j--;
	ft_prefill_array_3(i, j, &arr);
	while (j > 1)
	{
		j--;
		arr[i][j - 1] = arr[i - 1][j - 1];
	}
	while (arr[i][j])
		j++;
	while (j < 5)
	{
		ft_prefill_array_4(i, j, &arr);
		j++;
	}
}

static void	ft_prefill_array_1(int i, int j, int ***array)
{
	int	**arr;

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
		ft_prefill_array_2(i, j, &arr);
		j = 4;
		i++;
	}
}

void	*ft_prefill_array(int ***array)
{
	int	**arr;
	int	i;
	int	j;

	i = 0;
	arr = *array;
	arr = malloc(sizeof(int *) * 121);
	while (i < 120)
	{
		arr[i] = calloc(sizeof(int), 5);
		i++;
	}
	arr[i] = NULL;
	i = 0;
	j = 0;
	ft_prefill_array_1(i, j, &arr);
	return (arr);
}

/*
int ft_five_assignment(int *arr)
{
	int	i;

	i = 0;
	while (i < 120)
	{

	}
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	**ft_prefill_array(int **arr)
{
	int	i
	int	j;
	int	k;
	int	l;

	i = 0
	{
			j = 0;
		while (j < 5)
		{
			arr[0][j] = j + 1;
			j++;
		}
	}
	else
	{
		j = 4;
		while (arr[i - 1][j - 1] > arr[i - 1][j])
			j--;
		arr[i][j - 1] = arr[i - 1][j - 1] + 1;
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
				if (arr[i][j] == k)
					k++;
					l = 0;
				else
					l++;
			}
			arr[i][j] = 5;
			j++;
		}
	}
	return (arr);
}

void	ft_print(int array[11], int m)
{
	char	c;
	int		k;

	while (array[4] <= 5)
	{
		k = 1;
		if (array[4] != (4))
		{
			write(1, ", ", 2);
		}
		while (k <= m)
		{
			c = array[k] + '0';
			write(1, &c, 1);
			k++;
		}
		array[m]++;
	}
}

int	**ft_comb5_generator(void)
{
	static int	arr_comb[120][5];
	int			i;

	i = 5;
	comb = ft_prefill5_array();
	while (comb[0] == 0)
	{
		ft_print(comb, n);
		while (comb[i] == 10 - n + i)
		{
			i--;
		}
		comb[i]++;
		while (i < n)
		{
			i++;
			comb[i] = comb[i - 1] + 1;
		}
	}
	return (arr_comb);
}

int	**ft_instr5_generator(void)
{
	int	arr_instr[120][7];

}
*/
