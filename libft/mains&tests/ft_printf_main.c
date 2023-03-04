/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:49:23 by okraus            #+#    #+#             */
/*   Updated: 2023/03/02 15:21:49 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_printf(int fd, const char *s, ...);

int	main(void)
{
	char			c;
	char			d;
	unsigned int	u;
	int				pf;
	int				fp;
	int				fd;
	int				num;
	char			*s = "@@@";
	char			*s2 = NULL;

	c = 'a';
	d = 'b';
	fd = 1;
	num = 0x7FFFFFFF;
	u = 0xFFFFFFFF;
	pf = printf("printf : a%pbc%%de%5cfg%-20.15uhij%2sk%-+20.15dlm% inop%#20.15Xq%xr\n", (void *)&c, d, u, s, num, 0, u, u);
	fp = ft_printf(fd, "ftprint: a%pbc%%de%5cfg%-20.15uhij%2sk%-+20.15dlm% inop%#20.15Xq%xr\n", (void *)&c, d, u, s, num, 0, u, u);
	printf ("pf = %d, fp = %d\n", pf, fp);
	pf = printf("%.3d\n", -1234);
	fp = ft_printf(fd, "%.3d\n", -1234);
	printf ("pf = %d, fp = %d\n", pf, fp);
	pf = printf("%-9sScience!\n", "Aperture");
	fp = ft_printf(fd, "%-9sScience!\n", "Aperture");
	printf ("pf = %d, fp = %d\n", pf, fp);
	pf = printf("%8p-%8s\n", NULL, s2);
	fp = ft_printf(fd, "%8p-%8s\n", NULL, s2);
	printf ("pf = %d, fp = %d\n", pf, fp);
	ft_printf(fd, "%+10.16B a\n", num);
	ft_printf(fd, "aaa\n", num);
	u = 0x89ABCDEF;
	ft_printf(fd, "% 4.16P\n", (void *)&u);
	ft_printf(fd, "%- 4.16P\n", (void *)&u + 3);
	ft_printf(fd, "% 4.2P\n", (void *)&u);
	ft_printf(fd, "%- 16.16P\n", (void *)&u);
	ft_printf(fd, "colours!!! %1Cone%C-%2Ctwo%C-%3Cthree%C-%4Cfour%C-%5Cfive%C-%6Csix%C-%7Cseven%C-%8Ceight%C-%9Cnine%C-%10Cten%C\n");
	ft_printf(fd, "hexa: %3C%x%C\ncool: %8C%- 4.16P%C\nbin: %7C%- 4.2P%C\n", u, (void *)&u + 3, (void *)&u + 3);
	return (0);
}
