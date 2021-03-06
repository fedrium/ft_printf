/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:33:19 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/05/31 14:32:04 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	memsize(long n, int base)
{
	int	mem;

	mem = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		mem++;
	}
	while (n > 0)
	{
		n /= base;
		mem++;
	}
	return (mem);
}

// static	void	ft_putnbr_itoa(long nbr, char *str, int ctr, int base)
// {
// 	if (nbr == 0)
// 		str[0] = '0';
// 	if (nbr < 0)
// 	{
// 		str[0] = '-';
// 		nbr = -nbr;
// 	}
// 	while (nbr > 0)
// 	{
// 		str[ctr--] = hexa[nbr % base];
// 		nbr /= base;
// 	}
// }

char	*ft_itoa(int n, int base, char *hexa)
{
	char	*str;
	int		mem;
	int		ctr;
	long	nbr;

	nbr = (long)n;
	mem = memsize(nbr, base);
	str = malloc(sizeof(char) * (mem + 1));
	if (str == NULL)
		return (NULL);
	str[mem] = '\0';
	ctr = mem - 1;
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[ctr--] = hexa[nbr % base];
		nbr /= base;
	}
	return (str);
}
