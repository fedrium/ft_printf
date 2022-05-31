/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:33:19 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/05/31 11:45:34 by cyu-xian         ###   ########.fr       */
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

static	void	ft_putnbr_itoa(long nbr, char *str, int ctr, int base)
{

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
}

int	ft_itoa(int n, int base)
{
	char	*str;
	int		mem;
	int		ctr;
	long	nbr;
	char	*hexa;

	hexa = malloc(16 * sizeof(char));
	hexa = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'a', 'b', 'c', 'd', 'e', 'f'];
	nbr = (long)n;
	mem = memsize(nbr, base);
	str = malloc(sizeof(char) * (mem + 1));
	if (str == NULL)
		return (NULL);
	str[mem] = '\0';
	ctr = mem - 1;
	ft_putnbr_itoa(nbr, str, ctr, base);
	ft_putstr_fd(str, 1);
}
