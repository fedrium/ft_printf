/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:34:58 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/05/31 12:12:19 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	format(char val, va_list args)
{
	if (val == 'c')
		return (ft_putchar_fd((args, char), 1));
	else if (val == 's')
		ft_putstr_fd((args, char *), 1);
	else if (val == 'p')
		ft_itoa((args, unsigned long), 16);
	else if (val == 'd')
		ft_itoa((args, long), 10);
	else if (val == 'i')
		ft_itoa((args, int), 10);
	else if (val == 'u')
		ft_itoa((args, unsigned int), 10);
	else if (val == 'x')
		ft_itoa((args, size_t), 16);
	else if (val == 'X')
		ft_itoa((args, size_t), 16);
	else if (val == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *ph, ...)
{
	va_list args;
	int	i;

	i = 1;
	va_start(args, ph);
	while (ph[i] != '\0')
	{
		if (ph[i] != '%')
			write(1, ph[i], 1);
		else if (ph[i] == '%')
		{
			format(ph[i + 1], args);
			i++;
		}
		i++;
	}
}