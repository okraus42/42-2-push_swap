/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:43:08 by okraus            #+#    #+#             */
/*   Updated: 2023/03/15 15:50:30 by okraus           ###   ########.fr       */
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
// GET_NEXT_LINE definitions

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

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
int		ft_ps_bruteforce(t_ps_info *info);

//errors
void	ft_print_error(void);
int		ft_check_error_duplicates(int *arr_o, int size);
int		ft_check_error(char **nums, int size);

#endif
