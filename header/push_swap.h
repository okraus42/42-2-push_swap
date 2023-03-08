/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:43:08 by okraus            #+#    #+#             */
/*   Updated: 2023/03/08 10:10:38 by okraus           ###   ########.fr       */
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

// stack manipulation functions
void	ft_ps_sa(t_dlist **a, t_ps_info *info);
void	ft_ps_sb(t_dlist **b, t_ps_info *info);
void	ft_ps_ss(t_dlist **a, t_dlist **b, t_ps_info *info);
void	ft_ps_pa(t_dlist **a, t_dlist **b, t_ps_info *info);
void	ft_ps_pb(t_dlist **a, t_dlist **b, t_ps_info *info);

#endif
