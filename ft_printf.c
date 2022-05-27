/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:34:58 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/05/27 16:56:24 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(char val, args)
{
	if (val == 'c')
		ft_putchar_fd((args, char), 1);
	else if (val == 's')
		ft_putstr_fd((args, char *), 1);
	else if (val == 'p')
		ft_putstr_fd((args, unsigned long), 1);
	else if (val == 'd')
		ft_putnbr_fd((args, long), 1);
	else if (val == 'i')
		ft_putnbr_fd((args, int), 1);
	else if (val == 'u')
		ft_putnbr_fd((args, unsigned long), 1);
	//x
	//X
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