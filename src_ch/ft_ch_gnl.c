/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:05:22 by okraus            #+#    #+#             */
/*   Updated: 2023/03/21 17:07:05 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_ch_do(t_ps_info *info, char *inst)
{
	if (!ft_strncmp(inst, "sa\n", 5))
		ft_ps_sa(&info->a_start, info);
	else if (!ft_strncmp(inst, "sb\n", 5))
		ft_ps_sb(&info->b_start, info);
	else if (!ft_strncmp(inst, "ss\n", 5))
		ft_ps_ss(&info->a_start, &info->b_start, info);
	else if (!ft_strncmp(inst, "pa\n", 5))
		ft_ps_pa(&info->a_start, &info->b_start, info);
	else if (!ft_strncmp(inst, "pb\n", 5))
		ft_ps_pb(&info->a_start, &info->b_start, info);
	else if (!ft_strncmp(inst, "ra\n", 5))
		ft_ps_ra(&info->a_start, info);
	else if (!ft_strncmp(inst, "rb\n", 5))
		ft_ps_rb(&info->b_start, info);
	else if (!ft_strncmp(inst, "rr\n", 5))
		ft_ps_rr(&info->a_start, &info->b_start, info);
	else if (!ft_strncmp(inst, "rra\n", 5))
		ft_ps_rra(&info->a_start, info);
	else if (!ft_strncmp(inst, "rrb\n", 5))
		ft_ps_rrb(&info->b_start, info);
	else if (!ft_strncmp(inst, "rrr\n", 5))
		ft_ps_rrr(&info->a_start, &info->b_start, info);
}

int	ft_ch_check(char *inst)
{
	if (!ft_strncmp(inst, "pa\n", 5) || !ft_strncmp(inst, "pb\n", 5)
		|| !ft_strncmp(inst, "sa\n", 5) || !ft_strncmp(inst, "sb\n", 5)
		|| !ft_strncmp(inst, "ss\n", 5) || !ft_strncmp(inst, "ra\n", 5)
		|| !ft_strncmp(inst, "rb\n", 5) || !ft_strncmp(inst, "rr\n", 5)
		|| !ft_strncmp(inst, "rra\n", 5) || !ft_strncmp(inst, "rrb\n", 5)
		|| !ft_strncmp(inst, "rrr\n", 5))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	ft_ch_checksort(t_ps_info *info)
{
	int		i;
	t_dlist	*tmp;

	i = 1;
	if (!info->b_size)
	{
		if (info->a_size)
			tmp = info->a_start;
		while (i < info->a_size + 1 && i == *(int *)tmp->content)
		{
			tmp = tmp->next;
			i++;
		}
	}
	if (i == info->a_size + 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	ft_ch_gnl(t_ps_info *info)
{
	char	*inst;
	int		err;

	inst = get_next_line(0);
	err = 0;
	if (inst)
	{
		while (inst)
		{
			if (ft_ch_check(inst))
				ft_ch_do(info, inst);
			else
				err++;
			free (inst);
			inst = get_next_line(0);
		}
	}
	free (inst);
	if (err)
		ft_print_error();
	else
		ft_ch_checksort(info);
}
