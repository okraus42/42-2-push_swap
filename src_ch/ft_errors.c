/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:09:56 by okraus            #+#    #+#             */
/*   Updated: 2023/03/15 11:33:06 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_print_error(void)
{
	ft_printf_fd(2, "Error\n");
}

int	ft_check_error_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == arr[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_check_error_isbignumber(char **nums, int size, int i)
{
	while (i < size)
	{
		if (ft_strlen(nums[i]) > 11)
			return (1);
		else
		{
			if (ft_latoi(nums[i]) < -2147483648
				|| ft_latoi(nums[i]) > 2147483647)
			{
				return (1);
			}
		}
		i++;
	}
	return (0);
}

static int	ft_check_error_isnumber(char **nums, int size, int i)
{
	int	j;

	while (i < size)
	{
		j = 0;
		if (ft_isdigit(nums[i][j]) || nums[i][j] == '-' || nums[i][j] == '+')
			j++;
		while (ft_isdigit(nums[i][j]))
			j++;
		if (nums[i][j])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_error(char **nums, int size)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	err += ft_check_error_isnumber(nums, size, i);
	err += ft_check_error_isbignumber(nums, size, i);
	return (err);
}
