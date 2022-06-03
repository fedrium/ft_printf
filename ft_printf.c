/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:34:58 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/06/03 13:59:23 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	format(char val, va_list args)
{
	char	*str;
	int		var;

	if (val == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (val == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (val == 'p')
		str = ft_itoa_ptr(va_arg(args, unsigned long), 16, "0123456789abcdef");
	else if (val == 'i' || val == 'd')
		str = ft_itoa(va_arg(args, int), 10, "0123456789");
	else if (val == 'u')
		str = ft_itoa_ui(va_arg(args, unsigned int), 10, "0123456789");
	else if (val == 'x')
		str = ft_itoa_ui(va_arg(args, size_t), 16, "0123456789abcdef");
	else if (val == 'X')
		str = ft_itoa_ui(va_arg(args, size_t), 16, "0123456789ABCDEF");
	else if (val == '%')
		return (ft_putchar_fd('%', 1));
	else
		return (-1);
	var = ft_putstr_fd(str, 1);
	free(str);
	return (var);
}

int	ft_printf(const char *ph, ...)
{
	va_list	args;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	va_start(args, ph);
	while (ph[i] != '\0')
	{
		if (ph[i] != '%')
		{
			ft_putchar_fd(ph[i], 1);
			i++;
			j++;
		}
		else if (ph[i] == '%')
		{
			k = format(ph[i + 1], args);
			if (k == -1)
				ft_putchar_fd(ph[i + 1], 1);
			else
				j = j + k;
			i = i + 2;
		}
	}
	return (j);
}

// int main()
// {
// 	ft_printf(" NULL %s NULL ", NULL);
// 	printf(" NULL %s NULL ", NULL);
// 	return (0);
// }