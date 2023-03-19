/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pusha_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:47:28 by okraus            #+#    #+#             */
/*   Updated: 2023/03/19 15:43:28 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

//utils
int	ft_ps_findhigher(int ***arr_x, int i)
{
	int	**ax;

	ax = *arr_x;
	while (ax[2][i])
		i++;
	return (i);
}

static int	ft_ps_min4(int a, int b, int c, int d)
{
	int	min;

	if (a < b)
		min = a;
	else
		min = b;
	if (min > c)
		min = c;
	if (min > d)
		min = d;
	return (min);
}

static int	ft_ps_min4b(int a, int b, int c, int d)
{
	int	min;

	if (a < b)
		min = a;
	else
		min = b;
	if (min > c)
		min = c;
	if (min > d)
		min = d;
	if (min == a)
		return (1);
	else if (min == b)
		return (2);
	else if (min == c)
		return (3);
	else
		return (4);
}

int	ft_ps_findmin(int ***arr_x, int i)
{
	int	**ax;
	int	rarb;
	int	rrarb;
	int	rarrb;
	int	rrarrb;

	ax = *arr_x;
	rarb = ft_max(ax[3][i], ax[5][i]);
	rrarb = ax[4][i] + ax[5][i];
	rarrb = ax[3][i] + ax[6][i];
	rrarrb = ft_max(ax[4][i], ax[6][i]);
	ax[2][i] = ft_ps_min4b(rarb, rrarb, rarrb, rrarrb);
	return (ft_ps_min4(rarb, rrarb, rarrb, rrarrb));
}
