/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:54:34 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/06/03 14:02:27 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	memsize(unsigned long n, int base)
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

char	*ft_itoa_ptr(unsigned long n, int base, char *hexa)
{
	char	*str;
	int		mem;
	int		ctr;
	char	*ph;

	mem = memsize(n, base);
	str = malloc(sizeof(char) * (mem + 1));
	if (str == NULL)
		return (NULL);
	str[mem] = '\0';
	ctr = mem - 1;
	if (n == 0)
	{
		str[0] = '0';
	}
	while (n > 0)
	{
		str[ctr--] = hexa[n % base];
		n /= base;
	}
	ph = ft_strjoin("0x", str);
	free(str);
	return (ph);
}
