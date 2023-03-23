/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:43:08 by okraus            #+#    #+#             */
/*   Updated: 2023/03/23 14:58:02 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

// INCLUDES

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include "../libft/header/libft.h"

// DEFINITIONS

// STRUCTURES
// PUSH SWAP structure

typedef struct s_ps_info
{
	int				a_size;
	struct s_dlist	*a_start;
	int				b_size;
	struct s_dlist	*b_start;
}					t_ps_info;

typedef struct s_ps_arr
{
	int	i;
	int	j;
	int	min;
	int	tmp;
}		t_ps_arr;

// PROTOTYPES

void	*ft_prefill_array(int ***array);
void	ft_index_array(int **arr1, int **arr2, int size);
void	ft_index_stack(int **array, int size);
void	ft_initialize_stack_a(int *arr, t_ps_info *info);
void	ft_ps_cpa(t_ps_info *inf, t_ps_info *it);
void	ft_ps_cpb(t_ps_info *inf, t_ps_info *it);

// stack manipulation functions
void	ft_ps_sa(t_dlist **a, t_ps_info *info);
void	ft_ps_sb(t_dlist **b, t_ps_info *info);
void	ft_ps_ss(t_dlist **a, t_dlist **b, t_ps_info *info);
void	ft_ps_pa(t_dlist **a, t_dlist **b, t_ps_info *info);
void	ft_ps_pb(t_dlist **a, t_dlist **b, t_ps_info *info);
void	ft_ps_ra(t_dlist **a, t_ps_info *info);
void	ft_ps_rb(t_dlist **b, t_ps_info *info);
void	ft_ps_rr(t_dlist **a, t_dlist **b, t_ps_info *info);
void	ft_ps_rra(t_dlist **a, t_ps_info *info);
void	ft_ps_rrb(t_dlist **b, t_ps_info *info);
void	ft_ps_rrr(t_dlist **a, t_dlist **b, t_ps_info *info);

// solving
void	ft_ps_pushb(int *arr_s, t_ps_info *info, int size);
void	ft_ps_pusha(int ***arr_x, t_ps_info *info, int size);
void	ft_ps_dosmartpusha(int ***arr_x, t_ps_info *info, int i);
void	ft_ps_prefill_ax(int ***arr_x, t_ps_info *info, int size);

// solving utils
int		ft_ps_findhigher(int ***arr_x, int i);
int		ft_ps_findmin(int ***arr_x, int i);

// bruteforce
int		ft_ps_bruteforce(t_ps_info *info);
void	ft_ps_copyinfo(t_ps_info *info, t_ps_info *info_t);
void	ft_ps_cpb(t_ps_info *inf, t_ps_info *it);
void	ft_ps_cpa(t_ps_info *inf, t_ps_info *it);
void	ft_ps_putop(int i);

// errors
void	ft_print_error(void);
int		ft_check_error_duplicates(int *arr_o, int size);
int		ft_check_error(char **nums, int size);

// stuff
int		ft_ps_sortcheck(int *arr_i, int size);
void	ft_free_arrx(int ***arr_x);
void	ft_create_arrx(int **ax, int size);

// checker
void	ft_ch_gnl(t_ps_info *info);

#endif
