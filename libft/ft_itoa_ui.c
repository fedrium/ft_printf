/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:42:28 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/06/03 14:02:28 by cyu-xian         ###   ########.fr       */
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

char	*ft_itoa_ui(unsigned int n, int base, char *hexa)
{
	char	*str;
	int		mem;
	int		ctr;

	mem = memsize(n, base);
	str = malloc(sizeof(char) * (mem + 1));
	if (str == NULL)
		return (NULL);
	str[mem] = '\0';
	ctr = mem - 1;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[ctr--] = hexa[n % base];
		n /= base;
	}
	return (str);
}
