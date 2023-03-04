/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:49:23 by okraus            #+#    #+#             */
/*   Updated: 2023/01/22 13:56:10 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putmem_fd(unsigned long long mem, int fd)
{
	if (mem / 16)
		ft_putmem_fd(mem / 16, fd);
	write(fd, &"0123456789abcdef"[mem % 16], 1);
}

void	ft_putadd_fd(void *p, int fd)
{
	write(1, "0x", 2);
	ft_putmem_fd((unsigned long long)p, fd);
}

int	main(void)
{
	char				c;
	char				*p;

	c = 'a';
	p = &c;
	printf("print %p \n", p);
	write(1, "write ", 6);
	ft_putadd_fd(p, 1);
	write(1, "\n", 1);
	return (0);
}
