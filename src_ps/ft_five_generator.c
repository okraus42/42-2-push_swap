/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:04:51 by okraus            #+#    #+#             */
/*   Updated: 2023/03/05 16:25:57 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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