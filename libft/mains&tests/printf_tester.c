/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:53:09 by okraus            #+#    #+#             */
/*   Updated: 2023/01/21 15:55:55 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	printf("Print %% .10i:    Print % .10i#\n", 123);
	printf("Print %%+010i:    Print %+010i#\n", 123);
	printf("Print %%+10i:     Print %+10i#\n", 123);
	printf("Print %%10.5i:    Print %10.5i#\n", 123);
	printf("Print %%+10.05d:  Print %+10.5d#\n", 123);
	printf("Print %%010d:     Print %010d#\n", -123);
	printf("Print %%-10.5i:   Print %-10.5i#\n", 123);
	printf("Print %%#-10.05x: Print %#-10.5x#\n", 123);
	printf("Print %%5.10d:    Print %5.10d#\n", 123456789);
	printf("Print %%+i:       Print %+i#\n", -1);
	printf("Print %%+i:       Print %+i#\n", 0);
	printf("Print %%#x:       Print %#x#\n", 1);
	printf("Print %% i:       Print % i#\n", 1);
	printf("Print %% i:       Print % i#\n", -1);
	printf("Print %%i:        Print %i#\n", 1);
	printf("Print %%5.2s:     Print %5.2s#\n", "abc");
	printf("Print %%.2s:      Print %.6s#\n", (char *)NULL);
	printf("Print %%5c:       Print %5c#\n", '\0');
	printf("Print %%.3d:      Print %.3d#\n", -1);
	printf("Print %%03d:      Print %03d#\n", -1);
	printf("Print %%.3d:      Print %.3d#\n", 1);
	printf("Print %%03d:      Print %03d#\n", 1);
	
	return (0);
}
