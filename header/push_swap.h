/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:43:08 by okraus            #+#    #+#             */
/*   Updated: 2023/03/06 15:30:42 by okraus           ###   ########.fr       */
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
// LIBFT structure

/*typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// FT_PRINTF structure

typedef struct s_output
{
	char	*string;
	int		len;
	int		precision;
	int		padsize;
	int		dash;
	int		zero;
	int		period;
	int		hash;
	int		space;
	int		plus;
	char	type;
	int		base;
}			t_output;
*/

// PROTOTYPES

void	*ft_prefill_array(int ***array);

#endif
