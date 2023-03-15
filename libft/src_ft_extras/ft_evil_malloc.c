/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evil_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:20:43 by okraus            #+#    #+#             */
/*   Updated: 2023/03/15 11:42:05 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_evil_malloc(size_t size)
{
	char	*p;
	size_t	i;

	p = ft_malloc(size + 64);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * (size + 64))
	{
		if (i < 32 || i > nmemb * (size + 32))
			p[i] = 0xFF;
		else
			p[i] = 1;
		i++;
	}
	p = &p[32];
	return ((void *)p);
}

void	*ft_evil_malloc_plus(size_t size, size_t padding)
{
	char	*p;
	size_t	i;

	p = ft_malloc(size + (2 * padding));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * (size + (2 * padding)))
	{
		if (i < padding || i > nmemb * (size + padding))
			p[i] = 0xFF;
		else
			p[i] = 1;
		i++;
	}
	p = &p[padding];
	return ((void *)p);
}
